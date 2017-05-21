#include "../inc/WeatherOWM.h"

std::string WeatherOWM::getTemperature(std::string cityID)
{
	std::stringstream ss;
  return sendHttpRequest("api.openweathermap.org/data/2.5/weather?id=3093133&appid=b5df5912a869b5cf1cfa4899b10da754&units=metric" , "main.temp", ss); //&mode=xml
}

std::string WeatherOWM::getInfoAboutCity(std::stringstream &cityInfo)
{
  boost::property_tree::ptree pt;
  boost::property_tree::read_json(cityInfo, pt);
  //std::cout << pt.get() ;
  return pt.get<std::string>("_id");
}

std::string WeatherOWM::getCityID(std::string cityName)
{
	FileHandler fh("../data/owm.city.list.json");
	fh.openFile();
	std::stringstream info (fh.findLineWithData(cityName));
  std::string id = getInfoAboutCity(info);
  putCityIntoMap(cityName, id);
	return id;
}



