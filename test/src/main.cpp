#include <gtest/gtest.h>
 #include <math.h>
#include "../../inc/ProgramHandler.h"

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
