//
//  myAmeManager.cpp
//
#include "myAmeManager.h"

//----------------------------------------------
myAmeManager::myAmeManager(){

}

//----------------------------------------------
myAmeManager::~myAmeManager(){
		delete gui1; 
		delete gui2;
		delete gui3;
}

//--------------------------------------------------------------
void myAmeManager::setup()
{
	//	For final setup. Do not touch!
	
	ofEnableSmoothing();

	setup_GUI1(); 
	gui1->loadSettings("GUI/guiSettings1.xml");
	gui1->setDrawBack(true);

	setup_GUI2(); 
	gui2->loadSettings("GUI/guiSettings2.xml");
	gui2->setDrawBack(true);

	setup_GUI3(); 
	gui3->loadSettings("GUI/guiSettings3.xml");
	gui3->setDrawBack(true);//false

	//Stadistics Draw
	bStadisticsVisible = true;

	loadCameraPosition();


	//Volumetrics setup
	imageSequence.init("volumes/bruce/IM-0001-0",3,".tif", 1);	
	volWidth = imageSequence.getWidth();
    volHeight = imageSequence.getHeight();
    volDepth = imageSequence.getSequenceLength();
    cout << "setting up volume data buffer at " << volWidth << "x" << volHeight << "x" << volDepth <<"\n";
    volumeData = new unsigned char[volWidth*volHeight*volDepth];

    for(int z=0; z<volDepth; z++)
    {
        imageSequence.loadFrame(z);
        for(int x=0; x<volWidth; x++)
        {
            for(int y=0; y<volHeight; y++)
            {
                // convert from greyscale to RGBA, false color
                int i4 = ((x+volWidth*y)+z*volWidth*volHeight);
                int sample = imageSequence.getPixels()[x+y*volWidth];
        

                volumeData[i4] = sample;

            }
        }
    }

    myVolume.setup(volWidth, volHeight, volDepth, ofVec3f(1,1,1));
    myVolume.updateVolumeData(volumeData,volWidth,volHeight,volDepth,0,0,0);
    myVolume.setRenderSettings(FBOq, Zq, density, thresh);
	myVolume.setVolumeTextureFilterMode(GL_LINEAR);

	myTracker.setup();								//	Tracker
	mesh_tracker_interaction.setup();				//	Load Mesh, important to be located after Load GUI params

	//camera
	bcameraMode = true;
	
	//animation
	timeAnimation = 4000;
	animationTimer.setup(timeAnimation, false);
	//animationTimer.startTimer();
	//animationTimer.pauseTimer();
	bactionTimer = false;

	//Experiment mode
	bexperimentmode = false;

}

//--------------------------------------------------------------
void myAmeManager::update()
{
	//tracker
	myTracker.update();

	//get data
	myData.setPosition(myTracker.getPosition());
	myData.setOrientation(myTracker.getOrientation());

	//mesh is comparing with tracker and select new items
	mesh_tracker_interaction.update(myData, bexperimentmode);
	
	//update clipPlaneDepth with tracker position
	float clipDepth;
	clipDepth = myData.target.getGlobalPosition().z / 500;
	clipPlaneDepth = ofClamp(clipDepth,0.2,1.);
	myVolume.setClipDepth(clipPlaneDepth);
	//cout << "clipDepth" << clipDepth << endl;

	//update animations if they are activated
	//updateVolumeAnimations();
}

//--------------------------------------------------------------
void myAmeManager::draw()
{
	
	ofSetColor(255,255,255,255);
    cam.begin();

	ofPushMatrix();												//	save the old coordinate system  
		ofScale(1.0f, -1.0f);										//	flip the y axis vertically, so that it points upward  
		myVolume.drawVolume(0,0,0, ofGetHeight(), 0);				//	draw Volume
		mesh_tracker_interaction.draw(cam, myData);					//	draw mesh

		ofPushView();
			myData.draw();												//	draw tracker
			ofSetupScreenPerspective(ofGetWidth(), ofGetHeight(),OF_ORIENTATION_DEFAULT,true,50,0,1000);
		ofPopView();
	ofPopMatrix();												//	restore the previous coordinate system  
	
	cam.end();

	if(bStadisticsVisible)
	{
		myTracker.draw();
		//logTracker::getInstance()->draw(1000, 30);
	}
	
}

//--------------------------------------------------------------
void myAmeManager::keyPressed(int key ){
    switch(key)
    {
	case 'h':
		gui1->toggleVisible(); 
		gui2->toggleVisible(); 
		gui3->toggleVisible(); 
		bStadisticsVisible = !bStadisticsVisible;
        break;
	case 's':
		gui1->saveSettings("GUI/guiSettings1.xml"); 
		gui2->saveSettings("GUI/guiSettings2.xml"); 
		gui3->saveSettings("GUI/guiSettings3.xml"); 

		saveCameraPosition();
		printf("camera matrix saved\n");
		break;
	case 'l':
		loadCameraPosition();
		gui1->loadSettings("GUI/guiSettings1.xml");
		gui2->loadSettings("GUI/guiSettings2.xml");
		gui3->loadSettings("GUI/guiSettings3.xml");
		break;
	case 'f':
		ofSetWindowPosition(0, 0);
		ofSetVerticalSync(false);
		//ofSetFullscreen(false);
		break;
	case 'F':
		ofSetWindowPosition(windowXpos, 0);
		ofSetVerticalSync(true);
		ofSetFullscreen(true);
		break;
    case OF_KEY_UP:
        if(bcameraMode)cam.getTarget().boom(-5);
		else {
			cam.tilt(1);
		}
        break;
    case OF_KEY_DOWN:
        if(bcameraMode)cam.getTarget().boom(5);
		else {
			cam.tilt(-1);
		}
        break;
    case OF_KEY_LEFT:
        if(bcameraMode)cam.getTarget().truck(-5);
		else {
			cam.pan(1);
		}
        break;
    case OF_KEY_RIGHT:
        if(bcameraMode)cam.getTarget().truck(5);
		else {
			cam.pan(-1);
		}
        break;
	case 'M':
		bcameraMode = !bcameraMode;
		break;
	case OF_KEY_RETURN:
		//sequence of movements animated with timer
		animationTimer.reset();
		//animationTimer.setup(1000, false);
		animationTimer.startTimer();
		bactionTimer = true;
		//animationTimer.resumeTimer();
		//Save clip position
		last_clipPlaneDepth = clipPlaneDepth;
		break;
	}
		
}
//--------------------------------------------------------------
void myAmeManager::keyReleased(int key ){
	if(key == 'L')
	{
		myTracker.bUseLog = !myTracker.bUseLog;
		cout << "LOG Status = " << (int)myTracker.bUseLog << endl;
        gui2->setDrawWidgetPadding(myTracker.bUseLog); 
	}
}

//--------------------------------------------------------------
void myAmeManager::updateVolumeAnimations()
{
	/*
	// Update Volume if it's ask to play a memory
	//TODO: now just key return moment
	banimationTimer_INI = mesh_tracker_interaction.getInternalNewSelection();
	banimationTimer_STOP = mesh_tracker_interaction.getInternalStopSelection();
	
	//Activation timer and type of animation for the NEW selecion
	if(last_banimationTimer_INI!= banimationTimer_INI && banimationTimer_INI == true){
		cout << "Animation START!! " << endl;	
		bactionTimer = true;
		//Timer
		animationTimer.reset();
		animationTimer.startTimer();
		//Mem last position
		last_clipPlaneDepth = clipPlaneDepth;
		//type of animation
		bUpAnimation = true;
	}
	//save last action
	last_banimationTimer_INI = banimationTimer_INI;

	//Activation timer for STOP animation
	if(last_banimationTimer_STOP!= banimationTimer_STOP && banimationTimer_STOP == true){
		cout << "Animation start STOP selection!! " << endl;	
		bactionTimer = true;
		//Timer
		animationTimer.reset();
		animationTimer.startTimer();
		//Mem last position
		last_clipPlaneDepth = clipPlaneDepth;
		//type of animation
		bUpAnimation = false;
	}
	//save last action
	last_banimationTimer_STOP = banimationTimer_STOP;


	if(bactionTimer)
	{
		if(animationTimer.isTimerFinished()){
			bactionTimer = false;
			animationTimer.pauseTimer();
		}
		else{
			float auxMapTimer;
			//update timer
			if(bUpAnimation){
				auxMapTimer = ofMap(animationTimer.getTimeLeftInMillis(),timeAnimation,0,clipPlaneDepth,1);
			}
			else{
				auxMapTimer = ofMap(animationTimer.getTimeLeftInMillis(),timeAnimation,0,1,clipPlaneDepth);
			}
			//cout << "Timer = " << animationTimer.getTimeLeftInMillis() << endl;
			//cout << "Animation Timer = " << auxMapTimer << endl;

			//animation with timers
			if(animationTimer.getTimeLeftInMillis() > 0 && auxMapTimer>0){
				float animationClipDepth = ofxEasingFunc::Cubic::easeInOut(auxMapTimer);
				myVolume.setClipDepth(animationClipDepth);
			}
		}
	}

	//*/
}

//--------------------------------------------------------------
void myAmeManager::saveCameraPosition()
{
	posMat = cam.getTarget().getGlobalTransformMatrix();
	ofxXmlSettings *XML = new ofxXmlSettings("GUI/otherSettings.xml");
    XML->setValue("posMat_00", posMat(0,0), 0); XML->setValue("posMat_01", posMat(0,1), 0); XML->setValue("posMat_02", posMat(0,2), 0); XML->setValue("posMat_03", posMat(0,3), 0);
    XML->setValue("posMat_10", posMat(1,0), 0); XML->setValue("posMat_11", posMat(1,1), 0); XML->setValue("posMat_12", posMat(1,2), 0); XML->setValue("posMat_13", posMat(1,3), 0);
    XML->setValue("posMat_20", posMat(2,0), 0); XML->setValue("posMat_21", posMat(2,1), 0); XML->setValue("posMat_22", posMat(2,2), 0); XML->setValue("posMat_23", posMat(2,3), 0);
    XML->setValue("posMat_30", posMat(3,0), 0); XML->setValue("posMat_31", posMat(3,1), 0); XML->setValue("posMat_32", posMat(3,2), 0); XML->setValue("posMat_33", posMat(3,3), 0);
	XML->setValue("distance", cam.getDistance(), 0);
	XML->saveFile("GUI/otherSettings.xml");
    delete XML;
}

//--------------------------------------------------------------
void myAmeManager::loadCameraPosition()
{
	message = "loading mySettings.xml";
	if( XML.loadFile("GUI/otherSettings.xml") ){
		message = "otherSettings.xml loaded!";
	}else{
		message = "unable to load mySettings.xml check data/ folder";
	}
	posMat(0,0)= XML.getValue("posMat_00",0.0, 0); posMat(0,1)= XML.getValue("posMat_01",0.0, 0); posMat(0,2)= XML.getValue("posMat_02",0.0, 0); posMat(0,3)= XML.getValue("posMat_03",0.0, 0);
	posMat(1,0)= XML.getValue("posMat_10",0.0, 0); posMat(1,1)= XML.getValue("posMat_11",0.0, 0); posMat(1,2)= XML.getValue("posMat_12",0.0, 0); posMat(1,3)= XML.getValue("posMat_13",0.0, 0);
	posMat(2,0)= XML.getValue("posMat_20",0.0, 0); posMat(2,1)= XML.getValue("posMat_21",0.0, 0); posMat(2,2)= XML.getValue("posMat_22",0.0, 0); posMat(2,3)= XML.getValue("posMat_23",0.0, 0);
	posMat(3,0)= XML.getValue("posMat_30",0.0, 0); posMat(3,1)= XML.getValue("posMat_31",0.0, 0); posMat(3,2)= XML.getValue("posMat_32",0.0, 0); posMat(3,3)= XML.getValue("posMat_33",0.0, 0);
	cam.setDistance(XML.getValue("distance",0.0, 0));
	cam.getTarget().setTransformMatrix(posMat);
	
}

//--------------------------------------------------------------
void myAmeManager::guiEvent(ofxUIEventArgs &e)
{
	string name = e.widget->getName(); 
	int kind = e.widget->getKind(); 
	cout << "GUI:: got event from: " << name << endl; 	

	if(name == "BGR"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		backgroundColor.r = slider->getScaledValue(); 
		ofBackground(backgroundColor);
	}
	else if(name == "BGG"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		backgroundColor.g = slider->getScaledValue();
		ofBackground(backgroundColor);
	}
	
	else if(name == "BGB"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		backgroundColor.b = slider->getScaledValue(); 	
		ofBackground(backgroundColor);
	}
	else if(name == "RM"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_mean[0] = slider->getScaledValue(); 	
		myVolume.setRGBA_mean(RGBA_mean);
	}
	else if(name == "GM"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_mean[1] = slider->getScaledValue(); 	
		myVolume.setRGBA_mean(RGBA_mean);
	}
	else if(name == "BM"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_mean[2] = slider->getScaledValue(); 	
		myVolume.setRGBA_mean(RGBA_mean);
	}
	else if(name == "AM"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_mean[3] = slider->getScaledValue(); 	
		myVolume.setRGBA_mean(RGBA_mean);
	}
	else if(name == "RV"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_var[0] = slider->getScaledValue(); 	
		myVolume.setRGBA_var(RGBA_var);
	}
	else if(name == "GV"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_var[1] = slider->getScaledValue(); 	
		myVolume.setRGBA_var(RGBA_var);
	}
	else if(name == "BV"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_var[2] = slider->getScaledValue(); 	
		myVolume.setRGBA_var(RGBA_var);
	}
	else if(name == "AV"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA_var[3] = slider->getScaledValue(); 	
		myVolume.setRGBA_var(RGBA_var);
	}
	else if(name == "R"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA[0] = slider->getScaledValue(); 	
		myVolume.setRGBA(RGBA);
	}
	else if(name == "G"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA[1] = slider->getScaledValue(); 	
		myVolume.setRGBA(RGBA);
	}
	else if(name == "B"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA[2] = slider->getScaledValue(); 	
		myVolume.setRGBA(RGBA);
	}
	else if(name == "A"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		RGBA[3] = slider->getScaledValue(); 	
		myVolume.setRGBA(RGBA);
	}
	else if(name == "FBO quality"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "FBO quality " << slider->getScaledValue() << endl; 
		FBOq = slider->getScaledValue();
		myVolume.setXyQuality(FBOq);
	}
	else if(name == "Z quality"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Z quality " << slider->getScaledValue() << endl; 
		Zq = slider->getScaledValue();
		myVolume.setZQuality(Zq);
	}
	else if(name == "Threshold"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Threshold " << slider->getScaledValue() << endl; 
		thresh = slider->getScaledValue();
		myVolume.setThreshold(thresh);
	}
	else if(name == "Density"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Density " << slider->getScaledValue() << endl; 
		density = slider->getScaledValue();
		myVolume.setDensity(density);
	}
	else if(name == "Dithering"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Dithering " << slider->getScaledValue() << endl; 
		dithering = slider->getScaledValue();
		myVolume.setDithering(dithering);
	}
	else if(name == "Clip depth"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Cut Plane Depth " << slider->getScaledValue() << endl; 
		clipPlaneDepth = slider->getScaledValue();
		myVolume.setClipDepth(clipPlaneDepth);
	}
	else if(name == "Elevation clip angle"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Elevation " << slider->getScaledValue() << endl; 
		elevation = slider->getValue();
		myVolume.setElevation(elevation);
	}
	else if(name == "Azimuth clip angle"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Azimuth " << slider->getScaledValue() << endl; 
		azimuth = slider->getValue();
		myVolume.setAzimuth(azimuth);
	}
	else if(name == "linearFilter"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		linearFilter = toggle->getValue(); 
		if (linearFilter){myVolume.setVolumeTextureFilterMode(GL_LINEAR);} else {myVolume.setVolumeTextureFilterMode(GL_NEAREST);};
	}
	else if(name == "tilt"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		tilt = slider->getScaledValue();
		myData.setTilt(tilt);
	}
	else if(name == "pan"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		pan = slider->getScaledValue();
		myData.setPan(pan);
	}
	else if(name == "roll"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		roll = slider->getScaledValue();
		myData.setRoll(roll);
	}
	else if(name == "angle"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		angle = slider->getScaledValue();
		myData.setAngle(angle);
	}
	else if(name == "scale"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		scale = slider->getScaledValue();
		myData.setScale(scale);
	}
	else if(name == "log"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		myTracker.bUseLog = toggle->getValue();
	}
	else if(name == "Minimum Interaction Distance"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Minimum Interaction Distance" << slider->getScaledValue() << endl; 
		float auxDistance = slider->getScaledValue();
		mesh_tracker_interaction.setMinimumDistance2Interact(auxDistance);
	}
	else if(name == "Number of memories"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Number of memories" << slider->getScaledValue() << endl; 
		int numMemories = slider->getScaledValue();
		mesh_tracker_interaction.setMinimumMemories2Interact(numMemories);
	}
	else if(name == "Close Head Timer"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Change time Animation " << slider->getScaledValue() << endl; 
		timeAnimation = slider->getScaledValue();

	}
	else if(e.widget->getName() == "set SECOND SCREEN POS"){
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget;
		if(toggle->getValue()){
			ofSetWindowPosition(windowXpos, 0);
		}else ofSetWindowPosition(0, 0);
	}
	else if(e.widget->getName() == "2nd WINDOWS POSITION"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		//cout << "Change time Animation " << slider->getScaledValue() << endl; 
		windowXpos = (int)slider->getScaledValue();
	}
	else if(name == "Experiment mode")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		cout << "Experiment mode: " << toggle->getValue() << endl;
		bexperimentmode = toggle->getValue();
	}
	else if(name == "Auto log")
	{
		ofxUIToggle *toggle = (ofxUIToggle *) e.widget; 
		cout << "Auto log: " << toggle->getValue() << endl;
		myTracker.bUseAutoLog = toggle->getValue();
	}
	else if(name == "Log Threshold"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Log Threshold" << slider->getScaledValue() << endl; 
		myTracker.thresh = slider->getScaledValue();
	}
	else if(name == "Low Pass"){
		ofxUISlider *slider = (ofxUISlider *) e.widget; 
		cout << "Low Pass" << slider->getScaledValue() << endl; 
		float lowPassFromGui = slider->getScaledValue();
		statsTrackerPos.setLowPass(lowPassFromGui);
	}
	ofEnableSmoothing();
}

//-----"VOLUMETRICS GFX"----------------------------------------
void myAmeManager::setup_GUI1()
{	
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 

	
	gui1 = new ofxUICanvas(ofGetWidth()-length - 30, 0, length+xInit, ofGetHeight());  
	gui1->addWidgetDown(new ofxUILabel("VOLUMETRICS GFX", OFX_UI_FONT_MEDIUM)); 

	gui1->addSlider("FBO quality", 0.0, 1.0, FBOq, length-xInit, dim);
	gui1->addSlider("Z quality", 0.0, 2.0, Zq, length-xInit, dim);
	gui1->addSlider("Threshold", 0.0, 1.0, thresh, length-xInit, dim);
	gui1->addSlider("Density", 0.0, 1.0, density, length-xInit, dim);
	gui1->addSlider("Dithering", 0.0, 1.0, dithering, length-xInit, dim);
	gui1->addSlider("Clip depth", -1.0, 1.0, clipPlaneDepth, length-xInit, dim);
	gui1->addSlider("Elevation clip angle", -1.0, 1.0, elevation, length-xInit, dim);
	gui1->addSlider("Azimuth clip angle", -1.0, 1.0, azimuth, length-xInit, dim);
	gui1->addWidgetDown(new ofxUIToggle( dim, dim, false, "linearFilter"));
	
	gui1->addWidgetDown(new ofxUILabel("COLOR MEAN CONTROL", OFX_UI_FONT_MEDIUM));     
	gui1->addSlider("RM", 0.0, 1.0, RGBA_mean[0], 50, dim);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
	gui1->addSlider("GM", 0.0, 1.0, RGBA_mean[1], 50, dim);
	gui1->addSlider("BM", 0.0, 1.0, RGBA_mean[2], 50, dim);
	gui1->addSlider("AM", 0.0, 1.0, RGBA_mean[3], 50, dim);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);	

	gui1->addWidgetDown(new ofxUILabel("COLOR VARIANCE CONTROL", OFX_UI_FONT_MEDIUM));     
	gui1->addSlider("RV", 0.0, 1.0, RGBA_var[0], 50, dim);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
	gui1->addSlider("GV", 0.0, 1.0, RGBA_var[1], 50, dim);
	gui1->addSlider("BV", 0.0, 1.0, RGBA_var[2], 50, dim);
	gui1->addSlider("AV", 0.0, 1.0, RGBA_var[3], 50, dim);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

	gui1->addWidgetDown(new ofxUILabel("RGBAValue", OFX_UI_FONT_MEDIUM));     
	gui1->addSlider("R", 0.0, 1.0, RGBA[0], 50, dim);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
	gui1->addSlider("G", 0.0, 1.0, RGBA[1], 50, dim);
	gui1->addSlider("B", 0.0, 1.0, RGBA[2], 50, dim);
	gui1->addSlider("A", 0.0, 1.0, RGBA[3], 50, dim);
	gui1->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

	ofAddListener(gui1->newGUIEvent,this,&myAmeManager::guiEvent);
}

//-----"A-Me/LOG TRACKER"------------------------------------------
void myAmeManager::setup_GUI2()
{	
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 
	
	gui2 = new ofxUICanvas(0, 0, length+xInit, ofGetHeight()); 

	gui2->addWidgetDown(new ofxUILabel("A-Me/LOG TRACKER", OFX_UI_FONT_LARGE)); 
	
	gui2->addSpacer(length-xInit, 1);
	//TODO: use Buttons with keys at same time.. baad idea if buttons are no well syncronized with keys
	//gui2->addToggle("log", myTracker.bUseLog, dim, dim);
	gui2->addToggle("Experiment mode", false, dim, dim);
	gui2->addToggle("Auto log", false, dim, dim);
	gui2->addSlider("Log Threshold", 0.0001, 1., 0.08, length-xInit, dim);
	gui2->addSlider("Low Pass", -1., 1., -0.88, length-xInit, dim);
    gui2->addWidgetDown(new ofxUILabel("PLAY / RECORD", OFX_UI_FONT_MEDIUM)); 
	gui2->addWidgetDown(new ofxUILabel("Press 'L' to Activate/Deactivate LOG services", OFX_UI_FONT_SMALL)); 
	gui2->addWidgetDown(new ofxUILabel("Press 'R' to read, 'T' to stop reading, 'E' to read again, 'S' to write, 'D' to stop writting", OFX_UI_FONT_SMALL)); 
	
    gui2->addSpacer(length, 1); 
	//gui1->addWidgetDown(new ofxUILabel("Tracker CONTROL", OFX_UI_FONT_MEDIUM)); 
	//Interaction parameters
	gui2->addSlider("Minimum Interaction Distance", 40, 400, auxDistance, length-xInit, dim);
	mesh_tracker_interaction.setMinimumDistance2Interact(auxDistance);
	
	gui2->addSpacer(length, 1); 
	gui2->addSlider("Number of memories", 15, 100, numDisplayedMemories, length-xInit, dim);
	mesh_tracker_interaction.setMinimumMemories2Interact(numDisplayedMemories);
	

	gui2->addSpacer(length-xInit, 1);

	gui2->addWidgetDown(new ofxUILabel("Press 's' to save camera position and GUI params", OFX_UI_FONT_SMALL));
	gui2->addWidgetDown(new ofxUILabel("Press 'h' to Hide GUIs", OFX_UI_FONT_SMALL)); 	

	ofAddListener(gui2->newGUIEvent,this,&myAmeManager::guiEvent);
}

//-----"A-Me/APP"----------------------------------------------
void myAmeManager::setup_GUI3()
{	
	float dim = 16; 
	float xInit = OFX_UI_GLOBAL_WIDGET_SPACING; 
    float length = 255-xInit; 

	gui3 = new ofxUICanvas(0, 500, length+xInit, ofGetHeight()); 
	gui3->addWidgetDown(new ofxUILabel("A-Me/APP", OFX_UI_FONT_LARGE)); 
	
	//Background
	gui3->addSpacer(length, 1); 
	gui3->addWidgetDown(new ofxUILabel("Window Backgound Color", OFX_UI_FONT_MEDIUM)); 
	gui3->addSlider("BGR", 0, 255, backgroundColor.r, 70, dim);
    gui3->setWidgetPosition(OFX_UI_WIDGET_POSITION_RIGHT);
    gui3->addSlider("BGG", 0, 255, backgroundColor.g, 70, dim);
	gui3->addSlider("BGB", 0, 255, backgroundColor.b, 70, dim);
	gui3->setWidgetPosition(OFX_UI_WIDGET_POSITION_DOWN);

	//Windows properties
    gui3->addSpacer(length, 1); 
	gui3->addWidgetDown(new ofxUILabel("Window Properties", OFX_UI_FONT_MEDIUM)); 
	gui3->addSlider("2nd WINDOWS POSITION", 0, 2000, windowXpos, 70, dim);
	gui3->addToggle("set SECOND SCREEN POS", false, dim, dim);

	//Camera Properties
	gui3->addSpacer(length, 1); 
	gui3->addWidgetDown(new ofxUILabel("Camera Properties", OFX_UI_FONT_MEDIUM)); 
	gui3->addSlider("tilt", 0.0, 360.0, tilt, length-xInit, dim);
	gui3->addSlider("pan", 0.0, 360.0, pan, length-xInit, dim);
	gui3->addSlider("roll", 0.0, 360.0, roll, length-xInit, dim);
	gui3->addSlider("angle", 0.0, 360.0, angle, length-xInit, dim);
	gui3->addSlider("scale", 0.0, 6.0, scale, length-xInit, dim);

    gui3->addSpacer(length-xInit, 2);
    gui3->addWidgetDown(new ofxUIFPS(OFX_UI_FONT_MEDIUM)); 

	ofAddListener(gui3->newGUIEvent,this,&myAmeManager::guiEvent);
}

//--------------------------------------------------------------
void myAmeManager::exit(){

	myTracker.stopLog();
	logTracker::getInstance()->exit();
}