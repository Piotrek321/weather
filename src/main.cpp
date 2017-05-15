
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include <stdio.h>


int main(){

std::cout <<"AAAA";
Plotter y;
y.init();
WeatherAPI * b = new WeatherOWM;
 WeatherYahoo * c= new WeatherYahoo;

std::string x = "Lodz";
//std::cout << 
//std::cout <<a.getCityID("Lodz"); 	

std::cout << b->getCityID("Lodz");
std::cout << b->getCityID("London");
b->printMap();


//std::cout << ;

std::cout << c->getTemperature("lodz");
std::cout <<"XXXX\n\n\n" ;

	return 1;
}


