#include "robit_master_vision.h"

RobitLabeling::RobitLabeling()
//PRE CONDITION : Img, nThreshold, nNeighbor
//POST CONDITION : RobitLabeling
//PURPOSE : RobitLabeling 생성자 함수, Mat형 이미지와 임계값, 연결성 수치를 입력하면 해당 값으로 초기화 하고 그렇지 않으면 0으로 초기화
{
    if(!m_Image.empty())           m_Image.release();

    if(!m_recBlobs.empty())        m_recBlobs.clear();

    m_nThreshold        = 0;
    m_nNeighbor         = 0;
    m_nBlobs            = 0;
    m_height            = 0;
    m_width             = 0;
}

RobitLabeling::RobitLabeling(const cv::Mat& Img,
                             const unsigned int& nThreshold,
                             const unsigned int& nNeighbor)
{
    if(!m_recBlobs.empty())        m_recBlobs.clear();

    m_Image             = Img.clone();
    m_Image_Obj         = Img;

    m_nThreshold        = nThreshold;
    m_nNeighbor         = nNeighbor;
    m_nBlobs            = 0;
    m_height            = Img.rows;
    m_width             = Img.cols;
}

void RobitLabeling::doLabeling()
//PRE CONDITION : m_Img, nNeighbor
//POST CONDITION : 라벨링 함수 실행
//PURPOSE : nNeighbor값에 따라 4방향 또는 8방향의 연결성으로 라벨링을 실행한다.
{
    if(m_Image.channels() != 1)
    {
        //m_Img의 이미지 타입이 Mat가 아닐 경우
        std::cout << "Image type is not collect" << std::endl;
        return ;
    }

    switch (m_nNeighbor)
    {
    case 4: //m_nNeighbor가 4인 경우
        _labeling_four_neighbor(); //4연결성 라벨링 실행
        break;

    case 8: //m_nNeighbor가 8인 경우
        _labeling_eight_neighbor(); //8연결성 라벨링 실행
        break;

    default: //m_nNeighbor값이 4 또는 8이 아닐 경우
        std::cout << "Check nNeighbor" << std::endl;
        break;
    }
}

vector<cv::Rect> RobitLabeling::getRecBlobs()
{
    //PRE CONDITION : m_recBlobs
    //POST CONDITION : m_recBlobs 반환
    //PURPOSE : 객체 내 변수 m_recBlobs 반환한다
    return m_recBlobs;
}

unsigned int RobitLabeling::getNumOfBlobs()
{
    //PRE CONDITION : m_nBlobs
    //POST CONDITION : m_nBlobs 반환
    //PURPOSE : 객체 내 변수 m_nBlobs를 반환한다
    return m_nBlobs;
}

void RobitLabeling::sortingRecBlobs()
{
    //PRE CONDITION : m_nBlobs
    //POST CONDITION : _quick_sort_rec_blobs실행
    //PURPOSE : m_nBlobs값에 따라 _quick_sort_rec_blobs실행
    if(m_nBlobs < 2)
        return;

    _quick_sort_rec_blobs(0, m_nBlobs - 1);
}

void RobitLabeling::_labeling_four_neighbor()
{
    //PRE CONDITION : m_height, m_width, m_isVisited
    //POST CONDITION : __check_eight_neighbor 실행
    //PURPOSE : 모든 픽셀에서 4연결성 라벨링을 진행

    //m_isVisited, m_visited_pt를 동적할당 한 후 false로 초기화
    __dynamicAllocation();

    for(int nRow = 0, nowY = 0 ; nRow < m_height ; nRow ++, nowY += m_width)
        //한 열마다 모든 픽셀에서 라벨링 실행, nowY값은 1차원 배열인 m_isVisited와 m_Image.data에서 2차원 데이터를 저장하기 위해서 한 열의 계산이 끝날때 마다 nowY += m_width 연산
        for(int nCol = 0 ; nCol < m_width ; nCol ++)
            //열의 모든 행마다 계산
        {
            //해당 픽셀에 데이터가 있다면 건너뛰기
            if(m_isVisited[nowY + nCol]   == true)     continue;
            if(m_Image.data[nowY + nCol]  == 0)        continue;


            //픽셀 데이터 입력
            m_Image.data[nowY + nCol]     = ++m_nBlobs;
            m_isVisited[nowY + nCol]      = true;

            //blob의 시작점과 끝점 선언, 이후 __check_four_neighbor을 실행하며 해당 값이 달라짐
            cv::Point start_pt   = cv::Point(nCol, nRow);
            cv::Point end_pt     = cv::Point(nCol, nRow);


            if(__check_four_neighbor(start_pt, end_pt) > m_nThreshold)
            {
                //__check_four_neighbor실행, 해당 결과값이 임계값을 넘을경우 데이터를 벡터 컨테이너에 저장
                m_recBlobs.push_back(cv::Rect(start_pt, end_pt));
                m_vecArea.push_back(m_area);
            }
            else
            {
                //임계값을 넘지 않을 경우 해당 blob의 데이터 초기화
                for(int nRow = start_pt.y, nowY = start_pt.y * m_width ; nRow <= end_pt.y ; nRow ++, nowY += m_width)
                    for(int nCol = start_pt.x ; nCol <= end_pt.x ; nCol ++)
                        if(m_Image.data[nowY + nCol] == m_nBlobs)
                            m_Image.data[nowY + nCol] = 0;

                m_nBlobs--;
            }
        }
    //동적할당 해제
    __freeAllocation();
}

void RobitLabeling::_labeling_eight_neighbor()
{
    //PRE CONDITION : m_height, m_width, m_isVisited
    //POST CONDITION : __check_eight_neighbor 실행
    //PURPOSE : 모든 픽셀에서 8연결성 라벨링을 진행

    //m_isVisited, m_visited_pt를 동적할당 한 후 false로 초기화
    __dynamicAllocation();

    for(int nRow = 0, nowY = 0 ; nRow < m_height ; nRow ++, nowY += m_width)
        //한 열마다 모든 픽셀에서 라벨링 실행, nowY값은 1차원 배열인 m_isVisited와 m_Image.data에서 2차원 데이터를 저장하기 위해서 한 열의 계산이 끝날때 마다 nowY += m_width 연산
        for(int nCol = 0 ; nCol < m_width ; nCol ++)
            //열의 모든 행마다 계산
        {
            //해당 픽셀에 데이터가 있다면 건너뛰기
            if(m_isVisited[nowY + nCol]   == true)     continue;
            if(m_Image.data[nowY + nCol]  == 0)        continue;


            //픽셀 데이터 입력
            m_Image.data[nowY + nCol]     = ++m_nBlobs;
            m_isVisited[nowY + nCol]      = true;

            //blob의 시작점과 끝점 선언, 이후 __check_eight_neighbor을 실행하며 해당 값이 달라짐
            cv::Point start_pt   = cv::Point(nCol, nRow);
            cv::Point end_pt     = cv::Point(nCol, nRow);


            if(__check_eight_neighbor(start_pt, end_pt) > m_nThreshold)
            {
                //__check_eight_neighbor실행, 해당 결과값이 임계값을 넘을경우 데이터를 벡터 컨테이너에 저장
                m_recBlobs.push_back(cv::Rect(start_pt, end_pt));
                m_vecArea.push_back(m_area);
            }
            else
            {
                //임계값을 넘지 않을 경우 해당 blob의 데이터 초기화
                for(int nRow = start_pt.y, nowY = start_pt.y * m_width ; nRow <= end_pt.y ; nRow ++, nowY += m_width)
                    for(int nCol = start_pt.x ; nCol <= end_pt.x ; nCol ++)
                        if(m_Image.data[nowY + nCol] == m_nBlobs)
                            m_Image.data[nowY + nCol] = 0;

                m_nBlobs--;
            }
        }
    //동적할당 해제
    __freeAllocation();
}

void RobitLabeling::_quick_sort_rec_blobs(int left, int right)
{
    //PRE CONDITION : m_nBlobs
    //POST CONDITION : _quick_sort_rec_blobs실행
    //PURPOSE : 퀵 정렬 알고리즘을 통해 m_vecArea와 m_recBlobs를 내림차순 정렬
    int L = left;
    int R = right;
    unsigned int pivot = m_vecArea[(left + right) / 2];

    while(L <= R)
    {
        while(m_vecArea[L] > pivot)     L++;
        while(m_vecArea[R] < pivot)     R--;
        if( L <= R)
        {
            if(L != R)
            {
                __swap(m_vecArea[L] , m_vecArea[R]);
                __swap(m_recBlobs[L], m_recBlobs[R]);
            }
            L++;
            R--;
        }
    }
    if(left < R)        _quick_sort_rec_blobs(left, R);
    if(L < right)       _quick_sort_rec_blobs(L, right);
}

void RobitLabeling::__dynamicAllocation()
{
    //PRE CONDITION : X
    //POST CONDITION : m_isVisited, m_visited_pt
    //PURPOSE : m_isVisited, m_visited_pt를 동적할당 한 후 false로 초기화
    m_isVisited          = new bool [m_Image.size().area()];
    m_visited_pt         = new cv::Point [m_Image.size().area()];

    memset(m_isVisited,  false, m_Image.size().area() * sizeof(bool));
    memset(m_visited_pt, false, m_Image.size().area() * sizeof(cv::Point));
}

void RobitLabeling::__freeAllocation()
{
    //PRE CONDITION : m_isVisited, m_visited_pt
    //POST CONDITION : X
    //PURPOSE : m_isVisited, m_visited_pt를 동적할당 해제
    delete[]          m_isVisited;
    delete[]          m_visited_pt;

    m_isVisited       = NULL;
    m_visited_pt      = NULL;
}

const unsigned int RobitLabeling::__check_four_neighbor(cv::Point &start_pt, cv::Point &end_pt)
{
    //PRE CONDITION : start_pt, end_pt
    //POST CONDITION : m_Image.data
    //PURPOSE : start_pt부터 시작하여 근처 4방위에 존재하는 grayscale값이 0이 아닌 픽셀들을 계산하여 총 면적 계산 및 라벨링 진행

    cv::Point present_pt = start_pt;//present_pt의 값을 초기 값인 start_pt로 초기화
    m_area=1;//면적 값 m_area 초기화
    const int Visit[4] = {-1, 1, -m_width, m_width};    //4방위에 대한 배열 선언   //왼,오,상,하

    //픽셀 데이터를 계산 완료 할때까지 무한반복
    for(;;)
    {
        //nowIdx값 초기화 - 해당 값은 반복문 한 사이클이 돌 때마다 초기화됨
        unsigned int nowIdx=(present_pt.y * m_width) +  present_pt.x;

        if(present_pt.x != 0 &&
                m_isVisited[nowIdx + Visit[LEFT]] == false &&
                m_Image.data[nowIdx + Visit[LEFT]] != 0)
            //현재 포인트가 0이 아니고, W방향 픽셀에 방문전적이 없고, 픽셀 데이터가 0이 아닐때(검은색이 아닐때) 다음 코드 실행
        {
            m_isVisited[nowIdx + Visit[LEFT]] = true; //방문전적 저장
            m_Image.data[nowIdx + Visit[LEFT]] = m_Image.data[nowIdx]; //헤딩 픽셀 값에 데이터 저장
            m_visited_pt[nowIdx + Visit[LEFT]] = present_pt; //방문한 픽셀에 현재 픽셀 저장

            //현재 픽셀의 x에 -1 연산 - 왼쪽 픽셀로 이동
            present_pt.x --;

            //시작 점의 x값이 현재 점의 x값보다 클경우 해당 데이터 저장
            if(start_pt.x > present_pt.x)
                start_pt.x = present_pt.x;
            m_area++; //면적 +1
            continue;
        }

        if(present_pt.x != m_width - 1 &&
                m_isVisited[nowIdx + Visit[RIGHT]] == false &&
                m_Image.data[nowIdx + Visit[RIGHT]] != 0)
        {
            m_isVisited[nowIdx + Visit[RIGHT]] = true;
            m_Image.data[nowIdx + Visit[RIGHT]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[RIGHT]] = present_pt;

            //현재 픽셀의 x에 +1 연산 - 오른쪽 픽셀로 이동
            present_pt.x ++;

            //끝 점의 x값이 현재 점의 x값보다 작을경우 해당 데이터 저장
            if(end_pt.x < present_pt.x)
                end_pt.x = present_pt.x;
            m_area++;
            continue;
        }

        if(present_pt.y != 0 &&
                m_isVisited[nowIdx + Visit[UP]] == false &&
                m_Image.data[nowIdx + Visit[UP]] != 0)
        {
            m_isVisited[nowIdx + Visit[UP]] = true;
            m_Image.data[nowIdx + Visit[UP]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[UP]] = present_pt;

            //현재 픽셀의 y에 -1 연산 - 위 픽셀로 이동
            present_pt.y --;

            //시작 점의 y값이 현재 점의 y값보다 클경우 해당 데이터 저장
            if(start_pt.y > present_pt.y)
                start_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        if(present_pt.y != m_height - 1 &&
                m_isVisited[nowIdx + Visit[DOWN]] == false &&
                m_Image.data[nowIdx + Visit[DOWN]] != 0)
        {
            m_isVisited[nowIdx + Visit[DOWN]] = true;
            m_Image.data[nowIdx + Visit[DOWN]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[DOWN]] = present_pt;

            //현재 픽셀의 y에 +1 연산 - 아래 픽셀로 이동
            present_pt.y ++;

            //끝 점의 y값이 현재 점의 y값보다 작을경우 해당 데이터 저장
            if(end_pt.y < present_pt.y)
                end_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        //더이상 이동할 픽셀이 없을 경우 반복문 종료
        if(m_visited_pt[nowIdx] == present_pt)    break;
        present_pt = m_visited_pt[nowIdx];
    }
    //면적 값 반환
    return m_area;
}

const unsigned int RobitLabeling::__check_eight_neighbor(cv::Point &start_pt, cv::Point &end_pt)
{
    //PRE CONDITION : start_pt, end_pt
    //POST CONDITION : m_Image.data
    //PURPOSE : start_pt부터 시작하여 근처 8방위에 존재하는 grayscale값이 0이 아닌 픽셀들을 계산하여 총 면적 계산 및 라벨링 진행

    cv::Point present_pt = start_pt;//present_pt의 값을 초기 값인 start_pt로 초기화
    m_area=1;//면적 값 m_area 초기화

    //8방위에 대한 배열 선언
    const int Visit[8] = {-1, -m_width -1, -m_width, -m_width + 1,
                          1, m_width + 1,  m_width,  m_width - 1};

    //픽셀 데이터를 계산 완료 할때까지 무한반복
    for(;;)
    {
        //nowIdx값 초기화 - 해당 값은 반복문 한 사이클이 돌 때마다 초기화됨
        unsigned int nowIdx=(present_pt.y * m_width) +  present_pt.x;

        if(present_pt.x != 0 &&
                m_isVisited[nowIdx + Visit[W]] == false &&
                m_Image.data[nowIdx + Visit[W]] != 0)
            //현재 포인트가 0이 아니고, W방향 픽셀에 방문전적이 없고, 픽셀 데이터가 0이 아닐때(검은색이 아닐때) 다음 코드 실행
        {
            m_isVisited[nowIdx + Visit[W]] = true; //방문전적 저장
            m_Image.data[nowIdx + Visit[W]] = m_Image.data[nowIdx]; //헤딩 픽셀 값에 데이터 저장
            m_visited_pt[nowIdx + Visit[W]] = present_pt; //방문한 픽셀에 현재 픽셀 저장

            //현재 픽셀의 x에 -1 연산 - 왼쪽 픽셀로 이동
            present_pt.x --;

            //시작 점의 x값이 현재 점의 x값보다 클경우 해당 데이터 저장
            if(start_pt.x > present_pt.x)
                start_pt.x = present_pt.x;
            m_area++; //면적 +1
            continue;
        }

        if(present_pt.x != 0 &&
                present_pt.y != 0 &&
                m_isVisited[nowIdx + Visit[NW]] == false &&
                m_Image.data[nowIdx + Visit[NW]] != 0)
        {
            m_isVisited[nowIdx + Visit[NW]] = true;
            m_Image.data[nowIdx + Visit[NW]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[NW]] = present_pt;

            //현재 픽셀의 x y에 -1 연산 - 왼쪽위 픽셀로 이동
            present_pt.x --;
            present_pt.y --;

            //시작 점의 x값이 현재 점의 x값보다 클경우 해당 데이터 저장
            if(start_pt.x > present_pt.x)
                start_pt.x = present_pt.x;

            //시작 점의 y값이 현재 점의 y값보다 클경우 해당 데이터 저장
            if(start_pt.y > present_pt.y)
                start_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        if(present_pt.y != 0 &&
                m_isVisited[nowIdx + Visit[N]] == false &&
                m_Image.data[nowIdx + Visit[N]] != 0)
        {
            m_isVisited[nowIdx + Visit[N]] = true;
            m_Image.data[nowIdx + Visit[N]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[N]] = present_pt;

            //현재 픽셀의 y에 -1 연산 - 위 픽셀로 이동
            present_pt.y --;

            //시작 점의 y값이 현재 점의 y값보다 클경우 해당 데이터 저장
            if(start_pt.y > present_pt.y)
                start_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        if(present_pt.x != m_width - 1 &&
                present_pt.y != 0 &&
                m_isVisited[nowIdx + Visit[NE]] == false &&
                m_Image.data[nowIdx + Visit[NE]] != 0)
        {
            m_isVisited[nowIdx + Visit[NE]] = true;
            m_Image.data[nowIdx + Visit[NE]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[NE]] = present_pt;

            //현재 픽셀의 y에 -1 x에 +1 연산 - 오른쪽 위 픽셀로 이동
            present_pt.x ++;
            present_pt.y --;

            //끝 점의 x값이 현재 점의 x값보다 작을경우 해당 데이터 저장
            if(end_pt.x < present_pt.x)
                end_pt.x = present_pt.x;

            //시작 점의 y값이 현재 점의 y값보다 클경우 해당 데이터 저장
            if(start_pt.y > present_pt.y)
                start_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        if(present_pt.x != m_width - 1 &&
                m_isVisited[nowIdx + Visit[E]] == false &&
                m_Image.data[nowIdx + Visit[E]] != 0)
        {
            m_isVisited[nowIdx + Visit[E]] = true;
            m_Image.data[nowIdx + Visit[E]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[E]] = present_pt;

            //현재 픽셀의 x에 +1 연산 - 오른쪽 픽셀로 이동
            present_pt.x ++;

            //끝 점의 x값이 현재 점의 x값보다 작을경우 해당 데이터 저장
            if(end_pt.x < present_pt.x)
                end_pt.x = present_pt.x;
            m_area++;
            continue;
        }

        if(present_pt.x != m_width - 1 &&
                present_pt.y != m_height - 1 &&
                m_isVisited[nowIdx + Visit[SE]] == false &&
                m_Image.data[nowIdx + Visit[SE]] != 0)
        {
            m_isVisited[nowIdx + Visit[SE]] = true;
            m_Image.data[nowIdx + Visit[SE]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[SE]] = present_pt;

            //현재 픽셀의 x y에 +1 연산 - 오른쪽 아래 픽셀로 이동
            present_pt.x ++;
            present_pt.y ++;

            //끝 점의 x값이 현재 점의 x값보다 작을경우 해당 데이터 저장
            if(end_pt.x < present_pt.x)
                end_pt.x = present_pt.x;

            //끝 점의 y값이 현재 점의 y값보다 작을경우 해당 데이터 저장
            if(end_pt.y < present_pt.y)
                end_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        if(present_pt.y != m_height - 1 &&
                m_isVisited[nowIdx + Visit[S]] == false &&
                m_Image.data[nowIdx + Visit[S]] != 0)
        {
            m_isVisited[nowIdx + Visit[S]] = true;
            m_Image.data[nowIdx + Visit[S]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[S]] = present_pt;

            //현재 픽셀의 y에 +1 연산 - 아래 픽셀로 이동
            present_pt.y ++;

            //끝 점의 y값이 현재 점의 y값보다 작을경우 해당 데이터 저장
            if(end_pt.y < present_pt.y)
                end_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        if(present_pt.x != 0 &&
                present_pt.y != m_height - 1 &&
                m_isVisited[nowIdx + Visit[SW]] == false &&
                m_Image.data[nowIdx + Visit[SW]] != 0)
        {
            m_isVisited[nowIdx + Visit[SW]] = true;
            m_Image.data[nowIdx + Visit[SW]] = m_Image.data[nowIdx];
            m_visited_pt[nowIdx + Visit[SW]] = present_pt;

            //현재 픽셀의 x에 -1 y에 +1 연산 - 왼쪽 아래 픽셀로 이동
            present_pt.x --;
            present_pt.y ++;

            //시작 점의 x값이 현재 점의 x값보다 클경우 해당 데이터 저장
            if(start_pt.x > present_pt.x)
                start_pt.x = present_pt.x;

            //끝 점의 y값이 현재 점의 y값보다 작을경우 해당 데이터 저장
            if(end_pt.y < present_pt.y)
                end_pt.y = present_pt.y;
            m_area++;
            continue;
        }

        //더이상 이동할 픽셀이 없을 경우 반복문 종료
        if(m_visited_pt[nowIdx] == present_pt)    break;
        present_pt = m_visited_pt[nowIdx];
    }
    //면적 값 반환
    return m_area;
}

bool RobitLabeling::mergeArea(Mat &ImgOrg){
    //PRE CONDITION : m_Image.data, ImgOrg
    //POST CONDITION : blob합성, drawing
    //PURPOSE : 특정 값 이하의 블랍 삭제 및 블랍 합성, 컨투어 적용

    const int IMGSIZE = ImgOrg.size().area();

    for(int i = 0; i<IMGSIZE; i++){
        if( !m_Image.data[i] )
            m_Image_Obj.data[i] = 0;
    }

    bool isField = 0;

    cv::Point pastCen(0,0);

    for(int i = 0; i< m_nBlobs; i++){
        const int sX = m_recBlobs[i].x;
        const int sY = m_recBlobs[i].y;

        const int eX = m_recBlobs[i].x + m_recBlobs[i].width;
        const int eY = m_recBlobs[i].y + m_recBlobs[i].height;

        if(m_recBlobs[i].size().area() < 10000){
            for(int y = sY, idxY = sY * m_width; y<eY;y++, idxY += m_width){
                for(int x = sX; x < eX; x++)
                {
                    if(m_Image.data[idxY + x] == i + 1)
                        m_Image_Obj.data[idxY + x] = 0;
                }
            }
            continue;
        }      //블랍중에 n보다 작은크기의 블랍을 제거

        isField = true;

        int CenX = 0, CenY = 0, nCount = 0;
        Point exceptionPt;

        for(int fieldY = sY, fieldIdxY = sY * m_width; fieldY < eY; fieldY++, fieldIdxY += m_width)// y고정하고 밑에 for문에서 x++ 밑에 for문 끝나면 가로 크기 만큼 더한다(여기서는 fieldIdxY += img_bg.cols 이 부분)
        {
            for(int fieldX = sX; fieldX < eX; fieldX++)
            {
                if(m_Image.data[fieldIdxY + fieldX] == i + 1)
                {
                    CenX += fieldX;
                    CenY += fieldY;
                    nCount++;
                    exceptionPt.x = fieldX;
                    exceptionPt.y = fieldY;
                }
            }
        }

        if(nCount != 0)
        {
            CenX /= nCount;
            CenY /= nCount;

            if(m_Image.data[CenY * m_width + CenX] != i + 1)
            {
                CenX = exceptionPt.x;
                CenY = exceptionPt.y;
            }
        }


        if(pastCen.x != 0 && pastCen.y != 0)
        {
            if(cv::norm(Point(CenX, CenY) - exceptionPt) < 1500)
            {
                cv::line(m_Image,
                         pastCen,
                         Point(CenX, CenY),
                         Scalar(16),
                         3
                         );
            }
        }

        pastCen.x = CenX;
        pastCen.y = CenY;
        //블랍들을 합쳐서 하나의 큰 에리어로 합치는 과정
    }

    if(isField){
        vector< vector< Point > >contours;
        vector< Vec4i >hierarchy;


        cv::Mat img_contour = m_Image;


        cv::findContours(img_contour, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));
        vector< vector< Point > >hull(contours.size());

        for(size_t s = 0; s < contours.size(); s++) convexHull(Mat(contours[s]), hull[s], false);

        drawing = Mat::zeros(img_contour.size(), CV_8UC1);
        Mat drawingContours = Mat::zeros(img_contour.size(), CV_8UC1);

        int maxContours = -1;
        int maxSize = 0;

        for(size_t s = 0; s < contours.size(); s++)
        {
            if(hierarchy[s][3] != -1)    continue;

            int nowSize = contours[s].size();
            if(nowSize > maxSize)
            {
                maxSize = nowSize;
                maxContours = s;
            }

            cv::drawContours(drawing, hull, s, Scalar(69), 2, 8, hierarchy, 0, Point());

            cv::drawContours(drawingContours, contours, s, Scalar(70), 2, 8, hierarchy, 0, Point());

        }

        if(maxContours != -1)
        {
            cv::drawContours(ImgOrg, hull, (size_t)maxContours, Scalar(100, 255, 0), 3, 8, hierarchy, 0, Point());
        }

    }

    return isField;
}

void RobitLabeling::eraseOutField(Mat &Img,Mat& Img2, int nMore,Mat &imgOrg){

    /////////////////////////////////////////////////////////////////////////////////////////////////////////// x->y+->y-
    //PRE CONDITION : Img, Img2, imgOrg, nMore, drawing
    //POST CONDITION : blob합성
    //PURPOSE : 맵 추출 및 배경 제거


    for(int x = 0; x < drawing.cols; x++)
    {
        for(int y = 0; y < drawing.rows; y++)
        {
            Img.data[y*drawing.cols + x] = 0;
            //            Img2.data[y*drawing.cols + x] = 0;

            imgOrg.at<Vec3b>(y,x) = Vec3b(0,0,0);//배경제거
            Img2.at<Vec3b>(y,x) = Vec3b(0,0,0);//배경제거




            if(drawing.data[y*drawing.cols + x] == 69)  //69
            {
                for(int i = 1; i <= nMore; i++){
                    if(y+i >= drawing.rows) break;

                    Img.data[(y+i)*drawing.cols + x] = 0;
                    //                        Img2.data[(y+i)*drawing.cols + x] = 0;

                }
                break;
            }
        }

        for(int y = drawing.rows-1; y >= 0; y--)
        {
            Img.data[y*drawing.cols + x] = 0;
            //            Img2.data[y*drawing.cols + x] = 0;

            imgOrg.at<Vec3b>(y,x) = Vec3b(0,0,0);//배경제거
            Img2.at<Vec3b>(y,x) = Vec3b(0,0,0);//배경제거

            if(drawing.data[y*drawing.cols + x] == 69)
            {
                for(int i = 1; i <= nMore; i++){
                    if(y- i < 0) break;

                    Img.data[(y-i)*drawing.cols + x] = 0;
                    //                        Img2.data[(y-i)*drawing.cols + x] = 0;

                }
                break;
            }
            //blackbottom();


        }
    }
    //////////////////////////////////////////////////////////////////////////////////////////////////// y->x+->x-
    //    for(int y = 0; y < drawing.rows; y++)
    //    {
    //        for(int x = 0; x < drawing.cols; x++)
    //        {
    //            Img.data[x*drawing.rows + y] = 0;


    //            if(drawing.data[x*drawing.rows + y] == 69)  //69
    //            {
    //                for(int i = 1; i <= nMore; i++){
    //                    if(x+i >= drawing.cols) break;

    //                        Img.data[(x+i)*drawing.rows + y] = 0;

    //                }
    //                break;
    //            }
    //        }

    //        for(int x = drawing.cols-1; x >= 0; x--)
    //        {
    //            Img.data[x*drawing.rows + y] = 0;


    //            if(drawing.data[x*drawing.rows + y] == 69)
    //            {
    //                for(int i = 1; i <= nMore; i++){
    //                    if(x-i < 0) break;

    //                        Img.data[(x-i)*drawing.rows + y] = 0;

    //                }
    //                break;
    //            }
    //        }
    //    }
    /////////////////////////////////////////////////////////////////////////////////////////////////////////
    //    for(unsigned int i = 0; i < IMGSIZE; i++)
    //    {
    //        if(m_Image.data[i] == 255)
    //        {
    //            Img.data[i] = 0;


    //        }


    //    }

    /////////////////////////////////////////////////////////////////////////////////////////////////////////


}

void RobitLabeling::eraseTopBlob(const cv::Mat &binaryImg, cv::Mat &imgToModify) {
    // °¡Àå Å« ºí·ÓÀÇ °æ°è »óÀÚ Ã£±â
    int topY = findTopYOfLargestBlob(binaryImg);

    if (topY == -1) {
        std::cerr << "No blobs found in the image!" << std::endl;
        return;
    }

    // ¸Ç À§ ÇÈ¼¿ºÎÅÍ ÀÌ¹ÌÁöÀÇ ¸Ç À§±îÁö ¸ðµç ÇÈ¼¿ÀÇ °ªÀ» 0À¸·Î ¼³Á¤
    for (int y = topY; y >= 0; y--) {
        for (int x = 0; x < imgToModify.cols; x++) {
            imgToModify.at<cv::Vec3b>(y, x) = cv::Vec3b(0, 0, 0); // ÇÈ¼¿À» °ËÁ¤»öÀ¸·Î ¼³Á¤
        }
    }
}

int RobitLabeling::findTopYOfLargestBlob(const cv::Mat &binaryImg) {
    // ÀÌÁø ÀÌ¹ÌÁö¿¡¼­ À±°û¼± Ã£±â
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(binaryImg, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // °¡Àå Å« ºí·Ó Ã£±â
    int maxArea = 0;
    int maxIndex = -1;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = static_cast<int>(area);
            maxIndex = static_cast<int>(i);
        }
    }

    // °¡Àå Å« ºí·ÓÀÇ ÃÖ»ó´Ü y ÁÂÇ¥ ¹ÝÈ¯
    if (maxIndex != -1) {
        int topY = binaryImg.rows;
        for (const cv::Point &pt : contours[maxIndex]) {
            if (pt.y < topY) {
                topY = pt.y;
            }
        }
        return topY;
    } else {
        return -1; // ºí·ÓÀÌ ¾ø´Â °æ¿ì
    }
}

cv::Rect RobitLabeling::findLargestBlob(const cv::Mat &binaryImg) {
    // ÀÌÁø ÀÌ¹ÌÁö¿¡¼­ À±°û¼± Ã£±â
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;
    cv::findContours(binaryImg, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);

    // °¡Àå Å« ºí·Ó Ã£±â
    int maxArea = 0;
    int maxIndex = -1;
    for (size_t i = 0; i < contours.size(); i++) {
        double area = cv::contourArea(contours[i]);
        if (area > maxArea) {
            maxArea = static_cast<int>(area);
            maxIndex = static_cast<int>(i);
        }
    }

    // °¡Àå Å« ºí·ÓÀÇ °æ°è »óÀÚ ¹ÝÈ¯
    if (maxIndex != -1) {
        return cv::boundingRect(contours[maxIndex]);
    } else {
        return cv::Rect(); // ºó »ç°¢Çü ¹ÝÈ¯
    }
}

RobitLabeling::~RobitLabeling()
{
    m_Image.release();
}


RobitLineDetect::RobitLineDetect()
    : RobitLabeling()
{

}

RobitLineDetect::RobitLineDetect(const Mat &Img,
                                 const unsigned int &nThreshold,
                                 const unsigned int &nNeighbor)
    : RobitLabeling(Img, nThreshold, nNeighbor)
{

}

RobitLineDetect::RobitLineDetect(const RobitLabeling& labels)
{

}

void RobitLineDetect::findLineFeatures()
{

}

RobitLineDetect::~RobitLineDetect()
{

}
