#include "myOSCManager.h"


// SINGLETON initalizations
bool myOSCManager::instanceFlag = false;
myOSCManager* myOSCManager::single = NULL;

//----------------------------------------------

myOSCManager* myOSCManager::getInstance()
{
    if(! instanceFlag)
    {
        single = new myOSCManager();
        instanceFlag = true;
        return single;
    }else{
        return single;
    }
}

//----------------------------------------------
myOSCManager::myOSCManager()
{
	idMemoryIdString = "";
	elapsedTimeMemory = 0.0;
	bPlayStopMemory = false;
	last_bPlayStopMemory = false;
	bRecStopMemory = false;
	last_bRecStopMemory = false;

	bRecordingMemory = false;
	bStopRecordingMemory = false;

	bPlayingMemory= false;
	bStopingPlayingMemory = false;
}

//----------------------------------------------
myOSCManager::~myOSCManager()
{	
}

//----------------------------------------------
void myOSCManager::setupSend()
{
    sender.setup( HOST, PORT_SEND );
	cout << endl << "************ OSC ************" << endl;
	cout << "OSC sending at \"" << HOST << "\" port:" << PORT_SEND << endl;
}

//----------------------------------------------
void myOSCManager::setupReceive()
{
    receiver.setup( PORT_RECEIVE );
}

//--------------------------------------------------------------
string myOSCManager::getMemoryIdString(){
	return idMemoryIdString;
}


//--------------------------------------------------------------
// RECIVERS AND SENDERS
//--------------------------------------------------------------

//--------------------------------------------------------------
void myOSCManager::receiveOSC()
{
	// check for waiting messages
	while(receiver.hasWaitingMessages()){
		// get the next message
		ofxOscMessage m;
		receiver.getNextMessage(&m);

		// check for mouse moved message
		if(m.getAddress() == "/memory"){
			// both the arguments are int32's
			idMemoryIdString = m.getArgAsString(0);
			elapsedTimeMemory = m.getArgAsFloat(1);
			bPlayStopMemory  = (bool)m.getArgAsInt32(2);
			bRecStopMemory =  (bool)m.getArgAsInt32(3);

			cout << "received: /memory "<< idMemoryIdString  <<" "<< elapsedTimeMemory <<" "<< bPlayStopMemory <<" "<< bRecStopMemory << endl;
			actionMemoryAnalisis();
		}
	}
}	

//-------------------------------------------------------
// Mesh interaction OSC manager
void myOSCManager::sendMeshTrackerDistance(string idUnicmemory, float distance, float threshold)
{
    ofxOscMessage m;
    m.setAddress( "/distance" ); //meshTrackerDataAction

	m.addStringArg( idUnicmemory );
    m.addFloatArg( distance );
	m.addFloatArg( threshold );

	sender.sendMessage( m );
}

//-------------------------------------------------------
// Mesh interaction OSC manager
void myOSCManager::sendTrackerDataMachineStatus(int bplaying, int brecording)
{
    ofxOscMessage m;
    m.setAddress( "/machineStatus" ); //meshTrackerDataAction

	m.addIntArg(int(bplaying));
	m.addIntArg(int(brecording));

	sender.sendMessage( m );
}

//-------------------------------------------------------
bool myOSCManager::getButtonPlayPressed(){
	return bPlayStopMemory;
}

//-------------------------------------------------------
bool myOSCManager::getButtonRecordPressed(){
	return bRecStopMemory;
}


//-------------------------------------------------------
bool myOSCManager::getIsRecordingMemory()
{
	return bRecordingMemory;
}

//-------------------------------------------------------
bool myOSCManager::getIsPlayingMemory()
{
	return bPlayingMemory;
}

//-------------------------------------------------------
void myOSCManager::actionMemoryAnalisis()
{
	//Actions to PLAY
	if(bPlayStopMemory != last_bPlayStopMemory)
	{
		if(bPlayStopMemory){
			bPlayingMemory = true;
			bStopingPlayingMemory = false;
		}
		else {
			bPlayingMemory = false;
			bStopingPlayingMemory = true;
		}
		last_bPlayStopMemory = bPlayStopMemory;
	}

	//Actions to REC
	if(bRecStopMemory != last_bRecStopMemory)
	{
		if(bRecStopMemory){
			bRecordingMemory = true;
			bStopRecordingMemory = false;
		}
		else {
			bRecordingMemory = false;
			bStopRecordingMemory = true;
		}

		last_bRecStopMemory = bRecStopMemory;
	}
	
}

//-------------------------------------------------------
void myOSCManager::emuleController(string _idMemoryIdString/*, float _elapsedTimeMemory*/, bool _bPlayStopMemory, bool _bRecStopMemory)
{
	idMemoryIdString = _idMemoryIdString;
	//elapsedTimeMemory = _elapsedTimeMemory;
	bPlayStopMemory	= _bPlayStopMemory;
	bRecStopMemory = _bRecStopMemory;

	actionMemoryAnalisis();
}