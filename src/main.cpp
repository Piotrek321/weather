
#include "../inc/Plotter.h"
#include "../inc/WeatherOWM.h"
#include "../inc/WeatherYahoo.h"
#include <stdio.h>


int main(){

std::cout <<"AAAA";
Plotter y;
y.init();
WeatherAPI * b = new WeatherOWM;
 
char buff[512];
std::string x = "Lodz";
//std::cout << 
//std::cout <<a.getCityID("Lodz");

std::cout << b->getCityID("Lodz");
std::cout << b->getCityID("London");
b->printMap();

std::cout << "Give city name and countr (exceptional)\n";
std::string city;
std::cin >> city;


std::string filename = "python /home/ppp/Desktop/weather/pythonGetCityWoeid.py " + city;
FILE * in;

  if(!(in =  popen(filename.c_str(), "r"))){
					std::cout <<"XXX";
	        return 1;

	    }
   while(fgets(buff, sizeof(buff), in)!=NULL)
	{
	   //std::cout << "\nO : " << in.str();
  }
//(*in).open();

//
std::string ne (buff);
std::string aaa2 = "None\n";
if(strcmp(ne.c_str(), "None\n")==0) std::cout <<"HIHIIHHI2222\n";
if(strcmp(ne.c_str(), aaa2.c_str())==0) std::cout <<"HIHIIHHI2\n";
std::cout <<"X: " << ne <<"\n";
char d[6] = "None\n";
std::cout <<"ZZZZZZZZZZ\n";

if(strcmp(buff, d) == 0 ) std::cout <<" XXXXXXXXXXXX\n";

for(int i =0;i<5;i++)
{
	if(d[i] == buff[i]) std::cout << "OK\n";
	else std::cout <<"NOTOK\n";
}
//std::cout << strcmp(d,buff);

pclose(in);
//pclose(str);
	return 1;
}
