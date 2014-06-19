#include "brainMeshNode.h"

//--------------------------------------------------------------
brainMeshNode::brainMeshNode(){
	//path.reserve(100);
	idStringUnic = "";
	last_brainMeshFile = "";
}

//--------------------------------------------------------------
brainMeshNode::~brainMeshNode(){
}

//--------------------------------------------------------------
void brainMeshNode::update () {

}
//--------------------------------------------------------------
void brainMeshNode::drawCircleNode(){
			
	ofSetColor(255,0,0);
	ofCircle(path[0].x, path[0].y,path[0].z, 10);
}
//--------------------------------------------------------------
void brainMeshNode::drawPathNode(){
			
		ofSetColor(0);
		
		//Create and Draw a new Mesh
		actualMesh.clear();
		actualMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);

		for(int i = 1; i < path.size(); i++){

			//find this point and the next point
			ofVec3f thisPoint = path[i-1];
			ofVec3f nextPoint = path[i];

			//get the direction from one to the next.
			//the ribbon should fan out from this direction
			ofVec3f direction = (nextPoint - thisPoint);

			//get the distance from one point to the next
			float distance = direction.length();

			//get the normalized direction. normalized vectors always have a length of one
			//and are really useful for representing directions as opposed to something with length
			ofVec3f unitDirection = direction.normalized();

			//find both directions to the left and to the right
			ofVec3f toTheLeft = unitDirection.getRotated(-90, ofVec3f(0,0,1));
			ofVec3f toTheRight = unitDirection.getRotated(90, ofVec3f(0,0,1));

			//use the map function to determine the distance.
			//the longer the distance, the narrower the line.
			//this makes it look a bit like brush strokes
			float thickness = ofMap(distance, 0, 60, 2, .3, true);

			//calculate the points to the left and to the right
			//by extending the current point in the direction of left/right by the length
			ofVec3f leftPoint = thisPoint+toTheLeft*thickness;
			ofVec3f rightPoint = thisPoint+toTheRight*thickness;

			//add these points to the triangle strip
			actualMesh.addVertex(ofVec3f(leftPoint.x, leftPoint.y, leftPoint.z));
			actualMesh.addVertex(ofVec3f(rightPoint.x, rightPoint.y, rightPoint.z));
			
		}
	
	
}

//--------------------------------------------------------------
void brainMeshNode::draw () {
	drawCircleNode();
	if(path.size())drawPathNode();
}

//GETTERS
//--------------------------------------------------------------
string brainMeshNode::getIdStringNode(){
	return idStringUnic;
}

//--------------------------------------------------------------
void brainMeshNode::setIdStringNode(string _idStringName){
	idStringUnic = _idStringName;
	cout << "Set new ID String = " << idStringUnic << "from nodeMemory x= "<< nodePosition.x << " y= " << nodePosition.y << "z= " << nodePosition.z << endl;
}

//SETTERS
//--------------------------------------------------------------
void brainMeshNode::addNodeToPath(ofVec3f point) {
	path.push_back(point);
}
//--------------------------------------------------------------
void brainMeshNode::addNodePosition(ofVec3f point){
	nodePosition = point;
}

//--------------------------------------------------------------
ofVec3f brainMeshNode::getPosNodeMemory(){
	return nodePosition;
}

//Mesh path saver

//--------------------------------------------------------------
void brainMeshNode::saveMeshPath(string _idStringName){
	//TODO Need clean?

	last_brainMeshFile = _idStringName;
	//Add all points
	std::string fname = std::string("./brain_nodes/") + last_brainMeshFile;
	cout << "actualMesh.save(fname=" << fname << endl;
	actualMesh.save(fname);
}
