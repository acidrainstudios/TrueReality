/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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
* @author:Erik Johnson 06/06/2006
*
* Bits is a derivation from the Bits.h file of the CADKit project, Usul:
* @author:Perry L. Miller IV
* http://cadkit.sourceforge.net/
*
* @author: Maxim Serebrennik
*/
#pragma once
#include "Export.h"

namespace trUtil
{
    /**
    * @namespace trUtil::Bits
    *
    * Contains bit-wise operation functionality which makes using bits
    * a little "bit" easier.
    */
    namespace Bits
    {

        /**
        * See if the "bits" are in "number".
        * @code
        * unsigned int accum = 3;
        * Bits::Has( accum, 1 ); //true
        * Bits::Has( accum, 7 ); //false
        * @endcode
        */
        template < class N, class B > inline bool Has(N number, B bits)
        {
            return ((number & bits) == (static_cast<N>(bits)));
        }

        /**
        * Add the "bits" to "number".
        * @code
        * unsigned int accum = 1;
        * accum = Bits::Add(accum, 7); //Has(accum, 1) and Has(accum, 7) == true
        * @endcode
        */
        template < class N, class B > inline N Add(N number, B bits)
        {
            return (number | bits);
        }

        /**
        * Remove the "bits" from "number".
        * @code
        * unsigned int accum = 3;
        * accum = Bits::Remove(accum, 2); //Has(accum,3) == false, Has(accum,1) == true
        * @endcode
        */
        template < class N, class B > inline N Remove(N number, B bits)
        {
            return ((number & bits) ? (number ^ bits) : number);
        }

        /**
        * Toggle the "bits" in "number".
        * @code
        * unsigned int accum = 3;
        * unsigned int newBits;
        * newBits = Bits::Toggle(accum, 1); //newBits = 2
        * newBits = Bits::Toggle(accum, 1); //newBits = 3
        * @endcode
        */
        template < class N, class B > inline N Toggle(N number, B bits)
        {
            return (number ^ bits);
        }
    } 
}

