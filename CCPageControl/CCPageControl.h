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

#ifndef CCPageControl_h
#define CCPageControl_h

#include "cocos2d.h"

#define kPageControlEmptyDotFile "ccpagecontrol_empty_dot.png"
#define kPageControlFullDotFile "ccpagecontrol_full_dot.png"

class CCPageControl : public cocos2d::CCNode {
public:
    bool init();
    CREATE_FUNC(CCPageControl);
    ~CCPageControl();
    void setCurrentPage(int p);
    int getCurrentPage(){return currentPage;}
    void setNumberOfPages(int n);
    int getNumberOfPages(){return numberOfPages;}
    void setHidesForSinglePage(bool h);
    bool getHidesForSinglePage(){return hidesForSinglePage;}
    cocos2d::CCSize sizeForNumberOfPages(int n);
private:
    int currentPage, numberOfPages;
    bool hidesForSinglePage;
    cocos2d::CCSprite * fullDot;
    
    void updateCurrentPageDisplay();
    void updateVisibility();
};

#endif