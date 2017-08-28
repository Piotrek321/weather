#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>
#include <signal.h>

class Testing
{
public:
  Testing()
  { 
    std::cout << "Testing()\n";
  }
  ~Testing()
  { 
    std::cout << "~Testing()\n";
  }
};

bool isResetCalled = false;
void  SIGTERM_handler(int sig);
int main()
{
  Testing t;
  if(signal(SIGTERM, SIGTERM_handler) == SIG_ERR) 
  {
     printf("SIGTERM install error\n");
     exit(1);
  }
  
  while(!isResetCalled){}

  return 1;
}

void  SIGTERM_handler(int sig)
{
  printf("From SIGQUIT: just got a %d (SIGQUIT ^\\) signal and is about to quit\n", sig);
	isResetCalled =true;
  //exit(3);
}

