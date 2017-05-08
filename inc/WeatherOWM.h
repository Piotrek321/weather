#ifndef WeatherOWM_H_
#define WeatherOWM_H_

#include "WeatherAPI.h"
//#include "FileHandler.h"
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
///////////

class WeatherOWM :public WeatherAPI
{
	public:


		std::string getTemperatureFromJSON(std::stringstream &jsonData);
		std::string getTemperature();
		static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		std::string getCityID(std::string cityName);
		WeatherOWM(){};
	  virtual ~WeatherOWM(){};

		std::stringstream getCurrentDate(){};
		virtual void init(){};

	protected:
		std::string fileWithCitiesID;//needed??
};



#endif
