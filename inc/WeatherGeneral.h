#ifndef WeatherGeneral_H_
#define WeatherGeneral_H_

#include "WeatherAPI.h"
#include <boost/property_tree/json_parser.hpp>
#include "FileHandler.h"
#include <vector>
#include <curl/curl.h>

class WeatherGeneral : public WeatherAPI
{

	public:
		virtual std::string getTemperature(std::string cityName) =0;
		virtual std::string getTemperatureFromJSON(std::stringstream &jsonData, const char * getElement);
		virtual std::string getCityID(std::string cityName) =0;
		virtual ~WeatherGeneral(){};
		virtual std::string sendHttpRequest(std::string httpQuery , const char * getElement, std::stringstream &ss);
		virtual std::stringstream getCurrentDate();
		virtual void printTemperature(std::string cityName);
		virtual void init();
		WeatherGeneral(std::string appName) :m_appName(appName) {};
		void putCityIntoMap(std::string cityName , std::string id);
		static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		void printMap();

		int   SharedMemoryID;      
		pid_t *SharedMemoryPtr, anotherProcessPid;    

	protected:
		std::string m_appName;
		std::string fileWithCitiesID;//needed??
		std::map<std::string, std::string> cityNameID_m;
};




#endif

