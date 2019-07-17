#include "bba_objectdetect.h"

BBA_ObjectDetect::BBA_ObjectDetect()
{
    //
    scale=0.5;
    //scale=1.0;

}

BBA_ObjectDetect::~BBA_ObjectDetect()
{

}

void BBA_ObjectDetect::run()
{
    while(1)
    {
        ObjDetect();
    }
}

int BBA_ObjectDetect::MarkObject(Mat *p_mat)
{
    int objectNum=faces.size();
    /*Rect rect;
    for (int i = 0; i < objectNum; i++)
    {
        rect.x=faces[i].x/scale;
        rect.y=faces[i].y/scale;
        rect.width=faces[i].width/scale;
        rect.height=faces[i].height/scale;

        rectangle(*p_mat,rect, Scalar(255, 0, 0), 2, 8, 0);
    }
    */
    for(int i=0;i<faces.size();i++)
        rectangle(*p_mat,faces[i], Scalar(255, 0, 0), 2, 8, 0);
    return objectNum;
}

int BBA_ObjectDetect::ObjDetect()
{
    CascadeClassifier cascada;
    cascada.load("./haarcascade_frontalface_alt2.xml");
    //cascada.load("./lbpcascade_frontalface_improved.xml");
    //cascada.load("./lbpcascade_profileface.xml");
    //cascada.load("./lbpcascade_frontalface.xml");

    Size gSize = Size(imageSource.cols*scale,imageSource.rows*scale);

    Mat imageScreen1;
    Mat imageScreen2;

    //vector<Rect> faces;								//vector容器存检测到的faces


    //usleep(50000);
    // resize(_this->imageSource, imageScreen1,gSize);
    // cvtColor(imageScreen1,imageScreen2,COLOR_BGR2GRAY);
    cvtColor(imageSource,imageScreen1,COLOR_BGR2GRAY);
    resize(imageScreen1, imageScreen2,gSize);
    //变换后的图像进行 直方图均值化 处理,可以增强对比度
    equalizeHist( imageScreen2, imageScreen1 );

    //GaussianBlur();	//高斯滤波
    //1.frame_gray表示的是要检测的输入图像
    //2.faces表示检测到的人脸目标序列,
    //3.1.1表示每次图像尺寸减小的比例
    //4.表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大小都可以检测到人脸表示每一个目标至少要被检测到3次才算是真的目标(因为周围的像素和不同的窗口大小都可以检测到人脸
    /*5.flags–要么使用默认值，要么使用CV_HAAR_DO_CANNY_PRUNING，
        函数将会使用Canny边缘检测来排除边缘过多或过少的区域，
        因为这些区域通常不会是人脸所在区域；opencv3 以后都不用这个参数了*/
    //6. Size(100, 100)为目标的最小尺寸 一般为30*30 是最小的了 也够了
    //7. Size(500, 500)为目标的最大尺寸 其实可以不用这个，opencv会自动去找这个最大尺寸
    //适当调整5,6,7两个参数可以用来排除检测结果中的干扰项。
    //cascada.detectMultiScale(imageScreen, faces, 1.1, 4, CV_HAAR_DO_ROUGH_SEARCH, Size(70, 70), Size(1000, 1000));
    cascada.detectMultiScale(imageScreen1,faces, 1.2, 3, 0, Size(30, 30), gSize);

    //cv::imwrite("./output.jpg",imageScreen1);
    for (int i = 0; i < faces.size(); i++)
    {
        faces[i].x=faces[i].x/scale;
        faces[i].y=faces[i].y/scale;
        faces[i].width=faces[i].width/scale;
        faces[i].height=faces[i].height/scale;
    }
    //识别到的脸用矩形圈出
    // for (int i = 0; i <faces.size(); i++)
    // {
    // 	rectangle(imageScreen,faces[i] , Scalar(255, 0, 0), 2, 8, 0);
    // }
    //continue;
    // cv::circle(imageSource,
    // 		cv::Point(700,380),	//中心点位置
    // 		65,	//半径
    // 		CV_RGB(255, 0,0),	//颜色（红色）
    // 		3);	//厚度

    // cv::putText(imageSource,
    // 			"Fake-BBA",
    // 			cv::Point(600,300),			//文本位置
    // 			cv::FONT_HERSHEY_PLAIN,		//文本类型
    // 			2.0,						//字体大小
    // 			CV_RGB(255, 0,0),
    // 			3);							//文本厚度
}

