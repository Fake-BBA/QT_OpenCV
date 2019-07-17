#ifndef BBA_MAINTHREAD_H
#define BBA_MAINTHREAD_H


#include <QThread>
#include <QMutex>

class BBA_MainThread:public QThread
{
public:
    void* cp_ui;
    bool m_capture;
public:
    BBA_MainThread();
    void run();
};

#endif // BBA_MAINTHREAD_H
