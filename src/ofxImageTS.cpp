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

ofTexture ofxImageTS::alterColorRGB(ofImage image, float R, float G, float B){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = R * image.getPixels()[i];
        copy[i+1] = G * image.getPixels()[i+1];
        copy[i+2] = B * image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}
ofTexture ofxImageTS::alterColorR(ofImage image,float R){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = image.getPixels()[i] * R;
        copy[i+1] = 0;
        copy[i+2] = 0;
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::alterColorG(ofImage image,float G){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = 0;
        copy[i+1] = image.getPixels()[i] * G;
        copy[i+2] = 0;
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::alterColorB(ofImage image,float B){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        copy[i] = 0;
        copy[i+1] = 0;
        copy[i+2] = image.getPixels()[i] * B;
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

ofTexture ofxImageTS::dualist(ofImage image, ofColor base, ofColor top) {
    int avg;
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        avg = (image.getPixels()[i] + image.getPixels()[i+1] + image.getPixels()[i+2])/3;
        if(avg < 128) {
            copy[i] = base.r;
            copy[i+1] = base.g;
            copy[i+2] = base.b;
        }
        else {
            copy[i] = top.r;
            copy[i+1] = top.g;
            copy[i+2] = top.b;
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

ofTexture ofxImageTS::sinusoidal(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Sin;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Sin = (sin(i) + 1)/2.0f;
        copy[i] = Sin * image.getPixels()[i];
        copy[i+1] = Sin *  image.getPixels()[i+1];
        copy[i+2] = Sin *  image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::tanR(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Tan;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Tan = tan(i);
        copy[i] = Tan * image.getPixels()[i];
        copy[i+1] = image.getPixels()[i+1];
        copy[i+2] = image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::tanG(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Tan;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Tan = tan(i);
        copy[i] = image.getPixels()[i];
        copy[i+1] = Tan * image.getPixels()[i+1];
        copy[i+2] = image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::tanB(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Tan;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Tan = tan(i);
        copy[i] =  image.getPixels()[i];
        copy[i+1] = image.getPixels()[i+1];
        copy[i+2] = Tan * image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::tanRB(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Tan;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Tan = tan(i);
        copy[i] =  Tan * image.getPixels()[i];
        copy[i+1] = image.getPixels()[i+1];
        copy[i+2] = Tan * image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::tanRG(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Tan;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Tan = tan(i);
        copy[i] = Tan * image.getPixels()[i];
        copy[i+1] = Tan * image.getPixels()[i+1];
        copy[i+2] =  image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}

ofTexture ofxImageTS::tanGB(ofImage image){
    
    ofTexture texture;
    ofPixels copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    texture.allocate(image);
    float Tan;
    for(int i = 0; i < image.getPixels().size()-3; i += 3){
        Tan = tan(i);
        copy[i] =  image.getPixels()[i];
        copy[i+1] = Tan * image.getPixels()[i+1];
        copy[i+2] = Tan * image.getPixels()[i+2];
    }
    texture.loadData(copy);
    return texture;
}
void ofxImageTS::spaceTime(ofImage image, float depth, float density, float width, float height){

    ofFbo buffer;
    buffer.begin();
    ofSetRectMode(OF_RECTMODE_CENTER);
    for(float i = 0; i < depth; i += 1/density){
        image.draw(width/2,height/2,width/i,height/i);
    }
    buffer.end();
}
void ofxImageTS::spaceTime(ofTexture texture, float depth, float density, float width, float height){
    
    ofFbo buffer;
    buffer.begin();
    ofSetRectMode(OF_RECTMODE_CENTER);
    for(float i = 0; i < depth; i += 1/density){
        texture.draw(width/2,height/2,width/i,height/i);
    }
    buffer.end();
}
void ofxImageTS::divider(ofImage image,float divW, float divH, float width, float height){
    ofFbo buffer;
    buffer.begin();
    for(int i = 0; i < divW; i++) {
        for(int j = 0; j < divH; j++) {
            image.draw((width/divW) * i,(height/divH) * j,width/divW,height/divH);
        }
    }
    buffer.end();
}
void ofxImageTS::divider(ofTexture texture,float divW, float divH, float width, float height){
    ofFbo buffer;
    buffer.begin();
    for(int i = 0; i < divW; i++) {
        for(int j = 0; j < divH; j++) {
            texture.draw((width/divW) * i,(height/divH) * j,width/divW,height/divH);
        }
    }
    buffer.end();
}
//-------------------------------ofPixels-------------------------------------

ofPixels ofxImageTS::alterColorRGB(ofPixels pixels,int R, int G, int B){

    pixels.allocate(pixels.getWidth(), pixels.getHeight(), OF_PIXELS_RGB);
    ofPixels copy;
    copy = pixels;
    for(int i = 0; i < pixels.size()-3; i += 3){
        copy[i] = R - pixels[i];
        copy[i+1] = G - pixels[i+1];
        copy[i+2] = B - pixels[i+2];
    }
    return copy;
}

ofPixels ofxImageTS::alterColorRGB(ofPixels pixels,float R, float G, float B){
    
    pixels.allocate(pixels.getWidth(), pixels.getHeight(), OF_PIXELS_RGB);
    ofPixels copy;
    copy = pixels;
    for(int i = 0; i < pixels.size()-3; i += 3){
        copy[i] = R * pixels[i];
        copy[i+1] = G * pixels[i+1];
        copy[i+2] = B * pixels[i+2];
    }
    return copy;
}

ofPixels ofxImageTS::invertRB(ofPixels pixels){
    
    pixels.allocate(pixels.getWidth(), pixels.getHeight(), OF_PIXELS_RGBA);
    ofPixels copy;
    copy = pixels;
    for(int i = 0; i < pixels.size()-3; i += 4){
        copy[i] = pixels[i+2];
        copy[i+1] = pixels[i+1];
        copy[i+2] = pixels[i];
        copy[i+3] = pixels[i+3];
    }
    return copy;
}

void ofxImageTS::pixSaturation(ofPixels pixels, int pixelRatio, float saturation) {
    if(pixelRatio > 4 || pixelRatio < 0) {
        ofLogNotice("Pixel Ratio must be between 0 and 5");
    }
    else {
        ofPixels R,G,B, copy;
        if(pixels.getWidth() < pixels.getHeight())
            pixels.resize(640,480);
        if(pixels.getWidth() > pixels.getHeight())
            pixels.resize(480,640);
        copy.allocate(pixels.getWidth(), pixels.getHeight(), OF_PIXELS_RGB);
        copy = pixels;
        R = copy.getChannel(0);
        G = copy.getChannel(1);
        B = copy.getChannel(2);
        int camWidth = pixels.getWidth();
        int camHeight = pixels.getHeight();
        int boxWidth = pixels.getWidth()/(pow(2,pixelRatio)*10);
        int boxHeight = pixels.getHeight()/(pow(2,pixelRatio)*10);
        
        float tot = boxWidth*boxHeight;
        for (int x = 0; x < camWidth; x += boxWidth) {
            for (int y = 0; y < camHeight; y += boxHeight) {
                float Red = 0, Green = 0, Blue = 0;
                for (int k = 0; k < boxWidth; k++) {
                    for (int l = 0; l < boxHeight; l++) {
                        int index = (x + k) + (y + l) * camWidth;
                        Red += R[index];
                        Green += G[index];
                        Blue += B[index];
                    }
                    ofColor color;
                    color.set(Red/tot,Green/tot,Blue/tot);
                    color.setSaturation(saturation);
                    ofSetColor(color);
                    ofFill();
                    ofDrawRectangle(x, y, boxWidth, boxHeight);
                }
            }
        }
    }
}

void ofxImageTS::pixelate(ofPixels pixels, int pixelRatio) {
    if(pixelRatio > 4 || pixelRatio < 0) {
        ofLogNotice("Pixel Ratio must be between 0 and 5");
    }
    else {
        ofPixels R,G,B, copy;
        if(pixels.getWidth() < pixels.getHeight())
            pixels.resize(640,480);
        if(pixels.getWidth() > pixels.getHeight())
            pixels.resize(480,640);
        copy.allocate(pixels.getWidth(), pixels.getHeight(), OF_PIXELS_RGB);
        copy = pixels;
        R = copy.getChannel(0);
        G = copy.getChannel(1);
        B = copy.getChannel(2);
        int camWidth = pixels.getWidth();
        int camHeight = pixels.getHeight();
        int boxWidth = pixels.getWidth()/(pow(2,pixelRatio)*10);
        int boxHeight = pixels.getHeight()/(pow(2,pixelRatio)*10);
    
        float tot = boxWidth*boxHeight;
        for (int x = 0; x < camWidth; x += boxWidth) {
            for (int y = 0; y < camHeight; y += boxHeight) {
                float Red = 0, Green = 0, Blue = 0;
                for (int k = 0; k < boxWidth; k++) {
                    for (int l = 0; l < boxHeight; l++) {
                        int index = (x + k) + (y + l) * camWidth;
                        Red += R[index];
                        Green += G[index];
                        Blue += B[index];
                    }
                    ofSetColor(Red/tot,Green/tot,Blue/tot);
                    ofFill();
                    ofDrawRectangle(x, y, boxWidth, boxHeight);
                }
            }
        }
    }
}

void ofxImageTS::pixelate(ofPixels pixels, int pixelRatio, int X, int Y, int W, int H, int form) {
    if(pixelRatio > 4 || pixelRatio < 0) {
        ofLogNotice("Pixel Ratio must be between 0 and 5");
    }
    else {
        ofPixels R,G,B, copy;
        pixels.resize(W,H);
        copy.allocate(pixels.getWidth(), pixels.getHeight(), OF_PIXELS_RGBA);
        copy = pixels;
        R = copy.getChannel(0);
        G = copy.getChannel(1);
        B = copy.getChannel(2);
        int camWidth = pixels.getWidth();
        int camHeight = pixels.getHeight();
        int boxWidth = pixels.getWidth()/(pow(2,pixelRatio)*10);
        int boxHeight = pixels.getHeight()/(pow(2,pixelRatio)*10);
        
        float tot = boxWidth*boxHeight;
        for (int x = 0; x < camWidth; x += boxWidth) {
            for (int y = 0; y < camHeight; y += boxHeight) {
                float Red = 0, Green = 0, Blue = 0;
                for (int k = 0; k < boxWidth; k++) {
                    for (int l = 0; l < boxHeight; l++) {
                        int index = (x + k) + (y + l) * camWidth;
                        Red += R[index];
                        Green += G[index];
                        Blue += B[index];
                    }
                    ofSetColor(Red/tot,Green/tot,Blue/tot);
                    ofFill();
                    if(form == 1)
                        ofDrawRectangle(x+X, y+Y, boxWidth, boxHeight);
                    if(form == 2)
                        ofDrawBox(x+X, y+Y, boxWidth, boxHeight);
                    if(form == 3)
                        ofDrawCircle(x+X, y+Y, boxWidth, boxHeight);
                    if(form == 4)
                        ofDrawTriangle(x+X, y+Y, X+x+boxHeight, y+Y, x+X, y+Y+boxWidth);
                }
            }
        }
    }
}

void ofxImageTS::pixelateInv(ofPixels pixels, int pixelRatio, int X, int Y, int W, int H) {
    ofPixels R,G,B, Rc, Gc, Bc;
    pixels.resize(W,H);
    R = pixels.getChannel(0);
    G = pixels.getChannel(1);
    B = pixels.getChannel(2);
    Rc = R;
    Gc = G;
    Bc = B;
    int c = 0;
    for(int i = R.size()-1; i > 0; i--){
        Rc[c] = R[i];
        Gc[c] = G[i];
        Bc[c] = B[i];
        c++;
    }
    if(pixelRatio > 4 || pixelRatio < 0) {
        ofLogNotice("Pixel Ratio must be between 0 and 5");
    }
    else {
        
        int camWidth = pixels.getWidth();
        int camHeight = pixels.getHeight();
        int boxWidth = pixels.getWidth()/(pow(2,pixelRatio)*10);
        int boxHeight = pixels.getHeight()/(pow(2,pixelRatio)*10);
        
        float tot = boxWidth*boxHeight;
        for (int x = 0; x < camWidth; x += boxWidth) {
            for (int y = 0; y < camHeight; y += boxHeight) {
                float Red = 0, Green = 0, Blue = 0;
                for (int k = 0; k < boxWidth; k++) {
                    for (int l = 0; l < boxHeight; l++) {
                        int index = (x + k) + (y + l) * camWidth;
                        Red += Rc[index];
                        Green += Gc[index];
                        Blue += Bc[index];
                    }
                    ofSetColor(Red/tot,Green/tot,Blue/tot);
                    ofFill();
                    ofDrawRectangle(x+X, y+Y, boxWidth, boxHeight);
                }
            }
        }
    }
}

void ofxImageTS::pixelate(ofVideoGrabber video, int pixelRatio) {
    ofPixels R,G,B, copy;
    copy.allocate(video.getWidth(), video.getHeight(), OF_PIXELS_RGB);
    copy = video.getPixels();
    pixelate(copy,pixelRatio);
}

void ofxImageTS::pixelate(ofVideoPlayer video, int pixelRatio) {
    ofPixels R,G,B, copy;
    copy.allocate(video.getWidth(), video.getHeight(), OF_PIXELS_RGB);
    copy = video.getPixels();
    pixelate(copy,pixelRatio);
}

void ofxImageTS::pixelate(ofImage image, int pixelRatio) {
    ofPixels R,G,B, copy;
    copy.allocate(image.getWidth(), image.getHeight(), OF_PIXELS_RGB);
    copy = image.getPixels();
    pixelate(copy,pixelRatio);
}
//--------------------------------------------------------------
void ofxImageTS::setup(){

}

//--------------------------------------------------------------
void ofxImageTS::update(){

}


//--------------------------------------------------------------
void ofxImageTS::draw(ofPixels pixels,int ratio ,int x, int y, int width, int height,int form){
    pixelate(pixels,ratio,x,y,width,height,form);
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
