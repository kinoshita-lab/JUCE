/*
  ==============================================================================

   This file is part of the JUCE library - "Jules' Utility Class Extensions"
   Copyright 2004-7 by Raw Material Software ltd.

  ------------------------------------------------------------------------------

   JUCE can be redistributed and/or modified under the terms of the
   GNU General Public License, as published by the Free Software Foundation;
   either version 2 of the License, or (at your option) any later version.

   JUCE is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with JUCE; if not, visit www.gnu.org/licenses or write to the
   Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA

  ------------------------------------------------------------------------------

   If you'd like to release a closed-source product which uses JUCE, commercial
   licenses are also available: visit www.rawmaterialsoftware.com/juce for
   more information.

  ==============================================================================
*/

#ifndef __JUCE_MAC_NATIVEHEADERS_JUCEHEADER__
#define __JUCE_MAC_NATIVEHEADERS_JUCEHEADER__

#include "../../../src/juce_core/basics/juce_StandardHeader.h"

#include <Cocoa/Cocoa.h>


//==============================================================================
BEGIN_JUCE_NAMESPACE

class AutoPool
{
public:
    AutoPool()      { pool = [[NSAutoreleasePool alloc] init]; }
    ~AutoPool()     { [pool release]; }

private:
    NSAutoreleasePool* pool;
};

END_JUCE_NAMESPACE

//==============================================================================
static const JUCE_NAMESPACE::String nsStringToJuce (NSString* s)
{
    return JUCE_NAMESPACE::String::fromUTF8 ((JUCE_NAMESPACE::uint8*) [s UTF8String]);
}

static NSString* juceStringToNS (const JUCE_NAMESPACE::String& s)
{
    return [NSString stringWithUTF8String: (const char*) s.toUTF8()];
}


#endif   // __JUCE_MAC_NATIVEHEADERS_JUCEHEADER__
