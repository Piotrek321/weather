#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include "../inc/Messaginghandler.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <mqueue.h>

#define MSGSIZE 300

bool isResetCalled = false;
void  SIGTERM_handler(int sig);

int main()
{
  mqd_t messageQueueHandler;

  struct mq_attr attr;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MSGSIZE;

  messageQueueHandler= mq_open("/myqueue", O_RDWR | O_NONBLOCK, 0655, &attr);
  if(messageQueueHandler == -1)
  {
    std::cout <<"Mq_open went wrong\n" << strerror(errno) <<std::endl;
  }
  Plotter y;
  y.init();
  WeatherAPI * b = new WeatherOWM;
  WeatherAPI * c= new WeatherYahoo;

  if(signal(SIGTERM, SIGTERM_handler) == SIG_ERR) 
  {
     printf("SIGTERM install error\n");
     exit(1);
  }

  while(isResetCalled != true)
  {
    char * message = new char [MSGSIZE];
		if( mq_receive(messageQueueHandler, message, MSGSIZE, NULL) != -1)
		{
			c->printTemperature(message);
			b->printTemperature(message);
		}
		delete [] message;
		sleep(1);
	}
	delete b;
	delete c;

	return 1;
}

void SIGTERM_handler(int sig)
{
  printf("SIGTERM signal number: %d \n", sig);
	isResetCalled =true;
  exit(3);
}
