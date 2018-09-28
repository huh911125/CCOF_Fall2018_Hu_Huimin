#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    gui.setup();
    gui.add(radius.setup("radius", 200, 10, 300));
    gui.add(r.setup("R", 255, 0, 255));
    gui.add(g.setup("G", 191, 0, 255));
    gui.add(b.setup("B", 255, 0, 255));
    gui.add(t.setup("t", 26, 0, 100));
    gui.add(line.setup("line", 0, 0, 20));
    gui.add(cosParam.setup("cose", 2, 0, 300));
    gui.add(sinParam.setup("sine", 2, 0, 300));
    
    ofBackground(0);
    ofSetCircleResolution(100);
    
//    mySound.load("No Sleep.mp3");
//    mySound.load("Short Tay-K.mp3");
    mySound.load("Space.mp3");
    
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++){
        fftSmooth[i] = 0;
    }
    
    bands = 64;
    mySound.setLoop(true);
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    float *value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++){
        fftSmooth[i] *= 0.55f;
        if(fftSmooth[i]<value[i]){
            fftSmooth[i] = value[i];
        }
    }
    sine = sin(ofGetElapsedTimef() * 3) * sinParam;
    cose = cos(ofGetElapsedTimef() * 3) * cosParam;

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    gui.draw();
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    for (int i; i < bands; i++){
        
        ofSetColor(r+i, g, b, t);
        ofSetLineWidth(line);
        ofDrawCircle(sine, cose, -(fftSmooth[i]*100));
    }
    ofPopMatrix();
    
    ofPushMatrix();
    ofSetColor(r, g, b, t);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofSetColor(r+10, g+10, b+10, t);
    ofDrawCircle(sine, cose, radius);
    ofSetColor(r+20, g+20, b+20, t-3);
    ofDrawCircle(sine*2, cose*2, radius+3);
    ofSetColor(r+30, g+30, b+30, t-6);
    ofDrawCircle(sine*3, cose*3, radius+6);
    ofSetColor(r+40, g+40, b+40, t-9);
    ofDrawCircle(sine*4, cose*4, radius+9);
    ofSetColor(r+50, g+50, b+50, t-12);
    ofDrawCircle(sine*5, cose*5, radius+12);
    ofSetColor(r+60, g+60, b+60, t-15);
    ofDrawCircle(sine*6, cose*6, radius+15);
    ofPopMatrix();
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
