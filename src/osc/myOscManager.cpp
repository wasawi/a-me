/*
 *  myOscManager.cpp
 *  A-me
 *
 *  Created by Jordi Puig on 21/09/12.
 *  Copyright 2012 Lummo. All rights reserved.
 *
 */

#include "myOscManager.h"

myOscManager::myOscManager()
{
}

void myOscManager::setupSend()
{
    sender.setup( HOST, PORT_SEND );
}

void myOscManager::setupReceive()
{
    receiver.setup( PORT_RECEIVE );
}


void myOscManager::send(ofNode tracker)
{
    ofxOscMessage m;
    m.setAddress( "/tracker" );

    // position	
    m.addFloatArg( tracker.getX() );
    m.addFloatArg( tracker.getY() );
	m.addFloatArg( tracker.getZ() );

    // orientation
	ofQuaternion quat = tracker.getOrientationQuat();
    m.addFloatArg( quat.x() );
    m.addFloatArg( quat.y() );
	m.addFloatArg( quat.z() );
    m.addFloatArg( quat.w() );

	sender.sendMessage( m );
}