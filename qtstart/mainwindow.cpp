#include "mainwindow.h"

#include <QApplication>

#define ButtonWitdth 30

#define ButtonLength 100

bool compilationFinished = false;
bool compilationStarted = false;

class myThread: public QThread
{
public:
    void run()
    {  compilationStarted = true;
        ProgramHandler::runMakefile();
        std::cout <<"Compilation completed\n" <<std::flush;
        compilationFinished = true;
        compilationStarted = false;
    }
};

MainWindow::MainWindow()
{
    struct mq_attr attr;
       attr.mq_maxmsg = 10;
     attr.mq_msgsize = 20;

   messageQueueHandler= mq_open("/myqueue", O_WRONLY|O_CREAT, 0655, &attr);
    if(messageQueueHandler == -1)
    {
     std::cout <<"Mq_open went wrong22" <<std::endl;
    }
    messagingHandlerServer = new MessagingHandler("server");
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

    t = new myThread;
    lnEdit = new QLineEdit(this);
    lnEdit->setGeometry(200,200,100,50);
    lnEdit->setText("Hello my id");
    connect(restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(getData()));
    connect(exitButton, SIGNAL(clicked()), this, SLOT(exit()));
    connect(startButton, SIGNAL(clicked()), this, SLOT(runApp()));
    connect(compileButton, SIGNAL(clicked()), this, SLOT(compile()));
    connect(shortcut, SIGNAL(activated()), this, SLOT(getData()));
    connect(cleanButton, SIGNAL(clicked()), this, SLOT(clean()));

    //connect(lnEdit, SIGNAL(textChanged( const QString &)), this, SLOT(lineChanged(const QString &)));


    setMinimumSize(200, 200);
    resize(480, 320);
}
void MainWindow::exit()
{
  mq_close(messageQueueHandler);
  mq_unlink("/myqueue");
  this->restart();
  qApp->quit();

}

void MainWindow::restart()
{
  pid_t pid =  Helper::getPID("prog");
  if(pid != 0)
  {
    std::cout <<"Restart of process with PID: " << pid <<"\n"<<std::flush;
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
  cityName = lnEdit->text().toStdString();

  mq_send(messageQueueHandler,cityName.c_str(), cityName.length(), 0);
}

void MainWindow::clean()
{
  std::cout <<"Make clean\n" <<std::flush;
  compilationFinished = false;
  ProgramHandler::cleanMakefile();
}

void MainWindow::compile()
{
  std::cout <<"Compilation started\n" <<std::flush;

  t->start();
}

void MainWindow::runApp()
{
  if(compilationFinished || FileHandler::doesFileExist("../prog", 0))
  {
    if(progHandler->isProgramRunning())
    {
       std::cout <<"Program: " << "../prog"  << " is already running\n" <<std::flush;
    }
    else
    {
      std::cout <<"RunApp\n" <<std::flush;
      progHandler->startApp();
    }
  }else
  {
    if(compilationStarted) std::cout <<"Compilation started but not finished.\n" <<std::flush;
    else std::cout <<"Press compile button.\n" <<std::flush;
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
