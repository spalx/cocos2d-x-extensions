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
    void setNumberOfPages(int n);
    int getCurrentPage(){return currentPage;}
    int getNumberOfPages(){return numberOfPages;}
protected:
    CC_SYNTHESIZE(bool, hidesForSinglePage, HidesForSinglePage);
private:
    int currentPage, numberOfPages;
    cocos2d::CCSprite * fullDot;
    
    void updateCurrentPageDisplay();
};

#endif