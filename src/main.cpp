
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
int main(){

std::cout <<"AAAA";
Plotter y;
y.init();
WeatherAPI * b = new WeatherOWM;
 

std::string x = "Lodz";
//std::cout << 
//std::cout <<a.getCityID("Lodz");

std::cout << b->getCityID("Lodz");
std::cout << b->getCityID("London");
b->printMap();

	return 1;
}
