#include "../inc/ProgramHandler.h"
#include <signal.h>

int ProgramHandler::startApp(bool doYouWantToWaitForChild)
{
    pid_t pid = fork();
    int statval;

    if(pid == 0) //child
    {
        execl(m_programName.c_str(), m_programName.c_str(), (char*) NULL);
        exit(3);
    }
    else if(pid <0)
    {
        std::cerr <<"Failed to fork\n";
        exit(1);
    }
    else //Parent
    {
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

bool ProgramHandler::isProgramRunning()
{
  return Helper::getPID(m_programName) ? 1 : 0;
}


int ProgramHandler::performRestart()
{
 waitpid(Helper::getPID(m_programName), 0, 0);
 return 1;
}

void ProgramHandler::stop()
{

 return;
}


std::string ProgramHandler::exec(const char* cmd, bool printOutput = 0)
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
        if(printOutput)
        {
          std::cout << buffer <<std::flush;
        }
      }
    }
  }
  catch (std::exception const& e)
  {
    pclose(pipe);
    throw;
  }
  pclose(pipe);
  return result;
	
}

void ProgramHandler::runMakefile()
{
    exec("make -C ../", 1);
}

void ProgramHandler::cleanMakefile()
{
    exec("make clean -C ../");
}
