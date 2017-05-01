#include <iostream>

class WeatherAPI
{

	public:
		std::string getTemperature();
		std::string getTemperatureFromJSON(std::stringstream &jsonData);
	protected:
		std::string fileWithCitiesID;//needed??
};
