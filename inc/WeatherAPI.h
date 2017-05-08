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
		virtual std::string getTemperature() =0;
		virtual std::string getTemperatureFromJSON(std::stringstream &jsonData) =0;

		virtual std::stringstream getCurrentDate()
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

		virtual void init()
		{
			pid_t pid = getpid();

			//Key should be either generated or hard coded (it must have the same value in every application that uses particular part of shared memory)
			key_t MyKey = KEY_VALUE; 

			//Prepare memory and write pid into it
			SharedMemoryID   = shmget(MyKey, SHMSZ, IPC_CREAT | 0666);
			SharedMemoryPtr  = (int *) shmat(SharedMemoryID, NULL, 0);
			*SharedMemoryPtr = pid; 

		}

		virtual std::string getCityID(std::string cityName) =0;
		virtual ~WeatherAPI(){};

		int   SharedMemoryID;      
		pid_t *SharedMemoryPtr, anotherProcessPid;    

	protected:
		std::string fileWithCitiesID;//needed??
};




#endif

