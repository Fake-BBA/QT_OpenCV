#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "bba_mainthread.h"

#include <opencv2/opencv.hpp>
using namespace cv;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bbaMain=new BBA_MainThread();

    bbaMain->cp_ui=ui;
    bbaMain->start();
}

MainWindow::~MainWindow()
{
    delete ui;
    bbaMain->quit();
}

void MainWindow::on_m_Capture_clicked()
{
    bbaMain->m_capture=1;
}
