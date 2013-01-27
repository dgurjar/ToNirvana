#include "testApp.h"
#include "ofxProgressBar.h"

//--------------------------------------------------------------
void testApp::setup(){
    value = 0;
    max = 8000;
    progressBar = ofxProgressBar(10, 10, 500, 20, &value, &max);
    go = true;
    
    timer.setup(10000, true);
    timer.startTimer();
    
    synthesizer.listVoices();
    synthesizer.initSynthesizer("Ralph");
}

//--------------------------------------------------------------
void testApp::update(){
    
    //you can never really get to the end from this application
    if(go && value <= max){
        value += 50;
        max += 51;
    }
    
    //Every 5 seconds encourage the user to give up his quest
    if(timer.getTimeLeftInMillis() < 5000){
        synthesizer.speakPhrase("Give up");
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    progressBar.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    synthesizer.speakPhrase("Give up");
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}