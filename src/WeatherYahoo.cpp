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
std::cout << "CITYID:" << cityID.c_str();
	CURL * crl = curl_easy_init();


/////////////////////////////////////////////////DZIALA ALE CITY MA BYC Z MALEJ LITERY item.forecast kilkudniowa chyba 5
std::string cc = "https://query.yahooapis.com/v1/public/yql?q=select%20item.forecast%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22";
cc += cityID.c_str();
cc += "%2C%20pl%22)%20and%20u%3D%27c%27%20limit%203&format=json";
std::string pp = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20";
std::string lk = "12577937";
pp += lk.c_str(); //"12577937";
pp += "%20and%20u='c'&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";

	if(crl)
	{
//ZAMIENIC NA CC!!!
std::cout <<"x: " << cc.c_str()  << "\n";
		curl_easy_setopt(crl, CURLOPT_URL,pp.c_str() );
/*
https://query.yahooapis.com/v1/public/yql?q=select%20item.forecast%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22munic%2C%20de%22)%20and%20u%3D%27c%27%20limit%203&format=json
*/
		//curl_easy_setopt(crl, CURLOPT_URL, );
		curl_easy_setopt(crl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(crl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(crl, CURLOPT_WRITEDATA, &data);

		curl_easy_perform(crl);
		curl_easy_cleanup(crl);

		return data;
	}
std::cout <<"PPP\n";
	return "";
}


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


/*
///////////////////TEZ DZIALA ALE CITY MA BYC Z MALEJ LITERY
std::string xx = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20";
xx += cityID.substr(0,cityID.length()-1).c_str();
xx += "%20and%20u='c'&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";
///////////////////////////////////////////////

std::string pp = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20";
std::string lk = "12577937";
pp += lk.c_str(); //"12577937";
pp += "%20and%20u='c'&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";
///////////////////////////////////////////////

std::string WeatherYahoo::getTemperature22(std::string cityID)
{
	std::string data ;
std::cout << "CITYID:" << cityID.c_str();
	CURL * crl = curl_easy_init();
std::string xx = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20";
xx += cityID.substr(0,cityID.length()-1).c_str();
xx += "%20and%20u='c'&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";

std::string cc = "https://query.yahooapis.com/v1/public/yql?q=select%20item.forecast%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22";
cc += "lodz%2C%20";
cc += "pl%22)%20and%20u%3D%27c%27%20limit%203&format=json";
std::string pp = "https://query.yahooapis.com/v1/public/yql?q=select%20item.condition%20from%20weather.forecast%20where%20woeid%20%3D%20";
std::string lk = "12577937";
pp += lk.c_str(); //"12577937";
pp += "%20and%20u='c'&format=json&env=store%3A%2F%2Fdatatables.org%2Falltableswithkeys";

	if(crl)
	{
std::cout <<"x: " << pp.c_str()  << "\n";
		curl_easy_setopt(crl, CURLOPT_URL,cc.c_str() );

https://query.yahooapis.com/v1/public/yql?q=select%20item.forecast%20from%20weather.forecast%20where%20woeid%20in%20(select%20woeid%20from%20geo.places(1)%20where%20text%3D%22munic%2C%20de%22)%20and%20u%3D%27c%27%20limit%203&format=json

		//curl_easy_setopt(crl, CURLOPT_URL, );
		curl_easy_setopt(crl, CURLOPT_HTTPGET, 1L);
		curl_easy_setopt(crl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(crl, CURLOPT_WRITEDATA, &data);

		curl_easy_perform(crl);
		curl_easy_cleanup(crl);

		return data;
	}
std::cout <<"PPP\n";
	return "";
}

*/
