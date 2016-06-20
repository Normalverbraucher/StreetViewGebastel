#pragma once

#include "ofMain.h"
#include "ofxStreetView.h"
#include "ofxPostProcessing.h"
#include "ofxFirstPersonCamera.h"

#define NSTREETVIEW 6
#define NMESH 6

#pragma once

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(ofMouseEventArgs &mouse);
	void mouseReleased(int x, int y, int button);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);

	//ofEasyCam cam;
	ofxFirstPersonCamera cam;

	ofxStreetView streetview[NSTREETVIEW];

	ofVboMesh mesh[NMESH];
	
	ofShader shader;

	ofxPostProcessing post;

};
