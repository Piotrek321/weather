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
	protected:
		std::string fileWithCitiesID;//needed??
};
