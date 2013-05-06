/****************************************************************************
Copyright (c) 2013 Artavazd Barseghyan

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef CCActivityIndicator_h
#define CCActivityIndicator_h

#include "cocos2d.h"

#define kActivityIndicatorFramesCount 12
#define kActivityIndicatorDelayBetweenFrames 0.1

class CCActivityIndicator : public cocos2d::CCSpriteBatchNode {
public:
    bool init();
    CREATE_FUNC(CCActivityIndicator);
    ~CCActivityIndicator();
    void startAnimating();
    void stopAnimating();
    bool isAnimating() {return animating;}
    
    virtual void setParent(cocos2d::CCNode*p);
    virtual void setPosition(const cocos2d::CCPoint& pos);
protected:
    CC_SYNTHESIZE(bool, hidesWhenStopped, HidesWhenStopped);
private:
    bool animating;
    cocos2d::CCArray * spriteFrames;
    cocos2d::CCSprite * indicator;
    
    void updateVisibility();
};

#endif