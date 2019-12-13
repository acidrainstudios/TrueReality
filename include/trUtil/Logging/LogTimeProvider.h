/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2020 Acid Rain Studios LLC
*
* The Base of this class has been adopted from the Delta3D engine
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 3.0 of the License, or (at your option)
* any later version.
*
* This library is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
* FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more
* details.
*
* You should have received a copy of the GNU Lesser General Public License
* along with this library; if not, write to the Free Software Foundation, Inc.,
* 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*
* Class Inspired by the Delta3D Engine
* http://delta3dengine.org/
*
* @author David Guthrie
*/
#pragma once

#include <trUtil/Export.h>

#include <trUtil/DateTime.h>

#include <osg/Referenced>

/**
 * @namespace   trUtil
 *
 * @brief   .
 */
namespace trUtil::Logging
{
    /**
        * @class   LogTimeProvider
        *
        * @brief   Interface class get the time for the logger.
        *           There is probably no need to override this yourself. It is provided as a means for
        *           other parts of the system to provide the time.
        *          
        *           @note  The Log time provided does not extend osg::Referenced so that it can be used
        *                  easily as an interface on other referenced classes, but the log code assumes
        *                  that a dynamic_cast to reference will succeed.
        *
        * @sa  AsReferenced
        */
    class TR_UTIL_EXPORT LogTimeProvider
    {
    public:

        /**
            * @fn  virtual LogTimeProvider::~LogTimeProvider()
            *
            * @brief   Destructor.
            */
        virtual ~LogTimeProvider() {}

        /**
            * @fn  virtual const trUtil::DateTime& LogTimeProvider::GetDateTime() = 0;
            *
            * @brief   Gets date time.
            *
            * @return  The date time.
            */
        virtual const trUtil::DateTime& GetDateTime() = 0;

        /**
            * @fn  virtual unsigned LogTimeProvider::GetFrameNumber() = 0;
            *
            * @brief   Gets frame number.
            *
            * @return  The frame number.
            */
        virtual unsigned GetFrameNumber() = 0;

        /**
            * @fn  virtual osg::Referenced* LogTimeProvider::AsReferenced() = 0;
            *
            * @brief   Converts this object to a referenced.
            *
            * @return  Null if it fails, else a pointer to an osg::Referenced.
            */
        virtual osg::Referenced* AsReferenced() = 0;
    };
}