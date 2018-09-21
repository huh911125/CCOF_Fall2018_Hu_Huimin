#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(50);
    ofSetBackgroundAuto(false);
    counter = 0;
    pct = 0;
    gui.setup();
    gui.add(radius.setup("radius", 140, 10, 300));

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float radius = 500;
    float w = ofGetWindowWidth();
    float h = ofGetWindowHeight();
    pct += 0.5;
    ofSetFrameRate(20);
    
    if(counter >= 20000)
        return;
    
    ofPushMatrix();
    //    ofTranslate(ofGetMouseX(), ofGetMouseY());
    ofTranslate(ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    
    
    for(int i = 0; i<100; i++){
        cout<< i <<endl;
        
        float posX;
        posX = ofRandom(-radius, radius);
        float posY;
        posY=ofRandom(-radius, radius);
        if (ofDist(posX, posY, 0, 0) < radius){
            
            //            ofSetColor(255,10);
            //            ofDrawTriangle(10, 10, 50, 50, posX, posY);
            ofSetColor(10, 100, 100, 20);
            ofDrawTriangle(posX, posY, 1, 1, 0, 0);
            
            //          (posX, posY, 0.1);
            counter ++;
        }
    }
    
    ofPopMatrix();
    gui.draw();
    
    cout<< "for loop ends."<<endl;

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
