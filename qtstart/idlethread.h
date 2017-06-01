#ifndef IDLETHREAD_H
#define IDLETHREAD_H

#include <QThread>

class idleThread : public QThread
{
public:
    idleThread();
    void run();
    void start();
};

#endif // IDLETHREAD_H
