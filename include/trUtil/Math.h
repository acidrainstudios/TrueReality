/*
 * True Reality Open Source Game and Simulation Engine
 * Copyright © 2020 Acid Rain Studios LLC
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
 * @author Maxim Serebrennik
 */

#pragma once

#include <trUtil/Export.h>

#include <osg/Math>

namespace trUtil::Math
{
    /** @brief   / pi. */
    static const double PI = osg::PI;
    /** @brief   / pi/2. */
    static const double PI_OVER_2 = osg::PI_2;
    /** @brief   / pi/4. */
    static const double PI_OVER_4 = osg::PI_4;
    /** @brief   / pi*2. */
    static const double TWO_PI = trUtil::Math::PI * 2.0;
    /** @brief   / pi*4. */
    static const double FOUR_PI = trUtil::Math::PI * 4.0;
    /** @brief   / pi^(1/2) */
    static const double SQRT_PI = 1.77245385090551602729816748334;
    /** @brief   / e. */
    static const double E = 2.7182818284590452354;
    /** @brief   / ln(2) */
    static const double LOG_OF_2 = osg::LN_2;
    /** @brief   / 1/ln(2) */
    static const double INV_LOG_OF_2 = osg::INVLN_2;
    /** @brief   1/PI. */
    static const double ONE_OVER_PI = 1.0 / trUtil::Math::PI;
    /** @brief   PI/180. */
    static const double ONE80_OVER_PI = (180.0*ONE_OVER_PI);

    /**
        * @fn  inline void SinCos(double x, double& sinVal, double& cosVal)
        *
        * @brief   Takes a Value X and outputs its Sin and Cos by reference.
        *
        * @param           x       The x coordinate.
        * @param [in,out]  sinVal  The sine value.
        * @param [in,out]  cosVal  The cosine value.
        */
    inline void SinCos(double x, double& sinVal, double& cosVal)
    {
        sinVal = sin(x);
        cosVal = cos(x);
    }

    /**
        * @fn  inline void SinCos(float x, float& sinVal, float& cosVal)
        *
        * @brief   Takes a Value X and outputs its Sin and Cos by reference.
        *
        * @param           x       The x coordinate.
        * @param [in,out]  sinVal  The sine value.
        * @param [in,out]  cosVal  The cosine value.
        */
    inline void SinCos(float x, float& sinVal, float& cosVal)
    {
        sinVal = sin(x);
        cosVal = cos(x); // Might benefit from trig identities
    }

    /**
        * @fn  inline double Deg2Rad(double degree)
        *
        * @brief   Takes Degrees and converts them to Radians.
        *
        * @param   degree  The degree.
        *
        * @return  A double.
        */
    inline double Deg2Rad(double degree)
    {
        return osg::DegreesToRadians(degree);
    }

    /**
        * @fn  inline float Deg2Rad(float degree)
        *
        * @brief   Takes Degrees and converts them to Radians.
        *
        * @param   degree  The degree.
        *
        * @return  A float.
        */
    inline float Deg2Rad(float degree)
    {
        return osg::DegreesToRadians(degree);
    }

    /**
        * @fn  inline double Rad2Deg(double radian)
        *
        * @brief   Takes Radians and converts them to Degrees.
        *
        * @param   radian  The radian.
        *
        * @return  A double.
        */
    inline double Rad2Deg(double radian)
    {
        return osg::RadiansToDegrees(radian);
    }

    /**
        * @fn  inline float Rad2Deg(float radian)
        *
        * @brief   Takes Radians and converts them to Degrees.
        *
        * @param   radian  The radian.
        *
        * @return  A float.
        */
    inline float Rad2Deg(float radian)
    {
        return osg::RadiansToDegrees(radian);
    }

    /**
        * @fn  inline double CheckState(double state)
        *
        * @brief   Checks if State is = to 0, less then 0 or greater, and outputs -1, 0, 1.
        *
        * @param   state   The state.
        *
        * @return  A double.
        */
    inline double CheckState(double state)
    {
        if (state == 0)
            return 0;
        else if (state < 0)
            return -1;
        else
            return 1;
    }

    /**
        * @fn  inline float CheckState(float state)
        *
        * @brief   Checks if State is = to 0, less then 0 or greater, and outputs -1, 0, 1.
        *
        * @param   state   The state.
        *
        * @return  A float.
        */
    inline float CheckState(float state)
    {
        if (state == 0)
            return 0;
        else if (state < 0)
            return -1;
        else
            return 1;
    }

    /**
        * @fn  inline T Lerp(T from, T to, T alpha)
        *
        * @brief   Linear Interpolation function.
        *
        * @tparam  T   Generic type parameter.
        *
        * @param   from    Start point from which to interpret.
        * @param   to      End point to which to interpret.
        * @param   alpha   The alpha (0-1)
        *
        * @return  A T.
        */
    template <typename T>
    inline T Lerp(T from, T to, T alpha)
    {
        return from + ((to - from) * alpha);
    }
}