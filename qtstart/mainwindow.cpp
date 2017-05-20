#include "mainwindow.h"

#include <QApplication>

MainWindow::MainWindow()
{
    QTextCodec::codecForName ("UTF-8");

   //createMenus();
   // createStatusBar();
    label = new QLabel(tr("Weather forecast"), this);
    label->setGeometry(5, 15, 150, 30);

    button = new QPushButton(tr("&Exit"), this);
    button->setGeometry(5, 75, 100, 30);


    butlab = new QPushButton(tr("&Start"), this);
    butlab->setGeometry(5, 45, 100, 30);


    connect(button, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(butlab, SIGNAL(clicked()), this, SLOT(runApp()));

    setMinimumSize(200, 200);
    resize(480, 320);
}

void MainWindow::runApp()
{
    ProgramHandler pr;
    pr.startApp("../prog");
}

void MainWindow::createMenus()
{
    menu = menuBar()->addMenu(tr("&Plik"));

    quitAction = new QAction(tr("&Wyjście"), this);
    quitAction->setStatusTip(tr("Wyjdź z programu."));
    connect (quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
    menu->addAction(quitAction);
}

void MainWindow::createStatusBar()
{
    statusBar()->showMessage(tr("Gotowy"));
}
