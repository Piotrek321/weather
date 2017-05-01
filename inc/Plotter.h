#include <iostream>

#define SHMSZ     100
#define KEY_VALUE 5678

class Plotter
{
	public:
		Gnuplot gp;

		int *SharedMemoryPTR;
		
		void init();
		void handleSignal();//TODO
		void plotChart();
		void waitForUsersResond();
		void plotChart(Gnuplot &gp,std::vector<int> valuesToPlot, std::vector<std::pair<int,int>> dataToPlot );			
}


