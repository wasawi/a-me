//
//  logClosingThreaded.cpp
// 
#include "logClosingThreaded.h"

//----------------------------------------------
logClosingThreaded::logClosingThreaded() {  
	bCloseThreadDone = false;

	loadedFile = false;
	last_filename = "./logs/log.csv";
	filename = last_filename;
	allData="";

	//OJO recording MUST be false at the begining
	recording=false;
}

//----------------------------------------------
logClosingThreaded::~logClosingThreaded() {  
}

//--------------------------------
void clearQ( std::queue<QueuedLog> q )
{
   std::queue<QueuedLog> empty;
   std::swap( q, empty );
}

//----------------------------------------------
void logClosingThreaded::threadedFunction() {  

	while(isThreadRunning()) {

		QueuedLog i;
		//cout << "QUEUE Size=" << q.size() << endl;

		// lock access to the resource
		//if(lock()) {
			if(!q.empty()){
				i = q.front();
				q.pop();

				saveFrameCVS(i.logdata);
			}
			else{
				//cout << "QUEUE IS EMPTY" << endl;
				//Close it if its the time to do it
				if(!recording){
					
					// Close file
					closeCVS(i.filename);

					// clear string
					allData.clear();

					// thread is cloase
					bCloseThreadDone = true;
					
					// file can be loaded
					loadedFile = false;	
					
					//If cue empty stop saving with thread
					stopThread();
				}	
	
			//}
		//unlock();
		//ofSleepMillis(10); 
		}
    }
} 

//----------------------------------------------
string logClosingThreaded::getLastXmlFileSaved()
{
	if(std::string("./logs/log.csv").compare(last_filename)==0){
		if(!loadLastLogfromXmlAllLogs()){
			last_filename = "./logs/log.csv";
		}
	}

	return last_filename;
}

//----------------------------------------------
string logClosingThreaded::getLastFileSaved()
{
	return last_filename;
}

//---------------------------------------------- 
bool logClosingThreaded::getLastLoadedFileStatus()
{
	return loadedFile;
}

//----------------------------------------------
void logClosingThreaded::setLoadedFile(bool var){
	loadedFile = var;
}

//----------------------------------------------
void logClosingThreaded::saveFrameCVS(dataTracker savedData){

	string frame;
	frame="";

	int millis;
	millis = savedData.time;
	frame=ofToString(millis, 0)+", ";

	//position tracker
	ofVec3f pos;
	pos = savedData.getPosition();
	string posx, posy, posz;
	posx= ofToString(pos.x) + ", ";
	posy= ofToString(pos.y) + ", ";
	posz= ofToString(pos.z) + ", ";

	frame.append(posx);
	frame.append(posy);
	frame.append(posz);

	//quaternion tracker
	ofQuaternion quat;
	quat = savedData.getOrientationQuat();
	string quatx, quaty, quatz, quatw;
	quatx= ofToString(quat.x()) + ", ";
	quaty= ofToString(quat.y()) + ", ";
	quatz= ofToString(quat.z()) + ", ";
	quatw= ofToString(quat.w()) + ", ";
	frame.append(quatx);
	frame.append(quaty);
	frame.append(quatz);
	frame.append(quatw);


	//wii buttons tracker
	bool buttonA;
	bool buttonB;
	buttonA = savedData.wiiButtonA;
	buttonB = savedData.wiiButtonB;
	string bA, bB;
	bA= ofToString(buttonA, 1) + ", ";
	bB= ofToString(buttonB, 1) + ", ";
	frame.append(bA);
	frame.append(bB);

	//file name
	string idNameFile;
	idNameFile = savedData.filename + ", ";
	frame.append(idNameFile);

	//Sound Ellapsed time
	float soundellapsedtime;
	soundellapsedtime = savedData.playsoundelapsedtime;
	string ellapsedTime;
	ellapsedTime= ofToString(soundellapsedtime, 6) + ";\n";
	frame.append(ellapsedTime);
	
	/* TEST
	//Save Target Data // the pointer of the tracker
	ofVec3f posTarget;
	posTarget = savedData.target.getGlobalPosition(); 
	string posTargetx, posTargety, posTargetz;
	posTargetx= ofToString(pos.x) + ", ";
	posTargety= ofToString(pos.y) + ", ";
	posTargetz= ofToString(pos.z) + ", ";
	frame.append(posTargetx);
	frame.append(posTargety);
	frame.append(posTargetz);
	*/

	//SAVE ALL
	allData.append(frame);
	cout << "log: " << millis << endl;
}

//----------------------------------------------
void logClosingThreaded::closeCVS(string file){
    if(file==""){
		//default log name with a timeSamp
		string timeStamp = ofGetTimestampString();
		std::string fname = std::string("./logs/log_") + timeStamp + std::string(".csv");

		//save CVS
		ofBuffer buff;
		buff.set(allData.c_str(), allData.size());
		bool fileWritten = ofBufferToFile(fname, buff);

		//save here a new CVS 
		saveAllLogsFile(fname, timeStamp, "version 9, 2D, Headphones");

		//update last name in case you wanna load it
		//must wait until is totaly save it, check loadedFile var!
		last_filename = fname;
		loadedFile = false; //next load need to read the new log_xxx_CVS
		
		cout << "last_filename = " << last_filename << endl;
    }else{
        xmlWrite.saveFile(file);
		last_filename = file;
		loadedFile = false;
    }

	tagNum = 0;
}

//--------------------------------
void logClosingThreaded::addDataToLog(dataTracker savedData) {       

    QueuedLog qlog;  
    qlog.logdata = savedData;
    q.push(qlog);
        
} 

//----------------------------------------------
bool logClosingThreaded::saveAllLogsFile(string filename, string timeStamp, string notes) {
	
	//xmlBrainNodeWrite.clear();
	//Load and Write

	bool bloaded = xmlLogs.loadFile("./logs/AllLogs.xml");
	
	//if does not exist this tag, then create it
	if(!xmlLogs.pushTag("AllLogs"))
	{ 
		xmlLogs.addTag("AllLogs");
		xmlLogs.pushTag("AllLogs");
	}

	int numberOfSavedPoints = xmlLogs.getNumTags("log");
	xmlLogs.addTag("log");
    xmlLogs.pushTag("log",numberOfSavedPoints); //pusht new tag in the last position

    xmlLogs.addValue("filename", filename);
	xmlLogs.addValue("timeStamp", timeStamp);
	xmlLogs.addValue("notes", notes);
	
	bool saved = false;
	std::string fname = std::string("./logs/") + std::string("AllLogs.xml");
	saved = xmlLogs.saveFile(fname);

	cout << "Saving file = " << fname << endl;
	return saved;
}

//----------------------------------------------
bool logClosingThreaded::loadLastLogfromXmlAllLogs() {
	
	//cleaning in case it has been used before
	xmlLogs.clear();

	//Load and Read
	bool bloaded = xmlLogs.loadFile("./logs/AllLogs.xml");
	if(!bloaded){
		cout << "logClosingThreaded::Error AllLogs.xml bad loaded or not exist, then create Xml" << endl;
		bool saved = false;
		std::string fname = std::string("./logs/") + std::string("AllLogs.xml");
		saved = xmlLogs.saveFile(fname);
		bloaded = xmlLogs.loadFile("AllLogs.xml");
	}
	//if does not exist this tag, then create it, anyway that push the tag
	if(!xmlLogs.pushTag("AllLogs"))
	{ 
		xmlLogs.addTag("AllLogs");
		bool auxResPushTag = xmlLogs.pushTag("AllLogs");
		cout << "save2XmlNewBrainNode::AllLogs.xml AllLogs is empty and last push tag is " << (int)auxResPushTag << endl;
	}

	int numberOfSavedLogs = xmlLogs.getNumTags("log");

	bool bloadedNode = xmlLogs.pushTag("log",/*i*/numberOfSavedLogs-1); //pusht new tag in the first node
	cout << "numberOfSavedLogs i=" << /*i*/numberOfSavedLogs-1 << "bool =" << (int)bloadedNode << endl;
		
	string lastFilename2load = xmlLogs.getValue("filename", "");
	cout << "lastFilename2load = " << lastFilename2load << endl;
	if(bloaded)last_filename = lastFilename2load;		
	xmlLogs.popTag();
	
	return bloaded;
}

