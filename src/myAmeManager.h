//
//  myAmeManager.h
// 

#ifndef my_Visualization_Manager
#define my_Visualization_Manager

#include "ofMain.h"

#include "ofxVolumetrics.h"
#include "ofxUI.h"
#include "MyTrackerManager.h"
#include "meshTrackerInteraction.h"
#include "dataTracker.h"
#include "ofxEasingFunc.h"
#include "ofxTimer.h"

// Log
#include "logTracker.h"

class myAmeManager{

public: 
    myAmeManager(); 
	~myAmeManager();

	void setup();
    void update();
    void draw(); 
	void drawMesh();
	void exit();

	void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);

	//Camera
    ofEasyCam cam;
    ofQuaternion camOrientation;
	ofVec3f camPos;
	ofMatrix4x4 posMat;
	bool bcameraMode;

	//Volume Rendering
    ofxVolumetrics myVolume;
    unsigned char * volumeData;
    int volWidth, volHeight, volDepth;
    ofxImageSequencePlayer imageSequence;
    bool linearFilter;
	float lastClipPlaneDepth;
	float RGBA[4], RGBA_mean[4], RGBA_var[4];

	//Animations
	void updateVolumeAnimations();
	ofxTimer animationTimer;
	bool banimationTimer_INI, last_banimationTimer_INI,banimationTimer_STOP, last_banimationTimer_STOP, bactionTimer;
	int timeAnimation;
	float last_clipPlaneDepth;
	bool bUpAnimation;

	//UI	
	void saveCameraPosition();
	void loadCameraPosition();
	void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
	void guiEvent(ofxUIEventArgs &e);	
	void setup_GUI1(); 
	void setup_GUI2(); 
	void setup_GUI3(); 
	
	ofxUICanvas *gui1;
	ofxUICanvas *gui2;
	ofxUICanvas *gui3;
	ofColor backgroundColor; 

	//stats
	bool bStadisticsVisible;
	
	//Vars from UI to A-me
	float FBOq, Zq, thresh, density, dithering;
	float clipPlaneDepth, azimuth, elevation;
	bool bdrawGrid; 
	bool bdrawPadding; 
	float auxDistance;
	int numDisplayedMemories; // number of memories used in the vector to play displayed memories
		
	//Window properties
	int windowXpos;

	//XML settings
	ofxXmlSettings XML; 
	string message;
	
	//Mesh
	void drawGrid(float x, float y); 
	meshTrackerInteraction mesh_tracker_interaction;
	bool bexperimentmode;
	
	//Tracker
	dataTracker myData;
	MyTrackerManager myTracker;
	float angle, tilt, pan, roll;
	float scale;
};

#endif
