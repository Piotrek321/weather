
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include "../inc/Messaginghandler.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <mqueue.h>
bool IS = false;
#define MSGSZ     128

bool isResetCalled = false;
void  SIGTERM_handler(int sig);
static void
handler(int sig, siginfo_t *si, void *ucontext)
{
IS = true;
 //MessagingHandler client("client");
//std::cout << client.receiveMessage() <<std::endl;
}

int main()
{
    mqd_t messageQueueHandler;

 struct mq_attr attr;
       attr.mq_maxmsg = 10;
       attr.mq_msgsize = 20;

    messageQueueHandler= mq_open("/myqueue", O_RDWR|O_CREAT, 0655, &attr);
 if(messageQueueHandler == -1)
    {
        std::cout <<"Mq_open went wrong" <<std::endl;
    }
	Plotter y;
	y.init();
	WeatherAPI * b = new WeatherOWM;
	WeatherAPI * c= new WeatherYahoo;
  struct sigaction sigac;
  sigemptyset(&sigac.sa_mask);
  sigac.sa_sigaction = handler;
  sigac.sa_flags = SA_SIGINFO;


  sigaction(SIGINT, &sigac, NULL);


  if(signal(SIGTERM, SIGTERM_handler) == SIG_ERR) 
  {
     printf("SIGTERM install error\n");
     exit(1);
  }
	std::string x = "Lodz";
		std::cout <<"START\n" <<std::flush;
	//TODO: handle wrong city name ??
	//b->printTemperature("zxczxcsdvasdgsdfbdsfvds");

	b->printTemperature("London");

	c->printTemperature("lodz");

while(isResetCalled != true)
{
	if(IS)
	{
		char * message = new char [100];
		 if( mq_receive(messageQueueHandler, message, 100, 0) == -1)
			{
		 std::cout <<"Oh dear, something went wrong with read()!"  << strerror(errno)<< std::endl;
		}else
		{std::cout <<"\nAL: " << message <<std::endl;}
	delete [] message;
	}
sleep(1);



}
delete b;
delete c;
 std::cout <<"main close: " <<  mq_close(messageQueueHandler)<<std::flush;
 std::cout <<"main close: " << mq_unlink("/myqueue")<<std::flush;
exit(3);
	return 1;
}



void  SIGTERM_handler(int sig)
{
  printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal and is about to quit\n", sig);
	isResetCalled =true;
  //exit(3);
}



