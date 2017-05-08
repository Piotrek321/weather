#ifndef WeatherAPI_H_
#define WeatherAPI_H_

#include <iostream>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sstream> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>  

#define SHMSZ  100
#define KEY_VALUE 5678

class WeatherAPI
{

	public:
		virtual std::string getTemperature(){};
		virtual std::string getTemperatureFromJSON(std::stringstream &jsonData) {};
		//virtual std::stringstream getCurrentDate();
		virtual void init();
		virtual std::string getCityID(std::string cityName){};
		virtual ~WeatherAPI(){};

		int   SharedMemoryID;      
		pid_t *SharedMemoryPtr, anotherProcessPid;    
		static void signal_received(int sig, siginfo_t *info, void *context);
	protected:
		std::string fileWithCitiesID;//needed??
};

/*
std::stringstream WeatherAPI::getCurrentDate()
{
	std::stringstream currentDate;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

  currentDate << (tm.tm_year + 1900) ;
  if( (tm.tm_mon + 1 ) <10)
  {
		currentDate << "0";
  }
	currentDate << tm.tm_mon + 1;
		 
	currentDate << tm.tm_mday << " " << tm.tm_hour <<":";
	if(tm.tm_min <10)
	{
		currentDate << "0";
	}
	currentDate << tm.tm_min;
	
	return currentDate;
}
*/

void WeatherAPI::signal_received(int sig, siginfo_t *info, void *context) 
{
  std::cout <<"Paring completed\n";
 // anotherProcessPid = info->si_pid;
}

void WeatherAPI::init()
{
  pid_t pid = getpid();

  //Key should be either generated or hard coded (it must have the same value in every application that uses particular part of shared memory)
  key_t MyKey = KEY_VALUE; 

  //Prepare response for signals
  struct sigaction act;
  act.sa_sigaction = &WeatherAPI::signal_received;
  /*act.sa_flags = SA_SIGINFO;

  sigaction(SIGINT, &act, NULL);
  if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) 
  {
    printf("SIGQUIT install error\n");
    exit(2);
  }*/
  //Prepare memory and write pid into it
  SharedMemoryID   = shmget(MyKey, SHMSZ, IPC_CREAT | 0666);
  SharedMemoryPtr  = (int *) shmat(SharedMemoryID, NULL, 0);
  *SharedMemoryPtr = pid; 

}

#endif

