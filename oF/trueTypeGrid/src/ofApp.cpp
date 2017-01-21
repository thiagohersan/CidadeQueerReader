#include "ofApp.h"

void ofApp::setup() {
    ofBackground(200);
    mFont.load("arial.ttf", 600, true, true, true);
    mQuad.setup(ofVec2f(0,0), ofVec2f(650,300));
    mQuad1.setup(ofVec2f(0,300), ofVec2f(650,400));

    originalPolylines = mFont.getCharacterAsPoints('Q').getOutline();
    warpedPolylines = mFont.getCharacterAsPoints('Q').getOutline();
    for(int i=0; i<originalPolylines.size(); ++i) {
        for(int j=0; j<originalPolylines[i].size(); j++) {
            originalPolylines[i][j].y += 600;
            warpedPolylines[i][j].y += 600;
        }
    }
}

void ofApp::update() {}

void ofApp::draw() {
    ofSetColor(255);
    mFont.drawString("Q", 0,600);

    ofSetColor(200, 32, 32);
    for(int i=0; i<warpedPolylines.size(); ++i) {
        for(int j=0; j<warpedPolylines[i].size(); j++) {
            ofDrawCircle(warpedPolylines[i][j], 3);
        }
    }

    mQuad.draw();
    mQuad1.draw();
}

void ofApp::mouseReleased(int x, int y, int button) {
    for(int i=0; i<originalPolylines.size(); ++i) {
        for(int j=0; j<originalPolylines[i].size(); j++) {
            warpedPolylines[i][j].set(mQuad.warpPoint(originalPolylines[i][j]));
            warpedPolylines[i][j].set(mQuad1.warpPoint(warpedPolylines[i][j]));
        }
    }
}

void ofApp::keyReleased(int key){}
void ofApp::mouseDragged(int x, int y, int button){}
void ofApp::mousePressed(int x, int y, int button){}
