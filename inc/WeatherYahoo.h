#ifndef WeatherYahoo_H_
#define WeatherYahoo_H_

#include "WeatherAPI.h"
#include <vector>
#include <curl/curl.h>
#include <boost/property_tree/json_parser.hpp>


class WeatherYahoo :public WeatherAPI
{

	public:
		std::string getTemperature();
		std::string getTemperatureFromJSON(std::stringstream &jsonData);
		static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		std::string getCityID(std::string cityName);
		WeatherYahoo(){};
	  virtual ~WeatherYahoo(){};

		//std::stringstream getCurrentDate(){};
		virtual void init(){};
	protected:
		std::string fileWithCitiesID;//needed??
};

#endif
