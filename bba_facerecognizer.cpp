#include "bba_facerecognizer.h"


#include <iostream>
#include <fstream>
#include <sstream>

BBA_FaceRecognizer::BBA_FaceRecognizer()
{
    /*
        model_Eigen=EigenFaceRecognizer::create();
        model_Fisher=FisherFaceRecognizer::create();
        model_LBP=LBPHFaceRecognizer::create();
    */
    int a=0;
}

BBA_FaceRecognizer::~BBA_FaceRecognizer()
{

}

int BBA_FaceRecognizer::BBA_FaceRecognizer::LoadModel(char *path)
{
    model_Eigen->read("./BBA_FacePCA_Model.xml");// opencv2用load
    model_Fisher->read("./BBA_FisherModel.xml");// opencv2用load
    model_LBP->read("./BBA_FaceLBPH_Model.xml");// opencv2用load
    return 1;
}

int BBA_FaceRecognizer::AddModelSets()
{
   

    return 0;
}
/*
//使用CSV文件去读图像和标签，主要使用stringstream和getline方法  
void BBA_FaceRecognizer::read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), ifstream::in);//c_str()函数可用可不用，无需返回一个标准C类型的字符串
	if (!file) 
	{
		string error_message = "No valid input file was given, please check the given filename.";
        //CV_Error(CV_StsBadArg, error_message);
	}
	string line, path, classlabel;
	while (getline(file, line)) //从文本文件中读取一行字符，未指定限定符默认限定符为“/n”
	{
		stringstream liness(line);//这里采用stringstream主要作用是做字符串的分割
		getline(liness, path, separator);//读入图片文件路径以分好作为限定符
		getline(liness, classlabel);//读入图片标签，默认限定符
		if (!path.empty() && !classlabel.empty()) //如果读取成功，则将图片和对应标签压入对应容器中
		{

		}
	}
}
*/
int BBA_FaceRecognizer::Train()
{
    char strPath[30];
    for(int i=0;i<11;i++)
    {
        sprintf(strPath,"./faces/%d.jpg",i);
        images.push_back(imread(strPath, 0));
        labels.push_back(0);

    }
    //Ptr<LBPHFaceRecognizer> model_Eigen1=LBPHFaceRecognizer::create();
    //model_LBP->train(images,labels);
    //model_LBP->save("./BBA_FacePCA_Model.xml");
/*


    model_Fisher->train(images,labels);
    model_Fisher->save("./BBA_FaceFisherModel.xml");


    model_LBP->train(images,labels);
    model_LBP->save("./BBA_FaceLBPH_Model.xml");
*/

}

float BBA_FaceRecognizer::Recognizer(Mat imageFace)
{
    //input imageFace,output lable
    /*int predictedLabel = model_Eigen->predict(imageFace);//加载分类器
    predictedLabel = model_Fisher->predict(imageFace);
    predictedLabel = model_LBP->predict(imageFace);
    */
    //return predictedLabel;
    // 还有一种调用方式，可以获取结果同时得到阈值:  
	// int predictedLabel = -1;  
	// double confidence = 0.0;  
	//  model->predict(testSample, predictedLabel, confidence);

}




