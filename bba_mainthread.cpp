#include "bba_mainthread.h"
#include "bba_objectdetect.h"
#include "bba_facerecognizer.h"


#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <iostream>
#include <qdebug.h>
#include <QTime>

using namespace std;
using namespace cv;
BBA_MainThread::BBA_MainThread()
{

}

void BBA_MainThread::run()
{
    Ui::MainWindow *ui=(Ui::MainWindow*)this->cp_ui;

    VideoCapture capture(0);    // 打开摄像头
    if(!capture.isOpened())    // 判断是否打开成功
    {
        cout << "open camera failed. " << endl;

    }

    //用于计时
    QTime head,tail;
    int finishTime=0,sum=0,count=0;

    Mat mat,matShow,matTemp;
    //mat=imread("./2.jpg");

    QImage Img;
    char strPath[50];
    BBA_ObjectDetect detect;
    //detect.start();
    BBA_FaceRecognizer faceRecognizer;
    faceRecognizer.Train();
    //faceRecognizer.LoadModel(strPath);
    while(1)
    {
        head=QTime::currentTime();
        capture>>mat;
        mat.copyTo(matTemp);
        matTemp.copyTo(detect.imageSource);
        detect.ObjDetect();
        detect.MarkObject(&matTemp);
        cvtColor(matTemp, matShow, COLOR_BGR2RGB);//颜色空间转换
        if (mat.channels() == 3)//RGB Img
        {
            Img = QImage((const uchar*)(matShow.data), matShow.cols, matShow.rows, matShow.cols * matShow.channels(), QImage::Format_RGB888);
        }
        else//Gray Img
        {
            Img = QImage((const uchar*)(matShow.data), matShow.cols, matShow.rows, matShow.cols*matShow.channels(), QImage::Format_Indexed8);
        }
        ui->ImageShow->setPixmap(QPixmap::fromImage(Img));

        tail=QTime::currentTime();
        finishTime=1000 * (tail.second()-head.second())+ (tail.msec()-head.msec());
        finishTime=1000/finishTime;
        sum+=finishTime;
        if(++count>=10)
        {
            count=0;
            sum=sum/10;
            QString str=QString::number(sum,10);
            ui->m_FPS->setText(str);
            sum=0;
        }

        if(m_capture)
        {
            m_capture=0;
            static int num=0;
            char temp[20];

            cvtColor(matTemp,matTemp,COLOR_BGR2GRAY);
            Mat faceROI = matTemp(detect.faces[0]);//在灰度图中将圈出的脸所在区域裁剪出
            sprintf(temp,"./faces/%d.jpg",num++);
            imwrite(temp,faceROI);

        }

        //sleep(1);
        //msleep(500);

    }
}
