/*
* The Construct Open Source Game and Simulation Engine
* Copyright (C) 2013
*
* This library is free software; you can redistribute it and/or modify it under
* the terms of the GNU Lesser General Public License as published by the Free
* Software Foundation; either version 2.1 of the License, or (at your option)
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

#ifndef COREDLL_OBJECT_ACTOR_H
#define COREDLL_OBJECT_ACTOR_H

#include "export.h"

#include <iostream>

#include "vrsCoreEnum.h"

#include <dtDAL/enginepropertytypes.h>

#include <dtCore/Object.h>

#include <dtActors/StaticMeshActorProxy.h>

namespace vrsCore
{

	//A Generic Static Mesh Object Actor, that inherit dtCore::Object, but adds Render
	//Bin Controlls to STAGE proxyes
	class CORE_EXPORT ObjectActor : public dtCore::Object
	{
		public:

			//Default Actors Name
			static const std::string ACTOR_DEFAULT_NAME;
			
			//Default Actors Class Name
			static const std::string ACTOR_CLASS_NAME;

			//Constructor
			ObjectActor(void);

			//Set the Rendering Bin Number
			void SetRenderBin(int BinNum);

			//Get the Rendering Bin Number
			int GetRenderBin(void) const { return mRenderBinNum; }

			//Set the Rendering Bin Number Sort Type
			void SetRenderBinSortType(vrsCore::RENDER_BIN_TYPE& BinSortType);

			//Get the Rendering Bin Number Sort Type
			vrsCore::RENDER_BIN_TYPE& GetRenderBinSortType(void) { return *mBinSortType; }

			//Called when the Actor is added to the Scene
			virtual void AddedToScene(dtCore::Scene* scene);


	   //protected:
			//Destructor
			virtual ~ObjectActor() { } ;

		private:
			
					//Set the RenderBin Number and Sort Type
			void	ChangeRenderBinProp(int BinNum, vrsCore::RENDER_BIN_TYPE& BinType);


			
			int		mRenderBinNum;		//Holds the Rendering Bin Number
										//Holds the Rendering Bin Sorting Type
			vrsCore::RENDER_BIN_TYPE*	 mBinSortType;

	};

	/**
	 * Our proxy class for the actor.  The proxy contains properties,
	 * invokables, and the actor.
	 */
	class CORE_EXPORT ObjectActorProxy : public dtActors::StaticMeshActorProxy
	{
	   public:
		  // Constructs the proxy.
		  ObjectActorProxy();

		  // Creates the properties that are custom to the actor proxy.
		  virtual void BuildPropertyMap();

		  //Build Invokables to hook the proxy into the GM
		  //In this actor we will only use the default ones...
		  //virtual void BuildInvokables();

		  /**
          *  Called when this ActorProxy has finished loading from a Map and
          *  all Property values have been assigned.  Overwrite for custom
          *  behavior.
          */
		  virtual void OnMapLoadEnd();

		  virtual ~ObjectActorProxy() { };

	   protected:
	      

		  // Creates an instance of our actor
		  virtual void CreateActor();

		  
	};
}
#endif //COREDLL_OBJECT_ACTOR_H
