#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QStatusBar>
#include <QAction>
#include <QTextCodec>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include "../inc/ProgramHandler.h"

class MainWindow : public QMainWindow
{
Q_OBJECT

private:
    QPushButton *button;
    QPushButton *butlab;
    QLabel *label;

    QMenu *menu;
    QAction *quitAction;

    void createMenus();
    void createStatusBar();

public:
    MainWindow();

private slots:
    void runApp();
};

#endif // MAINWINDOW_HPP
