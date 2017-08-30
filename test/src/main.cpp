#include <gtest/gtest.h>
#include <math.h>
#include "../../inc/ProgramHandler.h"
#include "../../inc/FileHandler.h"

TEST(FileHandlerTest, OpenExistingFileTest) { 
	FileHandler fh("fileForTest.txt");
  ASSERT_TRUE(fh.openFile());
}

TEST(FileHandlerTest, OpenNonExistingFileTest) { 
  FileHandler fh("fileDoesNotExist.txt");
  ASSERT_FALSE(fh.openFile());
}

TEST(FileHandlerTest, ReadFromFileTest) { 
	FileHandler fh("fileForTest.txt");
  ASSERT_TRUE(fh.openFile());
	std::string stringToCompare = "Testing123\nHello\n";
	ASSERT_EQ(fh.readFileToString(), stringToCompare);
}

TEST(FileHandlerTest, CreateRemoveFileTest) { 
	FileHandler fh("fileToBeCreated.txt");
  ASSERT_FALSE(fh.doesFileExist("fileToBeCreated.txt", 1));
  fh.createFile();

  ASSERT_TRUE(fh.doesFileExist("fileToBeCreated.txt", 1));
	fh.removeFile();
  ASSERT_FALSE(fh.doesFileExist("fileToBeCreated.txt", 1));
}

TEST(ProgramHandlerTest, StartStopTest) { 

  ProgramHandler t("./program");
  ASSERT_FALSE(t.isProgramRunning());

  ASSERT_EQ(t.startApp(), 1);
	ASSERT_TRUE(t.isProgramRunning());
	t.stop();
  //ASSERT_TRUE(t.stop());
	ASSERT_FALSE(t.isProgramRunning());
}

TEST(ProgramHandlerTest, PerformRestart) { 

  ProgramHandler t("./program");
  ASSERT_FALSE(t.isProgramRunning());

  ASSERT_EQ(t.startApp(), 1);
	ASSERT_TRUE(t.isProgramRunning());
	ASSERT_NE(t.performRestart(), -1);
	ASSERT_TRUE(t.isProgramRunning());
	t.stop();
	ASSERT_FALSE(t.isProgramRunning());
}
 
 

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
