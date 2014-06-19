#pragma once

#include "ofMain.h"

class brainMeshNode
{
	public:
	
		brainMeshNode();
		~brainMeshNode();

		void draw();
		void update();
		
		//Getters
		string getIdStringNode();
		ofVec3f getPosNodeMemory();
		//Setters
		void setIdStringNode(string _idStringName);
		void addNodeToPath(ofVec3f point);
		void addNodePosition(ofVec3f point);

		//--------------------------------------------------------------
		void drawCircleNode();
		void drawPathNode();

		//Mesh Xml
		void saveMeshPath(string _idStringName);
	
		ofMesh actualMesh;

	private:
		string last_brainMeshFile;
	
		vector<ofVec3f> path;
		string idStringUnic;
		ofVec3f nodePosition;
};