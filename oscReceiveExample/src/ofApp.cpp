#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    receiver.setup(PORT);
    remoteMouseX = 0;
    remoteMouseY = 0;
    mouseButtonState = "";
    ofBackground(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update(){
    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        if(m.getAddress() == "/mouse/position"){
            remoteMouseX = m.getArgAsInt32(0);
            remoteMouseY = m.getArgAsInt32(1);
        }
        else if(m.getAddress() == "/mouse/button"){
            mouseButtonState = m.getArgAsString(0);
        }
        dumpOSC(m);
    }
}
void ofApp::dumpOSC(ofxOscMessage m){
    string msg_string;
    msg_string = m.getAddress();
    for(int i = 0; i < m.getNumArgs(); i++){
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32) msg_string += ofToString(m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT) msg_string += ofToString(m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING) msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    int radius = 0;
    if(mouseButtonState == "down"){
        radius = 20;
        ofSetColor(255, 127, 0);
    }
    else{
        radius = 10;
        ofSetColor(0, 127, 255);
    }
    ofDrawCircle(remoteMouseX, remoteMouseY, radius);
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
