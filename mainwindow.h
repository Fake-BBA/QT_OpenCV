#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bba_mainthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_m_Capture_clicked();

private:
    Ui::MainWindow *ui;
    BBA_MainThread *bbaMain;
};

#endif // MAINWINDOW_H
