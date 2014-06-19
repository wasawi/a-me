//
//  logTracker.h
// 
//  Log Read/Write created by mar Canet sola on 4/4/12.
//  Modified by Carles Gutierrez on 20/1/13
//	+FlyData vector to save CPU during the process
//	+Threaded Log services to write and read all as fly data from/to File.xml
//

#ifndef LaserRangeNetwork_logTracker_h
#define LaserRangeNetwork_logTracker_h

#include "ofMain.h"
#include "ofxXmlSettings.h"
#include "dataTracker.h"
#include "logClosingThreaded.h"



class logTracker : public ofThread{
    // variables & methods for singleton
private:
    static bool	instanceFlag;
    static logTracker *single;	

public: 
    static logTracker* getInstance();
    // end singleton

    logTracker();
	void update();
	void draw(int x, int y);
	void exit();
    
	int getDuration();
   
    void startRead();
	void startWrite();
	void endWrite();
    void load(string file);
	void loadCSV(string file); // TODO This should be faster Load method XML struct
    void stopRead();
    void setLoop(bool value);
    int totalFramesLog();
	bool getIsReading();

	void saveTrackerFrame(dataTracker data);
	dataTracker read();	



	/////////////////////////////////////////////
	//Simple Threaded Method to close a file
	string fileName, last_filename;  
    void threadedFunction();
    void loadThreaded(string fileName); 
	bool bLoadThreadDone;
	void closeThreaded(string fileName);
	logClosingThreaded logSaver;

	void resetLoadVars();

	int getStartTime();
	 
private:
    void keyReleased(ofKeyEventArgs& eventArgs );
    
    ofxXmlSettings xmlWrite;
    ofxXmlSettings xmlRead;
    vector<dataTracker> data;
	dataTracker actualData_toRead;

    int startTime, nextIndex;
    bool loopData, reading, loadedFile;

};

#endif
