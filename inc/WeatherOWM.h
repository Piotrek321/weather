#ifndef WeatherOWM_H_
#define WeatherOWM_H_

#include "WeatherGeneral.h"

class WeatherOWM :public WeatherGeneral
{
	public:

		std::string getTemperature(std::string cityName);
		//static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		std::string getCityID(std::string cityName);
    WeatherOWM() : WeatherGeneral("OWM"){};
	  virtual ~WeatherOWM(){};
		std::string getInfoAboutCity(std::stringstream &cityInfo);
		virtual void init(){};

	protected:
		std::string fileWithCitiesID;//needed??

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
