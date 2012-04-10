/*
* //////////////////////////////////////C++//////////////////////////////////////
* 
* CS900 DLL Stevens Institute of Technology Camera Tracker Project
*
* CopyRight © The Stevens Institute of Technology 2010
*
* @author CS900 Project:  e-mail MaximSter@gmail.com for more info
*
* View full author list in files Version Info
*////////////////////////////////////////////////////////////////////////////////


#ifndef VRS_TRACKER_COMPONENT_CPP
#define VRS_TRACKER_COMPONENT_CPP


#include "..\\Include\TrackerComponent.h"

XERCES_CPP_NAMESPACE_USE


////////////////////////////////////////////////////////////////////
const std::string TrackerComponent::COMPONENT_DEFAULT_NAME("TrackerComponent");
////////////////////////////////////////////////////////////////////
TrackerComponent::TrackerComponent(const std::string& name)
:dtGame::GMComponent(name)
,mDeltaSimTime(0.0f)
,mLastSimTime(0)
,mSimTime(0)
,fpos(0)
,mKillTime(10)
,mSubSampleRate(5)
,mAvgWindowSize(0)
{
	mOrigin[0]=0;
	mOrigin[1]=0;


	mShipTypes.insert(std::pair<std::string,std::string>("Default","Class_Default"));

	//////////parse config_tracker xml file
	//////////to get event_log location
	/////////and ship type pairings
	char* xmlFile = "Data/config_tracker.xml";
	try{
		XMLPlatformUtils::Initialize();
	}
	catch(const XMLException & toCatch){
		XERCES_STD_QUALIFIER cerr << "Error during Xerces-c Initialization.\n"
             << "  Exception message:"
			 << XMLString::transcode(toCatch.getMessage()) << XERCES_STD_QUALIFIER endl;
	}

	XercesDOMParser *parser=new XercesDOMParser;
	parser->setDoNamespaces(true);
	parser->parse(xmlFile);
	DOMDocument *doc = parser->getDocument();
	XMLCh tname[100];

	//get location of event_log file
    XMLString::transcode("eventlog", tname, 99);
	DOMNodeList *nl=doc->getElementsByTagName(tname);
	DOMElement *el;
	if(nl->getLength()>0){
		el=static_cast<DOMElement*>(nl->item(0));
		XMLString::transcode("path", tname, 99);
		fname=XMLString::transcode(el->getAttribute(tname));
	}
	
	//get mapping of class ids to prototype names
	XMLString::transcode("shiptype", tname, 99);
	nl=doc->getElementsByTagName(tname);
	for(unsigned int i=0;i<nl->getLength();i++)
	{
		el=static_cast<DOMElement *>(nl->item(i));
		XMLString::transcode("classname", tname, 99);
		std::string val=XMLString::transcode(el->getAttribute(tname));
		XMLString::transcode("prototype", tname, 99);
		std::string nm=XMLString::transcode(el->getAttribute(tname));
		mShipTypes.insert(std::pair<std::string,std::string>(val,nm));
	}

	//get component parameters:  timetokill, readrate, avgwindow
	XMLString::transcode("params", tname, 99);
	nl=doc->getElementsByTagName(tname);
	if(nl->getLength()>0){
		el=static_cast<DOMElement*>(nl->item(0));
		XMLString::transcode("timetokill", tname, 99);
		mKillTime=strtod(XMLString::transcode(el->getAttribute(tname)),NULL);
		XMLString::transcode("readrate", tname, 99);
		mSubSampleRate=strtod(XMLString::transcode(el->getAttribute(tname)),NULL);
		XMLString::transcode("avgwindow", tname, 99);
		mAvgWindowSize=strtod(XMLString::transcode(el->getAttribute(tname)),NULL);
	}

	//get world coordinates origin
	XMLString::transcode("origin", tname, 99);
	nl=doc->getElementsByTagName(tname);
	if(nl->getLength()>0){
		el=static_cast<DOMElement*>(nl->item(0));
		XMLString::transcode("UTME", tname, 99);
		mOrigin[0]=strtod(XMLString::transcode(el->getAttribute(tname)),NULL);
		XMLString::transcode("UTMN", tname, 99);
		mOrigin[1]=strtod(XMLString::transcode(el->getAttribute(tname)),NULL);
	}

	delete parser;
	XMLPlatformUtils::Terminate();

	AddSender(&dtCore::System::GetInstance());			
}

////////////////////////////////////////////////////////////////////
void TrackerComponent::SetupEvents()
{

}

//////////////////////////////////////////////////////////////////////////
void TrackerComponent::ProcessMessage(const dtGame::Message& message)
{
	if (message.GetMessageType() == dtGame::MessageType::TICK_LOCAL)
	{
		mSimTime = GetGameManager()->GetSimulationTime();
		mDeltaSimTime = mSimTime - mLastSimTime;
		
		if(mDeltaSimTime>mSubSampleRate)  //parse file every mSubSampleRate seconds
		{
			ReadNewData(fname);  //parse event_log file
			UpdateBabies();		//create and move actors
			KillBabies();		//remove old actors
			mLastSimTime = mSimTime;
		}
		
	}
	else if (message.GetMessageType() == dtGame::MessageType::INFO_MAP_LOADED)
	{
		//initially move the camera to the relative world
		std::vector<dtDAL::ActorProxy*>toFill;
		GetGameManager()->FindActorsByName("Camera",toFill);
		if(!toFill.empty()){
			dtCore::RefPtr<dtGame::GameActor>player=(dtGame::GameActor*)toFill[0]->GetActor();
			dtCore::Transform trans;
			osg::Vec3f pos;
			player->GetTransform(trans);
			trans.GetTranslation(pos);
			pos-=mOrigin;
			trans.SetTranslation(pos);
			player->SetTransform(trans);
		}
	}
}
//////////////////////////////////////////////////////////////////////////

void TrackerComponent::OnMessage(MessageData *data)
{
		
}

//parse event file starting at fpos
bool TrackerComponent::ReadNewData(std::string fname)
{
	std::ifstream npcPathFile;	
	npcPathFile.open(fname.c_str());
	newevents.clear();
	if(npcPathFile.is_open()){
		npcPathFile.seekg(fpos);
		std::string line;
		bool newdata=false;
		while (!npcPathFile.eof())
		{
			getline(npcPathFile, line);
			
			if(npcPathFile.tellg()>0){
				ParsePosition(line);
				fpos=npcPathFile.tellg();
				newdata=true;
			}
		}
		if(newdata){
			std::cout<<"New Data\n";
		}
		npcPathFile.close();
	}
	npcPathFile.clear();

	return true;
}


//extract parts of event and add to list of newevents
bool TrackerComponent::ParsePosition(const std::string& line)
{
	std::vector<std::string> position = Utils::splitString(line, POSITION_DELIM);
	int id,type;
	float xUTM, yUTM;
	std::string classname="Default";
	double timestamp;
	if (!Utils::stringTo<int>(id, position.at(PATH_ID)))
		return false;
	if (!Utils::stringTo<float>(xUTM, position.at(PATH_X_UTM)))
		return false;
	if (!Utils::stringTo<float>(yUTM, position.at(PATH_Y_UTM)))
		return false;
	if (!Utils::stringTo<double>(timestamp, position.at(PATH_TIME)))
		return false;
	if ((position.size()<=PATH_TYPE)||(!Utils::stringTo<int>(type, position.at(PATH_TYPE))))
		type=-1;
	if (position.size()>PATH_CLASSNAME){
		if(!(type>=0))
			return false;
		classname=position.at(PATH_CLASSNAME);
	};

	//add to list
	evt x;
	x.id=id;
	x.pos[0]=xUTM;
	x.pos[1]=yUTM;
	x.type=type;
	x.classname=classname;
	x.realtime=timestamp;
	x.time=GetGameManager()->GetSimulationTime();

	//check to see if an event already exists for that actor
	//if it does replace it with the one thats newer
	evtMap::iterator it;
	it=newevents.find(id);
	if(it==newevents.end())		//no actor exists for this id, create a new one
		newevents[id]=x;
	else{
		evt y=it->second;
		if(x.realtime>y.realtime)
			newevents[id]=x;
	}
	
	return true;
}


void TrackerComponent::UpdateBabies()
{
	for(evtMap::iterator it=newevents.begin();it!=newevents.end();++it){			//for each new event
		int loc=-1;
		for(int j=0;j<(int)mBabyVector.size();j++){									//find entry in hash table
			if(it->first==mBabyVector[j]->GetEventId()){
				loc=j;
				break;
			}
		}
		if(loc<0)  //new baby!
			MakeBaby(it->second);
		else{  //update actor according to corresponding event
			mBabyVector[loc]->UpdatePosition(it->second.pos,it->second.time);
		}
	}
	
}

void TrackerComponent::MakeBaby(evt baby){

	dtDAL::ActorProxy* actorProxy=0;
											//find prototype actor by name
	std::map<std::string,std::string>::iterator it;
	it=mShipTypes.find(baby.classname);
	std::string protoname="Class_Default";
	if(it!=mShipTypes.end())
		protoname=it->second;
	
	GetGameManager()->FindPrototypeByName(protoname, actorProxy); 
	if(actorProxy==0)
		return;
												//create a new actor and get its actual proxy
	osg::ref_ptr<dtDAL::ActorProxy> actualActorProxy = GetGameManager()->CreateActorFromPrototype(actorProxy->GetId() );

	if( actualActorProxy.valid() )
	{
		TrackerActor* actor = static_cast<TrackerActor*>(actualActorProxy->GetActor());
		actor->SetUseCache(true);
		actor->SetName(TrackerActor::ACTOR_DEFAULT_NAME);

		//add the actor to the GM
		GetGameManager()->AddActor(actor->GetGameActorProxy(), false, true);
		actor->SetLastUpdate(baby.time);
		actor->SetEventId(baby.id);
		actor->SetOrigin(mOrigin);
		actor->SetAvgWindowSize(mAvgWindowSize);
		actor->UpdatePosition(baby.pos,baby.time);
		mBabyVector.push_back(actor);
	}
}

void TrackerComponent::KillBabies()
{
	mSimTime = GetGameManager()->GetSimulationTime();
	for(int i=0;i<(int)mBabyVector.size();i++){
		float dt = mSimTime - mBabyVector[i]->GetLastUpdate();
		if(dt>mKillTime){
			GetGameManager()->DeleteActor(mBabyVector[i]->GetGameActorProxy());
			mBabyVector.erase(mBabyVector.begin()+i);
		}
	}
}


#endif //Tracker_COMPONENT_H