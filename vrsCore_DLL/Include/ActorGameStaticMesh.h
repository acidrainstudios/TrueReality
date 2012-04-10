/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* Virtual Reality Simulation Lab
* 
* This file is part of Virtual Reality Simulation Lab software. You can redistribute 
* it and/or modify it only with the authors permission. All unlicensed use and modification
* of this file are prohibited. 
* 
* This does not restrict the user from creating custom modules and additional files to 
* interface with the VR-Sim Lab.
* 
* This software was developed by Maxim Serebrennik for Various projects he worked on.
* It is sold and distributed only with his permission. 
* 
* For more information e-mail him at MaximSter@gmail.com
* 
* @author Maxim Serebrennik 
*////////////////////////////////////////////////////////////////////////////////

#ifndef COREDLL_GAME_STATIC_MESH_ACTOR_H
#define COREDLL_GAME_STATIC_MESH_ACTOR_H

#include <iostream>

#include "export.h"

#include "vrsCoreEnum.h"

#include <dtDAL/enginepropertytypes.h>
#include <dtDAL/functor.h>

#include <dtActors/gamemeshactor.h>


namespace vrsCore
{

	//A Generic Static Mesh Game Actor, that inherit dtActors::GameMeshActor, but adds Render
	//Bin Controlls to STAGE proxyes
	class CORE_EXPORT GameStaticMeshActor : public dtActors::GameMeshActor
	{
	public:

		//Default Actors Name
		static const std::string ACTOR_DEFAULT_NAME;

		//Default Actors Class Name
		static const std::string ACTOR_CLASS_NAME;

		// Constructs the actor.
		GameStaticMeshActor(dtActors::GameMeshActorProxy& proxy);
		
		//Set the Rendering Bin Number
		void SetRenderBin(int BinNum);

		//Get the Rendering Bin Number
		int GetRenderBin(void) const { return mRenderBinNum; }

		//Set the Rendering Bin Number Sort Type
		void SetRenderBinSortType(vrsCore::RENDER_BIN_TYPE& BinSortType);

		//Get the Rendering Bin Number Sort Type
		vrsCore::RENDER_BIN_TYPE& GetRenderBinSortType(void) { return *mBinSortType; }

		// Called when the actor has been added to the game manager.
		// You can respond to OnEnteredWorld on either the proxy or actor or both.
		virtual void OnEnteredWorld();

				/**
		*Calls Load File if we entered the scene....
		*/
        virtual void AddedToScene(dtCore::Scene* scene);

	//protected:
		virtual ~GameStaticMeshActor() { } ;

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
	class CORE_EXPORT GameStaticMeshActorProxy : public dtActors::GameMeshActorProxy
	{
	   public:
		  // Constructs the proxy.
		  GameStaticMeshActorProxy();

		  // Creates the properties that are custom to the actor proxy.
		  virtual void BuildPropertyMap();

		  //Build Invokables to hook the proxy into the GM
		  //In this actor we will only use the default ones...
		  //virtual void BuildInvokables();

		  virtual ~GameStaticMeshActorProxy() { };

	   protected:
	      

		  // Creates an instance of our actor
		  virtual void CreateActor();

		  // Called when this proxy is added to the game manager (ie, the "world")
		  // You can respond to OnEnteredWorld on either the proxy or actor or both.
		  virtual void OnEnteredWorld();
	};
}
#endif //COREDLL_GAME_STATIC_MESH_ACTOR_H
