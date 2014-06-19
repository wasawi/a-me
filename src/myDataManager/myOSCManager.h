#ifndef _OSC_MANAGER_H
#define _OSC_MANAGER_H

#include "ofMain.h"
#include "ofxOsc.h"
#include "dataTracker.h"
#include "vrpn_Tracker.h"

//#define HOST "localhost"
#define HOST "10.30.255.238"
#define PORT_SEND 9002//3884
#define PORT_RECEIVE 9001//3885
#define NUM_MSG_STRINGS 20

class myOSCManager
{
   
// variables & methods for singleton
private:
    static bool	instanceFlag;
    static myOSCManager *single;	

public: 
    static myOSCManager* getInstance();
    // end singleton
	
public:
	//Constructor & Destructors
	myOSCManager();
	~myOSCManager();

	void setupSend();
	void setupReceive();	
	void sendTrackerDataMachineStatus(int bplaying, int brecording);
	void sendMeshTrackerDistance(string idUnicmemory, float distance, float threshold);

	//OSC Memories
	void receiveOSC();
	void actionMemoryAnalisis();
	bool getIsRecordingMemory();
	bool getIsPlayingMemory();
	//Get ID and filename.mp3
	string getMemoryIdString();

	bool getButtonPlayPressed();
	bool getButtonRecordPressed();

	//Log Emuletation
	void emuleController(string _idMemoryIdString/*, float _elapsedTimeMemory*/, bool _bPlayStopMemory, bool _bRecStopMemory);


private:

	int current_msg_string;
	string msg_strings[NUM_MSG_STRINGS];
	float timers[NUM_MSG_STRINGS];

	// OSC vars
	ofxOscSender sender;
    ofxOscReceiver receiver;

	//vars
	string idMemoryIdString;
	float elapsedTimeMemory;
	bool bPlayStopMemory, last_bPlayStopMemory;
	bool bRecStopMemory, last_bRecStopMemory;

	//actions
	bool bPlayingMemory, bStopingPlayingMemory;
	bool bRecordingMemory, bStopRecordingMemory;
};

#endif