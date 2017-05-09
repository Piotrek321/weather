#ifndef WeatherOWM_H_
#define WeatherOWM_H_

#include "WeatherAPI.h"
#include "FileHandler.h"
#include <vector>
#include <curl/curl.h>
#include <boost/property_tree/json_parser.hpp>

//////////
#include <iostream>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sstream> 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h> 
#include <map>
///////////

class WeatherOWM :public WeatherAPI
{
	public:

		std::string getTemperatureFromJSON(std::stringstream &jsonData);
		std::string getTemperature();
		static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		std::string getCityInfo(std::string cityName);
		WeatherOWM(){};
	  virtual ~WeatherOWM(){};
		std::string getIDFromJSON(std::stringstream &cityInfo);
		//std::stringstream getCurrentDate(){};
		virtual void init(){};

	protected:
		std::string fileWithCitiesID;//needed??
		std::map<std::string, int> cityNameID;
};



#endif
/*
		static void signal_received(int sig, siginfo_t *info, void *context) 
		{
			std::cout <<"Paring completed\n";
		 // anotherProcessPid = info->si_pid;
		}*/
/*
			//Prepare response for signals
			struct sigaction act;
			act.sa_sigaction = &WeatherAPI::signal_received;
			act.sa_flags = SA_SIGINFO;

			sigaction(SIGINT, &act, NULL);
			if (signal(SIGQUIT, SIGQUIT_handler) == SIG_ERR) 
			{
				printf("SIGQUIT install error\n");
				exit(2);
			}*/
