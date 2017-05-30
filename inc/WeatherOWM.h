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
