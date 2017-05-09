#include "../inc/WeatherYahoo.h"

size_t WeatherYahoo::write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    ((std::string*)userdata)->append((char*)ptr, size * nmemb);
    return size * nmemb;
}

std::string WeatherYahoo::getTemperatureFromJSON(std::stringstream &jsonData)
{
  boost::property_tree::ptree pt;
  boost::property_tree::read_json(jsonData, pt);
  return pt.get<std::string>("query.results.channel.item.condition.temp");
}

std::string WeatherYahoo::getTemperature()
{
	std::string data ;
	CURL * crl = curl_easy_init();
	if(crl)
	{
		curl_easy_setopt(crl, CURLOPT_URL, "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%2012577937%20and%20u='c'&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys");
		curl_easy_setopt(crl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(crl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(crl, CURLOPT_WRITEDATA, &data);

		curl_easy_perform(crl);
		curl_easy_cleanup(crl);

		return data;
	}
	return "";
}

std::string WeatherYahoo::getCityID(std::string cityName)
{
//	FileHandler fh("data/owm.city.list.json");
	//fh.openFile();
//std::string fh.readFileToString();
	return "";
}



/*
int main()
{

return 1;
}*/
