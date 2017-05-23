#include "../inc/ProgramHandler.h"

int ProgramHandler::startApp(std::string pathToProgram, bool doYouWantToWaitForChild)
{
    pid_t pid = fork();
    int statval;

    if(pid == 0) //child
    {
        execl(pathToProgram.c_str(), pathToProgram.c_str(), (char*) NULL);
    }
    else if(pid <0)
    {
        std::cerr <<"Failed to fork\n";
        exit(1);
    }
    else //Parent
    {
      std::cout <<"Parent\n";
      if(doYouWantToWaitForChild)
      {
        waitpid( (pid <0), &statval, WCONTINUED);
        if(WIFEXITED(statval))
          printf("Child's exit code %d\n", WEXITSTATUS(statval));
        else
          printf("Child did not terminate with exit\n");
      }

    }
    return 1;
}
int ProgramHandler::performRestart()
{

 return 1;
}

void ProgramHandler::stop()
{

 return;
}


std::string ProgramHandler::exec(const char* cmd)
{
	char buffer[128];
	std::string result = "";
  FILE* pipe = popen(cmd, "r");
  if (!pipe) throw std::runtime_error("popen() failed!");
  try 
	{
  	while (!feof(pipe)) 
		{
    	if (fgets(buffer, 128, pipe) != NULL)
      {
				result += buffer;
      }
		}
  } catch (...) {
      pclose(pipe);
      throw;
  }
  pclose(pipe);
  return result;
	
}

void ProgramHandler::runMakefile()
{
	exec("make -C ../");
}

