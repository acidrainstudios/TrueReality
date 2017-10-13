/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2017 Acid Rain Studios LLC
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
* Author: Maxim Serebrennik
*/

#pragma once

#include "Export.h"

#include <trBase/SmrtClass.h>
#include <trBase/UniqueId.h>
#include <trUtil/RefStr.h>

namespace trBase
{

    /**
    * This is a Base class that carries the Class name and Unique ID of all the derived classes.
    */
    class TR_BASE_EXPORT Base : public trBase::SmrtClass
    {
    public:

        typedef trBase::SmrtClass BaseClass;            /// Adds an easy and swappable access to the base class

        const static trUtil::RefStr CLASS_TYPE;         /// Holds the class type name for efficient comparisons

        /**
        * ctor
        */
        Base(const std::string name = CLASS_TYPE);

        /**
        * Returns the class type
        */
        virtual const std::string& GetType() const override = 0;

        /**
        * Sets this instances name
        */
        virtual void SetName(const std::string& name);

        /**
        * Returns this instances name
        */
        virtual const std::string& GetName();

        /**
        * Overwrites the default internal UUID with the passed in one. 
        * This should be done very carefully.
        */
        virtual void SetUUID(const trBase::UniqueId& id);

        /**
        * Returns the instances Universally Unique ID
        */
        virtual const trBase::UniqueId& GetUUID(void);

    protected:

        /** Base destructor. Note, that it is protected so that classes cannot
        be deleted other than by being dereferenced and the reference
        count being zero (see trBase::SmrtClass), preventing the deletion
        of nodes which are still in use. This also means that
        Nodes cannot be created on stack i.e Node node will not compile,
        forcing all nodes to be created on the heap i.e Node* node
        = new Node().*/
        ~Base();

    private:
        
        trUtil::RefStr mName;
        trBase::UniqueId mId;

    };

}

