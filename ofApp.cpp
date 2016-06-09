#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetVerticalSync(true);
	ofEnableDepthTest();

	//Locations
	streetview[0].setLatLon(50.9413456, 6.9561981);
	streetview[1].setLatLon(50.9413697, 6.9556407);
	streetview[2].setLatLon(50.9414882, 6.9563284);
	streetview[3].setLatLon(50.9416979, 6.956443);
	streetview[4].setLatLon(50.9416886, 6.9556653);

	for (int i = 0; i < NSTREETVIEW; i++) {
		streetview[i].setZoom(6);
	}
	
	post.init(ofGetWidth(), ofGetHeight());
	post.createPass<BloomPass>()->setEnabled(true);
	post.createPass<DofAltPass>()->setEnabled(false);
	post.createPass<GodRaysPass>()->setEnabled(true);
}

//--------------------------------------------------------------
void ofApp::update() {

	for (int i = 0; i < NSTREETVIEW; i++) {
		streetview[i].update();
	}

	/*for (int i = 0; i < NSTREETVIEW; i++) {
		for (int j = 0; j < NMESH; j++) {
			mesh[j] = streetview[i].getDethMesh();
		}
	}*/

	mesh[0] = streetview[0].getDethMesh();
	mesh[1] = streetview[1].getDethMesh();
	mesh[2] = streetview[2].getDethMesh();
	mesh[3] = streetview[3].getDethMesh();
	mesh[4] = streetview[4].getDethMesh();

	for (int i = 0; i < NMESH; i++) {
		mesh[i].setMode(OF_PRIMITIVE_POINTS);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	ofBackground(5);
	ofSetColor(ofColor::cyan);
	
	post.begin(cam);
	
	mesh[0].draw();
	
	ofPushMatrix();
		ofTranslate(2,40);
		mesh[1].draw();
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(16, -8);
		ofRotate(88);
		mesh[2].draw();
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(43, -15);
		ofRotate(185);
		mesh[3].draw();
	ofPopMatrix();

	ofPushMatrix();
		ofTranslate(35, 170);
		ofRotate(0);
		mesh[4].draw();
	ofPopMatrix();
	
	post.end();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}