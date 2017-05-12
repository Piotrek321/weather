#include "../inc/WeatherGeneral.h"	

	std::stringstream WeatherGeneral::getCurrentDate()
	{
		std::stringstream currentDate;
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);

		currentDate << (tm.tm_year + 1900) ;
		if( (tm.tm_mon + 1 ) <10)
		{
			currentDate << "0";
		}
		currentDate << tm.tm_mon + 1;
			 
		currentDate << tm.tm_mday << " " << tm.tm_hour <<":";
		if(tm.tm_min <10)
		{
			currentDate << "0";
		}
		currentDate << tm.tm_min;

		return currentDate;
	}

	void WeatherGeneral::init()
	{
		pid_t pid = getpid();

		//Key should be either generated or hard coded (it must have the same value in every application that uses particular part of shared memory)
		key_t MyKey = KEY_VALUE; 

		//Prepare memory and write pid into it
		SharedMemoryID   = shmget(MyKey, SHMSZ, IPC_CREAT | 0666);
		SharedMemoryPtr  = (int *) shmat(SharedMemoryID, NULL, 0);
		*SharedMemoryPtr = pid; 
	}

	void WeatherGeneral::putCityIntoMap(std::string cityName , std::string id)
	{
		if(cityNameID_m.count(cityName) == 0)
		{
			cityNameID_m.insert(std::pair<std::string, std::string>(cityName, id));
		}
	}

	void WeatherGeneral::printMap()
	{
		auto iter = cityNameID_m.begin();
		std::cout <<"PrintMap \n";
		while(iter != cityNameID_m.end())
		{
			std::cout << "City: " << iter->first << " id: " << iter->second << "\n";
			++iter;
		}
	}
