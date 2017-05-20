
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include <stdio.h>


int main(){

Plotter y;
y.init();
WeatherAPI * b = new WeatherOWM;
WeatherAPI * c= new WeatherYahoo;

std::string x = "Lodz";
 	
std::cout <<"Weather Lodz OWM: " ;
std::cout << b->getTemperature("Lodz") << "\n";

std::cout <<"Weather Lodz Yahoo: " ;
std::cout << c->getTemperature("lodz") << "\n";


	return 1;
}


