#include "../inc/WeatherOWM.h"


		// WeatherOWM::WeatherOWM(){std::cout<<"ZZZZ";}

std::string WeatherOWM::getTemperature()
{
std::string data ;
	CURL * crl = curl_easy_init();
	if(crl)
	{
		curl_easy_setopt(crl, CURLOPT_URL, "api.openweathermap.org/data/2.5/weather?id=3093133&appid=b5df5912a869b5cf1cfa4899b10da754&units=metric"); //&mode=xml
		curl_easy_setopt(crl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(crl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(crl, CURLOPT_WRITEDATA, &data);
		curl_easy_perform(crl);
		curl_easy_cleanup(crl);
		std::stringstream ss;
		ss <<data;
		return getTemperatureFromJSON(ss);
		//return data;
	}
return "";
}

std::string WeatherOWM::getTemperatureFromJSON(std::stringstream &jsonData)
{
  boost::property_tree::ptree pt;
  boost::property_tree::read_json(jsonData, pt);
  //std::cout << pt.get() ;
  return pt.get<std::string>("main.temp");
}

size_t WeatherOWM::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

std::string WeatherOWM::getCityID(std::string cityName)
{
	//FileHandler fh("../data/owm.city.list.json");
	//fh.openFile();
	//std::cout << fh;
	return "";
}

std::stringstream WeatherOWM::getCurrentDate()
{
	std::stringstream currentDate;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

  currentDate << (tm.tm_year + 1900) ;
  if( (tm.tm_mon + 1 ) <10)
  {
		currentDate << "0";
  }
	currentDate << tm.tm_mon + 1;
		 
	currentDate << tm.tm_mday << " " << tm.tm_hour <<":";
	if(tm.tm_min <10)
	{
		currentDate << "0";
	}
	currentDate << tm.tm_min;
	
	return currentDate;
}


