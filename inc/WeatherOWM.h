#include "WeatherAPI.h"
#include <stdio.h>
#include <signal.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>  
#include <iostream>
#include <vector>
#include <curl/curl.h>
#include <sstream> 
#include <boost/property_tree/json_parser.hpp>


class WeatherOWM :public WeatherAPI
{

	public:
		std::string getTemperature();
		std::string getTemperatureFromJSON(std::stringstream &jsonData);
		static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
	protected:
		std::string fileWithCitiesID;//needed??
};
