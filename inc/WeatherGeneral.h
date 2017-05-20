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
		virtual std::string getTemperature(std::string cityID) =0;
		virtual std::string getTemperatureFromJSON(std::stringstream &jsonData, const char * getElement);
		virtual std::string getCityID(std::string cityName) =0;
		virtual ~WeatherGeneral(){};

		virtual std::stringstream getCurrentDate();

		virtual void init();

		void putCityIntoMap(std::string cityName , std::string id);

		void printMap();

		int   SharedMemoryID;      
		pid_t *SharedMemoryPtr, anotherProcessPid;    

	protected:
		std::string fileWithCitiesID;//needed??
		std::map<std::string, std::string> cityNameID_m;
};




#endif

