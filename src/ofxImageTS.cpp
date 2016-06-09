#include "ofxImageTS.h"

ofTexture ofxImageTS::alterColorRGB(ofImage image,int R, int G, int B){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = R - image.getPixels()[i];
        copy[i+1] = G - image.getPixels()[i+1];
        copy[i+2] = B - image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::greyScale(ofImage image) {
    
    int avg;
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        avg = (image.getPixels()[i] + image.getPixels()[i+1] + image.getPixels()[i+2])/3;
        copy[i] = avg;
        copy[i+1] = avg;
        copy[i+2] = avg;
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::whiteBlack(ofImage image) {
    
    int avg;
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        avg = (image.getPixels()[i] + image.getPixels()[i+1] + image.getPixels()[i+2])/3;
        if(avg >= 128) {
            copy[i] = 254;
            copy[i+1] = 254;
            copy[i+2] = 254;
        }
        else {
            copy[i] = 0;
            copy[i+1] = 0;
            copy[i+2] = 0;
        }
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::blackWhite(ofImage image) {
    
    int avg;
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        avg = (image.getPixels()[i] + image.getPixels()[i+1] + image.getPixels()[i+2])/3;
        if(avg > 128) {
            copy[i] = 0;
            copy[i+1] = 0;
            copy[i+2] = 0;
        }
        else {
            copy[i] = 254;
            copy[i+1] = 254;
            copy[i+2] = 254;
        }
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::invert(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = 255 - image.getPixels()[i];
        copy[i+1] = 255 - image.getPixels()[i+1];
        copy[i+2] = 255 - image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::invertRB(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = image.getPixels()[i+2];
        copy[i+1] = image.getPixels()[i+1];
        copy[i+2] = image.getPixels()[i];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::invertRG(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = image.getPixels()[i+1];
        copy[i+1] = image.getPixels()[i];
        copy[i+2] = image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::invertGB(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = image.getPixels()[i];
        copy[i+1] = image.getPixels()[i+2];
        copy[i+2] = image.getPixels()[i+1];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::noise(ofImage image, float mix) {
    
    float avg;
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        avg = (image.getPixels()[i] + image.getPixels()[i+1] + image.getPixels()[i+2])/3.0f;
        copy[i] = avg * (125 - avg) * mix;
        copy[i+1] = avg * (125 - avg) * mix;
        copy[i+2] = avg * (125 - avg) * mix;
    }
    texture.loadData(copy);
    return texture;
}

//--------------------------------------------------------------
void ofxImageTS::setup(){

}

//--------------------------------------------------------------
void ofxImageTS::update(){

}


//--------------------------------------------------------------
void ofxImageTS::draw(){

}

//--------------------------------------------------------------
void ofxImageTS::keyPressed(int key){

}

//--------------------------------------------------------------
void ofxImageTS::keyReleased(int key){

}

//--------------------------------------------------------------
void ofxImageTS::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofxImageTS::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxImageTS::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxImageTS::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofxImageTS::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofxImageTS::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofxImageTS::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofxImageTS::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofxImageTS::dragEvent(ofDragInfo dragInfo){ 

}
