#ifndef YOLOV4_H
#define YOLOV4_H

#include <opencv2/opencv.hpp>
#include <opencv2/core/utility.hpp>
#include <opencv2/core/ocl.hpp>
#include <opencv2/video/tracking.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/dnn/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

#include <ctime>
#include <random>





using namespace std;
using namespace cv;
using namespace dnn;

class YOLOV4
{
public:
    //For Init
    YOLOV4()
    {
        YOLO = cv::dnn::readNet(model_name);
//        YOLO = cv::dnn::readNetFromDarknet(cfg_name, weight_name);
        YOLO.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        YOLO.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);
    }

    //For Open Model
    string model_name = "/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/best256x192v8.onnx";
    string cfg_name =  "/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls3-v7.cfg"; //"/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls2-v4.cfg"; //"/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls2-v4.cfg";
    string weight_name =  "/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls3-v7_100000.weights"; //"/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls2-v4_final.weights"; //"/home/robit/catkin_ws/src/robocup_vision24_obstacle/net/yolov4-tiny-1ch-cls2-v4_final.weights";
    //For Model Param
    int NUM_CLASSES = 3;
    double CONFIDENCE_THRESHOLD = 0.1;
    double SCORE_THRESHOLD_B = 0.8;
    double NMS_THRESHOLD_B = 0.8;
    double SCORE_THRESHOLD_L = 0.5;
    double NMS_THRESHOLD_L = 0.5;
    double SCORE_THRESHOLD_R = 0.5;
    double NMS_THRESHOLD_R = 0.5;
    //    double SCORE_THRESHOLD_X = 0.5;
    //    double NMS_THRESHOLD_X = 0.5;
    //For save
    //Rect ago_rect(0,0,0,0);

    //For Run Yolo
    struct YOLO_RESULT
    {
        int NUM;
        double SCORE;
        int X;
        int Y;
        int W;
        int H;
    };

    struct Detection
    {
        int class_id{0};
        std::string className{};
        float confidence{0.0};
        Scalar color{};
        Rect box{};
    };

    YOLO_RESULT yolo_result;
    vector<YOLO_RESULT> vector_yolo;

    vector<YOLO_RESULT> YoloRun(const cv::Mat& img)
    {
        Mat image = img.clone();
        cv::resize(image, image, Size(640, 480));
//        cvtColor(image, image, COLOR_BGR2GRAY);

//        Ptr<CLAHE> clahe = createCLAHE();
//        clahe->setClipLimit(2);
//        clahe->apply(image,image);

        //        cout<<image.channels()<<endl;
        Mat blob;

//        blobFromImage(image, blob, 1.0/255.0, Size(256, 192), true, false);

        vector<cv::Mat> detections;
        //        blobFromImage(imgae, 1.0/225.0, Size(256, 192), Scalar(255, 0, 0), true, false);
        Mat inputBlob = /*blobFromImage(image, 1.0/225.0, Size(256, 192), Scalar(255, 0, 0), true, false);*/ blobFromImage(image, 1.0/225.0, Size(256, 192));
        YOLO.setInput(inputBlob);
        YOLO.forward(detections, YOLO.getUnconnectedOutLayersNames());

        int rows;
        int dimensions;


        rows = detections[0].size[2];
        dimensions = detections[0].size[1];

        detections[0] = detections[0].reshape(1, dimensions);
        cv::transpose(detections[0], detections[0]);

        float *data = (float *)detections[0].data;

        float x_factor = img.cols / 640;
        float y_factor = img.rows / 480;

        vector<std::string> classes{"ball", "line", "robot", "xcross"};
        float modelScoreThreshold   {0.45};
        float modelNMSThreshold   {0.50};

        vector<int> indices[NUM_CLASSES]; //class_ids
        vector<cv::Rect> boxes[NUM_CLASSES]; //boxex
        vector<float> scores[NUM_CLASSES]; //confidences

        vector<int> class_ids; //class_ids
        vector<cv::Rect> boxex; //boxex
        vector<float> confidences; //confidences

        //class_id는 0으로 고정됨 << 생각해보니 당연함
        //탐지된 물체는 여러개임
        //confidence값은 높음
        //공밖에 안잡음 << 공만 되는건데 개같이 되는건지, 공 이외에 다른것도 잡는데 그게 섞여서 그런건지
        //rows : 1008 dimensions : 8로 고정됨

//        cout << "rows           " << rows << endl;
//        cout << "dimensions     " << dimensions << endl;

        for(int i = 0 ; i < rows ; ++i)
        {
//            cout << "something detected            1" << endl;
            float *classes_scores = data + 4;

            Mat scores(1, classes.size(), CV_32FC1, classes_scores);
            Point class_id;
            double maxClassScore;

            minMaxLoc(scores, 0, &maxClassScore, 0, &class_id);

            if(class_id.x == 0)
            {
//                cout << "class_id :      " << class_id.x << endl;
//                cout << "something classified            2" << endl;
                if(maxClassScore > modelScoreThreshold)
                {
//                    cout << "something catched            3" << endl;
                    confidences.push_back(maxClassScore);
                    class_ids.push_back(class_id.x);

                    float x = data[0];
                    float y = data[1];
                    float w = data[2];
                    float h = data[3];

                    int left = int((x - 0.5 * w) * x_factor);
                    int top = int((y - 0.5 * h) * y_factor);

                    int width = int(w * x_factor);
                    int height = int(h * y_factor);

                    boxex.push_back(Rect(left, top, width, height));
                }
            }

            data += dimensions;
        }

        vector<int> nms_result;
        cv::dnn::NMSBoxes(boxex, confidences, modelScoreThreshold, modelNMSThreshold, nms_result);

        vector<YOLO_RESULT> detection{};
        for (unsigned long i = 0; i < nms_result.size(); ++i)
        {
//            cout << "something objection            4" << endl;
            int idx = nms_result[i];

            YOLO_RESULT result;
            result.NUM = class_ids[idx];
            result.SCORE = confidences[idx];

            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<int> dis(100, 255);
//            result.color = cv::Scalar(dis(gen),
//                                      dis(gen),
//                                      dis(gen));

//            result.className = classes[result.class_id];
            cout << nms_result.size() << endl;
            cout << "CONFIDENCE :       " << confidences[idx] << endl;
            cout << classes[class_ids[idx]] << endl;
            result.X = boxex[idx].x;
            result.Y = boxex[idx].y;
            result.W = boxex[idx].width;
            result.H = boxex[idx].height;

//            result.box = boxex[idx];

            detection.push_back(result);
        }

        return detection;

        //////////////////////////////////////////////////////////////////////////



//        for (auto& output : detections)
//        {
//            cout << "11" << endl;
//            const auto num_boxes = output.rows;
//            for (int i = 0; i < num_boxes; i++)
//            {
//                cout << "22" << endl;
//                auto x = output.at<float>(i, 0) * image.cols;
//                auto y = output.at<float>(i, 1) * image.rows;
//                auto width = output.at<float>(i, 2) * image.cols;
//                auto height = output.at<float>(i, 3) * image.rows;
//                cv::Rect rect(x - width/2, y - height/2, width, height);

//                for (int c = 0; c < NUM_CLASSES; c++)
//                {
//                    cout << "33" << endl;
//                    auto confidence = *output.ptr<float>(i, 5 + c);
//                    if (confidence >= CONFIDENCE_THRESHOLD)
//                    {
//                        cout << "44" << endl;
//                        boxes[c].push_back(rect);
//                        scores[c].push_back(confidence);
//                    }
//                }
//            }
//        }
//        vector<YOLO_RESULT> result;
//        for (int c = 0; c < NUM_CLASSES; c++)
//        {
//            cout << "55" << endl;
//            if(c == 0)
//            {
//                cv::dnn::NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_B, NMS_THRESHOLD_B, indices[c]);
//                cout << "66" << endl;
//            }
//            else if(c == 1)
//            {
//                cv::dnn::NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_L, NMS_THRESHOLD_L, indices[c]);
//                cout << "77" << endl;
//            }
//            else if(c == 2)
//            {
//                cv::dnn::NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_R, NMS_THRESHOLD_R, indices[c]);
//                cout << "88" << endl;
//            }
//            //            else if(c == 3)
//            //            {
//            //                cv::dnn::NMSBoxes(boxes[c], scores[c], SCORE_THRESHOLD_X, NMS_THRESHOLD_X, indices[c]);
//            //            }
//        }
//        for (int c = 0; c < NUM_CLASSES; c++)
//        {
//            cout << "1010" << endl;
//            for (size_t i = 0; i < indices[c].size(); ++i)
//            {
//                cout << "1111" << endl;
//                auto idx = indices[c][i];
//                const auto& rect = boxes[c][idx];
//                yolo_result.NUM = c;
//                yolo_result.SCORE = scores[c][idx];
//                yolo_result.X = rect.x;
//                yolo_result.Y = rect.y;
//                yolo_result.W = rect.width;
//                yolo_result.H = rect.height;
//                result.push_back(yolo_result);
//            }
//        }
//        return result;
    }



private:
    Net YOLO;

};




#endif // YOLOV4_H
