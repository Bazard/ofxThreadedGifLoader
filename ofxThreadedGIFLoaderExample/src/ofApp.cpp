#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetLogLevel(OF_LOG_VERBOSE);
	ofSetVerticalSync(true);
    
    ofAddListener(ofxGifLoadedEvent::events, this, &ofApp::gifLoaded);
    loader.startThread();
    ofSetFrameRate(60);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){	
	cnt++;
	// draw the images.
	ofSetColor(255);
	for(int i = 0; i < (int)gifs.size(); ++i) {
		gifs[i].drawFrame(cnt%gifs[i].getNumFrames(), 180*i, 20);
	}	
	
	// draw the FPS
	ofRect(0,ofGetHeight()-20,30,20);

	ofSetColor(0);
	ofDrawBitmapString(ofToString(ofGetFrameRate(),0),5,ofGetHeight()-5);
}

//--------------------------------------------------------------
void ofApp::exit(){
	loader.stopThread();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' ') {
        int total = 2;
        for(int i = 0; i < total; ++i) {
            ofLogNotice() << "hi";
            loader.loadFromDisk("view" + ofToString(i) + ".gif");
        }
    } else if (key == 'd') {
        gifs.pop_back();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

//--------------------------------------------------------------
void ofApp::gifLoaded(ofxGifLoadedEvent &e){
    gifs.push_back(e.gif);
}
