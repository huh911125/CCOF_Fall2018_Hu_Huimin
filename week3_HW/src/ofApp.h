#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofxPanel gui;
    ofxFloatSlider radius;
    ofxFloatSlider r;
    ofxFloatSlider g;
    ofxFloatSlider b;
    ofxFloatSlider t;
    ofxFloatSlider line;
    ofxFloatSlider sinParam;
    ofxFloatSlider cosParam;
    
    float sine;
    float cose;
    
    ofSoundPlayer mySound;
    float *fftSmooth;
    int bands;
		
};
