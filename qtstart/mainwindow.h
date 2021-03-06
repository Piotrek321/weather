#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QMenu>
#include <QInputDialog>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QTextCodec>
#include <QShortcut>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "../inc/ProgramHandler.h"
#include "../inc/FileHandler.h"
#include "../inc/MessagingHandler.h"
#include "../inc/Helper.h"
#include <QThread>
#include <QDebug>
#include <signal.h>
#include <errno.h>
#include <mqueue.h>


class myThread;
class MainWindow : public QMainWindow
{
Q_OBJECT

private:
    QPushButton *restartButton;
    QPushButton *startButton;
    QPushButton *exitButton;
    QPushButton *compileButton;
    QPushButton *okButton;
    QPushButton *cleanButton;
    myThread * t;

    QLabel *label;
    std::shared_ptr<MessagingHandler> messagingHandler;
    std::shared_ptr<ProgramHandler> progHandler;
    QMenu *menu;
    QAction *quitAction;
    QLineEdit * lnEdit;
    QShortcut * shortcut;
    mqd_t messageQueueHandler;
    std::string cityName;
    void createMenus();
    void createStatusBar();

public:
    MainWindow();
    ~MainWindow()
    {}

private slots:
    void runApp();
    void compile();
    void getData();
    void restart();
    void clean();
    void exit();
    //void lineChanged(const QString &txt);


};

#endif // MAINWINDOW_HPP
