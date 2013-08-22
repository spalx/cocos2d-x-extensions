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

#ifndef CCSwipeGestureRecognizer_h
#define CCSwipeGestureRecognizer_h

#include "CCGestureRecognizer.h"

#define kSwipeMaxDuration 300
#define kSwipeMinDistance 60

typedef enum {
    kSwipeGestureRecognizerDirectionRight = 1 << 0,
    kSwipeGestureRecognizerDirectionLeft  = 1 << 1,
    kSwipeGestureRecognizerDirectionUp    = 1 << 2,
    kSwipeGestureRecognizerDirectionDown  = 1 << 3
} CCSwipeGestureRecognizerDirection;

//this class is used for storing information about the swipe gesture
class CCSwipe : public cocos2d::CCObject
{
public:
    bool init() {return true;}
    CREATE_FUNC(CCSwipe);
    CCSwipeGestureRecognizerDirection direction;
    cocos2d::CCPoint location;
    cocos2d::CCPoint finalLocation;
};

class CCSwipeGestureRecognizer : public CCGestureRecognizer
{
public:
    bool init();
    ~CCSwipeGestureRecognizer();
    CREATE_FUNC(CCSwipeGestureRecognizer);
    
    virtual bool ccTouchBegan(cocos2d::CCTouch * pTouch, cocos2d::CCEvent * pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch * pTouch, cocos2d::CCEvent * pEvent){};
    virtual void ccTouchEnded(cocos2d::CCTouch * pTouch, cocos2d::CCEvent * pEvent);
protected:
    CC_SYNTHESIZE(int, direction, Direction);
private:
    cocos2d::CCPoint initialPosition;
    struct cocos2d::cc_timeval startTime;
    
    bool checkSwipeDirection(cocos2d::CCPoint p1, cocos2d::CCPoint p2, int & dir);
};

#endif
