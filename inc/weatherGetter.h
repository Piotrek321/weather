
class WeatherGetter
{
	public:
		void setup();
		bool createFileToStoreRecords();
		bool putMyIDIntoSharedMemory();
		void waitForSignal();
		void handleSignal();
		void getIDOfSecondProcess();





};
