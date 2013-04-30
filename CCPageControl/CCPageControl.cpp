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
    }
}