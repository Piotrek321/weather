
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include <stdio.h>


int main(){

Plotter y;
y.init();
WeatherAPI * b = new WeatherOWM;
WeatherAPI * c= new WeatherYahoo;

std::string x = "Lodz";
  
//TODO: handle wrong city name ??
b->printTemperature("zxczxcsdvasdgsdfbdsfvds");

b->printTemperature("London");

c->printTemperature("lodz");


	return 1;
}

//if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) 
/*
void  SIGQUIT_handler(int sig)
{
  signal(sig, SIG_IGN);
  printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal and is about to quit\n", sig);
  shmdt(SharedMemoryPtr);
  shmctl(SharedMemoryID, IPC_RMID, NULL);
  exit(3);
}*/
