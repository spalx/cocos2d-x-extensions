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

#ifndef CCRange_h
#define CCRange_h

#include "cocos2d.h"

#define CCRangeMake(loc, len) CCRange((unsigned int)(loc), (unsigned int)(len))

class CCRange : public cocos2d::CCObject
{
public:
    unsigned int location;
    unsigned int length;
    
    CCRange();
    CCRange(unsigned int loc, unsigned int len);
    CCRange(const CCRange& other);
    CCRange& operator= (const CCRange& other);
    void setRange(unsigned int loc, unsigned int len);
    virtual CCObject* copyWithZone(cocos2d::CCZone* pZone);
    bool equals(const CCRange& target);
    CCRange intersectionRange(const CCRange& other);
    CCRange unionRange(const CCRange& other);
    bool containsLocation(unsigned int loc);
    unsigned int max();
    const char* description();
};

#endif