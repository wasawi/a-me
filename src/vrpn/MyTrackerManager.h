#pragma once

#include "ofMain.h"
#include "myOSCManager.h"
#include "dataTracker.h"
#include "logTracker.h"
#include "statsRecorder.h"

// for kbhit()
#include "vrpn_Connection.h" // Missing this file?  Get the latest VRPN distro at
#include "vrpn_Tracker.h"    //    ftp://ftp.cs.unc.edu/pub/packages/GRIP/vrpn
#include "conio.h"           // for kbhit()


// Callback prototype
void VRPN_CALLBACK handle_pos (void *, const vrpn_TRACKERCB t);

// Global variables 
static int  got_report;     // Tells when a new report has come in
static dataTracker myData;


//Global statistics to access from VRPN callback
void statsRecorder_SetValue(dataTracker data);
static statsRecorder   statsTrackerPos;
static ofVec3f posTracker, last_posTracker;


/*
class myDataTracker : ofNode {

public:

	bool wiibuttonA;
	bool wiibuttonB;
	string idStringFileName;
};*/


class MyTrackerManager
{
public:

	MyTrackerManager();
	~MyTrackerManager();

	void	setup();
	void	update();
	void	updateTracker();
	void	draw();
	dataTracker getData();
	bool	getIsConnected();

	ofVec3f getPosition();
	ofQuaternion getOrientation();

	// to activate or deactivate log
	bool	bUseLog, bUseAutoLog;
	void	startLog();
	void	stopLog();

	// statistics
	int		statsQueue;
	float	thresh;
	float	average();
	bool	bAutolog_wasActive;
	int		counterPlay, counterStop, counterDelay;

	/*
	//Global statistics to access from VRPN callback
	void statsRecorder_SetValue(dataTracker data);
	statsRecorder   statsTrackerPos;
	ofVec3f posTracker, last_posTracker;
	*/

private:
	vrpn_Connection *connection;
	char	connectionName[128];
	int		port;
	bool	bconnected;

	vrpn_Tracker_Remote *tracker;
};
