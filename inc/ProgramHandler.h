#ifndef ProgramHandler_H_
#define ProgramHandler_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

class ProgramHandler
{

	public:
        virtual int startApp(std::string pathToProgram, bool doYouWantToWaitForChild =0);
		virtual int performRestart();
		virtual void stop(); 

		virtual ~ProgramHandler(){};

};




#endif

