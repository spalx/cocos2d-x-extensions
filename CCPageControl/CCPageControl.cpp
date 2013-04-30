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

#include "CCPageControl.h"

USING_NS_CC;

bool CCPageControl::init()
{
    hidesForSinglePage = false;
    currentPage = 0;
    numberOfPages = 0;
    
    fullDot = CCSprite::create(kPageControlFullDotFile);
    fullDot->retain();
    
    return true;
}

CCPageControl::~CCPageControl()
{
    fullDot->release();
}

void CCPageControl::updateVisibility()
{
    if (hidesForSinglePage && numberOfPages==1) {
        this->setVisible(false);
    }
    else {
        this->setVisible(true);
    }
}

void CCPageControl::setHidesForSinglePage(bool h)
{
    hidesForSinglePage = h;
    updateVisibility();
}

void CCPageControl::updateCurrentPageDisplay()
{
    CCSize size = fullDot->getContentSize();
    fullDot->setPosition(ccp(currentPage*size.width+size.width/2,size.height/2));
    if (fullDot->getParent()==NULL) {
        addChild(fullDot,2);
    }
}

void CCPageControl::setCurrentPage(int p)
{
    if (currentPage!=p && p>=0 && p<numberOfPages) {
        currentPage = p;
        updateCurrentPageDisplay();
    }
}

void CCPageControl::setNumberOfPages(int n)
{
    if (n>=0 && n!=numberOfPages) {
        numberOfPages = n;
        removeAllChildrenWithCleanup(true);
        setContentSize(CCSizeMake(n*fullDot->getContentSize().width, fullDot->getContentSize().height));
        
        for (int i=0; i<n; i++) {
            CCSprite * sprite = CCSprite::create(kPageControlEmptyDotFile);
            CCSize size = sprite->getContentSize();
            sprite->setPosition(ccp(i*size.width+size.width/2,size.height/2));
            addChild(sprite,1);
        }
        
        updateCurrentPageDisplay();
        updateVisibility();
    }
}