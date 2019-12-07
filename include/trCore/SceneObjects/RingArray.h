/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2019 Acid Rain Studios LLC
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

#include <trCore/Export.h>

#include <trBase/SmrtPtr.h>

#include <osg/Group>
#include <osg/Node>
#include <osg/NodeVisitor>
#include <osg/PositionAttitudeTransform>

/**
 * @namespace   trCore::SceneObjects
 *
 * @brief   Namespace that contains controls for sample scene objects.
 */
namespace trCore::SceneObjects
{
    /**
        * @class   RingArray
        *
        * @brief   A rotating ring array model.
        *
        * @author  Maxim Serebrennik
        */
    class TR_CORE_EXPORT RingArray : public osg::Group
    {
    public:

        const static std::string RING_1_FILE_NAME;
        const static std::string RING_2_FILE_NAME;
        const static std::string RING_3_FILE_NAME;
        const static std::string RING_4_FILE_NAME;

        /**
            * @fn  RingArray::RingArray();
            *
            * @brief   Default constructor.
            */
        RingArray();

        /**
            * @fn  RingArray::RingArray(double angleCorrection);
            *
            * @brief   Constructor.
            *
            * @param   angleCorrection Changes the initial direction of the ring. Angle is in degrees.
            */
        RingArray(double angleCorrection);

        /**
            * @fn  virtual void RingArray::Update(osg::Node* node, osg::NodeVisitor* nv, double deltaTime);
            *
            * @brief   This function gets called by the RingArrayCallback.
            *
            * @param           deltaTime   The delta time between frames.
            */
        virtual void Update(double deltaTime);

    protected:

        /**
            * @fn  RingArray::~RingArray();
            *
            * @brief   Destructor.
            */
        ~RingArray();

        /**
            * @fn  void RingArray::LoadModels();
            *
            * @brief   Loads the models and creates transform nodes for the model tree.
            */
        void LoadModels();

        /**
            * @fn  void RingArray::SetupModelTree();
            *
            * @brief   Sets up the model tree.
            */
        void SetupModelTree();

        /**
            * @fn  void RingArray::UpdateRing1Slide(double deltaTime);
            *
            * @brief   Updates the ring 1 slide.
            *
            * @param   deltaTime   The delta time.
            */
        void UpdateRing1Slide(double deltaTime);

        /**
            * @fn  void RingArray::UpdateRing2Angle(double deltaTime);
            *
            * @brief   Updates the ring 2 angle.
            *
            * @param   deltaTime   The delta time.
            */
        void UpdateRing2Angle(double deltaTime);

        /**
            * @fn  void RingArray::UpdateRing2Slide(double deltaTime);
            *
            * @brief   Updates the ring 2 slide.
            *
            * @param   deltaTime   The delta time.
            */
        void UpdateRing2Slide(double deltaTime);

        /**
            * @fn  void RingArray::UpdateRing3Angle(double deltaTime);
            *
            * @brief   Updates the ring 3 angle.
            *
            * @param   deltaTime   The delta time.
            */
        void UpdateRing3Angle(double deltaTime);

        /**
            * @fn  void RingArray::UpdateRing3Slide(double deltaTime);
            *
            * @brief   Updates the ring 3 slide.
            *
            * @param   deltaTime   The delta time.
            */
        void UpdateRing3Slide(double deltaTime);

        /**
            * @fn  void RingArray::UpdateRing4Angle(double deltaTime);
            *
            * @brief   Updates the ring 4 angle.
            *
            * @param   deltaTime   The delta time.
            */
        void UpdateRing4Angle(double deltaTime);

    private:

        const double MAX_RING_SPEED = 5.0;
        const double RING_ACCEL = 0.1;
        const double START_DELAY = 5.0;

        trBase::SmrtPtr<osg::Group> mRing1;
        trBase::SmrtPtr<osg::PositionAttitudeTransform> mRing1Slide;
        double mRing1SlideSpeed = 0.0;
        double mRing1SlideAngle = 0.0;
        double mRing1SlideDelay = 0.0;
        trBase::SmrtPtr<osg::Group> mRing2;
        trBase::SmrtPtr<osg::PositionAttitudeTransform> mRing2Rotation;
        double mRing2RotationSpeed = 0.0;
        double mRing2RotationAngle = 0.0;
        double mRing2RotationDelay = 0.0;
        trBase::SmrtPtr<osg::PositionAttitudeTransform> mRing2Slide;
        double mRing2SlideSpeed = 0.0;
        double mRing2SlideAngle = 0.0;
        double mRing2SlideDelay = 0.0;
        trBase::SmrtPtr<osg::Group> mRing3;
        trBase::SmrtPtr<osg::PositionAttitudeTransform> mRing3Rotation;
        double mRing3RotationSpeed = 0.0;
        double mRing3RotationAngle = 0.0;
        double mRing3RotationDelay = 0.0;
        trBase::SmrtPtr<osg::PositionAttitudeTransform> mRing3Slide;
        double mRing3SlideSpeed = 0.0;
        double mRing3SlideAngle = 0.0;
        double mRing3SlideDelay = 0.0;
        trBase::SmrtPtr<osg::Node> mRing4;
        trBase::SmrtPtr<osg::PositionAttitudeTransform> mRing4Rotation;
        double mRing4RotationSpeed = 0.0;
        double mRing4RotationAngle = 0.0;
        double mRing4RotationDelay = 0.0;

        trBase::SmrtPtr<osg::PositionAttitudeTransform> mAngleCorrection;
    };
}