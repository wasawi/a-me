/*
 *  myOscManager.h
 *  A-me
 *
 *  Created by Jordi Puig on 21/09/12.
 *  Copyright 2012 Lummo. All rights reserved.
 *
 */

#ifndef myOscManager_h
#define myOscManager_h

#include "ofxOsc.h"

#define HOST "localhost"
#define PORT_SEND 3884
#define PORT_RECEIVE 3885
// port 3883 is used by VRPN

class myOscManager
{
public:
	myOscManager();
	void setupSend();
	void setupReceive();	
	void send(ofNode tracker);

private:
    ofxOscSender sender;
    ofxOscReceiver receiver;
	ofNode tracker;
};

#endif