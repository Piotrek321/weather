
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

//TODO: handle wrong city name ??
b->printTemperature("zxczxcsdvasdgsdfbdsfvds");

b->printTemperature("London");

c->printTemperature("lodz");


	return 1;
}


