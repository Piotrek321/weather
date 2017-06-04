
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
bool isResetCalled = false;
void  SIGTERM_handler(int sig);
static void
handler(int sig, siginfo_t *si, void *ucontext)
{
std::string zz;

  std::cout <<  std::to_string(si->si_value.sival_int) << " \n" << std::flush;

}
int main()
{
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
	b->printTemperature("zxczxcsdvasdgsdfbdsfvds");

	b->printTemperature("London");

	c->printTemperature("lodz");
	while(isResetCalled != true)
	{}
delete b;
delete c;
exit(3);
	return 1;
}



void  SIGTERM_handler(int sig)
{
  printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal and is about to quit\n", sig);
	isResetCalled =true;
  //exit(3);
}


