//
//  logTracker.cpp
//

#include "logTracker.h"

// SINGLETON initalizations
bool logTracker::instanceFlag = false;
logTracker* logTracker::single = NULL;

//----------------------------------------------
logTracker* logTracker::getInstance()
{
    if(! instanceFlag)
    {
        single = new logTracker();
        instanceFlag = true;
        return single;
    }else{
        return single;
    }
}

//----------------------------------------------
logTracker::logTracker(){
//TODO: Listeners Works different in 071 version
	// ofAddListener(ofEvents.keyReleased, this, &logTracker::keyReleased); 
	// error C2228: left of '.keyReleased' must have class/struct/union
	ofAddListener(ofEvents().keyReleased, this, &logTracker::keyReleased);

	loadedFile = false;

	reading = false;

	loopData = true;

	//thread
	bLoadThreadDone = false;

	//200000 units reserved
	data.reserve(200000);

}

//----------------------------------------------
void logTracker::threadedFunction() {  

	while(isThreadRunning()) {
		
		if(lock()) {  // lock access to the resource

			//TODO: Giving priority to SAVE FILE before LOAD IT
			if(reading){ // Loading default action			{
				cout << "Loading FILE :: Threaded GOTO!" << endl;
				loadCSV(logSaver.getLastFileSaved()); // filePath
				cout << "Loading FILE :: Threaded DONE!" << endl;
			}
			unlock();  
		}
		else{
			cout << "LOCK acces ON wait to load another log" << endl;
			//STOP
			stopThread(); 
			return;
		}

		//Stuff Done
		//ENDING THREAD
		if(reading){
			bLoadThreadDone = true;
			cout << "bLoadThreadDone! So now you can read this file: " << logSaver.getLastFileSaved() << endl;
		}

		//STOP
		stopThread();  
		cout << "stopThread();!" << endl;
	}
}

//----------------------------------------------
void logTracker::update(){

    if(reading && bLoadThreadDone)
	{
		int totalRead = 1;
		int timer = ofGetElapsedTimeMillis(); 
		while(totalRead>0 && (ofGetElapsedTimeMillis()-timer) < 10){ // 5 is the less significant value that allows for now to read the whole tcp data

			totalRead = 0;
			if(data.size()>0)
			{
				if(ofGetElapsedTimeMillis()-startTime >=  data[nextIndex].time){
            
					actualData_toRead = data[nextIndex];
					
					ofQuaternion auxQuat;
					auxQuat = actualData_toRead.getOrientationQuat();

					if(nextIndex<(data.size()-1))nextIndex++;
			
					if(nextIndex==(data.size()-1) && loopData){
						//reset
						nextIndex = 0;
						startTime = ofGetElapsedTimeMillis();
					}
					totalRead = 1;
				}
			}
		}
	}//if	
}

//----------------------------------------------
void logTracker::draw(int x, int y){
   
	if(reading)
	{
		ofPushMatrix();
		ofTranslate(x,y,0);
		ofDrawBitmapString("Reading Log"+ofToString(nextIndex)+"/"+ofToString(data.size()), 0,0);
		ofPopMatrix();
	}

}

//----------------------------------------------
int logTracker::getDuration(){
    return data[data.size()-1].time;
}

//----------------------------------------------
void logTracker::setLoop(bool value){
    loopData = value;
}

//----------------------------------------------
bool logTracker::getIsReading(){
    return reading;
}

// -----------------------------------------------------
// READ METHODS
// -----------------------------------------------------

//----------------------------------------------
void logTracker::startRead(){
	
	cout << "Start Playing Log data " << endl;

	loadedFile = false;
	
    startTime = ofGetElapsedTimeMillis();
    nextIndex = 0;
	reading   = true; // important to be located before loading file to allow thread funcion to recognise threaded action

	if (!logSaver.getLastLoadedFileStatus()){
		cout << "loading Log file... " << endl;
		//load("log.xml");
		loadThreaded(logSaver.getLastFileSaved()/*last_filename*/);

		cout << "startRead() -> loadThreaded(xxxx.xml):" << logSaver.getLastFileSaved() << " thread loading active" << endl;
		loadedFile = true;
		logSaver.setLoadedFile(loadedFile);
	}
	
}

//----------------------------------------------
void logTracker::stopRead(){
    reading   = false;
	cout << "Stop playing Log data " << endl;
}


//----------------------------------------------
int logTracker::totalFramesLog(){
    return data.size();
}

//----------------------------------------------
dataTracker logTracker::read(){
    return actualData_toRead;
}

//----------------------------------------------
void logTracker::loadCSV(string filePath){
	cout << "Loading File Logtracker" << endl;

	//Reset Load Data Vars
	resetLoadVars();

	ofFile file(filePath);
	if(!file.exists()){
		ofLogError("The file " + filePath + " is missing");
	}

	ofBuffer buffer(file);
	while (!buffer.isLastLine()) {
		cout << ".";
		dataTracker temp;

		string line = buffer.getNextLine();						// get next line
		vector<string> items = ofSplitString(line, ",");		// break the line into items

		temp.time = ofToInt(items[0]);

		//position tracker
		ofVec3f pos;
		pos.x = ofToFloat(items[1]);
		pos.y = ofToFloat(items[2]);
		pos.z = ofToFloat(items[3]);

		//quaternion tracker
		ofQuaternion quat = ofQuaternion(
			ofToFloat(items[4]),
			ofToFloat(items[5]),
			ofToFloat(items[6]),
			ofToFloat(items[7])
		);

		//wii tracker buttons
		bool buttonA = ofToBool(items[8]);
		bool buttonB = ofToBool(items[9]);

		//not used yet
		//string fileName = items[10];
		//float elapsedTime = ofToFloat(items[11]);

		temp.setPosition(pos);
		temp.setOrientation(quat);
		temp.wiiButtonA = buttonA;
		temp.wiiButtonB = buttonB;

        data.push_back(temp);
	}
}

// -----------------------------------------------------
// SAVE METHODS
// -----------------------------------------------------

//----------------------------------------------
void logTracker::startWrite(){

    startTime = ofGetElapsedTimeMillis();
	logSaver.recording=true;

	closeThreaded("");

	cout << "recording frames " << endl;
	cout << "This auto will save the log at writting ending... " << endl;

}

//----------------------------------------------
int logTracker::getStartTime(){
	return startTime;
}

//----------------------------------------------
void logTracker::saveTrackerFrame(dataTracker data){

	if(!logSaver.recording) return;
	int millis = ofGetElapsedTimeMillis()-startTime;
	
	dataTracker temp;
	//temp.time= millis;
	temp.time = millis;
	temp.setPosition(data.getPosition());
	//temp.setPosition(data.target.getGlobalPosition());
	temp.setOrientation(data.getOrientationQuat());
	temp.wiiButtonA = data.wiiButtonA;
	temp.wiiButtonB = data.wiiButtonB;
	temp.filename = data.filename;
	temp.playsoundelapsedtime = data.playsoundelapsedtime;	

	logSaver.addDataToLog(temp);
}

//----------------------------------------------
void logTracker::resetLoadVars(){
	xmlWrite.clear();
	data.clear();
	data.reserve(200000);
}

//----------------------------------------------
void logTracker::loadThreaded(string fileName) { 
	bLoadThreadDone = false;
    this->fileName = fileName;  
    startThread(true, false);   // blocking, verbose  
	cout << " startThread(true, false);   // blocking, verbose  " << endl;
} 

//----------------------------------------------
void logTracker::closeThreaded(string fileName) {  
    logSaver.bCloseThreadDone = false;

    logSaver.startThread(true, false);   // blocking, verbose  ;

	cout << "  logSaver.startThread(true, false);   // blocking, verbose  ; " << endl;
}  
//----------------------------------------------
void logTracker::keyReleased(ofKeyEventArgs& eventArgs ){
    
	// read
    if(eventArgs.key=='R'){
        startRead();
    }
    if(eventArgs.key=='T'){
        stopRead();
    }
	if(eventArgs.key=='E'){
        startRead();
    }
    
    // save
    if(eventArgs.key=='S'){
        startWrite();

    }
    if(eventArgs.key=='D'){
		endWrite();
    }
	
}

//----------------------------------------------
void logTracker::endWrite(){
	logSaver.recording=false;
			
	cout << "saving Log file... " << endl;
	cout << "Trackerdata saved to data/actualTimeStamp.xml" << endl;
}


//----------------------------------------------
void logTracker::exit(){
	 logSaver.stopThread();
}