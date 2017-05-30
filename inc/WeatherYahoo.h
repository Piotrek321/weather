#ifndef WeatherYahoo_H_
#define WeatherYahoo_H_

#include "WeatherGeneral.h"
#include <algorithm>

class WeatherYahoo :public WeatherGeneral
{

	public:
		std::string getTemperature(std::string cityName);
		//static size_t write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);
		std::string getCityID(std::string cityName);
    WeatherYahoo() : WeatherGeneral("Yahoo"){};

	  virtual ~WeatherYahoo(){std::cout <<"~WeatherYahoo\n" <<std::flush;};

		virtual void init(){};
	protected:
		std::string fileWithCitiesID;//needed??
};

#endif
