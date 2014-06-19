#pragma once

#include "ofMain.h"
#include "dataTracker.h"
#include "myOSCManager.h"
#include "brainMeshNode.h"
#include "ofxXmlSettings.h"

enum MySelectionTracker { waitingSel, recondingSel, playingSel, doneSel};

class meshTrackerInteraction
{
public:
	void setup();
	void update(dataTracker myData, bool mode);
	bool getInternalNewSelection();
	void draw(ofEasyCam cam, dataTracker myData);
	void keyPressed(int key);

	void setMinimumDistance2Interact(float distance);
	void setMinimumMemories2Interact(int num);
	int getNearestDistance();
	ofVec3f getNearestVertex();


private:
	void updateColorAnimations(ofVec3f _position);
	void updateCleaningVectorData(int lastPosExtraSound);
	void calcAnimationsColorsAndAlphas();
	void FindNearestPointInMesh(ofVec3f _position);
	
	//Target
	ofNode target;							
	//Get tracker target
	ofVec3f positionTracker;

	//mesh to target
	float nearestDistance;
	ofVec3f nearestVertex;
	int nearestIndex, last_nearestIndex;
	int time2DoneDeselection, time2DoneSelection;
	string getNearesStringIndex(int idNearest);
	
	//NEW Brain Mesh
	vector<brainMeshNode> brainMemories;
	vector<brainMeshNode> allBrainMemories;
	string nearesStringIndex;

	//hand made timers
	void updateSelection();
	int timeSelected, last_timeSelected;
	int time2Select, last_time2Select;
	bool bMemorySelected;

	//My Selection
	float minimumDistance2Interact;
	MySelectionTracker myselection;
	ofColor colorfeedbackMeshSolid, colorfeedbackMeshTransparent, colorfeedbackMesh;
	ofColor	colorfeedbackLine, colorfeedbackLineSolid, colorfeedbackLineTransparent;
	ofColor colorfeedbackSelection, colorfeedbackSelectionSolid, colorfeedbackSelectionTransparent;
	ofColor colorfeedbackSelectionPlay, colorfeedbackSelectionPlaySolid, colorfeedbackSelectionPlayTransparent;
	int sizeMemorySelection;
	ofVec3f	vertexSel, lastvertexPlayed;
	bool bInternalNewSelection, bInternalStopSelection;
	int numDisplayedMemories;

	//mode experiement
	bool bexperimentmode;
	int counterExperimentMode;

	//OSC
	string last_idMemoryIdString;

	//Draw data
	bool bdebugInfo;
	ofTrueTypeFont  newmediaFont,newmediaFontDetail;

	//XML Brain Node Save and Load
	bool save2XmlNewBrainNode(string filename, ofVec3f positionNode);
	//read extra memories and pass last position to loadBrainNodedataXML
	int loadExtraBrainNodedataXML();
	bool loadBrainNodedataXML(int lastPos);
	int lastPosExtraSound;
	ofxXmlSettings xmlBrainNodeWrite;
};
