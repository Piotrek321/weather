#include <iostream>

class FileHandler
{

	public:
		FileHandler(std::string fName) : fileName(fName){};
		bool openFile(); //TODO options
		bool closeFile();
    bool writeLineToFile();

		std::string fileName;
		
		int getNumberOfCurrentLine();
		void updateNumberOfCurrentLine();
	protected:
		int numberOfCurrentLine;

};

