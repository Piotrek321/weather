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
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "../inc/ProgramHandler.h"
#include "../inc/FileHandler.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

private:
    QPushButton *restartButton;
    QPushButton *startButton;
    QPushButton *exitButton;
    QPushButton *compileButton;
    QLabel *label;
    ProgramHandler progHandler;
    QMenu *menu;
    QAction *quitAction;
QLineEdit * lnEdit;
    void createMenus();
    void createStatusBar();

public:
    MainWindow();

private slots:
    void runApp();
    void compile();
    void getData();

};

#endif // MAINWINDOW_HPP
