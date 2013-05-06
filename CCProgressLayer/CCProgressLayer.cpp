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

#include "CCProgressLayer.h"
#include "CCActivityIndicator.h"

USING_NS_CC;

bool CCProgressLayer::init()
{
    if (!CCLayerColor::initWithColor(ccc4(0, 0, 0, 0))) return false;
    
    showing = false;
    
    activityIndicator = CCActivityIndicator::create();
    activityIndicator->setHidesWhenStopped(true);
    addChild(activityIndicator);
    
    return true;
}

CCProgressLayer::~CCProgressLayer()
{
    
}

void CCProgressLayer::show()
{
    if (showing) return;
    showing = true;
    
    //display background with less opacity than the indicator
    setOpacity(kProgressLayerBackgroundShowOpacity);
    
    //indicator shows itself when it starts animating
    activityIndicator->startAnimating();
}

void CCProgressLayer::hide()
{
    if (!showing) return;
    showing = false;
    
    //hide everything
    setOpacity(0);
    activityIndicator->stopAnimating();
}