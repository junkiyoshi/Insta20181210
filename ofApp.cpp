#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);

	this->noise_seed = 0;
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(10);

	if (ofGetFrameNum() % 60 < 45) {
	
		this->noise_seed += ofMap(ofGetFrameNum() % 60, 0, 45, 0.03, 0);
	}
}

//--------------------------------------------------------------
void ofApp::draw() {

	int span = 120;
	int range = 100;
	for (int x = span * 0.5; x < ofGetWidth(); x += span) {

		for (int y = span * 0.5; y < ofGetHeight(); y += span) {

			ofPushMatrix();
			ofTranslate(x, y);

			ofFill();
			glm::vec2 top_point, prev_point;
			int number_of_point = 4;
			for (int i = 0; i < number_of_point; i++) {

				glm::vec2 point = glm::vec2(ofMap(ofNoise(ofRandom(10000), this->noise_seed), 0, 1, -range * 0.5, range * 0.5), ofMap(ofNoise(ofRandom(10000), this->noise_seed), 0, 1, -range * 0.5, range * 0.5));

				ofDrawCircle(point, 5);
				if (i != 0) {

					
					ofDrawLine(prev_point, point);
				}
				else {
					
					top_point = point;
				}

				prev_point = point;
			}
			ofDrawLine(top_point, prev_point);
			ofNoFill();
			ofDrawCircle(top_point, 8);
			
			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}