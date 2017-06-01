#include "mainwindow.h"

#include <QApplication>

#define ButtonWitdth 30

#define ButtonLength 100

MainWindow::MainWindow()
{
    QTextCodec::codecForName ("UTF-8");
    progHandler = new ProgramHandler("../prog");
   //createMenus();
   // createStatusBar();
    label = new QLabel(tr("Weather forecast"), this);
    label->setGeometry(5, 15, 150, 30);

    compileButton = new QPushButton(tr("&Compile"), this);
    compileButton->setGeometry(0, 0, ButtonLength, ButtonWitdth);

    okButton = new QPushButton(tr("&Ok"), this);
    okButton->setGeometry(300, 210, ButtonLength, ButtonWitdth);

    cleanButton= new QPushButton(tr("&Clean"), this);
    cleanButton->setGeometry(0, 60, ButtonLength, ButtonWitdth);

    restartButton = new QPushButton(tr("&Restart"), this);
    restartButton->setGeometry(0, 90, ButtonLength, ButtonWitdth);

    exitButton = new QPushButton(tr("&Exit"), this);
    exitButton->setGeometry(0, 120, ButtonLength, ButtonWitdth);

    startButton = new QPushButton(tr("&Start"), this);
    startButton->setGeometry(0, 150, ButtonLength, ButtonWitdth);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);

    connect(restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(getData()));
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(runApp()));
    connect(compileButton, SIGNAL(clicked()), this, SLOT(compile()));
    connect(shortcut, SIGNAL(activated()), this, SLOT(getData()));
    connect(cleanButton, SIGNAL(clicked()), this, SLOT(clean()));


    lnEdit = new QLineEdit(this);
    lnEdit->setGeometry(200,200,100,50);
    lnEdit->setText("Hello my id");

    setMinimumSize(200, 200);
    resize(480, 320);
}

void MainWindow::restart()
{
  pid_t pid =  Helper::getPID("prog");
   std::cout <<"PID: " << Helper::getPID("prog") <<std::flush;
  if(pid != 0)
  {
      std::cout <<"Restart of process with PID: " << pid <<std::flush;
      kill(pid, SIGTERM );
      progHandler->performRestart();
  }
  else
  {
      std::cout <<"Process does not exists\n" << std::flush;
  }
}

void MainWindow::getData()
{
  QString str;
  str = lnEdit->text();
  std::cout <<str.toStdString() <<std::flush;
  cityName = lnEdit->text().toStdString();
}

void MainWindow::clean()
{
  std::cout <<"Make clean\n" <<std::flush;
  progHandler->cleanMakefile();
}

void MainWindow::compile()
{
  std::cout <<"Compilation started\n" <<std::flush;
  progHandler->runMakefile();
  std::cout <<"Compilation completed\n" <<std::flush;
}

void MainWindow::runApp()
{
  std::cout <<"RunApp\n" << std::flush;
  if(!FileHandler::doesFileExist("../prog", 0))
  {
    compile();
  }
  if(progHandler->isProgramRunning())
  {
    std::cout <<"Program: " << "../prog"  << " is already running" <<std::flush;
  }
  else
  {
    progHandler->startApp();
  }
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
