#ifndef ProgramHandler_H_
#define ProgramHandler_H_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include "../inc/Helper.h"

class ProgramHandler
{

	public:
        std::string m_programName;
        virtual int startApp(bool doYouWantToWaitForChild =0);
		virtual int performRestart();
		virtual void stop(); 
		virtual std::string exec(const char* cmd);
		virtual void runMakefile();
        virtual bool isProgramRunning();
        virtual ~ProgramHandler(){std::cout <<"~ProgramHandler" << std::flush;};
        ProgramHandler(std::string programName) : m_programName(programName){};
        pid_t child_pid;
       // ProgramHandler(std::string programName) : m_programName(programName) {};

};

#endif

