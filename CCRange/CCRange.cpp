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

#include "CCRange.h"

USING_NS_CC;

CCRange::CCRange()
{
    setRange(0, 0);
}

CCRange::CCRange(unsigned int loc, unsigned int len)
{
    setRange(loc, len);
}

CCRange::CCRange(const CCRange& other)
{
    setRange(other.location, other.length);
}

CCRange& CCRange::operator= (const CCRange& other)
{
    setRange(other.location, other.length);
    return *this;
}

void CCRange::setRange(unsigned int loc, unsigned int len)
{
    location = loc;
    length = len;
}

CCObject* CCRange::copyWithZone(CCZone* pZone)
{
    CCRange* pRet = new CCRange();
    pRet->setRange(this->location, this->length);
    return pRet;
}

bool CCRange::equals(const CCRange& target)
{
    return (length==target.length && location==target.location);
}

CCRange CCRange::intersectionRange(const CCRange& other)
{
    unsigned int loc = MAX(location, other.location);
    unsigned int len = MIN(location+length-1, other.location+other.length-1)-loc+1;
	return CCRange(loc, len);
}

CCRange CCRange::unionRange(const CCRange& other)
{
    unsigned int loc = MIN(location, other.location);
    unsigned int len = MAX(location+length-1, other.location+other.length-1)-loc+1;
    return CCRange(loc, len);
}

bool CCRange::containsLocation(unsigned int loc)
{
    return (loc-location<length);
}

unsigned int CCRange::max()
{
    return (location+length);
}

const char* CCRange::description()
{
    return CCString::createWithFormat("{%u, %u}", location, length)->getCString();
}