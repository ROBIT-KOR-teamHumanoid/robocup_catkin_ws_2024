#ifndef YOLOV4_H
#define YOLOV4_H
#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>

using namespace std;
using namespace cv;
using namespace dnn;

class YOLOV4
{
public:
    // 초기화
    YOLOV4()
    {
        // 모델 로드
//        YOLO = readNet(model_name);
        YOLO = readNetFromDarknet(cfg_name, weight_name);
        YOLO.setPreferableBackend(DNN_BACKEND_OPENCV);
        YOLO.setPreferableTarget(DNN_TARGET_CPU);
    }

    // 모델 경로
    string model_name = "/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/best256v8.onnx";
    string cfg_name = "/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls3-v7.cfg";
    string weight_name = "/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls3-v7_100000.weights";

    // 모델 파라미터
    int NUM_CLASSES = 3;
    double CONFIDENCE_THRESHOLD = 0.1;
    double SCORE_THRESHOLD_B = 0.1;
    double NMS_THRESHOLD_B = 0.1;
    double SCORE_THRESHOLD_L = 0.1;
    double NMS_THRESHOLD_L = 0.1;
    double SCORE_THRESHOLD_R = 0.1;
    double NMS_THRESHOLD_R = 0.1;
//    double SCORE_THRESHOLD_X = 0.1;
//    double NMS_THRESHOLD_X = 0.1;

    // YOLO 결과 구조체
    struct YOLO_RESULT
    {
        int NUM;
        double SCORE;
        int X;
        int Y;
        int W;
        int H;
    };
    vector<YOLO_RESULT> vector_yolo;

    // YOLO 실행 함수
    vector<YOLO_RESULT> YoloRun(const Mat& img)
    {
        Mat image = img.clone();
        resize(image, image, Size(640, 480));

        Mat blob;
        vector<Mat> detections;
        Mat inputBlob = blobFromImage(image, 1.0 / 255.0, Size(256, 192), Scalar(0, 0, 0), true, false);
        YOLO.setInput(inputBlob);
        YOLO.forward(detections, YOLO.getUnconnectedOutLayersNames());

        vector<int> indices[NUM_CLASSES];
        vector<Rect> boxes[NUM_CLASSES];
        vector<float> scores[NUM_CLASSES];

        for (auto& output : detections)
        {
            cout <<"11"<<endl;
            const auto num_boxes = output.rows;
            for (int i = 0; i < num_boxes; i++)
            {
                 cout <<"22"<<endl; //x
                float* data = output.ptr<float>(i);
                float x = data[0] * image.cols;
                float y = data[1] * image.rows;
                float width = data[2] * image.cols;
                float height = data[3] * image.rows;
                Rect rect(x - width / 2, y - height / 2, width, height);

                for (int c = 0; c < NUM_CLASSES; c++)
                {
                     cout <<"33"<<endl; //x
                    float confidence = data[5 + c];
                    if (confidence >= CONFIDENCE_THRESHOLD)
                    {
                         cout <<"44"<<endl; //x
                        boxes[c].push_back(rect);
                        scores[c].push_back(confidence);
                    }
                }
            }
        }

        vector<YOLO_RESULT> result;
        for (int c = 0; c < NUM_CLASSES; c++)
        {
             cout <<"55"<<endl;
            if (c == 0)
            {NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_B, NMS_THRESHOLD_B, indices[c]);  cout <<"66"<<endl;}
            else if (c == 1)
            {NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_L, NMS_THRESHOLD_L, indices[c]);  cout <<"77"<<endl;}
            else if (c == 2)
            {NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_R, NMS_THRESHOLD_R, indices[c]);  cout <<"88"<<endl;}
//            else if (c == 3)
//            {NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_X, NMS_THRESHOLD_X, indices[c]);  cout <<"99"<<endl;}
        }

        for (int c = 0; c < NUM_CLASSES; c++)
        {
             cout <<"1010"<<endl;
            for (size_t i = 0; i < indices[c].size(); ++i)
            {
                 cout <<"1111"<<endl; //x
                int idx = indices[c][i];
                const Rect& rect = boxes[c][idx];
                YOLO_RESULT yolo_result;
                yolo_result.NUM = c;
                yolo_result.SCORE = scores[c][idx];
                yolo_result.X = rect.x;
                yolo_result.Y = rect.y;
                yolo_result.W = rect.width;
                yolo_result.H = rect.height;
                result.push_back(yolo_result);
            }
        }

        return result;
    }

private:
    Net YOLO;
};


#endif // YOLOV4_H
