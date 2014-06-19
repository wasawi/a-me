#include "meshTrackerInteraction.h"

//--------------------------------------------------------------
void meshTrackerInteraction::setup(){
	
	//Vectors with data to fill
	brainMemories.clear();
	allBrainMemories.clear();

	//any way previouly loaded by GUI params
	if(numDisplayedMemories<0) numDisplayedMemories = 1;
	if(minimumDistance2Interact<0) minimumDistance2Interact = 40;

	//setup selections vars
	last_time2Select= -2; // set different to time2Select to allow differences comparations
	time2Select = -1;
	last_nearestIndex = -1;
	nearestIndex = -1;
	last_timeSelected = -1;
	timeSelected = -1;

	//nearesStringIndex
	nearesStringIndex = "";

	//Initial status
	myselection = waitingSel;

	bdebugInfo = false;

	//TODO param this vars by UI
	time2DoneDeselection = 5000; // set number of milliseconds to X seconds keeping playing a Memory
	time2DoneSelection = 3000;

	// setups OSC sockets
	myOSCManager::getInstance()->setupSend();
	myOSCManager::getInstance()->setupReceive();

	//load fonts
	bool bfontLoaded = newmediaFont.loadFont("fonts/NewMedia Fett.ttf", 14, true, true);
	if(!bfontLoaded)cout << "Error NewMedia Fett.ttf font not loaded" << endl;
	newmediaFont.setLineHeight(18.0f);
	newmediaFont.setLetterSpacing(1.037);

	bfontLoaded = newmediaFontDetail.loadFont("fonts/NewMedia Fett.ttf", 9, true, true);
	if(!bfontLoaded)cout << "Error NewMedia Fett.ttf font not loaded" << endl;
	newmediaFontDetail.setLetterSpacing(1.5);


	//ColorDefinitions
	colorfeedbackMesh = ofColor::gray;
	colorfeedbackSelectionPlay = ofColor::red;

	//Loading data from XMLs
	lastPosExtraSound = 0;
	lastPosExtraSound = loadExtraBrainNodedataXML();
	loadBrainNodedataXML(lastPosExtraSound);

	//mode experiment
	bexperimentmode = false;
	counterExperimentMode = 0;
}

//--------------------------------------------------------------
void meshTrackerInteraction::updateCleaningVectorData(int lastExtraPos){
	//Keep Clean with the last 50th memories

	if(brainMemories.size()>0 && numDisplayedMemories > 1){

		while(brainMemories.size() > numDisplayedMemories) //50
		{
			cout << "Keeping only last numMemories actives=" << numDisplayedMemories << " actual vector brainMemories size =" << brainMemories.size() << endl;
			brainMemories.erase(brainMemories.begin()+lastExtraPos); // 
			cout << "Keeping only last DONE" << endl;
		}
	}
}

//--------------------------------------------------------------
void meshTrackerInteraction::update(dataTracker myData, bool experimentmode){
	
	bexperimentmode = experimentmode;

	//TRACKER DATA
	target = myData.target;									//Get tracker target
	positionTracker = ofVec3f(target.getGlobalPosition());	//Get target position
	
	//Receive OSC packets
	myOSCManager::getInstance()->receiveOSC();

	updateCleaningVectorData(lastPosExtraSound);

	//Status Machine and Osc Interaction
	updateSelection();

	//Send OSC tracker distance	
	//allways sending the nearest node
	myOSCManager::getInstance()->sendMeshTrackerDistance(nearesStringIndex, nearestDistance, minimumDistance2Interact); 

}
//--------------------------------------------------------------
void meshTrackerInteraction::draw(ofEasyCam cam, dataTracker myData){

	ofEnableAlphaBlending();
	int radius = 3;
	//-----------------------------------------------------------
	//update calcs
	nearestDistance = 0;//reset  neareest distance
	
	//TODO
	target = myData.target;							//Get tracker target
	positionTracker = ofVec3f(target.getGlobalPosition());	//Get target position

	//Find Nearest Point of the Tracker In the Mesh, always calc nearest id and distance
	FindNearestPointInMesh(positionTracker);
	
	//Set Color by Selection Status and Lerp Colors using distance to Mesh and selecction
	updateColorAnimations(positionTracker);

	//Draw Mesh
	ofPushStyle();
		//glPointSize(2);
		ofSetColor(colorfeedbackMesh);

		//Renderer matrix has beenmodified in main Draw
		ofGetCurrentRenderer()->pushMatrix();

		//Paint memories one by one "EXPERIMENT"
		for(int i=0; i< brainMemories.size();i++)
		{
			if(bexperimentmode)
			{	
				if(counterExperimentMode == i)
				//ofGetCurrentRenderer()->drawCircle(brainMemories[i].getPosNodeMemory().x, brainMemories[i].getPosNodeMemory().y, brainMemories[i].getPosNodeMemory().z, 4);
				ofSphere(brainMemories[i].getPosNodeMemory().x, brainMemories[i].getPosNodeMemory().y, brainMemories[i].getPosNodeMemory().z, 2);
			}
			else{
				//ofGetCurrentRenderer()->drawCircle(brainMemories[i].getPosNodeMemory().x, brainMemories[i].getPosNodeMemory().y, brainMemories[i].getPosNodeMemory().z, 6);
				ofSphere(brainMemories[i].getPosNodeMemory().x, brainMemories[i].getPosNodeMemory().y, brainMemories[i].getPosNodeMemory().z, 2);
				
			}
		}
		ofGetCurrentRenderer()->popMatrix();
		//Old
		//mesh.drawVertices();
		
	ofPopStyle();
	
	//Color Feedback lastvertexPlayed && colorfeedbackSelection
	ofPushStyle();
		//ofSetColor(ofColor::yellow);
		ofSetColor(colorfeedbackSelection);
		ofGetCurrentRenderer()->drawCircle(vertexSel.x, vertexSel.y, vertexSel.z, 3);
	ofPopStyle(); // end draw Color Feedback

	
	//Draw Line
	ofPushStyle();
		ofSetColor(colorfeedbackLine);
		ofGetCurrentRenderer()->drawLine(nearestVertex.x, nearestVertex.y, nearestVertex.z, positionTracker.x, positionTracker.y, positionTracker.z);

		if(bdebugInfo)
		{
			ofPushStyle();
			ofSetColor(ofColor::white);
			newmediaFontDetail.drawString(ofToString(nearestIndex), nearestVertex.x, nearestVertex.y-30);
			newmediaFontDetail.drawString(ofToString(nearestDistance), nearestVertex.x, nearestVertex.y-15);
			ofPopStyle();
		}
	ofPopStyle();
	
	//Draw Selection lastvertexPlayed && colorfeedbackSelectionPlay
	ofPushStyle();
		ofSetColor(colorfeedbackSelectionPlay);
		ofFill();

		ofGetCurrentRenderer()->drawCircle(lastvertexPlayed.x, lastvertexPlayed.y, lastvertexPlayed.z, 3);
		
	ofPopStyle(); // end draw Selection

	ofDisableAlphaBlending();

}


//--------------------------------------------------------------
void meshTrackerInteraction::keyPressed(int key){
}

//--------------------------------------------------------------
void meshTrackerInteraction::setMinimumDistance2Interact(float distance)
{
	minimumDistance2Interact = distance;
	cout << "minimumDistance2Interact = " << minimumDistance2Interact << endl;
}

//--------------------------------------------------------------
void meshTrackerInteraction::setMinimumMemories2Interact(int num)
{
	numDisplayedMemories = num;
	cout << "numDisplayedMemories = " << numDisplayedMemories << endl;
}


//---------------------------------------------------------------
void meshTrackerInteraction::updateColorAnimations(ofVec3f _position)
{
	///CALC animations Color // ALPHA ANIMATIONS
	calcAnimationsColorsAndAlphas();
	

	//-----------------------------------------------------------
	//Color Line Tracker
	if(nearestDistance < minimumDistance2Interact){
		/*
		// interpolation to RED 
		float percentcolorline = (minimumDistance2Interact-nearestDistance)/minimumDistance2Interact; 
		colorfeedbackLine.lerp( ofColor::red, percentcolorline);

		//TODO Easey debuggin colors
		colorfeedbackLine = ofColor(0,255,255);
		*/
	}
	else
	{
		//if its not near a dot
		colorfeedbackLine = ofColor(255,255,255, 0);
	}

}

//--------------------------------------------------------------
void meshTrackerInteraction::calcAnimationsColorsAndAlphas() {


	//Set transparent when goes far away from it .... > 400
	//Mesh
	colorfeedbackMeshTransparent = ofColor(255,255,255,0);
	colorfeedbackMeshSolid = ofColor(255,255,255,255);
	colorfeedbackMesh = colorfeedbackMeshTransparent;
	//LIne
	colorfeedbackLineTransparent = ofColor(255,0,0,0);
	colorfeedbackLineSolid = ofColor(255,255,0,255);
	colorfeedbackLine = ofColor(colorfeedbackLine.r,colorfeedbackLine.g,colorfeedbackLine.b,0);
	//Selection
	colorfeedbackSelectionSolid = ofColor(colorfeedbackSelection.r,colorfeedbackSelection.g,colorfeedbackSelection.b,255);
	colorfeedbackSelectionTransparent =  ofColor(colorfeedbackSelection.r,colorfeedbackSelection.g,colorfeedbackSelection.b,0);
	colorfeedbackSelection = colorfeedbackSelectionTransparent;
	//Selection Play
	colorfeedbackSelectionPlaySolid = ofColor(colorfeedbackSelectionPlay.r,colorfeedbackSelectionPlay.g,colorfeedbackSelectionPlay.b,255);
	colorfeedbackSelectionPlayTransparent = ofColor(colorfeedbackSelectionPlay.r,colorfeedbackSelectionPlay.g,colorfeedbackSelectionPlay.b,0);
	colorfeedbackSelectionPlay = colorfeedbackSelectionPlayTransparent;

	float range = 400.0;

	//
	float auxFloatCalc = nearestDistance/range;							
	if(auxFloatCalc > 1)auxFloatCalc = 1;
	if(nearestDistance < 100)auxFloatCalc = 0;							
	//
	float auxFloatCalcSelection = nearestDistance/range;				
	if(auxFloatCalcSelection > 1)auxFloatCalcSelection = 1;
	if(nearestDistance < 100)auxFloatCalcSelection = 0;
	//
	float auxFloatCalcSelectionPlay = nearestDistance/range;			
	if(auxFloatCalcSelectionPlay > 1)auxFloatCalcSelectionPlay = 1;
	if(nearestDistance < 100)auxFloatCalcSelectionPlay = 0;

	//Lerping colors
	//TODO DEBUGGIN COLORS

	colorfeedbackMesh.lerp(colorfeedbackMeshSolid, 1 - auxFloatCalc );
	colorfeedbackLine.lerp(colorfeedbackLineSolid, 1 - auxFloatCalc );
	colorfeedbackSelection.lerp(colorfeedbackSelectionSolid, 1- auxFloatCalcSelection);
	colorfeedbackSelectionPlay.lerp(colorfeedbackSelectionPlaySolid, 1- auxFloatCalcSelectionPlay);
		
}

//-----------------------------------------------------------
void meshTrackerInteraction::FindNearestPointInMesh(ofVec3f _position)
{
	// Find nearest point in mesh
	nearestDistance = 1000000;

	//TODO takeCare if no BrainMemories

	for(int i = 0; i < brainMemories.size(); i++){  
		//Skip iteration if does not fit with the actual counter for the experiemnt mode
		if(bexperimentmode)if(i!=counterExperimentMode)continue;

		//access to the pos memory
		ofVec3f cur = brainMemories[i].getPosNodeMemory();

		float distance = cur.distance(_position);//cur.squareDistance(position);
		if(distance < nearestDistance) {
			nearestDistance = distance;
			nearestVertex = cur;
			nearestIndex = i; // The nearest Index is gived by the mesh structure .... ( Check if this mantain order )
			nearesStringIndex = getNearesStringIndex(nearestIndex);
			//cout << " for i.. idString" << nearesStringIndex << endl;
		}
	}

	nearesStringIndex = getNearesStringIndex(nearestIndex);
}

//--------------------------------------------------------------
string meshTrackerInteraction::getNearesStringIndex(int idNearest){
	
	string result = "";
	
	//TODO nearest 
	if(brainMemories.size() > 0){
		result = brainMemories[idNearest].getIdStringNode();
	}else result = "String index not found";
	
	//TODO DEBUG
	//cout << "getNearesStringIndex:: String Index found in mesh = " << result << endl;

	return result;
}

//--------------------------------------------------------------
void meshTrackerInteraction::updateSelection(){

	if(myselection == waitingSel){

		//IF STARTS TO REC
		if(myOSCManager::getInstance()->getIsRecordingMemory()){

			last_nearestIndex = nearestIndex;
			last_idMemoryIdString = myOSCManager::getInstance()->getMemoryIdString();
			timeSelected = ofGetElapsedTimeMillis();//If recieve Selected Memory. timeSelected counts ellapsetime
			myselection = recondingSel;
			
			//Create a new memory and push back it into memories vector 
			brainMeshNode memory;
			memory.setIdStringNode(last_idMemoryIdString);
			memory.addNodePosition(positionTracker);
			//The path will be filled after the hole interaction

			brainMemories.push_back(memory);
			allBrainMemories.push_back(memory);
			
			cout << "START BUTTON REC MEMORY" << endl;
			cout << "RECEIVED idString=" << last_idMemoryIdString << endl;

			//save to XML the last interaction node added 
			bool bNsaved = save2XmlNewBrainNode(memory.getIdStringNode() , memory.getPosNodeMemory() );
			// at the end of the interaction save the recording path created
			memory.saveMeshPath(memory.getIdStringNode());

			//Go to REC
			myOSCManager::getInstance()->sendTrackerDataMachineStatus(false, true); //  int bplaying, int brecording)

			//Vertex and Color update
			lastvertexPlayed = nearestVertex;
			vertexSel = nearestVertex;
			colorfeedbackSelection = ofColor::red;
			colorfeedbackSelectionPlay = ofColor::yellow;

		}
		//IF STARTS TO PLAY
		//REC HAS PRIORITY OVER PLAY
		else if(myOSCManager::getInstance()->getIsPlayingMemory()){ 

			if(minimumDistance2Interact>nearestDistance)
			{
				last_nearestIndex = nearestIndex;
				last_idMemoryIdString = myOSCManager::getInstance()->getMemoryIdString();
				timeSelected = ofGetElapsedTimeMillis();//If recieve Selected Memory. timeSelected counts ellapsetime
				myselection = playingSel;
				cout << "START BUTTON PLAYING MEMORY"<< endl;
				if(bexperimentmode){
					counterExperimentMode++;
					if(counterExperimentMode>brainMemories.size()){
						counterExperimentMode = 0;
					}
				}

				//Send Go to Play
				myOSCManager::getInstance()->sendTrackerDataMachineStatus(true, false); // int bplaying, int brecording)

				//Vertex and Color update
				lastvertexPlayed = nearestVertex;
				vertexSel = nearestVertex;
				colorfeedbackSelection = ofColor::yellow;
				colorfeedbackSelectionPlay = ofColor::green;
			}
		}
		//IF NO ACTIONS GET BY OSC PURE WAINTING STATUS
		else
		{			
				//Vertex and Color update
				lastvertexPlayed = nearestVertex;
				vertexSel = nearestVertex;
				colorfeedbackSelection = ofColor::yellow;
				colorfeedbackSelectionPlay = ofColor::yellow;
		}

	}
	else if(myselection == recondingSel){

			//Check if since we selected one has pass enough time to Deselect the Memory and allow a new Selection
			bool checkifDefaultfinish = (ofGetElapsedTimeMillis() - timeSelected > time2DoneDeselection);
			checkifDefaultfinish = false; //TODO: comment/uncomment this line to use default timer, and check setup for :time2DoneDeselection
			if(!myOSCManager::getInstance()->getIsRecordingMemory()/* || checkifDefaultfinish*/) // or OSC recieveFinished listening
			{
				last_time2Select = ofGetElapsedTimeMillis();
				myselection = waitingSel;
				cout << "END BUTTON REC MEMORY"<< endl;		

				//end rec
				myOSCManager::getInstance()->sendTrackerDataMachineStatus(false, false);


				//Vertex and Color update
				//if Rec button, then change all colors and vertex to new status
				lastvertexPlayed = nearestVertex;
				colorfeedbackSelectionPlay = ofColor::yellow;

				vertexSel = nearestVertex;
				colorfeedbackSelection = ofColor::yellow;
				
			}
			else{
				//Vertex and Color update
				//if nobody change status just update nearest vertex and set color feedbaak Lower
				vertexSel = nearestVertex;
				colorfeedbackSelection = ofColor(colorfeedbackSelection.r,colorfeedbackSelection.g,colorfeedbackSelection.b,100);
			}
	}
	else if(myselection == playingSel){

		//if selected done, then status busy whyle playing memory
		
		bool checkifDefaultfinish = (ofGetElapsedTimeMillis() - timeSelected > time2DoneDeselection);
		checkifDefaultfinish = false; //TODO: comment/uncomment this line to use default timer, and check setup for :time2DoneDeselection
		if(!myOSCManager::getInstance()->getIsPlayingMemory() || checkifDefaultfinish) // or OSC recieveFinished listening
		{
			cout << "END BUTTON PLAYING MEMORY"<< endl;
			last_time2Select = ofGetElapsedTimeMillis();
			cout << "New Selection done." << endl;
			myselection = waitingSel;

			//end
			myOSCManager::getInstance()->sendTrackerDataMachineStatus(false, false);

			//Position and Color update
			//if Rec button, then change all colors and vertex to new status
			lastvertexPlayed = nearestVertex;
			colorfeedbackSelectionPlay = ofColor::yellow;

			vertexSel = nearestVertex;
			colorfeedbackSelection = ofColor::yellow;
			
		}
		else{
			//Position and Color update
			vertexSel = nearestVertex;
			colorfeedbackSelection = ofColor(colorfeedbackSelection.r,colorfeedbackSelection.g,colorfeedbackSelection.b,100);
		}
	}
	else
	{ cout << "Error Status Mode :: updateSelection" << endl; }

}

//--------------------------------------------------------------
bool meshTrackerInteraction::getInternalNewSelection(){

	bool auxSel = false;

	if(bInternalNewSelection)
	{
		auxSel = true;
		bInternalNewSelection = false;
	}
	
	return auxSel;
}


//-----------------------------------------------------------
int meshTrackerInteraction::getNearestDistance(){
	return nearestDistance;
}

//-----------------------------------------------------------
ofVec3f meshTrackerInteraction::getNearestVertex(){
	return nearestVertex;
}

//----------------------------------------------
bool meshTrackerInteraction::save2XmlNewBrainNode(string filename, ofVec3f positionNode) {
	
	//xmlBrainNodeWrite.clear();

	//Load and Write

	bool bloaded = xmlBrainNodeWrite.loadFile("./brain_nodes/AllBrainNodes.xml");
	
	//if does not exist this tag, then create it
	if(!xmlBrainNodeWrite.pushTag("BrainNodes"))
	{ 
		xmlBrainNodeWrite.addTag("BrainNodes");
		xmlBrainNodeWrite.pushTag("BrainNodes");
	}

	int numberOfSavedPoints = xmlBrainNodeWrite.getNumTags("node");
	xmlBrainNodeWrite.addTag("node");
    xmlBrainNodeWrite.pushTag("node",numberOfSavedPoints); //pusht new tag in the last position

    xmlBrainNodeWrite.addValue("filename", filename);
	xmlBrainNodeWrite.addValue("posX", positionNode.x);
	xmlBrainNodeWrite.addValue("posY", positionNode.y);
	xmlBrainNodeWrite.addValue("posZ", positionNode.z);
	
	bool saved = false;
	std::string fname = std::string("./brain_nodes/") + std::string("AllBrainNodes.xml");
	saved = xmlBrainNodeWrite.saveFile(fname);

	return saved;
}


//----------------------------------------------
bool meshTrackerInteraction::loadBrainNodedataXML(int lastPos) {

	//Load and Read
	bool bloaded = xmlBrainNodeWrite.loadFile("./brain_nodes/AllBrainNodes.xml");
	if(!bloaded){
		cout << "save2XmlNewBrainNode::Error AllBrainNodes.xml bad loaded or not exist, then create Xml" << endl;
		bool saved = false;
		std::string fname = std::string("./brain_nodes/") + std::string("AllBrainNodes.xml");
		saved = xmlBrainNodeWrite.saveFile(fname);
		bloaded = xmlBrainNodeWrite.loadFile("AllBrainNodes.xml");
	}
	//if does not exist this tag, then create it, anyway that push the tag
	if(!xmlBrainNodeWrite.pushTag("BrainNodes"))
	{ 
		xmlBrainNodeWrite.addTag("BrainNodes");
		bool auxResPushTag = xmlBrainNodeWrite.pushTag("BrainNodes");
		cout << "save2XmlNewBrainNode::AllBrainNodes.xml BrainNodes is empty and last push tag is " << (int)auxResPushTag << endl;
	}

	int numberOfSavedPoints = xmlBrainNodeWrite.getNumTags("node");

	int counterReadMemories = lastPos;

	for(int i = 0; i < numberOfSavedPoints ; i++){
		bool bloadedNode = xmlBrainNodeWrite.pushTag("node",i); //pusht new tag in the first node
		cout << "bloadedNode i=" << i << "bool =" << (int)bloadedNode << endl;
		
		brainMeshNode auxbrainNode;
		auxbrainNode.setIdStringNode(xmlBrainNodeWrite.getValue("filename", ""));
	
		ofVec3f nodePos;
		nodePos.x = xmlBrainNodeWrite.getValue("posX", 0);
		nodePos.y = xmlBrainNodeWrite.getValue("posY", 0);
		nodePos.z = xmlBrainNodeWrite.getValue("posZ", 0);
		auxbrainNode.addNodePosition(nodePos);
		
		counterReadMemories++;

		//Fill last brain node vector
		if(counterReadMemories > numberOfSavedPoints - numDisplayedMemories){
			brainMemories.push_back(auxbrainNode);
			cout << "Loading last values Brain Memories num = " << counterReadMemories << endl;
		}
		//Fill All brain node vector
		allBrainMemories.push_back(auxbrainNode);
		

		xmlBrainNodeWrite.popTag();
	}

	return bloaded;
}


//----------------------------------------------
int meshTrackerInteraction::loadExtraBrainNodedataXML() {
	
	//cleaning in case it has been used before
	xmlBrainNodeWrite.clear();

	//Load and Read
	bool bloaded = xmlBrainNodeWrite.loadFile("./brain_nodes/extraBrainNodes.xml");
	if(!bloaded){
		cout << "save2XmlNewBrainNode::Error extraBrainNodes.xml bad loaded or not exist, then create Xml" << endl;
		bool saved = false;
		std::string fname = std::string("./brain_nodes/") + std::string("extraBrainNodes.xml");
		saved = xmlBrainNodeWrite.saveFile(fname);
		bloaded = xmlBrainNodeWrite.loadFile("extraBrainNodes.xml");
	}
	//if does not exist this tag, then create it, anyway that push the tag
	if(!xmlBrainNodeWrite.pushTag("BrainNodes"))
	{ 
		xmlBrainNodeWrite.addTag("BrainNodes");
		bool auxResPushTag = xmlBrainNodeWrite.pushTag("BrainNodes");
		cout << "save2XmlNewBrainNode::extraBrainNodes.xml BrainNodes is empty and last push tag is " << (int)auxResPushTag << endl;
	}

	int numberOfSavedPoints = xmlBrainNodeWrite.getNumTags("node");

	int counterReadMemories = 0;

	for(int i = 0; i < numberOfSavedPoints ; i++){
		bool bloadedNode = xmlBrainNodeWrite.pushTag("node",i); //pusht new tag in the first node
		cout << "bloadedNode i=" << i << "bool =" << (int)bloadedNode << endl;
		
		brainMeshNode auxbrainNode;
		auxbrainNode.setIdStringNode(xmlBrainNodeWrite.getValue("filename", ""));
	
		ofVec3f nodePos;
		nodePos.x = xmlBrainNodeWrite.getValue("posX", 0);
		nodePos.y = xmlBrainNodeWrite.getValue("posY", 0);
		nodePos.z = xmlBrainNodeWrite.getValue("posZ", 0);
		auxbrainNode.addNodePosition(nodePos);
		
		counterReadMemories++;

		//Fill last brain node vector
		if(counterReadMemories > numberOfSavedPoints - numDisplayedMemories){
			brainMemories.push_back(auxbrainNode);
			cout << "Loading last values Brain Memories num = " << counterReadMemories << endl;
		}
		//Fill All brain node vector
		allBrainMemories.push_back(auxbrainNode);
		

		xmlBrainNodeWrite.popTag();
	}

	return counterReadMemories;
}

