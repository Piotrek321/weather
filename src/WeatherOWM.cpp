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

std::string WeatherOWM::getInfoAboutCity(std::stringstream &cityInfo)
{
  boost::property_tree::ptree pt;
  boost::property_tree::read_json(cityInfo, pt);
  //std::cout << pt.get() ;
  return pt.get<std::string>("_id");
}

size_t WeatherOWM::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}


std::string WeatherOWM::getCityID(std::string cityName)
{
	FileHandler fh("data/owm.city.list.json");
	fh.openFile();
	std::stringstream info (fh.findLineWithData(cityName));
  std::string id = getInfoAboutCity(info);
  putCityIntoMap(cityName, id);
	return id;
}



