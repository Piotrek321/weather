#include <iostream>
#include <stdio.h>

class Helper
{
	public:
		pid_t getPID(std::string processName)	
		{
			char buf[512];
			FILE *cmd_pipe = popen("pidof -s process_name", "r");

			fgets(buf, 512, cmd_pipe);
			pid_t pid = strtoul(buf, NULL, 10);

			pclose( cmd_pipe );  
			return pid;
		}

};

