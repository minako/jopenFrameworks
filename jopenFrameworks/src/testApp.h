#pragma once
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxCvHaarFinder.h"

class testApp : public ofBaseApp{
public:
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	
	ofVideoGrabber vidGrabber;
	
	ofxCvColorImage colorImg;
	ofxCvGrayscaleImage grayImage;
    
    ofxCvHaarFinder finder;
    
    ofImage joImg1, joImg2, joImg3, joImg4, logoImg, textImg;
    
    int w, h;
};

