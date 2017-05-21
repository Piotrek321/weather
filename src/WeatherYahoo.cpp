#include "../inc/WeatherYahoo.h"

std::string WeatherYahoo::getTemperature(std::string cityID)
{
	std::transform(cityID.begin(), cityID.end(), cityID.begin(), ::tolower);	
	std::stringstream ss;
//item.forecast to get 3-5 days forecast/ item.condition for one day condition
	std::string yahooQuery = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22";
	yahooQuery += cityID.c_str();
	yahooQuery += "%2C%20pl%22)%20and%20u%3D%27c%27%20limit%203&format=json";
  return sendHttpRequest(yahooQuery , "query.results.channel.item.condition.temp", ss);
		//std::cout << getTemperatureFromJSON(ss, "query.created");
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
