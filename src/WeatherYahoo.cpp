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

std::string WeatherYahoo::getTemperature(std::string cityID)
{
	std::string data ;
	std::transform(cityID.begin(), cityID.end(), cityID.begin(), ::tolower);	
	CURL * crl = curl_easy_init();
//item.forecast to get 3-5 days forecast/ item.condition for one day condition
	std::string yahooQuery = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22";
	yahooQuery += cityID.c_str();
	yahooQuery += "%2C%20pl%22)%20and%20u%3D%27c%27%20limit%203&format=json";
	if(crl)
	{
		curl_easy_setopt(crl, CURLOPT_URL,yahooQuery.c_str() );
		curl_easy_setopt(crl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(crl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(crl, CURLOPT_WRITEDATA, &data);

		curl_easy_perform(crl);
		curl_easy_cleanup(crl);

		return data;
	}
	return "";
}

//To be removed
std::string WeatherYahoo::getCityID(std::string cityName)
{	
	if(cityName == "")
	{
		std::cout << "Give city name and countr (exceptional)\n";
		std::cin >> cityName;
	}
	char buff[512];
	std::string cwd = getcwd(NULL, 0); //memory leaks?
	std::string filename = "python " + cwd + "/pythonGetCityWoeid.py " + cityName;
	FILE * output;

  if(!(output =  popen(filename.c_str(), "r")))
	{
		std::cout <<"Can't open file\n";
    return "";
	}
   while(fgets(buff, sizeof(buff), output)!=NULL)
	{}

	std::string woeid (buff);
	std::cout << "City woeid: " << woeid << "\n";
	if(strcmp(woeid.c_str(), "None\n")==0) std::cout <<"City not found\n";
  putCityIntoMap(cityName, woeid);
	pclose(output);
	return woeid;
}
