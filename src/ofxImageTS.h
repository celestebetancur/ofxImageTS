#pragma once

#include "ofMain.h"

class ofxImageTS : public ofBaseApp{

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
		
    //------------------ofTexture (ofImage)-------------------
    
        ofTexture alterColorRGB(ofImage image, int R, int G, int B);
        ofTexture alterColorRGB(ofImage image, float R, float G, float B);
        ofTexture alterColorR(ofImage image,float R);
        ofTexture alterColorG(ofImage image,float G);
        ofTexture alterColorB(ofImage image,float B);
        ofTexture greyScale(ofImage image);
        ofTexture whiteBlack(ofImage image);
        ofTexture blackWhite(ofImage image);
        ofTexture invert(ofImage image);
        ofTexture invertRB(ofImage image);
        ofTexture invertRG(ofImage image);
        ofTexture invertGB(ofImage image);
        ofTexture noise(ofImage image, float mix);
        ofTexture sinusoidal(ofImage image);
        ofTexture tanR(ofImage image);
        ofTexture tanG(ofImage image);
        ofTexture tanB(ofImage image);
        ofTexture tanRB(ofImage image);
        ofTexture tanRG(ofImage image);
        ofTexture tanGB(ofImage image);
};
