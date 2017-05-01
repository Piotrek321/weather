#include "../inc/fileHandler.h"

	FileHandler::~FileHandler()
	{
		fileHnd.close();
		std::cout<< "~FileHandler\n";
	}

	bool FileHandler::openFile()
	{
		if(doesFileExist(fileName))
		{
			std::cout << "File does not exist\n";
			return 0;
		}
		fileHnd.open(fileName.c_str());
		if(!fileHnd.is_open()) return 0;
			
		return 1;
	};

	void FileHandler::removeFile()
	{
		if( remove( fileName.c_str()) != 0 )
			perror( "Error deleting file" );
		else
			std::cout <<"File successfully deleted\n";
	};

	std::string FileHandler::readFileToString()
	{
	  std::ifstream ifs(fileName.c_str(), std::ios::in | std::ios::binary | std::ios::ate);

	  std::ifstream::pos_type fileSize = ifs.tellg();
	  ifs.seekg(0, std::ios::beg);

	  std::vector<char> bytes(fileSize);
	  ifs.read(&bytes[0], fileSize);

	  return std::string(&bytes[0], fileSize);
	}

	inline bool FileHandler::doesFileExist(const std::string& name)
	{
		struct stat buffer;   
		return (stat (name.c_str(), &buffer) == 1); 
	};

/*
int main(){
	FileHandler fh("test.txt");
	fh.printFile();
  std::string a;
std::cout << fh.readFileToString();

	return 1;
}*/



