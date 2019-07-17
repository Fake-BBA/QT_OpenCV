#ifndef BBA_FACERECOGNIZER_H
#define BBA_FACERECOGNIZER_H

#include <vector>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>

#include <opencv2/face/facerec.hpp>
#include <opencv2/face.hpp>

using namespace std;
using namespace cv;
using namespace cv::face;

class BBA_FaceRecognizer
{
public:
    BBA_FaceRecognizer();
    ~BBA_FaceRecognizer();
    
public:
    // 2个容器来存放图像数据和对应的标签
    vector<Mat> images;
    vector<int> labels;
    Ptr<BasicFaceRecognizer> model_Eigen;
    Ptr<FisherFaceRecognizer> model_Fisher;
    Ptr<LBPHFaceRecognizer> model_LBP;

    int LoadModel(char *path);
    int AddModelSets();
    int Train();
    float Recognizer(Mat src);
};

#endif // BBA_FACERECOGNIZER_H
