#include "testApp.h"

void testApp::setup(){
    
    w = ofGetScreenWidth();
    h = ofGetScreenHeight();
    
	ofSetFrameRate(30);
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    ofSetFullscreen(true);
	
	vidGrabber.setVerbose(true);
	vidGrabber.initGrabber(w,h);
    colorImg.allocate(w,h);
	grayImage.allocate(w,h);

    finder.setup("haarcascade_frontalface_default.xml");
    
    logoImg.loadImage("JOF.png");
    textImg.loadImage("jopencv1.png");
}

void testApp::update(){
	ofBackground(100,100,100);
	
    bool bNewFrame = false;
	
	vidGrabber.grabFrame();
	bNewFrame = vidGrabber.isFrameNew();
	
	if (bNewFrame){         
		colorImg.setFromPixels(vidGrabber.getPixels(), w,h);
        grayImage = colorImg;
        ofxCvGrayscaleImage img = ofxCvGrayscaleImage(grayImage);
        img.resize(w/2, h/2);
        finder.findHaarObjects(img);
	}
}

void testApp::draw(){
//	ofSetHexColor(0xffffff);
//    ofNoFill();
    
	colorImg.draw(0,0);
    
    for(int i = 0; i < finder.blobs.size(); i++) {
		ofRectangle cur = finder.blobs[i].boundingRect;
        
        int rand = ofRandom(0,5);
        int xd = cur.x*2;
        int yd = cur.y*2;
        int xoffset = cur.width*2*0.1;
        int yoffset = cur.height*2*0.1;
        int width = cur.width*2*1.2;
        int height = cur.height*2*1.2;
        
        if(rand == 1){
            joImg1.loadImage("joface0.png");
            joImg1.draw(xd-xoffset, yd-yoffset, width, height);
        }else if(rand == 2){
            joImg2.loadImage("joface1.png");
            joImg2.draw(xd-xoffset, yd-yoffset, width, height);
        }else if(rand == 3){
            joImg3.loadImage("joface2.png");
            joImg3.draw(xd-xoffset, yd-yoffset, width, height);
        }else if(rand == 4){
            joImg4.loadImage("jo6.png");
            joImg4.draw(xd-xoffset, yd-yoffset, width, height);
        }
	}
    logoImg.draw(5, 5,100,40);
    textImg.draw(125, 5, 140,20);
}

void testApp::keyPressed(int key){
//	switch (key){
//        case '1':
//            joImg1.loadImage("joface0.png");
//            break;
//		case '2':
//            joImg2.loadImage("joface1.png");
//			break;
//		case '3':
//            joImg3.loadImage("joface2.png");
//			break;
//        case '4':
//            joImg4.loadImage("jo6.png");
//			break;                     
//	}
}
