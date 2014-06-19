#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup()
{
	ame.setup();
}

//--------------------------------------------------------------
void testApp::update()
{
	ame.update();
}

//--------------------------------------------------------------
void testApp::draw()
{
	ame.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	ame.keyPressed(key);
}
//--------------------------------------------------------------
void testApp::keyReleased(int key)
{
	ame.keyReleased(key);
}
//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y )
{

}
//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button)
{

}
//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button)
{

}
//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button)
{
	
}
//--------------------------------------------------------------
void testApp::windowResized(int w, int h)
{

}
//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg)
{

}
//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo)
{

}

//--------------------------------------------------------------
void testApp::exit()
{
	ame.exit();
}
