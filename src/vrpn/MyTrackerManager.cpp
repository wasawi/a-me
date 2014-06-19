#include "MyTrackerManager.h"

//----------------------------------------------
//== Position/Orientation Callback ==--
void VRPN_CALLBACK handle_pos (void *, const vrpn_TRACKERCB t)
{
	got_report = 1;

	myData.setPosition( ofVec3f( t.pos[0], t.pos[1], t.pos[2]));
	ofQuaternion quat;
	quat.set( t.quat[0], t.quat[1], t.quat[2], t.quat[3]);

	myData.setOrientation( quat);	

	//OSC A-me Controller
	myData.wiiButtonA = myOSCManager::getInstance()->getButtonPlayPressed();
	myData.wiiButtonB = myOSCManager::getInstance()->getButtonRecordPressed();
	myData.filename = myOSCManager::getInstance()->getMemoryIdString(); // Sound filename created
	
	//Tracker analisys for auto saving Logs
	statsRecorder_SetValue(myData);

	//TODO without use thread. But then directly saving when is this data extracted
	//Using queue method
	logTracker::getInstance()->saveTrackerFrame(myData);
}


//--------------------------------------------------------------
MyTrackerManager::MyTrackerManager()
{

}

//--------------------------------------------------------------
MyTrackerManager::~MyTrackerManager()
{
	stopLog();
}

//--------------------------------------------------------------
void MyTrackerManager::startLog()
{
	logTracker::getInstance()->startWrite();
}

//--------------------------------------------------------------
void MyTrackerManager::stopLog()
{
	logTracker::getInstance()->endWrite();
}
//--------------------------------------------------------------
void MyTrackerManager::setup()
{
	// receive from tracker VRPN
	port = 3883;
	sprintf(connectionName,"localhost:%d", port);
	connection = vrpn_get_connection_by_name(connectionName);

	//tracker = NULL;
	tracker = new vrpn_Tracker_Remote("Tracker", connection);

  	tracker->register_change_handler(NULL, handle_pos);
	bconnected = connection->connected();

														// modified out from this class
	bUseLog = false;									// this is affected by the UI toggle
													
	bAutolog_wasActive = false;							// AutoLog is not recording by default
	
	//Stadistisc
	counterStop=0;
	counterPlay=0;
	statsQueue=200;
	thresh= 0.001;
	statsTrackerPos.setup(statsQueue, 0, 0.001);		// statistic 100 frames, lower value 0, max value 10 // That are min max are quantity of displacement from frame to frame of Tracker 
	statsTrackerPos.update(-100.0);					// set initial value to prevent writing log on startup
	counterDelay=250;
}

//--------------------------------------------------------------
void MyTrackerManager::update()
{	
	if(bUseLog){
		logTracker::getInstance()->update();

		//Use Log as reading tracker and emulating it
		if(logTracker::getInstance()->getIsReading() && logTracker::getInstance()->bLoadThreadDone){
			
			myData = logTracker::getInstance()->read();
			
			// Tracker analisys for auto saving Logs
			statsRecorder_SetValue(myData);

			// OSC Messages
			myOSCManager::getInstance()->emuleController(myData.filename/*, myData.elapsedTimeMemory*/, myData.wiiButtonA, myData.wiiButtonB);

		}
		//if it's trying to write tracker
		else
		{
			updateTracker();
		}
	}
	else{
		updateTracker();
	}

	if(bUseAutoLog){								//if autolog is activated from GUI
		if (average()>thresh){						//if there is somebody

			if (bAutolog_wasActive==false){			//if it was not active before
			counterPlay++;							//increment counter
			cout << "counterPlay " << counterPlay << endl;

				if (counterPlay > counterDelay){		//if the counter is above thresh
					startLog();							//we start the log
					bAutolog_wasActive = true;			//prevent the log to start every frame
					counterPlay=0;
				}
			}
			counterStop=0;
		}
		else{										//if there is nobody
			if (bAutolog_wasActive==true){			//if it is the first time
				counterStop++;						//increment counter
				cout << "count before stop " << counterStop << endl;

				if (counterStop > counterDelay){		//if the counter is above thresh			
					stopLog();							//we stop the log
					bAutolog_wasActive = false;			//prevent the log to stop every frame
					counterStop=0;
				}
			}
			counterPlay=0;
		}
	}else{											//if  we deactivate autolog and there is somebody
			if (bAutolog_wasActive==true){			//if it is the first time
				stopLog();							//we stop the log
				bAutolog_wasActive = false;			//prevent the log to stop every frame
			}												
	}
}


//--------------------------------------------------------------
void MyTrackerManager::updateTracker()
{
	// Purge all of the old reports
    tracker->mainloop();

	//If does not connect then keep trying
    if(connection->connected())
    {
		bconnected = true;           
		// Make sure that we get a new report
        got_report = 0;
		if (!got_report) {
			tracker->mainloop();
		}
	}
}

//--------------------------------------------------------------
void MyTrackerManager::draw()
{
	/*
	ofSetColor(20, 20, 20);
	ofDrawBitmapString("raw from log:\n", x, y);
	logTracker::getInstance()->draw(x, y+10);
	*/
	int x=300;
	int y=0;
	int height=80;

	//Statistics Drawing
	ofPushStyle();
   		ofNoFill();
		int lineColor = 0xFF0000;
		if (average()<thresh){lineColor=0xFFFFFF;}
		statsTrackerPos.draw(x, y, statsQueue, height, statsQueue, "Tracker motion",false, lineColor);
		ofSetHexColor(0xFFFFFF);
		ofDrawBitmapString( "Last Value: " + ofToString( average(), 7 ), x+5, y+30);
    ofPopStyle();
}

//----------------------------------------------
//	Tracker Analisys
//----------------------------------------------
void statsRecorder_SetValue(dataTracker data){

	ofVec3f auxpos = data.getPosition();	
	float diff = auxpos.distance(last_posTracker);	//get difference current pos last pos
	//cout << "statsTracker diff Raw = " << diff << endl;
	statsTrackerPos.update(diff);					// update value
	last_posTracker = auxpos;						// save last value
}

//----------------------------------------------
//	Get // Set
//----------------------------------------------
ofVec3f MyTrackerManager::getPosition(){
	return myData.getPosition();
}
//----------------------------------------------
ofQuaternion MyTrackerManager::getOrientation(){
	return myData.getOrientationQuat();
}
//----------------------------------------------
float MyTrackerManager::average(){
	return statsTrackerPos.getAverage(statsQueue);
}
//----------------------------------------------
bool MyTrackerManager::getIsConnected()
{
	return bconnected;
}
//----------------------------------------------