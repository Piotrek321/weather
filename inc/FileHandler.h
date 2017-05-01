#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <vector>
class FileHandler
{

	public:
		FileHandler(std::string fName) : fileName(fName)
		{
			openFile();
		}

		~FileHandler();
		bool openFile(); //TODO options
    bool writeLineToFile();

		
		bool readFile();

				void createFile();		
		void removeFile();		
	 bool doesFileExist(const std::string& name);
	std::string readFileToString();
	protected:
	  std::fstream fileHnd;
		int numberOfCurrentLine;
		const std::string fileName;
};

/*
  ofstream: Stream class to write on files
  ifstream: Stream class to read from files
  fstream: Stream class to both read and write from/to files.
*/
