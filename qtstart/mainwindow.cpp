#include "mainwindow.h"

#include <QApplication>

MainWindow::MainWindow()
{
    QTextCodec::codecForName ("UTF-8");

   //createMenus();
   // createStatusBar();
    label = new QLabel(tr("Weather forecast"), this);
    label->setGeometry(5, 15, 150, 30);

    compileButton = new QPushButton(tr("&Compile"), this);
    compileButton->setGeometry(150, 75, 100, 30);

    okButton = new QPushButton(tr("&Ok"), this);
    okButton->setGeometry(200, 100, 100, 30);
    okButton->setDefault(true);
    okButton->setAutoDefault(false);

    shortcut = new QShortcut(QKeySequence(Qt::Key_Return), this);

    restartButton = new QPushButton(tr("&Restart"), this);
    restartButton->setGeometry(5, 105, 100, 30);

    exitButton = new QPushButton(tr("&Exit"), this);
    exitButton->setGeometry(5, 75, 100, 30);

    startButton = new QPushButton(tr("&Start"), this);
    startButton->setGeometry(5, 45, 100, 30);

    connect(restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(getData()));
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(runApp()));
    connect(compileButton, SIGNAL(clicked()), this, SLOT(compile()));
    connect(shortcut, SIGNAL(activated()), this, SLOT(getData()));

    lnEdit = new QLineEdit(this);
    lnEdit->setGeometry(200,200,100,50);
    lnEdit->setText("Hello my id");

    setMinimumSize(200, 200);
    resize(480, 320);
}

void MainWindow::restart()
{

}

void MainWindow::getData()
{
  QString str;
  str = lnEdit->text();
  std::cout <<str.toStdString() <<std::flush;
  cityName = lnEdit->text().toStdString();
}

void MainWindow::compile()
{
  std::cout <<"Compilation started\n" <<std::flush;
  progHandler.runMakefile();
  std::cout <<"Compilation completed\n" <<std::flush;
}

void MainWindow::runApp()
{    
  if(!FileHandler::doesFileExist("../prog", 0))
  {
    compile();
  }
  progHandler.startApp("../prog");
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
