#include "../inc/Helper.h"

pid_t Helper::getPID(std::string processName)	
{
	char buf[512];
	std::string prName("pidof -s ");
	prName += processName;
	FILE *cmd_pipe = popen(prName.c_str(), "r");

	fgets(buf, 512, cmd_pipe);
	pid_t pid = strtoul(buf, NULL, 10);

	pclose( cmd_pipe );  
	return pid;
}
