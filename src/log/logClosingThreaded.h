//
//  logTracker.h
// 
//  Log Read/Write created by mar Canet sola on 4/4/12.
//  Modified by Carles Gutierrez on 20/1/13
//  Modified by Jordi Puig also....
//	+FlyData vector to save CPU during the process
//	+Threaded Log services to write and read all as fly data from/to File.xml
//

#ifndef LaserRangeNetwork_logClosingThreaded_h
#define LaserRangeNetwork_logClosingThreaded_h

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "dataTracker.h"
//#include "logTracker.h"

struct QueuedLog{
    string filename;
	dataTracker logdata;
};

class logClosingThreaded : public ofThread{

public: 

	logClosingThreaded();  
	~logClosingThreaded();
	void keyReleased(ofKeyEventArgs& eventArgs );
	void threadedFunction();

	void clearQ( std::queue<int> q );

	string getLastFileSaved();
	string getLastXmlFileSaved();

	bool getLastLoadedFileStatus();
	void setLoadedFile(bool var);
	void addDataToLog(dataTracker savedData);  
	void saveFrameCVS(dataTracker savedData);
	void closeCVS(string file="");

	//Que to save all new Logs to save in the thread
	queue<QueuedLog> q;
	bool recording, bCloseThreadDone;


private:
	
	string last_filename, filename, allData;

    int startTime, nextIndex;
    bool loopData, reading, loadedFile;	//loadedFile status to let LogTracker to load the next last_filename 

	
	//XML 
	int tagNum;
	ofxXmlSettings xmlWrite;
    ofxXmlSettings xmlRead;
	ofxXmlSettings xmlLogs;
	
	//XML LOGS
	bool saveAllLogsFile(string filename, string timeStamp, string notes);
	bool loadLastLogfromXmlAllLogs();
}; 

#endif
