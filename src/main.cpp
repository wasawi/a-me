#include "ofMain.h"
#include "testApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
//	window.setOrientation(OF_ORIENTATION_180);
//	window.enableSetupScreen();
	ofSetupOpenGL(&window, /*1440 , 900*/ 1920, 1080, OF_FULLSCREEN);		
	
	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new testApp());

}
