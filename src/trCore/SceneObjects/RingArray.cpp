/*
* True Reality Open Source Game and Simulation Engine
* Copyright © 2018 Acid Rain Studios LLC
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

#include <trCore/SceneObjects/RingArray.h>

#include <trBase/SmrtPtr.h>
#include <trBase/Vec3.h>
#include <trBase/Quat.h>
#include <trUtil/Math.h>
#include <trUtil/PathUtils.h>

#include <osg/Math>
#include <osgDB/ReadFile>

#include <iostream>

namespace trCore
{
    namespace SceneObjects
    {
        const std::string RingArray::RING_1_FILE_NAME("/RingArray/Ring1.osgb");
        const std::string RingArray::RING_2_FILE_NAME("/RingArray/Ring2.osgb");
        const std::string RingArray::RING_3_FILE_NAME("/RingArray/Ring3.osgb");
        const std::string RingArray::RING_4_FILE_NAME("/RingArray/Ring4.osgb");

        //////////////////////////////////////////////////////////////////////////
        RingArray::RingArray()
        {
            LoadModels();
            SetupModelTree();
        }

        //////////////////////////////////////////////////////////////////////////
        RingArray::RingArray(double angleCorrection) : RingArray()
        {
            mAngleCorrection->setAttitude(*new trBase::Quat(trUtil::Math::Deg2Rad(angleCorrection), trBase::Z_AXIS));
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::Update(double deltaTime)
        {
            UpdateRing1Slide(deltaTime);
        }

        //////////////////////////////////////////////////////////////////////////
        RingArray::~RingArray()
        {
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::LoadModels()
        {
            //Creates nodes for the first ring
            mRing1 = new osg::Group();
            mRing1->addChild(osgDB::readNodeFile(trUtil::PathUtils::GetStaticMeshesPath() + RING_1_FILE_NAME));
            mRing1Slide = new osg::PositionAttitudeTransform();

            //Creates nodes for the second ring
            mRing2Rotation = new osg::PositionAttitudeTransform();
            mRing2 = new osg::Group();
            mRing2->addChild(osgDB::readNodeFile(trUtil::PathUtils::GetStaticMeshesPath() + RING_2_FILE_NAME));
            mRing2Slide = new osg::PositionAttitudeTransform();

            //Creates Nodes for the third ring
            mRing3Rotation = new osg::PositionAttitudeTransform();
            mRing3 = new osg::Group();
            mRing3->addChild(osgDB::readNodeFile(trUtil::PathUtils::GetStaticMeshesPath() + RING_3_FILE_NAME));
            mRing3Slide = new osg::PositionAttitudeTransform();

            //Creates nodes for the smallest, internal ring. 
            mRing4Rotation = new osg::PositionAttitudeTransform();
            mRing4 = osgDB::readNodeFile(trUtil::PathUtils::GetStaticMeshesPath() + RING_4_FILE_NAME);

            //Creates the angle correction transform. 
            mAngleCorrection = new osg::PositionAttitudeTransform();

        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::SetupModelTree()
        {
            //Create the Ring tree		
            mRing1->addChild(mRing1Slide);
            mRing1Slide->addChild(mRing2Rotation);
            mRing2Rotation->addChild(mRing2);
            mRing2->addChild(mRing2Slide);
            mRing2Slide->addChild(mRing3Rotation);
            mRing3Rotation->addChild(mRing3);
            mRing3->addChild(mRing3Slide);
            mRing3Slide->addChild(mRing4Rotation);
            mRing4Rotation->addChild(mRing4);

            //Add the initial angle correction. 
            mAngleCorrection->addChild(mRing1);

            //Add the tree to root
            addChild(mAngleCorrection);
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::UpdateRing1Slide(double deltaTime)
        {
            if (mRing1SlideDelay > START_DELAY)
            {
                //Calculate the speed
                if (mRing1SlideSpeed < MAX_RING_SPEED)
                {
                    mRing1SlideSpeed += RING_ACCEL * deltaTime;
                }

                //Calculate the new position
                mRing1SlideAngle += mRing1SlideSpeed * deltaTime;

                if (mRing1SlideAngle > trUtil::Math::TWO_PI)
                {
                    mRing1SlideAngle -= trUtil::Math::TWO_PI;
                }

                mRing1Slide->setAttitude(trBase::Quat(mRing1SlideAngle, trBase::X_AXIS));

                UpdateRing2Angle(deltaTime);
            }
            else
            {
                mRing1SlideDelay += deltaTime;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::UpdateRing2Angle(double deltaTime)
        {
            if (mRing2RotationDelay > START_DELAY)
            {
                //Calculate the speed
                if (mRing2RotationSpeed < MAX_RING_SPEED)
                {
                    mRing2RotationSpeed += RING_ACCEL * deltaTime;
                }

                //Calculate the new position
                mRing2RotationAngle += mRing2RotationSpeed * deltaTime;

                if (mRing2RotationAngle > trUtil::Math::TWO_PI)
                {
                    mRing2RotationAngle -= trUtil::Math::TWO_PI;
                }


                mRing2Rotation->setAttitude(trBase::Quat(mRing2RotationAngle, trBase::Y_AXIS));

                UpdateRing2Slide(deltaTime);
            }
            else
            {
                mRing2RotationDelay += deltaTime;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::UpdateRing2Slide(double deltaTime)
        {
            if (mRing2SlideDelay > START_DELAY)
            {
                //Calculate the speed
                if (mRing2SlideSpeed < MAX_RING_SPEED)
                {
                    mRing2SlideSpeed += RING_ACCEL * deltaTime;
                }

                //Calculate the new position
                mRing2SlideAngle += mRing2SlideSpeed * deltaTime;

                if (mRing2SlideAngle > trUtil::Math::TWO_PI)
                {
                    mRing2SlideAngle -= trUtil::Math::TWO_PI;
                }

                mRing2Slide->setAttitude(trBase::Quat(mRing2SlideAngle, trBase::X_AXIS));

                UpdateRing3Angle(deltaTime);
            }
            else
            {
                mRing2SlideDelay += deltaTime;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::UpdateRing3Angle(double deltaTime)
        {
            if (mRing3RotationDelay > START_DELAY)
            {
                //Calculate the speed
                if (mRing3RotationSpeed < MAX_RING_SPEED)
                {
                    mRing3RotationSpeed += RING_ACCEL * deltaTime;
                }

                //Calculate the new position
                mRing3RotationAngle += mRing3RotationSpeed * deltaTime;

                if (mRing3RotationAngle > trUtil::Math::TWO_PI)
                {
                    mRing3RotationAngle -= trUtil::Math::TWO_PI;
                }

                mRing3Rotation->setAttitude(trBase::Quat(mRing3RotationAngle, trBase::Y_AXIS));

                UpdateRing3Slide(deltaTime);
            }
            else
            {
                mRing3RotationDelay += deltaTime;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::UpdateRing3Slide(double deltaTime)
        {
            if (mRing3SlideDelay > START_DELAY)
            {
                //Calculate the speed
                if (mRing3SlideSpeed < MAX_RING_SPEED)
                {
                    mRing3SlideSpeed += RING_ACCEL * deltaTime;
                }

                //Calculate the new position
                mRing3SlideAngle += mRing3SlideSpeed * deltaTime;

                if (mRing3SlideAngle > trUtil::Math::TWO_PI)
                {
                    mRing3SlideAngle -= trUtil::Math::TWO_PI;
                }

                mRing3Slide->setAttitude(trBase::Quat(mRing3SlideAngle, trBase::X_AXIS));

                UpdateRing4Angle(deltaTime);
            }
            else
            {
                mRing3SlideDelay += deltaTime;
            }
        }

        //////////////////////////////////////////////////////////////////////////
        void RingArray::UpdateRing4Angle(double deltaTime)
        {
            if (mRing4RotationDelay > START_DELAY)
            {
                //Calculate the speed
                if (mRing4RotationSpeed < MAX_RING_SPEED)
                {
                    mRing4RotationSpeed += RING_ACCEL * deltaTime;
                }

                //Calculate the new position
                mRing4RotationAngle += mRing4RotationSpeed * deltaTime;

                if (mRing4RotationAngle > trUtil::Math::TWO_PI)
                {
                    mRing4RotationAngle -= trUtil::Math::TWO_PI;
                }

                mRing4Rotation->setAttitude(trBase::Quat(mRing4RotationAngle, trBase::Y_AXIS));
            }
            else
            {
                mRing4RotationDelay += deltaTime;
            }
        }
    }
}