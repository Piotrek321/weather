
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
int main(){

std::cout <<"AAAA";
Plotter y;
y.init();
WeatherOWM b; 

std::string x = "Lodz";
//std::cout << 
//std::cout <<a.getCityID("Lodz");

std::cout << b.getCityInfo("Lodz");
	return 1;
}
