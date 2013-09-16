#pragma once

#include <memory>
#include "VLCMovie.h"

class ofxVLCVideoPlayer: public ofBaseVideoPlayer
{
    std::tr1::shared_ptr<VLCMovie> vlcMovieInstance;
    ofTexture dummyTexture;
	ofImage dummyImage;
public:
    
    ofxVLCVideoPlayer();
    ~ofxVLCVideoPlayer();
    
    bool loadMovieURL(string name);
    bool loadMovie(string name);
    void close();
    void update();
    
    void play();
    void pause();
    void stop();
    
    bool isFrameNew();
    unsigned char * getPixels(){return NULL;}
    ofPixelsRef	getPixelsRef(){ofPixels p; return p;}

    ofTexture *	getTexture(){return NULL;}
    
    ofTexture &getTextureReference();
	ofImage &getThumbnailImage();
    
    float getWidth();
    float getHeight();

    bool isPaused(){return false;}
    bool isLoaded();
    bool isPlaying();

    bool setPixelFormat(ofPixelFormat pixelFormat){return false;}
    ofPixelFormat getPixelFormat(){return OF_PIXELS_RGB;}
    
    void draw(float x, float y, float w, float h);
    void draw(float x, float y);

    bool getIsMovieDone();
    float getFPS();
    float getDuration();
    int getTotalNumFrames();
    void setLoop(bool loop);

    float getPosition();
    void setPosition(float pct);
    
	int getTimeMillis();
	void setTimeMillis(int ms);

    void setFrame(int frame);
    int getCurrentFrame();
    
    void setVolume(int volume);
    void toggleMute();
};

