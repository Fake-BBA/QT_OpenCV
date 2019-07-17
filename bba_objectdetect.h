#ifndef BBA_OBJECTDETECT_H
#define BBA_OBJECTDETECT_H
#include <QThread>
#include <QMutex>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace cv;
using namespace std;

class BBA_ObjectDetect:public QThread
{
public:
    BBA_ObjectDetect();
    ~BBA_ObjectDetect();
public:
    Mat imageSource;
    Mat imageMark;
    vector<Rect> faces; //vector容器存检测到的faces
    double scale;   //缩放因子

public:
    void run();
    int MarkObject(Mat *p_mat);
    int ObjDetect();

};

#endif // BBA_OBJECTDETECT_H
