osgViewer::CompositeViewer
osgViewer::GraphicsWindow
osgViewer::StatsHandler
osgViewer::View
osgViewer::Viewer
osgViewer::Viewer::CullThreadPerCameraDrawThreadPerContext
osgViewer::Viewer::SingleThreaded
osgViewer::Viewer::Windows
osgViewer::Viewer::Windows::iterator
osgViewer::ViewerBase::Contexts

osgUtil::CullVisitor
osgUtil::LineSegmentIntersector
osgUtil::LineSegmentIntersector::Intersections
osgUtil::LineSegmentIntersector::Intersections::iterator
osgUtil::Optimizer
osgUtil::Optimizer::FlattenStaticTransformsVisitor
osgUtil::Optimizer::REMOVE_LOADED_PROXY_NODES
osgUtil::Optimizer::REMOVE_REDUNDANT_NODES
osgUtil::Optimizer::SHARE_DUPLICATE_STATE
osgUtil::Simplifier
osgUtil::SceneView::VariablesMask::ALL_VARIABLES
osgUtil::SceneView::VariablesMask::CULL_MASK
osgUtil::SmoothingVisitor

osgText::Font
osgText::readFontFile
osgText::Text
osgText::Text::AlignmentType
osgText::Text::LEFT_CENTER
osgText::Text::REVERSED_YZ_PLANE
osgText::Text::SCREEN
osgText::Text::SCREEN_COORDS
osgText::TextBase::CENTER_CENTER

osgSim::DOFTransform
osgSim::MultiSwitch
osgSim::LightPointNode

osgParticle::Emitter
osgParticle::FluidProgram
osgParticle::ModularEmitter
osgParticle::ModularProgram
osgParticle::ParticleSystem
osgParticle::ParticleSystemUpdater
osgParticle::ParticleProcessor::ABSOLUTE_RF
osgParticle::Program

osgGA::CameraManipulator
osgGA::GUIActionAdapter
osgGA::GUIEventAdapter
osgGA::GUIEventAdapter::DRAG
osgGA::GUIEventAdapter::FRAME
osgGA::GUIEventAdapter::KEYUP
osgGA::GUIEventAdapter::KEYDOWN
osgGA::GUIEventAdapter::KEY_Control_R
osgGA::GUIEventAdapter::KEY_Shift_R
osgGA::GUIEventAdapter::KEY_Minus
osgGA::GUIEventAdapter::KEY_F1
osgGA::GUIEventAdapter::MODKEY_ALT
osgGA::GUIEventAdapter::MODKEY_SHIFT
osgGA::GUIEventAdapter::PUSH
osgGA::GUIEventHandler
osgGA::TrackballManipulator

osgDB::Archive
osgDB::ArchiveExtended
osgDB::CASE_INSENSITIVE
osgDB::concatPaths
osgDB::DIRECTORY
osgDB::FileType
osgDB::findDataFile
osgDB::findFileInDirectory
osgDB::getFileExtensionIncludingDot
osgDB::getFileExtension
osgDB::getFilePath
osgDB::getSimpleFileName
osgDB::getStrippedName
osgDB::Options
osgDB::Options::CACHE_ALL
osgDB::readImageFile
osgDB::readNodeFile
osgDB::ReaderWriter::Options
osgDB::ReaderWriter::Options::CACHE_IMAGES
osgDB::ReaderWriter::ReaderWriter::Options
osgDB::ReaderWriter::ReadResult
osgDB::ReaderWriter::READ
osgDB::ReaderWriter::WriteResult
osgDB::Registry::ArchiveExtensionList
osgDB::Registry::ArchiveExtensionList::const_iterator iter
osgDB::Registry::instance
osgDB::REGULAR_FILE
osgDB::SharedStateManager
osgDB::writeImageFile
osgDB::writeNodeFile

osg::AlphaFunc
osg::AlphaFunc::GEQUAL
osg::ArgumentParser
osg::Array::BIND_OVERALL 
osg::Billboard
osg::Billboard::AXIAL_ROT
osg::BlendFunc
osg::BoundingBox
osg::BoundingSphere
osg::Camera::DrawCallback
osg::Camera
osg::Camera::FRAME_BUFFER
osg::clone
osg::componentMultiply
osg::computeLocalToWorld
osg::CopyOp
osg::CopyOp::SHALLOW_COPY
osg::DegreesToRadians
osg::Depth
osg::Drawable
osg::Drawable::Drawable::UpdateCallback
osg::DrawArrays
osg::DrawElementsUInt
osg::DrawElementsUShort
osg::FloatArray(array_size);
osg::Geode
osg::Geometry::BIND_OVERALL
osg::Geometry::PrimitiveSetList
osg::Geometry::PrimitiveSetList::iterator
osg::GraphicsContext
osg::GraphicsContext::Traits
osg::Group
osg::Image
osg::isNaN
osg::LightSource
osg::LOD
osg::Material
osg::Material::FRONT_AND_BACK
osg::Matrix
osg::Matrixd
osg::MatrixTransform
osg::Node
osg::Node::ParentList::iterator
osg::NOTICE
osg::notify
osg::NodeCallback
osg::NodeVisitor
osg::NodeVisitor::TRAVERSE_ALL_CHILDREN
osg::Object
osg::Object::STATIC
osg::Operation
osg::Plane
osg::Polytope
osg::PrimitiveSet
osg::PrimitiveSet::QUADS
osg::PrimitiveSet::TRIANGLE_STRIP
osg::Program
osg::ProxyNode
osg::QueryGeometry
osg::RadiansToDegrees
osg::RefMatrix
osg::ref_ptr
osg::RenderInfo
osg::Shader
osg::Shader::FRAGMENT
osg::Shader::VERTEX
osg::StateAttribute::BLENDFUNC
osg::StateAttribute::ON
osg::StateAttribute::TEXTURE
osg::StateSet
osg::StateSet::TRANSPARENT_BIN
osg::StateSet::USE_RENDERBIN_DETAILS
osg::Switch
osg::TexEnv
osg::TexEnv::MODULATE
osg::Texture
osg::Texture::InternalFormatMode
osg::Texture::USE_IMAGE_DATA_FORMAT
osg::Texture::USE_S3TC_DXT5_COMPRESSION
osg::Texture::REPEAT
osg::Texture::WRAP_S
osg::Texture2D
osg::Texture3D
osg::Timer
osg::Timer_t 
osg::Transform::ABSOLUTE_RF
osg::Uniform
osg::Uniform::BOOL
osg::Uniform::FLOAT
osg::Vec2
osg::Vec2Array
osg::Vec3
osg::Vec3Array
osg::Vec3f
osg::Vec4
osg::Vec4Array
osg::Vec4f




  D:\Development\psim\src\subview\HandledNodesVisitor.cpp (2 hits)
	Line 37: void HandledNodesVisitor::apply(osg::Node &node)
	Line 81: bool HandledNodesVisitor::HandledNodesVisitor::isHandledNode(osg::Node &node)
  D:\Development\psim\src\subview\HandledNodesVisitor.h (3 hits)
	Line 9: class HandledNodesVisitor : public osg::NodeVisitor
	Line 14:     virtual void apply(osg::Node &);
	Line 24:     bool isHandledNode(osg::Node &node);
  D:\Development\psim\src\subview\Harbor.cpp (4 hits)
	Line 147: void Harbor::addLights(std::vector<osg::BoundingBox>* boundingBoxList)
	Line 161: void Harbor::adjustLightPosition(float &X, float &Y, float &Z, std::vector<osg::BoundingBox>* boundingBoxList)
	Line 165:     for (std::vector<osg::BoundingBox>::iterator it = boundingBoxList->begin(); it != boundingBoxList->end(); ++it)
	Line 167:         osg::Vec3 center = it->center();
  D:\Development\psim\src\subview\Harbor.h (2 hits)
	Line 32:     void addLights(std::vector<osg::BoundingBox>* boundingBoxList);
	Line 40:     void adjustLightPosition(float &X, float &Y, float &Z, std::vector<osg::BoundingBox>* boundingBoxList);
  D:\Development\psim\src\subview\HarborNodeVisitor.cpp (41 hits)
	Line 25: HarborNodeVisitor::HarborNodeVisitor() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
	Line 25: HarborNodeVisitor::HarborNodeVisitor() : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_ALL_CHILDREN)
	Line 31: void HarborNodeVisitor::apply(osg::Node& node)
	Line 42:                 osg::Node* childNode = node.asGroup()->getChild(i);
	Line 43:                 childNode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 43:                 childNode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 53:         node.getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 53:         node.getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 67: void HarborNodeVisitor::apply(osg::Geode& geode)
	Line 84: void HarborNodeVisitor::apply(osg::LOD& lod)
	Line 103: void HarborNodeVisitor::checkStateForOverride(osg::StateSet *stateSet)
	Line 110:     osg::StateAttribute *entexture = stateSet->getTextureAttribute(0, osg::StateAttribute::TEXTURE);
	Line 110:     osg::StateAttribute *entexture = stateSet->getTextureAttribute(0, osg::StateAttribute::TEXTURE);
	Line 111:     osg::StateAttribute::GLModeValue enlighting = stateSet->getMode(GL_LIGHTING);
	Line 116:         osg::ref_ptr<osg::Uniform> harborEntextureUniform = new osg::Uniform("entexture", false);
	Line 116:         osg::ref_ptr<osg::Uniform> harborEntextureUniform = new osg::Uniform("entexture", false);
	Line 116:         osg::ref_ptr<osg::Uniform> harborEntextureUniform = new osg::Uniform("entexture", false);
	Line 121:         osg::ref_ptr<osg::Uniform> harborEntextureUniform = new osg::Uniform("entexture", true);
	Line 121:         osg::ref_ptr<osg::Uniform> harborEntextureUniform = new osg::Uniform("entexture", true);
	Line 121:         osg::ref_ptr<osg::Uniform> harborEntextureUniform = new osg::Uniform("entexture", true);
	Line 126:     if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF))
	Line 126:     if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF))
	Line 129:     else if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON))
	Line 129:     else if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON))
	Line 133:     if ((enlighting == osg::StateAttribute::OFF && !mLightingOverrideOn) ||
	Line 134:             enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF) ||
	Line 134:             enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF) ||
	Line 135:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF) ||
	Line 135:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF) ||
	Line 138:         osg::ref_ptr<osg::Uniform> harborEnlightingUniform = new osg::Uniform("enlighting", false);
	Line 138:         osg::ref_ptr<osg::Uniform> harborEnlightingUniform = new osg::Uniform("enlighting", false);
	Line 138:         osg::ref_ptr<osg::Uniform> harborEnlightingUniform = new osg::Uniform("enlighting", false);
	Line 143:     else if ((enlighting == osg::StateAttribute::ON && !mLightingOverrideOff) ||
	Line 144:             enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON) ||
	Line 144:             enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON) ||
	Line 145:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::ON) ||
	Line 145:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::ON) ||
	Line 148:         osg::ref_ptr<osg::Uniform> harborEnlightingUniform = new osg::Uniform("enlighting", true);
	Line 148:         osg::ref_ptr<osg::Uniform> harborEnlightingUniform = new osg::Uniform("enlighting", true);
	Line 148:         osg::ref_ptr<osg::Uniform> harborEnlightingUniform = new osg::Uniform("enlighting", true);
	Line 153: std::vector<osg::BoundingBox>* HarborNodeVisitor::getBoundingBoxes()
  D:\Development\psim\src\subview\HarborNodeVisitor.h (7 hits)
	Line 19: class HarborNodeVisitor : public osg::NodeVisitor
	Line 25:     virtual void apply(osg::Node& node);
	Line 26:     virtual void apply(osg::Geode& geode);
	Line 27:     virtual void apply(osg::LOD& lod);
	Line 29:     void checkStateForOverride(osg::StateSet *stateSet);
	Line 31:     std::vector<osg::BoundingBox>* getBoundingBoxes();
	Line 36:     std::vector<osg::BoundingBox> mBoundingBoxList;
  D:\Development\psim\src\subview\HarborSwitch.cpp (6 hits)
	Line 17: HarborSwitch::HarborSwitch(Vehicle *harbor, osg::Switch *switchNode)
	Line 23: void HarborSwitch::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 23: void HarborSwitch::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 29:             if (((osg::Switch*)node)->getNumChildren() > 1)
	Line 30:                 ((osg::Switch*)node)->setSingleChildOn(pmSwitchInfo->curValue == pmSwitchInfo->onValue);
	Line 34:                 ((osg::Switch*)node)->setValue(0, pmSwitchInfo->curValue == pmSwitchInfo->onValue);
  D:\Development\psim\src\subview\HarborSwitch.h (4 hits)
	Line 19: class HarborSwitch : public osg::NodeCallback
	Line 22:     HarborSwitch(Vehicle *harbor, osg::Switch *switchNode);
	Line 23:     virtual void operator()(osg::Node *, osg::NodeVisitor *);
	Line 23:     virtual void operator()(osg::Node *, osg::NodeVisitor *);
  D:\Development\psim\src\subview\HeadingDB.cpp (5 hits)
	Line 22: HeadingDB::HeadingDB(Vehicle* vehicle, osg::Geode *node) :
	Line 23: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 24: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 29: void HeadingDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 29: void HeadingDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\HeadingDB.h (3 hits)
	Line 21:     HeadingDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\HeadingOrdDB.cpp (5 hits)
	Line 22: HeadingOrdDB::HeadingOrdDB(Vehicle* vehicle, osg::Geode *node) :
	Line 23: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 24: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 29: void HeadingOrdDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 29: void HeadingOrdDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\HeadingOrdDB.h (3 hits)
	Line 21:     HeadingOrdDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\HeadingSourceDB.cpp (5 hits)
	Line 20: HeadingSourceDB::HeadingSourceDB(Vehicle* vehicle, osg::Geode *node) :
	Line 21: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 22: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 28: void HeadingSourceDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 28: void HeadingSourceDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\HeadingSourceDB.h (3 hits)
	Line 21:     HeadingSourceDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\HelpText.cpp (29 hits)
	Line 45:     stateSet = new osg::StateSet;
	Line 48:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 57: osg::BoundingBox HelpText::computeBound() const
	Line 59:     osg::BoundingBox bbox;
	Line 60:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 61:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 65: void HelpText::addToOSG(osg::Group * root)
	Line 67:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 67:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 67:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 83: void HelpText::drawImplementation(osg::RenderInfo& ri) const
	Line 107: void HelpText::drawUsage(osg::RenderInfo& ri)
	Line 137: void HelpText::drawRanScopeType(osg::RenderInfo& ri)
	Line 151: void HelpText::drawSMMTT(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 158: void HelpText::drawRAN(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 165: void HelpText::drawONI(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 174: void HelpText::drawDemo(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 199: void HelpText::drawBoatMovement(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 224: void HelpText::drawScopeControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 284: void HelpText::drawJoystickControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 301: void HelpText::drawEnvironmentalControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 343: void HelpText::drawPrecipitationControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 367: void HelpText::drawSimulationControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 409: void HelpText::drawInformationalControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 425: void HelpText::drawFlyoutControls(double& rXPos, double& rYPos, osg::RenderInfo& ri)
	Line 447: void HelpText::drawDebug(osg::RenderInfo& ri)
	Line 961: void HelpText::drawContactDebugPages(osg::RenderInfo& ri)
	Line 1020: void HelpText::drawProgrammers(osg::RenderInfo& ri)
	Line 1064: void HelpText::printLine(std::string text, double *x, double *y, double yOffset, osg::RenderInfo& ri)
  D:\Development\psim\src\subview\HelpText.h (31 hits)
	Line 18: class HelpText : public osg::Geometry
	Line 23:     HelpText(const HelpText& HelpText, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 23:     HelpText(const HelpText& HelpText, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 24:     osg::Geometry(HelpText, copyop)
	Line 29:     virtual osg::BoundingBox computeBound() const;
	Line 33:     void drawImplementation(osg::RenderInfo& ri) const;
	Line 34:     void addToOSG(osg::Group * root);
	Line 39:     void printLine(std::string text, double *x, double *y, double yOffset, osg::RenderInfo& ri);
	Line 45:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 45:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 46:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 46:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 47:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 47:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 57:     void drawRanScopeType(osg::RenderInfo& ri);
	Line 58:     void drawUsage(osg::RenderInfo& ri);
	Line 59:     void drawProgrammers(osg::RenderInfo& ri);
	Line 60:     void drawDebug(osg::RenderInfo& ri);
	Line 61:     void drawContactDebugPages(osg::RenderInfo& ri);
	Line 63:     void drawDemo(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 64:     void drawSMMTT(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 65:     void drawRAN(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 66:     void drawONI(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 68:     void drawBoatMovement(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 69:     void drawScopeControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 70:     void drawJoystickControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 71:     void drawEnvironmentalControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 72:     void drawPrecipitationControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 73:     void drawSimulationControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 74:     void drawInformationalControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
	Line 75:     void drawFlyoutControls(double& rXPos, double& rYPos, osg::RenderInfo& ri);
  D:\Development\psim\src\subview\Hud.cpp (12 hits)
	Line 40: osg::BoundingBox Hud::computeBound() const
	Line 42:     osg::BoundingBox bbox;
	Line 43:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 44:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 48: void Hud::addDrawable(osg::Geode * geode)
	Line 53: void Hud::addToOSG(osg::Group * root)
	Line 55:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 55:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 55:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 61: void Hud::drawImplementation(osg::RenderInfo& ri) const
	Line 87:     stateSet = new osg::StateSet;
	Line 90:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
  D:\Development\psim\src\subview\Hud.h (14 hits)
	Line 17: class Hud : public osg::Geometry
	Line 22:     Hud(const Hud& Hud, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 22:     Hud(const Hud& Hud, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 23:     osg::Geometry(Hud, copyop)
	Line 28:     virtual osg::BoundingBox computeBound() const;
	Line 32:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 33:     virtual void addToOSG(osg::Group * root);
	Line 34:     virtual void addDrawable(osg::Geode * geode);
	Line 47:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 47:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 48:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 48:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 49:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 49:     osg::ref_ptr<osg::StateSet> stateSet;
  D:\Development\psim\src\subview\LandLeeTexture.h (2 hits)
	Line 23:     osg::Texture2D *landTexture;
	Line 24:     //osg::Image * landImage;
  D:\Development\psim\src\subview\LeeManager.cpp (32 hits)
	Line 80:         osg::Vec2 ship_dir = osg::Vec2(nContactPos[i][0], nContactPos[i][1]);
	Line 80:         osg::Vec2 ship_dir = osg::Vec2(nContactPos[i][0], nContactPos[i][1]);
	Line 81:         osg::Vec2 ship_dir_tan = osg::Vec2(-nContactDirSize[i][1], nContactDirSize[i][0]);
	Line 81:         osg::Vec2 ship_dir_tan = osg::Vec2(-nContactDirSize[i][1], nContactDirSize[i][0]);
	Line 86:         osg::Vec2 pw_contact = osg::Vec2(positionWorld[0] - closeContactPos[0], positionWorld[1] - closeContactPos[1]);
	Line 86:         osg::Vec2 pw_contact = osg::Vec2(positionWorld[0] - closeContactPos[0], positionWorld[1] - closeContactPos[1]);
	Line 92:             osg::Vec2 lee_dir = osg::Vec2(windDirection[0], windDirection[1]);
	Line 92:             osg::Vec2 lee_dir = osg::Vec2(windDirection[0], windDirection[1]);
	Line 98:             double sgn0 = osg::sign(lee_dir * ship_dir_tan);
	Line 99:             double sgn1 = osg::sign(lee_dir * ship_dir);
	Line 102:             double dist_along_shipline_fade = osg::clampBetween(0.05 * sgn0*dist_along_shipline, 0.0, 1.0);
	Line 104:             osg::Vec2 pw_contact_tip = osg::Vec2(
	Line 104:             osg::Vec2 pw_contact_tip = osg::Vec2(
	Line 109:             double dist_along_leeline_fade = osg::clampBetween(0.05 * dist_along_leeline_tip, 0.0, 1.0);
	Line 124:             lee_atten *= osg::clampBetween(1. - mag * lee_dist_atten * dist_along_shipline_fade * dist_along_leeline_fade / (1. + blend_width_recip * taperDist), 0.0, 1.0);
	Line 273:     geo->lees_nearContactPosUniform->set(osg::Vec4f(nearContactPos[0][0], nearContactPos[0][1], nearContactPos[0][2], nearContactPos[0][3]));
	Line 274:     geo->lees_nearContactDirSizeUniform->set(osg::Vec4f(nearContactDirSize[0][0], nearContactDirSize[0][1], nearContactDirSize[0][2], nearContactDirSize[0][3]));
	Line 276:     geo->lees_landLeeCenterUniform->set(osg::Vec2f(landLeeCenter[0], landLeeCenter[1]));
	Line 277:     geo->lees_global_lee_dirUniform->set(osg::Vec2f(windDirection[0], windDirection[1]));
	Line 411:     landLeeTexture.landTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 411:     landLeeTexture.landTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 412:     landLeeTexture.landTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 412:     landLeeTexture.landTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 413:     landLeeTexture.landTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 413:     landLeeTexture.landTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 414:     landLeeTexture.landTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 414:     landLeeTexture.landTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 420:         osg::ref_ptr<osg::Image> landLeeImg = new osg::Image;
	Line 420:         osg::ref_ptr<osg::Image> landLeeImg = new osg::Image;
	Line 420:         osg::ref_ptr<osg::Image> landLeeImg = new osg::Image;
	Line 436: void LeeManager::setLandLeeTexture(osg::Texture2D *texture, osg::Image *image)
	Line 436: void LeeManager::setLandLeeTexture(osg::Texture2D *texture, osg::Image *image)
  D:\Development\psim\src\subview\LeeManager.h (4 hits)
	Line 40:     void setLandLeeTexture(osg::Texture2D *texture, osg::Image *image);
	Line 40:     void setLandLeeTexture(osg::Texture2D *texture, osg::Image *image);
	Line 95:     osg::ref_ptr<osg::Uniform> wakePositionsUniform;
	Line 95:     osg::ref_ptr<osg::Uniform> wakePositionsUniform;
  D:\Development\psim\src\subview\LightDetectVisitor.cpp (1 hit)
	Line 22: void LightDetectVisitor::apply(osg::Node &node)
  D:\Development\psim\src\subview\LightDetectVisitor.h (2 hits)
	Line 16: class LightDetectVisitor : public osg::NodeVisitor
	Line 20:     virtual void apply(osg::Node &node);
  D:\Development\psim\src\subview\LightInfo.cpp (2 hits)
	Line 157: osg::Vec3f LightInfo::getPosition() const
	Line 159:     return osg::Vec3f(mX, mY, mZ);
  D:\Development\psim\src\subview\LightInfo.h (1 hit)
	Line 51:     osg::Vec3f getPosition() const;
  D:\Development\psim\src\subview\LightSampleDump.cpp (2 hits)
	Line 16: LightSampleDump::LightSampleDump(osg::Image* _envImage, std::string _filename)
	Line 22: void LightSampleDump::operator()(const osg::Camera& camera) const
  D:\Development\psim\src\subview\LightSampleDump.h (5 hits)
	Line 16: class LightSampleDump : public osg::Camera::DrawCallback
	Line 19:     LightSampleDump(osg::Image* _envImage, std::string _filename);
	Line 21:     virtual void operator()(const osg::Camera& camera) const;
	Line 25:     osg::ref_ptr<osg::Image> envImage;
	Line 25:     osg::ref_ptr<osg::Image> envImage;
  D:\Development\psim\src\subview\LightSampleMapUpdateCallback.cpp (39 hits)
	Line 29: leftImage(new osg::Image()),
	Line 30: rightImage(new osg::Image()),
	Line 31: frontImage(new osg::Image()),
	Line 32: backImage(new osg::Image()),
	Line 33: topImage(new osg::Image()),
	Line 79: void LightSampleMapUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 79: void LightSampleMapUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 189: osg::Camera* LightSampleMapUpdateCallback::createCamera(const ImageData& imageData, int imageSize, osg::Image* envImage, SkyDome* skydome, PrecomputeAtmoOp* precomputeOp, std::string name)
	Line 189: osg::Camera* LightSampleMapUpdateCallback::createCamera(const ImageData& imageData, int imageSize, osg::Image* envImage, SkyDome* skydome, PrecomputeAtmoOp* precomputeOp, std::string name)
	Line 191:     osg::Camera* cam = new osg::Camera();
	Line 191:     osg::Camera* cam = new osg::Camera();
	Line 194:         osg::ref_ptr<osg::Texture2D> fogTexture;
	Line 194:         osg::ref_ptr<osg::Texture2D> fogTexture;
	Line 197:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(11, fogTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 197:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(11, fogTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 201:     //	cam->setClearColor(osg::Vec4f(1.0, 0.0, 0.0, 1.0f));
	Line 205:     osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(imageSize, imageSize));
	Line 205:     osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(imageSize, imageSize));
	Line 205:     osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(imageSize, imageSize));
	Line 208:     cam->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 209:     cam->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 211:     osg::Vec3 center(0.0, 0.0, 10.0);
	Line 212:     osg::Matrix viewMatrix;
	Line 215:     cam->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	Line 224: osg::Group* LightSampleMapUpdateCallback::createLightSampleGraph(PrecomputeAtmoOp* precomputeOp, SkyDome* skydome, const std::string processingScriptLocation)
	Line 228:     osg::Group* lightSampleGroup = new osg::Group();
	Line 228:     osg::Group* lightSampleGroup = new osg::Group();
	Line 232:         ImageData(osg::Vec3(1, 0, 0), osg::Vec3(0, 0, 1)), // +X   // right       
	Line 232:         ImageData(osg::Vec3(1, 0, 0), osg::Vec3(0, 0, 1)), // +X   // right       
	Line 233:         ImageData(osg::Vec3(-1, 0, 0), osg::Vec3(0, 0, 1)), // -X  // left
	Line 233:         ImageData(osg::Vec3(-1, 0, 0), osg::Vec3(0, 0, 1)), // -X  // left
	Line 234:         ImageData(osg::Vec3(0, 1, 0), osg::Vec3(0, 0, 1)), // +Y // front 
	Line 234:         ImageData(osg::Vec3(0, 1, 0), osg::Vec3(0, 0, 1)), // +Y // front 
	Line 235:         ImageData(osg::Vec3(0, -1, 0), osg::Vec3(0, 0, 1)), // -Y // back
	Line 235:         ImageData(osg::Vec3(0, -1, 0), osg::Vec3(0, 0, 1)), // -Y // back
	Line 236:         ImageData(osg::Vec3(0, 0, 1), osg::Vec3(0, -1, 0)), // +Z   // top
	Line 236:         ImageData(osg::Vec3(0, 0, 1), osg::Vec3(0, -1, 0)), // +Z   // top
	Line 237:         ImageData(osg::Vec3(0, 0, -1), osg::Vec3(0, -1, 0)) // -Z   // bottom			                
	Line 237:         ImageData(osg::Vec3(0, 0, -1), osg::Vec3(0, -1, 0)) // -Z   // bottom			                
  D:\Development\psim\src\subview\LightSampleMapUpdateCallback.h (18 hits)
	Line 20: class LightSampleMapUpdateCallback : public osg::NodeCallback
	Line 26:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 26:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 30:     static osg::Group* createLightSampleGraph(PrecomputeAtmoOp* precomputeOp, SkyDome* skydome, const std::string processingScriptLocation);
	Line 33:     typedef std::pair<osg::Vec3, osg::Vec3> ImageData;
	Line 33:     typedef std::pair<osg::Vec3, osg::Vec3> ImageData;
	Line 35:     osg::ref_ptr<osg::Image> frontImage;
	Line 35:     osg::ref_ptr<osg::Image> frontImage;
	Line 36:     osg::ref_ptr<osg::Image> backImage;
	Line 36:     osg::ref_ptr<osg::Image> backImage;
	Line 37:     osg::ref_ptr<osg::Image> leftImage;
	Line 37:     osg::ref_ptr<osg::Image> leftImage;
	Line 38:     osg::ref_ptr<osg::Image> rightImage;
	Line 38:     osg::ref_ptr<osg::Image> rightImage;
	Line 39:     osg::ref_ptr<osg::Image> topImage;
	Line 39:     osg::ref_ptr<osg::Image> topImage;
	Line 48:     static osg::Camera* createCamera(const ImageData& imageData, int imageSize, osg::Image* envImage, SkyDome* skydome, PrecomputeAtmoOp* precomputeOp, std::string name = "lightsample");
	Line 48:     static osg::Camera* createCamera(const ImageData& imageData, int imageSize, osg::Image* envImage, SkyDome* skydome, PrecomputeAtmoOp* precomputeOp, std::string name = "lightsample");
  D:\Development\psim\src\subview\LightSourceCallback.cpp (16 hits)
	Line 20: LightSourceCallback::LightSourceCallback(Vehicle *vehicle, LightInfo *light, osg::Vec3 pos) :
	Line 27: void LightSourceCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 27: void LightSourceCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 29:     osg::Geode* lightGeode = dynamic_cast<osg::Geode*> (node); // dynamic cast will return null if node isn't a geode
	Line 29:     osg::Geode* lightGeode = dynamic_cast<osg::Geode*> (node); // dynamic cast will return null if node isn't a geode
	Line 36:             osg::Vec3 localPos = mPos; //lightGeode->computeBound().center();            
	Line 37:             osg::Vec3 worldPos = osg::computeLocalToWorld(nv->getNodePath()).preMult(localPos);
	Line 37:             osg::Vec3 worldPos = osg::computeLocalToWorld(nv->getNodePath()).preMult(localPos);
	Line 41:             osg::Vec3 color = osg::Vec3(0., 0., 0.);
	Line 41:             osg::Vec3 color = osg::Vec3(0., 0., 0.);
	Line 44:                 color = osg::Vec3(0., 1., 0.);
	Line 46:                 color = osg::Vec3(1., 0., 0.);
	Line 48:                 color = osg::Vec3(1., 1., 1.);
	Line 50:                 color = osg::Vec3(1., 0., 1.);
	Line 52:                 color = osg::Vec3(0., 0., 1.);
	Line 54:                 color = osg::Vec3(0., 0., 0.);
  D:\Development\psim\src\subview\LightSourceCallback.h (5 hits)
	Line 18: class LightSourceCallback : public osg::NodeCallback
	Line 21:     LightSourceCallback(Vehicle *vehicle, LightInfo *light, osg::Vec3 pos);
	Line 22:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	Line 22:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	Line 27:     osg::Vec3 mPos;
  D:\Development\psim\src\subview\LightSystemCull.cpp (3 hits)
	Line 14: bool LightSystemCull::cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const
	Line 14: bool LightSystemCull::cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const
	Line 14: bool LightSystemCull::cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const
  D:\Development\psim\src\subview\LightSystemCull.h (4 hits)
	Line 16: class LightSystemCull : public osg::Drawable::CullCallback
	Line 20:     virtual bool cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const;
	Line 20:     virtual bool cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const;
	Line 20:     virtual bool cull(osg::NodeVisitor* nv, osg::Drawable* drawable, osg::RenderInfo* renderInfo) const;
  D:\Development\psim\src\subview\LightSystemStateSetUpdate.cpp (11 hits)
	Line 22:     eyeLoc = new osg::Uniform("eye", osg::Vec3(0.0, 0.0, 0.0));
	Line 22:     eyeLoc = new osg::Uniform("eye", osg::Vec3(0.0, 0.0, 0.0));
	Line 23:     myModelOriginLoc = new osg::Uniform("myModelOrigin", osg::Vec3(0.0, 0.0, 0.0));
	Line 23:     myModelOriginLoc = new osg::Uniform("myModelOrigin", osg::Vec3(0.0, 0.0, 0.0));
	Line 24:     mySystemHeadingLoc = new osg::Uniform("mySystemHeading", 0.0f);
	Line 27: void LightSystemStateSetUpdate::operator()(osg::StateSet * ss, osg::NodeVisitor * nv)
	Line 27: void LightSystemStateSetUpdate::operator()(osg::StateSet * ss, osg::NodeVisitor * nv)
	Line 34:     osg::PolygonOffset * po = dynamic_cast<osg::PolygonOffset *> (ss->getAttribute(osg::StateAttribute::POLYGONOFFSET));
	Line 34:     osg::PolygonOffset * po = dynamic_cast<osg::PolygonOffset *> (ss->getAttribute(osg::StateAttribute::POLYGONOFFSET));
	Line 34:     osg::PolygonOffset * po = dynamic_cast<osg::PolygonOffset *> (ss->getAttribute(osg::StateAttribute::POLYGONOFFSET));
	Line 42: void LightSystemStateSetUpdate::setModelOrigin(osg::Vec3 modelOrigin)
  D:\Development\psim\src\subview\LightSystemStateSetUpdate.h (10 hits)
	Line 21: class LightSystemStateSetUpdate : public osg::StateSet::Callback
	Line 25:     virtual void operator()(osg::StateSet *, osg::NodeVisitor *);
	Line 25:     virtual void operator()(osg::StateSet *, osg::NodeVisitor *);
	Line 26:     void setModelOrigin(osg::Vec3 modelOrigin);
	Line 28:     osg::ref_ptr<osg::Uniform> mySystemHeadingLoc;
	Line 28:     osg::ref_ptr<osg::Uniform> mySystemHeadingLoc;
	Line 29:     osg::ref_ptr<osg::Uniform> myModelOriginLoc;
	Line 29:     osg::ref_ptr<osg::Uniform> myModelOriginLoc;
	Line 30:     osg::ref_ptr<osg::Uniform> eyeLoc;
	Line 30:     osg::ref_ptr<osg::Uniform> eyeLoc;
  D:\Development\psim\src\subview\LightSystemUpdate.cpp (57 hits)
	Line 38:     pmVertices = new osg::Vec3Array;
	Line 41:     pmPositions = new osg::Vec4Array;
	Line 44:     pmAttribs1 = new osg::Vec4Array;
	Line 47:     pmTexCoords0 = new osg::Vec2Array;
	Line 50:     pmIndices = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 50:     pmIndices = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 53:     osg::Geode * geode;
	Line 54:     osg::Vec3 pos;
	Line 55:     std::vector<osg::Geode *> * lights = visitor.getLights();
	Line 56:     std::vector<osg::Geode *>::iterator it;
	Line 158:     pmVertices->push_back(osg::Vec3(scale, scale, 0.f));
	Line 159:     pmVertices->push_back(osg::Vec3(-scale, scale, 0.f));
	Line 160:     pmVertices->push_back(osg::Vec3(-scale, -scale, 0.f));
	Line 161:     pmVertices->push_back(osg::Vec3(scale, -scale, 0.f));
	Line 163:     pmPositions->push_back(osg::Vec4(newLight->mX, newLight->mY, newLight->mZ, newLight->mTexture));
	Line 164:     pmPositions->push_back(osg::Vec4(newLight->mX, newLight->mY, newLight->mZ, newLight->mTexture));
	Line 165:     pmPositions->push_back(osg::Vec4(newLight->mX, newLight->mY, newLight->mZ, newLight->mTexture));
	Line 166:     pmPositions->push_back(osg::Vec4(newLight->mX, newLight->mY, newLight->mZ, newLight->mTexture));
	Line 168:     pmAttribs1->push_back(osg::Vec4(newLight->mMinAngle, newLight->mMaxAngle, newLight->mIntensity, newLight->mRange));
	Line 169:     pmAttribs1->push_back(osg::Vec4(newLight->mMinAngle, newLight->mMaxAngle, newLight->mIntensity, newLight->mRange));
	Line 170:     pmAttribs1->push_back(osg::Vec4(newLight->mMinAngle, newLight->mMaxAngle, newLight->mIntensity, newLight->mRange));
	Line 171:     pmAttribs1->push_back(osg::Vec4(newLight->mMinAngle, newLight->mMaxAngle, newLight->mIntensity, newLight->mRange));
	Line 173:     pmTexCoords0->push_back(osg::Vec2(1.f, 1.f));
	Line 174:     pmTexCoords0->push_back(osg::Vec2(0.f, 1.f));
	Line 175:     pmTexCoords0->push_back(osg::Vec2(0.f, 0.f));
	Line 176:     pmTexCoords0->push_back(osg::Vec2(1.f, 0.f));
	Line 187: void LightSystemUpdate::update(osg::NodeVisitor * nv, osg::Drawable * drawable)
	Line 187: void LightSystemUpdate::update(osg::NodeVisitor * nv, osg::Drawable * drawable)
	Line 189:     osg::Geometry * ls = dynamic_cast<osg::Geometry *> (drawable);
	Line 189:     osg::Geometry * ls = dynamic_cast<osg::Geometry *> (drawable);
	Line 229:             pmVertices->push_back(osg::Vec3(scale, scale, 0.f));
	Line 230:             pmVertices->push_back(osg::Vec3(-scale, scale, 0.f));
	Line 231:             pmVertices->push_back(osg::Vec3(-scale, -scale, 0.f));
	Line 232:             pmVertices->push_back(osg::Vec3(scale, -scale, 0.f));
	Line 234:             pmPositions->push_back(osg::Vec4(light->mX, light->mY, light->mZ, light->mTexture));
	Line 235:             pmPositions->push_back(osg::Vec4(light->mX, light->mY, light->mZ, light->mTexture));
	Line 236:             pmPositions->push_back(osg::Vec4(light->mX, light->mY, light->mZ, light->mTexture));
	Line 237:             pmPositions->push_back(osg::Vec4(light->mX, light->mY, light->mZ, light->mTexture));
	Line 239:             pmAttribs1->push_back(osg::Vec4(light->mMinAngle, light->mMaxAngle, light->mIntensity, light->mRange));
	Line 240:             pmAttribs1->push_back(osg::Vec4(light->mMinAngle, light->mMaxAngle, light->mIntensity, light->mRange));
	Line 241:             pmAttribs1->push_back(osg::Vec4(light->mMinAngle, light->mMaxAngle, light->mIntensity, light->mRange));
	Line 242:             pmAttribs1->push_back(osg::Vec4(light->mMinAngle, light->mMaxAngle, light->mIntensity, light->mRange));
	Line 244:             pmTexCoords0->push_back(osg::Vec2(1.f, 1.f));
	Line 245:             pmTexCoords0->push_back(osg::Vec2(0.f, 1.f));
	Line 246:             pmTexCoords0->push_back(osg::Vec2(0.f, 0.f));
	Line 247:             pmTexCoords0->push_back(osg::Vec2(1.f, 0.f));
	Line 290:     osg::Vec3f contactLoc = pmVehicle->getContactLoc();
	Line 291:     osg::Vec3f modelOrigin = pmVehicle->getModelOrigin();
	Line 308: void LightSystemUpdate::flattenVertices(osg::Drawable * drawable)
	Line 310:     osg::Geometry * ls = dynamic_cast<osg::Geometry *> (drawable);
	Line 310:     osg::Geometry * ls = dynamic_cast<osg::Geometry *> (drawable);
	Line 319:     osg::Vec3f contactLoc = pmVehicle->getContactLoc();
	Line 320:     osg::Vec3f modelOrigin = pmVehicle->getModelOrigin();
	Line 336:         pmVertices->push_back(osg::Vec3(1.f, 1.f, 0.f));
	Line 337:         pmVertices->push_back(osg::Vec3(-1.f, 1.f, 0.f));
	Line 338:         pmVertices->push_back(osg::Vec3(-1.f, -1.f, 0.f));
	Line 339:         pmVertices->push_back(osg::Vec3(1.f, -1.f, 0.f));
  D:\Development\psim\src\subview\LightSystemUpdate.h (14 hits)
	Line 27: class LightSystemUpdate : public osg::Drawable::UpdateCallback
	Line 32:     virtual void update(osg::NodeVisitor * nv, osg::Drawable * drawable);
	Line 32:     virtual void update(osg::NodeVisitor * nv, osg::Drawable * drawable);
	Line 37:     osg::ref_ptr<osg::Vec3Array> pmVertices;
	Line 37:     osg::ref_ptr<osg::Vec3Array> pmVertices;
	Line 38:     osg::ref_ptr<osg::Vec4Array> pmPositions;
	Line 38:     osg::ref_ptr<osg::Vec4Array> pmPositions;
	Line 39:     osg::ref_ptr<osg::Vec2Array> pmTexCoords0;
	Line 39:     osg::ref_ptr<osg::Vec2Array> pmTexCoords0;
	Line 40:     osg::ref_ptr<osg::Vec4Array> pmAttribs1;
	Line 40:     osg::ref_ptr<osg::Vec4Array> pmAttribs1;
	Line 41:     osg::ref_ptr<osg::DrawElementsUInt> pmIndices;
	Line 41:     osg::ref_ptr<osg::DrawElementsUInt> pmIndices;
	Line 44:     void flattenVertices(osg::Drawable * drawable);
  D:\Development\psim\src\subview\Line.h (1 hit)
	Line 7: class Line : public osg::Geode
  D:\Development\psim\src\subview\LineCallback.cpp (2 hits)
	Line 14: void LineCallback::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 14: void LineCallback::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\LineCallback.h (3 hits)
	Line 15: class LineCallback : public osg::NodeCallback
	Line 17: 	virtual void operator ()(osg::Node * node, osg::NodeVisitor * nv);
	Line 17: 	virtual void operator ()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\LinesManager.cpp (27 hits)
	Line 32: lines(new osg::Group)
	Line 36: void LinesManager::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 36: void LinesManager::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 41:         osg::Group * linesGrp = dynamic_cast<osg::Group *> (node);
	Line 41:         osg::Group * linesGrp = dynamic_cast<osg::Group *> (node);
	Line 69:                 osg::ref_ptr<Line> currLine = (Line*) (lines->getChild(jj));
	Line 96:                 osg::ref_ptr<Line> line = generateLine(&(p_line[ii]), lines->getNumChildren() + 1);
	Line 112:         osg::ref_ptr<Line> currLine = (Line*) (lines->getChild(jj));
	Line 135:         g->getOrCreateStateSet()->addUniform(new osg::Uniform("ropetex", 0));
	Line 138:         osg::ref_ptr<osg::Texture2D> texture = RopesManager::getInstance()->getTexture(lineStruct->LineType);
	Line 138:         osg::ref_ptr<osg::Texture2D> texture = RopesManager::getInstance()->getTexture(lineStruct->LineType);
	Line 140:         g->getOrCreateStateSet()->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON);
	Line 141:         g->getOrCreateStateSet()->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	Line 142:         g->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::ON);
	Line 143:         g->getOrCreateStateSet()->setAttributeAndModes(RopesManager::getInstance()->blend, osg::StateAttribute::ON);
	Line 145:         g->getOrCreateStateSet()->setAttributeAndModes(RopesManager::getInstance()->depth, osg::StateAttribute::ON);
	Line 176: osg::Geometry* LinesManager::getRope(int segs, Cleat * start, Cleat * end, float len)
	Line 178:     osg::Geometry * geometry = new osg::Geometry;
	Line 178:     osg::Geometry * geometry = new osg::Geometry;
	Line 188:     geometry->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLE_STRIP, 0, 2 * (rope->segments + 1)));
	Line 189:     geometry->addPrimitiveSet(new osg::DrawArrays(GL_TRIANGLE_STRIP, 2 * (rope->segments + 1), 2 * (rope->segments + 1)));
	Line 190:     geometry->getOrCreateStateSet()->addUniform(new osg::Uniform("wStart", start->getWorldPos()));
	Line 191:     geometry->getOrCreateStateSet()->addUniform(new osg::Uniform("wEnd", end->getWorldPos()));
	Line 192:     geometry->getOrCreateStateSet()->addUniform(new osg::Uniform("segments", (float) (rope->segments)));
	Line 193:     geometry->getOrCreateStateSet()->addUniform(new osg::Uniform("ropelength", rope->length));
	Line 194:     geometry->getOrCreateStateSet()->addUniform(new osg::Uniform("ropewidth", rope->width));
	Line 195:     geometry->getOrCreateStateSet()->addUniform(new osg::Uniform("lightCoeff", 1.f));
  D:\Development\psim\src\subview\LinesManager.h (6 hits)
	Line 15: class LinesManager : public osg::NodeCallback
	Line 17:     osg::ref_ptr<osg::Group> lines;
	Line 17:     osg::ref_ptr<osg::Group> lines;
	Line 25:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 25:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 33:     osg::Geometry* getRope(int segs, Cleat * start, Cleat * end, float len);
  D:\Development\psim\src\subview\LoadingScreen.cpp (8 hits)
	Line 79:     mpStateSet = new osg::StateSet;
	Line 82:     mpStateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 91: void LoadingScreen::addDrawable(osg::Geode *geode)
	Line 97: osg::BoundingBox LoadingScreen::computeBound() const
	Line 99:     osg::BoundingBox bbox;
	Line 100:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 101:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 166: void LoadingScreen::drawImplementation(osg::RenderInfo& ri) const
  D:\Development\psim\src\subview\LoadingScreen.h (13 hits)
	Line 18: class LoadingScreen : public osg::Geometry
	Line 54:     LoadingScreen(const LoadingScreen& LoadingScreen, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 54:     LoadingScreen(const LoadingScreen& LoadingScreen, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 55:     osg::Geometry(LoadingScreen, copyop)
	Line 63:     virtual void addDrawable(osg::Geode *geode);
	Line 64:     virtual osg::BoundingBox computeBound() const;
	Line 69:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 75:     osg::ref_ptr<osg::RefMatrix> mpProjectionMatrix;
	Line 75:     osg::ref_ptr<osg::RefMatrix> mpProjectionMatrix;
	Line 76:     osg::ref_ptr<osg::RefMatrix> mpModelviewMatrix;
	Line 76:     osg::ref_ptr<osg::RefMatrix> mpModelviewMatrix;
	Line 77:     osg::ref_ptr<osg::StateSet> mpStateSet;
	Line 77:     osg::ref_ptr<osg::StateSet> mpStateSet;
  D:\Development\psim\src\subview\MainCameraFinalDrawCallback.cpp (2 hits)
	Line 13:         bool *agcOn, bool *polarity, float *gamma, osg::Vec2 *border, int pboSize)
	Line 23: void MainCameraFinalDrawCallback::operator()(osg::RenderInfo& renderInfo) const
  D:\Development\psim\src\subview\MainCameraFinalDrawCallback.h (2 hits)
	Line 15:                                 bool *agcOn, bool *polarity, float *gamma, osg::Vec2 *border, int pboSize = 2);
	Line 18:     virtual void operator()(osg::RenderInfo& renderInfo) const;
  D:\Development\psim\src\subview\ManualMastRORModeLightUpdate.cpp (1 hit)
	Line 27:         originalPosition = osg::Vec3(light->mX, light->mY, light->mZ);
  D:\Development\psim\src\subview\ManualMastRORModeLightUpdate.h (1 hit)
	Line 32:     osg::Vec3 originalPosition;
  D:\Development\psim\src\subview\ManualRudderRORModeLightUpdate.cpp (1 hit)
	Line 22:         originalPosition = osg::Vec3(light->mX, light->mY, light->mZ);
  D:\Development\psim\src\subview\ManualRudderRORModeLightUpdate.h (2 hits)
	Line 29:     osg::Vec3 originalPosition;
	Line 30:     osg::Vec3 rudderPivotPosition;
  D:\Development\psim\src\subview\Marker.cpp (3 hits)
	Line 17:     osg::ref_ptr<osg::Uniform> enlightingUniform = new osg::Uniform("enlighting", false);
	Line 17:     osg::ref_ptr<osg::Uniform> enlightingUniform = new osg::Uniform("enlighting", false);
	Line 17:     osg::ref_ptr<osg::Uniform> enlightingUniform = new osg::Uniform("enlighting", false);
  D:\Development\psim\src\subview\MarkReleaseOp.cpp (1 hit)
	Line 25: void MarkReleaseOp::operator()(osg::Object* obj)
  D:\Development\psim\src\subview\MarkReleaseOp.h (2 hits)
	Line 13: class MarkReleaseOp : public osg::Operation
	Line 18:     void operator()(osg::Object* obj);
  D:\Development\psim\src\subview\MastCullCallback.cpp (3 hits)
	Line 25: bool MastCullCallback::cull(osg::NodeVisitor * nv, osg::Drawable * drawable, osg::RenderInfo * renderInfo) const
	Line 25: bool MastCullCallback::cull(osg::NodeVisitor * nv, osg::Drawable * drawable, osg::RenderInfo * renderInfo) const
	Line 25: bool MastCullCallback::cull(osg::NodeVisitor * nv, osg::Drawable * drawable, osg::RenderInfo * renderInfo) const
  D:\Development\psim\src\subview\MastCullCallback.h (4 hits)
	Line 14: class MastCullCallback : public osg::Drawable::Drawable::CullCallback
	Line 20:     virtual bool cull(osg::NodeVisitor * nv, osg::Drawable * drawable, osg::RenderInfo * renderInfo) const;
	Line 20:     virtual bool cull(osg::NodeVisitor * nv, osg::Drawable * drawable, osg::RenderInfo * renderInfo) const;
	Line 20:     virtual bool cull(osg::NodeVisitor * nv, osg::Drawable * drawable, osg::RenderInfo * renderInfo) const;
  D:\Development\psim\src\subview\MastCullCallbackVisitor.cpp (5 hits)
	Line 22: void MastCullCallbackVisitor::apply(osg::Geode &node)
	Line 25:     osg::Geode::DrawableList & dl = const_cast<osg::Geode::DrawableList &> (node.getDrawableList());
	Line 25:     osg::Geode::DrawableList & dl = const_cast<osg::Geode::DrawableList &> (node.getDrawableList());
	Line 26:     osg::Geode::DrawableList::iterator it = dl.begin();
	Line 27:     osg::Geode::DrawableList::iterator end = dl.end();
  D:\Development\psim\src\subview\MastCullCallbackVisitor.h (2 hits)
	Line 13: class MastCullCallbackVisitor : public osg::NodeVisitor
	Line 18:     virtual void apply(osg::Geode &node);
  D:\Development\psim\src\subview\MastData.h (8 hits)
	Line 18:         mastXform = new osg::MatrixTransform;
	Line 19:         /*mastGrp = new osg::Group;*/ mat = new osg::Matrix;
	Line 19:         /*mastGrp = new osg::Group;*/ mat = new osg::Matrix;
	Line 31:     osg::ref_ptr< osg::MatrixTransform > mastXform;
	Line 31:     osg::ref_ptr< osg::MatrixTransform > mastXform;
	Line 32:     //osg::ref_ptr< osg::Group > mastGrp;
	Line 32:     //osg::ref_ptr< osg::Group > mastGrp;
	Line 34:     osg::Matrix *mat;
  D:\Development\psim\src\subview\MergeGeodesVisitor.cpp (15 hits)
	Line 23: void MergeGeodesVisitor::apply(osg::Group& group)
	Line 25:     if (typeid (group) == typeid (osg::Group)) mergeGeodes(group);
	Line 29: bool MergeGeodesVisitor::mergeGeodes(osg::Group& group)
	Line 31:     typedef std::vector< osg::Geode* > DuplicateList;
	Line 32:     typedef std::map<osg::Geode*, DuplicateList, GeodeComparator> GeodeDuplicateMap;
	Line 35:     osg::NodeList children;
	Line 50:         osg::Node* child = children[i].get();
	Line 53:         if (typeid (*child) == typeid (osg::Geode) && child->getNodeMask() != 0x1)
	Line 55:             osg::Geode* geode = static_cast<osg::Geode*> (child);
	Line 55:             osg::Geode* geode = static_cast<osg::Geode*> (child);
	Line 75:             osg::Geode* lhs = itr->second[0];
	Line 84:                 osg::Geode* rhs = *dupItr;
	Line 90:             osg::Geode* lhs = itr->second[0];
	Line 100: bool MergeGeodesVisitor::mergeGeode(osg::Geode& lhs, osg::Geode& rhs)
	Line 100: bool MergeGeodesVisitor::mergeGeode(osg::Geode& lhs, osg::Geode& rhs)
  D:\Development\psim\src\subview\MergeGeodesVisitor.h (5 hits)
	Line 10: class MergeGeodesVisitor : public osg::NodeVisitor
	Line 16:     virtual void apply(osg::Group &);
	Line 17:     bool mergeGeodes(osg::Group& group);
	Line 18:     bool mergeGeode(osg::Geode& lhs, osg::Geode& rhs);
	Line 18:     bool mergeGeode(osg::Geode& lhs, osg::Geode& rhs);
  D:\Development\psim\src\subview\MiniBackgroundLoader.cpp (214 hits)
	Line 152:             osg::ref_ptr<osgDB::ReaderWriter::Options> options = new osgDB::ReaderWriter::ReaderWriter::Options;
	Line 247:                     std::vector <osg::Node *> *bad = visitor.getBadNodes();
	Line 248:                     std::vector<osg::Node *>::iterator it = bad->begin();
	Line 249:                     std::vector<osg::Node *>::iterator end = bad->end();
	Line 252:                         osg::ref_ptr<osg::Node> n = *it;
	Line 252:                         osg::ref_ptr<osg::Node> n = *it;
	Line 258:                 osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 258:                 osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 258:                 osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 287:                 osg::ref_ptr<osg::Node> newModelNode = (osg::Group*)grp->getChild(0);
	Line 287:                 osg::ref_ptr<osg::Node> newModelNode = (osg::Group*)grp->getChild(0);
	Line 287:                 osg::ref_ptr<osg::Node> newModelNode = (osg::Group*)grp->getChild(0);
	Line 304:             //this is a clone of osg::ComputeBoundsVisitor, except it excludes pivot_object Geodes
	Line 408:                     for (std::vector<osg::Node*>::iterator it = findVisitor.getNodeList().begin(); it != findVisitor.getNodeList().end(); it++)
	Line 413:                         osg::ref_ptr<osg::Geode> theGeode = (osg::Geode*)(*it);
	Line 413:                         osg::ref_ptr<osg::Geode> theGeode = (osg::Geode*)(*it);
	Line 413:                         osg::ref_ptr<osg::Geode> theGeode = (osg::Geode*)(*it);
	Line 414:                         osg::ref_ptr<osg::Group> parent = theGeode->getParent(0);
	Line 414:                         osg::ref_ptr<osg::Group> parent = theGeode->getParent(0);
	Line 420:                             osg::ref_ptr<osg::Group> parentOfParent = parent->getParent(0);
	Line 420:                             osg::ref_ptr<osg::Group> parentOfParent = parent->getParent(0);
	Line 434:                     for (std::vector<osg::BoundingSphere>::iterator it = bSphereVisitor.getBoundingSpheres()->begin(); it != bSphereVisitor.getBoundingSpheres()->end(); it++)
	Line 436:                         osg::Vec3 pt = it->center();
	Line 487:         osg::ref_ptr<osg::Node> nodeClone;
	Line 487:         osg::ref_ptr<osg::Node> nodeClone;
	Line 488:         int copyOptions = osg::CopyOp::SHALLOW_COPY;
	Line 491:             copyOptions |= osg::CopyOp::DEEP_COPY_NODES;
	Line 494:             copyOptions |= osg::CopyOp::DEEP_COPY_DRAWABLES;
	Line 499:                 copyOptions |= osg::CopyOp::DEEP_COPY_ARRAYS;
	Line 502:         if (copyOptions != osg::CopyOp::SHALLOW_COPY)
	Line 503:             nodeClone = dynamic_cast<osg::Node*> (model->node->clone(copyOptions));
	Line 511:             osg::ref_ptr<osg::Switch> visibilitySwitch = new osg::Switch;
	Line 511:             osg::ref_ptr<osg::Switch> visibilitySwitch = new osg::Switch;
	Line 511:             osg::ref_ptr<osg::Switch> visibilitySwitch = new osg::Switch;
	Line 539:             std::vector<osg::BoundingBox>* tempBoundingBoxList;
	Line 588:             vehicle->xform->setDataVariance(osg::Object::STATIC);
	Line 606:                 osg::ref_ptr<osg::NodeCallback> updatecb = vehicle->xform->getUpdateCallback();
	Line 606:                 osg::ref_ptr<osg::NodeCallback> updatecb = vehicle->xform->getUpdateCallback();
	Line 607:                 osg::ref_ptr<osg::NodeCallback> cullcb = vehicle->xform->getCullCallback();
	Line 607:                 osg::ref_ptr<osg::NodeCallback> cullcb = vehicle->xform->getCullCallback();
	Line 610:                 osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 610:                 osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 610:                 osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 624:                 osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 624:                 osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 624:                 osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 666:         osg::ref_ptr<osg::Geode> theGeode = NULL;
	Line 666:         osg::ref_ptr<osg::Geode> theGeode = NULL;
	Line 667:         std::vector<osg::Geode*> *pivotGeodesToRemove = visitor.getPivotGeodes();
	Line 668:         std::vector<osg::Geode*>::iterator it = pivotGeodesToRemove->begin();
	Line 672:             osg::ref_ptr<osg::Group> parent = theGeode->getParent(0);
	Line 672:             osg::ref_ptr<osg::Group> parent = theGeode->getParent(0);
	Line 682:                 osg::ref_ptr<osg::Group> parentOfParent = parent->getParent(0);
	Line 682:                 osg::ref_ptr<osg::Group> parentOfParent = parent->getParent(0);
	Line 690:         std::vector<osg::Geode*> *pivotUpdateGeodes = visitor.getUpdatePivotGeodes();
	Line 695:             osg::ref_ptr<osg::Group> parent = theGeode->getParent(0);
	Line 695:             osg::ref_ptr<osg::Group> parent = theGeode->getParent(0);
	Line 705:                 osg::ref_ptr<osg::Group> parentOfParent = parent->getParent(0);
	Line 705:                 osg::ref_ptr<osg::Group> parentOfParent = parent->getParent(0);
	Line 745: void MiniBackgroundLoader::flattenScale(osg::ref_ptr<osg::Node>& node, osg::Vec3f scaleFactor)
	Line 745: void MiniBackgroundLoader::flattenScale(osg::ref_ptr<osg::Node>& node, osg::Vec3f scaleFactor)
	Line 745: void MiniBackgroundLoader::flattenScale(osg::ref_ptr<osg::Node>& node, osg::Vec3f scaleFactor)
	Line 748:     osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 748:     osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 748:     osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 749:     osg::ref_ptr<osg::MatrixTransform> scalingXform = new osg::MatrixTransform;
	Line 749:     osg::ref_ptr<osg::MatrixTransform> scalingXform = new osg::MatrixTransform;
	Line 749:     osg::ref_ptr<osg::MatrixTransform> scalingXform = new osg::MatrixTransform;
	Line 753:     scalingXform->setDataVariance(osg::Object::STATIC);
	Line 754:     scalingXform->setMatrix(osg::Matrix::scale(scaleFactor));
	Line 768:     osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 768:     osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 768:     osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 770:     osg::ref_ptr<osg::Node> newNode = flattenedTransform->getChild(0);
	Line 770:     osg::ref_ptr<osg::Node> newNode = flattenedTransform->getChild(0);
	Line 776: void MiniBackgroundLoader::parseInstance(osg::Node *instance, int contactId, Vehicle *vehicle)
	Line 781:     osg::Vec3f anchorLocation;
	Line 790:         osg::ref_ptr<osg::Geode> lsg = new osg::Geode;
	Line 790:         osg::ref_ptr<osg::Geode> lsg = new osg::Geode;
	Line 790:         osg::ref_ptr<osg::Geode> lsg = new osg::Geode;
	Line 796: void MiniBackgroundLoader::parseModel(osg::Node * node, int &numPivots, bool &hasDynamicDrawables, bool createSwitchesAndTransforms)
	Line 803:         std::vector <osg::Node *> * throwaways = visitor.getThrowaway();
	Line 804:         std::vector<osg::Node *>::iterator it = throwaways->begin();
	Line 805:         std::vector<osg::Node *>::iterator end = throwaways->end();
	Line 808:             osg::ref_ptr<osg::Node> n = *it;
	Line 808:             osg::ref_ptr<osg::Node> n = *it;
	Line 816:     std::vector<osg::Group *>::iterator it;
	Line 822:         std::vector<osg::Group *> * matrixTransforms = visitor.getMatrixTransforms();
	Line 826:             osg::ref_ptr<osg::Group> group = *it;
	Line 826:             osg::ref_ptr<osg::Group> group = *it;
	Line 827:             osg::ref_ptr<osg::MatrixTransform> matrixTransform = new osg::MatrixTransform;
	Line 827:             osg::ref_ptr<osg::MatrixTransform> matrixTransform = new osg::MatrixTransform;
	Line 827:             osg::ref_ptr<osg::MatrixTransform> matrixTransform = new osg::MatrixTransform;
	Line 829:             matrixTransform->setDataVariance(osg::Object::DYNAMIC);
	Line 834:                 ((osg::Group *) matrixTransform)->insertChild(0, group->getChild(i));
	Line 844:         std::vector<osg::Group *> * switches = visitor.getSwitches();
	Line 847:             osg::ref_ptr<osg::Group> group = *it;
	Line 847:             osg::ref_ptr<osg::Group> group = *it;
	Line 848:             osg::ref_ptr<osg::Switch> switc = new osg::Switch;
	Line 848:             osg::ref_ptr<osg::Switch> switc = new osg::Switch;
	Line 848:             osg::ref_ptr<osg::Switch> switc = new osg::Switch;
	Line 854:             osg::ref_ptr<osg::Group> newGroup;
	Line 854:             osg::ref_ptr<osg::Group> newGroup;
	Line 857:                 newGroup = new osg::Group;
	Line 858:                 newGroup->setDataVariance(osg::Object::DYNAMIC); //set to dynamic so that this strategic group does not get optimized away
	Line 878:     std::map<std::string, std::vector<osg::Group *> > * switchMap = visitor.getSwitchMap();
	Line 879:     std::map<std::string, std::vector<osg::Group *> >::iterator mapIt;
	Line 884:         std::vector<osg::Group*> switchGroup = mapIt->second;
	Line 887:         osg::ref_ptr<osg::Switch> newSwitch = new osg::Switch;
	Line 887:         osg::ref_ptr<osg::Switch> newSwitch = new osg::Switch;
	Line 887:         osg::ref_ptr<osg::Switch> newSwitch = new osg::Switch;
	Line 894:             osg::ref_ptr<osg::Group> grp = *it;
	Line 894:             osg::ref_ptr<osg::Group> grp = *it;
	Line 903:             ((osg::Group *) node)->addChild(newSwitch);
	Line 907:     osg::ref_ptr<osg::Group> hullGrp = new osg::Group;
	Line 907:     osg::ref_ptr<osg::Group> hullGrp = new osg::Group;
	Line 907:     osg::ref_ptr<osg::Group> hullGrp = new osg::Group;
	Line 909:     std::vector<osg::Group *> * numbers = visitor.getNumbers();
	Line 913:         osg::ref_ptr<osg::Group> grp = *it;
	Line 913:         osg::ref_ptr<osg::Group> grp = *it;
	Line 921:     osg::ref_ptr<osg::PolygonOffset> polygon_offset = new osg::PolygonOffset;
	Line 921:     osg::ref_ptr<osg::PolygonOffset> polygon_offset = new osg::PolygonOffset;
	Line 921:     osg::ref_ptr<osg::PolygonOffset> polygon_offset = new osg::PolygonOffset;
	Line 924:     hullGrp->getOrCreateStateSet()->setAttribute(polygon_offset.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 924:     hullGrp->getOrCreateStateSet()->setAttribute(polygon_offset.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 925:     hullGrp->getOrCreateStateSet()->setMode(GL_POLYGON_OFFSET_FILL, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 925:     hullGrp->getOrCreateStateSet()->setMode(GL_POLYGON_OFFSET_FILL, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 929:         ((osg::Group *) node)->addChild(hullGrp);
	Line 932:     std::vector<osg::Geode *> * geodesToPrune = visitor.getGeodesToPrune();
	Line 933:     std::vector<osg::Geode *>::iterator geodeIt;
	Line 934:     osg::ref_ptr<osg::Geode> geode = NULL;
	Line 934:     osg::ref_ptr<osg::Geode> geode = NULL;
	Line 935:     osg::ref_ptr<osg::Group> parent = NULL;
	Line 935:     osg::ref_ptr<osg::Group> parent = NULL;
	Line 940:         osg::ref_ptr<osg::Switch> switc = new osg::Switch;
	Line 940:         osg::ref_ptr<osg::Switch> switc = new osg::Switch;
	Line 940:         osg::ref_ptr<osg::Switch> switc = new osg::Switch;
	Line 971:         osg::Vec3f eyeLocation;
	Line 986:             osg::Vec3f anchorLocation;
	Line 997:         osg::Vec3f anchorLocation = findVisitor.getFirst()->computeBound().center(); //will always find as at worst case it was just created
	Line 1001:         osg::Vec3f floorLocation;
	Line 1018:         osg::ref_ptr<osg::Group> chainGroup = new osg::Group;
	Line 1018:         osg::ref_ptr<osg::Group> chainGroup = new osg::Group;
	Line 1018:         osg::ref_ptr<osg::Group> chainGroup = new osg::Group;
	Line 1024: void MiniBackgroundLoader::addPivotObject(std::string name, osg::Vec3 position, osg::Group* root)
	Line 1024: void MiniBackgroundLoader::addPivotObject(std::string name, osg::Vec3 position, osg::Group* root)
	Line 1026:     osg::ref_ptr<osg::Group> pivotGroup = new osg::Group;
	Line 1026:     osg::ref_ptr<osg::Group> pivotGroup = new osg::Group;
	Line 1026:     osg::ref_ptr<osg::Group> pivotGroup = new osg::Group;
	Line 1028:     osg::ref_ptr<osg::Geode> pivotGeode = new osg::Geode;
	Line 1028:     osg::ref_ptr<osg::Geode> pivotGeode = new osg::Geode;
	Line 1028:     osg::ref_ptr<osg::Geode> pivotGeode = new osg::Geode;
	Line 1030:     osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	Line 1030:     osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	Line 1030:     osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	Line 1032:     std::vector<osg::Vec3f> vertices;
	Line 1038:     osg::ref_ptr<osg::Vec3Array> vertices_array = new osg::Vec3Array(vertices.size(), (osg::Vec3f*) &(vertices.front()));
	Line 1038:     osg::ref_ptr<osg::Vec3Array> vertices_array = new osg::Vec3Array(vertices.size(), (osg::Vec3f*) &(vertices.front()));
	Line 1038:     osg::ref_ptr<osg::Vec3Array> vertices_array = new osg::Vec3Array(vertices.size(), (osg::Vec3f*) &(vertices.front()));
	Line 1038:     osg::ref_ptr<osg::Vec3Array> vertices_array = new osg::Vec3Array(vertices.size(), (osg::Vec3f*) &(vertices.front()));
	Line 1049:     osg::Geometry::PrimitiveSetList prim_list;
	Line 1050:     osg::ref_ptr<osg::DrawElementsUInt> de_tris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, indices.size(),
	Line 1050:     osg::ref_ptr<osg::DrawElementsUInt> de_tris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, indices.size(),
	Line 1050:     osg::ref_ptr<osg::DrawElementsUInt> de_tris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, indices.size(),
	Line 1050:     osg::ref_ptr<osg::DrawElementsUInt> de_tris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, indices.size(),
	Line 1060: void MiniBackgroundLoader::loadLODFiles(std::string &filename, osg::ref_ptr<osg::Node> &modelNode, float modelLODRanges[])
	Line 1060: void MiniBackgroundLoader::loadLODFiles(std::string &filename, osg::ref_ptr<osg::Node> &modelNode, float modelLODRanges[])
	Line 1062:     std::vector< osg::ref_ptr<osg::Node> > lodList;
	Line 1062:     std::vector< osg::ref_ptr<osg::Node> > lodList;
	Line 1075:         osg::ref_ptr<osgDB::ReaderWriter::Options> options = new osgDB::ReaderWriter::ReaderWriter::Options;
	Line 1079:         osg::ref_ptr<osg::Node> node = osgDB::readNodeFile(filenamePre + ".ive", options);
	Line 1079:         osg::ref_ptr<osg::Node> node = osgDB::readNodeFile(filenamePre + ".ive", options);
	Line 1097:         std::vector<osg::LOD *> LODs;
	Line 1106:         std::vector<osg::Group *>::iterator it;
	Line 1107:         std::vector<osg::Group *> * groups = mainVisitor.getGroups();
	Line 1110:             osg::ref_ptr<osg::Group> group = *it;
	Line 1110:             osg::ref_ptr<osg::Group> group = *it;
	Line 1111:             osg::ref_ptr<osg::LOD> lodNode = new osg::LOD;
	Line 1111:             osg::ref_ptr<osg::LOD> lodNode = new osg::LOD;
	Line 1111:             osg::ref_ptr<osg::LOD> lodNode = new osg::LOD;
	Line 1113:             lodNode->setRangeMode(osg::LOD::DISTANCE_FROM_EYE_POINT);
	Line 1133:         osg::ref_ptr<osg::LOD> mainLod = new osg::LOD;
	Line 1133:         osg::ref_ptr<osg::LOD> mainLod = new osg::LOD;
	Line 1133:         osg::ref_ptr<osg::LOD> mainLod = new osg::LOD;
	Line 1135:         mainLod->setRangeMode(osg::LOD::DISTANCE_FROM_EYE_POINT);
	Line 1139:         osg::ref_ptr<osg::Group> mainGrp = new osg::Group;
	Line 1139:         osg::ref_ptr<osg::Group> mainGrp = new osg::Group;
	Line 1139:         osg::ref_ptr<osg::Group> mainGrp = new osg::Group;
	Line 1144:         osg::ref_ptr<osg::Group> defaultGrp = dynamic_cast<osg::Group*> (modelNode.get());
	Line 1144:         osg::ref_ptr<osg::Group> defaultGrp = dynamic_cast<osg::Group*> (modelNode.get());
	Line 1144:         osg::ref_ptr<osg::Group> defaultGrp = dynamic_cast<osg::Group*> (modelNode.get());
	Line 1162:         std::vector<osg::Group *>::iterator it2;
	Line 1163:         std::vector<osg::Group *> * boomGroups = boomVisitor.getGroups();
	Line 1180:             //osg::ref_ptr<osg::Group> boomGroup = *it2;
	Line 1180:             //osg::ref_ptr<osg::Group> boomGroup = *it2;
	Line 1195:             std::vector<osg::Group *>::iterator it;
	Line 1196:             std::vector<osg::Group *> * groups = lodVisitor.getGroups();
	Line 1199:                 osg::ref_ptr<osg::Group> group = *it;
	Line 1199:                 osg::ref_ptr<osg::Group> group = *it;
	Line 1200:                 osg::ref_ptr<osg::LOD> lod = NULL;
	Line 1200:                 osg::ref_ptr<osg::LOD> lod = NULL;
	Line 1203:                 for (std::vector<osg::LOD *>::iterator lodIt = LODs.begin(); lodIt != LODs.end(); lodIt++)
	Line 1234:             osg::ref_ptr<osg::Group> lodMainGrp = new osg::Group;
	Line 1234:             osg::ref_ptr<osg::Group> lodMainGrp = new osg::Group;
	Line 1234:             osg::ref_ptr<osg::Group> lodMainGrp = new osg::Group;
	Line 1243:             osg::ref_ptr<osg::Group> lodDefaultGrp = dynamic_cast<osg::Group*> (lodList[lodNum].get());
	Line 1243:             osg::ref_ptr<osg::Group> lodDefaultGrp = dynamic_cast<osg::Group*> (lodList[lodNum].get());
	Line 1243:             osg::ref_ptr<osg::Group> lodDefaultGrp = dynamic_cast<osg::Group*> (lodList[lodNum].get());
	Line 1283: void MiniBackgroundLoader::adjustLODLevels(osg::Node *modelNode, float scaleFactor)
	Line 1285:     std::vector<osg::Node*> nodeList;
	Line 1291:     for (std::vector<osg::Node*>::iterator it = nodeList.begin(); it != nodeList.end(); it++)
	Line 1293:         osg::ref_ptr<osg::LOD> lod = dynamic_cast<osg::LOD*> (*it);
	Line 1293:         osg::ref_ptr<osg::LOD> lod = dynamic_cast<osg::LOD*> (*it);
	Line 1293:         osg::ref_ptr<osg::LOD> lod = dynamic_cast<osg::LOD*> (*it);
  D:\Development\psim\src\subview\MiniBackgroundLoader.h (10 hits)
	Line 29:     void loadLODFiles(std::string &filename, osg::ref_ptr<osg::Node> &modelNode, float modelLODRanges[]);
	Line 29:     void loadLODFiles(std::string &filename, osg::ref_ptr<osg::Node> &modelNode, float modelLODRanges[]);
	Line 30:     void adjustLODLevels(osg::Node *modelNode, float scaleFactor);
	Line 32:     void parseModel(osg::Node * model, int &numPivots, bool &hasBuoyOrMarkerNumbers, bool createSwitchesAndTransforms);
	Line 36:     void flattenScale(osg::ref_ptr<osg::Node>& node, osg::Vec3f scaleFactor);
	Line 36:     void flattenScale(osg::ref_ptr<osg::Node>& node, osg::Vec3f scaleFactor);
	Line 36:     void flattenScale(osg::ref_ptr<osg::Node>& node, osg::Vec3f scaleFactor);
	Line 37:     static void parseInstance(osg::Node *, int, Vehicle *vehicle);
	Line 39:     void addPivotObject(std::string name, osg::Vec3 position, osg::Group* root);
	Line 39:     void addPivotObject(std::string name, osg::Vec3 position, osg::Group* root);
  D:\Development\psim\src\subview\Missile.cpp (12 hits)
	Line 441:     osg::Vec3f where;
	Line 458: void Missile::getSmokeTrailLocation(osg::Vec3f& loc) const
	Line 461:     osg::Matrixf xformMat;
	Line 462:     xformMat.set(osg::Matrix::rotate(osg::inDegrees(contactHPR[0]), 0.0f, 0.0f, 1.0f) *
	Line 462:     xformMat.set(osg::Matrix::rotate(osg::inDegrees(contactHPR[0]), 0.0f, 0.0f, 1.0f) *
	Line 463:             osg::Matrix::rotate(osg::inDegrees(contactHPR[1]), 0.0f, 1.0f, 0.0f) *
	Line 463:             osg::Matrix::rotate(osg::inDegrees(contactHPR[1]), 0.0f, 1.0f, 0.0f) *
	Line 464:             osg::Matrix::rotate(osg::inDegrees(contactHPR[2]), 1.0f, 0.0f, 0.0f) *
	Line 464:             osg::Matrix::rotate(osg::inDegrees(contactHPR[2]), 1.0f, 0.0f, 0.0f) *
	Line 465:             osg::Matrix::translate(contactLoc[0], contactLoc[1], contactLoc[2]));
	Line 468:     osg::Vec4f position = xformMat.preMult(mSmokeOffset);
	Line 473: osg::Vec3f Missile::getSmokeTrailOffsetWorld() const
  D:\Development\psim\src\subview\Missile.h (6 hits)
	Line 21:     osg::Vec3f launchVehicleXYZ;
	Line 22:     osg::Vec3f launchHPR;
	Line 26:     osg::Vec3f mslOffsetPos;
	Line 33:     osg::Vec4f mSmokeOffset;
	Line 60:     void getSmokeTrailLocation(osg::Vec3f& loc) const; // world position
	Line 62:     osg::Vec3f getSmokeTrailOffsetWorld() const; // offset in world space
  D:\Development\psim\src\subview\MissileInfo.h (1 hit)
	Line 19:     osg::Vec3f mLastOffset;
  D:\Development\psim\src\subview\Model.cpp (55 hits)
	Line 78:     nodeBoundingBox = new osg::Geode();
	Line 81:     osg::ref_ptr<osg::Geometry> boundingBoxGeometry = new osg::Geometry();
	Line 81:     osg::ref_ptr<osg::Geometry> boundingBoxGeometry = new osg::Geometry();
	Line 81:     osg::ref_ptr<osg::Geometry> boundingBoxGeometry = new osg::Geometry();
	Line 84:     nodeBoundingBox->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 85:     nodeBoundingBox->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	Line 87:     osg::Vec3Array* boundingBoxVertices = new osg::Vec3Array;
	Line 87:     osg::Vec3Array* boundingBoxVertices = new osg::Vec3Array;
	Line 88:     boundingBoxVertices->push_back(osg::Vec3(bboxMin[0], bboxMin[1], bboxMin[2])); // bottom back left
	Line 89:     boundingBoxVertices->push_back(osg::Vec3(bboxMax[0], bboxMin[1], bboxMin[2])); // bottom back right
	Line 90:     boundingBoxVertices->push_back(osg::Vec3(bboxMax[0], bboxMin[1], bboxMax[2])); // top back right
	Line 91:     boundingBoxVertices->push_back(osg::Vec3(bboxMin[0], bboxMin[1], bboxMax[2])); // top back left
	Line 92:     boundingBoxVertices->push_back(osg::Vec3(bboxMin[0], bboxMax[1], bboxMin[2])); // bottom front left
	Line 93:     boundingBoxVertices->push_back(osg::Vec3(bboxMax[0], bboxMax[1], bboxMin[2])); // bottom front right
	Line 94:     boundingBoxVertices->push_back(osg::Vec3(bboxMax[0], bboxMax[1], bboxMax[2])); // top front right
	Line 95:     boundingBoxVertices->push_back(osg::Vec3(bboxMin[0], bboxMax[1], bboxMax[2])); // top front left
	Line 99:     osg::ref_ptr<osg::DrawElementsUInt> bboxBottomFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 99:     osg::ref_ptr<osg::DrawElementsUInt> bboxBottomFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 99:     osg::ref_ptr<osg::DrawElementsUInt> bboxBottomFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 99:     osg::ref_ptr<osg::DrawElementsUInt> bboxBottomFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 106:     osg::ref_ptr<osg::DrawElementsUInt> bboxTopFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 106:     osg::ref_ptr<osg::DrawElementsUInt> bboxTopFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 106:     osg::ref_ptr<osg::DrawElementsUInt> bboxTopFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 106:     osg::ref_ptr<osg::DrawElementsUInt> bboxTopFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 113:     osg::ref_ptr<osg::DrawElementsUInt> bboxBackFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 113:     osg::ref_ptr<osg::DrawElementsUInt> bboxBackFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 113:     osg::ref_ptr<osg::DrawElementsUInt> bboxBackFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 113:     osg::ref_ptr<osg::DrawElementsUInt> bboxBackFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 120:     osg::ref_ptr<osg::DrawElementsUInt> bboxFrontFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 120:     osg::ref_ptr<osg::DrawElementsUInt> bboxFrontFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 120:     osg::ref_ptr<osg::DrawElementsUInt> bboxFrontFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 120:     osg::ref_ptr<osg::DrawElementsUInt> bboxFrontFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 127:     osg::ref_ptr<osg::DrawElementsUInt> bboxRightFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 127:     osg::ref_ptr<osg::DrawElementsUInt> bboxRightFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 127:     osg::ref_ptr<osg::DrawElementsUInt> bboxRightFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 127:     osg::ref_ptr<osg::DrawElementsUInt> bboxRightFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 134:     osg::ref_ptr<osg::DrawElementsUInt> bboxLeftFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 134:     osg::ref_ptr<osg::DrawElementsUInt> bboxLeftFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 134:     osg::ref_ptr<osg::DrawElementsUInt> bboxLeftFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 134:     osg::ref_ptr<osg::DrawElementsUInt> bboxLeftFace = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, 0);
	Line 142:     osg::ref_ptr<osg::Vec4Array> bboxColors = new osg::Vec4Array;
	Line 142:     osg::ref_ptr<osg::Vec4Array> bboxColors = new osg::Vec4Array;
	Line 142:     osg::ref_ptr<osg::Vec4Array> bboxColors = new osg::Vec4Array;
	Line 143:     bboxColors->push_back(osg::Vec4(1.0, 0.0, 0.0, 0.5));
	Line 145:     boundingBoxGeometry->setColorBinding(osg::Geometry::BIND_OVERALL);
	Line 147:     osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
	Line 147:     osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
	Line 147:     osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array;
	Line 148:     normals->push_back(osg::Vec3(0.0, 0.0, -1.0));
	Line 149:     normals->push_back(osg::Vec3(0.0, 0.0, 1.0));
	Line 150:     normals->push_back(osg::Vec3(0.0, -1.0, 0.0));
	Line 151:     normals->push_back(osg::Vec3(0.0, 1.0, 0.0));
	Line 152:     normals->push_back(osg::Vec3(1.0, 0.0, 0.0));
	Line 153:     normals->push_back(osg::Vec3(-1.0, 0.0, 0.0));
	Line 155:     boundingBoxGeometry->setNormalBinding(osg::Geometry::BIND_PER_PRIMITIVE_SET);
  D:\Development\psim\src\subview\Model.h (7 hits)
	Line 33:     osg::ref_ptr<osg::Node> node;
	Line 33:     osg::ref_ptr<osg::Node> node;
	Line 35:     osg::ref_ptr<osg::Node> nodeBoundingBox;
	Line 35:     osg::ref_ptr<osg::Node> nodeBoundingBox;
	Line 42:     osg::Vec3 scaleFactor;
	Line 43:     osg::Vec3 bboxMin, bboxMax;
	Line 48:     std::vector<osg::Vec3> lightPointLocations;
  D:\Development\psim\src\subview\Moon.cpp (49 hits)
	Line 54:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 54:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 54:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 55:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "moonFrag.glsl"));
	Line 58:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 58:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 58:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 61:     stateset->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 62:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 62:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 63:     stateset->addUniform(new osg::Uniform("texture", 0));
	Line 64:     stateset->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 64:     stateset->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 67:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 67:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 67:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 68:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 68:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 68:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 71:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 71:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 71:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 75:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vertices->size()));
	Line 75:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vertices->size()));
	Line 79:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 79:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 79:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 83:     mTransform = new osg::MatrixTransform;
	Line 107: osg::Group* Moon::GetNode()
	Line 112: osg::Vec3 Moon::GetPos()
	Line 169:             osg::Matrix::rotate(osg::inDegrees(mRotation), 0.0f, 1.0f, 0.0f) *
	Line 169:             osg::Matrix::rotate(osg::inDegrees(mRotation), 0.0f, 1.0f, 0.0f) *
	Line 170:             osg::Matrix::rotate(osg::inDegrees(mElevation), 1.0f, 0.0f, 0.0f) *
	Line 170:             osg::Matrix::rotate(osg::inDegrees(mElevation), 1.0f, 0.0f, 0.0f) *
	Line 171:             osg::Matrix::rotate(osg::inDegrees(mAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 171:             osg::Matrix::rotate(osg::inDegrees(mAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 172:             osg::Matrix::scale(scale, scale, scale) *
	Line 173:             osg::Matrix::translate(mPosition*MOON_DISTANCE));
	Line 426:     mTexture = new osg::Texture2D;
	Line 427:     mTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	Line 427:     mTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	Line 428:     mTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 428:     mTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 429:     mTexture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 429:     mTexture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 430:     mTexture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP);
	Line 430:     mTexture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP);
	Line 431:     mTexture->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
	Line 431:     mTexture->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
  D:\Development\psim\src\subview\Moon.h (9 hits)
	Line 22:         osg::Group* GetNode();
	Line 23:         osg::Vec3 GetPos();
	Line 59:         osg::Vec3 mPosition;
	Line 64:         osg::ref_ptr<osg::MatrixTransform> mTransform;
	Line 64:         osg::ref_ptr<osg::MatrixTransform> mTransform;
	Line 65:         osg::ref_ptr<osg::Image> mImages[24];
	Line 65:         osg::ref_ptr<osg::Image> mImages[24];
	Line 66:         osg::ref_ptr<osg::Texture2D> mTexture;
	Line 66:         osg::ref_ptr<osg::Texture2D> mTexture;
  D:\Development\psim\src\subview\MunitionsAnimator.cpp (11 hits)
	Line 39: void MunitionsAnimator::showSplash(osg::Vec2 latlon){
	Line 48:     params.setGeomDimensions(osg::Vec2(geomWidth, geomHeight));
	Line 52:     params.setOrientation(osg::Vec3(0.0, 0.0, 1.0)); //billboard rotates around the vertical axis
	Line 59:     params.setPosition(osg::Vec3(posArray[0], posArray[1], -depth));
	Line 74: void MunitionsAnimator::showProxBurst(osg::Vec3 latlonalt){
	Line 83:     params.setGeomDimensions(osg::Vec2(geomWidth, geomHeight));
	Line 87:     params.setOrientation(osg::Vec3(0.0, 0.0, 1.0)); //billboard rotates around the vertical axis
	Line 93:     params.setPosition(osg::Vec3(posArray[0], posArray[1], latlonalt.z()));
	Line 102: void MunitionsAnimator::showExplosion(osg::Vec3 location){
	Line 113:     params.setGeomDimensions(osg::Vec2(175, 175));
	Line 119:     params.setOrientation(osg::Vec3(0, 0, 1));
  D:\Development\psim\src\subview\MunitionsAnimator.h (3 hits)
	Line 23:     static void showSplash(osg::Vec2 latlon);          
	Line 24:     static void showProxBurst(osg::Vec3 latlonalt);
	Line 25:     static void showExplosion(osg::Vec3 latlonalt);
  D:\Development\psim\src\subview\NoiseQuad.cpp (31 hits)
	Line 35: NoiseQuad::NoiseQuad(osg::TextureRectangle *_textureRect)
	Line 38:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-1.0, 1.0, -1.0, 1.0, -50.0, 50.0));
	Line 38:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-1.0, 1.0, -1.0, 1.0, -50.0, 50.0));
	Line 39:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 39:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 41:     osg::ref_ptr< osg::Program > noisePassProgram = new osg::Program;
	Line 41:     osg::ref_ptr< osg::Program > noisePassProgram = new osg::Program;
	Line 41:     osg::ref_ptr< osg::Program > noisePassProgram = new osg::Program;
	Line 42:     noisePassProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "noise.glsl"));
	Line 44:     osg::StateSet* stateSet = new osg::StateSet();
	Line 44:     osg::StateSet* stateSet = new osg::StateSet();
	Line 46:     stateSet->setAttributeAndModes(noisePassProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 46:     stateSet->setAttributeAndModes(noisePassProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 50:     stateSet->addUniform(new osg::Uniform("scene", 0));
	Line 51:     noiseUniform = new osg::Uniform("useNoise", 0.0f);
	Line 53:     rgbContribUniform = new osg::Uniform("rgb_contrib", osg::Vec4f(0.18f, 0.6f, 0.18f, 1.f));
	Line 53:     rgbContribUniform = new osg::Uniform("rgb_contrib", osg::Vec4f(0.18f, 0.6f, 0.18f, 1.f));
	Line 55:     saturationUniform = new osg::Uniform("saturation", osg::Vec4f(2.f, 3.f, 1.5f, 1.f));
	Line 55:     saturationUniform = new osg::Uniform("saturation", osg::Vec4f(2.f, 3.f, 1.5f, 1.f));
	Line 57:     bwUniform = new osg::Uniform("useBW", 0.f);
	Line 59:     timeUniform = new osg::Uniform("current_time_s", (float) Shared->glob.problemTime);
	Line 72:     stateSet->addUniform(new osg::Uniform("noise_color", (float) noise_color));
	Line 73:     stateSet->addUniform(new osg::Uniform("noise_strength", (float) noise_strength));
	Line 80: void NoiseQuad::drawImplementation(osg::RenderInfo& ri) const
	Line 112: osg::Vec4 NoiseQuad::CalcRgbUniform(VisualEffectEnum mode) const
	Line 118:             return osg::Vec4(0.18f, 0.60f, 0.18f, 1.0f);
	Line 125:             return osg::Vec4(1.0f, 1.0f, 1.0f, 1.0f);
	Line 129: osg::Vec4 NoiseQuad::CalcSaturationUniform(VisualEffectEnum mode) const
	Line 137:             return osg::Vec4(0.33f, 0.33f, 0.33f, 1.0f);
	Line 140:             return osg::Vec4(2.0f, 2.0f, 2.0f, 1.0f);
	Line 143:             return osg::Vec4(6.0f, 9.0f, 4.5f, 1.0f);
  D:\Development\psim\src\subview\NoiseQuad.h (27 hits)
	Line 23: class NoiseQuad : public osg::Geometry
	Line 26:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 26:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 27:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 27:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 28:     osg::TextureRectangle* textureRect;
	Line 29:     osg::ref_ptr<osg::Uniform> saturationUniform;
	Line 29:     osg::ref_ptr<osg::Uniform> saturationUniform;
	Line 30:     osg::ref_ptr<osg::Uniform> noiseUniform;
	Line 30:     osg::ref_ptr<osg::Uniform> noiseUniform;
	Line 31:     osg::ref_ptr<osg::Uniform> rgbContribUniform;
	Line 31:     osg::ref_ptr<osg::Uniform> rgbContribUniform;
	Line 32:     osg::ref_ptr<osg::Uniform> timeUniform;
	Line 32:     osg::ref_ptr<osg::Uniform> timeUniform;
	Line 33:     osg::ref_ptr<osg::Uniform> bwUniform;
	Line 33:     osg::ref_ptr<osg::Uniform> bwUniform;
	Line 38:     NoiseQuad(const NoiseQuad& NoiseQuad, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 38:     NoiseQuad(const NoiseQuad& NoiseQuad, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 39:     osg::Geometry(NoiseQuad, copyop)
	Line 46:     NoiseQuad(osg::TextureRectangle* _textureRect);
	Line 47:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 49:     virtual osg::BoundingBox computeBound() const
	Line 51:         osg::BoundingBox bbox;
	Line 52:         bbox.expandBy(osg::Vec3(-10000.0, -10000.0, -10000.0));
	Line 53:         bbox.expandBy(osg::Vec3(10000.0, 10000.0, 10000.0));
	Line 63:     osg::Vec4 CalcRgbUniform(VisualEffectEnum mode) const;
	Line 64:     osg::Vec4 CalcSaturationUniform(VisualEffectEnum mode) const;
  D:\Development\psim\src\subview\Ocean.cpp (4 hits)
	Line 125: void Ocean::setCamera(osg::Camera *camera)
	Line 192: void Ocean::addToOSG(osg::Group * root)
	Line 218:     osg::Vec3f eye, center, dir, up;
	Line 226:     osg::Matrixf view = mCamera->getViewMatrix();
  D:\Development\psim\src\subview\Ocean.h (3 hits)
	Line 27:     void setCamera(osg::Camera *camera);
	Line 47:     void addToOSG(osg::Group * root);
	Line 68:     osg::Camera *mCamera;
  D:\Development\psim\src\subview\oceanCU.cu (3 hits)
	Line 153: //    osg::Vec2 K;
	Line 211: //    osg::Vec2 K;
	Line 212: //    osg::Vec2 Kh0(0,0);
  D:\Development\psim\src\subview\OceanGeometry.cpp (320 hits)
	Line 64: extern osg::Texture* projTexture;
	Line 65: extern osg::Texture* reflTexture;
	Line 66: extern osg::Texture* reflAlphaTexture;
	Line 68: extern osg::Texture* submergedTexture;
	Line 70: extern osg::TexMat* projTexMat;
	Line 72: extern osg::TextureCubeMap* gCubeMapTexture;
	Line 161:     mHeightTexture = new osg::Texture2D;
	Line 163:     mHeightTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 163:     mHeightTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 164:     mHeightTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 164:     mHeightTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 165:     mHeightTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 165:     mHeightTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 166:     mHeightTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 166:     mHeightTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 168:     mNormalTexture = new osg::Texture2D;
	Line 170:     mNormalTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 170:     mNormalTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 171:     mNormalTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 171:     mNormalTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 172:     mNormalTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 172:     mNormalTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 173:     mNormalTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 173:     mNormalTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 175:     mRippleNormalTexture = new osg::Texture2D;
	Line 177:     mRippleNormalTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 177:     mRippleNormalTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 178:     mRippleNormalTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 178:     mRippleNormalTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 179:     mRippleNormalTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 179:     mRippleNormalTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 180:     mRippleNormalTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 180:     mRippleNormalTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 182:     mRippleHeightTexture = new osg::Texture2D;
	Line 184:     mRippleHeightTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 184:     mRippleHeightTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 185:     mRippleHeightTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 185:     mRippleHeightTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 186:     mRippleHeightTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 186:     mRippleHeightTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 187:     mRippleHeightTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 187:     mRippleHeightTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 191:     dispxTex = new osg::Texture2D;
	Line 193:     dispxTex->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 193:     dispxTex->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 194:     dispxTex->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 194:     dispxTex->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 195:     dispxTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 195:     dispxTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 196:     dispxTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 196:     dispxTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 198:     dispyTex = new osg::Texture2D;
	Line 200:     dispyTex->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 200:     dispyTex->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 201:     dispyTex->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 201:     dispyTex->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 202:     dispyTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 202:     dispyTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 203:     dispyTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 203:     dispyTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 225:         dispxImg[i] = new osg::Image;
	Line 227:         dispyImg[i] = new osg::Image;
	Line 236:     this->setDataVariance(osg::Object::DYNAMIC);
	Line 238:     mpOceanTransform = new osg::MatrixTransform();
	Line 240:     mpOceanTransform->setDataVariance(osg::Object::DYNAMIC);
	Line 242:     mpOceanSwitch = new osg::Switch();
	Line 246: osg::BoundingBox OceanGeometry::computeBound() const
	Line 249:     osg::BoundingBox bbox(-MAX_FOG_DISTANCE_FT, -MAX_FOG_DISTANCE_FT, -100.f, MAX_FOG_DISTANCE_FT, MAX_FOG_DISTANCE_FT, 100.f);
	Line 272:     stateSet = new osg::StateSet;
	Line 274:     cubeMapSampler = new osg::Uniform("envMap", 0);
	Line 275:     foamMapSampler = new osg::Uniform("foamMap", 5);
	Line 277:     landLeeMapSampler = new osg::Uniform("landLeeMap", 6);
	Line 278:     wakeNormalMap0Sampler = new osg::Uniform("wakeNormalMap0", 7);
	Line 279:     wakeNormalMap1Sampler = new osg::Uniform("wakeNormalMap1", 8);
	Line 280:     wakeNormalMap2Sampler = new osg::Uniform("wakeNormalMap2", 12);
	Line 281:     wakeNormalMap3Sampler = new osg::Uniform("wakeNormalMap3", 14);
	Line 282:     wakeNormalMap4Sampler = new osg::Uniform("wakeNormalMap4", 15);
	Line 285:     mSeaStateUniform = new osg::Uniform(osg::Uniform::FLOAT, "seaState");
	Line 285:     mSeaStateUniform = new osg::Uniform(osg::Uniform::FLOAT, "seaState");
	Line 286:     whiteCapLevelUniform = new osg::Uniform("whiteCapLevel", 0.1f);
	Line 287:     maxWindWaveHeightUniform = new osg::Uniform("maxWindWaveHeight", 0.1f);
	Line 288:     fovPerPixelUniform = new osg::Uniform("fovPerPixel", 0.1f);
	Line 289:     duskUniform = new osg::Uniform("dusk", 0.1f);
	Line 290:     eyeAboveUniform = new osg::Uniform("eyeAbove", 0.1f);
	Line 291:     viewUniform = new osg::Uniform("view", osg::Vec3(0., 0., 0.));
	Line 291:     viewUniform = new osg::Uniform("view", osg::Vec3(0., 0., 0.));
	Line 292:     viewOriginUniform = new osg::Uniform("viewOrigin", osg::Vec2(0., 0.));
	Line 292:     viewOriginUniform = new osg::Uniform("viewOrigin", osg::Vec2(0., 0.));
	Line 293:     useDriftSetUniform = new osg::Uniform("useDriftSet", false);
	Line 294:     oceanSetUniform = new osg::Uniform("oceanSet", osg::Vec2(0., 0.));
	Line 294:     oceanSetUniform = new osg::Uniform("oceanSet", osg::Vec2(0., 0.));
	Line 295:     oceanDriftUniform = new osg::Uniform("oceanDrift", 0.f);
	Line 296:     windDirUniform = new osg::Uniform("windDir", osg::Vec2(0., 0.));
	Line 296:     windDirUniform = new osg::Uniform("windDir", osg::Vec2(0., 0.));
	Line 297:     windSpeedUniform = new osg::Uniform("windSpeed", 0.f);
	Line 298:     swellHeightPeriodUniform = new osg::Uniform("swellHeightPeriod", osg::Vec2(0.f, 1.f));
	Line 298:     swellHeightPeriodUniform = new osg::Uniform("swellHeightPeriod", osg::Vec2(0.f, 1.f));
	Line 299:     problemTimeUniform = new osg::Uniform("problemTime", osg::Vec2(0.f, 0.f));
	Line 299:     problemTimeUniform = new osg::Uniform("problemTime", osg::Vec2(0.f, 0.f));
	Line 300:     duskTailLightUniform = new osg::Uniform("duskTailLightPos", osg::Vec4f(0., 0., 0., 0.));
	Line 300:     duskTailLightUniform = new osg::Uniform("duskTailLightPos", osg::Vec4f(0., 0., 0., 0.));
	Line 301:     duskTailLightDirUniform = new osg::Uniform("duskTailLightDir", osg::Vec3f(0., 0., 0.));
	Line 301:     duskTailLightDirUniform = new osg::Uniform("duskTailLightDir", osg::Vec3f(0., 0., 0.));
	Line 302:     rudderAngleUniform = new osg::Uniform("rudderAngle", 0.f);
	Line 303:     mSwellHeight0Uniform = new osg::Uniform("swellHeight0", 0.f);
	Line 304:     mSwellHeight1Uniform = new osg::Uniform("swellHeight1", 0.f);
	Line 305:     mSwellWt0Uniform = new osg::Uniform("swellWt0", 0.f);
	Line 306:     mSwellWt1Uniform = new osg::Uniform("swellWt1", 0.f);
	Line 307:     mSwellK0Uniform = new osg::Uniform("swellK0", 0.f);
	Line 308:     mSwellK1Uniform = new osg::Uniform("swellK1", 0.f);
	Line 309:     mSwellPhaseOffset0Uniform = new osg::Uniform("swellPhaseOffset0", 0.f);
	Line 310:     mSwellPhaseOffset1Uniform = new osg::Uniform("swellPhaseOffset1", 0.f);
	Line 311:     mSwellDir0Uniform = new osg::Uniform("swellDir0", osg::Vec2f(1.f, 0.f));
	Line 311:     mSwellDir0Uniform = new osg::Uniform("swellDir0", osg::Vec2f(1.f, 0.f));
	Line 312:     mSwellDir1Uniform = new osg::Uniform("swellDir1", osg::Vec2f(1.f, 0.f));
	Line 312:     mSwellDir1Uniform = new osg::Uniform("swellDir1", osg::Vec2f(1.f, 0.f));
	Line 313:     mPrecipIntensityUniform = new osg::Uniform("precipIntensity", 0.0f);
	Line 314:     mOceanMeshOffsetUniform = new osg::Uniform("meshOffset", osg::Vec2f(0.0, 0.0));
	Line 314:     mOceanMeshOffsetUniform = new osg::Uniform("meshOffset", osg::Vec2f(0.0, 0.0));
	Line 317:     buoyPositionsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "buoyPositions", MAX_NUM_BUOYS);
	Line 317:     buoyPositionsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "buoyPositions", MAX_NUM_BUOYS);
	Line 319:     buoyPositionsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "buoyPositions[0]", MAX_NUM_BUOYS);
	Line 319:     buoyPositionsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "buoyPositions[0]", MAX_NUM_BUOYS);
	Line 322:     numBuoysUniform = new osg::Uniform(osg::Uniform::INT, "numBuoys");
	Line 322:     numBuoysUniform = new osg::Uniform(osg::Uniform::INT, "numBuoys");
	Line 327:     lees_nearContactPosUniform = new osg::Uniform("lees_nearContactPos", osg::Vec4(0.1, 0.1, 0.1, 0.1));
	Line 327:     lees_nearContactPosUniform = new osg::Uniform("lees_nearContactPos", osg::Vec4(0.1, 0.1, 0.1, 0.1));
	Line 328:     lees_nearContactDirSizeUniform = new osg::Uniform("lees_nearContactDirSize", osg::Vec4(0.1, 0.1, 0.1, 0.1));
	Line 328:     lees_nearContactDirSizeUniform = new osg::Uniform("lees_nearContactDirSize", osg::Vec4(0.1, 0.1, 0.1, 0.1));
	Line 329:     lees_landLeeCenterUniform = new osg::Uniform("lees_landLeeCenter", osg::Vec2(0.1, 0.1));
	Line 329:     lees_landLeeCenterUniform = new osg::Uniform("lees_landLeeCenter", osg::Vec2(0.1, 0.1));
	Line 330:     lees_landLeeWidthUniform = new osg::Uniform("lees_landLeeWidth", osg::Vec2(0.1, 0.1));
	Line 330:     lees_landLeeWidthUniform = new osg::Uniform("lees_landLeeWidth", osg::Vec2(0.1, 0.1));
	Line 333:     lees_nearWakePosUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakePos", MAX_NUM_CONTACT_WAKES);
	Line 333:     lees_nearWakePosUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakePos", MAX_NUM_CONTACT_WAKES);
	Line 334:     lees_nearWakeDirSizeUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeDirSize", MAX_NUM_CONTACT_WAKES);
	Line 334:     lees_nearWakeDirSizeUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeDirSize", MAX_NUM_CONTACT_WAKES);
	Line 335:     lees_nearWakeHeightUniform = new osg::Uniform(osg::Uniform::FLOAT, "lees_nearWakeHeight", MAX_NUM_CONTACT_WAKES);
	Line 335:     lees_nearWakeHeightUniform = new osg::Uniform(osg::Uniform::FLOAT, "lees_nearWakeHeight", MAX_NUM_CONTACT_WAKES);
	Line 336:     lees_nearWakeFalloffsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeFalloffs", 4);
	Line 336:     lees_nearWakeFalloffsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeFalloffs", 4);
	Line 337:     wake_is_backingUniform = new osg::Uniform(osg::Uniform::BOOL, "wake_is_backing", MAX_NUM_CONTACT_WAKES);
	Line 337:     wake_is_backingUniform = new osg::Uniform(osg::Uniform::BOOL, "wake_is_backing", MAX_NUM_CONTACT_WAKES);
	Line 339:     lees_nearWakePosUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakePos[0]", MAX_NUM_CONTACT_WAKES);
	Line 339:     lees_nearWakePosUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakePos[0]", MAX_NUM_CONTACT_WAKES);
	Line 340:     lees_nearWakeDirSizeUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeDirSize[0]", MAX_NUM_CONTACT_WAKES);
	Line 340:     lees_nearWakeDirSizeUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeDirSize[0]", MAX_NUM_CONTACT_WAKES);
	Line 341:     lees_nearWakeHeightUniform = new osg::Uniform(osg::Uniform::FLOAT, "lees_nearWakeHeight[0]", MAX_NUM_CONTACT_WAKES);
	Line 341:     lees_nearWakeHeightUniform = new osg::Uniform(osg::Uniform::FLOAT, "lees_nearWakeHeight[0]", MAX_NUM_CONTACT_WAKES);
	Line 342:     lees_nearWakeFalloffsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeFalloffs[0]", 4);
	Line 342:     lees_nearWakeFalloffsUniform = new osg::Uniform(osg::Uniform::FLOAT_VEC4, "lees_nearWakeFalloffs[0]", 4);
	Line 343:     wake_is_backingUniform = new osg::Uniform(osg::Uniform::BOOL, "wake_is_backing[0]", MAX_NUM_CONTACT_WAKES);
	Line 343:     wake_is_backingUniform = new osg::Uniform(osg::Uniform::BOOL, "wake_is_backing[0]", MAX_NUM_CONTACT_WAKES);
	Line 346:     lees_nearWakeFalloffsAftUniform = new osg::Uniform("lees_nearWakeFalloffsAft", osg::Vec4(0.1, 0.1, 0.1, 0.1));
	Line 346:     lees_nearWakeFalloffsAftUniform = new osg::Uniform("lees_nearWakeFalloffsAft", osg::Vec4(0.1, 0.1, 0.1, 0.1));
	Line 348:     lees_global_lee_dirUniform = new osg::Uniform("lees_global_lee_dir", osg::Vec2(0.1, 0.1));
	Line 348:     lees_global_lee_dirUniform = new osg::Uniform("lees_global_lee_dir", osg::Vec2(0.1, 0.1));
	Line 349:     lees_lee_min_heightUniform = new osg::Uniform("lees_lee_min_height", 0.1f);
	Line 350:     lees_lee_max_heightUniform = new osg::Uniform("lees_lee_max_height", 0.1f);
	Line 351:     lees_lee_min_lengthUniform = new osg::Uniform("lees_lee_min_length", 0.1f);
	Line 352:     lees_lee_max_lengthUniform = new osg::Uniform("lees_lee_max_length", 0.1f);
	Line 353:     lees_lee_dist_atten_finalUniform = new osg::Uniform("lees_lee_dist_atten", 0.1f);
	Line 354:     lees_lee_dist_blend_widthUniform = new osg::Uniform("lees_lee_dist_blend_width", 0.1f);
	Line 355:     lees_lee_dist_abeamUniform = new osg::Uniform("lees_lee_dist_abeam", 0.1f);
	Line 356:     lees_lee_atten_show_debugUniform = new osg::Uniform("lees_lee_dist_atten_show_debug", 0.1f);
	Line 360:     wake_typeUniform = new osg::Uniform(osg::Uniform::INT, "wake_type", MAX_NUM_CONTACT_WAKES);
	Line 360:     wake_typeUniform = new osg::Uniform(osg::Uniform::INT, "wake_type", MAX_NUM_CONTACT_WAKES);
	Line 362:     wake_typeUniform = new osg::Uniform(osg::Uniform::INT, "wake_type[0]", MAX_NUM_CONTACT_WAKES);
	Line 362:     wake_typeUniform = new osg::Uniform(osg::Uniform::INT, "wake_type[0]", MAX_NUM_CONTACT_WAKES);
	Line 365:     fadeWhiteCapsUniform = new osg::Uniform("fadeWhiteCaps", 0.1f);
	Line 374:     reflectionCoefUniform = new osg::Uniform("reflection_coefficient", reflectionPercentage);
	Line 385:     tailLightReflectionUniform = new osg::Uniform("tailLightReflectionPercent", tailLightReflectionPercentage);
	Line 471:     wakeNormalMapTexture[0] = new osg::Texture2D;
	Line 475:     wakeNormalMapTexture[0]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 475:     wakeNormalMapTexture[0]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 476:     wakeNormalMapTexture[0]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 476:     wakeNormalMapTexture[0]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 477:     wakeNormalMapTexture[0]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 477:     wakeNormalMapTexture[0]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 478:     wakeNormalMapTexture[0]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 478:     wakeNormalMapTexture[0]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 479:     wakeNormalMapTexture[0]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 479:     wakeNormalMapTexture[0]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 483:     wakeNormalMapTexture[1] = new osg::Texture2D;
	Line 487:     wakeNormalMapTexture[1]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 487:     wakeNormalMapTexture[1]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 488:     wakeNormalMapTexture[1]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 488:     wakeNormalMapTexture[1]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 489:     wakeNormalMapTexture[1]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 489:     wakeNormalMapTexture[1]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 490:     wakeNormalMapTexture[1]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 490:     wakeNormalMapTexture[1]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 491:     wakeNormalMapTexture[1]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 491:     wakeNormalMapTexture[1]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 495:     wakeNormalMapTexture[2] = new osg::Texture2D;
	Line 499:     wakeNormalMapTexture[2]->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 499:     wakeNormalMapTexture[2]->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 500:     wakeNormalMapTexture[2]->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 500:     wakeNormalMapTexture[2]->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 501:     wakeNormalMapTexture[2]->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP);
	Line 501:     wakeNormalMapTexture[2]->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP);
	Line 502:     wakeNormalMapTexture[2]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 502:     wakeNormalMapTexture[2]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 503:     wakeNormalMapTexture[2]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 503:     wakeNormalMapTexture[2]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 506:     wakeNormalMapTexture[3] = new osg::Texture2D;
	Line 510:     wakeNormalMapTexture[3]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 510:     wakeNormalMapTexture[3]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 511:     wakeNormalMapTexture[3]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 511:     wakeNormalMapTexture[3]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 512:     wakeNormalMapTexture[3]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 512:     wakeNormalMapTexture[3]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 513:     wakeNormalMapTexture[3]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 513:     wakeNormalMapTexture[3]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 514:     wakeNormalMapTexture[3]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 514:     wakeNormalMapTexture[3]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 517:     wakeNormalMapTexture[4] = new osg::Texture2D;
	Line 521:     wakeNormalMapTexture[4]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 521:     wakeNormalMapTexture[4]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 522:     wakeNormalMapTexture[4]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 522:     wakeNormalMapTexture[4]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 523:     wakeNormalMapTexture[4]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 523:     wakeNormalMapTexture[4]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 524:     wakeNormalMapTexture[4]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 524:     wakeNormalMapTexture[4]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 525:     wakeNormalMapTexture[4]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 525:     wakeNormalMapTexture[4]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 528:     foamMapTexture = new osg::Texture2D;
	Line 532:     foamMapTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 532:     foamMapTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 533:     foamMapTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 533:     foamMapTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 534:     foamMapTexture->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 534:     foamMapTexture->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 535:     foamMapTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 535:     foamMapTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 536:     foamMapTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 536:     foamMapTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 540:     landLeeImage = new osg::Image;
	Line 541:     landLeeTexture = new osg::Texture2D;
	Line 544:     stateSet->setTextureAttributeAndModes(0, gCubeMapTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 544:     stateSet->setTextureAttributeAndModes(0, gCubeMapTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 545:     stateSet->setTextureAttributeAndModes(5, foamMapTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 545:     stateSet->setTextureAttributeAndModes(5, foamMapTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 548:     stateSet->setTextureAttributeAndModes(6, landLeeTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 548:     stateSet->setTextureAttributeAndModes(6, landLeeTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 549:     stateSet->setTextureAttributeAndModes(7, wakeNormalMapTexture[0], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 549:     stateSet->setTextureAttributeAndModes(7, wakeNormalMapTexture[0], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 550:     stateSet->setTextureAttributeAndModes(8, wakeNormalMapTexture[1], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 550:     stateSet->setTextureAttributeAndModes(8, wakeNormalMapTexture[1], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 551:     stateSet->setTextureAttributeAndModes(12, wakeNormalMapTexture[2], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 551:     stateSet->setTextureAttributeAndModes(12, wakeNormalMapTexture[2], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 552:     stateSet->setTextureAttributeAndModes(14, wakeNormalMapTexture[3], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 552:     stateSet->setTextureAttributeAndModes(14, wakeNormalMapTexture[3], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 553:     stateSet->setTextureAttributeAndModes(15, wakeNormalMapTexture[4], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 553:     stateSet->setTextureAttributeAndModes(15, wakeNormalMapTexture[4], osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 557:     sharpUniform = new osg::Uniform("sharp", 1.f);
	Line 560:     mHeightTextureUniform = new osg::Uniform("heightTex", 1);
	Line 562:     mRippleHeightTextureUniform = new osg::Uniform("rippleHeightTex", 2);
	Line 565:     stateSet->addUniform(new osg::Uniform("projTex", 13));
	Line 566:     stateSet->addUniform(new osg::Uniform("reflTex", 18));
	Line 567:     stateSet->addUniform(new osg::Uniform("reflAlphaTex", 19));
	Line 569:     stateSet->addUniform(new osg::Uniform("submergedTex", 17));
	Line 573:     dispxUniform0 = new osg::Uniform("dispx0", 3);
	Line 575:     dispyUniform0 = new osg::Uniform("dispy0", 4);
	Line 579:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 579:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 579:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 580:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "frequencyVert.glsl"));
	Line 581:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "frequencyFrag.glsl"));
	Line 582:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 582:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 589: void OceanGeometry::attachExternalUniforms(osg::StateSet *ss)
	Line 653:     ss->setTextureAttributeAndModes(1, mHeightTexture, osg::StateAttribute::ON);
	Line 654:     ss->setTextureAttributeAndModes(2, mRippleHeightTexture, osg::StateAttribute::ON);
	Line 656:     ss->setTextureAttributeAndModes(13, projTexture, osg::StateAttribute::ON);
	Line 657:     ss->setTextureAttributeAndModes(18, reflTexture, osg::StateAttribute::ON);
	Line 658:     ss->setTextureAttributeAndModes(19, reflAlphaTexture, osg::StateAttribute::ON);
	Line 661:     ss->setTextureAttributeAndModes(17, submergedTexture, osg::StateAttribute::ON);
	Line 663:     ss->setTextureAttributeAndModes(0, projTexMat, osg::StateAttribute::ON);
	Line 666:     ss->setTextureAttributeAndModes(3, dispxTex, osg::StateAttribute::ON);
	Line 667:     ss->setTextureAttributeAndModes(4, dispyTex, osg::StateAttribute::ON);
	Line 671:     ss->setTextureAttributeAndModes(6, landLeeTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 671:     ss->setTextureAttributeAndModes(6, landLeeTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 703:     oceanSetUniform->set(osg::Vec2f(sin(oceanSet), cos(oceanSet)));
	Line 706:     windDirUniform->set(osg::Vec2f(-sin(windAng), -cos(windAng)));
	Line 718:             osg::Vec3 pos = ownship->getSternLightPos();
	Line 719:             osg::Vec3 dir = ownship->getSternLightDir();
	Line 720:             duskTailLightUniform->set(osg::Vec4(pos[0], pos[1], pos[2], LightInfoUpdate::isSternLightOn(ownship) && ownship->getType() == VehicleType::SUBMARINE));
	Line 721:             duskTailLightDirUniform->set(osg::Vec3(dir[0], dir[1], dir[2]));
	Line 728:             duskTailLightUniform->set(osg::Vec4(0., 0., 0., 0.));
	Line 733:         duskTailLightUniform->set(osg::Vec4(0., 0., 0., 0.));
	Line 744:     stateSet->setTextureAttributeAndModes(1, mHeightTexture, osg::StateAttribute::ON);
	Line 745:     stateSet->setTextureAttributeAndModes(2, mRippleHeightTexture, osg::StateAttribute::ON);
	Line 747:     stateSet->setTextureAttributeAndModes(13, projTexture, osg::StateAttribute::ON);
	Line 748:     stateSet->setTextureAttributeAndModes(18, reflTexture, osg::StateAttribute::ON);
	Line 749:     stateSet->setTextureAttributeAndModes(19, reflAlphaTexture, osg::StateAttribute::ON);
	Line 751:     stateSet->setTextureAttributeAndModes(17, submergedTexture, osg::StateAttribute::ON);
	Line 753:     stateSet->setTextureAttributeAndModes(0, projTexMat, osg::StateAttribute::ON);
	Line 757:     stateSet->setTextureAttributeAndModes(3, dispxTex, osg::StateAttribute::ON);
	Line 758:     stateSet->setTextureAttributeAndModes(4, dispyTex, osg::StateAttribute::ON);
	Line 762: void OceanGeometry::drawImplementation(osg::RenderInfo& ri) const
	Line 777:     viewUniform->set(osg::Vec3f(view_xyz[0], view_xyz[1], view_xyz[2]));
	Line 800:     viewOriginUniform->set(osg::Vec2f(xx, yy));
	Line 817:     osg::Vec2f dir0(swell_sinDir[0], swell_cosDir[0]); // This converts compass direction (North is 0, positive clockwise) to the XY plane (X is 0, positive CCW)
	Line 819:     osg::Vec2f dir1(swell_sinDir[1], swell_cosDir[1]); // This converts compass direction (North is 0, positive clockwise) to the XY plane (X is 0, positive CCW)
	Line 847: void OceanGeometry::addToOSG(osg::Group * root)
	Line 851:     stateSet->setTextureAttributeAndModes(0, gCubeMapTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 851:     stateSet->setTextureAttributeAndModes(0, gCubeMapTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 852:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 852:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 852:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 863: osg::Switch* OceanGeometry::getOceanSwitch()
	Line 870:     osg::Image* height_image = mpWaveHeightUpdate->getHeightImage();
	Line 887:     osg::Matrixd trans;
	Line 890:     mOceanMeshOffsetUniform->set(osg::Vec2f(-mOceanMeshOffset[0], -mOceanMeshOffset[1]));
	Line 915:     lees_nearWakePosUniform->set(osg::Vec4f(0.f, 0.f, 0.f, 0.f));
	Line 916:     lees_nearWakeDirSizeUniform->set(osg::Vec4f(0.f, 0.f, 0.f, 0.f));
	Line 918:     //lees_nearWakeFalloffsUniform->set(osg::Vec4f(0.f, 0.f, 0.f, 0.f));
	Line 919:     lees_nearWakeFalloffsAftUniform->set(osg::Vec4f(0.f, 0.f, 0.f, 0.f));
  D:\Development\psim\src\subview\OceanGeometry.h (195 hits)
	Line 24: class OceanGeometry : public osg::Geometry
	Line 30:     virtual osg::BoundingBox computeBound() const;
	Line 34:     void drawImplementation(osg::RenderInfo& ri) const;
	Line 37:     void addToOSG(osg::Group * root);
	Line 39:     osg::Switch* getOceanSwitch();
	Line 44:     void attachExternalUniforms(osg::StateSet *ss);
	Line 53:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 53:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 55:     osg::ref_ptr<osg::Uniform> sharpUniform;
	Line 55:     osg::ref_ptr<osg::Uniform> sharpUniform;
	Line 56:     osg::ref_ptr<osg::TexMat> texMat0, texMat1, texMat2, texMat3;
	Line 56:     osg::ref_ptr<osg::TexMat> texMat0, texMat1, texMat2, texMat3;
	Line 58:     osg::ref_ptr<osg::Uniform> cubeMapSampler;
	Line 58:     osg::ref_ptr<osg::Uniform> cubeMapSampler;
	Line 59:     osg::ref_ptr<osg::Uniform> foamMapSampler;
	Line 59:     osg::ref_ptr<osg::Uniform> foamMapSampler;
	Line 61:     osg::ref_ptr<osg::Uniform> landLeeMapSampler;
	Line 61:     osg::ref_ptr<osg::Uniform> landLeeMapSampler;
	Line 62:     osg::ref_ptr<osg::Uniform> wakeNormalMap0Sampler;
	Line 62:     osg::ref_ptr<osg::Uniform> wakeNormalMap0Sampler;
	Line 63:     osg::ref_ptr<osg::Uniform> wakeNormalMap1Sampler;
	Line 63:     osg::ref_ptr<osg::Uniform> wakeNormalMap1Sampler;
	Line 64:     osg::ref_ptr<osg::Uniform> wakeNormalMap2Sampler;
	Line 64:     osg::ref_ptr<osg::Uniform> wakeNormalMap2Sampler;
	Line 65:     osg::ref_ptr<osg::Uniform> wakeNormalMap3Sampler;
	Line 65:     osg::ref_ptr<osg::Uniform> wakeNormalMap3Sampler;
	Line 66:     osg::ref_ptr<osg::Uniform> wakeNormalMap4Sampler;
	Line 66:     osg::ref_ptr<osg::Uniform> wakeNormalMap4Sampler;
	Line 70:     osg::ref_ptr<osg::Uniform> whiteCapLevelUniform;
	Line 70:     osg::ref_ptr<osg::Uniform> whiteCapLevelUniform;
	Line 71:     osg::ref_ptr<osg::Uniform> maxWindWaveHeightUniform;
	Line 71:     osg::ref_ptr<osg::Uniform> maxWindWaveHeightUniform;
	Line 72:     osg::ref_ptr<osg::Uniform> fovPerPixelUniform;
	Line 72:     osg::ref_ptr<osg::Uniform> fovPerPixelUniform;
	Line 73:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 73:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 74:     osg::ref_ptr<osg::Uniform> duskUniform;
	Line 74:     osg::ref_ptr<osg::Uniform> duskUniform;
	Line 75:     osg::ref_ptr<osg::Uniform> viewUniform;
	Line 75:     osg::ref_ptr<osg::Uniform> viewUniform;
	Line 76:     osg::ref_ptr<osg::Uniform> viewOriginUniform;
	Line 76:     osg::ref_ptr<osg::Uniform> viewOriginUniform;
	Line 77:     osg::ref_ptr<osg::Uniform> windDirUniform;
	Line 77:     osg::ref_ptr<osg::Uniform> windDirUniform;
	Line 78:     osg::ref_ptr<osg::Uniform> windSpeedUniform;
	Line 78:     osg::ref_ptr<osg::Uniform> windSpeedUniform;
	Line 79:     osg::ref_ptr<osg::Uniform> oceanSetUniform;
	Line 79:     osg::ref_ptr<osg::Uniform> oceanSetUniform;
	Line 80:     osg::ref_ptr<osg::Uniform> oceanDriftUniform;
	Line 80:     osg::ref_ptr<osg::Uniform> oceanDriftUniform;
	Line 81:     osg::ref_ptr<osg::Uniform> useDriftSetUniform;
	Line 81:     osg::ref_ptr<osg::Uniform> useDriftSetUniform;
	Line 82:     osg::ref_ptr<osg::Uniform> duskTailLightUniform;
	Line 82:     osg::ref_ptr<osg::Uniform> duskTailLightUniform;
	Line 83:     osg::ref_ptr<osg::Uniform> duskTailLightDirUniform;
	Line 83:     osg::ref_ptr<osg::Uniform> duskTailLightDirUniform;
	Line 84:     osg::ref_ptr<osg::Uniform> rudderAngleUniform;
	Line 84:     osg::ref_ptr<osg::Uniform> rudderAngleUniform;
	Line 85:     osg::ref_ptr<osg::Uniform> mSwellHeight0Uniform;
	Line 85:     osg::ref_ptr<osg::Uniform> mSwellHeight0Uniform;
	Line 86:     osg::ref_ptr<osg::Uniform> mSwellHeight1Uniform;
	Line 86:     osg::ref_ptr<osg::Uniform> mSwellHeight1Uniform;
	Line 87:     osg::ref_ptr<osg::Uniform> mSwellWt0Uniform;
	Line 87:     osg::ref_ptr<osg::Uniform> mSwellWt0Uniform;
	Line 88:     osg::ref_ptr<osg::Uniform> mSwellWt1Uniform;
	Line 88:     osg::ref_ptr<osg::Uniform> mSwellWt1Uniform;
	Line 89:     osg::ref_ptr<osg::Uniform> mSwellK0Uniform;
	Line 89:     osg::ref_ptr<osg::Uniform> mSwellK0Uniform;
	Line 90:     osg::ref_ptr<osg::Uniform> mSwellK1Uniform;
	Line 90:     osg::ref_ptr<osg::Uniform> mSwellK1Uniform;
	Line 91:     osg::ref_ptr<osg::Uniform> mSwellPhaseOffset0Uniform;
	Line 91:     osg::ref_ptr<osg::Uniform> mSwellPhaseOffset0Uniform;
	Line 92:     osg::ref_ptr<osg::Uniform> mSwellPhaseOffset1Uniform;
	Line 92:     osg::ref_ptr<osg::Uniform> mSwellPhaseOffset1Uniform;
	Line 93:     osg::ref_ptr<osg::Uniform> mSwellDir0Uniform;
	Line 93:     osg::ref_ptr<osg::Uniform> mSwellDir0Uniform;
	Line 94:     osg::ref_ptr<osg::Uniform> mSwellDir1Uniform;
	Line 94:     osg::ref_ptr<osg::Uniform> mSwellDir1Uniform;
	Line 95:     osg::ref_ptr<osg::Uniform> mPrecipIntensityUniform;
	Line 95:     osg::ref_ptr<osg::Uniform> mPrecipIntensityUniform;
	Line 96:     osg::ref_ptr<osg::Uniform> mOceanMeshOffsetUniform;
	Line 96:     osg::ref_ptr<osg::Uniform> mOceanMeshOffsetUniform;
	Line 98:     osg::ref_ptr<osg::Uniform> fadeWhiteCapsUniform;
	Line 98:     osg::ref_ptr<osg::Uniform> fadeWhiteCapsUniform;
	Line 99:     osg::ref_ptr<osg::Uniform> blendUniform;
	Line 99:     osg::ref_ptr<osg::Uniform> blendUniform;
	Line 100:     osg::ref_ptr<osg::Uniform> periodUniform;
	Line 100:     osg::ref_ptr<osg::Uniform> periodUniform;
	Line 101:     osg::ref_ptr<osg::Uniform> amplitudeUniform;
	Line 101:     osg::ref_ptr<osg::Uniform> amplitudeUniform;
	Line 102:     osg::ref_ptr<osg::Uniform> fadeUniform;
	Line 102:     osg::ref_ptr<osg::Uniform> fadeUniform;
	Line 103:     osg::ref_ptr<osg::Uniform> swellHeightPeriodUniform;
	Line 103:     osg::ref_ptr<osg::Uniform> swellHeightPeriodUniform;
	Line 104:     osg::ref_ptr<osg::Uniform> problemTimeUniform;
	Line 104:     osg::ref_ptr<osg::Uniform> problemTimeUniform;
	Line 106:     osg::ref_ptr<osg::Uniform> reflectionCoefUniform;
	Line 106:     osg::ref_ptr<osg::Uniform> reflectionCoefUniform;
	Line 109:     osg::ref_ptr<osg::Uniform> tailLightReflectionUniform;
	Line 109:     osg::ref_ptr<osg::Uniform> tailLightReflectionUniform;
	Line 113:     osg::ref_ptr<osg::Uniform> buoyPositionsUniform;
	Line 113:     osg::ref_ptr<osg::Uniform> buoyPositionsUniform;
	Line 114:     osg::ref_ptr<osg::Uniform> numBuoysUniform;
	Line 114:     osg::ref_ptr<osg::Uniform> numBuoysUniform;
	Line 116:     osg::ref_ptr<osg::Texture2D> wakeNormalMapTexture[5];
	Line 116:     osg::ref_ptr<osg::Texture2D> wakeNormalMapTexture[5];
	Line 117:     osg::ref_ptr<osg::Image> wakeNormalMapImage[5];
	Line 117:     osg::ref_ptr<osg::Image> wakeNormalMapImage[5];
	Line 119:     osg::ref_ptr<osg::Texture2D> foamMapTexture;
	Line 119:     osg::ref_ptr<osg::Texture2D> foamMapTexture;
	Line 120:     osg::ref_ptr<osg::Image> foamMapImage;
	Line 120:     osg::ref_ptr<osg::Image> foamMapImage;
	Line 121:     osg::ref_ptr<osg::Texture2D> landLeeTexture;
	Line 121:     osg::ref_ptr<osg::Texture2D> landLeeTexture;
	Line 122:     osg::ref_ptr<osg::Image> landLeeImage;
	Line 122:     osg::ref_ptr<osg::Image> landLeeImage;
	Line 125:     osg::ref_ptr<osg::Texture2D> mHeightTexture;
	Line 125:     osg::ref_ptr<osg::Texture2D> mHeightTexture;
	Line 126:     osg::ref_ptr<osg::Texture2D> mNormalTexture;
	Line 126:     osg::ref_ptr<osg::Texture2D> mNormalTexture;
	Line 127:     osg::ref_ptr<osg::Texture2D> mRippleNormalTexture;
	Line 127:     osg::ref_ptr<osg::Texture2D> mRippleNormalTexture;
	Line 128:     osg::ref_ptr<osg::Texture2D> mRippleHeightTexture;
	Line 128:     osg::ref_ptr<osg::Texture2D> mRippleHeightTexture;
	Line 131:     osg::ref_ptr<osg::Uniform> lees_nearContactPosUniform;
	Line 131:     osg::ref_ptr<osg::Uniform> lees_nearContactPosUniform;
	Line 132:     osg::ref_ptr<osg::Uniform> lees_nearContactDirSizeUniform;
	Line 132:     osg::ref_ptr<osg::Uniform> lees_nearContactDirSizeUniform;
	Line 133:     osg::ref_ptr<osg::Uniform> lees_landLeeCenterUniform;
	Line 133:     osg::ref_ptr<osg::Uniform> lees_landLeeCenterUniform;
	Line 134:     osg::ref_ptr<osg::Uniform> lees_landLeeWidthUniform;
	Line 134:     osg::ref_ptr<osg::Uniform> lees_landLeeWidthUniform;
	Line 135:     osg::ref_ptr<osg::Uniform> lees_nearWakePosUniform;
	Line 135:     osg::ref_ptr<osg::Uniform> lees_nearWakePosUniform;
	Line 136:     osg::ref_ptr<osg::Uniform> lees_nearWakeDirSizeUniform;
	Line 136:     osg::ref_ptr<osg::Uniform> lees_nearWakeDirSizeUniform;
	Line 137:     osg::ref_ptr<osg::Uniform> lees_nearWakeHeightUniform;
	Line 137:     osg::ref_ptr<osg::Uniform> lees_nearWakeHeightUniform;
	Line 138:     osg::ref_ptr<osg::Uniform> lees_nearWakeFalloffsUniform;
	Line 138:     osg::ref_ptr<osg::Uniform> lees_nearWakeFalloffsUniform;
	Line 139:     osg::ref_ptr<osg::Uniform> lees_nearWakeFalloffsAftUniform;
	Line 139:     osg::ref_ptr<osg::Uniform> lees_nearWakeFalloffsAftUniform;
	Line 141:     osg::ref_ptr<osg::Uniform> lees_global_lee_dirUniform;
	Line 141:     osg::ref_ptr<osg::Uniform> lees_global_lee_dirUniform;
	Line 142:     osg::ref_ptr<osg::Uniform> lees_lee_min_heightUniform;
	Line 142:     osg::ref_ptr<osg::Uniform> lees_lee_min_heightUniform;
	Line 143:     osg::ref_ptr<osg::Uniform> lees_lee_max_heightUniform;
	Line 143:     osg::ref_ptr<osg::Uniform> lees_lee_max_heightUniform;
	Line 144:     osg::ref_ptr<osg::Uniform> lees_lee_min_lengthUniform;
	Line 144:     osg::ref_ptr<osg::Uniform> lees_lee_min_lengthUniform;
	Line 145:     osg::ref_ptr<osg::Uniform> lees_lee_max_lengthUniform;
	Line 145:     osg::ref_ptr<osg::Uniform> lees_lee_max_lengthUniform;
	Line 146:     osg::ref_ptr<osg::Uniform> lees_lee_dist_atten_finalUniform;
	Line 146:     osg::ref_ptr<osg::Uniform> lees_lee_dist_atten_finalUniform;
	Line 147:     osg::ref_ptr<osg::Uniform> lees_lee_dist_abeamUniform;
	Line 147:     osg::ref_ptr<osg::Uniform> lees_lee_dist_abeamUniform;
	Line 148:     osg::ref_ptr<osg::Uniform> lees_lee_dist_blend_widthUniform;
	Line 148:     osg::ref_ptr<osg::Uniform> lees_lee_dist_blend_widthUniform;
	Line 149:     osg::ref_ptr<osg::Uniform> lees_lee_atten_show_debugUniform;
	Line 149:     osg::ref_ptr<osg::Uniform> lees_lee_atten_show_debugUniform;
	Line 151:     osg::ref_ptr<osg::Uniform> wake_typeUniform;
	Line 151:     osg::ref_ptr<osg::Uniform> wake_typeUniform;
	Line 153:     osg::ref_ptr<osg::Uniform> wake_is_backingUniform;
	Line 153:     osg::ref_ptr<osg::Uniform> wake_is_backingUniform;
	Line 161:     float phillipsSpectrum(const osg::Vec2f& K);
	Line 172:     osg::ref_ptr<osg::Uniform> mHeightTextureUniform;
	Line 172:     osg::ref_ptr<osg::Uniform> mHeightTextureUniform;
	Line 174:     osg::ref_ptr<osg::Uniform> mSeaStateUniform;
	Line 174:     osg::ref_ptr<osg::Uniform> mSeaStateUniform;
	Line 175:     osg::ref_ptr<osg::Uniform> mRippleNormalTextureUniform;
	Line 175:     osg::ref_ptr<osg::Uniform> mRippleNormalTextureUniform;
	Line 176:     osg::ref_ptr<osg::Uniform> mRippleHeightTextureUniform;
	Line 176:     osg::ref_ptr<osg::Uniform> mRippleHeightTextureUniform;
	Line 178:     osg::ref_ptr<osg::Uniform> dispxUniform0;
	Line 178:     osg::ref_ptr<osg::Uniform> dispxUniform0;
	Line 179:     osg::ref_ptr<osg::Uniform> dispyUniform0;
	Line 179:     osg::ref_ptr<osg::Uniform> dispyUniform0;
	Line 192:     osg::ref_ptr<osg::Image> mNormalImage;
	Line 192:     osg::ref_ptr<osg::Image> mNormalImage;
	Line 193:     osg::ref_ptr<osg::Image> mRippleNormalImage;
	Line 193:     osg::ref_ptr<osg::Image> mRippleNormalImage;
	Line 194:     osg::ref_ptr<osg::Image> mRippleHeightImage[NUM_RIPPLE_IMAGES];
	Line 194:     osg::ref_ptr<osg::Image> mRippleHeightImage[NUM_RIPPLE_IMAGES];
	Line 196:     osg::ref_ptr<osg::Texture2D> dispxTex;
	Line 196:     osg::ref_ptr<osg::Texture2D> dispxTex;
	Line 197:     osg::ref_ptr<osg::Image> dispxImg[TILE_TIME];
	Line 197:     osg::ref_ptr<osg::Image> dispxImg[TILE_TIME];
	Line 198:     osg::ref_ptr<osg::Texture2D> dispyTex;
	Line 198:     osg::ref_ptr<osg::Texture2D> dispyTex;
	Line 199:     osg::ref_ptr<osg::Image> dispyImg[TILE_TIME];
	Line 199:     osg::ref_ptr<osg::Image> dispyImg[TILE_TIME];
	Line 202:     osg::ref_ptr<osg::MatrixTransform> mpOceanTransform;
	Line 202:     osg::ref_ptr<osg::MatrixTransform> mpOceanTransform;
	Line 203:     osg::ref_ptr<osg::Switch> mpOceanSwitch;
	Line 203:     osg::ref_ptr<osg::Switch> mpOceanSwitch;
  D:\Development\psim\src\subview\OceanMesh.cpp (37 hits)
	Line 293: void OceanMesh::draw(bool drawFarField, bool drawNearField, osg::Geometry *geo)
	Line 301:     osg::Timer timer;
	Line 302:     osg::Timer_t timer_begin, timer_end;
	Line 315:     //	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(mNumVertices,(osg::Vec3*)mVertices);
	Line 315:     //	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(mNumVertices,(osg::Vec3*)mVertices);
	Line 315:     //	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(mNumVertices,(osg::Vec3*)mVertices);
	Line 315:     //	osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(mNumVertices,(osg::Vec3*)mVertices);
	Line 316:     //	osg::ref_ptr<osg::Vec4Array> texCoords = new osg::Vec4Array(mNumVertices, (osg::Vec4f*)mAdjacents);
	Line 316:     //	osg::ref_ptr<osg::Vec4Array> texCoords = new osg::Vec4Array(mNumVertices, (osg::Vec4f*)mAdjacents);
	Line 316:     //	osg::ref_ptr<osg::Vec4Array> texCoords = new osg::Vec4Array(mNumVertices, (osg::Vec4f*)mAdjacents);
	Line 316:     //	osg::ref_ptr<osg::Vec4Array> texCoords = new osg::Vec4Array(mNumVertices, (osg::Vec4f*)mAdjacents);
	Line 318:     //	osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLES, mNumFarTriIndices, mFarTriIndices );
	Line 318:     //	osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLES, mNumFarTriIndices, mFarTriIndices );
	Line 318:     //	osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLES, mNumFarTriIndices, mFarTriIndices );
	Line 318:     //	osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLES, mNumFarTriIndices, mFarTriIndices );
	Line 319:     //	osg::ref_ptr<osg::DrawElementsUInt> deTriStrips = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_STRIP, mNumFarStripIndices, mFarStripIndices );
	Line 319:     //	osg::ref_ptr<osg::DrawElementsUInt> deTriStrips = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_STRIP, mNumFarStripIndices, mFarStripIndices );
	Line 319:     //	osg::ref_ptr<osg::DrawElementsUInt> deTriStrips = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_STRIP, mNumFarStripIndices, mFarStripIndices );
	Line 319:     //	osg::ref_ptr<osg::DrawElementsUInt> deTriStrips = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_STRIP, mNumFarStripIndices, mFarStripIndices );
	Line 323:     osg::Geometry::PrimitiveSetList list(2);
	Line 336:         osg::Geometry::PrimitiveSetList list(num_fans+1);
	Line 340:             osg::ref_ptr<osg::DrawElementsUInt> deTriFan = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_FAN, 10, &mTriFanIndices[ii*10]);
	Line 340:             osg::ref_ptr<osg::DrawElementsUInt> deTriFan = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_FAN, 10, &mTriFanIndices[ii*10]);
	Line 340:             osg::ref_ptr<osg::DrawElementsUInt> deTriFan = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_FAN, 10, &mTriFanIndices[ii*10]);
	Line 340:             osg::ref_ptr<osg::DrawElementsUInt> deTriFan = new osg::DrawElementsUInt( osg::PrimitiveSet::TRIANGLE_FAN, 10, &mTriFanIndices[ii*10]);
	Line 926:         mVertexArray = new osg::Vec3Array(mNumVertices, (osg::Vec3*)mVertices);
	Line 926:         mVertexArray = new osg::Vec3Array(mNumVertices, (osg::Vec3*)mVertices);
	Line 927:         mTexCoordArray = new osg::Vec4Array(mNumVertices, (osg::Vec4f*)mAdjacents);
	Line 927:         mTexCoordArray = new osg::Vec4Array(mNumVertices, (osg::Vec4f*)mAdjacents);
	Line 929:         mTrisSet = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, mNumFarTriIndices, mFarTriIndices);
	Line 929:         mTrisSet = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, mNumFarTriIndices, mFarTriIndices);
	Line 930:         mTriStripsSet = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_STRIP, mNumFarStripIndices, mFarStripIndices);
	Line 930:         mTriStripsSet = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLE_STRIP, mNumFarStripIndices, mFarStripIndices);
	Line 1162:         osg::Timer timer;
	Line 1163:         osg::Timer_t timer_begin, timer_end;
	Line 1258:         osg::Timer timer;
	Line 1259:         osg::Timer_t timer_begin, timer_end;
  D:\Development\psim\src\subview\OceanMesh.h (9 hits)
	Line 28:     void draw(bool drawFarField, bool drawNearField, osg::Geometry *geo);
	Line 129:     osg::ref_ptr<osg::Vec3Array> mVertexArray;
	Line 129:     osg::ref_ptr<osg::Vec3Array> mVertexArray;
	Line 130:     osg::ref_ptr<osg::Vec4Array> mTexCoordArray;
	Line 130:     osg::ref_ptr<osg::Vec4Array> mTexCoordArray;
	Line 132:     osg::ref_ptr<osg::DrawElementsUInt> mTrisSet;
	Line 132:     osg::ref_ptr<osg::DrawElementsUInt> mTrisSet;
	Line 133:     osg::ref_ptr<osg::DrawElementsUInt> mTriStripsSet;
	Line 133:     osg::ref_ptr<osg::DrawElementsUInt> mTriStripsSet;
  D:\Development\psim\src\subview\OceanMeshGenerator.cpp (8 hits)
	Line 42:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 42:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 43:     double currentTime = osg::Timer::instance()->delta_s(viewer.getStartTick(), tick);
	Line 53:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 53:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 54:     double currentTime = osg::Timer::instance()->delta_s(viewer.getStartTick(), tick);
	Line 83:     /*   osg::Timer timer;
	Line 84:     osg::Timer_t timer_begin, timer_end;
  D:\Development\psim\src\subview\OceanUpdate.cpp (2 hits)
	Line 19: void OceanUpdate::update(osg::NodeVisitor * nv, osg::Drawable * drawable)
	Line 19: void OceanUpdate::update(osg::NodeVisitor * nv, osg::Drawable * drawable)
  D:\Development\psim\src\subview\OceanUpdate.h (3 hits)
	Line 13: class OceanUpdate : public osg::Drawable::UpdateCallback
	Line 19:     virtual void update(osg::NodeVisitor * nv, osg::Drawable * drawable);
	Line 19:     virtual void update(osg::NodeVisitor * nv, osg::Drawable * drawable);
  D:\Development\psim\src\subview\OsgSubview.cpp (184 hits)
	Line 68: extern osg::ref_ptr<PrecomputeAtmoOp> precomputeOp;
	Line 73: osg::ref_ptr<PsimCameraManipulator> cameraManipulator = NULL;
	Line 74: osg::TextureCubeMap* gCubeMapTexture = NULL;
	Line 76: osg::ref_ptr<osg::Camera> mainCamera;
	Line 76: osg::ref_ptr<osg::Camera> mainCamera;
	Line 77: osg::ref_ptr<osg::Camera> nearCamera;
	Line 77: osg::ref_ptr<osg::Camera> nearCamera;
	Line 78: osg::ref_ptr<osg::Camera> secondaryCamera; // secondary rendering camera for dual views
	Line 78: osg::ref_ptr<osg::Camera> secondaryCamera; // secondary rendering camera for dual views
	Line 80: osg::ref_ptr<osg::Camera> pickCamera; // not in the sg, just used for intersection tests (marks)
	Line 80: osg::ref_ptr<osg::Camera> pickCamera; // not in the sg, just used for intersection tests (marks)
	Line 81: osg::ref_ptr<PickHandler> pickHandler = NULL;
	Line 83: osg::ref_ptr<osg::Camera> projCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 83: osg::ref_ptr<osg::Camera> projCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 84: osg::ref_ptr<osg::Camera> reflCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 84: osg::ref_ptr<osg::Camera> reflCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 87: osg::ref_ptr<osg::Camera> submergedCamera; // captures geometry below the surface
	Line 87: osg::ref_ptr<osg::Camera> submergedCamera; // captures geometry below the surface
	Line 88: osg::Texture* submergedTexture = NULL;
	Line 91: osg::TexMat* projTexMat = NULL; // holds the proj matrix for the projection cameras (accounts for overprojection and differing near/far distances)
	Line 93: osg::Texture* projTexture = NULL;
	Line 94: osg::Texture* reflTexture = NULL;
	Line 95: osg::Texture* reflAlphaTexture = NULL;
	Line 99:     mainCamera = new osg::Camera;
	Line 101:     nearCamera = new osg::Camera;
	Line 103:     pickCamera = new osg::Camera;
	Line 105:     secondaryCamera = new osg::Camera;
	Line 107:     projCamera = new osg::Camera;
	Line 110:     reflCamera = new osg::Camera;
	Line 115:     submergedCamera = new osg::Camera;
	Line 127:     osg::ArgumentParser arguments(&argc, argv);
	Line 139:     osg::ref_ptr<osgViewer::StatsHandler> statsHandler = new osgViewer::StatsHandler;
	Line 140:     statsHandler->addUserStatsLine("Mesh", osg::Vec4(1, 0, 0.5, 1), osg::Vec4(1, 0, 0.5, 0.5),
	Line 140:     statsHandler->addUserStatsLine("Mesh", osg::Vec4(1, 0, 0.5, 1), osg::Vec4(1, 0, 0.5, 0.5),
	Line 142:     statsHandler->addUserStatsLine("RootNodeCallback", osg::Vec4(0, 0.5, 0.5, 1), osg::Vec4(0, 0.5, 0.5, 0.5),
	Line 142:     statsHandler->addUserStatsLine("RootNodeCallback", osg::Vec4(0, 0.5, 0.5, 1), osg::Vec4(0, 0.5, 0.5, 0.5),
	Line 144:     statsHandler->addUserStatsLine("PFTK", osg::Vec4(1, 0, 0, 1), osg::Vec4(1, 0, 0, 0.5),
	Line 144:     statsHandler->addUserStatsLine("PFTK", osg::Vec4(1, 0, 0, 1), osg::Vec4(1, 0, 0, 0.5),
	Line 173:     osg::GraphicsContext::WindowingSystemInterface *wsi = osg::GraphicsContext::getWindowingSystemInterface();
	Line 173:     osg::GraphicsContext::WindowingSystemInterface *wsi = osg::GraphicsContext::getWindowingSystemInterface();
	Line 200: void OsgSubview::singleWindowCamera(osgViewer::Viewer& viewer, osg::Camera* mainCamera, osg::Camera* nearCamera)
	Line 200: void OsgSubview::singleWindowCamera(osgViewer::Viewer& viewer, osg::Camera* mainCamera, osg::Camera* nearCamera)
	Line 202:     osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
	Line 202:     osg::GraphicsContext::WindowingSystemInterface* wsi = osg::GraphicsContext::getWindowingSystemInterface();
	Line 205:         osg::notify(osg::NOTICE) << "Error, no WindowSystemInterface available." << std::endl;
	Line 205:         osg::notify(osg::NOTICE) << "Error, no WindowSystemInterface available." << std::endl;
	Line 212:     wsi->getScreenResolution(osg::GraphicsContext::ScreenIdentifier(0), wsiWidth, wsiHeight);
	Line 239:     osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	Line 239:     osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	Line 239:     osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	Line 251:     osg::DisplaySettings* ds = osg::DisplaySettings::instance();
	Line 251:     osg::DisplaySettings* ds = osg::DisplaySettings::instance();
	Line 256:     osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
	Line 256:     osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
	Line 256:     osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
	Line 261:     mpSecondaryImageBuffer = new osg::Image();
	Line 305:         osg::notify(osg::INFO) << "  GraphicsWindow has been created." << std::endl;
	Line 305:         osg::notify(osg::INFO) << "  GraphicsWindow has been created." << std::endl;
	Line 311:         //osg::ref_ptr<const osg::GraphicsContext::Traits> traits2 = gc->getTraits();
	Line 311:         //osg::ref_ptr<const osg::GraphicsContext::Traits> traits2 = gc->getTraits();
	Line 317:         gc->setClearColor(osg::Vec4f(0.2f, 0.2f, 0.6f, 1.0f));
	Line 322:         osg::notify(osg::NOTICE) << "  GraphicsWindow not created." << std::endl;
	Line 322:         osg::notify(osg::NOTICE) << "  GraphicsWindow not created." << std::endl;
	Line 325:     osg::Camera* master = viewer.getCamera();
	Line 352:             osg::CullSettings::COMPUTE_NEAR_FAR_MODE |
	Line 353:             osg::CullSettings::CULLING_MODE |
	Line 354:             osg::CullSettings::LOD_SCALE |
	Line 355:             osg::CullSettings::SMALL_FEATURE_CULLING_PIXEL_SIZE |
	Line 356:             osg::CullSettings::CLAMP_PROJECTION_MATRIX_CALLBACK |
	Line 357:             osg::CullSettings::NEAR_FAR_RATIO |
	Line 358:             osg::CullSettings::IMPOSTOR_ACTIVE |
	Line 359:             osg::CullSettings::DEPTH_SORT_IMPOSTOR_SPRITES |
	Line 360:             osg::CullSettings::IMPOSTOR_PIXEL_ERROR_THRESHOLD |
	Line 361:             osg::CullSettings::NUM_FRAMES_TO_KEEP_IMPOSTORS_SPRITES |
	Line 362:             osg::CullSettings::CULL_MASK |
	Line 363:             osg::CullSettings::CULL_MASK_LEFT |
	Line 364:             osg::CullSettings::CULL_MASK_RIGHT |
	Line 365:             osg::CullSettings::CLEAR_COLOR |
	Line 366:             osg::CullSettings::LIGHTING_MODE |
	Line 367:             osg::CullSettings::LIGHT;
	Line 379:     mainCamera->setViewport(new osg::Viewport(0, 0, width, height));
	Line 380:     osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(width, height));
	Line 380:     osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(width, height));
	Line 380:     osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(width, height));
	Line 389:     osg::Stencil * defaultStencil = new osg::Stencil;
	Line 389:     osg::Stencil * defaultStencil = new osg::Stencil;
	Line 390:     defaultStencil->setFunction(osg::Stencil::ALWAYS);
	Line 391:     defaultStencil->setOperation(osg::Stencil::KEEP, osg::Stencil::KEEP, osg::Stencil::KEEP);
	Line 391:     defaultStencil->setOperation(osg::Stencil::KEEP, osg::Stencil::KEEP, osg::Stencil::KEEP);
	Line 391:     defaultStencil->setOperation(osg::Stencil::KEEP, osg::Stencil::KEEP, osg::Stencil::KEEP);
	Line 392:     mainCamera->getOrCreateStateSet()->setAttributeAndModes(defaultStencil, osg::StateAttribute::ON);
	Line 394:     mainCamera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	Line 404:     //mainCamera->attach(osg::Camera::COLOR_BUFFER, pp->textureRect.get());
	Line 406:     viewer.addSlave(mainCamera, osg::Matrixd::scale(1.0, 1., 1.0), osg::Matrixd());
	Line 406:     viewer.addSlave(mainCamera, osg::Matrixd::scale(1.0, 1., 1.0), osg::Matrixd());
	Line 415:     projCamera->setClearColor(osg::Vec4(0.f, 0.f, 1.f, 0.f));
	Line 417:     projCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	Line 419:     projCamera->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 420:     projCamera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 424:     projCamera->attach(osg::Camera::COLOR_BUFFER, projTexture);
	Line 428:     reflCamera->setClearColor(osg::Vec4(0.f, 0.f, 0.f, 0.f));
	Line 430:     reflCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	Line 432:     reflCamera->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 433:     reflCamera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 438:     reflCamera->attach(osg::Camera::COLOR_BUFFER0, reflTexture);
	Line 439:     reflCamera->attach(osg::Camera::COLOR_BUFFER1, reflAlphaTexture);
	Line 445:     submergedCamera->setClearColor(osg::Vec4(0.f, 0.f, 0.f, 0.f));
	Line 447:     submergedCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	Line 449:     submergedCamera->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 450:     submergedCamera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 454:     submergedCamera->attach(osg::Camera::COLOR_BUFFER, submergedTexture);
	Line 472: osg::Texture* OsgSubview::createProjTexture(int width, int height)
	Line 474:     osg::Texture2D* texture = new osg::Texture2D();
	Line 474:     osg::Texture2D* texture = new osg::Texture2D();
	Line 478:     texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
	Line 478:     texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
	Line 479:     texture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
	Line 479:     texture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
	Line 480:     texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_BORDER);
	Line 480:     texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_BORDER);
	Line 481:     texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER);
	Line 481:     texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER);
	Line 482:     texture->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_BORDER);
	Line 482:     texture->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_BORDER);
	Line 484:     texture->setBorderColor(osg::Vec4(0., 0., 0., 0.));
	Line 489: void OsgSubview::addRenderToTextureCubeMap(osg::Camera* mainCamera, osg::Camera* nearCamera, unsigned int settings, RootNodeCallback* rootNodeCallback)
	Line 489: void OsgSubview::addRenderToTextureCubeMap(osg::Camera* mainCamera, osg::Camera* nearCamera, unsigned int settings, RootNodeCallback* rootNodeCallback)
	Line 491:     osg::Camera::RenderTargetImplementation renderImplementation = osg::Camera::FRAME_BUFFER_OBJECT;
	Line 491:     osg::Camera::RenderTargetImplementation renderImplementation = osg::Camera::FRAME_BUFFER_OBJECT;
	Line 496:     osg::ref_ptr<osg::Group> group = new osg::Group;
	Line 496:     osg::ref_ptr<osg::Group> group = new osg::Group;
	Line 496:     osg::ref_ptr<osg::Group> group = new osg::Group;
	Line 498:     osg::ref_ptr<osg::Switch> irCameraGroup = new osg::Switch;
	Line 498:     osg::ref_ptr<osg::Switch> irCameraGroup = new osg::Switch;
	Line 498:     osg::ref_ptr<osg::Switch> irCameraGroup = new osg::Switch;
	Line 501:     osg::ref_ptr< osg::TextureCubeMap > textureCM = new osg::TextureCubeMap;
	Line 501:     osg::ref_ptr< osg::TextureCubeMap > textureCM = new osg::TextureCubeMap;
	Line 501:     osg::ref_ptr< osg::TextureCubeMap > textureCM = new osg::TextureCubeMap;
	Line 505:     textureCM->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 505:     textureCM->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 506:     textureCM->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 506:     textureCM->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 507:     textureCM->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_EDGE);
	Line 507:     textureCM->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_EDGE);
	Line 508:     textureCM->setFilter(osg::TextureCubeMap::MIN_FILTER, osg::TextureCubeMap::NEAREST); //osg::TextureCubeMap::LINEAR);
	Line 508:     textureCM->setFilter(osg::TextureCubeMap::MIN_FILTER, osg::TextureCubeMap::NEAREST); //osg::TextureCubeMap::LINEAR);
	Line 508:     textureCM->setFilter(osg::TextureCubeMap::MIN_FILTER, osg::TextureCubeMap::NEAREST); //osg::TextureCubeMap::LINEAR);
	Line 509:     textureCM->setFilter(osg::TextureCubeMap::MAG_FILTER, osg::TextureCubeMap::NEAREST); //osg::TextureCubeMap::LINEAR);
	Line 509:     textureCM->setFilter(osg::TextureCubeMap::MAG_FILTER, osg::TextureCubeMap::NEAREST); //osg::TextureCubeMap::LINEAR);
	Line 509:     textureCM->setFilter(osg::TextureCubeMap::MAG_FILTER, osg::TextureCubeMap::NEAREST); //osg::TextureCubeMap::LINEAR);
	Line 535:         osg::Geode* debugCubeMapGeode = new osg::Geode();
	Line 535:         osg::Geode* debugCubeMapGeode = new osg::Geode();
	Line 540:         osg::ref_ptr<osg::Camera> cameraModelsToCube = new osg::Camera;
	Line 540:         osg::ref_ptr<osg::Camera> cameraModelsToCube = new osg::Camera;
	Line 540:         osg::ref_ptr<osg::Camera> cameraModelsToCube = new osg::Camera;
	Line 542:         osg::ref_ptr<osg::Switch> camera_switch = new osg::Switch;
	Line 542:         osg::ref_ptr<osg::Switch> camera_switch = new osg::Switch;
	Line 542:         osg::ref_ptr<osg::Switch> camera_switch = new osg::Switch;
	Line 548:         osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(tex_width, tex_height));
	Line 548:         osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(tex_width, tex_height));
	Line 548:         osg::Uniform* screenSizeUniform = new osg::Uniform("screenSize", osg::Vec2(tex_width, tex_height));
	Line 551:         cameraModelsToCube->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 555:             cameraModelsToCube->attach(osg::Camera::COLOR_BUFFER, textureCM, 0, i);
	Line 557:             cameraModelsToCube->attach(osg::Camera::COLOR_BUFFER, textureCM, 0, i, false, 4, 4);
	Line 563:             osg::ref_ptr<osg::Texture2D> fogTexture;
	Line 563:             osg::ref_ptr<osg::Texture2D> fogTexture;
	Line 566:             cameraModelsToCube->getOrCreateStateSet()->setTextureAttributeAndModes(11, fogTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 566:             cameraModelsToCube->getOrCreateStateSet()->setTextureAttributeAndModes(11, fogTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 571:         cameraModelsToCube->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	Line 586:         osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	Line 586:         osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	Line 586:         osg::ref_ptr<osg::Camera> camera = new osg::Camera;
	Line 589:         camera->setClearColor(osg::Vec4f(0.f, 0.f, 0.f, 1.0f));
	Line 591:         camera->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 593:         camera->attach(osg::Camera::COLOR_BUFFER, pp->texture[i]);
	Line 596:         camera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	Line 606:     nearCamera->setRenderOrder(osg::Camera::POST_RENDER);
	Line 609:     nearCamera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	Line 616:     //secondaryCamera->setRenderOrder(osg::Camera::POST_RENDER, 20);	
	Line 617:     secondaryCamera->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 618:     secondaryCamera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 620:     secondaryCamera->attach(osg::Camera::COLOR_BUFFER, mpSecondaryTexture);
	Line 634:     //secondaryCamera->setComputeNearFarMode(osg::CullSettings::DO_NOT_COMPUTE_NEAR_FAR);
	Line 636:     secondaryCamera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
  D:\Development\psim\src\subview\OsgSubview.h (7 hits)
	Line 28:     void singleWindowCamera(osgViewer::Viewer& viewer, osg::Camera* mainCamera, osg::Camera* nearCamera);
	Line 28:     void singleWindowCamera(osgViewer::Viewer& viewer, osg::Camera* mainCamera, osg::Camera* nearCamera);
	Line 29:     void addRenderToTextureCubeMap(osg::Camera* mainCamera, osg::Camera* nearCamera, unsigned int settings, RootNodeCallback* rootNodeCallback);
	Line 29:     void addRenderToTextureCubeMap(osg::Camera* mainCamera, osg::Camera* nearCamera, unsigned int settings, RootNodeCallback* rootNodeCallback);
	Line 30:     osg::Texture* createProjTexture(int width, int height);
	Line 31:     osg::Image* mpSecondaryImageBuffer;
	Line 32:     osg::Texture* mpSecondaryTexture;
  D:\Development\psim\src\subview\Overlay.h (1 hit)
	Line 28: class Overlay : public osg::Geode
  D:\Development\psim\src\subview\OverlayText.cpp (6 hits)
	Line 51: void OverlayText::draw(const std::string str, double xpos, double ypos, osg::RenderInfo& ri)
	Line 56: 		text->setPosition(osg::Vec3(xpos,ypos,0.));
	Line 75: 		text->setColor(osg::Vec4(mRed/255.0,mGreen/255.0,mBlue/255.0,1.0f));
	Line 94:     osg::ref_ptr<osgText::Font> font = osgText::readFontFile(fontPath);
	Line 128: 	osg::ref_ptr<osgText::Font> font = osgText::readFontFile(fontPath);
	Line 131: 	text->setColor(osg::Vec4(mRed/255.0,mGreen/255.0,mBlue/255.0,1.0f));
  D:\Development\psim\src\subview\OverlayText.h (2 hits)
	Line 25: 		void draw(const std::string str, double xpos, double ypos, osg::RenderInfo& ri);
	Line 34: 		osg::ref_ptr<osgText::Text> text;
  D:\Development\psim\src\subview\OverlayTexture.cpp (41 hits)
	Line 46: 	mBoarderSize = osg::Vec2();
	Line 68: 	mBoarderSize = osg::Vec2();
	Line 77: osg::BoundingBox OverlayTexture::computeBound() const
	Line 79:     osg::BoundingBox bbox;
	Line 80:     bbox.expandBy(osg::Vec3(-10000.f,-10000.f,-10000.f));
	Line 81:     bbox.expandBy(osg::Vec3(10000.f,10000.f,10000.f));
	Line 85: void OverlayTexture::addToOSG( osg::Group * root )
	Line 87: 	osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 87: 	osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 87: 	osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 97: 		const osg::Image* texImg = mTexture->getImage();
	Line 210: 		osg::ref_ptr<osg::Image> image = NULL;
	Line 210: 		osg::ref_ptr<osg::Image> image = NULL;
	Line 250:   mTexture->setWrap(osg::Texture2D::WRAP_S, repeatWrapS ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 250:   mTexture->setWrap(osg::Texture2D::WRAP_S, repeatWrapS ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 250:   mTexture->setWrap(osg::Texture2D::WRAP_S, repeatWrapS ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 251:   mTexture->setWrap(osg::Texture2D::WRAP_T, repeatWrapT ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 251:   mTexture->setWrap(osg::Texture2D::WRAP_T, repeatWrapT ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 251:   mTexture->setWrap(osg::Texture2D::WRAP_T, repeatWrapT ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 252:   mTexture->setWrap(osg::Texture2D::WRAP_R, repeatWrapR ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 252:   mTexture->setWrap(osg::Texture2D::WRAP_R, repeatWrapR ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 252:   mTexture->setWrap(osg::Texture2D::WRAP_R, repeatWrapR ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 265: void OverlayTexture::drawImplementation(osg::RenderInfo& ri) const
	Line 309: 	stateSet = new osg::StateSet;
	Line 312: 	osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 312: 	osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 312: 	osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 315: 	textureEnabledUniform = new osg::Uniform("textureEnabled",1.0f);
	Line 316: 	alphaUniform = new osg::Uniform("alpha",1.0f);
	Line 317: 	rotAngleUniform = new osg::Uniform("rotAngle",float(mAngle * (M_PI/180)));
	Line 318: 	drawDegreesUniform = new osg::Uniform("drawDegrees",float(mDrawDegrees * (M_PI/180)));
	Line 319: 	mRedUniform = new osg::Uniform("red", float(mRed/255.0));
	Line 320: 	mBlueUniform = new osg::Uniform("blue", float(mBlue/255.0));
	Line 321: 	mGreenUniform = new osg::Uniform("green", float(mGreen/255.0));
	Line 322: 	mUseRGBUniform = new osg::Uniform("useRGB", mUseRGB);
	Line 333: 	stateSet->setTextureAttributeAndModes(0, mTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 333: 	stateSet->setTextureAttributeAndModes(0, mTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 336:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "overlayFrag.glsl"));
	Line 342: 	stateSet->setAttributeAndModes( program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE );
	Line 342: 	stateSet->setAttributeAndModes( program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE );
	Line 345: 	stateSet->setMode( GL_DEPTH_TEST, osg::StateAttribute::OFF );
  D:\Development\psim\src\subview\OverlayTexture.h (33 hits)
	Line 17: class OverlayTexture: public osg::Geometry
	Line 21: 		OverlayTexture(const OverlayTexture& OverlayTexture,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
	Line 21: 		OverlayTexture(const OverlayTexture& OverlayTexture,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
	Line 22: 		osg::Geometry(OverlayTexture,copyop) {}
	Line 25: 		virtual osg::BoundingBox computeBound() const;
	Line 29: 		osg::Vec2 getOverlayBoarderSize(){ return mBoarderSize; }
	Line 48: 		virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 49: 		void addToOSG( osg::Group * root );
	Line 52: 		osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 52: 		osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 53: 		osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 53: 		osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 57: 		osg::ref_ptr<osg::Texture2D> mTexture;
	Line 57: 		osg::ref_ptr<osg::Texture2D> mTexture;
	Line 58: 		osg::Vec2 mBoarderSize;
	Line 75: 		osg::ref_ptr<osg::StateSet> stateSet;
	Line 75: 		osg::ref_ptr<osg::StateSet> stateSet;
	Line 77: 		osg::ref_ptr<osg::Uniform> textureEnabledUniform;
	Line 77: 		osg::ref_ptr<osg::Uniform> textureEnabledUniform;
	Line 78: 		osg::ref_ptr<osg::Uniform> alphaUniform;
	Line 78: 		osg::ref_ptr<osg::Uniform> alphaUniform;
	Line 79: 		osg::ref_ptr<osg::Uniform> rotAngleUniform;
	Line 79: 		osg::ref_ptr<osg::Uniform> rotAngleUniform;
	Line 80: 		osg::ref_ptr<osg::Uniform> drawDegreesUniform;
	Line 80: 		osg::ref_ptr<osg::Uniform> drawDegreesUniform;
	Line 81: 		osg::ref_ptr<osg::Uniform> mRedUniform;
	Line 81: 		osg::ref_ptr<osg::Uniform> mRedUniform;
	Line 82: 		osg::ref_ptr<osg::Uniform> mBlueUniform;
	Line 82: 		osg::ref_ptr<osg::Uniform> mBlueUniform;
	Line 83: 		osg::ref_ptr<osg::Uniform> mGreenUniform;
	Line 83: 		osg::ref_ptr<osg::Uniform> mGreenUniform;
	Line 84: 		osg::ref_ptr<osg::Uniform> mUseRGBUniform;
	Line 84: 		osg::ref_ptr<osg::Uniform> mUseRGBUniform;
  D:\Development\psim\src\subview\ParseEdgeInstanceVisitor.cpp (7 hits)
	Line 33: void ParseEdgeInstanceVisitor::apply(osg::Node &node)
	Line 47: void ParseEdgeInstanceVisitor::apply(osg::Switch &node)
	Line 54: void ParseEdgeInstanceVisitor::apply(osg::Geode &node)
	Line 56:     osg::Node * parent = node.getParent(0);
	Line 85: void ParseEdgeInstanceVisitor::addSwitchCallback(osg::Node* node)
	Line 91:     osg::ref_ptr<EDGESwitch> cb = new EDGESwitch(node->getName());
	Line 99:         //node->getOrCreateStateSet()->setDataVariance(osg::Object::DYNAMIC);
  D:\Development\psim\src\subview\ParseEdgeInstanceVisitor.h (5 hits)
	Line 20: class ParseEdgeInstanceVisitor : public osg::NodeVisitor
	Line 25:     virtual void apply(osg::Node &);
	Line 26:     virtual void apply(osg::Switch &);
	Line 27:     virtual void apply(osg::Geode &);
	Line 29:     void addSwitchCallback(osg::Node* node);
  D:\Development\psim\src\subview\ParseEdgeVisitor.cpp (118 hits)
	Line 37: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::entextureOn = new osg::Uniform("entexture", true);
	Line 37: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::entextureOn = new osg::Uniform("entexture", true);
	Line 37: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::entextureOn = new osg::Uniform("entexture", true);
	Line 38: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::enlightingOn = new osg::Uniform("enlighting", true);
	Line 38: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::enlightingOn = new osg::Uniform("enlighting", true);
	Line 38: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::enlightingOn = new osg::Uniform("enlighting", true);
	Line 39: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::enlightingOff = new osg::Uniform("enlighting", false);
	Line 39: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::enlightingOff = new osg::Uniform("enlighting", false);
	Line 39: osg::ref_ptr<osg::Uniform> ParseEdgeVisitor::enlightingOff = new osg::Uniform("enlighting", false);
	Line 53: void ParseEdgeVisitor::apply(osg::Node &node)
	Line 62: void ParseEdgeVisitor::apply(osg::Group &node)
	Line 72:     osg::LOD *lodNode = dynamic_cast<osg::LOD*> (&node);
	Line 72:     osg::LOD *lodNode = dynamic_cast<osg::LOD*> (&node);
	Line 86:         osg::Node* childNode = node.getChild(i);
	Line 92:             if (dynamic_cast<osg::ProxyNode*> (childNode->asGroup()) != NULL)
	Line 105:             osg::ref_ptr<osg::Node> childNode = node.getChild(i);
	Line 105:             osg::ref_ptr<osg::Node> childNode = node.getChild(i);
	Line 110:                     dynamic_cast<osg::Transform*> (childNode.get()) == NULL &&
	Line 113:                     dynamic_cast<osg::Switch*> (childNode.get()) == NULL &&
	Line 114:                     dynamic_cast<osg::LOD*> (childNode.get()) == NULL)
	Line 118:                     osg::ref_ptr<osg::Node> childOfChildNode = childNode->asGroup()->getChild(j);
	Line 118:                     osg::ref_ptr<osg::Node> childOfChildNode = childNode->asGroup()->getChild(j);
	Line 132: void ParseEdgeVisitor::apply(osg::ProxyNode &node)
	Line 138: void ParseEdgeVisitor::apply(osg::Switch &node)
	Line 154: void ParseEdgeVisitor::apply(osg::LOD &node)
	Line 174: void ParseEdgeVisitor::apply(osg::Geode &node)
	Line 177:     /*osg::Node * parent = node.getParent (0);
	Line 183:         osg::Vec3f coords = node.computeBound().center();
	Line 190:     osg::Billboard* billboard = dynamic_cast<osg::Billboard*> (&node);
	Line 190:     osg::Billboard* billboard = dynamic_cast<osg::Billboard*> (&node);
	Line 192:     osg::BoundingSphere sph = node.computeBound();
	Line 240: void ParseEdgeVisitor::fixLODs(osg::Group &node)
	Line 243:     osg::Switch *switchNode = dynamic_cast<osg::Switch*> (&node);
	Line 243:     osg::Switch *switchNode = dynamic_cast<osg::Switch*> (&node);
	Line 251:             osg::ref_ptr<osg::LOD> lodChild = dynamic_cast<osg::LOD*> (node.getChild(i));
	Line 251:             osg::ref_ptr<osg::LOD> lodChild = dynamic_cast<osg::LOD*> (node.getChild(i));
	Line 251:             osg::ref_ptr<osg::LOD> lodChild = dynamic_cast<osg::LOD*> (node.getChild(i));
	Line 255:                 osg::ref_ptr<osg::Group> newGrp = new osg::Group;
	Line 255:                 osg::ref_ptr<osg::Group> newGrp = new osg::Group;
	Line 255:                 osg::ref_ptr<osg::Group> newGrp = new osg::Group;
	Line 264:         osg::ref_ptr<osg::LOD> lodChild = dynamic_cast<osg::LOD*> (node.getChild(i));
	Line 264:         osg::ref_ptr<osg::LOD> lodChild = dynamic_cast<osg::LOD*> (node.getChild(i));
	Line 264:         osg::ref_ptr<osg::LOD> lodChild = dynamic_cast<osg::LOD*> (node.getChild(i));
	Line 270:                 osg::ref_ptr<osg::Node> childNode = lodChild->getChild(j);
	Line 270:                 osg::ref_ptr<osg::Node> childNode = lodChild->getChild(j);
	Line 281: void ParseEdgeVisitor::convertLightPoints(osg::Group &node)
	Line 289:             osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	Line 289:             osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	Line 289:             osg::ref_ptr<osg::Geode> geode = new osg::Geode;
	Line 290:             osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	Line 290:             osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	Line 290:             osg::ref_ptr<osg::Geometry> geom = new osg::Geometry;
	Line 292:             osg::ref_ptr<osg::DrawArrays> primitiveSet = new osg::DrawArrays;
	Line 292:             osg::ref_ptr<osg::DrawArrays> primitiveSet = new osg::DrawArrays;
	Line 292:             osg::ref_ptr<osg::DrawArrays> primitiveSet = new osg::DrawArrays;
	Line 295:             osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 295:             osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 295:             osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 299:             osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	Line 299:             osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	Line 299:             osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	Line 303:             osg::ref_ptr<osg::StateSet> stateSet = new osg::StateSet;
	Line 303:             osg::ref_ptr<osg::StateSet> stateSet = new osg::StateSet;
	Line 303:             osg::ref_ptr<osg::StateSet> stateSet = new osg::StateSet;
	Line 304:             stateSet->setDataVariance(osg::Object::STATIC);
	Line 305:             stateSet->setRenderingHint(osg::StateSet::DEFAULT_BIN);
	Line 306:             stateSet->setRenderBinMode(osg::StateSet::USE_RENDERBIN_DETAILS);
	Line 309:             stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 309:             stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 310:             stateSet->addUniform(new osg::Uniform("entexture", false));
	Line 311:             stateSet->addUniform(new osg::Uniform("enlighting", false));
	Line 312:             stateSet->addUniform(new osg::Uniform("lightpoint", true));
	Line 313:             stateSet->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::OFF | osg::StateAttribute::PROTECTED);
	Line 313:             stateSet->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::OFF | osg::StateAttribute::PROTECTED);
	Line 319:             geom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	Line 332: void ParseEdgeVisitor::removeMaskedChildren(osg::Group &node)
	Line 341: void ParseEdgeVisitor::handleTextures(osg::StateSet *stateset)
	Line 347:             osg::Texture* texture = dynamic_cast<osg::Texture*> (stateset->getTextureAttribute(i, osg::StateAttribute::TEXTURE));
	Line 347:             osg::Texture* texture = dynamic_cast<osg::Texture*> (stateset->getTextureAttribute(i, osg::StateAttribute::TEXTURE));
	Line 347:             osg::Texture* texture = dynamic_cast<osg::Texture*> (stateset->getTextureAttribute(i, osg::StateAttribute::TEXTURE));
	Line 357:                         texture->getImage(imageNum)->setOrigin(osg::Image::TOP_LEFT);
	Line 369: void ParseEdgeVisitor::fixSwitch(osg::Node *node)
	Line 537:                     osg::Node* childNode = node->asGroup()->getChild(i);
	Line 538:                     childNode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 538:                     childNode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 546:                     osg::Node* childNode = node->asGroup()->getChild(i);
	Line 547:                     childNode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 547:                     childNode->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 559:         node->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 559:         node->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF);
	Line 565: /*void ParseEdgeVisitor::addSwitchCallback(osg::Node* node)
	Line 567:     osg::ref_ptr<EDGESwitch> cb = new EDGESwitch(node->getName());
	Line 572:         node->getOrCreateStateSet()->setDataVariance(osg::Object::DYNAMIC);
	Line 576: void ParseEdgeVisitor::fixNames(osg::Node &node)
	Line 697:         osg::Group *grp = dynamic_cast<osg::Group*> (&node);
	Line 697:         osg::Group *grp = dynamic_cast<osg::Group*> (&node);
	Line 716:         osg::Group *grp = dynamic_cast<osg::Group*> (&node);
	Line 716:         osg::Group *grp = dynamic_cast<osg::Group*> (&node);
	Line 759: void ParseEdgeVisitor::fixTextureWraps(osg::Texture *tex)
	Line 844:                     tex->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_BORDER);
	Line 844:                     tex->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_BORDER);
	Line 849:                     tex->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER);
	Line 849:                     tex->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER);
	Line 856: void ParseEdgeVisitor::checkStateForOverride(osg::StateSet *stateSet)
	Line 863:     osg::StateAttribute *entexture = stateSet->getTextureAttribute(0, osg::StateAttribute::TEXTURE);
	Line 863:     osg::StateAttribute *entexture = stateSet->getTextureAttribute(0, osg::StateAttribute::TEXTURE);
	Line 864:     osg::StateAttribute::GLModeValue enlighting = stateSet->getMode(GL_LIGHTING);
	Line 869:     if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF) ||
	Line 869:     if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::OFF) ||
	Line 870:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF))
	Line 870:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF))
	Line 873:     else if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON) ||
	Line 873:     else if (enlighting == (osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON) ||
	Line 874:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::ON))
	Line 874:             enlighting == (osg::StateAttribute::PROTECTED | osg::StateAttribute::ON))
	Line 880: std::vector<osg::Node *> *ParseEdgeVisitor::getBadNodes()
	Line 890: std::vector<osg::Texture*> *ParseEdgeVisitor::getTextureList()
	Line 895: std::vector<osg::BoundingSphere> *ParseEdgeVisitor::getBoundingSpheres()
  D:\Development\psim\src\subview\ParseEdgeVisitor.h (28 hits)
	Line 19: class ParseEdgeVisitor : public osg::NodeVisitor
	Line 24:     virtual void apply(osg::Node &);
	Line 25:     virtual void apply(osg::Group &);
	Line 26:     virtual void apply(osg::LOD &);
	Line 27:     virtual void apply(osg::ProxyNode &node);
	Line 28:     virtual void apply(osg::Switch &);
	Line 29:     virtual void apply(osg::Geode &);
	Line 31:     void handleTextures(osg::StateSet *stateset);
	Line 32:     void fixSwitch(osg::Node *node);
	Line 33:     //void addSwitchCallback(osg::Node* node);
	Line 34:     void fixNames(osg::Node &);
	Line 35:     void fixTextureWraps(osg::Texture *tex);
	Line 36:     void fixLODs(osg::Group &);
	Line 37:     void removeMaskedChildren(osg::Group &node);
	Line 38:     void convertLightPoints(osg::Group &node);
	Line 39:     std::vector<osg::Node *> * getBadNodes();
	Line 41:     std::vector<osg::Texture*> * getTextureList();
	Line 42:     std::vector<osg::BoundingSphere> * getBoundingSpheres();
	Line 43:     void checkStateForOverride(osg::StateSet *stateSet);
	Line 46:     std::vector <osg::Node *> badNodes;
	Line 48:     std::vector <osg::Texture*> textureList;
	Line 49:     std::vector<osg::BoundingSphere> mBoundingSphereList;
	Line 50:     static osg::ref_ptr<osg::Uniform> entextureOn;
	Line 50:     static osg::ref_ptr<osg::Uniform> entextureOn;
	Line 51:     static osg::ref_ptr<osg::Uniform> enlightingOn;
	Line 51:     static osg::ref_ptr<osg::Uniform> enlightingOn;
	Line 52:     static osg::ref_ptr<osg::Uniform> enlightingOff;
	Line 52:     static osg::ref_ptr<osg::Uniform> enlightingOff;
  D:\Development\psim\src\subview\ParseInstanceVisitor.cpp (29 hits)
	Line 79: void ParseInstanceVisitor::apply(osg::Group &node)
	Line 107:             osg::ref_ptr<osg::Geode> geode = (osg::Geode*)node.getChild(ii);
	Line 107:             osg::ref_ptr<osg::Geode> geode = (osg::Geode*)node.getChild(ii);
	Line 107:             osg::ref_ptr<osg::Geode> geode = (osg::Geode*)node.getChild(ii);
	Line 151: ParseInstanceVisitor::apply(osg::Switch &node)
	Line 192: ParseInstanceVisitor::apply(osg::MatrixTransform &node)
	Line 198: ParseInstanceVisitor::apply(osg::Geode &node)
	Line 200:     osg::Node * parent = node.getParent(0);
	Line 274:             osg::ComputeBoundsVisitor bb;
	Line 277:             osg::Vec3f bboxMax = bb.getBoundingBox()._max;
	Line 278:             osg::Vec3f bboxMin = bb.getBoundingBox()._min;
	Line 280:             osg::Vec3f mastWakePos = (bboxMax + bboxMin) * 0.5;
	Line 338:                 AddScrewOp* screwOp = new AddScrewOp(dynamic_cast<osg::MatrixTransform*> (parent), mVehicle, prop->getPropPosition(), screwScale);
	Line 341:                 osg::Vec3f propeller_pos = prop->getPropPosition();
	Line 348:                     osg::Vec3f propeller_pos = prop->getPropPosition();
	Line 408:                 osg::Vec3f sailTopPivot = node.getBoundingBox().center() * mVehicle->getScale();
	Line 417:                 osg::Vec3f sailBasePivot = node.getBoundingBox().center() * mVehicle->getScale();
	Line 660:             osg::Vec3f stack_pos = node.computeBound().center();
	Line 746:             osg::ref_ptr<GWSBearing> brng = gws->addBearing(&node);
	Line 786:                 osg::ref_ptr<GWSTilt> tilt = gws->addTilt(&node);
	Line 841:                 osg::Vec3f bowWakePivot = node.getBoundingBox().center() * mVehicle->getScale();
	Line 847:                 osg::Vec3f bowWakeRightPivot = node.getBoundingBox().center() * mVehicle->getScale();
	Line 853:                 osg::Vec3f bowWakeLeftPivot = node.getBoundingBox().center() * mVehicle->getScale();
	Line 870:             osg::MatrixTransform* matrix = dynamic_cast<osg::MatrixTransform*> (parent);
	Line 870:             osg::MatrixTransform* matrix = dynamic_cast<osg::MatrixTransform*> (parent);
	Line 873:                 //osg::Matrixd rot;
	Line 941:                     osg::Vec3f position = node.computeBound().center();
	Line 961:     for (std::vector<osg::Node*>::iterator it = mShapeNodes.begin(); it != mShapeNodes.end(); it++)
	Line 965: std::vector<osg::Geode*>* ParseInstanceVisitor::getLights()
  D:\Development\psim\src\subview\ParseInstanceVisitor.h (10 hits)
	Line 15: class ParseInstanceVisitor : public osg::NodeVisitor
	Line 20:     virtual void apply(osg::Group &);
	Line 21:     virtual void apply(osg::MatrixTransform &);
	Line 22:     virtual void apply(osg::Geode &);
	Line 23:     virtual void apply(osg::Switch &);
	Line 25:     //	std::vector<osg::Geode*>* getSmokePivots() { return &mSmokePivots; }
	Line 27:     std::vector<osg::Geode*>* getLights();
	Line 35:     //	std::vector<osg::Geode*> mSmokePivots;
	Line 36:     std::vector<osg::Geode*> mLights;
	Line 37:     std::vector<osg::Node*> mShapeNodes;
  D:\Development\psim\src\subview\ParseModelVisitor.cpp (7 hits)
	Line 23: void ParseModelVisitor::apply(osg::Group &node)
	Line 158: std::vector<osg::Group *> * ParseModelVisitor::getMatrixTransforms()
	Line 163: std::vector<osg::Group *> * ParseModelVisitor::getSwitches()
	Line 168: std::vector<osg::Group *> * ParseModelVisitor::getNumbers()
	Line 173: std::vector<osg::Geode *> * ParseModelVisitor::getGeodesToPrune()
	Line 178: std::vector<osg::Node *> * ParseModelVisitor::getThrowaway()
	Line 183: std::map<std::string, std::vector<osg::Group *> > * ParseModelVisitor::getSwitchMap()
  D:\Development\psim\src\subview\ParseModelVisitor.h (14 hits)
	Line 12: class ParseModelVisitor : public osg::NodeVisitor
	Line 17:     virtual void apply(osg::Group &);
	Line 19:     std::vector<osg::Group *> * getMatrixTransforms();
	Line 20:     std::vector<osg::Group *> * getSwitches();
	Line 21:     std::vector<osg::Group *> * getNumbers();
	Line 22:     std::vector<osg::Node *> * getThrowaway();
	Line 23:     std::vector<osg::Geode *> * getGeodesToPrune();
	Line 24:     std::map <std::string, std::vector<osg::Group *> > * getSwitchMap();
	Line 30:     std::vector<osg::Group *> _matrixTransforms;
	Line 31:     std::vector<osg::Group *> _switches;
	Line 32:     std::vector<osg::Group *> _numbers;
	Line 33:     std::map<std::string, std::vector<osg::Group* > > _switchMap;
	Line 36:     std::vector <osg::Node *> _throwaway;
	Line 39:     std::vector<osg::Geode *> _geodesToPrune;
  D:\Development\psim\src\subview\Particle.cpp (3 hits)
	Line 26: Particle::Particle(osg::Vec3f& position, float rotation)
	Line 42: void Particle::setPosition(const osg::Vec3f& position)
	Line 50: const osg::Vec3f& Particle::getPosition() const
  D:\Development\psim\src\subview\Particle.h (4 hits)
	Line 17:     Particle(osg::Vec3f& position, float rotation);
	Line 21:     void setPosition(const osg::Vec3f& position);
	Line 22:     const osg::Vec3f& getPosition() const;
	Line 32:     osg::Vec3f mPosition; // Position relative to particle system center
  D:\Development\psim\src\subview\ParticleGeom.cpp (69 hits)
	Line 60:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 60:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 61:     osg::ref_ptr<osg::Program> program = new osg::Program();
	Line 61:     osg::ref_ptr<osg::Program> program = new osg::Program();
	Line 61:     osg::ref_ptr<osg::Program> program = new osg::Program();
	Line 64:     mGeode = (osg::Geode*)osgDB::readNodeFile("ps" + ps->mShaderName + ".ive");
	Line 70:             mGeometry = (osg::Geometry*)(mGeode->getDrawable(0));
	Line 76:                 osg::StateSet::UniformList ulist = stateSet->getUniformList();
	Line 132:                     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, ps->mShaderName + ".glsl"));
	Line 133:                     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, ps->mShaderName + ".glsl"));
	Line 134:                     stateSet->setAttributeAndModes(program, osg::StateAttribute::ON);
	Line 152:     mGeometry = new osg::Geometry();
	Line 155:     stateSet = new osg::StateSet;
	Line 158:     osg::ref_ptr<osg::Image> img = new osg::Image;
	Line 158:     osg::ref_ptr<osg::Image> img = new osg::Image;
	Line 158:     osg::ref_ptr<osg::Image> img = new osg::Image;
	Line 160:     osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	Line 160:     osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	Line 160:     osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	Line 161:     texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 161:     texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 162:     texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 162:     texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 163:     texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 163:     texture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 164:     texture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 164:     texture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 166:     stateSet->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 166:     stateSet->setTextureAttributeAndModes(0, texture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 167:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 171:     eyeAboveUniform = new osg::Uniform("eyeAbove", false);
	Line 174:     viewPositionUniform = new osg::Uniform("viewPosition", osg::Vec3f(0.0, 0.0, 0.0));
	Line 174:     viewPositionUniform = new osg::Uniform("viewPosition", osg::Vec3f(0.0, 0.0, 0.0));
	Line 176:     globalTimeUniform = new osg::Uniform("globalTime", 0.f);
	Line 179:     windMovementDirUniform = new osg::Uniform("windMovementDir", osg::Vec3f(0.f, 0.f, 0.f));
	Line 179:     windMovementDirUniform = new osg::Uniform("windMovementDir", osg::Vec3f(0.f, 0.f, 0.f));
	Line 181:     windDispUniform = new osg::Uniform("windDisp", osg::Vec2f(0.f, 0.f));
	Line 181:     windDispUniform = new osg::Uniform("windDisp", osg::Vec2f(0.f, 0.f));
	Line 184:     OSDispUniform = new osg::Uniform("OSDisp", osg::Vec2f(0.f, 0.f));
	Line 184:     OSDispUniform = new osg::Uniform("OSDisp", osg::Vec2f(0.f, 0.f));
	Line 187:     intensityUniform = new osg::Uniform("intensity", 0.f);
	Line 190:     zoomUniform = new osg::Uniform("zoom", 1.f);
	Line 192:     mvpUniform = new osg::Uniform("mvp", osg::Matrixf::identity());
	Line 192:     mvpUniform = new osg::Uniform("mvp", osg::Matrixf::identity());
	Line 195:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, ps->mShaderName + ".glsl"));
	Line 196:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, ps->mShaderName + ".glsl"));
	Line 199:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 199:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 199:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 201:     stateSet->setAttributeAndModes(depth, osg::StateAttribute::ON);
	Line 202:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 204:     osg::ref_ptr<osg::DrawElementsUInt> d0 = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0, (unsigned int*) NULL);
	Line 204:     osg::ref_ptr<osg::DrawElementsUInt> d0 = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0, (unsigned int*) NULL);
	Line 204:     osg::ref_ptr<osg::DrawElementsUInt> d0 = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0, (unsigned int*) NULL);
	Line 204:     osg::ref_ptr<osg::DrawElementsUInt> d0 = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, 0, (unsigned int*) NULL);
	Line 210:     stateSet->setMode(GL_CULL_FACE, osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF);
	Line 210:     stateSet->setMode(GL_CULL_FACE, osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF);
	Line 212:     mGeode = new osg::Geode();
	Line 252:     extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 252:     extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 253:     osg::Matrixf proj, view, trans, scale, mvp;
	Line 260:     osg::Vec3 hpr = os->getContactHPR();
	Line 262:     osg::Vec3f windVec = ps->getWindVec();
	Line 263:     osg::Vec3f wv(windVec.x(), windVec.y(), 0.f);
	Line 264:     osg::Vec3f tr(-speed * cos(hpr[0] * M_PI / 180.f), -speed * sin(hpr[0] * M_PI / 180.f), 0.f);
	Line 265:     osg::Vec3f relWindDir = tr + wv;
	Line 268:     OSDispUniform->set(osg::Vec2f(SubviewUtils::DoubleToFloat(Shared->OSDisplacement[0]), SubviewUtils::DoubleToFloat(Shared->OSDisplacement[1])));
	Line 269:     windDispUniform->set(osg::Vec2f(SubviewUtils::DoubleToFloat(Shared->windDisplacement[0]), SubviewUtils::DoubleToFloat(Shared->windDisplacement[1])));
	Line 283:     osg::Vec3f eye, center, up;
  D:\Development\psim\src\subview\ParticleGeom.h (27 hits)
	Line 22: class ParticleGeom// : public osg::Geometry
	Line 26:     //	ParticleGeom(const ParticleGeom& ParticleGeom,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
	Line 26:     //	ParticleGeom(const ParticleGeom& ParticleGeom,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
	Line 27:     //	    osg::Geometry(ParticleGeom,copyop) {}
	Line 35:     osg::ref_ptr<osg::Geometry> mGeometry;
	Line 35:     osg::ref_ptr<osg::Geometry> mGeometry;
	Line 36:     osg::ref_ptr<osg::Geode> mGeode;
	Line 36:     osg::ref_ptr<osg::Geode> mGeode;
	Line 50:     osg::ref_ptr<osg::Uniform> mvpUniform;
	Line 50:     osg::ref_ptr<osg::Uniform> mvpUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> zoomUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> zoomUniform;
	Line 52:     osg::ref_ptr<osg::Uniform> viewPositionUniform;
	Line 52:     osg::ref_ptr<osg::Uniform> viewPositionUniform;
	Line 53:     osg::ref_ptr<osg::Uniform> windMovementDirUniform;
	Line 53:     osg::ref_ptr<osg::Uniform> windMovementDirUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> windDispUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> windDispUniform;
	Line 55:     osg::ref_ptr<osg::Uniform> OSDispUniform;
	Line 55:     osg::ref_ptr<osg::Uniform> OSDispUniform;
	Line 56:     osg::ref_ptr<osg::Uniform> intensityUniform;
	Line 56:     osg::ref_ptr<osg::Uniform> intensityUniform;
	Line 57:     osg::ref_ptr<osg::Uniform> globalTimeUniform;
	Line 57:     osg::ref_ptr<osg::Uniform> globalTimeUniform;
	Line 58:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 58:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 60:     typedef std::map<std::string, osg::StateSet::RefUniformPair>::iterator UniformIterator;
  D:\Development\psim\src\subview\ParticleGeomUpdate.cpp (2 hits)
	Line 20: void ParticleGeomUpdate::update(osg::NodeVisitor * nv, osg::Drawable * drawable)
	Line 20: void ParticleGeomUpdate::update(osg::NodeVisitor * nv, osg::Drawable * drawable)
  D:\Development\psim\src\subview\ParticleGeomUpdate.h (3 hits)
	Line 15: class ParticleGeomUpdate : public osg::Drawable::UpdateCallback
	Line 20:     virtual void update(osg::NodeVisitor * nv, osg::Drawable * drawable);
	Line 20:     virtual void update(osg::NodeVisitor * nv, osg::Drawable * drawable);
  D:\Development\psim\src\subview\ParticleSource.cpp (10 hits)
	Line 38: ParticleSource::ParticleSource(osg::Vec3f& position, float spawnRate, float startingTime)
	Line 70: const osg::Vec3f& ParticleSource::getPosition() const
	Line 78: void ParticleSource::setPosition(const osg::Vec3f& position)
	Line 88: void ParticleSource::setSpawnPositionRange(const osg::Vec3f& minValues, const osg::Vec3f& maxValues)
	Line 88: void ParticleSource::setSpawnPositionRange(const osg::Vec3f& minValues, const osg::Vec3f& maxValues)
	Line 98: void ParticleSource::getSpawnPositionRange(osg::Vec3f& minValues, osg::Vec3f& maxValues)
	Line 98: void ParticleSource::getSpawnPositionRange(osg::Vec3f& minValues, osg::Vec3f& maxValues)
	Line 247:     osg::Vec3f position_range = mMaxSpawnPosition - mMinSpawnPosition;
	Line 248:     //osg::Vec3f newPosition(effects->getRandomNum() * positionRange.x() + mMinSpawnPosition.x(),
	Line 251:     osg::Vec3f new_position((position_range.x() != 0 ? fmod((float) (rand() / 100.0), position_range.x()) : 0.0f) + mMinSpawnPosition.x(),
  D:\Development\psim\src\subview\ParticleSource.h (12 hits)
	Line 22:     ParticleSource(osg::Vec3f& position, float spawnRate, float initialTime);
	Line 29:     const osg::Vec3f& getPosition() const;
	Line 30:     void setPosition(const osg::Vec3f& position);
	Line 33:     void setSpawnPositionRange(const osg::Vec3f& minValues, const osg::Vec3f& maxValues);
	Line 33:     void setSpawnPositionRange(const osg::Vec3f& minValues, const osg::Vec3f& maxValues);
	Line 34:     void getSpawnPositionRange(osg::Vec3f& minValues, osg::Vec3f& maxValues);
	Line 34:     void getSpawnPositionRange(osg::Vec3f& minValues, osg::Vec3f& maxValues);
	Line 50:     void getRandPosVel(osg::Vec3f &pos, osg::Vec3f &vel);
	Line 50:     void getRandPosVel(osg::Vec3f &pos, osg::Vec3f &vel);
	Line 57:     osg::Vec3f mPosition; // position of source in 3space
	Line 66:     osg::Vec3f mMaxSpawnPosition; // Vector representing the maximum value of a new particle's position in each of the 3 dimensions
	Line 70:     osg::Vec3f mMinSpawnPosition; // Vector representing the minimum value of a new particle's position in each of the 3 dimensions
  D:\Development\psim\src\subview\ParticleSystem.cpp (79 hits)
	Line 85: mSwitch(new osg::Switch())
	Line 102: ParticleSystem::ParticleSystem(osg::Camera* camera, double latitude, double longitude, double height,
	Line 103:         float heading, const osg::Vec3f& dimensions, float particleWidth,
	Line 143: mSwitch(new osg::Switch())
	Line 191:     mpSystemTransform = new osg::MatrixTransform;
	Line 194:             osg::Matrix::rotate(osg::inDegrees(-mHeading), 0.0f, 0.0f, 1.0f) *
	Line 194:             osg::Matrix::rotate(osg::inDegrees(-mHeading), 0.0f, 0.0f, 1.0f) *
	Line 195:             osg::Matrix::translate(mPosition.x(), mPosition.y(), mPosition.z())
	Line 210: void ParticleSystem::setPosition(const osg::Vec3f& position)
	Line 218: const osg::Vec3f& ParticleSystem::getPosition() const
	Line 243: void ParticleSystem::getBoundingBox(std::vector<osg::Vec3f>& bounds) const
	Line 247:     osg::Matrix system_matrix = mpSystemTransform->getMatrix();
	Line 251:         osg::Vec3f new_point;
	Line 264:         osg::Vec4 new_point4(new_point.x(), new_point.y(), new_point.z(), 0.f);
	Line 265:         osg::Vec4 res = system_matrix * new_point4;
	Line 275: void ParticleSystem::setDimensions(const osg::Vec3f& dimensions)
	Line 283: const osg::Vec3f& ParticleSystem::getDimensions() const
	Line 586: const osg::Vec3f& ParticleSystem::getWindVec()
	Line 620: void ParticleSystem::removeSource(osg::Vec3f& position)
	Line 651: void ParticleSystem::AngleAxisRotate(osg::Vec3f p, float theta, osg::Vec3f r, osg::Vec3f &q)
	Line 651: void ParticleSystem::AngleAxisRotate(osg::Vec3f p, float theta, osg::Vec3f r, osg::Vec3f &q)
	Line 651: void ParticleSystem::AngleAxisRotate(osg::Vec3f p, float theta, osg::Vec3f r, osg::Vec3f &q)
	Line 688:     osg::Matrix system_matrix = mpSystemTransform->getMatrix();
	Line 726:     osg::Vec3f look_at_vec_orig(0.0, -1.0, 0.0);
	Line 727:     osg::Vec3f right_vec_orig(1.0, 0.0, 0.0);
	Line 728:     osg::Vec3f up_vec(0.0, 0.0, 1.0);
	Line 741:     osg::Vec3f eye_pt, center, dir, up;
	Line 749:             osg::Vec3f particle_pos = (*particle_itr)->getPosition();
	Line 751:             osg::Vec4 new_point4(particle_pos.x(), particle_pos.y(), particle_pos.z(), 0.f);
	Line 752:             osg::Vec4 res = system_matrix * new_point4;
	Line 753:             osg::Vec3f new_particle_pos(res[0], res[1], res[2]);
	Line 755:             osg::Vec3f obj_to_camera = new_particle_pos * -1.0f;
	Line 759:             osg::Vec3f up_aux;
	Line 763:             osg::Vec3f axis(-obj_to_camera.x(), -obj_to_camera.y(), -obj_to_camera.z());
	Line 768:             osg::Vec3f right_vec;
	Line 772:             osg::Vec3f ll_vec, lr_vec, ul_vec, ur_vec;
	Line 783:             osg::Vec3f result_ll, result_ur, result_lr, result_ul;
	Line 952:             osg::Vec3f pos = (*particle_itr)->getPosition();
	Line 954:             osg::Vec4 pf_pos(pos.x(), pos.y(), pos.z(), 0.f);
	Line 956:             osg::Vec4 res = system_matrix * pf_pos;
	Line 957:             osg::Vec3 pos_worldspace(res[0], res[1], res[2]);
	Line 959:             osg::Vec3f pos_world(pos_worldspace[0], pos_worldspace[1], pos_worldspace[2]);
	Line 961:             osg::Vec3f midpoint = pos_world;
	Line 963:             osg::Vec3f eye_point(eye_pt[0], eye_pt[1], eye_pt[2]);
	Line 965:             osg::Vec3f normal = midpoint - eye_point;
	Line 966:             osg::Vec3f width_vec;
	Line 967:             width_vec = osg::Vec3f(0., 0., 0.)^(normal);
	Line 969:             osg::Vec3f ll, lr, ul, ur;
	Line 970:             osg::Vec3f half_width = width_vec * 0.5f * mParticleWidth;
	Line 1037:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpVertices);
	Line 1037:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpVertices);
	Line 1037:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpVertices);
	Line 1037:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpVertices);
	Line 1040:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array(num_vertices, (osg::Vec2*)mpTexCoords);
	Line 1040:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array(num_vertices, (osg::Vec2*)mpTexCoords);
	Line 1040:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array(num_vertices, (osg::Vec2*)mpTexCoords);
	Line 1040:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array(num_vertices, (osg::Vec2*)mpTexCoords);
	Line 1042:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(num_vertices, (osg::Vec4*)mpColorArray);
	Line 1042:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(num_vertices, (osg::Vec4*)mpColorArray);
	Line 1042:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(num_vertices, (osg::Vec4*)mpColorArray);
	Line 1042:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array(num_vertices, (osg::Vec4*)mpColorArray);
	Line 1044:     mParticleGeom->mGeometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	Line 1048:         osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpNormalArray);
	Line 1048:         osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpNormalArray);
	Line 1048:         osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpNormalArray);
	Line 1048:         osg::ref_ptr<osg::Vec3Array> normals = new osg::Vec3Array(num_vertices, (osg::Vec3*)mpNormalArray);
	Line 1050:         mParticleGeom->mGeometry->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);
	Line 1055:         osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, mNumIndices, mpIndices);
	Line 1055:         osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, mNumIndices, mpIndices);
	Line 1055:         osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, mNumIndices, mpIndices);
	Line 1055:         osg::ref_ptr<osg::DrawElementsUInt> deTris = new osg::DrawElementsUInt(osg::PrimitiveSet::TRIANGLES, mNumIndices, mpIndices);
	Line 1084:                 osg::Matrix::rotate(osg::inDegrees(-mHeading), 0.0f, 0.0f, 1.0f) *
	Line 1084:                 osg::Matrix::rotate(osg::inDegrees(-mHeading), 0.0f, 0.0f, 1.0f) *
	Line 1085:                 osg::Matrix::translate(mPosition.x(), mPosition.y(), mPosition.z())
	Line 1106:         osg::Vec3f wind_vec(sin(wind_heading_rads), cos(wind_heading_rads), 0.0f);
	Line 1123: void ParticleSystem::setOSGRoot(osg::Group * root)
	Line 1140: void ParticleSystem::removeOSGRoot(osg::Group * root)
	Line 1147: void ParticleSystem::setCamera(osg::Camera* camera)
	Line 1152: osg::Camera* ParticleSystem::getCamera()
  D:\Development\psim\src\subview\ParticleSystem.h (24 hits)
	Line 34:     ParticleSystem(osg::Camera* camera, double latitude, double longitude, double height, float heading,
	Line 35:                    const osg::Vec3f& dimensions, float particleWidth, float particleHeight);
	Line 40:     void setOSGRoot(osg::Group * _root);
	Line 41:     void removeOSGRoot(osg::Group * _root);
	Line 45:     void setPosition(const osg::Vec3f& position);
	Line 46:     const osg::Vec3f& getPosition() const;
	Line 48:     void setDimensions(const osg::Vec3f& dimensions);
	Line 49:     const osg::Vec3f& getDimensions() const;
	Line 59:     void getBoundingBox(std::vector<osg::Vec3f>& bounds) const;
	Line 114:     const osg::Vec3f& getWindVec();
	Line 121:     void removeSource(osg::Vec3f& position); // sources can be removed simply by position.
	Line 125:     void AngleAxisRotate(osg::Vec3f p, float theta, osg::Vec3f r, osg::Vec3f &q);
	Line 125:     void AngleAxisRotate(osg::Vec3f p, float theta, osg::Vec3f r, osg::Vec3f &q);
	Line 125:     void AngleAxisRotate(osg::Vec3f p, float theta, osg::Vec3f r, osg::Vec3f &q);
	Line 127:     void setCamera(osg::Camera* camera);
	Line 129:     osg::Camera* getCamera();
	Line 148:     osg::Vec3f mPosition; // current position of center point of particle bounding volume, relative to ownship
	Line 149:     osg::Vec3f mDimensions; // dimensions of particle bounding volume axes
	Line 180:     osg::ref_ptr<osg::MatrixTransform> mpSystemTransform; // transform needed to get to particle system
	Line 180:     osg::ref_ptr<osg::MatrixTransform> mpSystemTransform; // transform needed to get to particle system
	Line 181:     osg::ref_ptr<osg::Switch> mSwitch; // switch located 
	Line 181:     osg::ref_ptr<osg::Switch> mSwitch; // switch located 
	Line 193:     osg::Vec3f mWindVec;
	Line 195:     osg::Camera* mCamera;
  D:\Development\psim\src\subview\PBO.cpp (1 hit)
	Line 28: void PBO::operator()(osg::RenderInfo& renderInfo) const
  D:\Development\psim\src\subview\PBO.h (2 hits)
	Line 13: class PBO : public osg::Camera::DrawCallback
	Line 19:     virtual void operator()(osg::RenderInfo& renderInfo) const;
  D:\Development\psim\src\subview\PickHandler.cpp (13 hits)
	Line 24: PickHandler::PickHandler(osg::Camera *_pickCamera)
	Line 48:                 osg::ref_ptr<osgGA::GUIEventAdapter> event = new osgGA::GUIEventAdapter(ea);
	Line 65:     osg::Vec3f eye, center, dir, up;
	Line 66:     osg::Vec3f w;
	Line 75:     osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
	Line 105:                 osg::NodePath nodePath = hit->nodePath;
	Line 106:                 for (osg::NodePath::iterator iter = nodePath.begin();
	Line 123:                         osg::Vec3f w(hit->getWorldIntersectPoint());
	Line 179:     osg::Vec3f eye, center, dir, up;
	Line 180:     osg::Vec3f w;
	Line 187:     osg::ref_ptr<osgUtil::LineSegmentIntersector> intersector =
	Line 205:                 osg::NodePath nodePath = hit->nodePath;
	Line 206:                 for (osg::NodePath::iterator iter = nodePath.begin();
  D:\Development\psim\src\subview\PickHandler.h (2 hits)
	Line 13:     PickHandler(osg::Camera *_pickCamera);
	Line 22:     osg::Camera *pickCamera;
  D:\Development\psim\src\subview\PickNodeCallback.cpp (4 hits)
	Line 19: extern osg::ref_ptr<PickHandler> pickHandler;
	Line 26: void PickNodeCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 26: void PickNodeCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 37:     osg::ref_ptr<DeletePickNodeOp> deletePickNodeOp = new DeletePickNodeOp(node);
  D:\Development\psim\src\subview\PickNodeCallback.h (3 hits)
	Line 14: class PickNodeCallback : public osg::NodeCallback
	Line 20:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	Line 20:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
  D:\Development\psim\src\subview\PickOp.cpp (4 hits)
	Line 28: void PickOp::operator()(osg::Object* obj)
	Line 37:         osg::Node *pNode = new osg::Node();
	Line 37:         osg::Node *pNode = new osg::Node();
	Line 39:         osg::ref_ptr<PickNodeCallback> pickNode = new PickNodeCallback();
  D:\Development\psim\src\subview\PickOp.h (2 hits)
	Line 13: class PickOp : public osg::Operation
	Line 19:     void operator()(osg::Object* obj);
  D:\Development\psim\src\subview\PivotsVisitor.cpp (5 hits)
	Line 19: void PivotsVisitor::apply(osg::Geode& node)
	Line 25:             pivotGeodes.push_back((osg::Geode*) &node);
	Line 29: 			pivotsWithUpdate.push_back((osg::Geode*) &node);
	Line 35: std::vector<osg::Geode*> * PivotsVisitor::getPivotGeodes()
	Line 40: std::vector<osg::Geode*> * PivotsVisitor::getUpdatePivotGeodes()
  D:\Development\psim\src\subview\PivotsVisitor.h (6 hits)
	Line 15: class PivotsVisitor : public osg::NodeVisitor
	Line 23:     virtual void apply(osg::Geode &);
	Line 24:     std::vector<osg::Geode *>* getPivotGeodes();
	Line 25:     std::vector<osg::Geode *>* getUpdatePivotGeodes();
	Line 28:     std::vector<osg::Geode *> pivotGeodes;
	Line 29:     std::vector<osg::Geode *> pivotsWithUpdate;
  D:\Development\psim\src\subview\PostProcessing.cpp (90 hits)
	Line 34:     textureRect = new osg::TextureRectangle;
	Line 36:     textureRect->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 36:     textureRect->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 37:     textureRect->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 37:     textureRect->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 38:     textureRect->setFilter(osg::TextureRectangle::MIN_FILTER, osg::TextureRectangle::LINEAR);
	Line 38:     textureRect->setFilter(osg::TextureRectangle::MIN_FILTER, osg::TextureRectangle::LINEAR);
	Line 39:     textureRect->setFilter(osg::TextureRectangle::MAG_FILTER, osg::TextureRectangle::LINEAR);
	Line 39:     textureRect->setFilter(osg::TextureRectangle::MAG_FILTER, osg::TextureRectangle::LINEAR);
	Line 41:     textureRectFB = new osg::TextureRectangle;
	Line 43:     textureRectFB->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 43:     textureRectFB->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 44:     textureRectFB->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 44:     textureRectFB->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 45:     textureRectFB->setFilter(osg::TextureRectangle::MIN_FILTER, osg::TextureRectangle::LINEAR);
	Line 45:     textureRectFB->setFilter(osg::TextureRectangle::MIN_FILTER, osg::TextureRectangle::LINEAR);
	Line 46:     textureRectFB->setFilter(osg::TextureRectangle::MAG_FILTER, osg::TextureRectangle::LINEAR);
	Line 46:     textureRectFB->setFilter(osg::TextureRectangle::MAG_FILTER, osg::TextureRectangle::LINEAR);
	Line 48:     mPostProcessingGroup = new osg::Group;
	Line 66:             texture[i] = new osg::Texture2D;
	Line 69:             texture[i]->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 69:             texture[i]->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_EDGE);
	Line 70:             texture[i]->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 70:             texture[i]->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_EDGE);
	Line 71:             texture[i]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 71:             texture[i]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 72:             texture[i]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 72:             texture[i]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 75:         programDownsample = new osg::Program;
	Line 92:             osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 92:             osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 92:             osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 92:             osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 93:             programDownsample = new osg::Program;
	Line 98:         buildQuad(quad[1], texture[1].get(), programDownsample.get(), osg::Vec2(1. / 4., 1. / 4.));
	Line 100:         postSwitch = new osg::Switch;
	Line 105:         osg::ref_ptr<osg::Geode> finalgeode = new osg::Geode();
	Line 105:         osg::ref_ptr<osg::Geode> finalgeode = new osg::Geode();
	Line 105:         osg::ref_ptr<osg::Geode> finalgeode = new osg::Geode();
	Line 111:         osg::ref_ptr<osg::Geode> noisegeode = new osg::Geode();
	Line 111:         osg::ref_ptr<osg::Geode> noisegeode = new osg::Geode();
	Line 111:         osg::ref_ptr<osg::Geode> noisegeode = new osg::Geode();
	Line 136: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::TextureRectangle *tex)
	Line 136: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::TextureRectangle *tex)
	Line 136: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::TextureRectangle *tex)
	Line 138:     osg::Geometry *geo = new osg::Geometry;
	Line 138:     osg::Geometry *geo = new osg::Geometry;
	Line 139:     osg::Vec3Array *vx = new osg::Vec3Array;
	Line 139:     osg::Vec3Array *vx = new osg::Vec3Array;
	Line 140:     vx->push_back(osg::Vec3(-1, 0, -1));
	Line 141:     vx->push_back(osg::Vec3(1, 0, -1));
	Line 142:     vx->push_back(osg::Vec3(1, 0, 1));
	Line 143:     vx->push_back(osg::Vec3(-1, 0, 1));
	Line 145:     osg::Vec2Array *tx = new osg::Vec2Array;
	Line 145:     osg::Vec2Array *tx = new osg::Vec2Array;
	Line 146:     tx->push_back(osg::Vec2(0, 0));
	Line 147:     tx->push_back(osg::Vec2(SubviewConfig::winWidth, 0));
	Line 148:     tx->push_back(osg::Vec2(SubviewConfig::winWidth, SubviewConfig::winHeight));
	Line 149:     tx->push_back(osg::Vec2(0, SubviewConfig::winHeight));
	Line 151:     geo->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));
	Line 153:     osg::StateSet *stateSet = geo->getOrCreateStateSet();
	Line 156:     geode = new osg::Geode;
	Line 160: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::Texture2D *tex, osg::Program *program, osg::Vec2 offset)
	Line 160: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::Texture2D *tex, osg::Program *program, osg::Vec2 offset)
	Line 160: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::Texture2D *tex, osg::Program *program, osg::Vec2 offset)
	Line 160: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::Texture2D *tex, osg::Program *program, osg::Vec2 offset)
	Line 160: void PostProcessing::buildQuad(osg::ref_ptr< osg::Geode > & geode, osg::Texture2D *tex, osg::Program *program, osg::Vec2 offset)
	Line 162:     osg::Geometry *geo = new osg::Geometry;
	Line 162:     osg::Geometry *geo = new osg::Geometry;
	Line 163:     osg::Vec3Array *vx = new osg::Vec3Array;
	Line 163:     osg::Vec3Array *vx = new osg::Vec3Array;
	Line 164:     vx->push_back(osg::Vec3(-1, 0, -1));
	Line 165:     vx->push_back(osg::Vec3(1, 0, -1));
	Line 166:     vx->push_back(osg::Vec3(1, 0, 1));
	Line 167:     vx->push_back(osg::Vec3(-1, 0, 1));
	Line 169:     osg::Vec2Array *tx = new osg::Vec2Array;
	Line 169:     osg::Vec2Array *tx = new osg::Vec2Array;
	Line 170:     tx->push_back(osg::Vec2(0, 0));
	Line 171:     tx->push_back(osg::Vec2(1, 0));
	Line 172:     tx->push_back(osg::Vec2(1, 1));
	Line 173:     tx->push_back(osg::Vec2(0, 1));
	Line 175:     geo->addPrimitiveSet(new osg::DrawArrays(GL_QUADS, 0, 4));
	Line 177:     osg::StateSet *stateSet = geo->getOrCreateStateSet();
	Line 179:     stateSet->addUniform(new osg::Uniform("scene", 0));
	Line 180:     stateSet->addUniform(new osg::Uniform("offset", offset));
	Line 181:     stateSet->setAttributeAndModes(program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 181:     stateSet->setAttributeAndModes(program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 183:     geode = new osg::Geode;
	Line 310: osg::ref_ptr<osg::Group> PostProcessing::GetPostProcessingGroup() const
	Line 310: osg::ref_ptr<osg::Group> PostProcessing::GetPostProcessingGroup() const
  D:\Development\psim\src\subview\PostProcessing.h (24 hits)
	Line 21:     osg::TextureRectangle* textureRect;
	Line 22:     osg::TextureRectangle* textureRectFB;
	Line 23:     std::vector<osg::ref_ptr<osg::Texture2D>> texture;
	Line 23:     std::vector<osg::ref_ptr<osg::Texture2D>> texture;
	Line 24:     std::vector<osg::ref_ptr<osg::Geode>> quad;
	Line 24:     std::vector<osg::ref_ptr<osg::Geode>> quad;
	Line 27:     osg::ref_ptr<osg::Program> programDownsample;
	Line 27:     osg::ref_ptr<osg::Program> programDownsample;
	Line 48:     osg::ref_ptr<osg::Group> GetPostProcessingGroup() const;
	Line 48:     osg::ref_ptr<osg::Group> GetPostProcessingGroup() const;
	Line 51:     osg::ref_ptr<PostProcessQuadFinal> quadfinal;
	Line 52:     osg::ref_ptr<NoiseQuad> quadnoise;
	Line 53:     osg::ref_ptr<osg::Switch> postSwitch;
	Line 53:     osg::ref_ptr<osg::Switch> postSwitch;
	Line 54:     osg::ref_ptr<osg::Group> mPostProcessingGroup;
	Line 54:     osg::ref_ptr<osg::Group> mPostProcessingGroup;
	Line 56:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::TextureRectangle* tex);
	Line 56:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::TextureRectangle* tex);
	Line 56:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::TextureRectangle* tex);
	Line 57:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::Texture2D* tex, osg::Program* program, osg::Vec2 offset);
	Line 57:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::Texture2D* tex, osg::Program* program, osg::Vec2 offset);
	Line 57:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::Texture2D* tex, osg::Program* program, osg::Vec2 offset);
	Line 57:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::Texture2D* tex, osg::Program* program, osg::Vec2 offset);
	Line 57:     void buildQuad(osg::ref_ptr<osg::Geode>& geode, osg::Texture2D* tex, osg::Program* program, osg::Vec2 offset);
  D:\Development\psim\src\subview\PostProcessQuadFinal.cpp (25 hits)
	Line 37: PostProcessQuadFinal::PostProcessQuadFinal(osg::TextureRectangle *_textureRect, osg::TextureRectangle *_textureRectFB,
	Line 37: PostProcessQuadFinal::PostProcessQuadFinal(osg::TextureRectangle *_textureRect, osg::TextureRectangle *_textureRectFB,
	Line 38:         osg::Texture2D *_textureAGC)
	Line 42: , state(new osg::State)
	Line 43: , stateSet(new osg::StateSet)
	Line 46:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-1.0, 1.0, -1.0, 1.0, -50.0, 50.0));
	Line 46:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-1.0, 1.0, -1.0, 1.0, -50.0, 50.0));
	Line 47:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 47:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 49:     osg::ref_ptr< osg::Program > finalPassProgram = new osg::Program;
	Line 49:     osg::ref_ptr< osg::Program > finalPassProgram = new osg::Program;
	Line 49:     osg::ref_ptr< osg::Program > finalPassProgram = new osg::Program;
	Line 51:     finalPassProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "quadfinalFrag.glsl"));
	Line 52:     stateSet->setAttributeAndModes(finalPassProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 52:     stateSet->setAttributeAndModes(finalPassProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 57:     stateSet->addUniform(new osg::Uniform("scene", 0));
	Line 58:     stateSet->addUniform(new osg::Uniform("agc", 1));
	Line 59:     gainUniform = new osg::Uniform("gain", 1.f);
	Line 60:     biasUniform = new osg::Uniform("agcBias", 1.f);
	Line 61:     agcOnUniform = new osg::Uniform("agcOn", 1.f);
	Line 62:     gammaUniform = new osg::Uniform("agcGamma", 1.f);
	Line 63:     polarityUniform = new osg::Uniform("polarity", 0.f); // white hot = 0.0; black hot = 1.0
	Line 75: void PostProcessQuadFinal::drawImplementation(osg::RenderInfo& ri) const
	Line 89:         osg::Texture::TextureObject* textureObject = textureRect->getTextureObject(0);
	Line 144:         osg::Texture::TextureObject* textureObjectFB = textureRectFB->getTextureObject(0);
  D:\Development\psim\src\subview\PostProcessQuadFinal.h (33 hits)
	Line 24: class PostProcessQuadFinal : public osg::Geometry
	Line 27:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 27:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 28:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 28:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 29:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 29:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 30:     osg::ref_ptr<osg::State> state;
	Line 30:     osg::ref_ptr<osg::State> state;
	Line 31:     osg::TextureRectangle* textureRect;
	Line 32:     osg::TextureRectangle* textureRectFB;
	Line 33:     osg::Texture2D* textureAGC;
	Line 34:     osg::ref_ptr<osg::Uniform> gainUniform;
	Line 34:     osg::ref_ptr<osg::Uniform> gainUniform;
	Line 35:     osg::ref_ptr<osg::Uniform> biasUniform;
	Line 35:     osg::ref_ptr<osg::Uniform> biasUniform;
	Line 36:     osg::ref_ptr<osg::Uniform> agcOnUniform;
	Line 36:     osg::ref_ptr<osg::Uniform> agcOnUniform;
	Line 37:     osg::ref_ptr<osg::Uniform> polarityUniform;
	Line 37:     osg::ref_ptr<osg::Uniform> polarityUniform;
	Line 38:     osg::ref_ptr<osg::Uniform> gammaUniform;
	Line 38:     osg::ref_ptr<osg::Uniform> gammaUniform;
	Line 44:     PostProcessQuadFinal(const PostProcessQuadFinal& PostProcessQuadFinal, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 44:     PostProcessQuadFinal(const PostProcessQuadFinal& PostProcessQuadFinal, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 45:     osg::Geometry(PostProcessQuadFinal, copyop)
	Line 52:     PostProcessQuadFinal(osg::TextureRectangle* _textureRect, osg::TextureRectangle* _textureRectFB, osg::Texture2D* _textureAGC);
	Line 52:     PostProcessQuadFinal(osg::TextureRectangle* _textureRect, osg::TextureRectangle* _textureRectFB, osg::Texture2D* _textureAGC);
	Line 52:     PostProcessQuadFinal(osg::TextureRectangle* _textureRect, osg::TextureRectangle* _textureRectFB, osg::Texture2D* _textureAGC);
	Line 53:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 55:     virtual osg::BoundingBox computeBound() const
	Line 57:         osg::BoundingBox bbox;
	Line 58:         bbox.expandBy(osg::Vec3(-10000.0, -10000.0, -10000.0));
	Line 59:         bbox.expandBy(osg::Vec3(10000.0, 10000.0, 10000.0));
  D:\Development\psim\src\subview\PrecipUpdateOp.cpp (1 hit)
	Line 32: void PrecipUpdateOp::operator()(osg::Object* obj)
  D:\Development\psim\src\subview\PrecipUpdateOp.h (2 hits)
	Line 21: class PrecipUpdateOp : public osg::Operation
	Line 29:     void operator()(osg::Object* obj);
  D:\Development\psim\src\subview\PrecomputeAtmoOp.cpp (210 hits)
	Line 30:     passSwitch = new osg::Switch();
	Line 38:     firstUniform = new osg::Uniform(osg::Uniform::FLOAT, "first");
	Line 38:     firstUniform = new osg::Uniform(osg::Uniform::FLOAT, "first");
	Line 54:     osg::ref_ptr<osg::Texture> deltaETex = irradiance1Pass.second;
	Line 54:     osg::ref_ptr<osg::Texture> deltaETex = irradiance1Pass.second;
	Line 58:     osg::ref_ptr<osg::Texture3D> deltaSRTex = SkydomeUtils::createRTTTarget(RES_MU_S * RES_NU, RES_MU, RES_R);
	Line 58:     osg::ref_ptr<osg::Texture3D> deltaSRTex = SkydomeUtils::createRTTTarget(RES_MU_S * RES_NU, RES_MU, RES_R);
	Line 59:     osg::ref_ptr<osg::Texture3D> deltaSMTex = SkydomeUtils::createRTTTarget(RES_MU_S * RES_NU, RES_MU, RES_R);
	Line 59:     osg::ref_ptr<osg::Texture3D> deltaSMTex = SkydomeUtils::createRTTTarget(RES_MU_S * RES_NU, RES_MU, RES_R);
	Line 62:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 62:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 64:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 64:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 65:         cam->attach(osg::Camera::COLOR_BUFFER0, deltaSRTex, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 65:         cam->attach(osg::Camera::COLOR_BUFFER0, deltaSRTex, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 66:         cam->attach(osg::Camera::COLOR_BUFFER1, deltaSMTex, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 66:         cam->attach(osg::Camera::COLOR_BUFFER1, deltaSMTex, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 68:         cam->getOrCreateStateSet()->setAttribute(inscatter1Program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 68:         cam->getOrCreateStateSet()->setAttribute(inscatter1Program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 73:         osg::Uniform* texUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 73:         osg::Uniform* texUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 73:         osg::Uniform* texUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 76:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 76:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 84:     copyIrradiancePass.first->getOrCreateStateSet()->addUniform(new osg::Uniform("k", 0.0f));
	Line 90:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 90:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 92:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 92:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 93:         cam->attach(osg::Camera::COLOR_BUFFER, inscatterSampler, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 93:         cam->attach(osg::Camera::COLOR_BUFFER, inscatterSampler, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 95:         cam->getOrCreateStateSet()->setAttribute(copyInscatter1Program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 95:         cam->getOrCreateStateSet()->setAttribute(copyInscatter1Program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 100:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 100:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 100:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 103:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 103:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 105:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 105:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 105:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 108:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaSMTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 108:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaSMTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 113:     osg::ref_ptr<osg::Texture3D> deltaJTexture = SkydomeUtils::createRTTTarget(RES_MU_S * RES_NU, RES_MU, RES_R);
	Line 113:     osg::ref_ptr<osg::Texture3D> deltaJTexture = SkydomeUtils::createRTTTarget(RES_MU_S * RES_NU, RES_MU, RES_R);
	Line 115:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 115:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 117:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 117:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 118:         cam->attach(osg::Camera::COLOR_BUFFER, deltaJTexture, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 118:         cam->attach(osg::Camera::COLOR_BUFFER, deltaJTexture, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 120:         cam->getOrCreateStateSet()->setAttribute(jProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 120:         cam->getOrCreateStateSet()->setAttribute(jProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 125:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 125:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 125:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 128:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 128:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 130:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 130:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 130:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 133:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaSMTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 133:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaSMTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 135:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 135:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 135:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 138:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(2, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 138:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(2, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 140:         osg::Uniform* irradianceTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaESampler");
	Line 140:         osg::Uniform* irradianceTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaESampler");
	Line 140:         osg::Uniform* irradianceTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaESampler");
	Line 143:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(3, deltaETex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 143:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(3, deltaETex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 150:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(SKY_W, SKY_H);
	Line 150:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(SKY_W, SKY_H);
	Line 152:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 152:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 153:         cam->attach(osg::Camera::COLOR_BUFFER, deltaETex);
	Line 155:         cam->getOrCreateStateSet()->setAttribute(irradianceNProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 155:         cam->getOrCreateStateSet()->setAttribute(irradianceNProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 157:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 157:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 157:         osg::Uniform* rayTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSRSampler");
	Line 160:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 160:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 162:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 162:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 162:         osg::Uniform* mieTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSMSampler");
	Line 165:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaSMTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 165:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaSMTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 167:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 167:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 167:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 170:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(2, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 170:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(2, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 179:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 179:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 181:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 181:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 182:         cam->attach(osg::Camera::COLOR_BUFFER, deltaSRTex, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 182:         cam->attach(osg::Camera::COLOR_BUFFER, deltaSRTex, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 184:         cam->getOrCreateStateSet()->setAttribute(inscatterNProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 184:         cam->getOrCreateStateSet()->setAttribute(inscatterNProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 189:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 189:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 189:         osg::Uniform* transTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 192:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 192:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 194:         osg::Uniform* deltaJTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaJSampler");
	Line 194:         osg::Uniform* deltaJTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaJSampler");
	Line 194:         osg::Uniform* deltaJTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaJSampler");
	Line 197:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaJTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 197:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(1, deltaJTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 204:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(SKY_W, SKY_H);
	Line 204:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(SKY_W, SKY_H);
	Line 206:         cam->getOrCreateStateSet()->addUniform(new osg::Uniform("k", 1.0f)); // accumulate the deltaE into the E
	Line 208:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 208:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 209:         cam->attach(osg::Camera::COLOR_BUFFER, irradianceSampler);
	Line 211:         cam->getOrCreateStateSet()->setAttribute(copyIrradianceProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 211:         cam->getOrCreateStateSet()->setAttribute(copyIrradianceProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 213:         osg::Uniform* irradianceTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaESampler");
	Line 213:         osg::Uniform* irradianceTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaESampler");
	Line 213:         osg::Uniform* irradianceTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaESampler");
	Line 216:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaETex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 216:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaETex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 220:         osg::BlendFunc* blendFunc = new osg::BlendFunc(); // the blend function will handle the accumulation
	Line 220:         osg::BlendFunc* blendFunc = new osg::BlendFunc(); // the blend function will handle the accumulation
	Line 221:         blendFunc->setFunction(osg::BlendFunc::ONE,
	Line 222:                 osg::BlendFunc::ONE); // use equal waiting of current value and 
	Line 223:         cam->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 224:         cam->getOrCreateStateSet()->setAttributeAndModes(blendFunc, osg::StateAttribute::ON);
	Line 232:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 232:         osg::ref_ptr<osg::Camera> cam = SkydomeUtils::createRTTCamera(RES_MU_S * RES_NU, RES_MU);
	Line 234:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 234:         cam->setImplicitBufferAttachmentMask(osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT, osg::Camera::IMPLICIT_COLOR_BUFFER_ATTACHMENT);
	Line 235:         cam->attach(osg::Camera::COLOR_BUFFER, inscatterSampler, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 235:         cam->attach(osg::Camera::COLOR_BUFFER, inscatterSampler, 0, osg::Camera::FACE_CONTROLLED_BY_GEOMETRY_SHADER);
	Line 237:         cam->getOrCreateStateSet()->setAttribute(copyInscatterNProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 237:         cam->getOrCreateStateSet()->setAttribute(copyInscatterNProgram, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 243:         osg::Uniform* deltaSTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSSampler");
	Line 243:         osg::Uniform* deltaSTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSSampler");
	Line 243:         osg::Uniform* deltaSTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "deltaSSampler");
	Line 246:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 246:         cam->getOrCreateStateSet()->setTextureAttributeAndModes(0, deltaSRTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 248:         osg::BlendFunc* blendFunc = new osg::BlendFunc(); // the blend function will handle the accumulation
	Line 248:         osg::BlendFunc* blendFunc = new osg::BlendFunc(); // the blend function will handle the accumulation
	Line 249:         blendFunc->setFunction(osg::BlendFunc::ONE,
	Line 250:                 osg::BlendFunc::ONE); // use equal waiting of current value and delta
	Line 251:         cam->getOrCreateStateSet()->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 252:         cam->getOrCreateStateSet()->setAttributeAndModes(blendFunc, osg::StateAttribute::ON);
	Line 260:     osg::ref_ptr<osg::Shader> transmittanceFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoTransmittance.glsl");
	Line 260:     osg::ref_ptr<osg::Shader> transmittanceFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoTransmittance.glsl");
	Line 260:     osg::ref_ptr<osg::Shader> transmittanceFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoTransmittance.glsl");
	Line 262:     osg::ref_ptr<osg::Shader> irradiance1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoIrradiance1.glsl");
	Line 262:     osg::ref_ptr<osg::Shader> irradiance1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoIrradiance1.glsl");
	Line 262:     osg::ref_ptr<osg::Shader> irradiance1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoIrradiance1.glsl");
	Line 264:     osg::ref_ptr<osg::Shader> inscatter1Geom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatter1.geom");
	Line 264:     osg::ref_ptr<osg::Shader> inscatter1Geom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatter1.geom");
	Line 264:     osg::ref_ptr<osg::Shader> inscatter1Geom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatter1.geom");
	Line 265:     osg::ref_ptr<osg::Shader> inscatter1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatter1.frag");
	Line 265:     osg::ref_ptr<osg::Shader> inscatter1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatter1.frag");
	Line 265:     osg::ref_ptr<osg::Shader> inscatter1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatter1.frag");
	Line 267:     osg::ref_ptr<osg::Shader> copyIrradianceFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyIrradiance.glsl");
	Line 267:     osg::ref_ptr<osg::Shader> copyIrradianceFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyIrradiance.glsl");
	Line 267:     osg::ref_ptr<osg::Shader> copyIrradianceFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyIrradiance.glsl");
	Line 269:     osg::ref_ptr<osg::Shader> copyInscatter1Geom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoCopyInscatter1.geom");
	Line 269:     osg::ref_ptr<osg::Shader> copyInscatter1Geom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoCopyInscatter1.geom");
	Line 269:     osg::ref_ptr<osg::Shader> copyInscatter1Geom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoCopyInscatter1.geom");
	Line 270:     osg::ref_ptr<osg::Shader> copyInscatter1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyInscatter1.frag");
	Line 270:     osg::ref_ptr<osg::Shader> copyInscatter1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyInscatter1.frag");
	Line 270:     osg::ref_ptr<osg::Shader> copyInscatter1Frag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyInscatter1.frag");
	Line 272:     osg::ref_ptr<osg::Shader> jGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatterS.geom");
	Line 272:     osg::ref_ptr<osg::Shader> jGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatterS.geom");
	Line 272:     osg::ref_ptr<osg::Shader> jGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatterS.geom");
	Line 273:     osg::ref_ptr<osg::Shader> jFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatterS.frag");
	Line 273:     osg::ref_ptr<osg::Shader> jFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatterS.frag");
	Line 273:     osg::ref_ptr<osg::Shader> jFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatterS.frag");
	Line 275:     osg::ref_ptr<osg::Shader> irradianceNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoIrradianceN.glsl");
	Line 275:     osg::ref_ptr<osg::Shader> irradianceNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoIrradianceN.glsl");
	Line 275:     osg::ref_ptr<osg::Shader> irradianceNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoIrradianceN.glsl");
	Line 277:     osg::ref_ptr<osg::Shader> inscatterNGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatterN.geom");
	Line 277:     osg::ref_ptr<osg::Shader> inscatterNGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatterN.geom");
	Line 277:     osg::ref_ptr<osg::Shader> inscatterNGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoInscatterN.geom");
	Line 278:     osg::ref_ptr<osg::Shader> inscatterNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatterN.frag");
	Line 278:     osg::ref_ptr<osg::Shader> inscatterNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatterN.frag");
	Line 278:     osg::ref_ptr<osg::Shader> inscatterNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoInscatterN.frag");
	Line 280:     osg::ref_ptr<osg::Shader> copyInscatterNGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoCopyInscatterN.geom");
	Line 280:     osg::ref_ptr<osg::Shader> copyInscatterNGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoCopyInscatterN.geom");
	Line 280:     osg::ref_ptr<osg::Shader> copyInscatterNGeom = ShaderMaster::getInstance().createShader(osg::Shader::GEOMETRY, "atmoCopyInscatterN.geom");
	Line 281:     osg::ref_ptr<osg::Shader> copyInscatterNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyInscatterN.frag");
	Line 281:     osg::ref_ptr<osg::Shader> copyInscatterNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyInscatterN.frag");
	Line 281:     osg::ref_ptr<osg::Shader> copyInscatterNFrag = ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopyInscatterN.frag");
	Line 284:     osg::ref_ptr<osg::Shader> screenQuadVertShader = ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "atmoScreenQuadVertShader.glsl");
	Line 284:     osg::ref_ptr<osg::Shader> screenQuadVertShader = ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "atmoScreenQuadVertShader.glsl");
	Line 284:     osg::ref_ptr<osg::Shader> screenQuadVertShader = ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "atmoScreenQuadVertShader.glsl");
	Line 286:     transmittanceProgram = new osg::Program();
	Line 290:     irradiance1Program = new osg::Program();
	Line 294:     inscatter1Program = new osg::Program();
	Line 300:     copyIrradianceProgram = new osg::Program();
	Line 304:     copyInscatter1Program = new osg::Program();
	Line 310:     jProgram = new osg::Program();
	Line 316:     irradianceNProgram = new osg::Program();
	Line 320:     inscatterNProgram = new osg::Program();
	Line 326:     copyInscatterNProgram = new osg::Program();
	Line 333: PrecomputeAtmoOp::PrecomputeAtmoOp(int _width, int _height, osg::Group* _root) : osg::Operation("Multipass render op", true), width(_width), height(_height), root(_root)
	Line 333: PrecomputeAtmoOp::PrecomputeAtmoOp(int _width, int _height, osg::Group* _root) : osg::Operation("Multipass render op", true), width(_width), height(_height), root(_root)
	Line 335:     //osg::setNotifyLevel(osg::DEBUG_FP);   
	Line 335:     //osg::setNotifyLevel(osg::DEBUG_FP);   
	Line 347: void PrecomputeAtmoOp::operator()(osg::Object* obj)
  D:\Development\psim\src\subview\PrecomputeAtmoOp.h (33 hits)
	Line 28: class PrecomputeAtmoOp : public osg::Operation
	Line 36:     PrecomputeAtmoOp(int _width, int _height, osg::Group* _root);
	Line 38:     virtual void operator() (osg::Object* obj);
	Line 42:     osg::ref_ptr<osg::Texture> irradianceSampler;
	Line 42:     osg::ref_ptr<osg::Texture> irradianceSampler;
	Line 43:     osg::ref_ptr<osg::Texture3D> inscatterSampler;
	Line 43:     osg::ref_ptr<osg::Texture3D> inscatterSampler;
	Line 44:     osg::ref_ptr<osg::Texture> transmittanceSampler;
	Line 44:     osg::ref_ptr<osg::Texture> transmittanceSampler;
	Line 53:     osg::ref_ptr<osg::Group> root;
	Line 53:     osg::ref_ptr<osg::Group> root;
	Line 54:     osg::ref_ptr<osg::Uniform> firstUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> firstUniform;
	Line 56:     osg::ref_ptr<osg::Program> transmittanceProgram;
	Line 56:     osg::ref_ptr<osg::Program> transmittanceProgram;
	Line 57:     osg::ref_ptr<osg::Program> irradiance1Program;
	Line 57:     osg::ref_ptr<osg::Program> irradiance1Program;
	Line 58:     osg::ref_ptr<osg::Program> inscatter1Program;
	Line 58:     osg::ref_ptr<osg::Program> inscatter1Program;
	Line 59:     osg::ref_ptr<osg::Program> copyIrradianceProgram;
	Line 59:     osg::ref_ptr<osg::Program> copyIrradianceProgram;
	Line 60:     osg::ref_ptr<osg::Program> copyInscatter1Program;
	Line 60:     osg::ref_ptr<osg::Program> copyInscatter1Program;
	Line 61:     osg::ref_ptr<osg::Program> jProgram;
	Line 61:     osg::ref_ptr<osg::Program> jProgram;
	Line 62:     osg::ref_ptr<osg::Program> irradianceNProgram;
	Line 62:     osg::ref_ptr<osg::Program> irradianceNProgram;
	Line 63:     osg::ref_ptr<osg::Program> inscatterNProgram;
	Line 63:     osg::ref_ptr<osg::Program> inscatterNProgram;
	Line 64:     osg::ref_ptr<osg::Program> copyInscatterNProgram;
	Line 64:     osg::ref_ptr<osg::Program> copyInscatterNProgram;
	Line 66:     osg::ref_ptr<osg::Switch> passSwitch;
	Line 66:     osg::ref_ptr<osg::Switch> passSwitch;
  D:\Development\psim\src\subview\PrintModelHierarchy.cpp (2 hits)
	Line 27: void PrintModelHierarchy::apply(osg::Node &node)
	Line 39:     osg::Node * oldParent = parent;
  D:\Development\psim\src\subview\PrintModelHierarchy.h (3 hits)
	Line 13: class PrintModelHierarchy : public osg::NodeVisitor
	Line 21:     virtual void apply(osg::Node &node);
	Line 24:     osg::Node * parent;
  D:\Development\psim\src\subview\PrintRootOp.cpp (1 hit)
	Line 17: void PrintRootOp::operator()(osg::Object * object)
  D:\Development\psim\src\subview\PrintRootOp.h (2 hits)
	Line 13: class PrintRootOp : public osg::Operation
	Line 17:     virtual void operator()(osg::Object * object);
  D:\Development\psim\src\subview\ProjWakeGeometry.cpp (70 hits)
	Line 46: ProjWakeGeometry::ProjWakeGeometry(const ProjWakeGeometry& ProjWakeGeometry, const osg::CopyOp& copyop) :
	Line 47: osg::Geometry(ProjWakeGeometry, copyop)
	Line 53:     setDataVariance(osg::Object::DYNAMIC);
	Line 57:     stateSet = new osg::StateSet;
	Line 58:     stateSet->setTextureAttributeAndModes(9, SideCutoutTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 58:     stateSet->setTextureAttributeAndModes(9, SideCutoutTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 59:     stateSet->setTextureAttributeAndModes(10, WakeMaskTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 59:     stateSet->setTextureAttributeAndModes(10, WakeMaskTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 61:     stateSet->addUniform(new osg::Uniform("SideCutout", 9));
	Line 62:     stateSet->addUniform(new osg::Uniform("WakeMask", 10));
	Line 64:     eyeAboveFadeUniform = new osg::Uniform("eyeAboveFade", 0.1f);
	Line 76:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 76:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 76:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 77:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "wakeFreqVert.glsl"));
	Line 78:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "wakeFrag.glsl"));
	Line 82:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 82:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 83:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 84:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 90: void ProjWakeGeometry::drawImplementation(osg::RenderInfo& ri) const
	Line 141:     osg::Vec4f c0 = (*(wake->baseColors))[0];
	Line 150:         osg::Vec3f v0 = (*(wake->baseCoords))[i + 0];
	Line 151:         osg::Vec3f v1 = (*(wake->baseCoords))[i + 1];
	Line 152:         osg::Vec3f v2 = (*(wake->baseCoords))[i + 2];
	Line 153:         osg::Vec3f v3 = (*(wake->baseCoords))[i + 3];
	Line 164:         osg::Vec2f t0 = (*(wake->baseTexCoords0))[i + 0];
	Line 165:         osg::Vec2f t1 = (*(wake->baseTexCoords0))[i + 1];
	Line 166:         osg::Vec2f t2 = (*(wake->baseTexCoords0))[i + 2];
	Line 167:         osg::Vec2f t3 = (*(wake->baseTexCoords0))[i + 3];
	Line 169:         osg::Vec2f t0b = (*(wake->baseTexCoords1))[i + 0];
	Line 170:         osg::Vec2f t1b = (*(wake->baseTexCoords1))[i + 1];
	Line 171:         osg::Vec2f t2b = (*(wake->baseTexCoords1))[i + 2];
	Line 172:         osg::Vec2f t3b = (*(wake->baseTexCoords1))[i + 3];
	Line 200:         osg::Vec2f tailMultiTexCoordLeft(1.0, 0.0);
	Line 201:         osg::Vec2f tailMultiTexCoordRight(1.0, 1.0);
	Line 203:         osg::Vec3f v0 = (*(wake->tailCoords))[i + 0];
	Line 204:         osg::Vec3f v1 = (*(wake->tailCoords))[i + 1];
	Line 205:         osg::Vec3f v2 = (*(wake->tailCoords))[i + 2];
	Line 206:         osg::Vec3f v3 = (*(wake->tailCoords))[i + 3];
	Line 217:         osg::Vec4f c0 = (*(wake->tailColors))[i + 0];
	Line 218:         osg::Vec4f c1 = (*(wake->tailColors))[i + 1];
	Line 219:         osg::Vec4f c2 = (*(wake->tailColors))[i + 2];
	Line 220:         osg::Vec4f c3 = (*(wake->tailColors))[i + 3];
	Line 222:         osg::Vec2f t0 = (*(wake->tailTexCoords))[i + 0];
	Line 223:         osg::Vec2f t1 = (*(wake->tailTexCoords))[i + 1];
	Line 224:         osg::Vec2f t2 = (*(wake->tailTexCoords))[i + 2];
	Line 225:         osg::Vec2f t3 = (*(wake->tailTexCoords))[i + 3];
	Line 274:             WakeMaskTexture = new osg::Texture2D;
	Line 275:             WakeMaskTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 275:             WakeMaskTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 276:             WakeMaskTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 276:             WakeMaskTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 277:             WakeMaskTexture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 277:             WakeMaskTexture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 278:             WakeMaskTexture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP);
	Line 278:             WakeMaskTexture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP);
	Line 279:             WakeMaskTexture->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
	Line 279:             WakeMaskTexture->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
	Line 292:             SideCutoutTexture = new osg::Texture2D;
	Line 293:             SideCutoutTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 293:             SideCutoutTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 294:             SideCutoutTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 294:             SideCutoutTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 295:             SideCutoutTexture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::REPEAT);
	Line 295:             SideCutoutTexture->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::REPEAT);
	Line 296:             SideCutoutTexture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP);
	Line 296:             SideCutoutTexture->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP);
	Line 297:             SideCutoutTexture->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
	Line 297:             SideCutoutTexture->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
  D:\Development\psim\src\subview\ProjWakeGeometry.h (16 hits)
	Line 23: class ProjWakeGeometry : public osg::Geometry
	Line 28:     ProjWakeGeometry(const ProjWakeGeometry& ProjWakeGeometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 28:     ProjWakeGeometry(const ProjWakeGeometry& ProjWakeGeometry, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 30:     void drawImplementation(osg::RenderInfo& ri) const;
	Line 39:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 39:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 40:     osg::ref_ptr<osg::Uniform> eyeAboveFadeUniform;
	Line 40:     osg::ref_ptr<osg::Uniform> eyeAboveFadeUniform;
	Line 42:     osg::ref_ptr<osg::Image> WakeMask;
	Line 42:     osg::ref_ptr<osg::Image> WakeMask;
	Line 43:     osg::ref_ptr<osg::Texture2D> WakeMaskTexture;
	Line 43:     osg::ref_ptr<osg::Texture2D> WakeMaskTexture;
	Line 44:     osg::ref_ptr<osg::Image> SideCutout[2];
	Line 44:     osg::ref_ptr<osg::Image> SideCutout[2];
	Line 45:     osg::ref_ptr<osg::Texture2D> SideCutoutTexture;
	Line 45:     osg::ref_ptr<osg::Texture2D> SideCutoutTexture;
  D:\Development\psim\src\subview\Propeller.cpp (12 hits)
	Line 18: Propeller::Propeller(int contactId, Vehicle *vehicle, osg::Geode * node) :
	Line 24:     mPutMatrix = osg::Matrix::translate(-mPosition);
	Line 25:     mInvPutMatrix = osg::Matrix::translate(mPosition);
	Line 41:     osg::Geometry* geom = node->getDrawable(0)->asGeometry(); //the geometry of the pivot
	Line 44:         osg::Array* norms = geom->getNormalArray(); //array of normals of the pivot
	Line 47:             osg::Vec3f* normal = (osg::Vec3f*)norms->getDataPointer(); //get the normal as a vector
	Line 47:             osg::Vec3f* normal = (osg::Vec3f*)norms->getDataPointer(); //get the normal as a vector
	Line 59: void Propeller::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 59: void Propeller::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 72:         mTransform.postMult(osg::Matrix::rotate(mRoll, mAxisOfRot));
	Line 74:         dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
	Line 81: osg::Vec3f Propeller::getPropPosition()
  D:\Development\psim\src\subview\Propeller.h (10 hits)
	Line 11: class Propeller : public osg::NodeCallback
	Line 15:     Propeller(int contactId, Vehicle *vehicle, osg::Geode * node);
	Line 16:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 16:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 19:     osg::Vec3f getPropPosition();
	Line 28:     osg::Vec3f mAxisOfRot;
	Line 29:     osg::Vec3f mPosition;
	Line 30:     osg::Matrix mPutMatrix; // puts back to end of shaft
	Line 31:     osg::Matrix mInvPutMatrix; // puts back to end of shaft
	Line 32:     osg::Matrix mTransform; // local transformation
  D:\Development\psim\src\subview\psCore\deltadrawable.cpp (43 hits)
	Line 37:       //void AddedToScene(Scene* scene, osg::Node* node);
	Line 38:       //void RemovedFromScene(Scene* scene, osg::Node* node);
	Line 60:       void GetBoundingSphere(osg::Vec3& center, float& radius, osg::Node* node);
	Line 60:       void GetBoundingSphere(osg::Vec3& center, float& radius, osg::Node* node);
	Line 62:       void SetActive(bool enable, osg::Node* node);
	Line 65:       osg::Node* GetProxyNode();
	Line 66:       const osg::Node* GetProxyNode() const;
	Line 67:       void SetProxyNode(osg::Node* proxyNode);
	Line 81:       void InsertSwitchNode(osg::Node *node);
	Line 84:       void RemoveSwitchNode(osg::Node* node);
	Line 89: 	  typedef std::vector< osg::ref_ptr<DeltaDrawable> > ChildList;
	Line 92:       osg::ref_ptr<osg::Node> mProxyNode; ///< Handle to the rendered proxy node (or NULL)
	Line 92:       osg::ref_ptr<osg::Node> mProxyNode; ///< Handle to the rendered proxy node (or NULL)
	Line 221:    void DeltaDrawablePrivate::GetBoundingSphere(osg::Vec3& center,
	Line 223:                                                 osg::Node* node)
	Line 227:          osg::BoundingSphere bs = node->getBound();
	Line 238:    void DeltaDrawablePrivate::SetActive(bool enable, osg::Node* node)
	Line 271:    void DeltaDrawablePrivate::SetProxyNode(osg::Node* proxyNode)
	Line 283:    void DeltaDrawablePrivate::InsertSwitchNode(osg::Node *node)
	Line 286:       osg::Node::ParentList parents = node->getParents();
	Line 289:       osg::Node::ParentList::iterator parentItr = parents.begin();
	Line 296:       osg::ref_ptr<osg::Switch> parentSwitch = new osg::Switch();
	Line 296:       osg::ref_ptr<osg::Switch> parentSwitch = new osg::Switch();
	Line 296:       osg::ref_ptr<osg::Switch> parentSwitch = new osg::Switch();
	Line 312:    void DeltaDrawablePrivate::RemoveSwitchNode(osg::Node* node)
	Line 318:       osg::Switch* parentSwitch = dynamic_cast<osg::Switch*>(node->getParent(0));
	Line 318:       osg::Switch* parentSwitch = dynamic_cast<osg::Switch*>(node->getParent(0));
	Line 322:       osg::Node::ParentList parents = parentSwitch->getParents();
	Line 325:       osg::Node::ParentList::iterator parentItr = parents.begin();
	Line 342:    osg::Node* DeltaDrawablePrivate::GetProxyNode()
	Line 348:    const osg::Node* DeltaDrawablePrivate::GetProxyNode() const
	Line 394:    //   osg::Node* node = mOwner->GetOSGNode();
	Line 457:    //void DeltaDrawablePrivate::AddedToScene(Scene* scene, osg::Node* node)
	Line 482:    //void DeltaDrawablePrivate::RemovedFromScene(Scene* scene, osg::Node* node)
	Line 528:       osg::ref_ptr<const DeltaDrawable> t = GetParent();
	Line 721: void DeltaDrawable::SetProxyNode(osg::Node* proxyNode)
	Line 733: void DeltaDrawable::GetBoundingSphere(osg::Vec3& center, float& radius)
	Line 739: osg::BoundingBox DeltaDrawable::GetBoundingBox()
	Line 741:    osg::Node* topNode = this->GetOSGNode();
	Line 746:       osg::BoundingBox bb;
	Line 750:    osg::ComputeBoundsVisitor cbv;
	Line 805: osg::Node* psCore::DeltaDrawable::GetProxyNode()
	Line 811: const osg::Node* psCore::DeltaDrawable::GetProxyNode() const
  D:\Development\psim\src\subview\psCore\deltadrawable.h (9 hits)
	Line 52:     * the mNode protected variable which is some type of osg::Node.
	Line 57:    class DeltaDrawable : public osg::Referenced
	Line 66:       virtual osg::Node* GetOSGNode() = 0;
	Line 67:       virtual const osg::Node* GetOSGNode() const = 0;
	Line 170:       virtual void GetBoundingSphere(osg::Vec3& center, float& radius);
	Line 177:       virtual osg::BoundingBox GetBoundingBox();
	Line 242:       osg::Node* GetProxyNode();
	Line 243:       const osg::Node* GetProxyNode() const;
	Line 244:       void SetProxyNode(osg::Node* proxyNode);
  D:\Development\psim\src\subview\psCore\loadable.cpp (11 hits)
	Line 52: osg::Node* Loadable::LoadFile(const std::string& filename, bool useCache)
	Line 59:    osg::ref_ptr<osgDB::ReaderWriter::Options> options = reg->getOptions() ?
	Line 60:       static_cast<osgDB::ReaderWriter::Options*>(reg->getOptions()->clone(osg::CopyOp::SHALLOW_COPY)) :
	Line 72:    osg::Node* model = ReadNode(mFilename, options.get());
	Line 77: osg::Node* Loadable::ReadNode(const std::string& filename, osgDB::ReaderWriter::Options* options)
	Line 82:     osg::Node* result = NULL;
	Line 97:         osg::Object* obj = reg->getFromObjectCache(strippedFilename);
	Line 100:         result = dynamic_cast<osg::Node*>(obj);
	Line 298:     osg::ref_ptr<osgDB::Archive> archiveResult = NULL;
	Line 322:         osg::ref_ptr<osgDB::ReaderWriter::Options> options = reg->getOptions() ?
	Line 323:             static_cast<osgDB::ReaderWriter::Options*>(reg->getOptions()->clone(osg::CopyOp::SHALLOW_COPY)) :
  D:\Development\psim\src\subview\psCore\loadable.h (3 hits)
	Line 70:     * and return back the osg::Node.  The LoadFile() method is intended to be
	Line 86:       virtual osg::Node* LoadFile(const std::string& filename, bool useCache = true);
	Line 91: 	  osg::Node* ReadNode(const std::string& filename, osgDB::ReaderWriter::Options* options = NULL);
  D:\Development\psim\src\subview\psCore\particlesystem.cpp (67 hits)
	Line 32: class ParticleSystemParameterVisitor : public osg::NodeVisitor
	Line 37:       : osg::NodeVisitor(TRAVERSE_ALL_CHILDREN),
	Line 41:    virtual void apply(osg::Node& node)
	Line 43:       osg::Node* nodePtr = &node;
	Line 87: class psGeodeTransform : public osg::MatrixTransform
	Line 90:    class psGeodeTransformCallback : public osg::NodeCallback
	Line 96:       virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 96:       virtual void operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 100:             osg::NodePath fullNodePath = nv->getNodePath();
	Line 106:                osg::Matrix localCoordMat = osg::computeLocalToWorld( fullNodePath );
	Line 106:                osg::Matrix localCoordMat = osg::computeLocalToWorld( fullNodePath );
	Line 107:                osg::Matrix inverseOfAccum = osg::Matrix::inverse( localCoordMat );
	Line 107:                osg::Matrix inverseOfAccum = osg::Matrix::inverse( localCoordMat );
	Line 120: class findGeodeVisitor : public osg::NodeVisitor
	Line 123:    findGeodeVisitor() : osg::NodeVisitor(TRAVERSE_ALL_CHILDREN)
	Line 126:    virtual void apply(osg::Geode& searchNode)
	Line 133:    const std::vector<osg::Geode*> getGeodeVector() { return foundGeodeVector; }
	Line 136:    std::vector<osg::Geode*> foundGeodeVector;
	Line 141: class particleSystemHelper : public osg::Group
	Line 144:    particleSystemHelper(osg::Group* psGroup) : osg::Group(*psGroup)
	Line 144:    particleSystemHelper(osg::Group* psGroup) : osg::Group(*psGroup)
	Line 146:       osg::ref_ptr<findGeodeVisitor> geodeFinder = new findGeodeVisitor();
	Line 148:       std::vector<osg::Geode*> psGeodeVector = geodeFinder->getGeodeVector();
	Line 156:       for (std::vector<osg::Geode*>::iterator itr = psGeodeVector.begin();
	Line 167:    osg::observer_ptr<psGeodeTransform> mGeodeTransform;
	Line 189: void ParticleLayer::SetGeode(osg::Geode& geode)
	Line 201: void ParticleLayer::SetEmitterTransform(osg::MatrixTransform& matrixtransform)
	Line 225: osg::Geode& ParticleLayer::GetGeode()
	Line 231: const osg::Geode& ParticleLayer::GetGeode() const
	Line 249: osg::MatrixTransform& ParticleLayer::GetEmitterTransform()
	Line 255: const osg::MatrixTransform& ParticleLayer::GetEmitterTransform() const
	Line 291: osg::Node* ParticleSystem::LoadFile( const std::string& filename, bool useCache)
	Line 307:    osg::ref_ptr<osg::Node> node = Loadable::LoadFile(filename, useCache); //force it to use cache
	Line 307:    osg::ref_ptr<osg::Node> node = Loadable::LoadFile(filename, useCache); //force it to use cache
	Line 315:               osg::CopyOp::DEEP_COPY_OBJECTS
	Line 316:             | osg::CopyOp::DEEP_COPY_NODES
	Line 317:             | osg::CopyOp::DEEP_COPY_STATESETS
	Line 318:             | osg::CopyOp::DEEP_COPY_STATEATTRIBUTES
	Line 319:             | osg::CopyOp::DEEP_COPY_UNIFORMS;
	Line 321:          osg::ref_ptr<osg::Node> copy = static_cast<osg::Node*>(node->clone(COPY_OPS_SHARED_GEOMETRY));
	Line 321:          osg::ref_ptr<osg::Node> copy = static_cast<osg::Node*>(node->clone(COPY_OPS_SHARED_GEOMETRY));
	Line 321:          osg::ref_ptr<osg::Node> copy = static_cast<osg::Node*>(node->clone(COPY_OPS_SHARED_GEOMETRY));
	Line 362:          particleSystemHelper* psh = new particleSystemHelper(static_cast<osg::Group*>(mLoadedFile.get()));
	Line 422: osg::Node* ParticleSystem::GetLoadedParticleSystemRoot()
	Line 428: const osg::Node* ParticleSystem::GetLoadedParticleSystemRoot() const
	Line 434: osg::Node* ParticleSystem::GetCachedOriginalParticleSystemRoot()
	Line 440: const osg::Node* ParticleSystem::GetCachedOriginalParticleSystemRoot() const
	Line 446: void ParticleSystem::ParseParticleLayers(osg::Node& ps, LayerList& layers, osg::ref_ptr<osgParticle::ParticleSystemUpdater>& particleSystemUpdater)
	Line 446: void ParticleSystem::ParseParticleLayers(osg::Node& ps, LayerList& layers, osg::ref_ptr<osgParticle::ParticleSystemUpdater>& particleSystemUpdater)
	Line 450:    osg::Group* newParticleSystemGroup = static_cast<osg::Group*>(&ps);
	Line 450:    osg::Group* newParticleSystemGroup = static_cast<osg::Group*>(&ps);
	Line 454:    osg::Node* searchingNode = NULL;
	Line 484:       osg::Geode* geode = dynamic_cast<osg::Geode*>(searchingNode);
	Line 484:       osg::Geode* geode = dynamic_cast<osg::Geode*>(searchingNode);
	Line 494:             osg::Drawable* drawable    = layer.GetGeode().getDrawable(j);
	Line 517:       if (dynamic_cast<osg::MatrixTransform*>(searchingNode)!= NULL)
	Line 520:          osg::MatrixTransform* newEmitterTransform = static_cast<osg::MatrixTransform*>(searchingNode);
	Line 520:          osg::MatrixTransform* newEmitterTransform = static_cast<osg::MatrixTransform*>(searchingNode);
	Line 524:             osg::Node* childNode = newEmitterTransform->getChild(j);
	Line 595:    static const unsigned int COPY_OPS_DRAWABLE = (osg::CopyOp::DEEP_COPY_OBJECTS
	Line 596:       | osg::CopyOp::DEEP_COPY_NODES
	Line 597:       | osg::CopyOp::DEEP_COPY_STATESETS
	Line 598:       | osg::CopyOp::DEEP_COPY_STATEATTRIBUTES
	Line 599:       | osg::CopyOp::DEEP_COPY_UNIFORMS
	Line 600:       | osg::CopyOp::DEEP_COPY_DRAWABLES);
	Line 609:    osg::ref_ptr<osgParticle::ParticleSystemUpdater> newParticleSystemUpdater = new osgParticle::ParticleSystemUpdater;
	Line 624:       osg::ref_ptr<osgParticle::ParticleSystem> newPSDrawable =
  D:\Development\psim\src\subview\psCore\particlesystem.h (26 hits)
	Line 41:  * osg::ref_ptr<psCore::ParticleSystem> mSun;
	Line 78:          void SetGeode(osg::Geode& geode);
	Line 80:          void SetEmitterTransform(osg::MatrixTransform& matrixtransform);
	Line 86:          osg::Geode& GetGeode();
	Line 87:          const osg::Geode& GetGeode() const;
	Line 92:          osg::MatrixTransform& GetEmitterTransform();
	Line 93:          const osg::MatrixTransform& GetEmitterTransform() const;
	Line 119: 		 osg::ref_ptr<osg::Geode> mGeode;
	Line 119: 		 osg::ref_ptr<osg::Geode> mGeode;
	Line 124:          osg::ref_ptr<osgParticle::ParticleSystem> mParticleSystem;
	Line 129:          osg::ref_ptr<osg::MatrixTransform> mEmitterTransform;
	Line 129:          osg::ref_ptr<osg::MatrixTransform> mEmitterTransform;
	Line 134:          osg::ref_ptr<osgParticle::ModularEmitter> mModularEmitter;
	Line 140:          osg::ref_ptr<osgParticle::Program> mProgram;
	Line 179:          virtual osg::Node* LoadFile( const std::string& filename, bool useCache = true);
	Line 256:          const osg::Node* GetLoadedParticleSystemRoot() const;
	Line 257:          const osg::Node* GetCachedOriginalParticleSystemRoot() const;
	Line 258:          osg::Node* GetLoadedParticleSystemRoot();
	Line 259:          osg::Node* GetCachedOriginalParticleSystemRoot();
	Line 261:          static void ParseParticleLayers(osg::Node& ps, LayerList& layers,
	Line 262:                   osg::ref_ptr<osgParticle::ParticleSystemUpdater>& particleSystemUpdater);
	Line 292:          osg::ref_ptr<osg::Node> mLoadedFile;
	Line 292:          osg::ref_ptr<osg::Node> mLoadedFile;
	Line 294:          osg::ref_ptr<osg::Node> mOriginalLoadedParticleSystem;
	Line 294:          osg::ref_ptr<osg::Node> mOriginalLoadedParticleSystem;
	Line 295:          osg::ref_ptr<osgParticle::ParticleSystemUpdater> mParticleSystemUpdater;
  D:\Development\psim\src\subview\psCore\transform.cpp (100 hits)
	Line 10: 	osg::Vec3 GetRow3(const osg::Matrix& matrix, int row)
	Line 10: 	osg::Vec3 GetRow3(const osg::Matrix& matrix, int row)
	Line 12: 	   return osg::Vec3(matrix(row,0), matrix(row, 1), matrix(row,2));
	Line 16: 	osg::Vec4 GetRow4(const osg::Matrix& matrix, int row)
	Line 16: 	osg::Vec4 GetRow4(const osg::Matrix& matrix, int row)
	Line 18: 	   return osg::Vec4(matrix(row,0), matrix(row,1), matrix(row,2), matrix(row,3));
	Line 22: 	void SetRow(osg::Matrix& matrix, const osg::Vec3& vec, int row)
	Line 22: 	void SetRow(osg::Matrix& matrix, const osg::Vec3& vec, int row)
	Line 31: 	void SetRow(osg::Matrix& matrix, const osg::Vec4& vec, int row)
	Line 31: 	void SetRow(osg::Matrix& matrix, const osg::Vec4& vec, int row)
	Line 48: 	void HprToMatrix(osg::Matrix& rotation, const osg::Vec3& hpr)
	Line 48: 	void HprToMatrix(osg::Matrix& rotation, const osg::Vec3& hpr)
	Line 60: 	   const osg::Vec3::value_type magic_epsilon = (osg::Vec3::value_type)0.00001;
	Line 60: 	   const osg::Vec3::value_type magic_epsilon = (osg::Vec3::value_type)0.00001;
	Line 62: 	   if (osg::equivalent(hpr[0], (osg::Vec3::value_type)0.0, magic_epsilon))
	Line 62: 	   if (osg::equivalent(hpr[0], (osg::Vec3::value_type)0.0, magic_epsilon))
	Line 69: 		  sh = sinf(osg::DegreesToRadians(hpr[0]));
	Line 70: 		  ch = cosf(osg::DegreesToRadians(hpr[0]));
	Line 73: 	   if (osg::equivalent(hpr[1], (osg::Vec3::value_type)0.0, magic_epsilon))
	Line 73: 	   if (osg::equivalent(hpr[1], (osg::Vec3::value_type)0.0, magic_epsilon))
	Line 80: 		  sp = sinf(osg::DegreesToRadians(hpr[1]));
	Line 81: 		  cp = cosf(osg::DegreesToRadians(hpr[1]));
	Line 84: 	   if (osg::equivalent(hpr[2], (osg::Vec3::value_type)0.0, magic_epsilon))
	Line 84: 	   if (osg::equivalent(hpr[2], (osg::Vec3::value_type)0.0, magic_epsilon))
	Line 94: 		  sr   = sinf(osg::DegreesToRadians(hpr[2]));
	Line 95: 		  cr   = cosf(osg::DegreesToRadians(hpr[2]));
	Line 124: 	void MatrixToHpr(osg::Vec3& hpr, const osg::Matrix& rotation)
	Line 124: 	void MatrixToHpr(osg::Vec3& hpr, const osg::Matrix& rotation)
	Line 131: 	   osg::Matrix mat;
	Line 133: 	   osg::Vec3 col1(rotation(0, 0), rotation(0, 1), rotation(0, 2));
	Line 156: 	   hpr[1] = osg::RadiansToDegrees(pitch);
	Line 174: 		  hpr[2] = osg::RadiansToDegrees(atan2(sr,cr));
	Line 184: 		  if ((osg::equivalent(sh,0.0,magic_epsilon) && osg::equivalent(ch,0.0,magic_epsilon)) ||
	Line 184: 		  if ((osg::equivalent(sh,0.0,magic_epsilon) && osg::equivalent(ch,0.0,magic_epsilon)) ||
	Line 185: 			  (osg::equivalent(sr,0.0,magic_epsilon) && osg::equivalent(cr,0.0,magic_epsilon)) )
	Line 185: 			  (osg::equivalent(sr,0.0,magic_epsilon) && osg::equivalent(cr,0.0,magic_epsilon)) )
	Line 194: 			hpr[0] = osg::RadiansToDegrees(atan2(sh, ch));
	Line 197: 		  hpr[2] = osg::RadiansToDegrees(atan2(sr, cr));
	Line 218:    void Transform::GetRow(unsigned index, osg::Vec3& row) const
	Line 224:    void Transform::SetRow(unsigned index, const osg::Vec3& row)
	Line 230:    void Transform::GetRow(unsigned index, osg::Vec4& row) const
	Line 236:    void Transform::SetRow(unsigned index, const osg::Vec4& row)
	Line 244:       osg::Vec3 xyz(tx, ty, tz);
	Line 245:       osg::Vec3 hpr(h, p, r);
	Line 251:    void Transform::Set(const osg::Vec3& xyz, const osg::Matrix& rotation)
	Line 251:    void Transform::Set(const osg::Vec3& xyz, const osg::Matrix& rotation)
	Line 258:    void Transform::Set(const osg::Vec3& xyz, const osg::Quat& quat)
	Line 258:    void Transform::Set(const osg::Vec3& xyz, const osg::Quat& quat)
	Line 265:    void Transform::Set(const osg::Vec3& xyz, const osg::Vec3& hpr)
	Line 265:    void Transform::Set(const osg::Vec3& xyz, const osg::Vec3& hpr)
	Line 267:       osg::Matrix rotation;
	Line 274:    void Transform::Set(const osg::Matrix& mat)
	Line 276:       //osg::Vec3 x_vec( mat(0, 0), mat(0, 1), mat(0, 2) );
	Line 277:       //osg::Vec3 y_vec( mat(1, 0), mat(1, 1), mat(1, 2) );
	Line 278:       //osg::Vec3 z_vec( mat(2, 0), mat(2, 1), mat(2, 2) );
	Line 279:       //osg::Vec3 scale(x_vec.length(), y_vec.length(), z_vec.length());
	Line 291:        //osg::Matrix rotation, scale;
	Line 292:        //osg::Vec3 translation;
	Line 303:    void Transform::SetRotation(const osg::Vec3& hpr)
	Line 305:       osg::Matrix rotation;
	Line 311:    void Transform::SetRotation(const osg::Matrix& rotation)
	Line 313:       osg::Vec3d trans;
	Line 327:    void Transform::Get(osg::Vec3& xyz, osg::Matrix& rotation) const
	Line 327:    void Transform::Get(osg::Vec3& xyz, osg::Matrix& rotation) const
	Line 334:    void Transform::Get(osg::Matrix& matrix) const
	Line 340:    void Transform::Get(osg::Vec3& xyz, osg::Quat& quat) const
	Line 340:    void Transform::Get(osg::Vec3& xyz, osg::Quat& quat) const
	Line 347:    void Transform::Get(osg::Vec3& xyz, osg::Vec3& hpr) const
	Line 347:    void Transform::Get(osg::Vec3& xyz, osg::Vec3& hpr) const
	Line 356:       osg::Vec3f vec3;
	Line 364:    void Transform::Move(const osg::Vec3f& distance)
	Line 370:    void Transform::Move(const osg::Vec3d& distance)
	Line 378:       osg::Vec3 hpr;
	Line 387:    void Transform::GetRotation(osg::Vec3& hpr) const
	Line 393:    void Transform::GetRotation(osg::Matrix& rotation) const
	Line 401:    static void Rescale(const VecType& scale, osg::Matrix& toScale)
	Line 403:       osg::Matrix rotation, matScale;
	Line 404:       osg::Vec3 translation;
	Line 414:    static void CalcScale(VecType& scale, const osg::Matrix& transform)
	Line 416:       osg::Matrix rotation, matScale;
	Line 417:       osg::Vec3 translation;
	Line 426:    //void Transform::CalcScale(osg::Vec3f& scale) const
	Line 432:    //void Transform::CalcScale(osg::Vec3d& scale) const
	Line 438:    //void Transform::Rescale(const osg::Vec3d& scale)
	Line 444:    //void Transform::Rescale(const osg::Vec3f& scale)
	Line 458:       osg::Vec3 positionOne, positionTwo;
	Line 468:    void Transform::Set(const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec)
	Line 468:    void Transform::Set(const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec)
	Line 468:    void Transform::Set(const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec)
	Line 470:       osg::Vec3 x,y,z;
	Line 492:       osg::Vec3 xyz(posX, posY, posZ);
	Line 493:       osg::Vec3 lookAt(lookAtX, lookAtY, lookAtZ);
	Line 494:       osg::Vec3 upVec(upVecX, upVecY, upVecZ);
	Line 500:    void Transform::GetOrientation(osg::Vec3& right, osg::Vec3& up, osg::Vec3& forward) const
	Line 500:    void Transform::GetOrientation(osg::Vec3& right, osg::Vec3& up, osg::Vec3& forward) const
	Line 500:    void Transform::GetOrientation(osg::Vec3& right, osg::Vec3& up, osg::Vec3& forward) const
	Line 508:    osg::Vec3 Transform::GetRightVector() const
	Line 514:    osg::Vec3 Transform::GetUpVector() const
	Line 520:    osg::Vec3 Transform::GetForwardVector() const
	Line 532:    //         if(!dtUtil::Equivalent(mTransform(i,j), transform.mTransform(i,j), osg::Matrix::value_type(epsilon)))
  D:\Development\psim\src\subview\psCore\transform.h (57 hits)
	Line 47:       void MakeScale(const osg::Vec3d& scaleVec) { mTransform.makeScale(scaleVec); }
	Line 49:       void MakeScale(const osg::Vec3f& scaleVec) { mTransform.makeScale(scaleVec); }
	Line 51:       void MakeScale(osg::Matrix::value_type x, osg::Matrix::value_type y, osg::Matrix::value_type z)
	Line 51:       void MakeScale(osg::Matrix::value_type x, osg::Matrix::value_type y, osg::Matrix::value_type z)
	Line 51:       void MakeScale(osg::Matrix::value_type x, osg::Matrix::value_type y, osg::Matrix::value_type z)
	Line 54:       void GetRow(unsigned index, osg::Vec3& row) const;
	Line 55:       void SetRow(unsigned index, const osg::Vec3& row);
	Line 57:       void GetRow(unsigned index, osg::Vec4& row) const;
	Line 58:       void SetRow(unsigned index, const osg::Vec4& row);
	Line 64:       virtual void Set(const osg::Vec3& xyz, const osg::Vec3& hprRotation);
	Line 64:       virtual void Set(const osg::Vec3& xyz, const osg::Vec3& hprRotation);
	Line 66:       virtual void Set(const osg::Vec3& xyz, const osg::Quat& quat);
	Line 66:       virtual void Set(const osg::Vec3& xyz, const osg::Quat& quat);
	Line 68:       virtual void Set(const osg::Vec3& xyz, const osg::Matrix& rotation);
	Line 68:       virtual void Set(const osg::Vec3& xyz, const osg::Matrix& rotation);
	Line 70:       virtual void Set(const osg::Matrix& mat);
	Line 73:       void Set(const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec);
	Line 73:       void Set(const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec);
	Line 73:       void Set(const osg::Vec3& xyz, const osg::Vec3& lookAtXYZ, const osg::Vec3& upVec);
	Line 81:       virtual void SetTranslation(float tx, float ty, float tz) { SetTranslation(osg::Vec3(tx, ty, tz)); }
	Line 83:       virtual void SetTranslation(const osg::Vec3f& xyz) { mTransform.setTrans( xyz ); }
	Line 85:       virtual void SetTranslation(const osg::Vec3d& xyz) { mTransform.setTrans( xyz ); }
	Line 88:       void Move(const osg::Vec3f& distance);
	Line 90:       void Move(const osg::Vec3d& distance);
	Line 96:       virtual void SetRotation(float h, float p, float r) { SetRotation(osg::Vec3(h, p, r)); }
	Line 102:       virtual void SetRotation(const osg::Vec3& hpr);
	Line 108:       virtual void SetRotation(const osg::Quat& quat) { mTransform.setRotate(quat); }
	Line 113:       virtual void SetRotation(const osg::Matrix& rotation);
	Line 115: 	  osg::Matrix GetMatrix(){return mTransform;};
	Line 120:       void Get(osg::Vec3& xyz, osg::Matrix& rotation) const;
	Line 120:       void Get(osg::Vec3& xyz, osg::Matrix& rotation) const;
	Line 122:       void Get(osg::Vec3& xyz, osg::Vec3& hpr) const;
	Line 122:       void Get(osg::Vec3& xyz, osg::Vec3& hpr) const;
	Line 124:       void Get(osg::Vec3& xyz, osg::Quat& quat) const;
	Line 124:       void Get(osg::Vec3& xyz, osg::Quat& quat) const;
	Line 126:       void Get(osg::Matrix& matrix) const;
	Line 129:       void GetTranslation(osg::Vec3f& translation) const { translation.set(mTransform.getTrans()); }
	Line 131:       void GetTranslation(osg::Vec3d& translation) const { translation.set(mTransform.getTrans()); }
	Line 135:       const osg::Vec3 GetTranslation() const { return mTransform.getTrans(); }
	Line 140:       void GetRotation(osg::Vec3& hpr) const;
	Line 142:       void GetRotation(osg::Quat& quat) const { quat = mTransform.getRotate(); }
	Line 144:       void GetRotation(osg::Matrix& rotation) const;
	Line 146:       osg::Vec3 GetRotation() const { osg::Vec3 hpr; GetRotation(hpr); return hpr; }
	Line 146:       osg::Vec3 GetRotation() const { osg::Vec3 hpr; GetRotation(hpr); return hpr; }
	Line 149:       void GetOrientation(osg::Vec3& right, osg::Vec3& up, osg::Vec3& forward) const;
	Line 149:       void GetOrientation(osg::Vec3& right, osg::Vec3& up, osg::Vec3& forward) const;
	Line 149:       void GetOrientation(osg::Vec3& right, osg::Vec3& up, osg::Vec3& forward) const;
	Line 151:       osg::Vec3 GetRightVector() const;
	Line 153:       osg::Vec3 GetUpVector() const;
	Line 155:       osg::Vec3 GetForwardVector() const;
	Line 158:       //void CalcScale(osg::Vec3f& scale) const;
	Line 160:       //void CalcScale(osg::Vec3d& scale) const;
	Line 175:      // void Rescale(const osg::Vec3d& scale);
	Line 185:       //void Rescale(const osg::Vec3f& scale);
	Line 198:       osg::Matrix::value_type& operator()(unsigned i, unsigned j) { return mTransform(i, j); }
	Line 201:       osg::Matrix::value_type operator()(unsigned i, unsigned j) const { return mTransform(i, j); }
	Line 208:       osg::Matrix mTransform; ///<Internal storage
  D:\Development\psim\src\subview\psCore\transformable.cpp (63 hits)
	Line 29:      * This Visitor will only traverse osg::Transforms and is used to
	Line 32:      * Modified from osg::CollectParentPaths class.
	Line 34:    class CollectParentPaths : public osg::NodeVisitor
	Line 37:       CollectParentPaths(osg::Node* haltTraversalAtNode=0)
	Line 38:          : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_PARENTS)
	Line 38:          : osg::NodeVisitor(osg::NodeVisitor::TRAVERSE_PARENTS)
	Line 46:       virtual void apply(osg::Node& node)
	Line 58:       osg::Node*        _haltTraversalAtNode;
	Line 59:       osg::NodePathList _nodePaths;
	Line 81:       osg::ref_ptr<Transformable::TransformableNode> mNode;
	Line 89:       //osg::ref_ptr<PointAxis> mPointAxis;
	Line 148: osg::Node* Transformable::GetOSGNode()
	Line 154: const osg::Node* Transformable::GetOSGNode() const
	Line 160: //bool GetAbsoluteMatrixOld(const osg::Node* node, osg::Matrix& wcMatrix)
	Line 160: //bool GetAbsoluteMatrixOld(const osg::Node* node, osg::Matrix& wcMatrix)
	Line 165: //      const_cast<osg::Node*>(node)->accept(cpp);
	Line 166: //      const osg::NodePathList& nodePathList = cpp._nodePaths;
	Line 170: //         const osg::NodePath& nodePath = nodePathList[0];
	Line 172: //         wcMatrix.set(osg::computeLocalToWorld(nodePath));
	Line 181: bool GetAbsoluteMatrixNew(const osg::Node* node, osg::Matrix& wcMatrix)
	Line 181: bool GetAbsoluteMatrixNew(const osg::Node* node, osg::Matrix& wcMatrix)
	Line 187:       std::vector<osg::Transform*>  nodePath;
	Line 194:       osg::Node* curNode = const_cast<osg::Node*>(node);
	Line 194:       osg::Node* curNode = const_cast<osg::Node*>(node);
	Line 197:          osg::Transform* txNode = curNode->asTransform();
	Line 204:             osg::Camera* camera = txNode->asCamera();
	Line 206:             osg::Camera* camera = dynamic_cast<osg::Camera*>(curNode);
	Line 206:             osg::Camera* camera = dynamic_cast<osg::Camera*>(curNode);
	Line 209:             osg::Camera* camera = dynamic_cast<osg::Camera*>(curNode);
	Line 209:             osg::Camera* camera = dynamic_cast<osg::Camera*>(curNode);
	Line 212:             if (camera != NULL && (camera->getReferenceFrame() != osg::Transform::RELATIVE_RF || camera->getNumParents() == 0))
	Line 236:          std::vector<osg::Transform*>::reverse_iterator i = nodePath.rbegin(), iend = nodePath.rend();
	Line 239:             osg::Transform* curTran = *i;
	Line 263: bool Transformable::GetAbsoluteMatrix(const osg::Node* node, osg::Matrix& wcMatrix)
	Line 263: bool Transformable::GetAbsoluteMatrix(const osg::Node* node, osg::Matrix& wcMatrix)
	Line 280:    osg::Matrix newMat;
	Line 292:          osg::Matrix parentMat;
	Line 297:          osg::Matrix relMat = newMat * osg::Matrix::inverse(parentMat);
	Line 297:          osg::Matrix relMat = newMat * osg::Matrix::inverse(parentMat);
	Line 323:       osg::Matrix newMat;
	Line 347: const osg::Matrix& Transformable::GetMatrix() const
	Line 353: void Transformable::SetMatrix(const osg::Matrix& mat)
	Line 401: //      osg::Sphere* sphere = new osg::Sphere(osg::Vec3(0.0f, 0.0f, 0.0f), radius);
	Line 401: //      osg::Sphere* sphere = new osg::Sphere(osg::Vec3(0.0f, 0.0f, 0.0f), radius);
	Line 401: //      osg::Sphere* sphere = new osg::Sphere(osg::Vec3(0.0f, 0.0f, 0.0f), radius);
	Line 403: //      osg::Geode* proxyGeode = new osg::Geode();
	Line 403: //      osg::Geode* proxyGeode = new osg::Geode();
	Line 406: //      osg::TessellationHints* hints = new osg::TessellationHints;
	Line 406: //      osg::TessellationHints* hints = new osg::TessellationHints;
	Line 409: //      osg::ShapeDrawable* sd = new osg::ShapeDrawable(sphere, hints);
	Line 409: //      osg::ShapeDrawable* sd = new osg::ShapeDrawable(sphere, hints);
	Line 410: //      sd->setColor(osg::Vec4(1.0f, 0.0f, 1.0f, 0.5f));
	Line 414: //      osg::StateSet* ss = proxyGeode->getOrCreateStateSet();
	Line 415: //      ss->setMode(GL_BLEND, osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);
	Line 415: //      ss->setMode(GL_BLEND, osg::StateAttribute::PROTECTED | osg::StateAttribute::ON);
	Line 416: //      ss->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	Line 417: //      ss->setMode(GL_LIGHTING, osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF);
	Line 417: //      ss->setMode(GL_LIGHTING, osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF);
	Line 444:    osg::StateAttribute::GLModeValue state;
	Line 445:    state = (enable) ? osg::StateAttribute::ON : osg::StateAttribute::OFF;
	Line 445:    state = (enable) ? osg::StateAttribute::ON : osg::StateAttribute::OFF;
	Line 458:       osg::StateAttribute::GLModeValue state = GetOSGNode()->getStateSet()->getMode(GL_RESCALE_NORMAL);
	Line 459:       return (state & osg::StateAttribute::ON) ? true : false;
  D:\Development\psim\src\subview\psCore\transformable.h (8 hits)
	Line 54:     * The Transformable class creates a osg::MatrixTransform node for the
	Line 69:       typedef osg::MatrixTransform TransformableNode;
	Line 145:       const osg::Matrix& GetMatrix() const;
	Line 148:       void SetMatrix(const osg::Matrix& mat);
	Line 163:       static bool GetAbsoluteMatrix(const osg::Node* node, osg::Matrix& wcMatrix);
	Line 163:       static bool GetAbsoluteMatrix(const osg::Node* node, osg::Matrix& wcMatrix);
	Line 189:       osg::Node* GetOSGNode();
	Line 190:       const osg::Node* GetOSGNode() const;
  D:\Development\psim\src\subview\PsimCameraManipulator.cpp (78 hits)
	Line 45: PsimCameraManipulator::PsimCameraManipulator(osg::Camera *_camera, osgViewer::Viewer* _viewer)
	Line 76: void PsimCameraManipulator::setByMatrix(const osg::Matrixd& matrix)
	Line 82: void PsimCameraManipulator::setByInverseMatrix(const osg::Matrixd& matrix)
	Line 84:     setByMatrix(osg::Matrixd::inverse(matrix));
	Line 87: osg::Matrixd PsimCameraManipulator::getMatrix() const
	Line 89:     return osg::Matrixd::rotate(rotation) * osg::Matrixd::translate(center);
	Line 89:     return osg::Matrixd::rotate(rotation) * osg::Matrixd::translate(center);
	Line 92: osg::Matrixd PsimCameraManipulator::getInverseMatrix() const
	Line 94:     return osg::Matrixd::translate(-center) * osg::Matrixd::rotate(rotation.inverse());
	Line 94:     return osg::Matrixd::translate(-center) * osg::Matrixd::rotate(rotation.inverse());
	Line 97: void PsimCameraManipulator::setNode(osg::Node* node)
	Line 102: const osg::Node* PsimCameraManipulator::getNode() const
	Line 107: osg::Node* PsimCameraManipulator::getNode()
	Line 123: osg::Vec3 PsimCameraManipulator::getCenter() const
	Line 128: osg::Vec3 PsimCameraManipulator::getEyePosition() const
	Line 130:     osg::Vec3 eye, center, dir, up;
	Line 323:             angz += osg::inDegrees(os->getHeading() - 90);
	Line 335:         const osg::BoundingSphere& boundingSphere = _node->getBound();
	Line 337:         computePosition(boundingSphere.center() + osg::Vec3(0.0f, 0.0f, 20.0f),
	Line 338:                 osg::Vec3(0.0f, 1.0f, 0.0f),
	Line 339:                 osg::Vec3(0.0f, 0.0f, 1.0f));
	Line 378:         osg::Vec3f eye, cen, dir, up;
	Line 379:         osg::Vec3f hpr;
	Line 380:         osg::Matrixf view = camera->getViewMatrix();
	Line 504:                 osg::Vec3 offsetVector(0.0, 0.0, 0.0);
	Line 509:                     angz -= osg::inDegrees(os->getHeading() - 90);
	Line 563:             center = osg::Vec3(0.f, 0.f, Shared->viewAbove) + osg::Vec3(Shared->xFly, Shared->yFly, Shared->zFly); //AWB
	Line 563:             center = osg::Vec3(0.f, 0.f, Shared->viewAbove) + osg::Vec3(Shared->xFly, Shared->yFly, Shared->zFly); //AWB
	Line 565:             center = os->mCameraWorldPos + osg::Vec3(0.f, 0.f, Shared->viewAbove); //OMF
	Line 572:     osg::Matrixd vehicleOrient;
	Line 574:     osg::Matrixd cameraOrient;
	Line 576:     osg::Matrixd camOrientOffset;
	Line 589:     vehicleOrient.makeRotate(osg::inDegrees(os->getRoll()), osg::Vec3(0., 1., 0.),
	Line 589:     vehicleOrient.makeRotate(osg::inDegrees(os->getRoll()), osg::Vec3(0., 1., 0.),
	Line 590:             osg::inDegrees(-os->getPitch()), osg::Vec3(1., 0., 0.),
	Line 590:             osg::inDegrees(-os->getPitch()), osg::Vec3(1., 0., 0.),
	Line 591:             osg::inDegrees(os->getHeading() - 90.0), osg::Vec3(0., 0., 1.));
	Line 591:             osg::inDegrees(os->getHeading() - 90.0), osg::Vec3(0., 0., 1.));
	Line 593:     camOrientOffset.makeRotate(osg::inDegrees(viewRollOffset), osg::Vec3(0., 1., 0.),
	Line 593:     camOrientOffset.makeRotate(osg::inDegrees(viewRollOffset), osg::Vec3(0., 1., 0.),
	Line 594:             osg::inDegrees(viewPitchOffset), osg::Vec3(1., 0., 0.),
	Line 594:             osg::inDegrees(viewPitchOffset), osg::Vec3(1., 0., 0.),
	Line 595:             osg::inDegrees(-viewHeadingOffset), osg::Vec3(0., 0., 1.));
	Line 595:             osg::inDegrees(-viewHeadingOffset), osg::Vec3(0., 0., 1.));
	Line 597:     cameraOrient.makeRotate(osg::inDegrees(Shared->viewxcoord_pos_hpr[2]) + osg::inDegrees(rollOffset), osg::Vec3(0., 1., 0.),
	Line 597:     cameraOrient.makeRotate(osg::inDegrees(Shared->viewxcoord_pos_hpr[2]) + osg::inDegrees(rollOffset), osg::Vec3(0., 1., 0.),
	Line 597:     cameraOrient.makeRotate(osg::inDegrees(Shared->viewxcoord_pos_hpr[2]) + osg::inDegrees(rollOffset), osg::Vec3(0., 1., 0.),
	Line 598:             osg::inDegrees(Shared->viewxcoord_pos_hpr[1]) + angx + osg::inDegrees(pitchOffset), osg::Vec3(1., 0., 0.),
	Line 598:             osg::inDegrees(Shared->viewxcoord_pos_hpr[1]) + angx + osg::inDegrees(pitchOffset), osg::Vec3(1., 0., 0.),
	Line 598:             osg::inDegrees(Shared->viewxcoord_pos_hpr[1]) + angx + osg::inDegrees(pitchOffset), osg::Vec3(1., 0., 0.),
	Line 599:             osg::inDegrees(-Shared->viewxcoord_pos_hpr[0]) - angz + osg::inDegrees(-headingOffset), osg::Vec3(0., 0., 1.));
	Line 599:             osg::inDegrees(-Shared->viewxcoord_pos_hpr[0]) - angz + osg::inDegrees(-headingOffset), osg::Vec3(0., 0., 1.));
	Line 599:             osg::inDegrees(-Shared->viewxcoord_pos_hpr[0]) - angz + osg::inDegrees(-headingOffset), osg::Vec3(0., 0., 1.));
	Line 601:     osg::Quat vehicleOrientQ = vehicleOrient.getRotate();
	Line 602:     osg::Quat cameraOrientQ = cameraOrient.getRotate();
	Line 603:     osg::Quat camOrientOffsetQ = camOrientOffset.getRotate();
	Line 612: void PsimCameraManipulator::computePosition(const osg::Vec3& eye, const osg::Vec3& lv, const osg::Vec3& up)
	Line 612: void PsimCameraManipulator::computePosition(const osg::Vec3& eye, const osg::Vec3& lv, const osg::Vec3& up)
	Line 612: void PsimCameraManipulator::computePosition(const osg::Vec3& eye, const osg::Vec3& lv, const osg::Vec3& up)
	Line 614:     osg::Vec3 f(lv);
	Line 616:     osg::Vec3 s(f^up);
	Line 618:     osg::Vec3 u(s^f);
	Line 621:     osg::Matrixd rotationMatrix(s[0], u[0], -f[0], 0.0f,
	Line 625:     osg::Quat rotationMatrixInv = rotationMatrix.getRotate().inverse();
	Line 1002: void PsimCameraManipulator::setOrientationOffsets(osg::Vec3 orientationOffset)
	Line 1083:     Shared->xFly += amount * cos(angx + osg::inDegrees(pitchOffset)) * sin(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset));
	Line 1083:     Shared->xFly += amount * cos(angx + osg::inDegrees(pitchOffset)) * sin(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset));
	Line 1083:     Shared->xFly += amount * cos(angx + osg::inDegrees(pitchOffset)) * sin(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset));
	Line 1084:     Shared->yFly += amount * cos(angx + osg::inDegrees(pitchOffset)) * cos(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset));
	Line 1084:     Shared->yFly += amount * cos(angx + osg::inDegrees(pitchOffset)) * cos(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset));
	Line 1084:     Shared->yFly += amount * cos(angx + osg::inDegrees(pitchOffset)) * cos(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset));
	Line 1085:     Shared->zFly += amount * sin(angx + osg::inDegrees(pitchOffset));
	Line 1090:     Shared->xFly += amount * sin(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset) + osg::inDegrees(90.f));
	Line 1090:     Shared->xFly += amount * sin(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset) + osg::inDegrees(90.f));
	Line 1090:     Shared->xFly += amount * sin(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset) + osg::inDegrees(90.f));
	Line 1091:     Shared->yFly += amount * cos(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset) + osg::inDegrees(90.f));
	Line 1091:     Shared->yFly += amount * cos(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset) + osg::inDegrees(90.f));
	Line 1091:     Shared->yFly += amount * cos(angz + osg::inDegrees(headingOffset) + osg::inDegrees(viewHeadingOffset) + osg::inDegrees(90.f));
  D:\Development\psim\src\subview\PsimCameraManipulator.h (22 hits)
	Line 34:     PsimCameraManipulator(osg::Camera *_camera, osgViewer::Viewer* _viewer);
	Line 39:     virtual void setByMatrix(const osg::Matrixd& matrix);
	Line 42:     virtual void setByInverseMatrix(const osg::Matrixd& matrix);
	Line 45:     virtual osg::Matrixd getMatrix() const;
	Line 48:     virtual osg::Matrixd getInverseMatrix() const;
	Line 54:     virtual void setNode(osg::Node*);
	Line 57:     virtual const osg::Node* getNode() const;
	Line 60:     virtual osg::Node* getNode();
	Line 65:     osg::Vec3 getCenter() const;
	Line 66:     osg::Vec3 getEyePosition() const;
	Line 81:     void computePosition(const osg::Vec3& eye, const osg::Vec3& lv, const osg::Vec3& up);
	Line 81:     void computePosition(const osg::Vec3& eye, const osg::Vec3& lv, const osg::Vec3& up);
	Line 81:     void computePosition(const osg::Vec3& eye, const osg::Vec3& lv, const osg::Vec3& up);
	Line 103:     void setOrientationOffsets(osg::Vec3 orientationOffset);
	Line 138:     osg::ref_ptr<const osgGA::GUIEventAdapter> _ga_t1;
	Line 139:     osg::ref_ptr<const osgGA::GUIEventAdapter> _ga_t0;
	Line 141:     osg::ref_ptr<osg::Node> _node;
	Line 141:     osg::ref_ptr<osg::Node> _node;
	Line 145:     osg::Vec3 center;
	Line 146:     osg::Quat rotation;
	Line 147:     osg::Quat baseRotation;
	Line 149:     osg::Camera *camera;
  D:\Development\psim\src\subview\Radar.cpp (8 hits)
	Line 16: Radar::Radar(osg::Geode * node) :
	Line 19:     osg::Vec3f position(node->computeBound().center());
	Line 20:     mPutMatrix = osg::Matrix::translate(-position);
	Line 21:     mInvPutMatrix = osg::Matrix::translate(position);
	Line 24: void Radar::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 24: void Radar::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 30:     mTransform.postMult(osg::Matrix::rotate(mAngle, 0.f, 0.f, 1.f));
	Line 32:     dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
  D:\Development\psim\src\subview\Radar.h (7 hits)
	Line 9: class Radar : public osg::NodeCallback
	Line 13:     Radar(osg::Geode * node);
	Line 15:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 15:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 18:     osg::Matrix mPutMatrix; // puts back to world origin
	Line 19:     osg::Matrix mInvPutMatrix; // puts back to local origin
	Line 20:     osg::Matrix mTransform; // local transformation
  D:\Development\psim\src\subview\RANHud.cpp (32 hits)
	Line 93: void RANHud::addDrawable(osg::Geode * geode)
	Line 100: void RANHud::addToOSG(osg::Group * root)
	Line 102:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 102:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 102:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 108: void RANHud::drawImplementation(osg::RenderInfo& ri) const
	Line 113: void RANHud::draw(osg::RenderInfo& ri)
	Line 265:     static osg::Vec4f line_segments[7];
	Line 312:     stateSet = new osg::StateSet;
	Line 314:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 314:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 317:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 317:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 317:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 320:     textureEnabledUniform = new osg::Uniform("textureEnabled", 0.0f);
	Line 321:     redUniform = new osg::Uniform("red", 1.0f);
	Line 322:     greenUniform = new osg::Uniform("green", 0.0f);
	Line 323:     blueUniform = new osg::Uniform("blue", 0.0f);
	Line 324:     alphaUniform = new osg::Uniform("alpha", 1.0f);
	Line 333:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "overlayFrag.glsl"));
	Line 339:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 339:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 342:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 348: void RANHud::updateShaderAlphaUniform(osg::RenderInfo &ri, float value)
	Line 350:     //!! Should we use the osg::Uniform class instead?
	Line 351:     //osg::Uniform test(osg::Uniform::FLOAT, "alphaUniformLoc");
	Line 351:     //osg::Uniform test(osg::Uniform::FLOAT, "alphaUniformLoc");
	Line 354:     osg::ref_ptr<osg::State> state = ri.getState();
	Line 354:     osg::ref_ptr<osg::State> state = ri.getState();
	Line 361:     osg::ref_ptr<osg::GL2Extensions> _extensions = osg::GL2Extensions::Get(_contextID, true);
	Line 361:     osg::ref_ptr<osg::GL2Extensions> _extensions = osg::GL2Extensions::Get(_contextID, true);
	Line 361:     osg::ref_ptr<osg::GL2Extensions> _extensions = osg::GL2Extensions::Get(_contextID, true);
  D:\Development\psim\src\subview\RANHud.h (15 hits)
	Line 21:     virtual void addToOSG(osg::Group * root);
	Line 22:     virtual void addDrawable(osg::Geode * geode);
	Line 23:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 28:     virtual void draw(osg::RenderInfo& ri);
	Line 33:     void updateShaderAlphaUniform(osg::RenderInfo &ri, float value);
	Line 36:     osg::ref_ptr<osg::Uniform> textureEnabledUniform;
	Line 36:     osg::ref_ptr<osg::Uniform> textureEnabledUniform;
	Line 37:     osg::ref_ptr<osg::Uniform> redUniform;
	Line 37:     osg::ref_ptr<osg::Uniform> redUniform;
	Line 38:     osg::ref_ptr<osg::Uniform> greenUniform;
	Line 38:     osg::ref_ptr<osg::Uniform> greenUniform;
	Line 39:     osg::ref_ptr<osg::Uniform> blueUniform;
	Line 39:     osg::ref_ptr<osg::Uniform> blueUniform;
	Line 40:     osg::ref_ptr<osg::Uniform> alphaUniform;
	Line 40:     osg::ref_ptr<osg::Uniform> alphaUniform;
  D:\Development\psim\src\subview\RANSubTelemeter.cpp (16 hits)
	Line 68: void RANSubTelemeter::drawImplementation(osg::RenderInfo& ri) const
	Line 117:     stateSet = new osg::StateSet;
	Line 119:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 119:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 122:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 122:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 122:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 124:     textureEnabledUniform = new osg::Uniform("textureEnabled", 0.0f);
	Line 125:     redUniform = new osg::Uniform("red", 0.0f);
	Line 126:     greenUniform = new osg::Uniform("green", 0.0f);
	Line 127:     blueUniform = new osg::Uniform("blue", 0.0f);
	Line 128:     alphaUniform = new osg::Uniform("alpha", 1.0f);
	Line 136:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "overlayFrag.glsl"));
	Line 142:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 142:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 145:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
  D:\Development\psim\src\subview\RANSubTelemeter.h (1 hit)
	Line 20: 		virtual void drawImplementation(osg::RenderInfo& ri) const;
  D:\Development\psim\src\subview\ReflCullCallback.cpp (2 hits)
	Line 22: void ReflCullCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 22: void ReflCullCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
  D:\Development\psim\src\subview\ReflCullCallback.h (3 hits)
	Line 14: class ReflCullCallback : public osg::NodeCallback
	Line 19:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 19:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
  D:\Development\psim\src\subview\ReflectionUpdate.cpp (2 hits)
	Line 23: void ReflectionUpdate::operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 23: void ReflectionUpdate::operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\ReflectionUpdate.h (3 hits)
	Line 13: class ReflectionUpdate : public osg::Uniform::Uniform::Callback
	Line 19:     virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv);
	Line 19:     virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\RootCullCallback.cpp (2 hits)
	Line 22: void RootCullCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 22: void RootCullCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
  D:\Development\psim\src\subview\RootCullCallback.h (3 hits)
	Line 14: class RootCullCallback : public osg::NodeCallback
	Line 20:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 20:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
  D:\Development\psim\src\subview\RootNodeCallback.cpp (184 hits)
	Line 96: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 96: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 98: extern osg::ref_ptr<osg::Camera> projCamera;
	Line 98: extern osg::ref_ptr<osg::Camera> projCamera;
	Line 99: extern osg::ref_ptr<osg::Camera> reflCamera;
	Line 99: extern osg::ref_ptr<osg::Camera> reflCamera;
	Line 102: extern osg::ref_ptr<osg::Camera> submergedCamera;
	Line 102: extern osg::ref_ptr<osg::Camera> submergedCamera;
	Line 106: extern osg::ref_ptr<PrecomputeAtmoOp> precomputeOp;
	Line 110: shipsSubsGrp(new osg::Switch),
	Line 112: boundingBoxGrp(new osg::Switch),
	Line 114: nearGrp(new osg::Group),
	Line 115: edgeGrp(new osg::Group),
	Line 116: edgeReflectionGrp(new osg::Group),
	Line 117: harborsGrp(new osg::Switch),
	Line 118: harborsGrpBase(new osg::Group),
	Line 119: root(new osg::Group),
	Line 120: linesGrp(new osg::Group),
	Line 121: sternWakesGrp(new osg::Group),
	Line 122: skyDomeGrp(new osg::Group),
	Line 123: mpParticleSystemGeode(new osg::Geode),
	Line 124: aoFactor(new osg::Uniform("aoFactor", 0.0f)),
	Line 156:     root->getOrCreateStateSet()->addUniform(new osg::Uniform("submergedPass", false));
	Line 157:     root->getOrCreateStateSet()->addUniform(new osg::Uniform("reflectionPass", false));
	Line 158:     root->getOrCreateStateSet()->addUniform(new osg::Uniform("screenWidth", SubviewConfig::winWidth));
	Line 159:     root->getOrCreateStateSet()->addUniform(new osg::Uniform("screenHeight", SubviewConfig::winHeight));
	Line 168:     osg::Matrix reflMatrix;
	Line 169:     reflMatrix.makeScale(osg::Vec3(1.0, 1.0, 1.0));
	Line 170:     osg::MatrixTransform* reflTransform = new osg::MatrixTransform(reflMatrix);
	Line 170:     osg::MatrixTransform* reflTransform = new osg::MatrixTransform(reflMatrix);
	Line 172:     osg::ref_ptr <osg::ClipPlane> clipplane = new osg::ClipPlane;
	Line 172:     osg::ref_ptr <osg::ClipPlane> clipplane = new osg::ClipPlane;
	Line 172:     osg::ref_ptr <osg::ClipPlane> clipplane = new osg::ClipPlane;
	Line 175:     osg::ref_ptr<osg::ClipNode> clipNode = new osg::ClipNode;
	Line 175:     osg::ref_ptr<osg::ClipNode> clipNode = new osg::ClipNode;
	Line 175:     osg::ref_ptr<osg::ClipNode> clipNode = new osg::ClipNode;
	Line 179:     osg::StateSet * state = clipNode->getOrCreateStateSet();
	Line 180:     //state->setAttribute(new osg::CullFace(osg::CullFace::FRONT));
	Line 180:     //state->setAttribute(new osg::CullFace(osg::CullFace::FRONT));
	Line 181:     state->setMode(GL_CULL_FACE, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 181:     state->setMode(GL_CULL_FACE, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 182:     state->addUniform(new osg::Uniform("reflectionPass", true));
	Line 191:     state->addUniform(new osg::Uniform("reflection_scale", reflection_scale));
	Line 200:     state->addUniform(new osg::Uniform("reflection_darken", reflection_darken));
	Line 202:     //  state->setAttribute(new osg::PolygonMode(osg::PolygonMode::BACK, osg::PolygonMode::FILL));
	Line 202:     //  state->setAttribute(new osg::PolygonMode(osg::PolygonMode::BACK, osg::PolygonMode::FILL));
	Line 202:     //  state->setAttribute(new osg::PolygonMode(osg::PolygonMode::BACK, osg::PolygonMode::FILL));
	Line 219:     submergedCamera->getOrCreateStateSet()->addUniform(new osg::Uniform("submergedPass", true));
	Line 311:         root->removeChild((osg::Group *)skyDome);
	Line 313:         root->removeChild((osg::Group *)terrain);
	Line 318:         root->removeChild((osg::Group *)edgeInterface);
	Line 324:         root->removeChild((osg::Group *)edgeSwitchHandler);
	Line 330:         root->removeChild((osg::Group *)washover);
	Line 338:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 338:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 339:     double currentTime = osg::Timer::instance()->delta_s(viewer.getStartTick(), tick);
	Line 347:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 347:     osg::Timer_t tick = osg::Timer::instance()->tick();
	Line 348:     double currentTime = osg::Timer::instance()->delta_s(viewer.getStartTick(), tick);
	Line 364: void RootNodeCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 364: void RootNodeCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 377:     osg::Timer timer;
	Line 378:     osg::Timer_t timer_begin, timer_end;
	Line 579:                             EDGEtransforms[newEdgeLatLon] = new osg::MatrixTransform;
	Line 580:                             (EDGEtransforms[newEdgeLatLon])->setDataVariance(osg::Object::DYNAMIC);
	Line 602:                         osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 602:                         osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 602:                         osg::ref_ptr<osg::Group> grp = new osg::Group;
	Line 603:                         osg::ref_ptr<osg::MatrixTransform> xform = new osg::MatrixTransform;
	Line 603:                         osg::ref_ptr<osg::MatrixTransform> xform = new osg::MatrixTransform;
	Line 603:                         osg::ref_ptr<osg::MatrixTransform> xform = new osg::MatrixTransform;
	Line 605:                         xform->setMatrix(osg::Matrix::translate(newXY[0], newXY[1], 0.0));
	Line 607:                         xform->setDataVariance(osg::Object::STATIC);
	Line 619:                         osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 619:                         osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 619:                         osg::ref_ptr<osg::Group> flattenedTransform = (osg::Group*)grp->getChild(0);
	Line 621:                         vehicle->xform = (osg::Group*)flattenedTransform->getChild(0);
	Line 652:                                 EDGEReflectionTransforms[newEdgeLatLon] = new osg::MatrixTransform;
	Line 653:                                 (EDGEReflectionTransforms[newEdgeLatLon])->setDataVariance(osg::Object::DYNAMIC);
	Line 677:     for (std::map<std::pair<int, int>, osg::MatrixTransform*>::iterator trans_iter = RootNodeCallback::getInstance()->EDGEtransforms.begin();
	Line 689:         ((*trans_iter).second)->setMatrix(osg::Matrix::translate(cartesian[0], cartesian[1], cartesian[2]));
	Line 693:     for (std::map<std::pair<int, int>, osg::MatrixTransform*>::iterator trans_iter = RootNodeCallback::getInstance()->EDGEReflectionTransforms.begin();
	Line 705:         ((*trans_iter).second)->setMatrix(osg::Matrix::translate(cartesian[0], cartesian[1], cartesian[2]));
	Line 726:             osg::Vec3f translate, scale;
	Line 727:             osg::Quat rotate, so;
	Line 783:     //osg::StateSet* rootStateSet = root->getOrCreateStateSet();
	Line 784:     //rootStateSet->setAttribute(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK,
	Line 784:     //rootStateSet->setAttribute(new osg::PolygonMode(osg::PolygonMode::FRONT_AND_BACK,
	Line 785:     //    Shared->fillMode ? osg::PolygonMode::FILL : osg::PolygonMode::LINE ));
	Line 785:     //    Shared->fillMode ? osg::PolygonMode::FILL : osg::PolygonMode::LINE ));
	Line 839:         oceanColorOffsetUniform->set(osg::Vec3((float) Shared->ocData.offsetcolor.Red / 255.0, (float) Shared->ocData.offsetcolor.Green / 255.0, (float) Shared->ocData.offsetcolor.Blue / 255.0));
	Line 1037:         osg::Group *grp = (vehicle->getModel()->isHarbor() ? harborsGrp : shipsSubsGrp);
	Line 1048:                     EDGEReflectionTransforms[edgeLatLon] = new osg::MatrixTransform;
	Line 1049:                     (EDGEReflectionTransforms[edgeLatLon])->setDataVariance(osg::Object::DYNAMIC);
	Line 1061:                     (EDGEReflectionTransforms[edgeLatLon])->setMatrix(osg::Matrix::translate(cartesian[0], cartesian[1], cartesian[2]));
	Line 1076:                     EDGEtransforms[edgeLatLon] = new osg::MatrixTransform;
	Line 1077:                     (EDGEtransforms[edgeLatLon])->setDataVariance(osg::Object::DYNAMIC);
	Line 1089:                     (EDGEtransforms[edgeLatLon])->setMatrix(osg::Matrix::translate(cartesian[0], cartesian[1], cartesian[2]));
	Line 1137:     osg::StateSet* rootStateSet = root->getOrCreateStateSet();
	Line 1141:     rootStateSet->addUniform(new osg::Uniform("baseTexture", 0));
	Line 1142:     rootStateSet->addUniform(new osg::Uniform("specTexture", 1));
	Line 1143:     rootStateSet->addUniform(new osg::Uniform("irTexture", 2));
	Line 1144:     rootStateSet->addUniform(new osg::Uniform("normalTexture", 3));
	Line 1147:     addDynamicUniform(rootStateSet, "sunPos", osg::Uniform::FLOAT_VEC3, osg::Vec3(0.0, 0.0, 0.0),
	Line 1147:     addDynamicUniform(rootStateSet, "sunPos", osg::Uniform::FLOAT_VEC3, osg::Vec3(0.0, 0.0, 0.0),
	Line 1152:     addDynamicUniform(rootStateSet, "sunIntensity", osg::Uniform::FLOAT, 1.0f,
	Line 1157:     addDynamicUniform(rootStateSet, "sunColor", osg::Uniform::FLOAT_VEC3, osg::Vec3(0.0, 0.0, 0.0),
	Line 1157:     addDynamicUniform(rootStateSet, "sunColor", osg::Uniform::FLOAT_VEC3, osg::Vec3(0.0, 0.0, 0.0),
	Line 1162:     addDynamicUniform(rootStateSet, "moonPos", osg::Uniform::FLOAT_VEC3, osg::Vec3(0.0, 0.0, 0.0),
	Line 1162:     addDynamicUniform(rootStateSet, "moonPos", osg::Uniform::FLOAT_VEC3, osg::Vec3(0.0, 0.0, 0.0),
	Line 1167:     addDynamicUniform(rootStateSet, "moonIntensity", osg::Uniform::FLOAT, 0.0f,
	Line 1172:     addDynamicUniform(rootStateSet, "viewHeight", osg::Uniform::FLOAT, 0.0f,
	Line 1177:     lightPosUniform = new osg::Uniform("lightPos", osg::Vec3(0., 1., 0.));
	Line 1177:     lightPosUniform = new osg::Uniform("lightPos", osg::Vec3(0., 1., 0.));
	Line 1178:     lightColorUniform = new osg::Uniform("lightColor", osg::Vec4(1., 0., 0., 1.));
	Line 1178:     lightColorUniform = new osg::Uniform("lightColor", osg::Vec4(1., 0., 0., 1.));
	Line 1179:     oceanColorOffsetUniform = new osg::Uniform("oceanColorOffset", osg::Vec3(1.0, 1.0, 1.0));
	Line 1179:     oceanColorOffsetUniform = new osg::Uniform("oceanColorOffset", osg::Vec3(1.0, 1.0, 1.0));
	Line 1180:     eyeAboveUniform = new osg::Uniform("eyeAbove", false);
	Line 1181:     eyeAboveFloatUniform = new osg::Uniform("myEyeAbove", 0.0f);
	Line 1182:     myZoomUniform = new osg::Uniform("myZoom", 1.0f);
	Line 1183:     mySunTermUniform = new osg::Uniform("mySunTerm", 0.0f);
	Line 1184:     oceanHeightUniform = new osg::Uniform("oceanHeight", 0.f);
	Line 1185:     zHeightUniform = new osg::Uniform("zHeight", 0.f);
	Line 1186:     zHeightUniformNear = new osg::Uniform("zHeight", 1.f);
	Line 1187:     osg::ref_ptr<osg::Uniform> maxNegativeReflectionPassUniform = new osg::Uniform("maxNegativeReflPass", -1000.f);
	Line 1187:     osg::ref_ptr<osg::Uniform> maxNegativeReflectionPassUniform = new osg::Uniform("maxNegativeReflPass", -1000.f);
	Line 1187:     osg::ref_ptr<osg::Uniform> maxNegativeReflectionPassUniform = new osg::Uniform("maxNegativeReflPass", -1000.f);
	Line 1188:     enlightingUniform = new osg::Uniform("enlighting", true);
	Line 1189:     entextureUniform = new osg::Uniform("entexture", false);
	Line 1190:     edgeLightpointUniform = new osg::Uniform("lightpoint", false);
	Line 1198:     osg::Uniform* atmoTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "atmoSampler");
	Line 1198:     osg::Uniform* atmoTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "atmoSampler");
	Line 1198:     osg::Uniform* atmoTexUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "atmoSampler");
	Line 1201:     rootStateSet->setTextureAttributeAndModes(11, skyDome->atmoFogTex, osg::StateAttribute::ON);
	Line 1208:     osg::ref_ptr<osg::Program> programEdge = new osg::Program;
	Line 1208:     osg::ref_ptr<osg::Program> programEdge = new osg::Program;
	Line 1208:     osg::ref_ptr<osg::Program> programEdge = new osg::Program;
	Line 1214:     programEdge->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "edgeVert.glsl"));
	Line 1215:     programEdge->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "edgeFrag.glsl"));
	Line 1217:     edgeGrp->getOrCreateStateSet()->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 1217:     edgeGrp->getOrCreateStateSet()->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 1218:     edgeGrp->getOrCreateStateSet()->setMode(GL_NORMALIZE, osg::StateAttribute::ON); // this call should protect the normals of the verts after scaling
	Line 1219:     //edgeGrp->getOrCreateStateSet()->setMode (GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1219:     //edgeGrp->getOrCreateStateSet()->setMode (GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1227:     edgeReflectionGrp->getOrCreateStateSet()->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 1227:     edgeReflectionGrp->getOrCreateStateSet()->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 1228:     edgeReflectionGrp->getOrCreateStateSet()->setMode(GL_NORMALIZE, osg::StateAttribute::ON); // this call should protect the normals of the verts after scaling
	Line 1229:     //edgeReflectionGrp->getOrCreateStateSet()->setMode (GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1229:     //edgeReflectionGrp->getOrCreateStateSet()->setMode (GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1233:     osg::ref_ptr<osg::Program> programHarbor = new osg::Program;
	Line 1233:     osg::ref_ptr<osg::Program> programHarbor = new osg::Program;
	Line 1233:     osg::ref_ptr<osg::Program> programHarbor = new osg::Program;
	Line 1237:     programHarbor->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "harborVert.glsl"));
	Line 1238:     programHarbor->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "harborFrag.glsl"));
	Line 1240:     harborsGrp->getOrCreateStateSet()->setMode(GL_NORMALIZE, osg::StateAttribute::ON); // this call should protect the normals of the verts after scaling
	Line 1241:     //harborsGrp->getOrCreateStateSet()->setMode (GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1241:     //harborsGrp->getOrCreateStateSet()->setMode (GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1248:     shipsSubsGrp->getOrCreateStateSet()->setMode(GL_NORMALIZE, osg::StateAttribute::ON); // this call should protect the normals of the verts after scaling
	Line 1249:     shipsSubsGrp->getOrCreateStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::ON);
	Line 1259:     shipsSubsGrp->getOrCreateStateSet()->addUniform(new osg::Uniform("light_darken", nav_light_darken));
	Line 1265:     nearGrp->getOrCreateStateSet()->setMode(GL_NORMALIZE, osg::StateAttribute::ON); // this call should protect the normals of the verts after scaling
	Line 1266:     nearGrp->getOrCreateStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1266:     nearGrp->getOrCreateStateSet()->setMode(GL_CULL_FACE, osg::StateAttribute::OVERRIDE | osg::StateAttribute::ON);
	Line 1268:     osg::ref_ptr<osg::Program> programModel = new osg::Program;
	Line 1268:     osg::ref_ptr<osg::Program> programModel = new osg::Program;
	Line 1268:     osg::ref_ptr<osg::Program> programModel = new osg::Program;
	Line 1269:     osg::ref_ptr<osg::Shader> shipVShader = new osg::Shader(osg::Shader::VERTEX);
	Line 1269:     osg::ref_ptr<osg::Shader> shipVShader = new osg::Shader(osg::Shader::VERTEX);
	Line 1269:     osg::ref_ptr<osg::Shader> shipVShader = new osg::Shader(osg::Shader::VERTEX);
	Line 1269:     osg::ref_ptr<osg::Shader> shipVShader = new osg::Shader(osg::Shader::VERTEX);
	Line 1270:     programModel->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "modelVert.glsl"));
	Line 1271:     programModel->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "modelFrag.glsl"));
	Line 1276:     //edgeGrp->getOrCreateStateSet()->setMode( GL_DEPTH_CLAMP_NV,osg::StateAttribute::ON );
	Line 1277:     //harborsGrp->getOrCreateStateSet()->setMode( GL_DEPTH_CLAMP_NV,osg::StateAttribute::ON );
	Line 1278:     //shipsSubsGrp->getOrCreateStateSet()->setMode( GL_DEPTH_CLAMP_NV,osg::StateAttribute::ON );
	Line 1330: void RootNodeCallback::applyOccluderStencil(osg::Node* node)
	Line 1334:         occluderStencil = new osg::Stencil();
	Line 1335:         occluderStencil->setFunction(osg::Stencil::ALWAYS);
	Line 1338:         occluderStencil->setStencilPassAndDepthPassOperation(osg::Stencil::REPLACE); // write a 1 to the LSB to denote coverage
	Line 1341:     osg::ref_ptr<osg::StateSet> ss = node->getOrCreateStateSet();
	Line 1341:     osg::ref_ptr<osg::StateSet> ss = node->getOrCreateStateSet();
	Line 1342:     ss->setAttributeAndModes(occluderStencil, osg::StateAttribute::ON);
	Line 1343:     ss->setMode(GL_STENCIL_TEST, osg::StateAttribute::ON);
  D:\Development\psim\src\subview\RootNodeCallback.h (79 hits)
	Line 45: class RootNodeCallback : public osg::NodeCallback
	Line 48:     osg::ref_ptr<osg::Stencil> occluderStencil;
	Line 48:     osg::ref_ptr<osg::Stencil> occluderStencil;
	Line 55:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 55:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 61:     void setupShader(std::string filename, osg::Program **vprog, osg::Program **fprog);
	Line 61:     void setupShader(std::string filename, osg::Program **vprog, osg::Program **fprog);
	Line 63:     //	static void parseInstance (osg::Node *, int, Vehicle *vehicle, bool);
	Line 73:     osg::ref_ptr<osg::Group> shipsSubsGrp;
	Line 73:     osg::ref_ptr<osg::Group> shipsSubsGrp;
	Line 74:     osg::ref_ptr<osg::Group> edgeGrp;
	Line 74:     osg::ref_ptr<osg::Group> edgeGrp;
	Line 75:     osg::ref_ptr<osg::Group> edgeReflectionGrp;
	Line 75:     osg::ref_ptr<osg::Group> edgeReflectionGrp;
	Line 76:     osg::ref_ptr<osg::Group> harborsGrpBase;
	Line 76:     osg::ref_ptr<osg::Group> harborsGrpBase;
	Line 77:     osg::ref_ptr<osg::Group> harborsGrp;
	Line 77:     osg::ref_ptr<osg::Group> harborsGrp;
	Line 78:     osg::ref_ptr<osg::Group> skyDomeGrp;
	Line 78:     osg::ref_ptr<osg::Group> skyDomeGrp;
	Line 79:     osg::ref_ptr<osg::Switch> irCameraGroup;
	Line 79:     osg::ref_ptr<osg::Switch> irCameraGroup;
	Line 80:     osg::ref_ptr<osg::Group> sternWakesGrp;
	Line 80:     osg::ref_ptr<osg::Group> sternWakesGrp;
	Line 81:     osg::ref_ptr<osg::Group> root;
	Line 81:     osg::ref_ptr<osg::Group> root;
	Line 82:     osg::ref_ptr<osg::Group> linesGrp;
	Line 82:     osg::ref_ptr<osg::Group> linesGrp;
	Line 84:     osg::ref_ptr<osg::Switch> boundingBoxGrp;
	Line 84:     osg::ref_ptr<osg::Switch> boundingBoxGrp;
	Line 88:     osg::ref_ptr<osg::Uniform> aoFactor;
	Line 88:     osg::ref_ptr<osg::Uniform> aoFactor;
	Line 91:     osg::ref_ptr<osg::Group> nearGrp;
	Line 91:     osg::ref_ptr<osg::Group> nearGrp;
	Line 101:     std::map<std::pair<int, int>, osg::MatrixTransform*> EDGEtransforms;
	Line 102:     std::map<std::pair<int, int>, osg::MatrixTransform*> EDGEReflectionTransforms;
	Line 107:     osg::ref_ptr<osg::Uniform> oceanColorOffsetUniform;
	Line 107:     osg::ref_ptr<osg::Uniform> oceanColorOffsetUniform;
	Line 108:     osg::ref_ptr<osg::Uniform> lightPosUniform;
	Line 108:     osg::ref_ptr<osg::Uniform> lightPosUniform;
	Line 109:     osg::ref_ptr<osg::Uniform> lightColorUniform;
	Line 109:     osg::ref_ptr<osg::Uniform> lightColorUniform;
	Line 110:     osg::ref_ptr<osg::Uniform> modelViewProjOSUniform;
	Line 110:     osg::ref_ptr<osg::Uniform> modelViewProjOSUniform;
	Line 111:     osg::ref_ptr<osg::Uniform> nearModelViewProjOSUniform;
	Line 111:     osg::ref_ptr<osg::Uniform> nearModelViewProjOSUniform;
	Line 112:     osg::ref_ptr<osg::Uniform> zHeightUniformNear;
	Line 112:     osg::ref_ptr<osg::Uniform> zHeightUniformNear;
	Line 113:     osg::ref_ptr<osg::Uniform> zHeightUniform;
	Line 113:     osg::ref_ptr<osg::Uniform> zHeightUniform;
	Line 114:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 114:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 115:     osg::ref_ptr<osg::Uniform> eyeAboveFloatUniform;
	Line 115:     osg::ref_ptr<osg::Uniform> eyeAboveFloatUniform;
	Line 116:     osg::ref_ptr<osg::Uniform> myZoomUniform;
	Line 116:     osg::ref_ptr<osg::Uniform> myZoomUniform;
	Line 117:     osg::ref_ptr<osg::Uniform> mySunTermUniform;
	Line 117:     osg::ref_ptr<osg::Uniform> mySunTermUniform;
	Line 118:     osg::ref_ptr<osg::Uniform> oceanHeightUniform;
	Line 118:     osg::ref_ptr<osg::Uniform> oceanHeightUniform;
	Line 119:     osg::ref_ptr<osg::Uniform> harborLightpointUniform;
	Line 119:     osg::ref_ptr<osg::Uniform> harborLightpointUniform;
	Line 120:     osg::ref_ptr<osg::Uniform> enlightingUniform;
	Line 120:     osg::ref_ptr<osg::Uniform> enlightingUniform;
	Line 121:     osg::ref_ptr<osg::Uniform> entextureUniform;
	Line 121:     osg::ref_ptr<osg::Uniform> entextureUniform;
	Line 122:     osg::ref_ptr<osg::Uniform> edgeLightpointUniform;
	Line 122:     osg::ref_ptr<osg::Uniform> edgeLightpointUniform;
	Line 124:     osg::ref_ptr<SmokeStacks> mSmokeStacks;
	Line 125:     osg::ref_ptr<SmokeTrails> mSmokeTrails;
	Line 126:     //	osg::ref_ptr<CloudQuad> cloudQuad;
	Line 127:     osg::ref_ptr<CloudSet> mCloudSet;
	Line 128:     osg::ref_ptr<Fires> mFires;
	Line 129:     osg::ref_ptr<CloudBanks> mCloudBanks;
	Line 130:     osg::ref_ptr<Cavitations> mCavitations;
	Line 132:     osg::Matrixf viewMatrixInv;
	Line 134:     osg::ref_ptr<Stadimeter> stadimeter;
	Line 139:     osg::Geode* mpParticleSystemGeode;
	Line 143:     void applyOccluderStencil(osg::Node* node); // Applies a stencil that allows an object to occlude the sun
  D:\Development\psim\src\subview\RopesManager.cpp (49 hits)
	Line 25:     prog = new osg::Program;
	Line 26:     prog->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, ROPE_VERT));
	Line 27:     prog->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, ROPE_FRAG));
	Line 30:     kevlarTex = new osg::Texture2D;
	Line 32:     kevlarTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 32:     kevlarTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 33:     kevlarTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 33:     kevlarTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 34:     kevlarTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 34:     kevlarTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 35:     kevlarTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 35:     kevlarTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 40:     hempTex = new osg::Texture2D;
	Line 42:     hempTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 42:     hempTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 43:     hempTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 43:     hempTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 44:     hempTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 44:     hempTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 45:     hempTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 45:     hempTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 50:     nylonTex = new osg::Texture2D;
	Line 52:     nylonTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 52:     nylonTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 53:     nylonTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 53:     nylonTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 54:     nylonTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 54:     nylonTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 55:     nylonTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 55:     nylonTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 60:     chainTex = new osg::Texture2D;
	Line 62:     chainTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 62:     chainTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 63:     chainTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 63:     chainTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 64:     chainTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 64:     chainTex->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP);
	Line 65:     chainTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 65:     chainTex->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::REPEAT);
	Line 71:     blend = new osg::BlendFunc;
	Line 72:     blend->setFunction(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA);
	Line 72:     blend->setFunction(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA);
	Line 73:     texenv = new osg::TexEnv;
	Line 74:     texenv->setMode(osg::TexEnv::MODULATE);
	Line 75:     depth = new osg::Depth;
	Line 90: osg::ref_ptr<osg::Texture2D> RopesManager::getTexture(PsimLineTypeEnum materialIn)
	Line 90: osg::ref_ptr<osg::Texture2D> RopesManager::getTexture(PsimLineTypeEnum materialIn)
	Line 92:     osg::ref_ptr<osg::Texture2D> texture = NULL;
	Line 92:     osg::ref_ptr<osg::Texture2D> texture = NULL;
  D:\Development\psim\src\subview\RopesManager.h (18 hits)
	Line 36:     osg::ref_ptr<osg::BlendFunc> blend;
	Line 36:     osg::ref_ptr<osg::BlendFunc> blend;
	Line 37:     osg::ref_ptr<osg::Depth> depth;
	Line 37:     osg::ref_ptr<osg::Depth> depth;
	Line 38:     osg::ref_ptr<osg::Texture2D> kevlarTex;
	Line 38:     osg::ref_ptr<osg::Texture2D> kevlarTex;
	Line 39:     osg::ref_ptr<osg::Texture2D> hempTex;
	Line 39:     osg::ref_ptr<osg::Texture2D> hempTex;
	Line 40:     osg::ref_ptr<osg::Texture2D> nylonTex;
	Line 40:     osg::ref_ptr<osg::Texture2D> nylonTex;
	Line 41:     osg::ref_ptr<osg::Texture2D> chainTex;
	Line 41:     osg::ref_ptr<osg::Texture2D> chainTex;
	Line 42:     osg::ref_ptr<osg::TexEnv> texenv;
	Line 42:     osg::ref_ptr<osg::TexEnv> texenv;
	Line 43:     osg::ref_ptr<osg::Program> prog;
	Line 43:     osg::ref_ptr<osg::Program> prog;
	Line 45:     osg::ref_ptr<osg::Texture2D> getTexture(PsimLineTypeEnum materialIn);
	Line 45:     osg::ref_ptr<osg::Texture2D> getTexture(PsimLineTypeEnum materialIn);
  D:\Development\psim\src\subview\RopeStateSetUpdate.cpp (2 hits)
	Line 20: void RopeStateSetUpdate::operator()(osg::StateSet * ss, osg::NodeVisitor *nv)
	Line 20: void RopeStateSetUpdate::operator()(osg::StateSet * ss, osg::NodeVisitor *nv)
  D:\Development\psim\src\subview\RopeStateSetUpdate.h (3 hits)
	Line 13: class RopeStateSetUpdate: public osg::StateSet::Callback
	Line 16: 	virtual void operator () (osg::StateSet * ss, osg::NodeVisitor *nv);
	Line 16: 	virtual void operator () (osg::StateSet * ss, osg::NodeVisitor *nv);
  D:\Development\psim\src\subview\RopeUserData.cpp (4 hits)
	Line 27:     verts = new osg::Vec4Array(numVerts);
	Line 28:     texCoords = new osg::Vec2Array(numVerts);
	Line 56: osg::Vec3 RopeUserData::getStartPos()
	Line 61: osg::Vec3 RopeUserData::getEndPos()
  D:\Development\psim\src\subview\RopeUserData.h (5 hits)
	Line 16: class RopeUserData : public osg::Referenced
	Line 22:     osg::Vec3 getStartPos();
	Line 24:     osg::Vec3 getEndPos();
	Line 31:     osg::Vec4Array * verts;
	Line 32:     osg::Vec2Array * texCoords;
  D:\Development\psim\src\subview\Rotor.cpp (13 hits)
	Line 16: Rotor::Rotor(osg::Geode * node) :
	Line 19:     osg::Vec3f position(node->computeBound().center());
	Line 20:     mPutMatrix = osg::Matrix::translate(-position);
	Line 21:     mInvPutMatrix = osg::Matrix::translate(position);
	Line 23:     osg::Geometry* geom = node->getDrawable(0)->asGeometry(); //the geometry of the pivot
	Line 26:         osg::Array* norms = geom->getNormalArray(); //array of normals of the pivot
	Line 29:             osg::Vec3f* normal = (osg::Vec3f*)norms->getDataPointer(); //get the normal as a vector
	Line 29:             osg::Vec3f* normal = (osg::Vec3f*)norms->getDataPointer(); //get the normal as a vector
	Line 43: void Rotor::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 43: void Rotor::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 51: void Rotor::applyRotation(osg::Node *node)
	Line 55:     mTransform.postMult(osg::Matrix::rotate(mAngle, mAxisOfRot));
	Line 57:     dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
  D:\Development\psim\src\subview\Rotor.h (9 hits)
	Line 9: class Rotor : public osg::NodeCallback
	Line 12:     Rotor(osg::Geode * node);
	Line 13:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 13:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 14:     void applyRotation(osg::Node *node);
	Line 18:     osg::Matrix mPutMatrix; // puts back to world origin
	Line 19:     osg::Matrix mInvPutMatrix; // puts back to local origin
	Line 20:     osg::Matrix mTransform; // local transformation
	Line 21:     osg::Vec3f mAxisOfRot;
  D:\Development\psim\src\subview\Rudder.cpp (9 hits)
	Line 14: Rudder::Rudder(int contactId, Vehicle *vehicle, osg::Geode * node) :
	Line 17:     osg::Vec3f position(node->computeBound().center());
	Line 18:     mPutMatrix = osg::Matrix::translate(-position);
	Line 19:     mInvPutMatrix = osg::Matrix::translate(position);
	Line 22: void Rudder::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 22: void Rudder::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 29:         mTransform.postMult(osg::Matrix::rotate(M_PI / 180.0 * (-mAngle), 0.f, 0.f, 1.f));
	Line 31:         dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
	Line 41: osg::Vec3f Rudder::getPosition()
  D:\Development\psim\src\subview\Rudder.h (8 hits)
	Line 12: class Rudder : public osg::NodeCallback
	Line 16:     Rudder(int contactId, Vehicle *vehicle, osg::Geode * node);
	Line 18:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 18:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 22:     osg::Vec3f getPosition();
	Line 27:     osg::Matrix mPutMatrix; // puts back to world origin
	Line 28:     osg::Matrix mInvPutMatrix; // puts back to local origin
	Line 29:     osg::Matrix mTransform; // local transformation
  D:\Development\psim\src\subview\RudderDB.cpp (5 hits)
	Line 20: RudderDB::RudderDB(Vehicle* vehicle, osg::Geode *node) :
	Line 21: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 22: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 27: void RudderDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 27: void RudderDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\RudderDB.h (3 hits)
	Line 21:     RudderDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\SatImageryHandler.cpp (13 hits)
	Line 160:                 osg::ref_ptr<osg::Image> image = osgDB::readImageFile(filepath + imagefilename);
	Line 160:                 osg::ref_ptr<osg::Image> image = osgDB::readImageFile(filepath + imagefilename);
	Line 183:                     texStruct.texture = new osg::Texture2D;
	Line 185:                     texStruct.texture.get()->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 185:                     texStruct.texture.get()->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 186:                     texStruct.texture.get()->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 186:                     texStruct.texture.get()->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 188:                     texStruct.texture.get()->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP); //REPEAT);
	Line 188:                     texStruct.texture.get()->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP); //REPEAT);
	Line 189:                     texStruct.texture.get()->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP); //REPEAT);
	Line 189:                     texStruct.texture.get()->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP); //REPEAT);
	Line 190:                     texStruct.texture.get()->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
	Line 190:                     texStruct.texture.get()->setWrap(osg::Texture2D::WRAP_R, osg::Texture2D::CLAMP);
  D:\Development\psim\src\subview\SatTextureStruct.h (2 hits)
	Line 23:     osg::ref_ptr<osg::Texture2D> texture;
	Line 23:     osg::ref_ptr<osg::Texture2D> texture;
  D:\Development\psim\src\subview\SceneGraphHierarchy.cpp (12 hits)
	Line 52: void SceneGraphHierarchy::apply(osg::Node& r_node)
	Line 68:     osg::Node * p_old_parent = mpParent;
	Line 82: void SceneGraphHierarchy::buildGraph(osg::Node& r_node)
	Line 90:     osg::NodePath r_node_path;
	Line 106:                 osg::NodePath::iterator it = r_node_path.end() - 1;
	Line 107:                 osg::NodePath::iterator end = r_node_path.begin();
	Line 138: void SceneGraphHierarchy::buildText(osg::Node& r_node)
	Line 183: void SceneGraphHierarchy::callbackDisplay(osg::Node& r_node, std::string node_name,
	Line 186:     osg::NodeCallback* p_event_callback;
	Line 187:     osg::NodeCallback* p_update_callback;
	Line 188:     osg::NodeCallback* p_cull_callback;
	Line 229: bool SceneGraphHierarchy::check(osg::Node& r_node, bool exclusion)
  D:\Development\psim\src\subview\SceneGraphHierarchy.h (7 hits)
	Line 16: class SceneGraphHierarchy : public osg::NodeVisitor
	Line 26:     virtual void apply(osg::Node&);
	Line 29:     void buildGraph(osg::Node&);
	Line 30:     void buildText(osg::Node&);
	Line 31:     void callbackDisplay(osg::Node&, std::string, std::string, unsigned long);
	Line 32:     bool check(osg::Node&, bool);
	Line 43:     osg::Node* mpParent;
  D:\Development\psim\src\subview\ScreenClear.cpp (13 hits)
	Line 27: ScreenClear::ScreenClear(const ScreenClear& ScreenClear, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 27: ScreenClear::ScreenClear(const ScreenClear& ScreenClear, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 28:   osg::Geometry(ScreenClear, copyop)
	Line 37:     stateSet = new osg::StateSet;
	Line 49: osg::BoundingBox ScreenClear::computeBound() const
	Line 51:     osg::BoundingBox bbox;
	Line 52:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 53:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 57: void ScreenClear::addToOSG(osg::Group * root)
	Line 59:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 59:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 59:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 65: void ScreenClear::drawImplementation(osg::RenderInfo& ri) const
  D:\Development\psim\src\subview\ScreenClear.h (9 hits)
	Line 5:  * This is a super basic class to handle clearing the screen. Must be osg::Drawable
	Line 21: class ScreenClear : public osg::Geometry
	Line 26:     ScreenClear(const ScreenClear& ScreenClear, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 26:     ScreenClear(const ScreenClear& ScreenClear, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 28:     virtual osg::BoundingBox computeBound() const;
	Line 32:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 33:     void addToOSG(osg::Group * root);
	Line 40:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 40:     osg::ref_ptr<osg::StateSet> stateSet;
  D:\Development\psim\src\subview\SecondaryCameraCallback.cpp (3 hits)
	Line 17: SecondaryCameraCallback::SecondaryCameraCallback(int width, int height, osg::Image* image, osg::Texture* tex, int pboSize)
	Line 17: SecondaryCameraCallback::SecondaryCameraCallback(int width, int height, osg::Image* image, osg::Texture* tex, int pboSize)
	Line 24: void SecondaryCameraCallback::operator()(osg::RenderInfo& renderInfo) const
  D:\Development\psim\src\subview\SecondaryCameraCallback.h (7 hits)
	Line 14:     SecondaryCameraCallback(int width, int height, osg::Image* image, osg::Texture* tex, int pboSize = 2);
	Line 14:     SecondaryCameraCallback(int width, int height, osg::Image* image, osg::Texture* tex, int pboSize = 2);
	Line 16:     virtual void operator()(osg::RenderInfo& renderInfo) const;
	Line 21:     osg::ref_ptr<osg::Image> mpImage;
	Line 21:     osg::ref_ptr<osg::Image> mpImage;
	Line 22:     osg::ref_ptr<osg::Texture> mpTexture;
	Line 22:     osg::ref_ptr<osg::Texture> mpTexture;
  D:\Development\psim\src\subview\ShaderMaster.cpp (14 hits)
	Line 164: bool ShaderMaster::addShader(const osg::ref_ptr<osg::Shader> shader, const std::string& filename)
	Line 164: bool ShaderMaster::addShader(const osg::ref_ptr<osg::Shader> shader, const std::string& filename)
	Line 184: osg::ref_ptr<osg::Shader> ShaderMaster::createShader(const osg::Shader::Type type, const std::string& filename)
	Line 184: osg::ref_ptr<osg::Shader> ShaderMaster::createShader(const osg::Shader::Type type, const std::string& filename)
	Line 184: osg::ref_ptr<osg::Shader> ShaderMaster::createShader(const osg::Shader::Type type, const std::string& filename)
	Line 188:         osg::ref_ptr<osg::Shader> shader = new osg::Shader(type);
	Line 188:         osg::ref_ptr<osg::Shader> shader = new osg::Shader(type);
	Line 188:         osg::ref_ptr<osg::Shader> shader = new osg::Shader(type);
	Line 205: bool ShaderMaster::removeShader(osg::ref_ptr<osg::Shader> shader)
	Line 205: bool ShaderMaster::removeShader(osg::ref_ptr<osg::Shader> shader)
	Line 221: bool ShaderMaster::changeShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename)
	Line 221: bool ShaderMaster::changeShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename)
	Line 237: void ShaderMaster::loadShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename)
	Line 237: void ShaderMaster::loadShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename)
  D:\Development\psim\src\subview\ShaderMaster.h (13 hits)
	Line 54:     bool addShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename);
	Line 54:     bool addShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename);
	Line 64:     osg::ref_ptr<osg::Shader> createShader(osg::Shader::Type type, const std::string& filename);
	Line 64:     osg::ref_ptr<osg::Shader> createShader(osg::Shader::Type type, const std::string& filename);
	Line 64:     osg::ref_ptr<osg::Shader> createShader(osg::Shader::Type type, const std::string& filename);
	Line 72:     bool removeShader(osg::ref_ptr<osg::Shader> shader);
	Line 72:     bool removeShader(osg::ref_ptr<osg::Shader> shader);
	Line 79:     bool changeShader(osg::ref_ptr<osg::Shader> shader, const std::string& newFilename);
	Line 79:     bool changeShader(osg::ref_ptr<osg::Shader> shader, const std::string& newFilename);
	Line 116:     void loadShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename);
	Line 116:     void loadShader(osg::ref_ptr<osg::Shader> shader, const std::string& filename);
	Line 120:     typedef std::map<osg::ref_ptr<osg::Shader>, std::string> shaderMap;
	Line 120:     typedef std::map<osg::ref_ptr<osg::Shader>, std::string> shaderMap;
  D:\Development\psim\src\subview\SharedData.h (7 hits)
	Line 60:     osg::Vec4f fogColor;
	Line 93:     osg::Vec2 overlayBoarder = osg::Vec2();
	Line 93:     osg::Vec2 overlayBoarder = osg::Vec2();
	Line 109:     osg::Vec3 scopePivotOffset;
	Line 125:     osg::ref_ptr<osg::Image> snapshotTarget;
	Line 125:     osg::ref_ptr<osg::Image> snapshotTarget;
	Line 279:     osg::ref_ptr<Overlay> overlays;
  D:\Development\psim\src\subview\Ship.cpp (1 hit)
	Line 82:         osg::Vec3 bowPoint = xformMat->preMult(bowWake->GetPivotOffset());
  D:\Development\psim\src\subview\Ship.h (1 hit)
	Line 23:     osg::ref_ptr<BowWake> bowWake;
  D:\Development\psim\src\subview\shmstructs.h (2 hits)
	Line 32: static osg::Vec3 baseOceanColor = osg::Vec3(24.0 / 255.0, 47.0 / 255.0, 72.0 / 255.0);
	Line 32: static osg::Vec3 baseOceanColor = osg::Vec3(24.0 / 255.0, 47.0 / 255.0, 72.0 / 255.0);
  D:\Development\psim\src\subview\SkyDome.cpp (175 hits)
	Line 53: osg::ref_ptr<PrecomputeAtmoOp> precomputeOp;
	Line 55: SkyDome::SkyDome(SunMoon *_sunMoon, osg::Group *skyDomeGrp, osg::Group *root) :
	Line 55: SkyDome::SkyDome(SunMoon *_sunMoon, osg::Group *skyDomeGrp, osg::Group *root) :
	Line 59:     osg::setNotifyLevel(osg::NotifySeverity::WARN);
	Line 59:     osg::setNotifyLevel(osg::NotifySeverity::WARN);
	Line 87:     osg::ref_ptr<osg::Node> skyDome = osgDB::readNodeFile(std::string(getenv("PSIM_DATA")) + "/models/osg/skydome_scaled_old.osg");
	Line 87:     osg::ref_ptr<osg::Node> skyDome = osgDB::readNodeFile(std::string(getenv("PSIM_DATA")) + "/models/osg/skydome_scaled_old.osg");
	Line 96:         osg::MatrixTransform * loadedModelTransform = new osg::MatrixTransform;
	Line 96:         osg::MatrixTransform * loadedModelTransform = new osg::MatrixTransform;
	Line 98:         loadedModelTransform->setMatrix(osg::Matrix::rotate(osg::inDegrees(-90.f), 1.0f, 0.0f, 0.0f) *
	Line 98:         loadedModelTransform->setMatrix(osg::Matrix::rotate(osg::inDegrees(-90.f), 1.0f, 0.0f, 0.0f) *
	Line 99:                 osg::Matrix::scale(2., 2., 2.));
	Line 107:     precipIntensityUniform = new osg::Uniform("precipIntensity", 0.0f);
	Line 109:     osg::StateSet* stateSet = skyDome->getOrCreateStateSet();
	Line 113:     osg::ref_ptr<osg::Program> programSky = new osg::Program;
	Line 113:     osg::ref_ptr<osg::Program> programSky = new osg::Program;
	Line 113:     osg::ref_ptr<osg::Program> programSky = new osg::Program;
	Line 114:     programSky->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "skyVert.glsl"));
	Line 115:     programSky->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "skyFrag.glsl"));
	Line 118:     mDensityTexMat = new osg::TexMat;
	Line 119:     mDensityTexMat->setMatrix(osg::Matrix::translate(0., 0., 0.) * osg::Matrix::scale(2., 2., 2.));
	Line 119:     mDensityTexMat->setMatrix(osg::Matrix::translate(0., 0., 0.) * osg::Matrix::scale(2., 2., 2.));
	Line 122:     osg::Depth* depth = new osg::Depth;
	Line 122:     osg::Depth* depth = new osg::Depth;
	Line 124:     stateSet->setAttributeAndModes(depth, osg::StateAttribute::ON);
	Line 126:     stateSet->setMode(GL_CULL_FACE, osg::StateAttribute::OFF);
	Line 127:     stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	Line 128:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 128:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 148:         stateSet->addUniform(new osg::Uniform(ss.str().c_str(), ii + cloud_tex_offset));
	Line 150:         osg::ref_ptr<osg::Texture2D> cloudTex = new osg::Texture2D;
	Line 150:         osg::ref_ptr<osg::Texture2D> cloudTex = new osg::Texture2D;
	Line 150:         osg::ref_ptr<osg::Texture2D> cloudTex = new osg::Texture2D;
	Line 151:         cloudTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::NEAREST_MIPMAP_LINEAR);
	Line 151:         cloudTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::NEAREST_MIPMAP_LINEAR);
	Line 152:         cloudTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 152:         cloudTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 153:         cloudTex->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 153:         cloudTex->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 154:         cloudTex->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 154:         cloudTex->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 156:         stateSet->setTextureAttributeAndModes(ii + cloud_tex_offset, cloudTex.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 156:         stateSet->setTextureAttributeAndModes(ii + cloud_tex_offset, cloudTex.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 159:     mCloudTypeFrac0Uniform = new osg::Uniform("cloudTypeFrac0", 0.f);
	Line 160:     mCloudTypeFrac1Uniform = new osg::Uniform("cloudTypeFrac1", 0.f);
	Line 161:     mCloudTypeFrac2Uniform = new osg::Uniform("cloudTypeFrac2", 0.f);
	Line 162:     mCloudTypeFrac3Uniform = new osg::Uniform("cloudTypeFrac3", 0.f);
	Line 163:     mCloudTypeFrac4Uniform = new osg::Uniform("cloudTypeFrac4", 0.f);
	Line 164:     mCloudTypeFrac5Uniform = new osg::Uniform("cloudTypeFrac5", 0.f);
	Line 182:     mCloudDensityUniform = new osg::Uniform("cloudDensity", 1.0f);
	Line 183:     mDensityTexUniform = new osg::Uniform("densityTex", 1);
	Line 187:     mDensityTex = new osg::Texture3D;
	Line 188:     mDensityTex->setFilter(osg::Texture3D::MIN_FILTER, osg::Texture3D::LINEAR);
	Line 188:     mDensityTex->setFilter(osg::Texture3D::MIN_FILTER, osg::Texture3D::LINEAR);
	Line 189:     mDensityTex->setFilter(osg::Texture3D::MAG_FILTER, osg::Texture3D::LINEAR);
	Line 189:     mDensityTex->setFilter(osg::Texture3D::MAG_FILTER, osg::Texture3D::LINEAR);
	Line 190:     mDensityTex->setWrap(osg::Texture3D::WRAP_S, osg::Texture3D::REPEAT);
	Line 190:     mDensityTex->setWrap(osg::Texture3D::WRAP_S, osg::Texture3D::REPEAT);
	Line 191:     mDensityTex->setWrap(osg::Texture3D::WRAP_T, osg::Texture3D::REPEAT);
	Line 191:     mDensityTex->setWrap(osg::Texture3D::WRAP_T, osg::Texture3D::REPEAT);
	Line 192:     mDensityTex->setWrap(osg::Texture3D::WRAP_R, osg::Texture3D::CLAMP_TO_BORDER);
	Line 192:     mDensityTex->setWrap(osg::Texture3D::WRAP_R, osg::Texture3D::CLAMP_TO_BORDER);
	Line 194:     osg::ref_ptr<osg::Image> image;
	Line 194:     osg::ref_ptr<osg::Image> image;
	Line 196:     osg::Image* image_3d = new osg::Image;
	Line 196:     osg::Image* image_3d = new osg::Image;
	Line 218:         stateSet->setTextureAttributeAndModes(1, mDensityTex.get(), osg::StateAttribute::ON);
	Line 219:         stateSet->setTextureAttributeAndModes(1, mDensityTexMat.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 219:         stateSet->setTextureAttributeAndModes(1, mDensityTexMat.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 222:     stateSet->setDataVariance(osg::Object::STATIC);
	Line 225: osg::Group* SkyDome::createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 225: osg::Group* SkyDome::createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 225: osg::Group* SkyDome::createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 225: osg::Group* SkyDome::createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 227:     osg::Program* skyRenderProgram = new osg::Program(); // Create a partial atmo render shader for cubemap
	Line 227:     osg::Program* skyRenderProgram = new osg::Program(); // Create a partial atmo render shader for cubemap
	Line 228:     skyRenderProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "skyRenderSimplified.glsl"));
	Line 229:     skyRenderProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "skyRenderSimplified.glsl"));
	Line 234: osg::Group* SkyDome::createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 234: osg::Group* SkyDome::createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 234: osg::Group* SkyDome::createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 234: osg::Group* SkyDome::createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 236:     osg::Program* skyRenderProgram = new osg::Program(); // Create a partial atmo render shader for cubemap
	Line 236:     osg::Program* skyRenderProgram = new osg::Program(); // Create a partial atmo render shader for cubemap
	Line 237:     skyRenderProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "skyRenderSimplified.glsl"));
	Line 238:     skyRenderProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "skyRenderSimplified.glsl"));
	Line 243: osg::Group* SkyDome::createAtmoSubgraphForFramebuffer(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 243: osg::Group* SkyDome::createAtmoSubgraphForFramebuffer(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 243: osg::Group* SkyDome::createAtmoSubgraphForFramebuffer(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const
	Line 245:     osg::Texture2D* atmoRenderTex = SkydomeUtils::createRTTTarget(width, height, GL_RGBA,
	Line 246:             osg::Texture2D::LINEAR, osg::Texture2D::LINEAR,
	Line 246:             osg::Texture2D::LINEAR, osg::Texture2D::LINEAR,
	Line 247:             osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE);
	Line 247:             osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE);
	Line 247:             osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE);
	Line 249:     osg::Program* skyRenderProgram = new osg::Program(); // Create a full atmo render shader for framebuffer
	Line 249:     osg::Program* skyRenderProgram = new osg::Program(); // Create a full atmo render shader for framebuffer
	Line 250:     skyRenderProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "skyRender.glsl"));
	Line 251:     skyRenderProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "skyRender.glsl"));
	Line 254:     osg::Group* _root = createAtmoSubgraph(_precomputeOp, width, height, skyRenderProgram, atmoRenderTex, 0, NULL, atmoFogTex, false);
	Line 258:     osg::Camera* skyCopyCam = new osg::Camera();
	Line 258:     osg::Camera* skyCopyCam = new osg::Camera();
	Line 261:     skyCopyCam->setProjectionMatrix(osg::Matrix::ortho2D(0, width, 0, height));
	Line 262:     skyCopyCam->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	Line 263:     skyCopyCam->setViewMatrix(osg::Matrix::identity());
	Line 264:     skyCopyCam->setClearColor(osg::Vec4(.7f, 0.1f, 0.0f, 1.0f));
	Line 266:     skyCopyCam->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 267:     skyCopyCam->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER);
	Line 270:     osg::Program* skyCopyProgram = new osg::Program();
	Line 270:     osg::Program* skyCopyProgram = new osg::Program();
	Line 271:     skyCopyProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "atmoScreenQuadVertShader.glsl"));
	Line 272:     skyCopyProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "atmoCopySky.glsl"));
	Line 273:     skyCopyCam->getOrCreateStateSet()->setAttribute(skyCopyProgram, osg::StateAttribute::ON); // apply this to the camera so we can use a simplified shader program for the cubemap
	Line 280: osg::Group* SkyDome::createAtmoSubgraph(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Program* skyRenderProgram,
	Line 280: osg::Group* SkyDome::createAtmoSubgraph(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Program* skyRenderProgram,
	Line 281:                                         osg::Texture* atmoRenderTex, unsigned int cubeMapIndex, osg::Image* atmoRenderImage,
	Line 281:                                         osg::Texture* atmoRenderTex, unsigned int cubeMapIndex, osg::Image* atmoRenderImage,
	Line 282:                                         osg::ref_ptr<osg::Texture2D>& atmoFogTex, bool isCubeMap) const
	Line 282:                                         osg::ref_ptr<osg::Texture2D>& atmoFogTex, bool isCubeMap) const
	Line 284:     osg::Group* _root = new osg::Group();
	Line 284:     osg::Group* _root = new osg::Group();
	Line 285:     osg::Camera* cam = new osg::Camera();
	Line 285:     osg::Camera* cam = new osg::Camera();
	Line 289:             osg::Texture2D::LINEAR, osg::Texture2D::LINEAR,
	Line 289:             osg::Texture2D::LINEAR, osg::Texture2D::LINEAR,
	Line 290:             osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE);
	Line 290:             osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE);
	Line 290:             osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE, osg::Texture::CLAMP_TO_EDGE);
	Line 293:     cam->setProjectionMatrix(osg::Matrix::identity());
	Line 294:     cam->setViewMatrix(osg::Matrix::identity());
	Line 295:     cam->setClearColor(osg::Vec4(.7f, 0.1f, 0.0f, 1.0f));
	Line 297:     cam->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 298:     cam->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 299:     cam->attach(osg::Camera::COLOR_BUFFER1, atmoFogTex);
	Line 303:         cam->attach(osg::Camera::COLOR_BUFFER0, atmoRenderImage);
	Line 307:         cam->attach(osg::Camera::COLOR_BUFFER0, atmoRenderTex, 0, cubeMapIndex);
	Line 310:     osg::Geometry* quadGeom = osg::createTexturedQuadGeometry(osg::Vec3(-1.0 / 2.0, -1.0 / 2.0, 0.f),
	Line 310:     osg::Geometry* quadGeom = osg::createTexturedQuadGeometry(osg::Vec3(-1.0 / 2.0, -1.0 / 2.0, 0.f),
	Line 310:     osg::Geometry* quadGeom = osg::createTexturedQuadGeometry(osg::Vec3(-1.0 / 2.0, -1.0 / 2.0, 0.f),
	Line 311:                                                               osg::Vec3(1.0, 0.0f, 0.0f),
	Line 312:                                                               osg::Vec3(0.0f, 1.0, 0.0f));
	Line 314:     quadGeom->setDataVariance(osg::Object::STATIC);
	Line 318:     osg::Geode* screenQuadGeode = new osg::Geode();
	Line 318:     osg::Geode* screenQuadGeode = new osg::Geode();
	Line 323:     osg::StateSet* stateSet = quadGeom->getOrCreateStateSet();
	Line 325:     osg::Depth* depth = new osg::Depth;
	Line 325:     osg::Depth* depth = new osg::Depth;
	Line 327:     stateSet->setAttributeAndModes(depth, osg::StateAttribute::ON);
	Line 329:     stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	Line 330:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 332:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 336:     osg::Uniform* transmittanceUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 336:     osg::Uniform* transmittanceUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 336:     osg::Uniform* transmittanceUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "transmittanceSampler");
	Line 339:     stateSet->setTextureAttributeAndModes(0, _precomputeOp->transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 339:     stateSet->setTextureAttributeAndModes(0, _precomputeOp->transmittanceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 341:     osg::Uniform* irradianceUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "irradianceSampler");
	Line 341:     osg::Uniform* irradianceUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "irradianceSampler");
	Line 341:     osg::Uniform* irradianceUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "irradianceSampler");
	Line 344:     stateSet->setTextureAttributeAndModes(1, _precomputeOp->irradianceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 344:     stateSet->setTextureAttributeAndModes(1, _precomputeOp->irradianceSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 346:     osg::Uniform* inscatterUniform = new osg::Uniform(osg::Uniform::SAMPLER_3D, "inscatterSampler");
	Line 346:     osg::Uniform* inscatterUniform = new osg::Uniform(osg::Uniform::SAMPLER_3D, "inscatterSampler");
	Line 346:     osg::Uniform* inscatterUniform = new osg::Uniform(osg::Uniform::SAMPLER_3D, "inscatterSampler");
	Line 349:     stateSet->setTextureAttributeAndModes(2, _precomputeOp->inscatterSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 349:     stateSet->setTextureAttributeAndModes(2, _precomputeOp->inscatterSampler, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 351:     osg::Uniform* exposureUniform = new osg::Uniform("exposure", 0.4f);
	Line 351:     osg::Uniform* exposureUniform = new osg::Uniform("exposure", 0.4f);
	Line 354:     osg::Uniform* vertScaleUniform = new osg::Uniform("vertScale", osg::Vec2(width, height));
	Line 354:     osg::Uniform* vertScaleUniform = new osg::Uniform("vertScale", osg::Vec2(width, height));
	Line 354:     osg::Uniform* vertScaleUniform = new osg::Uniform("vertScale", osg::Vec2(width, height));
	Line 357:     cam->getOrCreateStateSet()->setAttribute(skyRenderProgram, osg::StateAttribute::ON);
	Line 377:     osg::Vec3f localMotion;
	Line 381:     mDensityTexMat->setMatrix(osg::Matrix::translate(localMotion[0]*1.2, localMotion[1]*1.2, 1) * osg::Matrix::scale(2., 2., 2.));
	Line 381:     mDensityTexMat->setMatrix(osg::Matrix::translate(localMotion[0]*1.2, localMotion[1]*1.2, 1) * osg::Matrix::scale(2., 2., 2.));
  D:\Development\psim\src\subview\SkyDome.h (55 hits)
	Line 28:     SkyDome(SunMoon *sunmoon, osg::Group *skyDomeGrp, osg::Group *root);
	Line 28:     SkyDome(SunMoon *sunmoon, osg::Group *skyDomeGrp, osg::Group *root);
	Line 31:     osg::ref_ptr<osg::Texture2D> atmoFogTex; // texture storing atmosphere image
	Line 31:     osg::ref_ptr<osg::Texture2D> atmoFogTex; // texture storing atmosphere image
	Line 33:     osg::Group* createAtmoSubgraphForFramebuffer(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 33:     osg::Group* createAtmoSubgraphForFramebuffer(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 33:     osg::Group* createAtmoSubgraphForFramebuffer(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 34:     osg::Group* createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 34:     osg::Group* createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 34:     osg::Group* createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 34:     osg::Group* createAtmoSubgraphForCubeMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::TextureCubeMap* atmoRenderTex, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 35:     osg::Group* createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 35:     osg::Group* createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 35:     osg::Group* createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 35:     osg::Group* createAtmoSubgraphForLightSampleMap(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Image* lightSampleImage, unsigned int cubeMapIndex, osg::ref_ptr<osg::Texture2D>& atmoFogTex) const;
	Line 38:     osg::Group* createAtmoSubgraph(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Program* skyRenderProgram,
	Line 38:     osg::Group* createAtmoSubgraph(PrecomputeAtmoOp* _precomputeOp, unsigned int width, unsigned int height, osg::Program* skyRenderProgram,
	Line 39:                                    osg::Texture* atmoRenderTex, unsigned int cubeMapIndex, osg::Image* atmoRenderImage,
	Line 39:                                    osg::Texture* atmoRenderTex, unsigned int cubeMapIndex, osg::Image* atmoRenderImage,
	Line 40:                                    osg::ref_ptr<osg::Texture2D>& atmoFogTex, bool isCubeMap) const;
	Line 40:                                    osg::ref_ptr<osg::Texture2D>& atmoFogTex, bool isCubeMap) const;
	Line 45:     osg::ref_ptr<osg::TexMat> mDensityTexMat;
	Line 45:     osg::ref_ptr<osg::TexMat> mDensityTexMat;
	Line 46:     osg::ref_ptr<osg::Texture3D> mDensityTex;
	Line 46:     osg::ref_ptr<osg::Texture3D> mDensityTex;
	Line 48:     osg::ref_ptr<osg::Uniform> viewHeightUniform;
	Line 48:     osg::ref_ptr<osg::Uniform> viewHeightUniform;
	Line 49:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 49:     osg::ref_ptr<osg::Uniform> eyeAboveUniform;
	Line 50:     osg::ref_ptr<osg::Uniform> sunHaloColorUniform;
	Line 50:     osg::ref_ptr<osg::Uniform> sunHaloColorUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> skyTopColorUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> skyTopColorUniform;
	Line 52:     osg::ref_ptr<osg::Uniform> skyBotColorUniform;
	Line 52:     osg::ref_ptr<osg::Uniform> skyBotColorUniform;
	Line 53:     osg::ref_ptr<osg::Uniform> skyEveningColorUniform;
	Line 53:     osg::ref_ptr<osg::Uniform> skyEveningColorUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> precipIntensityUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> precipIntensityUniform;
	Line 56:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac0Uniform;
	Line 56:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac0Uniform;
	Line 57:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac1Uniform;
	Line 57:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac1Uniform;
	Line 58:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac2Uniform;
	Line 58:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac2Uniform;
	Line 59:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac3Uniform;
	Line 59:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac3Uniform;
	Line 60:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac4Uniform;
	Line 60:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac4Uniform;
	Line 61:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac5Uniform;
	Line 61:     osg::ref_ptr<osg::Uniform> mCloudTypeFrac5Uniform;
	Line 63:     osg::ref_ptr<osg::Uniform> mCloudDensityUniform;
	Line 63:     osg::ref_ptr<osg::Uniform> mCloudDensityUniform;
	Line 64:     osg::ref_ptr<osg::Uniform> mDensityTexUniform;
	Line 64:     osg::ref_ptr<osg::Uniform> mDensityTexUniform;
  D:\Development\psim\src\subview\SkydomeGraphicsContext.cpp (5 hits)
	Line 15:     osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	Line 15:     osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	Line 15:     osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;
	Line 25:     _gc = osg::GraphicsContext::createGraphicsContext(traits.get());
	Line 30:         _gc = osg::GraphicsContext::createGraphicsContext(traits.get());
  D:\Development\psim\src\subview\SkydomeGraphicsContext.h (2 hits)
	Line 22:     osg::ref_ptr<osg::GraphicsContext> _gc;
	Line 22:     osg::ref_ptr<osg::GraphicsContext> _gc;
  D:\Development\psim\src\subview\SkydomeUtils.cpp (106 hits)
	Line 29: osg::ref_ptr<osg::Geode> SkydomeUtils::createScreenQuadInstances(float width, float height, int numInstances)
	Line 29: osg::ref_ptr<osg::Geode> SkydomeUtils::createScreenQuadInstances(float width, float height, int numInstances)
	Line 31:     const osg::Vec3 corner = osg::Vec3(0., 0., 0.);
	Line 31:     const osg::Vec3 corner = osg::Vec3(0., 0., 0.);
	Line 32:     const osg::Vec3 widthVec = osg::Vec3(width, 0.0f, 0.0f);
	Line 32:     const osg::Vec3 widthVec = osg::Vec3(width, 0.0f, 0.0f);
	Line 33:     const osg::Vec3 heightVec = osg::Vec3(0.0f, height, 0.0f);
	Line 33:     const osg::Vec3 heightVec = osg::Vec3(0.0f, height, 0.0f);
	Line 38:     osg::ref_ptr<osg::Geometry> geom = new osg::Geometry();
	Line 38:     osg::ref_ptr<osg::Geometry> geom = new osg::Geometry();
	Line 38:     osg::ref_ptr<osg::Geometry> geom = new osg::Geometry();
	Line 40:     osg::Vec3Array* coords = new osg::Vec3Array(4);
	Line 40:     osg::Vec3Array* coords = new osg::Vec3Array(4);
	Line 47:     osg::Vec2Array* tcoords = new osg::Vec2Array(4);
	Line 47:     osg::Vec2Array* tcoords = new osg::Vec2Array(4);
	Line 54:     osg::Vec4Array* colours = new osg::Vec4Array(1);
	Line 54:     osg::Vec4Array* colours = new osg::Vec4Array(1);
	Line 57:     geom->setColorBinding(osg::Geometry::BIND_OVERALL);
	Line 59:     osg::Vec3Array* normals = new osg::Vec3Array(1);
	Line 59:     osg::Vec3Array* normals = new osg::Vec3Array(1);
	Line 63:     geom->setNormalBinding(osg::Geometry::BIND_OVERALL);
	Line 65:     geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4, numInstances));
	Line 65:     geom->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, 4, numInstances));
	Line 67:     geom->setStateSet(new osg::StateSet());
	Line 70:     osg::ref_ptr<osg::StateSet> stateSet = geom->getOrCreateStateSet();
	Line 70:     osg::ref_ptr<osg::StateSet> stateSet = geom->getOrCreateStateSet();
	Line 71:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 72:     osg::ref_ptr<osg::Geode> screenQuadGeode = new osg::Geode();
	Line 72:     osg::ref_ptr<osg::Geode> screenQuadGeode = new osg::Geode();
	Line 72:     osg::ref_ptr<osg::Geode> screenQuadGeode = new osg::Geode();
	Line 78: osg::Geode* SkydomeUtils::createScreenQuad(int width, int height, osg::Texture* tex, osg::Program* prog)
	Line 78: osg::Geode* SkydomeUtils::createScreenQuad(int width, int height, osg::Texture* tex, osg::Program* prog)
	Line 78: osg::Geode* SkydomeUtils::createScreenQuad(int width, int height, osg::Texture* tex, osg::Program* prog)
	Line 80:     osg::Geometry* quadGeom = osg::createTexturedQuadGeometry(osg::Vec3(),
	Line 80:     osg::Geometry* quadGeom = osg::createTexturedQuadGeometry(osg::Vec3(),
	Line 80:     osg::Geometry* quadGeom = osg::createTexturedQuadGeometry(osg::Vec3(),
	Line 81:             osg::Vec3(width, 0.0f, 0.0f),
	Line 82:             osg::Vec3(0.0f, height, 0.0f));
	Line 83:     quadGeom->setStateSet(new osg::StateSet());
	Line 85:     osg::StateSet* stateSet = quadGeom->getOrCreateStateSet();
	Line 86:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 88:     osg::Geode* screenQuadGeode = new osg::Geode();
	Line 88:     osg::Geode* screenQuadGeode = new osg::Geode();
	Line 93:         osg::Uniform* texUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "inputImage");
	Line 93:         osg::Uniform* texUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "inputImage");
	Line 93:         osg::Uniform* texUniform = new osg::Uniform(osg::Uniform::SAMPLER_2D, "inputImage");
	Line 96:         screenQuadGeode->getOrCreateStateSet()->setTextureAttributeAndModes(0, tex, osg::StateAttribute::ON);
	Line 101:         quadGeom->getOrCreateStateSet()->setAttribute(prog, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 101:         quadGeom->getOrCreateStateSet()->setAttribute(prog, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 107: osg::Texture2D* SkydomeUtils::createRTTTarget(int width, int height, GLint internalFormat,
	Line 108:         osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 108:         osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 109:         osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 109:         osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 110:         osg::Texture::WrapMode wrapR)
	Line 112:     osg::Texture2D* rttTarget = new osg::Texture2D;
	Line 112:     osg::Texture2D* rttTarget = new osg::Texture2D;
	Line 114:     rttTarget->setInternalFormat(/*osg::Texture::USE_IMAGE_DATA_FORMAT*/GL_RGB16F_ARB); //GL_RGBA
	Line 115:     rttTarget->setFilter(osg::Texture2D::MIN_FILTER, minFilter);
	Line 116:     rttTarget->setFilter(osg::Texture2D::MAG_FILTER, magFilter);
	Line 118:     rttTarget->setWrap(osg::Texture::WRAP_S, wrapS);
	Line 119:     rttTarget->setWrap(osg::Texture::WRAP_T, wrapT);
	Line 120:     //    rttTarget->setWrap(osg::Texture::WRAP_R, wrapR);
	Line 122:     osg::Image* image = new osg::Image;
	Line 122:     osg::Image* image = new osg::Image;
	Line 129: osg::ref_ptr<osg::Texture3D> SkydomeUtils::createRTTTarget(int width, int height, int depth, GLint internalFormat,
	Line 129: osg::ref_ptr<osg::Texture3D> SkydomeUtils::createRTTTarget(int width, int height, int depth, GLint internalFormat,
	Line 130:         osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 130:         osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 131:         osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 131:         osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 132:         osg::Texture::WrapMode wrapR)
	Line 134:     osg::ref_ptr<osg::Texture3D> rttTarget = new osg::Texture3D();
	Line 134:     osg::ref_ptr<osg::Texture3D> rttTarget = new osg::Texture3D();
	Line 134:     osg::ref_ptr<osg::Texture3D> rttTarget = new osg::Texture3D();
	Line 137:     rttTarget->setFilter(osg::Texture2D::MIN_FILTER, minFilter);
	Line 138:     rttTarget->setFilter(osg::Texture2D::MAG_FILTER, magFilter);
	Line 140:     rttTarget->setWrap(osg::Texture::WRAP_S, wrapS);
	Line 141:     rttTarget->setWrap(osg::Texture::WRAP_T, wrapT);
	Line 142:     rttTarget->setWrap(osg::Texture::WRAP_R, wrapR);
	Line 144:     osg::ref_ptr<osg::Image> image = new osg::Image;
	Line 144:     osg::ref_ptr<osg::Image> image = new osg::Image;
	Line 144:     osg::ref_ptr<osg::Image> image = new osg::Image;
	Line 151: osg::Camera* SkydomeUtils::createRTTCamera(int width, int height)
	Line 153:     osg::ref_ptr<osg::Camera> rttCamera = new osg::Camera();
	Line 153:     osg::ref_ptr<osg::Camera> rttCamera = new osg::Camera();
	Line 153:     osg::ref_ptr<osg::Camera> rttCamera = new osg::Camera();
	Line 156:     rttCamera->setProjectionMatrix(osg::Matrix::ortho2D(0, width, 0, height));
	Line 157:     rttCamera->setReferenceFrame(osg::Transform::ABSOLUTE_RF);
	Line 158:     rttCamera->setViewMatrix(osg::Matrix::identity());
	Line 159:     rttCamera->setClearColor(osg::Vec4(.7f, 0.1f, 0.0f, 1.0f));
	Line 161:     rttCamera->setRenderOrder(osg::Camera::PRE_RENDER);
	Line 162:     rttCamera->setRenderTargetImplementation(osg::Camera::FRAME_BUFFER_OBJECT);
	Line 167: RTTPair SkydomeUtils::createRTTPair(int width, int height, osg::Program* program, GLint internalFormat,
	Line 168:         osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 168:         osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 169:         osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 169:         osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 170:         osg::Texture::WrapMode wrapR)
	Line 172:     osg::ref_ptr<osg::Texture2D> tex = createRTTTarget(width, height, internalFormat, minFilter, magFilter,
	Line 172:     osg::ref_ptr<osg::Texture2D> tex = createRTTTarget(width, height, internalFormat, minFilter, magFilter,
	Line 174:     osg::ref_ptr<osg::Camera> cam = createRTTCamera(width, height);
	Line 174:     osg::ref_ptr<osg::Camera> cam = createRTTCamera(width, height);
	Line 176:     cam->attach(osg::Camera::COLOR_BUFFER, tex);
	Line 179:         cam->getOrCreateStateSet()->setAttribute(program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 179:         cam->getOrCreateStateSet()->setAttribute(program, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
  D:\Development\psim\src\subview\SkydomeUtils.h (40 hits)
	Line 22: typedef std::pair<osg::Camera*, osg::ref_ptr<osg::Texture> > RTTPair;
	Line 22: typedef std::pair<osg::Camera*, osg::ref_ptr<osg::Texture> > RTTPair;
	Line 22: typedef std::pair<osg::Camera*, osg::ref_ptr<osg::Texture> > RTTPair;
	Line 23: typedef std::pair<osg::ref_ptr<osg::Texture>, char*> TextureAttachment;
	Line 23: typedef std::pair<osg::ref_ptr<osg::Texture>, char*> TextureAttachment;
	Line 40:     static osg::ref_ptr<osg::Geode> createScreenQuadInstances(float width, float height, int numInstances);
	Line 40:     static osg::ref_ptr<osg::Geode> createScreenQuadInstances(float width, float height, int numInstances);
	Line 42:     static osg::Geode* createScreenQuad(int width, int height, osg::Texture* tex = NULL, osg::Program* prog = NULL);
	Line 42:     static osg::Geode* createScreenQuad(int width, int height, osg::Texture* tex = NULL, osg::Program* prog = NULL);
	Line 42:     static osg::Geode* createScreenQuad(int width, int height, osg::Texture* tex = NULL, osg::Program* prog = NULL);
	Line 44:     static osg::Texture2D* createRTTTarget(int width, int height, GLint internalFormat,
	Line 45:                                            osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 45:                                            osg::Texture::FilterMode minFilter, osg::Texture::FilterMode magFilter,
	Line 46:                                            osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 46:                                            osg::Texture::WrapMode wrapS, osg::Texture::WrapMode wrapT,
	Line 47:                                            osg::Texture::WrapMode wrapR);
	Line 49:     static osg::ref_ptr<osg::Texture3D> createRTTTarget(int width, int height, int depth, GLint internalFormat = GL_RGB16F_ARB,
	Line 49:     static osg::ref_ptr<osg::Texture3D> createRTTTarget(int width, int height, int depth, GLint internalFormat = GL_RGB16F_ARB,
	Line 50:                                                         osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 50:                                                         osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 50:                                                         osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 50:                                                         osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 51:                                                         osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 51:                                                         osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 51:                                                         osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 51:                                                         osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 52:                                                         osg::Texture::WrapMode wrapR = osg::Texture::CLAMP_TO_EDGE);
	Line 52:                                                         osg::Texture::WrapMode wrapR = osg::Texture::CLAMP_TO_EDGE);
	Line 54:     static osg::Camera* createRTTCamera(int width, int height);
	Line 56:     static RTTPair createRTTPair(int width, int height, osg::Program* program = NULL, GLint internalFormat = GL_RGBA,
	Line 57:                                  osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 57:                                  osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 57:                                  osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 57:                                  osg::Texture::FilterMode minFilter = osg::Texture2D::LINEAR, osg::Texture::FilterMode magFilter = osg::Texture2D::LINEAR,
	Line 58:                                  osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 58:                                  osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 58:                                  osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 58:                                  osg::Texture::WrapMode wrapS = osg::Texture::CLAMP_TO_EDGE, osg::Texture::WrapMode wrapT = osg::Texture::CLAMP_TO_EDGE,
	Line 59:                                  osg::Texture::WrapMode wrapR = osg::Texture::CLAMP_TO_EDGE);
	Line 59:                                  osg::Texture::WrapMode wrapR = osg::Texture::CLAMP_TO_EDGE);
  D:\Development\psim\src\subview\SmokeStacks.cpp (38 hits)
	Line 41:     mStateSet = new osg::StateSet;
	Line 44:     osg::ref_ptr<osg::Image> img;
	Line 44:     osg::ref_ptr<osg::Image> img;
	Line 47:     mTexture = new osg::Texture2D;
	Line 49:     mTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 49:     mTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 50:     mTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 50:     mTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 51:     mTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 51:     mTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 52:     mTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 52:     mTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 55:     mStateSet->setTextureAttributeAndModes(0, mTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 55:     mStateSet->setTextureAttributeAndModes(0, mTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 56:     mStateSet->addUniform(new osg::Uniform("smoke", 0));
	Line 59:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 59:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 59:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 61:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "stackSmokeVert.glsl"));
	Line 62:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "stackSmokeFrag.glsl"));
	Line 64:     mStateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 64:     mStateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 66:     mStateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	Line 67:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 67:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 67:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 69:     mStateSet->setAttributeAndModes(depth, osg::StateAttribute::ON);
	Line 70:     mStateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 71:     mStateSet->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 71:     mStateSet->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 73:     mWindDirUniform = new osg::Uniform("windDir", 0.f);
	Line 74:     mWindSpeedUniform = new osg::Uniform("windSpeed", 0.f);
	Line 75:     mTimeUniform = new osg::Uniform("time", 0.f);
	Line 88: void SmokeStacks::addStack(int vehicleId, osg::Vec3 stackPos, float scale)
	Line 90:     mStacksAdded[vehicleId].push_back(std::pair<osg::Vec3, float>(stackPos, scale));
	Line 94: void SmokeStacks::addToOSG(osg::Group* root)
	Line 102:     std::map<int, std::vector<std::pair<osg::Vec3, float> > >::iterator vIter = mStacksAdded.find(vehicleId);
	Line 153:             const std::vector<std::pair<osg::Vec3, float> >* stacks = &(add_iter->second);
  D:\Development\psim\src\subview\SmokeStacks.h (18 hits)
	Line 18: class SmokeStacks : public osg::Switch
	Line 25:     SmokeStacks(const SmokeStacks& stacks, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 25:     SmokeStacks(const SmokeStacks& stacks, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 26:     osg::Switch(stacks, copyop)
	Line 31:     void addStack(int vehicleId, osg::Vec3 stackPos, float scale);
	Line 32:     void addToOSG(osg::Group* root);
	Line 44:     std::map<int, std::vector<std::pair<osg::Vec3, float> > > mStacksAdded;
	Line 47:     typedef std::map<int, std::vector<std::pair<osg::Vec3, float> > >::const_iterator add_stack_iter;
	Line 49:     osg::ref_ptr<osg::Uniform> mWindDirUniform;
	Line 49:     osg::ref_ptr<osg::Uniform> mWindDirUniform;
	Line 50:     osg::ref_ptr<osg::Uniform> mWindSpeedUniform;
	Line 50:     osg::ref_ptr<osg::Uniform> mWindSpeedUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> mTimeUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> mTimeUniform;
	Line 53:     osg::ref_ptr<osg::Texture2D> mTexture;
	Line 53:     osg::ref_ptr<osg::Texture2D> mTexture;
	Line 54:     osg::ref_ptr<osg::StateSet> mStateSet;
	Line 54:     osg::ref_ptr<osg::StateSet> mStateSet;
  D:\Development\psim\src\subview\SmokeStacksUpdate.cpp (2 hits)
	Line 24: void SmokeStacksUpdate::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 24: void SmokeStacksUpdate::operator()(osg::Node* node, osg::NodeVisitor* nv)
  D:\Development\psim\src\subview\SmokeStacksUpdate.h (3 hits)
	Line 15: class SmokeStacksUpdate : public osg::NodeCallback
	Line 23:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 23:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
  D:\Development\psim\src\subview\SmokeTrails.cpp (88 hits)
	Line 51: SmokeTrails::SmokeTrails(const SmokeTrails& trails, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 51: SmokeTrails::SmokeTrails(const SmokeTrails& trails, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 52: osg::Group(trails, copyop)
	Line 60: mState(new osg::State),
	Line 61: mDepthImage(new osg::Image)
	Line 71:     mStateSet = new osg::StateSet;
	Line 75:     osg::ref_ptr<osg::Image> img;
	Line 75:     osg::ref_ptr<osg::Image> img;
	Line 77:     mTexture = new osg::Texture2D;
	Line 79:     mTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 79:     mTexture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 80:     mTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 80:     mTexture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 81:     mTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 81:     mTexture->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 82:     mTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 82:     mTexture->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 85:     mStateSet->setTextureAttributeAndModes(0, mTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 85:     mStateSet->setTextureAttributeAndModes(0, mTexture, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 86:     mStateSet->addUniform(new osg::Uniform("smoke", 0));
	Line 89:     mDepthTex = new osg::Texture2D;
	Line 92:     mDepthTex->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 92:     mDepthTex->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 93:     mDepthTex->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 93:     mDepthTex->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 94:     mDepthTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 94:     mDepthTex->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 95:     mDepthTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 95:     mDepthTex->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 96:     mStateSet->setTextureAttributeAndModes(1, mDepthTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 96:     mStateSet->setTextureAttributeAndModes(1, mDepthTex, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 97:     mStateSet->addUniform(new osg::Uniform("depth", 1));
	Line 100:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 100:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 100:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 102:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "smokeTrailPuffVert.glsl"));
	Line 103:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "smokeTrailPuffFrag.glsl"));
	Line 106:     mStateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 106:     mStateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 108:     mStateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	Line 110:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 110:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 110:     osg::ref_ptr<osg::Depth> depth = new osg::Depth;
	Line 112:     mStateSet->setAttributeAndModes(depth, osg::StateAttribute::ON);
	Line 113:     mStateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 114:     mStateSet->setMode(GL_CULL_FACE, osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF);
	Line 114:     mStateSet->setMode(GL_CULL_FACE, osg::StateAttribute::PROTECTED | osg::StateAttribute::OFF);
	Line 115:     //mStateSet->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 115:     //mStateSet->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 118:     osg::ref_ptr<osg::BlendFunc> blend = new osg::BlendFunc;
	Line 118:     osg::ref_ptr<osg::BlendFunc> blend = new osg::BlendFunc;
	Line 118:     osg::ref_ptr<osg::BlendFunc> blend = new osg::BlendFunc;
	Line 119:     blend->setFunction(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA);
	Line 119:     blend->setFunction(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA);
	Line 120:     mStateSet->setAttributeAndModes(blend, osg::StateAttribute::ON);
	Line 121:     mViewMatInvUniform = new osg::Uniform("viewMatInv", osg::Matrixf::identity());
	Line 121:     mViewMatInvUniform = new osg::Uniform("viewMatInv", osg::Matrixf::identity());
	Line 122:     mWindDirUniform = new osg::Uniform("windDir", 0.f);
	Line 123:     mWindSpeedUniform = new osg::Uniform("windSpeed", 0.f);
	Line 124:     mTimeUniform = new osg::Uniform("time", 0.f);
	Line 125:     mLightCoeffUniform = new osg::Uniform("lightCoeff", 1.0f);
	Line 126:     mInvScreenWidthHeightUniform = new osg::Uniform("invScreenWidthHeight", osg::Vec2(1.f / SubviewConfig::winWidth, 1.f / SubviewConfig::winHeight));
	Line 126:     mInvScreenWidthHeightUniform = new osg::Uniform("invScreenWidthHeight", osg::Vec2(1.f / SubviewConfig::winWidth, 1.f / SubviewConfig::winHeight));
	Line 127:     mEyeAboveUniform = new osg::Uniform("eyeAbove", false);
	Line 163: void SmokeTrails::addToOSG(osg::Group* root)
	Line 231:                 osg::ref_ptr<SmokeTrailsPuff> puff = new SmokeTrailsPuff(mLastUpdateSeq, life_time_seq, current_time_offset, life_time, *info);
	Line 233:                 osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 233:                 osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 233:                 osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 237:                 osg::ref_ptr<osg::MatrixTransform> matrixXform = new osg::MatrixTransform();
	Line 237:                 osg::ref_ptr<osg::MatrixTransform> matrixXform = new osg::MatrixTransform();
	Line 237:                 osg::ref_ptr<osg::MatrixTransform> matrixXform = new osg::MatrixTransform();
	Line 239:                 osg::Matrixd mat_pos;
	Line 255:                             osg::Vec3f position = puff->getPosition();
	Line 259:                             osg::ref_ptr<osg::Geode> newgeode = new osg::Geode();
	Line 259:                             osg::ref_ptr<osg::Geode> newgeode = new osg::Geode();
	Line 259:                             osg::ref_ptr<osg::Geode> newgeode = new osg::Geode();
	Line 262:                             osg::ref_ptr<osg::MatrixTransform> offsetXform = new osg::MatrixTransform();
	Line 262:                             osg::ref_ptr<osg::MatrixTransform> offsetXform = new osg::MatrixTransform();
	Line 262:                             osg::ref_ptr<osg::MatrixTransform> offsetXform = new osg::MatrixTransform();
	Line 263:                             osg::Matrixd mat_pos;
	Line 283:             osg::Transform* xform = this->getChild(child)->asTransform();
	Line 289:             osg::MatrixTransform* matrixXform = xform->asMatrixTransform();
	Line 295:             osg::Geode* geode = xform->getChild(0)->asGeode();
	Line 316:                     osg::Matrixd mat_pos;
	Line 317:                     osg::Vec3f pos = puff->getPosition();
	Line 319:                     pos += osg::Vec3f(Shared->glEnv.windSpd * dt*cosdir, Shared->glEnv.windSpd * dt*sindir, 0.0);
	Line 338:     mInvScreenWidthHeightUniform->set(osg::Vec2(1.f / SubviewConfig::winWidth, 1.f / SubviewConfig::winHeight));
  D:\Development\psim\src\subview\SmokeTrails.h (28 hits)
	Line 20: class SmokeTrails : public osg::Group
	Line 26:     SmokeTrails(const SmokeTrails& trails, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 26:     SmokeTrails(const SmokeTrails& trails, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 30:     void addToOSG(osg::Group* root);
	Line 37:     osg::ref_ptr<osg::StateSet> mStateSet;
	Line 37:     osg::ref_ptr<osg::StateSet> mStateSet;
	Line 38:     osg::ref_ptr<osg::State> mState;
	Line 38:     osg::ref_ptr<osg::State> mState;
	Line 39:     osg::ref_ptr<osg::Image> mDepthImage;
	Line 39:     osg::ref_ptr<osg::Image> mDepthImage;
	Line 41:     osg::ref_ptr<osg::Texture2D> mTexture;
	Line 41:     osg::ref_ptr<osg::Texture2D> mTexture;
	Line 42:     osg::ref_ptr<osg::Uniform> mViewMatInvUniform;
	Line 42:     osg::ref_ptr<osg::Uniform> mViewMatInvUniform;
	Line 43:     osg::ref_ptr<osg::Uniform> mWindDirUniform;
	Line 43:     osg::ref_ptr<osg::Uniform> mWindDirUniform;
	Line 44:     osg::ref_ptr<osg::Uniform> mWindSpeedUniform;
	Line 44:     osg::ref_ptr<osg::Uniform> mWindSpeedUniform;
	Line 45:     osg::ref_ptr<osg::Uniform> mTimeUniform;
	Line 45:     osg::ref_ptr<osg::Uniform> mTimeUniform;
	Line 46:     osg::ref_ptr<osg::Uniform> mLightCoeffUniform;
	Line 46:     osg::ref_ptr<osg::Uniform> mLightCoeffUniform;
	Line 47:     osg::ref_ptr<osg::Uniform> mInvScreenWidthHeightUniform;
	Line 47:     osg::ref_ptr<osg::Uniform> mInvScreenWidthHeightUniform;
	Line 48:     osg::ref_ptr<osg::Texture2D> mDepthTex;
	Line 48:     osg::ref_ptr<osg::Texture2D> mDepthTex;
	Line 49:     osg::ref_ptr<osg::Uniform> mEyeAboveUniform;
	Line 49:     osg::ref_ptr<osg::Uniform> mEyeAboveUniform;
  D:\Development\psim\src\subview\SmokeTrailsPuff.cpp (31 hits)
	Line 26: SmokeTrailsPuff::SmokeTrailsPuff(const SmokeTrailsPuff& puff, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 26: SmokeTrailsPuff::SmokeTrailsPuff(const SmokeTrailsPuff& puff, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 27: osg::Geometry(puff, copyop)
	Line 59:     std::vector< osg::Vec4f > vertices;
	Line 60:     std::vector< osg::Vec4f > tex_coords;
	Line 61:     std::vector< osg::Vec4f > bb_coords;
	Line 71:         vertices.push_back(osg::Vec4f(0.0, 0.0, 0.0, birthSeq));
	Line 75:         tex_coords.push_back(osg::Vec4f(uu, vv, startTime, lifeTime));
	Line 76:         bb_coords.push_back(osg::Vec4f(local_verts[ii][0], local_verts[ii][1], 0.0, info.mSmokeScale));
	Line 81:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 81:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 81:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 81:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 84:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 84:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 84:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 84:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 87:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 87:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 87:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 87:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 90:     osg::Geometry::PrimitiveSetList prim_list;
	Line 91:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 91:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 91:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 91:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 101: osg::BoundingBox SmokeTrailsPuff::computeBound() const
	Line 106:     osg::BoundingBox bbox(-nominal, -nominal, -nominal, nominal, nominal, nominal);
	Line 121: osg::Vec3f SmokeTrailsPuff::getPosition() const
	Line 125:     osg::Vec3f position;
	Line 132: void SmokeTrailsPuff::setPosition(osg::Vec3f newPosition)
  D:\Development\psim\src\subview\SmokeTrailsPuff.h (7 hits)
	Line 18: class SmokeTrailsPuff : public osg::Geometry
	Line 24:     SmokeTrailsPuff(const SmokeTrailsPuff& puff, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 24:     SmokeTrailsPuff(const SmokeTrailsPuff& puff, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 28:     virtual osg::BoundingBox computeBound() const;
	Line 31:     osg::Vec3f getPosition() const;
	Line 32:     void setPosition(osg::Vec3f);
	Line 45:     osg::Vec3f mSmokeOffset;
  D:\Development\psim\src\subview\SmokeTrailsUpdate.cpp (2 hits)
	Line 24: void SmokeTrailsUpdate::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 24: void SmokeTrailsUpdate::operator()(osg::Node* node, osg::NodeVisitor* nv)
  D:\Development\psim\src\subview\SmokeTrailsUpdate.h (3 hits)
	Line 16: class SmokeTrailsUpdate : public osg::NodeCallback
	Line 24:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 24:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
  D:\Development\psim\src\subview\Snapshot.cpp (5 hits)
	Line 132: void Snapshot::takeSnapshot(osg::Image* targetImage, unsigned int xorg, unsigned int yorg, unsigned int width, unsigned int height)
	Line 142:     osg::ref_ptr<osg::Image> image;
	Line 142:     osg::ref_ptr<osg::Image> image;
	Line 143:     image = new osg::Image;
	Line 151: void Snapshot::takeSnapshot(const osg::Camera& camera, SnapshotType snapshotType)
  D:\Development\psim\src\subview\Snapshot.h (2 hits)
	Line 16:     static void takeSnapshot(osg::Image* targetImage, unsigned int xorg, unsigned int yorg, unsigned int width, unsigned int height);
	Line 17:     static void takeSnapshot(const osg::Camera &camera, SnapshotType snapshotType);
  D:\Development\psim\src\subview\SoundingAlertDB.cpp (5 hits)
	Line 20: SoundingAlertDB::SoundingAlertDB(Vehicle* vehicle, osg::Geode *node) :
	Line 21: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 22: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 27: void SoundingAlertDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 27: void SoundingAlertDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\SoundingAlertDB.h (3 hits)
	Line 21:     SoundingAlertDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\SoundingDB.cpp (5 hits)
	Line 24: SoundingDB::SoundingDB(Vehicle* vehicle, osg::Geode *node) :
	Line 25: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 26: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 31: void SoundingDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 31: void SoundingDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\SoundingDB.h (3 hits)
	Line 21:     SoundingDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\SpeedDB.cpp (5 hits)
	Line 21: SpeedDB::SpeedDB(Vehicle* vehicle, osg::Geode *node) :
	Line 22: TextBox(node, "msttcore/consola.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f)),
	Line 23: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 28: void SpeedDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 28: void SpeedDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\SpeedDB.h (3 hits)
	Line 21:     SpeedDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\StackSmoke.cpp (8 hits)
	Line 25: StackSmoke::StackSmoke(int vehicleId, const std::vector<std::pair<osg::Vec3, float> >* stacks) :
	Line 31:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 31:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 31:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 40:     mHeadingUniform = new osg::Uniform("heading", 0.f);
	Line 41:     mSpeedUniform = new osg::Uniform("speed", 0.f);
	Line 68:     osg::Matrixd mat_pos;
	Line 75:         osg::Vec3f contactLoc = vehicle->getContactLoc();
  D:\Development\psim\src\subview\StackSmoke.h (12 hits)
	Line 23: class StackSmoke : public osg::MatrixTransform
	Line 26:     StackSmoke(int vehicleId, const std::vector<std::pair<osg::Vec3, float> >* stacks);
	Line 33:     StackSmoke(const StackSmoke& fire, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 33:     StackSmoke(const StackSmoke& fire, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 34:     osg::MatrixTransform(fire, copyop)
	Line 46:     osg::ref_ptr<StackSmokeGeometry> mGeometry;
	Line 48:     osg::ref_ptr<osg::StateSet> mStateSet;
	Line 48:     osg::ref_ptr<osg::StateSet> mStateSet;
	Line 50:     osg::ref_ptr<osg::Uniform> mHeadingUniform;
	Line 50:     osg::ref_ptr<osg::Uniform> mHeadingUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> mSpeedUniform;
	Line 51:     osg::ref_ptr<osg::Uniform> mSpeedUniform;
  D:\Development\psim\src\subview\StackSmokeGeometry.cpp (27 hits)
	Line 27: StackSmokeGeometry::StackSmokeGeometry(int vehicleId, const std::vector<std::pair<osg::Vec3, float> >* stacks)
	Line 45:     std::vector< osg::Vec4f > vertices;
	Line 46:     std::vector< osg::Vec4f > tex_coords;
	Line 47:     std::vector< osg::Vec4f > bb_coords;
	Line 64:                 osg::Vec3f xyz = (*stacks)[ii].first;
	Line 65:                 vertices.push_back(osg::Vec4f(xyz, height_frac)); // (float)vehicle_id));
	Line 69:                 tex_coords.push_back(osg::Vec4f(uu, vv, dx, dy));
	Line 70:                 bb_coords.push_back(osg::Vec4f(local_verts[jj][0], local_verts[jj][1],
	Line 79:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 79:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 79:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 79:     osg::ref_ptr<osg::Vec4Array> vertices_array = new osg::Vec4Array(vertices.size(), (osg::Vec4f*) &(vertices.front()));
	Line 82:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 82:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 82:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 82:     osg::ref_ptr<osg::Vec4Array> tex_coords_array = new osg::Vec4Array(tex_coords.size(), (osg::Vec4f*)&(tex_coords.front()));
	Line 85:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 85:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 85:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 85:     osg::ref_ptr<osg::Vec4Array> bb_coords_array = new osg::Vec4Array(bb_coords.size(), (osg::Vec4f*)&(bb_coords.front()));
	Line 88:     osg::Geometry::PrimitiveSetList prim_list;
	Line 89:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 89:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 89:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 89:     osg::ref_ptr<osg::DrawElementsUInt> de_quads = new osg::DrawElementsUInt(osg::PrimitiveSet::QUADS, indices.size(),
	Line 99: osg::BoundingBox StackSmokeGeometry::computeBound() const
	Line 103:     osg::BoundingBox bbox(-nominal, -nominal, -nominal, nominal, nominal, nominal);
  D:\Development\psim\src\subview\StackSmokeGeometry.h (7 hits)
	Line 21: class StackSmokeGeometry : public osg::Geometry
	Line 24:     StackSmokeGeometry(int vehicleId, const std::vector<std::pair<osg::Vec3, float> >* stacks);
	Line 27:     StackSmokeGeometry(const StackSmokeGeometry& smoke, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 27:     StackSmokeGeometry(const StackSmokeGeometry& smoke, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 28:     osg::Geometry(smoke, copyop)
	Line 37:     virtual osg::BoundingBox computeBound() const;
	Line 46:     std::vector<std::pair<osg::Vec3, float> > mStacks;
  D:\Development\psim\src\subview\Stadimeter.cpp (42 hits)
	Line 31: Stadimeter::Stadimeter(const Stadimeter& Stadimeter, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 31: Stadimeter::Stadimeter(const Stadimeter& Stadimeter, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 32: osg::Geometry(Stadimeter, copyop)
	Line 40: Stadimeter::Stadimeter(osg::Group *root)
	Line 42:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0));
	Line 42:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-10.0, 10.0, -10.0, 10.0, -1.0, 1.0));
	Line 43:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 43:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 47:     textureRect = new osg::TextureRectangle;
	Line 50:     textureRect->setFilter(osg::TextureRectangle::MIN_FILTER, osg::TextureRectangle::LINEAR);
	Line 50:     textureRect->setFilter(osg::TextureRectangle::MIN_FILTER, osg::TextureRectangle::LINEAR);
	Line 51:     textureRect->setFilter(osg::TextureRectangle::MAG_FILTER, osg::TextureRectangle::LINEAR);
	Line 51:     textureRect->setFilter(osg::TextureRectangle::MAG_FILTER, osg::TextureRectangle::LINEAR);
	Line 53:     stateSet = new osg::StateSet;
	Line 54:     stateSet->setTextureAttributeAndModes(0, textureRect, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 54:     stateSet->setTextureAttributeAndModes(0, textureRect, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 57:     stateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	Line 60:     osg::Geode* geode = new osg::Geode();
	Line 60:     osg::Geode* geode = new osg::Geode();
	Line 63:     quadSwitch = new osg::Switch;
	Line 69:     stateSet->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	Line 70:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 71:     stateSet->setMode(GL_BLEND, osg::StateAttribute::ON);
	Line 73:     stateSet->setTextureAttributeAndModes(0, textureRect, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 73:     stateSet->setTextureAttributeAndModes(0, textureRect, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 74:     stateSet->addUniform(new osg::Uniform("texture", 0));
	Line 75:     stadiAdjustUniform = new osg::Uniform("stadiAdjust", 0.f);
	Line 90:     osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 90:     osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 90:     osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 90:     osg::ref_ptr<osg::Shader> fshader = new osg::Shader(osg::Shader::FRAGMENT, shaderSource);
	Line 91:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 91:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 91:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 93:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 93:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 102: void Stadimeter::drawImplementation(osg::RenderInfo& ri) const
	Line 108:     osg::Texture::TextureObject* textureObject = textureRect->getTextureObject(0);
	Line 181: osg::BoundingBox Stadimeter::computeBound() const
	Line 183:     osg::BoundingBox bbox;
	Line 184:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 185:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
  D:\Development\psim\src\subview\Stadimeter.h (17 hits)
	Line 18: class Stadimeter : public osg::Geometry
	Line 25:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 25:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 26:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 26:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 27:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 27:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 29:     osg::TextureRectangle *textureRect;
	Line 30:     osg::ref_ptr<osg::Switch> quadSwitch;
	Line 30:     osg::ref_ptr<osg::Switch> quadSwitch;
	Line 31:     osg::ref_ptr<osg::Uniform> stadiAdjustUniform;
	Line 31:     osg::ref_ptr<osg::Uniform> stadiAdjustUniform;
	Line 36:     Stadimeter(const Stadimeter& Stadimeter, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 36:     Stadimeter(const Stadimeter& Stadimeter, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 39:     Stadimeter(osg::Group *root);
	Line 40:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 41:     virtual osg::BoundingBox computeBound() const;
  D:\Development\psim\src\subview\Starfield.cpp (46 hits)
	Line 38:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 38:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 38:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 39:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	Line 39:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	Line 39:     osg::ref_ptr<osg::Vec4Array> colors = new osg::Vec4Array;
	Line 43:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 43:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 43:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 46:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, vertices->size()));
	Line 46:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::POINTS, 0, vertices->size()));
	Line 48:     geometry->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	Line 51:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 51:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 51:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 52:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 52:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 53:     stateset->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 53:     stateset->setMode(GL_LIGHTING, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 55:     stateset->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 56:     osg::ref_ptr<osg::Point> point = new osg::Point(pointSize);
	Line 56:     osg::ref_ptr<osg::Point> point = new osg::Point(pointSize);
	Line 56:     osg::ref_ptr<osg::Point> point = new osg::Point(pointSize);
	Line 61:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 61:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 61:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 62:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "starFrag.glsl"));
	Line 63:     stateset->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 63:     stateset->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 66:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 66:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 66:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 71:     mTransformPtr = new osg::MatrixTransform;
	Line 74:     mTransformPtr->setMatrix(osg::Matrix::scale(STARS_SCALE, STARS_SCALE, STARS_SCALE));
	Line 81: osg::Group* Starfield::GetNode()
	Line 92:             osg::Matrix::rotate(osg::inDegrees(dailyRotation), 0.0f, 0.0f, 1.0f) *
	Line 92:             osg::Matrix::rotate(osg::inDegrees(dailyRotation), 0.0f, 0.0f, 1.0f) *
	Line 93:             osg::Matrix::rotate(osg::inDegrees(STARS_HEADING_OFFSET - lon), 0.0f, 0.0f, 1.0f) *
	Line 93:             osg::Matrix::rotate(osg::inDegrees(STARS_HEADING_OFFSET - lon), 0.0f, 0.0f, 1.0f) *
	Line 94:             osg::Matrix::rotate(osg::inDegrees(STARS_PITCH_OFFSET + lat), 1.0f, 0.0f, 0.0f) *
	Line 94:             osg::Matrix::rotate(osg::inDegrees(STARS_PITCH_OFFSET + lat), 1.0f, 0.0f, 0.0f) *
	Line 95:             osg::Matrix::scale(STARS_SCALE, STARS_SCALE, STARS_SCALE));
	Line 98: void Starfield::ReadStarFile(osg::Vec3Array *verticesPtr, osg::Vec4Array *colorsPtr)
	Line 98: void Starfield::ReadStarFile(osg::Vec3Array *verticesPtr, osg::Vec4Array *colorsPtr)
	Line 121:             verticesPtr->push_back(osg::Vec3(xPos, yPos, zPos));
	Line 122:             colorsPtr->push_back(osg::Vec4(intensity, intensity, intensity, std::min(2.0f*intensity, 1.0f)));
  D:\Development\psim\src\subview\Starfield.h (5 hits)
	Line 18:         osg::Group* GetNode();
	Line 23:         void ReadStarFile(osg::Vec3Array *verticesPtr, osg::Vec4Array *colorsPtr);
	Line 23:         void ReadStarFile(osg::Vec3Array *verticesPtr, osg::Vec4Array *colorsPtr);
	Line 25:         osg::ref_ptr<osg::MatrixTransform> mTransformPtr;
	Line 25:         osg::ref_ptr<osg::MatrixTransform> mTransformPtr;
  D:\Development\psim\src\subview\StateSetUpdater.cpp (12 hits)
	Line 16: StateSetUpdater::StateSetUpdater(const StateSetUpdater &copy, const osg::CopyOp &copyop)
	Line 17: : osg::NodeCallback(copy, copyop)
	Line 21: void StateSetUpdater::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 21: void StateSetUpdater::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 26:         osg::StateSet* src = node->getOrCreateStateSet();
	Line 30:             mStateSets[i] = static_cast<osg::StateSet*> (osg::clone(src, osg::CopyOp::SHALLOW_COPY));
	Line 30:             mStateSets[i] = static_cast<osg::StateSet*> (osg::clone(src, osg::CopyOp::SHALLOW_COPY));
	Line 30:             mStateSets[i] = static_cast<osg::StateSet*> (osg::clone(src, osg::CopyOp::SHALLOW_COPY));
	Line 34:             mStateSets[i]->setDataVariance(osg::Object::DYNAMIC);
	Line 55: void StateSetUpdater::apply(osg::StateSet* stateset, osg::NodeVisitor* nv)
	Line 55: void StateSetUpdater::apply(osg::StateSet* stateset, osg::NodeVisitor* nv)
	Line 59: void StateSetUpdater::setDefaults(osg::StateSet* stateset)
  D:\Development\psim\src\subview\StateSetUpdater.h (9 hits)
	Line 10: class StateSetUpdater : public osg::NodeCallback
	Line 14:     StateSetUpdater(const StateSetUpdater& copy, const osg::CopyOp& copyop);
	Line 16:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 16:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 18:     virtual void apply(osg::StateSet* stateset, osg::NodeVisitor* nv);
	Line 18:     virtual void apply(osg::StateSet* stateset, osg::NodeVisitor* nv);
	Line 20:     virtual void setDefaults(osg::StateSet* stateset);
	Line 26:     osg::ref_ptr<osg::StateSet> mStateSets[2];
	Line 26:     osg::ref_ptr<osg::StateSet> mStateSets[2];
  D:\Development\psim\src\subview\SternLightCallback.cpp (9 hits)
	Line 19: SternLightCallback::SternLightCallback(Vehicle *vehicle, osg::Vec3f position) :
	Line 26: void SternLightCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 26: void SternLightCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 28:     osg::Geode* sternLightGeode = dynamic_cast<osg::Geode*> (node); // dynamic cast will return null if node isn't a geode
	Line 28:     osg::Geode* sternLightGeode = dynamic_cast<osg::Geode*> (node); // dynamic cast will return null if node isn't a geode
	Line 34:             osg::Vec3 localDir(-1., 0., 0.);
	Line 35:             mVehicle->setSternLightPos(osg::computeLocalToWorld(nv->getNodePath()).preMult(mLocalPos));
	Line 36:             mVehicle->setSternLightDir(osg::Matrix::rotate(osg::DegreesToRadians(mVehicle->getHeading()), 0.f, 0.f, 1.f).preMult(localDir));
	Line 36:             mVehicle->setSternLightDir(osg::Matrix::rotate(osg::DegreesToRadians(mVehicle->getHeading()), 0.f, 0.f, 1.f).preMult(localDir));
  D:\Development\psim\src\subview\SternLightCallback.h (5 hits)
	Line 17: class SternLightCallback : public osg::NodeCallback
	Line 20:     SternLightCallback(Vehicle *vehicle, osg::Vec3f position);
	Line 21:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	Line 21:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	Line 25:     osg::Vec3f mLocalPos;
  D:\Development\psim\src\subview\Sub.cpp (1 hit)
	Line 55:         Shared->scopePivotOffset = osg::Vec3(0.f, 0.f, 0.f);
  D:\Development\psim\src\subview\SubHud.cpp (2 hits)
	Line 30: void SubHud::drawImplementation(osg::RenderInfo& ri) const
	Line 36: void SubHud::draw(osg::RenderInfo& ri)
  D:\Development\psim\src\subview\SubHud.h (2 hits)
	Line 14:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 17:     void draw(osg::RenderInfo& ri);
  D:\Development\psim\src\subview\SubTelemeter.cpp (16 hits)
	Line 156: void SubTelemeter::drawImplementation(osg::RenderInfo& ri) const
	Line 248:     stateSet = new osg::StateSet;
	Line 250:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 250:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 253:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 253:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 253:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 255:     textureEnabledUniform = new osg::Uniform("textureEnabled", 0.0f);
	Line 256:     redUniform = new osg::Uniform("red", 0.0f);
	Line 257:     greenUniform = new osg::Uniform("green", 0.0f);
	Line 258:     blueUniform = new osg::Uniform("blue", 0.0f);
	Line 259:     alphaUniform = new osg::Uniform("alpha", 1.0f);
	Line 267:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "overlayFrag.glsl"));
	Line 273:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 273:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 276:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
  D:\Development\psim\src\subview\SubTelemeter.h (1 hit)
	Line 25:     virtual void drawImplementation(osg::RenderInfo& ri) const;
  D:\Development\psim\src\subview\subview.cpp (5 hits)
	Line 66: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 66: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 318:     Shared->overlayBoarder = osg::Vec2();
	Line 339:     SubviewConfig::orientationOffset = osg::Vec3(0.0, 0.0, 0.0);
	Line 340:     SubviewConfig::viewOffset = osg::Vec3(0.0, 0.0, 0.0);
  D:\Development\psim\src\subview\SubviewConfig.cpp (4 hits)
	Line 33: osg::Vec3 SubviewConfig::orientationOffset = osg::Vec3(0.0, 0.0, 0.0);
	Line 33: osg::Vec3 SubviewConfig::orientationOffset = osg::Vec3(0.0, 0.0, 0.0);
	Line 34: osg::Vec3 SubviewConfig::viewOffset = osg::Vec3(0.0, 0.0, 0.0);
	Line 34: osg::Vec3 SubviewConfig::viewOffset = osg::Vec3(0.0, 0.0, 0.0);
  D:\Development\psim\src\subview\SubviewConfig.h (4 hits)
	Line 39:     static osg::Vec3 orientationOffset; // = osg::Vec3(0.0, 0.0, 0.0);
	Line 39:     static osg::Vec3 orientationOffset; // = osg::Vec3(0.0, 0.0, 0.0);
	Line 40:     static osg::Vec3 viewOffset; // = osg::Vec3(0.0, 0.0, 0.0);
	Line 40:     static osg::Vec3 viewOffset; // = osg::Vec3(0.0, 0.0, 0.0);
  D:\Development\psim\src\subview\SubviewSwapCallback.cpp (16 hits)
	Line 30: extern osg::ref_ptr<PsimCameraManipulator> cameraManipulator;
	Line 39: osg::GraphicsContext::SwapCallback(),
	Line 50: void SubviewSwapCallback::enableSecondaryWrite(std::string key, int width, int height, osg::Image* image, osg::Texture* tex)
	Line 50: void SubviewSwapCallback::enableSecondaryWrite(std::string key, int width, int height, osg::Image* image, osg::Texture* tex)
	Line 63: void SubviewSwapCallback::swapBuffersImplementation(osg::GraphicsContext *gc)
	Line 137:                 osg::Quat ScalableQuat(osg::inDegrees(Frustum.ViewAngleC + 90.0), osg::Vec3(-1., -0., 0.),
	Line 137:                 osg::Quat ScalableQuat(osg::inDegrees(Frustum.ViewAngleC + 90.0), osg::Vec3(-1., -0., 0.),
	Line 137:                 osg::Quat ScalableQuat(osg::inDegrees(Frustum.ViewAngleC + 90.0), osg::Vec3(-1., -0., 0.),
	Line 138:                         osg::inDegrees(Frustum.ViewAngleB), osg::Vec3(0., 0., 1.),
	Line 138:                         osg::inDegrees(Frustum.ViewAngleB), osg::Vec3(0., 0., 1.),
	Line 139:                         osg::inDegrees(Frustum.ViewAngleA), osg::Vec3(0., 1., 0.));
	Line 139:                         osg::inDegrees(Frustum.ViewAngleA), osg::Vec3(0., 1., 0.));
	Line 143:                 _cameraManipulator->setFrustum(osg::RadiansToDegrees(res[0]), osg::RadiansToDegrees(res[1]), osg::RadiansToDegrees(res[2]),
	Line 143:                 _cameraManipulator->setFrustum(osg::RadiansToDegrees(res[0]), osg::RadiansToDegrees(res[1]), osg::RadiansToDegrees(res[2]),
	Line 143:                 _cameraManipulator->setFrustum(osg::RadiansToDegrees(res[0]), osg::RadiansToDegrees(res[1]), osg::RadiansToDegrees(res[2]),
	Line 185: void SubviewSwapCallback::quatToEuler(const osg::Quat& q, double res[], RotSeq rotSeq)
  D:\Development\psim\src\subview\SubviewSwapCallback.h (5 hits)
	Line 19: class SubviewSwapCallback : public osg::GraphicsContext::SwapCallback
	Line 27:     void enableSecondaryWrite(std::string key, int width, int height, osg::Image* image, osg::Texture* tex);
	Line 27:     void enableSecondaryWrite(std::string key, int width, int height, osg::Image* image, osg::Texture* tex);
	Line 30:     virtual void swapBuffersImplementation(osg::GraphicsContext* gc);
	Line 55:     void quatToEuler(const osg::Quat& q, double res[], RotSeq rotSeq);
  D:\Development\psim\src\subview\SubviewUtils.cpp (98 hits)
	Line 154: osg::Vec3f SubviewUtils::GetOceanColor(VisualEffectEnum visualEffect)
	Line 156:     osg::Vec3f color;
	Line 180: void SubviewUtils::SetVisualEffectState(osg::StateSet *stateSet, VisualEffectEnum& visualEffect)
	Line 182:     addDynamicUniform(stateSet, "irMode", osg::Uniform::BOOL, (visualEffect == VISUAL_IR || visualEffect == VISUAL_IR_NOISE),
	Line 188:     addDynamicUniform(stateSet, "lightEnhancement", osg::Uniform::BOOL, visualEffect == VISUAL_NVG || visualEffect == VISUAL_LLL,
	Line 194:     addDynamicUniform(stateSet, "baseOceanColor", osg::Uniform::FLOAT_VEC3, SubviewUtils::GetOceanColor(visualEffect),
	Line 200:     addDynamicUniform(stateSet, "fogColor", osg::Uniform::FLOAT_VEC4, CalcFogColor(visualEffect),
	Line 206:     addDynamicUniform(stateSet, "fogDelta", osg::Uniform::FLOAT, GetVisibilityRange(Shared->glEnv.visRange, Shared->eyeAbove, Shared->hud.scopeElev, visualEffect),
	Line 212:     addDynamicUniform(stateSet, "cloudFog", osg::Uniform::FLOAT, GetCloudFog(Shared->glEnv.precipType, Shared->glEnv.visRange, Shared->eyeAbove, Shared->hud.scopeElev, visualEffect),
	Line 219: osg::Vec4f SubviewUtils::CalcFogColor(VisualEffectEnum visualEffect)
	Line 221:     osg::Vec4f fogColor;
	Line 226:     osg::Vec4 baseColor;
	Line 235:         baseColor = osg::Vec4f(0.9f, 0.9f, 0.9f, 1.0f) * density;
	Line 236:         baseColor += osg::Vec4(sun_moon->GetBottomColor(), 1.0) * (1.0f - density);
	Line 362: osg::Vec4 SubviewUtils::ColorToGrayscale(osg::Vec4 color)
	Line 362: osg::Vec4 SubviewUtils::ColorToGrayscale(osg::Vec4 color)
	Line 366:     osg::Vec4 gray(grayscale, grayscale, grayscale, color[3]);
	Line 414: void SubviewUtils::AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset)
	Line 414: void SubviewUtils::AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset)
	Line 414: void SubviewUtils::AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset)
	Line 414: void SubviewUtils::AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset)
	Line 416:     vertices->push_back(osg::Vec3d(-1.0 + xOffset, 0.0, -1.0 + zOffset));
	Line 417:     texcoords->push_back(osg::Vec2(0.0, 0.0));
	Line 419:     vertices->push_back(osg::Vec3d(1.0 + xOffset, 0.0, -1.0 + zOffset));
	Line 420:     texcoords->push_back(osg::Vec2(1.0, 0.0));
	Line 422:     vertices->push_back(osg::Vec3d(1.0 + xOffset, 0.0, 1.0 + zOffset));
	Line 423:     texcoords->push_back(osg::Vec2(1.0, 1.0));
	Line 425:     vertices->push_back(osg::Vec3d(-1.0 + xOffset, 0.0, 1.0 + zOffset));
	Line 426:     texcoords->push_back(osg::Vec2(0.0, 1.0));
	Line 434: osg::Vec3 SubviewUtils::GetCelestialPosition(float azimuth, float elevation)
	Line 453:     return osg::Vec3(-X * xyscale, Y * xyscale, Z);
	Line 548: std::string& SubviewUtils::PrintVec3(std::string & str, const osg::Vec3 &v)
	Line 572: std::string& SubviewUtils::PrintQuat(std::string & str, const osg::Quat &v)
	Line 1276: osg::ref_ptr<osg::Texture2D> SubviewUtils::CreateTexture(const std::string &path, bool wrapS, bool wrapT, bool wrapR)
	Line 1276: osg::ref_ptr<osg::Texture2D> SubviewUtils::CreateTexture(const std::string &path, bool wrapS, bool wrapT, bool wrapR)
	Line 1282: osg::ref_ptr<osg::Texture2D> SubviewUtils::CreateTexture(char *path, bool wrapS, bool wrapT, bool wrapR)
	Line 1282: osg::ref_ptr<osg::Texture2D> SubviewUtils::CreateTexture(char *path, bool wrapS, bool wrapT, bool wrapR)
	Line 1284:     osg::ref_ptr<osg::Image> image;
	Line 1284:     osg::ref_ptr<osg::Image> image;
	Line 1291:     osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	Line 1291:     osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	Line 1291:     osg::ref_ptr<osg::Texture2D> texture = new osg::Texture2D;
	Line 1293:     texture.get()->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	Line 1293:     texture.get()->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_NEAREST);
	Line 1294:     texture.get()->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 1294:     texture.get()->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 1295:     texture.get()->setWrap(osg::Texture2D::WRAP_S, wrapS ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1295:     texture.get()->setWrap(osg::Texture2D::WRAP_S, wrapS ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1295:     texture.get()->setWrap(osg::Texture2D::WRAP_S, wrapS ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1296:     texture.get()->setWrap(osg::Texture2D::WRAP_T, wrapT ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1296:     texture.get()->setWrap(osg::Texture2D::WRAP_T, wrapT ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1296:     texture.get()->setWrap(osg::Texture2D::WRAP_T, wrapT ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1297:     texture.get()->setWrap(osg::Texture2D::WRAP_R, wrapR ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1297:     texture.get()->setWrap(osg::Texture2D::WRAP_R, wrapR ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1297:     texture.get()->setWrap(osg::Texture2D::WRAP_R, wrapR ? osg::Texture2D::REPEAT : osg::Texture2D::CLAMP);
	Line 1330: void SubviewUtils::PaintString(osg::ref_ptr<osg::Geode> geode, std::string number)
	Line 1330: void SubviewUtils::PaintString(osg::ref_ptr<osg::Geode> geode, std::string number)
	Line 1341:     osg::ref_ptr<osg::Geometry> baseDrawable = (osg::Geometry*)(geode->getDrawable(0));
	Line 1341:     osg::ref_ptr<osg::Geometry> baseDrawable = (osg::Geometry*)(geode->getDrawable(0));
	Line 1341:     osg::ref_ptr<osg::Geometry> baseDrawable = (osg::Geometry*)(geode->getDrawable(0));
	Line 1344:     osg::ref_ptr<osg::Vec3Array> coords = (osg::Vec3Array*)(baseDrawable->getVertexArray());
	Line 1344:     osg::ref_ptr<osg::Vec3Array> coords = (osg::Vec3Array*)(baseDrawable->getVertexArray());
	Line 1344:     osg::ref_ptr<osg::Vec3Array> coords = (osg::Vec3Array*)(baseDrawable->getVertexArray());
	Line 1347:     osg::ref_ptr<osg::StateSet> stateSet = baseDrawable->getStateSet();
	Line 1347:     osg::ref_ptr<osg::StateSet> stateSet = baseDrawable->getStateSet();
	Line 1353:     osg::Vec3 lowerLeft;
	Line 1354:     osg::Vec3 upperLeft;
	Line 1355:     osg::Vec3 upperRight;
	Line 1356:     osg::Vec3 lowerRight;
	Line 1357:     osg::ref_ptr<osg::Vec3Array> newCoords;
	Line 1357:     osg::ref_ptr<osg::Vec3Array> newCoords;
	Line 1358:     osg::ref_ptr<osg::Vec2Array> texcoords;
	Line 1358:     osg::ref_ptr<osg::Vec2Array> texcoords;
	Line 1359:     osg::ref_ptr<osg::Vec3Array> normals;
	Line 1359:     osg::ref_ptr<osg::Vec3Array> normals;
	Line 1361:     newCoords = new osg::Vec3Array;
	Line 1362:     texcoords = new osg::Vec2Array;
	Line 1363:     normals = new osg::Vec3Array;
	Line 1373:         osg::Vec3 stride = (upperLeft - upperRight) / float(numChars);
	Line 1376:         osg::Vec3 normal = (upperLeft - upperRight)^(lowerLeft - upperRight);
	Line 1389:         osg::Vec4 ret;
	Line 1401:             texcoords->push_back(osg::Vec2(ret[2], ret[3]));
	Line 1402:             texcoords->push_back(osg::Vec2(ret[0], ret[3]));
	Line 1403:             texcoords->push_back(osg::Vec2(ret[0], ret[1]));
	Line 1404:             texcoords->push_back(osg::Vec2(ret[2], ret[1]));
	Line 1415:     osg::ref_ptr<osg::DrawArrays> primitive = new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, newCoords->size());
	Line 1415:     osg::ref_ptr<osg::DrawArrays> primitive = new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, newCoords->size());
	Line 1415:     osg::ref_ptr<osg::DrawArrays> primitive = new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, newCoords->size());
	Line 1415:     osg::ref_ptr<osg::DrawArrays> primitive = new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, newCoords->size());
	Line 1418:     osg::ref_ptr<osg::Geometry> newFace = new osg::Geometry();
	Line 1418:     osg::ref_ptr<osg::Geometry> newFace = new osg::Geometry();
	Line 1418:     osg::ref_ptr<osg::Geometry> newFace = new osg::Geometry();
	Line 1422:     newFace->setNormalBinding(osg::Geometry::BIND_PER_VERTEX);
	Line 1432: osg::Vec4 SubviewUtils::GetShipLettersTexCoords(char letter)
	Line 1437:     osg::Vec4 ret;
	Line 1441:         ret = osg::Vec4((51.2 * (asciival - 48)) / width,
	Line 1449:         ret = osg::Vec4((float(letter % 10) * 51.2) / width,
	Line 1458:         ret = osg::Vec4(0.0, 0.0, 0.0, 0.0);
  D:\Development\psim\src\subview\SubviewUtils.h (19 hits)
	Line 35:     static osg::Vec4f CalcFogColor(VisualEffectEnum visualEffect);
	Line 38:     static osg::ref_ptr<osg::Texture2D> CreateTexture(char *path, bool wrapS = false, bool wrapT = false, bool wrapR = false);
	Line 38:     static osg::ref_ptr<osg::Texture2D> CreateTexture(char *path, bool wrapS = false, bool wrapT = false, bool wrapR = false);
	Line 39:     static osg::ref_ptr<osg::Texture2D> CreateTexture(const std::string &path, bool wrapS = false, bool wrapT = false, bool wrapR = false);
	Line 39:     static osg::ref_ptr<osg::Texture2D> CreateTexture(const std::string &path, bool wrapS = false, bool wrapT = false, bool wrapR = false);
	Line 47:     static osg::Vec3f GetOceanColor(VisualEffectEnum visualEffect);
	Line 51:     static void AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset);
	Line 51:     static void AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset);
	Line 51:     static void AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset);
	Line 51:     static void AddQuad(osg::ref_ptr<osg::Vec3Array> vertices, osg::ref_ptr<osg::Vec2Array> texcoords, double xOffset, double zOffset);
	Line 53:     static osg::Vec3 GetCelestialPosition(float azimuth, float elevation);
	Line 60:     static void PaintString(osg::ref_ptr<osg::Geode> geode, std::string number);
	Line 60:     static void PaintString(osg::ref_ptr<osg::Geode> geode, std::string number);
	Line 63:     static std::string & PrintQuat(std::string & str, const osg::Quat &v);
	Line 66:     static std::string & PrintVec3(std::string & str, const osg::Vec3 &v);
	Line 79:     static void SetVisualEffectState(osg::StateSet *stateSet, VisualEffectEnum& visualEffect);
	Line 94:     static osg::Vec4 ColorToGrayscale(osg::Vec4 color);
	Line 94:     static osg::Vec4 ColorToGrayscale(osg::Vec4 color);
	Line 95:     static osg::Vec4 GetShipLettersTexCoords(char letter);
  D:\Development\psim\src\subview\SubviewViewer.cpp (32 hits)
	Line 27: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 27: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 28: extern osg::ref_ptr<osg::Camera> nearCamera;
	Line 28: extern osg::ref_ptr<osg::Camera> nearCamera;
	Line 29: extern osg::ref_ptr<osg::Camera> secondaryCamera; // secondary rendering camera for dual views
	Line 29: extern osg::ref_ptr<osg::Camera> secondaryCamera; // secondary rendering camera for dual views
	Line 30: extern osg::ref_ptr<osg::Camera> projCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 30: extern osg::ref_ptr<osg::Camera> projCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 31: extern osg::ref_ptr<osg::Camera> reflCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 31: extern osg::ref_ptr<osg::Camera> reflCamera; // renders stern wakes to a texture for projection onto the ocean's surface
	Line 35: osg::ref_ptr<osg::Uniform> SubviewViewer::atmoCUniform = NULL;
	Line 35: osg::ref_ptr<osg::Uniform> SubviewViewer::atmoCUniform = NULL;
	Line 37: SubviewViewer::SubviewViewer(osg::ArgumentParser& arguments)
	Line 47:     mLastFrameTime = osg::Timer::instance()->tick();
	Line 71:         osg::Timer_t current_time = osg::Timer::instance()->tick();
	Line 71:         osg::Timer_t current_time = osg::Timer::instance()->tick();
	Line 72:         if (osg::Timer::instance()->delta_s(mLastFrameTime, current_time) < mMinFrameTime) return;
	Line 91:     // osg::notify(osg::NOTICE)<<std::endl<<"CompositeViewer::frame()"<<std::endl<<std::endl;
	Line 91:     // osg::notify(osg::NOTICE)<<std::endl<<"CompositeViewer::frame()"<<std::endl<<std::endl;
	Line 110:     osg::Matrixd reflMat;
	Line 111:     reflMat.makeScale(osg::Vec3d(1.0, 1.0, -1.0));
	Line 115:     osg::Uniform * uniform = reflCamera->getOrCreateStateSet()->getOrCreateUniform("osg_ViewMatrixInverse", osg::Uniform::FLOAT_MAT4);
	Line 115:     osg::Uniform * uniform = reflCamera->getOrCreateStateSet()->getOrCreateUniform("osg_ViewMatrixInverse", osg::Uniform::FLOAT_MAT4);
	Line 116:     uniform->set(osg::Matrix::inverse(reflMat * mainCamera->getViewMatrix())); //osg view matrix inverse.
	Line 117:     uniform = reflCamera->getOrCreateStateSet()->getOrCreateUniform("osg_ViewMatrix", osg::Uniform::FLOAT_MAT4);
	Line 133:         osg::Timer_t endFrameTime = osg::Timer::instance()->tick();
	Line 133:         osg::Timer_t endFrameTime = osg::Timer::instance()->tick();
	Line 134:         double elapsedTime = osg::Timer::instance()->delta_s(mLastFrameTime, endFrameTime);
	Line 142:         //        endFrameTime = osg::Timer::instance()->tick();
	Line 143:         //        elapsedTime = osg::Timer::instance()->delta_s(mLastFrameTime, endFrameTime);
	Line 169:         osg::Vec3f eye, center, dir, up;
	Line 176:             atmoCUniform->set(osg::Vec3f(center[2] + Rg, center[1], center[0]));
  D:\Development\psim\src\subview\SubviewViewer.h (4 hits)
	Line 22:     SubviewViewer(osg::ArgumentParser& arguments);
	Line 28:     static osg::ref_ptr<osg::Uniform> atmoCUniform;
	Line 28:     static osg::ref_ptr<osg::Uniform> atmoCUniform;
	Line 36:     osg::Timer_t mLastFrameTime;
  D:\Development\psim\src\subview\Sun.cpp (46 hits)
	Line 55:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 55:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 55:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 56:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 56:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 56:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 60:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 60:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 60:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 64:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vertices->size()));
	Line 64:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vertices->size()));
	Line 66:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 66:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 66:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 67:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "sunVert.glsl"));
	Line 68:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "sunFrag.glsl"));
	Line 70:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 70:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 70:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 72:     osg::Depth* depth = new osg::Depth;
	Line 72:     osg::Depth* depth = new osg::Depth;
	Line 74:     stateset->setAttributeAndModes(depth, osg::StateAttribute::ON);
	Line 75:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 75:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 79:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 79:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 79:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 83:     mTransformPtr = new osg::MatrixTransform;
	Line 87:     mGroupPtr = new osg::Group;
	Line 92:     rgb_bot = osg::Vec3(0.7f, 0.7f, 0.9f);
	Line 99: osg::Group* Sun::GetNode()
	Line 119: osg::Vec3 Sun::GetOldSunPosVec()
	Line 139: osg::Vec3 Sun::GetPos()
	Line 144: osg::Vec3 Sun::GetColor()
	Line 154: osg::Vec3 Sun::GetBottomColor()
	Line 261: void Sun::Update(double dayNumber, double latitude, double longitude, float moonIntensity, osg::Camera *camera)
	Line 340:     rgb_bot = osg::Vec3(r, g, b);
	Line 344:     mColor = osg::Vec3(Sr, Sg, Sb);
	Line 413: void Sun::Draw(double UT, osg::Camera *camera, Moon *moonPtr)
	Line 423:             osg::Matrix::rotate(osg::inDegrees(mElevation), 1.0f, 0.0f, 0.0f) *
	Line 423:             osg::Matrix::rotate(osg::inDegrees(mElevation), 1.0f, 0.0f, 0.0f) *
	Line 424:             osg::Matrix::rotate(osg::inDegrees(mAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 424:             osg::Matrix::rotate(osg::inDegrees(mAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 425:             osg::Matrix::scale(SUN_QUAD_SCALE, SUN_QUAD_SCALE, SUN_QUAD_SCALE) *
	Line 426:             osg::Matrix::translate(mPosition*SUN_DISTANCE));
	Line 436: osg::Vec3 Sun::getOldSunPos(double dayNumber, double latitude, double longitude, double minBack)
  D:\Development\psim\src\subview\Sun.h (16 hits)
	Line 30:         osg::Vec3 GetBottomColor();
	Line 31:         osg::Vec3 GetColor();
	Line 36:         osg::Group* GetNode();
	Line 37:         osg::Vec3 GetOldSunPosVec();
	Line 38:         osg::Vec3 GetPos();
	Line 44:         void Update(double dayNumber, double latitude, double longitude, float moonIntensity, osg::Camera *camera);
	Line 45:         void Draw(double UT, osg::Camera *camera, Moon *moonPtr);
	Line 70:         osg::Vec3 getOldSunPos(double dayNumber, double latitude, double longitude, double minBack);
	Line 76:         osg::Vec3 rgb_bot;
	Line 77:         osg::Vec3 oldSunPos;
	Line 84:         osg::Vec3 mColor;
	Line 87:         osg::Vec3 mPosition;
	Line 92:         osg::ref_ptr<osg::Group> mGroupPtr;
	Line 92:         osg::ref_ptr<osg::Group> mGroupPtr;
	Line 93:         osg::ref_ptr<osg::MatrixTransform> mTransformPtr;
	Line 93:         osg::ref_ptr<osg::MatrixTransform> mTransformPtr;
  D:\Development\psim\src\subview\SunFlare.cpp (64 hits)
	Line 108:     mFlareColorUniform = new osg::Uniform("flareColor", osg::Vec4(1.0, 0.5, 0.5, 1.0));
	Line 108:     mFlareColorUniform = new osg::Uniform("flareColor", osg::Vec4(1.0, 0.5, 0.5, 1.0));
	Line 109:     mFlareScaleUniform = new osg::Uniform("flareScale", 0.0f);
	Line 112:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 112:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 112:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 113:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "flareVert.glsl"));
	Line 114:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "flareFrag.glsl"));
	Line 117:     osg::ref_ptr<osg::Geode> flareGeode = new osg::Geode();
	Line 117:     osg::ref_ptr<osg::Geode> flareGeode = new osg::Geode();
	Line 117:     osg::ref_ptr<osg::Geode> flareGeode = new osg::Geode();
	Line 161:     osg::ref_ptr<osg::StateSet> stateset = flareGeode->getOrCreateStateSet();
	Line 161:     osg::ref_ptr<osg::StateSet> stateset = flareGeode->getOrCreateStateSet();
	Line 164:     stateset->addUniform(new osg::Uniform("flareOriginX", FLARE_PRIMARY_X));
	Line 165:     stateset->addUniform(new osg::Uniform("texture", 0));
	Line 166:     stateset->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 166:     stateset->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 169:     mTransform = new osg::MatrixTransform;
	Line 178: osg::Group* SunFlare::GetNode()
	Line 183: void SunFlare::Update(osg::Vec3 sunColor, float sunElevation, int numOccludedPixels)
	Line 204:     mFlareColorUniform->set(osg::Vec4(sunColor, mFlareAlpha));
	Line 207: void SunFlare::Draw(float sunElevation, float sunAzimuth, osg::Vec3 sunPos, osg::Camera *camera)
	Line 207: void SunFlare::Draw(float sunElevation, float sunAzimuth, osg::Vec3 sunPos, osg::Camera *camera)
	Line 210:     osg::Vec3 flarePos = sunPos;
	Line 225:             osg::Matrix::rotate(flareRotate, 0.0f, 1.0f, 0.0) *
	Line 226:             osg::Matrix::rotate(osg::inDegrees(sunElevation), 1.0f, 0.0f, 0.0f) *
	Line 226:             osg::Matrix::rotate(osg::inDegrees(sunElevation), 1.0f, 0.0f, 0.0f) *
	Line 227:             osg::Matrix::rotate(osg::inDegrees(sunAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 227:             osg::Matrix::rotate(osg::inDegrees(sunAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 228:             osg::Matrix::scale(FLARE_SCALE, FLARE_SCALE, FLARE_SCALE) *
	Line 229:             osg::Matrix::translate(flarePos[0], flarePos[1], flarePos[2]));
	Line 241: void SunFlare::CalculateFlareTransform(osg::Vec3 flarePos, float& flareRotation, float& flareLength, osg::Camera *camera)
	Line 241: void SunFlare::CalculateFlareTransform(osg::Vec3 flarePos, float& flareRotation, float& flareLength, osg::Camera *camera)
	Line 243:     osg::Vec4 flareCoords = osg::Vec4(flarePos[0], flarePos[1], flarePos[2], 1.0);
	Line 243:     osg::Vec4 flareCoords = osg::Vec4(flarePos[0], flarePos[1], flarePos[2], 1.0);
	Line 245:     osg::Matrix viewMatrix = camera->getViewMatrix();
	Line 246:     osg::Matrix projectionMatrix = camera->getProjectionMatrix();
	Line 247:     osg::Matrix windowMatrix = camera->getViewport()->computeWindowMatrix();
	Line 275: osg::ref_ptr<osg::Geometry> SunFlare::CreateFlareGeometry(
	Line 275: osg::ref_ptr<osg::Geometry> SunFlare::CreateFlareGeometry(
	Line 279:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 279:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 279:     osg::ref_ptr<osg::Geometry> geometry = new osg::Geometry;
	Line 282:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 282:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 282:     osg::ref_ptr<osg::Vec3Array> vertices = new osg::Vec3Array;
	Line 283:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 283:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 283:     osg::ref_ptr<osg::Vec2Array> texcoords = new osg::Vec2Array;
	Line 289:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vertices->size()));
	Line 289:     geometry->addPrimitiveSet(new osg::DrawArrays(osg::PrimitiveSet::QUADS, 0, vertices->size()));
	Line 295:     osg::BoundingBox bbox;
	Line 296:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 299:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 299:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 299:     osg::ref_ptr<osg::StateSet> stateset = new osg::StateSet;
	Line 305:     stateset->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 309:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 309:     stateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 312:     stateset->addUniform(new osg::Uniform("artifactX", xOffset));
	Line 313:     stateset->addUniform(new osg::Uniform("artifactZ", zOffset));
	Line 314:     stateset->addUniform(new osg::Uniform("baseAlpha", baseAlpha));
	Line 315:     stateset->addUniform(new osg::Uniform("artifactScale", artifactScale));
	Line 316:     stateset->addUniform(new osg::Uniform("isWhiteOut", isWhiteOut));
  D:\Development\psim\src\subview\SunFlare.h (14 hits)
	Line 87:         osg::Group* GetNode();
	Line 89:         void Update(osg::Vec3 sunColor, float sunElevation, int numOccludedPixels);
	Line 90:         void Draw(float sunElevation, float sunAzimuth, osg::Vec3 sunPos, osg::Camera *camera);
	Line 90:         void Draw(float sunElevation, float sunAzimuth, osg::Vec3 sunPos, osg::Camera *camera);
	Line 93:         void CalculateFlareTransform(osg::Vec3 flarePos, float& flareRotation,
	Line 94:                                      float& flareLength, osg::Camera *camera);
	Line 95:         osg::ref_ptr<osg::Geometry> CreateFlareGeometry(std::string texturePath,
	Line 95:         osg::ref_ptr<osg::Geometry> CreateFlareGeometry(std::string texturePath,
	Line 101:         osg::ref_ptr<osg::Uniform> mFlareColorUniform;
	Line 101:         osg::ref_ptr<osg::Uniform> mFlareColorUniform;
	Line 102:         osg::ref_ptr<osg::Uniform> mFlareScaleUniform;
	Line 102:         osg::ref_ptr<osg::Uniform> mFlareScaleUniform;
	Line 103:         osg::ref_ptr<osg::MatrixTransform> mTransform;
	Line 103:         osg::ref_ptr<osg::MatrixTransform> mTransform;
  D:\Development\psim\src\subview\SunMoon.cpp (11 hits)
	Line 16: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 16: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 22: SunMoon::SunMoon(osg::Group *root)
	Line 38:     osg::ref_ptr<osg::Group> ephemerisGroup = new osg::Group;
	Line 38:     osg::ref_ptr<osg::Group> ephemerisGroup = new osg::Group;
	Line 38:     osg::ref_ptr<osg::Group> ephemerisGroup = new osg::Group;
	Line 65: osg::Vec3 SunMoon::GetMoonPos()
	Line 75: osg::Vec3 SunMoon::GetSunColor()
	Line 90: osg::Vec3 SunMoon::GetSunPos()
	Line 231: osg::Vec3 SunMoon::getOldSunPosVec()
	Line 256: osg::Vec3 SunMoon::GetBottomColor()
  D:\Development\psim\src\subview\SunMoon.h (6 hits)
	Line 13:         SunMoon(osg::Group *root);
	Line 23:         osg::Vec3 getOldSunPosVec();
	Line 33:         osg::Vec3 GetMoonPos();
	Line 36:         osg::Vec3 GetSunColor();
	Line 39:         osg::Vec3 GetSunPos();
	Line 41:         osg::Vec3 GetBottomColor();
  D:\Development\psim\src\subview\SunOcclusionQuery.cpp (35 hits)
	Line 44: , mSunTokenTransformPtr(new osg::MatrixTransform)
	Line 47:     osg::ref_ptr<osg::Cylinder> tokenShape = new osg::Cylinder(osg::Vec3(0.0, 0.0, 0.0), 0.25, 1.0);
	Line 47:     osg::ref_ptr<osg::Cylinder> tokenShape = new osg::Cylinder(osg::Vec3(0.0, 0.0, 0.0), 0.25, 1.0);
	Line 47:     osg::ref_ptr<osg::Cylinder> tokenShape = new osg::Cylinder(osg::Vec3(0.0, 0.0, 0.0), 0.25, 1.0);
	Line 47:     osg::ref_ptr<osg::Cylinder> tokenShape = new osg::Cylinder(osg::Vec3(0.0, 0.0, 0.0), 0.25, 1.0);
	Line 48:     osg::ref_ptr<osg::ShapeDrawable> tokenDrawable = new osg::ShapeDrawable(tokenShape);
	Line 48:     osg::ref_ptr<osg::ShapeDrawable> tokenDrawable = new osg::ShapeDrawable(tokenShape);
	Line 48:     osg::ref_ptr<osg::ShapeDrawable> tokenDrawable = new osg::ShapeDrawable(tokenShape);
	Line 49:     tokenDrawable->setColor(osg::Vec4(1.0, 0.0, 0.0, 0.0)); // the token should be invisible
	Line 50:     tokenShape->setRotation(*(new osg::Quat(0.5 * M_PI, osg::Vec3(1.0, 0.0, 0.0)))); // rotate the geometry so it appears to be a circle
	Line 50:     tokenShape->setRotation(*(new osg::Quat(0.5 * M_PI, osg::Vec3(1.0, 0.0, 0.0)))); // rotate the geometry so it appears to be a circle
	Line 53:     osg::ref_ptr<osg::Geode> sunToken = new osg::Geode();
	Line 53:     osg::ref_ptr<osg::Geode> sunToken = new osg::Geode();
	Line 53:     osg::ref_ptr<osg::Geode> sunToken = new osg::Geode();
	Line 58:     osg::ref_ptr<osg::StateSet> tokenStateset = sunToken->getOrCreateStateSet();
	Line 58:     osg::ref_ptr<osg::StateSet> tokenStateset = sunToken->getOrCreateStateSet();
	Line 60:     tokenStateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 60:     tokenStateset->setMode(GL_BLEND, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 63:     osg::ref_ptr<osg::Stencil> stencil = new osg::Stencil;
	Line 63:     osg::ref_ptr<osg::Stencil> stencil = new osg::Stencil;
	Line 63:     osg::ref_ptr<osg::Stencil> stencil = new osg::Stencil;
	Line 64:     stencil->setFunction(osg::Stencil::EQUAL, 0, 0x01);
	Line 67:     osg::ref_ptr<osg::StateSet> queryStateset = mFragQueryNodePtr->getQueryStateSet();
	Line 67:     osg::ref_ptr<osg::StateSet> queryStateset = mFragQueryNodePtr->getQueryStateSet();
	Line 68:     queryStateset->setAttributeAndModes(stencil, osg::StateAttribute::ON);
	Line 69:     queryStateset->setMode(GL_STENCIL_TEST, osg::StateAttribute::ON);
	Line 90: osg::Group* SunOcclusionQuery::GetNode()
	Line 95: int SunOcclusionQuery::GetOccludedPixels(osg::Camera *camera)
	Line 100: void SunOcclusionQuery::UpdateMatrix(float sunElevation, float sunAzimuth, float sunScale, osg::Vec3 sunPos)
	Line 104:             osg::Matrix::rotate(osg::inDegrees(sunElevation), 1.0f, 0.0f, 0.0f) *
	Line 104:             osg::Matrix::rotate(osg::inDegrees(sunElevation), 1.0f, 0.0f, 0.0f) *
	Line 105:             osg::Matrix::rotate(osg::inDegrees(sunAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 105:             osg::Matrix::rotate(osg::inDegrees(sunAzimuth), 0.0f, 0.0f, 1.0f) *
	Line 106:             osg::Matrix::scale(sunScale, sunScale, sunScale) *
	Line 107:             osg::Matrix::translate(sunPos));
  D:\Development\psim\src\subview\SunOcclusionQuery.h (6 hits)
	Line 17:         osg::Group* GetNode();
	Line 18:         int GetOccludedPixels(osg::Camera *camera);
	Line 20:         void UpdateMatrix(float sunElevation, float sunAzimuth, float sunScale, osg::Vec3 sunPos);
	Line 23:         osg::ref_ptr<FragQueryNode> mFragQueryNodePtr;
	Line 24:         osg::ref_ptr<osg::MatrixTransform> mSunTokenTransformPtr;
	Line 24:         osg::ref_ptr<osg::MatrixTransform> mSunTokenTransformPtr;
  D:\Development\psim\src\subview\SwitchedEntity.cpp (56 hits)
	Line 26: void SwitchedEntity::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 26: void SwitchedEntity::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 37:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 41:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 48:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 52:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 57:             osg::Node * child = ((osg::Group*)node)->getChild(1);
	Line 57:             osg::Node * child = ((osg::Group*)node)->getChild(1);
	Line 60:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 64:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 71:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 75:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 84:             //    ((osg::Switch *) node)->setAllChildrenOn();
	Line 88:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 97:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 101:             //    ((osg::Switch *) node)->setAllChildrenOff();
	Line 109:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 113:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 121:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 125:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 134:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 138:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 147:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 151:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 159:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 163:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 171:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 175:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 183:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 187:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 195:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 199:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 208:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 212:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 219:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 223:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 230:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 234:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 241:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 245:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 252:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 256:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 263:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 267:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 274:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 278:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 288:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 292:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 301:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 305:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 314:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 318:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 327:                 ((osg::Switch *) node)->setAllChildrenOn();
	Line 331:                 ((osg::Switch *) node)->setAllChildrenOff();
	Line 404:             ((osg::Switch *) node)->setAllChildrenOn();
	Line 406:             ((osg::Switch *) node)->setAllChildrenOff();
  D:\Development\psim\src\subview\SwitchedEntity.h (3 hits)
	Line 9: class SwitchedEntity : public osg::NodeCallback
	Line 13:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 13:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\TacDisp.cpp (13 hits)
	Line 30:         mFontColorDay = osg::Vec3(atoi(getenv("TAC_DISP_DAY_RED")),
	Line 36:         mFontColorNight = osg::Vec3(atoi(getenv("TAC_DISP_NIGHT_RED")),
	Line 67: void TacDisp::drawImplementation(osg::RenderInfo& ri) const
	Line 73: osg::Vec3 TacDisp::convertRGBToHSV(osg::Vec3 rgb)
	Line 73: osg::Vec3 TacDisp::convertRGBToHSV(osg::Vec3 rgb)
	Line 76:     osg::Vec3 hsv;
	Line 111: osg::Vec3 TacDisp::convertHSVToRGB(osg::Vec3 hsv)
	Line 111: osg::Vec3 TacDisp::convertHSVToRGB(osg::Vec3 hsv)
	Line 114:     osg::Vec3 rgb;
	Line 152: void TacDisp::draw(osg::RenderInfo& ri)
	Line 161:     osg::Vec3 hsv;
	Line 162:     osg::Vec3 rgb;
	Line 172:     hsv = convertRGBToHSV(osg::Vec3(rgb[0] / 255.f, rgb[1] / 255.f, rgb[2] / 255.f));
  D:\Development\psim\src\subview\TacDisp.h (8 hits)
	Line 17:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 20:     void draw(osg::RenderInfo& ri);
	Line 21:     osg::Vec3 convertRGBToHSV(osg::Vec3 rgb);
	Line 21:     osg::Vec3 convertRGBToHSV(osg::Vec3 rgb);
	Line 22:     osg::Vec3 convertHSVToRGB(osg::Vec3 hsv);
	Line 22:     osg::Vec3 convertHSVToRGB(osg::Vec3 hsv);
	Line 25:     osg::Vec3 mFontColorDay;
	Line 26:     osg::Vec3 mFontColorNight;
  D:\Development\psim\src\subview\Telemeter.cpp (14 hits)
	Line 14: Telemeter::Telemeter(const Telemeter& Telemeter, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 14: Telemeter::Telemeter(const Telemeter& Telemeter, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 15: osg::Geometry(Telemeter, copyop)
	Line 56: osg::BoundingBox Telemeter::computeBound() const
	Line 58:     osg::BoundingBox bbox;
	Line 59:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 60:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 64: void Telemeter::addToOSG(osg::Group * root)
	Line 66:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 66:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 66:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 72: void Telemeter::addDrawable(osg::Geode *geode)
	Line 77: void Telemeter::removeDrawable(osg::Geode *geode)
	Line 82: void Telemeter::drawImplementation(osg::RenderInfo& ri) const
  D:\Development\psim\src\subview\Telemeter.h (24 hits)
	Line 23: class Telemeter : public osg::Geometry
	Line 28:     Telemeter(const Telemeter& Telemeter, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 28:     Telemeter(const Telemeter& Telemeter, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 31:     virtual osg::BoundingBox computeBound() const;
	Line 35:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 36:     void addToOSG(osg::Group * root);
	Line 38:     virtual void addDrawable(osg::Geode *geode);
	Line 39:     virtual void removeDrawable(osg::Geode *geode);
	Line 57:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 57:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 58:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 58:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 59:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 59:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 60:     osg::ref_ptr<osg::Uniform> textureEnabledUniform;
	Line 60:     osg::ref_ptr<osg::Uniform> textureEnabledUniform;
	Line 61:     osg::ref_ptr<osg::Uniform> redUniform;
	Line 61:     osg::ref_ptr<osg::Uniform> redUniform;
	Line 62:     osg::ref_ptr<osg::Uniform> greenUniform;
	Line 62:     osg::ref_ptr<osg::Uniform> greenUniform;
	Line 63:     osg::ref_ptr<osg::Uniform> blueUniform;
	Line 63:     osg::ref_ptr<osg::Uniform> blueUniform;
	Line 64:     osg::ref_ptr<osg::Uniform> alphaUniform;
	Line 64:     osg::ref_ptr<osg::Uniform> alphaUniform;
  D:\Development\psim\src\subview\Terrain.cpp (41 hits)
	Line 41: Terrain::Terrain(const Terrain& Terrain, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 41: Terrain::Terrain(const Terrain& Terrain, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 42: osg::Geode(Terrain, copyop)
	Line 50: Terrain::Terrain(osg::Camera *c) :
	Line 118:     osg::ref_ptr<osg::Geometry> defaultDrawable = new TerrainDrawable(this, -1, this->getNumDrawables() + 1);
	Line 118:     osg::ref_ptr<osg::Geometry> defaultDrawable = new TerrainDrawable(this, -1, this->getNumDrawables() + 1);
	Line 146:     texmat = new osg::TexMat;
	Line 147:     texmat->setMatrix(osg::Matrix::translate(0., 0., 0.));
	Line 169:     osg::ref_ptr<TerrainDrawable> curDrawable;
	Line 202:     osg::ref_ptr<osg::Geometry> newDrawable;
	Line 202:     osg::ref_ptr<osg::Geometry> newDrawable;
	Line 212:     osg::Vec3f eye, center, dir, up;
	Line 216:     osg::Matrixf view = camera->getViewMatrix();
	Line 261: void Terrain::addToOSG(osg::Group * root)
	Line 268:     stateSet = new osg::StateSet;
	Line 271:     rockTexSampler = new osg::Uniform("RockTex", 0);
	Line 272:     sandTexSampler = new osg::Uniform("SandTex", 1);
	Line 273:     grassTexSampler = new osg::Uniform("GrassTex", 2);
	Line 274:     forestTexSampler = new osg::Uniform("ForestTex", 3);
	Line 275:     texIDUniform = new osg::Uniform("texID", -1.0f);
	Line 278:     maxSunZUniform = new osg::Uniform("maxSunZ", 0.0f);
	Line 279:     curTimeInDarkUniform = new osg::Uniform("curTimeInDark", 0.0f);
	Line 280:     totalTimeInDarkUniform = new osg::Uniform("totalTimeInDark", 0.0f);
	Line 283:     distanceEWUniform = new osg::Uniform("distanceEW", 0.f);
	Line 284:     distanceNSUniform = new osg::Uniform("distanceNS", 0.f);
	Line 285:     scopeElevationUniform = new osg::Uniform("scopeElevation", 0.f);
	Line 286:     oldSunPosUniform = new osg::Uniform("oldSunPos", osg::Vec3(0, 1, 0));
	Line 286:     oldSunPosUniform = new osg::Uniform("oldSunPos", osg::Vec3(0, 1, 0));
	Line 305:     stateSet->setTextureAttributeAndModes(0, texmat.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 305:     stateSet->setTextureAttributeAndModes(0, texmat.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 306:     stateSet->setTextureAttributeAndModes(0, RockTex, osg::StateAttribute::ON);
	Line 307:     stateSet->setTextureAttributeAndModes(1, SandTex, osg::StateAttribute::ON);
	Line 308:     stateSet->setTextureAttributeAndModes(2, GrassTex, osg::StateAttribute::ON);
	Line 309:     stateSet->setTextureAttributeAndModes(3, ForestTex, osg::StateAttribute::ON);
	Line 312:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 312:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 312:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 315:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, "terrainVert.glsl"));
	Line 316:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "terrainFrag.glsl"));
	Line 322:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 322:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
  D:\Development\psim\src\subview\Terrain.h (44 hits)
	Line 22: class Terrain : public osg::Geode
	Line 27:     Terrain(const Terrain& Terrain, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 27:     Terrain(const Terrain& Terrain, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 30:     Terrain(osg::Camera *camera);
	Line 39:     void addToOSG(osg::Group * root);
	Line 50:     osg::Camera *camera;
	Line 53:     osg::ref_ptr<osg::Texture2D> RockTex;
	Line 53:     osg::ref_ptr<osg::Texture2D> RockTex;
	Line 54:     osg::ref_ptr<osg::Texture2D> SandTex;
	Line 54:     osg::ref_ptr<osg::Texture2D> SandTex;
	Line 55:     osg::ref_ptr<osg::Texture2D> GrassTex;
	Line 55:     osg::ref_ptr<osg::Texture2D> GrassTex;
	Line 56:     osg::ref_ptr<osg::Texture2D> ForestTex;
	Line 56:     osg::ref_ptr<osg::Texture2D> ForestTex;
	Line 57:     osg::ref_ptr<osg::TexMat> texmat;
	Line 57:     osg::ref_ptr<osg::TexMat> texmat;
	Line 91:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 91:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 93:     //osg::ref_ptr<osg::Uniform> texSampler;
	Line 93:     //osg::ref_ptr<osg::Uniform> texSampler;
	Line 94:     osg::ref_ptr<osg::Uniform> rockTexSampler;
	Line 94:     osg::ref_ptr<osg::Uniform> rockTexSampler;
	Line 95:     osg::ref_ptr<osg::Uniform> sandTexSampler;
	Line 95:     osg::ref_ptr<osg::Uniform> sandTexSampler;
	Line 96:     osg::ref_ptr<osg::Uniform> grassTexSampler;
	Line 96:     osg::ref_ptr<osg::Uniform> grassTexSampler;
	Line 97:     osg::ref_ptr<osg::Uniform> forestTexSampler;
	Line 97:     osg::ref_ptr<osg::Uniform> forestTexSampler;
	Line 98:     osg::ref_ptr<osg::Uniform> texIDUniform;
	Line 98:     osg::ref_ptr<osg::Uniform> texIDUniform;
	Line 99:     osg::ref_ptr<osg::Uniform> maxSunZUniform;
	Line 99:     osg::ref_ptr<osg::Uniform> maxSunZUniform;
	Line 100:     osg::ref_ptr<osg::Uniform> curTimeInDarkUniform;
	Line 100:     osg::ref_ptr<osg::Uniform> curTimeInDarkUniform;
	Line 101:     osg::ref_ptr<osg::Uniform> totalTimeInDarkUniform;
	Line 101:     osg::ref_ptr<osg::Uniform> totalTimeInDarkUniform;
	Line 102:     osg::ref_ptr<osg::Uniform> distanceEWUniform;
	Line 102:     osg::ref_ptr<osg::Uniform> distanceEWUniform;
	Line 103:     osg::ref_ptr<osg::Uniform> distanceNSUniform;
	Line 103:     osg::ref_ptr<osg::Uniform> distanceNSUniform;
	Line 104:     osg::ref_ptr<osg::Uniform> scopeElevationUniform;
	Line 104:     osg::ref_ptr<osg::Uniform> scopeElevationUniform;
	Line 105:     osg::ref_ptr<osg::Uniform> oldSunPosUniform;
	Line 105:     osg::ref_ptr<osg::Uniform> oldSunPosUniform;
  D:\Development\psim\src\subview\TerrainBuffer.cpp (2 hits)
	Line 136: void TerrainBuffer::draw(int texID, osg::RenderInfo& ri)
	Line 144:         osg::State & state = *ri.getState();
  D:\Development\psim\src\subview\TerrainBuffer.h (1 hit)
	Line 25:     void draw(int texID, osg::RenderInfo& ri);
  D:\Development\psim\src\subview\TerrainDrawable.cpp (20 hits)
	Line 25: TerrainDrawable::TerrainDrawable(const TerrainDrawable& TerrainDrawable, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 25: TerrainDrawable::TerrainDrawable(const TerrainDrawable& TerrainDrawable, const osg::CopyOp& copyop/* = osg::CopyOp::SHALLOW_COPY*/) :
	Line 26: osg::Geometry(TerrainDrawable, copyop)
	Line 78: osg::BoundingBox TerrainDrawable::computeBound() const
	Line 80:     osg::BoundingBox bbox;
	Line 81:     bbox.expandBy(osg::Vec3(-100000.f, -100000.f, -100000.f));
	Line 82:     bbox.expandBy(osg::Vec3(100000.f, 100000.f, 100000.f));
	Line 105:     offsetUniform->set(osg::Vec3(-1. * (0.5 + shaderDistanceEW * centerXYZ[0]), -1. * shaderDistanceNS * centerXYZ[1], 1.));
	Line 120: void TerrainDrawable::drawImplementation(osg::RenderInfo& ri) const
	Line 142:                 osg::ref_ptr<osg::State> state = ri.getState();
	Line 142:                 osg::ref_ptr<osg::State> state = ri.getState();
	Line 193:     mStateSet = new osg::StateSet;
	Line 195:     offsetUniform = new osg::Uniform("offset", osg::Vec3(centerXYZ[0], centerXYZ[1], 1.));
	Line 195:     offsetUniform = new osg::Uniform("offset", osg::Vec3(centerXYZ[0], centerXYZ[1], 1.));
	Line 197:     distanceNSUniform = new osg::Uniform("distanceNS", shaderDistanceNS);
	Line 198:     distanceEWUniform = new osg::Uniform("distanceEW", shaderDistanceEW);
	Line 207:         satImageryTexSampler = new osg::Uniform("SatImageryTex", 4);
	Line 208:         texIDUniform = new osg::Uniform("texID", float(mTexID));
	Line 213:         mStateSet->setTextureAttributeAndModes(4, mTexture, osg::StateAttribute::ON | osg::StateAttribute::PROTECTED);
	Line 213:         mStateSet->setTextureAttributeAndModes(4, mTexture, osg::StateAttribute::ON | osg::StateAttribute::PROTECTED);
  D:\Development\psim\src\subview\TerrainDrawable.h (19 hits)
	Line 17: class TerrainDrawable : public osg::Geometry
	Line 22:     TerrainDrawable(const TerrainDrawable& TerrainDrawable, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 22:     TerrainDrawable(const TerrainDrawable& TerrainDrawable, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY);
	Line 26:     virtual osg::BoundingBox computeBound() const;
	Line 30:     void drawImplementation(osg::RenderInfo& ri) const;
	Line 56:     osg::ref_ptr<osg::Texture2D> mTexture;
	Line 56:     osg::ref_ptr<osg::Texture2D> mTexture;
	Line 57:     osg::ref_ptr<osg::Uniform> satImageryTexSampler;
	Line 57:     osg::ref_ptr<osg::Uniform> satImageryTexSampler;
	Line 58:     osg::ref_ptr<osg::Uniform> texIDUniform;
	Line 58:     osg::ref_ptr<osg::Uniform> texIDUniform;
	Line 59:     osg::ref_ptr<osg::Uniform> distanceNSUniform;
	Line 59:     osg::ref_ptr<osg::Uniform> distanceNSUniform;
	Line 60:     osg::ref_ptr<osg::Uniform> distanceEWUniform;
	Line 60:     osg::ref_ptr<osg::Uniform> distanceEWUniform;
	Line 61:     osg::ref_ptr<osg::Uniform> offsetUniform;
	Line 61:     osg::ref_ptr<osg::Uniform> offsetUniform;
	Line 64:     osg::ref_ptr<osg::StateSet> mStateSet;
	Line 64:     osg::ref_ptr<osg::StateSet> mStateSet;
  D:\Development\psim\src\subview\TerrainMeshGenerator.cpp (5 hits)
	Line 34: TerrainMeshGenerator::TerrainMeshGenerator(Terrain* pTerrain, double lat, double lon, ViewSpecShared* pCurrentViewSpec, osg::Camera *c) :
	Line 582:     osg::Vec3f eye, center, up;
	Line 583:     osg::Matrixf view;
	Line 599:     osg::Vec3f eye, center, up;
	Line 600:     osg::Matrixf view;
  D:\Development\psim\src\subview\TerrainMeshGenerator.h (2 hits)
	Line 20:     TerrainMeshGenerator(Terrain* pTerrain, double lat, double lon, ViewSpecShared* pCurrentViewSpec, osg::Camera *c);
	Line 58:     osg::Camera *camera;
  D:\Development\psim\src\subview\test\ShipWakes.cc (6 hits)
	Line 51:   void updateDynamicWake(Sub* vehicle, float speed, osg::Vec3f pos)
	Line 56:   void updateDynamicWakeSteadyState(Sub* vehicle, float speed, osg::Vec3f pos, int num_iterations) // forces the wake to update num_iterations times so it reaches a constant value after filtering
	Line 117:   updateDynamicWakeSteadyState(os, 10.0f, osg::Vec3f(0.0,0.0,0.0), 200);
	Line 142:   updateDynamicWake(os, 10.0f, osg::Vec3f(0.0,0.0,0.0));
	Line 143:   updateDynamicWake(other_sub, 10.0f, osg::Vec3f(10.0,0.0,0.0));
	Line 170:   updateDynamicWake(other_sub, 10.0f, osg::Vec3f(10.0,0.0,0.0));
  D:\Development\psim\src\subview\TexCamUpdateCallback.cpp (8 hits)
	Line 21: extern osg::TexMat* projTexMat;
	Line 23: TexCamUpdateCallback::TexCamUpdateCallback(osg::ref_ptr<osg::Camera> mainCamera) :
	Line 23: TexCamUpdateCallback::TexCamUpdateCallback(osg::ref_ptr<osg::Camera> mainCamera) :
	Line 29: void TexCamUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 29: void TexCamUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 31:     osg::Camera* texCam = dynamic_cast<osg::Camera*> (node); // dynamic cast will return null if node isn't a camera
	Line 31:     osg::Camera* texCam = dynamic_cast<osg::Camera*> (node); // dynamic cast will return null if node isn't a camera
	Line 69:                 projTexMat = new osg::TexMat();
  D:\Development\psim\src\subview\TexCamUpdateCallback.h (7 hits)
	Line 16: class TexCamUpdateCallback : public osg::NodeCallback
	Line 19:     TexCamUpdateCallback(osg::ref_ptr<osg::Camera> mainCamera);
	Line 19:     TexCamUpdateCallback(osg::ref_ptr<osg::Camera> mainCamera);
	Line 21:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 21:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 24:     osg::ref_ptr<osg::Camera> mMainCamera;
	Line 24:     osg::ref_ptr<osg::Camera> mMainCamera;
  D:\Development\psim\src\subview\TextBox.cpp (18 hits)
	Line 19: TextBox::TextBox(osg::Geode * node, std::string fontPath, osg::Vec4 color)
	Line 19: TextBox::TextBox(osg::Geode * node, std::string fontPath, osg::Vec4 color)
	Line 23:     node->getOrCreateStateSet()->setAttributeAndModes(new osg::Program(),
	Line 24:             osg::StateAttribute::ON
	Line 25:             | osg::StateAttribute::PROTECTED);
	Line 27:     osg::BoundingBox bb = node->getDrawable(0)->getBound();
	Line 28:     osg::Vec3 upperLeftCorner = bb.corner(6);
	Line 35:     osg::Vec3 position;
	Line 45:     mText->getOrCreateStateSet()->setDataVariance(osg::Object::DYNAMIC);
	Line 63:     //mText->setRotation(osg::Quat(w, x, y, z));
	Line 65:     osg::Quat quat1, quat2, quatFinal;
	Line 66:     quat1.makeRotate(270 * M_PI / 180, osg::Vec3(0, 0, 1));
	Line 67:     quat2.makeRotate(65 * M_PI / 180, osg::Vec3(1, 0, 0)); //rotations of bridge box
	Line 78: void TextBox::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 78: void TextBox::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 84: void TextBox::setText(osg::Node *node)
	Line 86:     osg::Geode* geode = dynamic_cast<osg::Geode*> (node);
	Line 86:     osg::Geode* geode = dynamic_cast<osg::Geode*> (node);
  D:\Development\psim\src\subview\TextBox.h (7 hits)
	Line 13: class TextBox : public osg::NodeCallback
	Line 17:     TextBox(osg::Geode * node, std::string fontPath, osg::Vec4 color);
	Line 17:     TextBox(osg::Geode * node, std::string fontPath, osg::Vec4 color);
	Line 21:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 21:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 23:     void setText(osg::Node *node);
	Line 28:     osg::ref_ptr<osgText::Text> mText;
  D:\Development\psim\src\subview\TexturedQuadLightsManager.cpp (50 hits)
	Line 35:     blend = new osg::BlendFunc;
	Line 36:     blend->setFunction(osg::BlendFunc::DST_ALPHA, osg::BlendFunc::ONE);
	Line 36:     blend->setFunction(osg::BlendFunc::DST_ALPHA, osg::BlendFunc::ONE);
	Line 37:     blend->setFunction(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA);
	Line 37:     blend->setFunction(osg::BlendFunc::SRC_ALPHA, osg::BlendFunc::ONE_MINUS_SRC_ALPHA);
	Line 40:     depth = new osg::Depth;
	Line 44:     tex1 = new osg::Texture2D;
	Line 46:     tex1->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 46:     tex1->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 47:     tex1->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 47:     tex1->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 48:     tex1->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP_TO_EDGE);
	Line 48:     tex1->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP_TO_EDGE);
	Line 49:     tex1->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_EDGE);
	Line 49:     tex1->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_EDGE);
	Line 52:     tex2 = new osg::Texture2D;
	Line 54:     tex2->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 54:     tex2->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 55:     tex2->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 55:     tex2->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 56:     tex2->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP_TO_EDGE);
	Line 56:     tex2->setWrap(osg::Texture2D::WRAP_S, osg::Texture2D::CLAMP_TO_EDGE);
	Line 57:     tex2->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_EDGE);
	Line 57:     tex2->setWrap(osg::Texture2D::WRAP_T, osg::Texture2D::CLAMP_TO_EDGE);
	Line 61:     lightSystemProgram = new osg::Program;
	Line 62:     lightSystemProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::VERTEX, lightVertShader));
	Line 63:     lightSystemProgram->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, lightFragShader));
	Line 80: void TexturedQuadLightsManager::createLightSystem(osg::Geode & geode, ParseInstanceVisitor & visitor)
	Line 83:     osg::ref_ptr<LightSystemStateSetUpdate> lsssu = new LightSystemStateSetUpdate(visitor);
	Line 87:     osg::ref_ptr<osg::StateSet> ss = new osg::StateSet;
	Line 87:     osg::ref_ptr<osg::StateSet> ss = new osg::StateSet;
	Line 87:     osg::ref_ptr<osg::StateSet> ss = new osg::StateSet;
	Line 92:         //ss->setDataVariance(osg::Object::DYNAMIC);
	Line 95:         ss->setMode(GL_LIGHTING, osg::StateAttribute::OFF);
	Line 101:         ss->setAttributeAndModes(TexturedQuadLightsManager::getInstance()->blend, osg::StateAttribute::ON);
	Line 104:         ss->setAttributeAndModes(TexturedQuadLightsManager::getInstance()->depth, osg::StateAttribute::ON);
	Line 107:         ss->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::OFF | osg::StateAttribute::PROTECTED);
	Line 107:         ss->setMode(GL_SAMPLE_ALPHA_TO_COVERAGE, osg::StateAttribute::OFF | osg::StateAttribute::PROTECTED);
	Line 110:         //ss->setAttributeAndModes (TexturedQuadLightsManager::getInstance ()->po, osg::StateAttribute::ON);
	Line 113:         ss->setTextureAttributeAndModes(0, TexturedQuadLightsManager::getInstance()->tex1, osg::StateAttribute::ON);
	Line 114:         ss->addUniform(new osg::Uniform("myTex", 0));
	Line 115:         ss->setTextureAttributeAndModes(1, TexturedQuadLightsManager::getInstance()->tex2, osg::StateAttribute::ON);
	Line 116:         ss->addUniform(new osg::Uniform("myTexFog", 1));
	Line 122:         ss->addUniform(new osg::Uniform("hullDown", visitor.getVehicle()->isEDGEContact() || visitor.getVehicle()->getType() == VehicleType::HARBOR));
	Line 134:     osg::ref_ptr<LightSystemUpdate> lsu = new LightSystemUpdate(visitor);
	Line 138:     osg::ref_ptr<osg::Geometry> lightSystem = new osg::Geometry;
	Line 138:     osg::ref_ptr<osg::Geometry> lightSystem = new osg::Geometry;
	Line 138:     osg::ref_ptr<osg::Geometry> lightSystem = new osg::Geometry;
	Line 147:         lightSystem->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
	Line 150:         lightSystem->setSecondaryColorBinding(osg::Geometry::BIND_PER_VERTEX);
  D:\Development\psim\src\subview\TexturedQuadLightsManager.h (15 hits)
	Line 26:     void createLightSystem(osg::Geode &, ParseInstanceVisitor &);
	Line 28:     osg::ref_ptr<osg::BlendFunc> blend;
	Line 28:     osg::ref_ptr<osg::BlendFunc> blend;
	Line 29:     osg::ref_ptr<osg::Depth> depth;
	Line 29:     osg::ref_ptr<osg::Depth> depth;
	Line 30:     osg::ref_ptr<osg::PolygonOffset> po;
	Line 30:     osg::ref_ptr<osg::PolygonOffset> po;
	Line 31:     osg::ref_ptr<osg::Texture2D> tex1;
	Line 31:     osg::ref_ptr<osg::Texture2D> tex1;
	Line 32:     osg::ref_ptr<osg::Texture2D> tex2;
	Line 32:     osg::ref_ptr<osg::Texture2D> tex2;
	Line 33:     osg::ref_ptr<osg::Program> lightSystemProgram;
	Line 33:     osg::ref_ptr<osg::Program> lightSystemProgram;
	Line 36:     osg::ref_ptr<osg::Texture2D> shapes;
	Line 36:     osg::ref_ptr<osg::Texture2D> shapes;
  D:\Development\psim\src\subview\TextureTelemeter.cpp (7 hits)
	Line 46: void TextureTelemeter::addDrawable(osg::Geode * geode)
	Line 52: void TextureTelemeter::removeDrawable(osg::Geode *geode)
	Line 64: void TextureTelemeter::drawImplementation(osg::RenderInfo& ri) const
	Line 92:     stateSet = new osg::StateSet;
	Line 94:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 94:     stateSet->setTextureAttributeAndModes(0, NULL, osg::StateAttribute::OFF | osg::StateAttribute::OVERRIDE);
	Line 97:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
  D:\Development\psim\src\subview\TextureTelemeter.h (3 hits)
	Line 24:     virtual void addDrawable(osg::Geode * geode);
	Line 25:     virtual void removeDrawable(osg::Geode *geode);
	Line 28:     virtual void drawImplementation(osg::RenderInfo& ri) const;
  D:\Development\psim\src\subview\TimeDB.cpp (5 hits)
	Line 24: TimeDB::TimeDB(Vehicle* vehicle, osg::Geode *node) :
	Line 25: TextBox(node, "msttcore/consola.ttf", osg::Vec4(1.f, 1.f, 1.f, 1.f)),
	Line 26: //TextBox(node, "gnu-free/FreeMonoBold.ttf", osg::Vec4(0.f, 0.f, 0.f, 1.f) ),
	Line 31: void TimeDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 31: void TimeDB::operator()(osg::Node * node, osg::NodeVisitor * nv)
  D:\Development\psim\src\subview\TimeDB.h (3 hits)
	Line 21:     TimeDB(Vehicle* vehicle, osg::Geode *node);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 23:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\UAVOverlay.cpp (63 hits)
	Line 27: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 27: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 45:     stateSet = new osg::StateSet;
	Line 48:     stateSet->setMode(GL_DEPTH_TEST, osg::StateAttribute::OFF);
	Line 59:     overlayInitialization(&mAltitudeAxis, (char*) "uav/vertical_line_1", osg::Vec3(255, 255, 255));
	Line 60:     overlayInitialization(&mCamOrient, (char*) "uav/large_arrow_1", osg::Vec3(255, 153, 0)); //Orange
	Line 61:     overlayInitialization(&mCommandedElev, (char*) "uav/small_arrow_1", osg::Vec3(0, 255, 0));
	Line 62:     overlayInitialization(&mHeadingToHome, (char*) "uav/half_line_three_quarters", osg::Vec3(255, 75, 170)); //Pink
	Line 63:     overlayInitialization(&mHeadingToTarget, (char*) "uav/half_line_full", osg::Vec3(255, 0, 0));
	Line 64:     overlayInitialization(&mHomeElev, (char*) "uav/small_arrow_1", osg::Vec3(255, 75, 170)); //Pink
	Line 65:     overlayInitialization(&mHorizonLine, (char*) "uav/vertical_line_3", osg::Vec3(255, 255, 255));
	Line 66:     overlayInitialization(&mNonOptRange, (char*) "uav/vertical_line_2", osg::Vec3(255, 0, 0));
	Line 67:     overlayInitialization(&mOptRange, (char*) "uav/vertical_line_2", osg::Vec3(0, 255, 0));
	Line 68:     overlayInitialization(&mTargetElev, (char*) "uav/small_arrow_1", osg::Vec3(255, 0, 0));
	Line 69:     overlayInitialization(&mUAVAlt, (char*) "uav/small_arrow_1", osg::Vec3(255, 153, 0)); //Orange
	Line 70:     overlayInitialization(&mUAVHeading, (char*) "uav/half_line_half", osg::Vec3(255, 255, 255));
	Line 71:     overlayInitialization(&mWindHeading, (char*) "uav/wind_baseline", osg::Vec3(0, 255, 255)); //Cyan
	Line 74: void UAVOverlay::overlayInitialization(OverlayTexture* overlay, char* overlayLoc, osg::Vec3 rgb)
	Line 84: void UAVOverlay::addDrawable(osg::Geode * geode)
	Line 102: void UAVOverlay::addToOSG(osg::Group * root)
	Line 104:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 104:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 104:     osg::ref_ptr<osg::Geode> geode = new osg::Geode();
	Line 276: void UAVOverlay::drawImplementation(osg::RenderInfo& ri) const
	Line 281: void UAVOverlay::draw(osg::RenderInfo& ri)
	Line 435: void UAVOverlay::drawHorizonLine(osg::RenderInfo& ri)
	Line 444:     osg::Vec2 point1 = osg::Vec2(-lineWidth, vertOffset);
	Line 444:     osg::Vec2 point1 = osg::Vec2(-lineWidth, vertOffset);
	Line 445:     osg::Vec2 point2 = osg::Vec2(lineWidth, vertOffset);
	Line 445:     osg::Vec2 point2 = osg::Vec2(lineWidth, vertOffset);
	Line 450: osg::Vec4 UAVOverlay::pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri)
	Line 450: osg::Vec4 UAVOverlay::pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri)
	Line 450: osg::Vec4 UAVOverlay::pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri)
	Line 450: osg::Vec4 UAVOverlay::pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri)
	Line 456:     osg::State &state = *ri.getState();
	Line 457:     osg::Matrixd viewMatrix = mainCamera->getViewMatrix();
	Line 458:     osg::Matrixd projectionMatrix = state.getProjectionMatrix();
	Line 459:     osg::Matrixd windowMatrix = mainCamera->getViewport()->computeWindowMatrix();
	Line 460:     osg::Matrixd inverseViewMatrix = osg::Matrixd::inverse(viewMatrix);
	Line 460:     osg::Matrixd inverseViewMatrix = osg::Matrixd::inverse(viewMatrix);
	Line 461:     osg::Matrixd inverseProjectionMatrix = osg::Matrixd::inverse(projectionMatrix);
	Line 461:     osg::Matrixd inverseProjectionMatrix = osg::Matrixd::inverse(projectionMatrix);
	Line 462:     osg::Matrixd inverseWindowMatrix = osg::Matrixd::inverse(windowMatrix);
	Line 462:     osg::Matrixd inverseWindowMatrix = osg::Matrixd::inverse(windowMatrix);
	Line 463:     osg::Matrixd rotationMatrix;
	Line 466:     osg::Vec4 point1Screen = osg::Vec4(point1.x(), point1.y(), 0.0, 1.0);
	Line 466:     osg::Vec4 point1Screen = osg::Vec4(point1.x(), point1.y(), 0.0, 1.0);
	Line 467:     osg::Vec4 point2Screen = osg::Vec4(point2.x(), point2.y(), 0.0, 1.0);
	Line 467:     osg::Vec4 point2Screen = osg::Vec4(point2.x(), point2.y(), 0.0, 1.0);
	Line 479:     osg::Quat pitchRollQuat = osg::Quat(0.0, osg::Vec3d(1, 0, 0),
	Line 479:     osg::Quat pitchRollQuat = osg::Quat(0.0, osg::Vec3d(1, 0, 0),
	Line 479:     osg::Quat pitchRollQuat = osg::Quat(0.0, osg::Vec3d(1, 0, 0),
	Line 480:                                         0, osg::Vec3d(0, 1, 0),
	Line 481:                                         effectiveRoll * M_PI / 180.0, osg::Vec3d(0, 0, 1));
	Line 483:     osg::Vec4 point1World = inverseWindowMatrix * inverseProjectionMatrix * inverseViewMatrix * point1Screen;
	Line 484:     osg::Vec4 point2World = inverseWindowMatrix * inverseProjectionMatrix * inverseViewMatrix * point2Screen;
	Line 541:     osg::Vec4 screenPoints = osg::Vec4(point1Screen.x(), point1Screen.y(), point2Screen.x(), point2Screen.y());
	Line 541:     osg::Vec4 screenPoints = osg::Vec4(point1Screen.x(), point1Screen.y(), point2Screen.x(), point2Screen.y());
	Line 546: void UAVOverlay::drawText(osg::RenderInfo& ri, char* text, float horizOffset, float vertOffset, float altitude)
	Line 553: /*void UAVOverlay::drawWaypointIndicators(osg::RenderInfo& ri)
	Line 567:       mWaypointTexts[i].text->getOrCreateStateSet()->setDataVariance(osg::Object::DYNAMIC);
	Line 578:         mWaypointTexts[i].text->setColor(osg::Vec4(1, 0, 0, 1));
	Line 580:         mWaypointTexts[i].text->setColor(osg::Vec4(255/255.0, 75/255.0, 170/255.0, 1.0));
  D:\Development\psim\src\subview\UAVOverlay.h (22 hits)
	Line 18: class UAVOverlay : public osg::Geometry
	Line 23:     //  UAVOverlay(const UAVOverlay& UAVOverlay,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
	Line 23:     //  UAVOverlay(const UAVOverlay& UAVOverlay,const osg::CopyOp& copyop=osg::CopyOp::SHALLOW_COPY):
	Line 24:     //osg::Geometry(UAVOverlay,copyop) {}
	Line 30:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 32:     virtual void addToOSG(osg::Group * root);
	Line 33:     virtual void addDrawable(osg::Geode * geode);
	Line 68:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 68:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 69:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 69:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 70:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 70:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 73:     void overlayInitialization(OverlayTexture* overlay, char* overlayLoc, osg::Vec3 rgb);
	Line 74:     void draw(osg::RenderInfo& ri);
	Line 78:     void drawHorizonLine(osg::RenderInfo& ri);
	Line 79:     void drawText(osg::RenderInfo& ri, char* text, float horizOfset, float vertOffset, float altitude);
	Line 80:     void drawWaypointIndicators(osg::RenderInfo& ri);
	Line 82:     osg::Vec4 pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri);
	Line 82:     osg::Vec4 pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri);
	Line 82:     osg::Vec4 pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri);
	Line 82:     osg::Vec4 pitchRollRotations(osg::Vec2 point1, osg::Vec2 point2, osg::RenderInfo& ri);
  D:\Development\psim\src\subview\UniformCallback.h (27 hits)
	Line 11: class UniformBoolUpdate : public osg::Uniform::Uniform::Callback
	Line 15:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 15:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 23: class UniformFloatUpdate : public osg::Uniform::Uniform::Callback
	Line 27:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 27:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 35: class UniformVec3fUpdate : public osg::Uniform::Uniform::Callback
	Line 38:         UniformVec3fUpdate(const std::function<osg::Vec3f()>& eval) : mEval(eval) {}
	Line 39:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 39:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 44:         std::function<osg::Vec3f()> mEval;
	Line 47: class UniformVec4fUpdate : public osg::Uniform::Uniform::Callback
	Line 50:         UniformVec4fUpdate(const std::function<osg::Vec4f()>& eval) : mEval(eval) {}
	Line 51:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 51:         virtual void operator()(osg::Uniform * uniform, osg::NodeVisitor * nv)
	Line 56:         std::function<osg::Vec4f()> mEval;
	Line 60: void addStaticUniform(osg::StateSet *stateSet, std::string name, osg::Uniform::Type uniformType, valueType value)
	Line 60: void addStaticUniform(osg::StateSet *stateSet, std::string name, osg::Uniform::Type uniformType, valueType value)
	Line 62:     osg::ref_ptr<osg::Uniform> uniform = new osg::Uniform(uniformType, name);
	Line 62:     osg::ref_ptr<osg::Uniform> uniform = new osg::Uniform(uniformType, name);
	Line 62:     osg::ref_ptr<osg::Uniform> uniform = new osg::Uniform(uniformType, name);
	Line 72: void addDynamicUniform(osg::StateSet *stateSet, std::string name, osg::Uniform::Type uniformType, valueType value,
	Line 72: void addDynamicUniform(osg::StateSet *stateSet, std::string name, osg::Uniform::Type uniformType, valueType value,
	Line 73:                        osg::Uniform::Uniform::Callback *callback)
	Line 75:     osg::ref_ptr<osg::Uniform> uniform = new osg::Uniform(uniformType, name);
	Line 75:     osg::ref_ptr<osg::Uniform> uniform = new osg::Uniform(uniformType, name);
	Line 75:     osg::ref_ptr<osg::Uniform> uniform = new osg::Uniform(uniformType, name);
  D:\Development\psim\src\subview\UpdateCubemapCamera.cpp (44 hits)
	Line 25: extern osg::ref_ptr<osg::Camera> pickCamera;
	Line 25: extern osg::ref_ptr<osg::Camera> pickCamera;
	Line 30:         osg::ref_ptr<osg::Camera> nearCamera,
	Line 30:         osg::ref_ptr<osg::Camera> nearCamera,
	Line 31:         osg::ref_ptr<osg::Camera> mainCamera) :
	Line 31:         osg::ref_ptr<osg::Camera> mainCamera) :
	Line 44: void UpdateCubemapCamera::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 44: void UpdateCubemapCamera::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 73:     osg::Vec3f eye, center, dir, up;
	Line 116:     //	osg::Vec3 position(eye[0],eye[1],-eye[2]);
	Line 118:     osg::Vec3 position(center[0], center[1], cubemap_height);
	Line 120:     typedef std::pair<osg::Vec3, osg::Vec3> ImageData;
	Line 120:     typedef std::pair<osg::Vec3, osg::Vec3> ImageData;
	Line 122:         ImageData(osg::Vec3(1, 0, 0), osg::Vec3(0, -1, 0)), // +X   // right       
	Line 122:         ImageData(osg::Vec3(1, 0, 0), osg::Vec3(0, -1, 0)), // +X   // right       
	Line 123:         ImageData(osg::Vec3(-1, 0, 0), osg::Vec3(0, -1, 0)), // -X  // left
	Line 123:         ImageData(osg::Vec3(-1, 0, 0), osg::Vec3(0, -1, 0)), // -X  // left
	Line 124:         ImageData(osg::Vec3(0, 1, 0), osg::Vec3(0, 0, 1)), // +Y // front 
	Line 124:         ImageData(osg::Vec3(0, 1, 0), osg::Vec3(0, 0, 1)), // +Y // front 
	Line 125:         ImageData(osg::Vec3(0, -1, 0), osg::Vec3(0, 0, -1)), // -Y // back
	Line 125:         ImageData(osg::Vec3(0, -1, 0), osg::Vec3(0, 0, -1)), // -Y // back
	Line 126:         ImageData(osg::Vec3(0, 0, 1), osg::Vec3(0, -1, 0)), // +Z   // top
	Line 126:         ImageData(osg::Vec3(0, 0, 1), osg::Vec3(0, -1, 0)), // +Z   // top
	Line 127:         ImageData(osg::Vec3(0, 0, -1), osg::Vec3(0, -1, 0)) // -Z   // bottom			                
	Line 127:         ImageData(osg::Vec3(0, 0, -1), osg::Vec3(0, -1, 0)) // -Z   // bottom			                
	Line 128:         /*		ImageData( osg::Vec3(1,  0,  0), osg::Vec3( 0, 1,  0) ), // +X   // right       
	Line 128:         /*		ImageData( osg::Vec3(1,  0,  0), osg::Vec3( 0, 1,  0) ), // +X   // right       
	Line 129:          ImageData( osg::Vec3(-1,  0,  0), osg::Vec3( 0, 1,  0) ), // -X  // left
	Line 129:          ImageData( osg::Vec3(-1,  0,  0), osg::Vec3( 0, 1,  0) ), // -X  // left
	Line 130:          ImageData( osg::Vec3( 0,  1,  0), osg::Vec3( 1,  0,  0) ), // +Y // front 
	Line 130:          ImageData( osg::Vec3( 0,  1,  0), osg::Vec3( 1,  0,  0) ), // +Y // front 
	Line 131:          ImageData( osg::Vec3( 0, -1,  0), osg::Vec3( 1,  0, 0) ), // -Y // back
	Line 131:          ImageData( osg::Vec3( 0, -1,  0), osg::Vec3( 1,  0, 0) ), // -Y // back
	Line 132:          ImageData( osg::Vec3( 0,  0,  1), osg::Vec3( 0, 1,  0) ), // +Z   // top
	Line 132:          ImageData( osg::Vec3( 0,  0,  1), osg::Vec3( 0, 1,  0) ), // +Z   // top
	Line 133:          ImageData( osg::Vec3( 0,  0, -1), osg::Vec3( 0, 1,  0) )  // -Z   // bottom
	Line 133:          ImageData( osg::Vec3( 0,  0, -1), osg::Vec3( 0, 1,  0) )  // -Z   // bottom
	Line 143:         osg::Matrix localOffset;
	Line 145:         osg::Matrix viewMatrix = localOffset; //_mainCamer-a->getViewMatrix()*localOffset;
	Line 146:         _Cameras[i]->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	Line 154:         osg::Matrix localOffset;
	Line 156:         _CamerasPP[i]->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
	Line 161:     osg::Matrix viewMatrix = _mainCamera->getViewMatrix();
	Line 163:     _nearCamera->setReferenceFrame(osg::Camera::ABSOLUTE_RF);
  D:\Development\psim\src\subview\UpdateCubemapCamera.h (15 hits)
	Line 19: class UpdateCubemapCamera : public osg::NodeCallback
	Line 22:     typedef std::vector< osg::ref_ptr<osg::Switch> > CameraSwitchList;
	Line 22:     typedef std::vector< osg::ref_ptr<osg::Switch> > CameraSwitchList;
	Line 23:     typedef std::vector< osg::ref_ptr<osg::Camera> > CameraList;
	Line 23:     typedef std::vector< osg::ref_ptr<osg::Camera> > CameraList;
	Line 28:             osg::ref_ptr<osg::Camera> nearCamera,
	Line 28:             osg::ref_ptr<osg::Camera> nearCamera,
	Line 29:             osg::ref_ptr<osg::Camera> mainCamera);
	Line 29:             osg::ref_ptr<osg::Camera> mainCamera);
	Line 31:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 31:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 39:     osg::ref_ptr<osg::Camera> _nearCamera;
	Line 39:     osg::ref_ptr<osg::Camera> _nearCamera;
	Line 40:     osg::ref_ptr<osg::Camera> _mainCamera;
	Line 40:     osg::ref_ptr<osg::Camera> _mainCamera;
  D:\Development\psim\src\subview\Vehicle.cpp (132 hits)
	Line 104: sternLightPos(osg::Vec3(0., 0., 0.)),
	Line 105: sternLightDir(osg::Vec3(0., 0., 0.)),
	Line 118: modelOrigin(osg::Vec3(0.0, 0.0, 0.0)),
	Line 125: mKnucklePos(osg::Vec3(0.0, 0.0, 0.0)),
	Line 138:     xform = new osg::MatrixTransform;
	Line 143:     xformBoundingBox = new osg::MatrixTransform;
	Line 147:     xformMat = new osg::Matrixf;
	Line 269:     osg::Vec2d movementVector(newPosition[0], newPosition[1]);
	Line 275:     osg::Vec3 headingVector3 = osg::Matrixf::rotate(osg::DegreesToRadians(contactHPR[0]), osg::Vec3(0., 0., 1.)).preMult(osg::Vec3(1.f, 0.f, 0.f));
	Line 275:     osg::Vec3 headingVector3 = osg::Matrixf::rotate(osg::DegreesToRadians(contactHPR[0]), osg::Vec3(0., 0., 1.)).preMult(osg::Vec3(1.f, 0.f, 0.f));
	Line 275:     osg::Vec3 headingVector3 = osg::Matrixf::rotate(osg::DegreesToRadians(contactHPR[0]), osg::Vec3(0., 0., 1.)).preMult(osg::Vec3(1.f, 0.f, 0.f));
	Line 275:     osg::Vec3 headingVector3 = osg::Matrixf::rotate(osg::DegreesToRadians(contactHPR[0]), osg::Vec3(0., 0., 1.)).preMult(osg::Vec3(1.f, 0.f, 0.f));
	Line 275:     osg::Vec3 headingVector3 = osg::Matrixf::rotate(osg::DegreesToRadians(contactHPR[0]), osg::Vec3(0., 0., 1.)).preMult(osg::Vec3(1.f, 0.f, 0.f));
	Line 276:     osg::Vec2 headingVector2(headingVector3.x(), headingVector3.y());
	Line 341:             osg::Node* node = xform->getChild(i);
	Line 343:                 mLightGeometry = (osg::Geometry*)((osg::Geode*)node)->getDrawable(0);
	Line 343:                 mLightGeometry = (osg::Geometry*)((osg::Geode*)node)->getDrawable(0);
	Line 456: void Vehicle::initHullNumber(osg::Group *hullGrp)
	Line 463:         std::vector<osg::Vec2Array*> curTexCoords;
	Line 464:         osg::ref_ptr<osg::Group> sideGrp = (osg::Group *) mHullGrp->getChild(numberSet);
	Line 464:         osg::ref_ptr<osg::Group> sideGrp = (osg::Group *) mHullGrp->getChild(numberSet);
	Line 464:         osg::ref_ptr<osg::Group> sideGrp = (osg::Group *) mHullGrp->getChild(numberSet);
	Line 469:             osg::ref_ptr<osg::Geode> origQuad = dynamic_cast<osg::Geode *> (sideGrp->getChild(curQuad));
	Line 469:             osg::ref_ptr<osg::Geode> origQuad = dynamic_cast<osg::Geode *> (sideGrp->getChild(curQuad));
	Line 469:             osg::ref_ptr<osg::Geode> origQuad = dynamic_cast<osg::Geode *> (sideGrp->getChild(curQuad));
	Line 470:             osg::ref_ptr<osg::Geometry> origGeom = dynamic_cast<osg::Geometry *> (origQuad->getDrawable(0));
	Line 470:             osg::ref_ptr<osg::Geometry> origGeom = dynamic_cast<osg::Geometry *> (origQuad->getDrawable(0));
	Line 470:             osg::ref_ptr<osg::Geometry> origGeom = dynamic_cast<osg::Geometry *> (origQuad->getDrawable(0));
	Line 471:             curTexCoords.push_back(dynamic_cast<osg::Vec2Array *> (origGeom->getTexCoordArray(0)));
	Line 474:             osg::ref_ptr<osg::Geode> newQuad = (osg::Geode *) origQuad->clone(osg::CopyOp::DEEP_COPY_ALL);
	Line 474:             osg::ref_ptr<osg::Geode> newQuad = (osg::Geode *) origQuad->clone(osg::CopyOp::DEEP_COPY_ALL);
	Line 474:             osg::ref_ptr<osg::Geode> newQuad = (osg::Geode *) origQuad->clone(osg::CopyOp::DEEP_COPY_ALL);
	Line 474:             osg::ref_ptr<osg::Geode> newQuad = (osg::Geode *) origQuad->clone(osg::CopyOp::DEEP_COPY_ALL);
	Line 508:         osg::ref_ptr<osg::Group> sideGrp = (osg::Group *) mHullGrp->getChild(numberSet);
	Line 508:         osg::ref_ptr<osg::Group> sideGrp = (osg::Group *) mHullGrp->getChild(numberSet);
	Line 508:         osg::ref_ptr<osg::Group> sideGrp = (osg::Group *) mHullGrp->getChild(numberSet);
	Line 565:             osg::ref_ptr<osg::Geode> quad = dynamic_cast<osg::Geode *> (sideGrp->getChild(curQuad));
	Line 565:             osg::ref_ptr<osg::Geode> quad = dynamic_cast<osg::Geode *> (sideGrp->getChild(curQuad));
	Line 565:             osg::ref_ptr<osg::Geode> quad = dynamic_cast<osg::Geode *> (sideGrp->getChild(curQuad));
	Line 566:             osg::ref_ptr<osg::Geometry> geom = dynamic_cast<osg::Geometry *> (quad->getDrawable(0));
	Line 566:             osg::ref_ptr<osg::Geometry> geom = dynamic_cast<osg::Geometry *> (quad->getDrawable(0));
	Line 566:             osg::ref_ptr<osg::Geometry> geom = dynamic_cast<osg::Geometry *> (quad->getDrawable(0));
	Line 567:             osg::Vec2Array* texCoords = dynamic_cast<osg::Vec2Array *> (geom->getTexCoordArray(0));
	Line 567:             osg::Vec2Array* texCoords = dynamic_cast<osg::Vec2Array *> (geom->getTexCoordArray(0));
	Line 570:             osg::Geometry::PrimitiveSetList list = geom->getPrimitiveSetList();
	Line 572:             if (list[0]->getMode() == osg::PrimitiveSet::TRIANGLES) numCoords = int(numCoords / 3) + 2; //if it is just triangles, use this calculation
	Line 639: void Vehicle::setHorizontalLaunchPoint(osg::Vec3f launchH)
	Line 646: void Vehicle::setVerticalLaunchPoint(osg::Vec3f launchV)
	Line 694: void Vehicle::addVlsCellLaunchPt(std::string name, osg::Vec3 point)
	Line 696:     vlsCellLaunchPts.insert(std::pair<std::string, osg::Vec3>(name, point));
	Line 706: void Vehicle::addVlsVentLaunchPt(std::string name, osg::Vec3 point)
	Line 708:     vlsVentLaunchPts.insert(std::pair<std::string, osg::Vec3>(name, point));
	Line 718: //void Vehicle::setGWSSmokePt(std::string whichGun, osg::Vec3 point)
	Line 799:             osg::Vec3d launchPt = getVlsCellLaunchPt(launcherSet, moduleNumber, cellNumber);
	Line 857: osg::Vec3 Vehicle::getVlsCellLaunchPt(int launcherSet, int moduleNumber, int cellNumber)
	Line 870:     for (std::map<std::string, osg::Vec3 >::iterator pointIter = vlsCellLaunchPts.begin();
	Line 886:     return osg::Vec3f(0, 0, 0);
	Line 896: osg::Vec3 Vehicle::getVlsVentLaunchPt(int launcherSet, int moduleNumber)
	Line 909:     std::map<std::string, osg::Vec3f>::iterator pointIter = vlsVentLaunchPts.begin();
	Line 926:     return osg::Vec3f(0, 0, 0);
	Line 935: osg::Vec3 Vehicle::getGWSSmokePt(std::string whichGun)
	Line 990:     explode(osg::Vec3(0, 0, 0));
	Line 996:  * Input: osg::Vec3f - X/Y/Z position relative to the vehicle
	Line 999: void Vehicle::explode(osg::Vec3f offset)
	Line 1006:     params.setGeomDimensions(osg::Vec2(175, 175));
	Line 1012:     params.setOrientation(osg::Vec3(0, 0, 1));
	Line 1027:     osg::MatrixTransform * loadedModelTransform = (osg::MatrixTransform *)(xform.get());
	Line 1027:     osg::MatrixTransform * loadedModelTransform = (osg::MatrixTransform *)(xform.get());
	Line 1028:     osg::Vec3 pos = contactLoc;
	Line 1029:     osg::Vec3 hpr = contactHPR;
	Line 1033:         loadedModelTransform->setMatrix(osg::Matrix::rotate(osg::inDegrees(0.), 0.0f, 0.0f, 1.0f) *
	Line 1033:         loadedModelTransform->setMatrix(osg::Matrix::rotate(osg::inDegrees(0.), 0.0f, 0.0f, 1.0f) *
	Line 1034:                 osg::Matrix::translate(pos[0], pos[1], pos[2])
	Line 1040:         loadedModelTransform->setMatrix(osg::Matrix::scale(scale, scale, scale) *
	Line 1041:                 osg::Matrix::rotate(osg::inDegrees(hpr[2]), 1.0f, 0.0f, 0.0f) *
	Line 1041:                 osg::Matrix::rotate(osg::inDegrees(hpr[2]), 1.0f, 0.0f, 0.0f) *
	Line 1042:                 osg::Matrix::rotate(osg::inDegrees(hpr[1]), 0.0f, 1.0f, 0.0f) *
	Line 1042:                 osg::Matrix::rotate(osg::inDegrees(hpr[1]), 0.0f, 1.0f, 0.0f) *
	Line 1043:                 osg::Matrix::rotate(osg::inDegrees(hpr[0]), 0.0f, 0.0f, 1.0f) *
	Line 1043:                 osg::Matrix::rotate(osg::inDegrees(hpr[0]), 0.0f, 0.0f, 1.0f) *
	Line 1044:                 osg::Matrix::translate(pos[0], pos[1], pos[2])
	Line 1051:     if (xformBoundingBox) ((osg::MatrixTransform *)(xformBoundingBox.get()))->setMatrix(*(xformMat));
	Line 1061:             lightPos_1 = new osg::Uniform("lightPos_1", osg::Vec3(0.f, 0.f, 0.f));
	Line 1061:             lightPos_1 = new osg::Uniform("lightPos_1", osg::Vec3(0.f, 0.f, 0.f));
	Line 1067:             lightColor_1 = new osg::Uniform("lightColor_1", osg::Vec3(0.f, 0.f, 0.f));
	Line 1067:             lightColor_1 = new osg::Uniform("lightColor_1", osg::Vec3(0.f, 0.f, 0.f));
	Line 1073:             lightPos_2 = new osg::Uniform("lightPos_2", osg::Vec3(0.f, 0.f, 0.f));
	Line 1073:             lightPos_2 = new osg::Uniform("lightPos_2", osg::Vec3(0.f, 0.f, 0.f));
	Line 1079:             lightColor_2 = new osg::Uniform("lightColor_2", osg::Vec3(0.f, 0.f, 0.f));
	Line 1079:             lightColor_2 = new osg::Uniform("lightColor_2", osg::Vec3(0.f, 0.f, 0.f));
	Line 1247: osg::Vec3f Vehicle::getActiveMastLoc()
	Line 1265:                 osg::Vec3f curMastLoc = curMastXform->getActiveMastLoc();
	Line 1287:     osg::Vec3f activeMastLoc = osg::Vec3f(farthestScopeDist, averageScopeXLoc, 0.f);
	Line 1287:     osg::Vec3f activeMastLoc = osg::Vec3f(farthestScopeDist, averageScopeXLoc, 0.f);
	Line 1534: void Vehicle::setLightStateSet(osg::StateSet* ss)
	Line 1539: void Vehicle::setLightGeometry(osg::Geometry* geo)
	Line 1544: void Vehicle::setLightPos_1(osg::Vec3 val)
	Line 1549: void Vehicle::setLightColor_1(osg::Vec3 val)
	Line 1554: void Vehicle::setLightPos_2(osg::Vec3 val)
	Line 1559: void Vehicle::setLightColor_2(osg::Vec3 val)
	Line 1564: void Vehicle::setSternLightPos(osg::Vec3 val)
	Line 1569: void Vehicle::setSternLightDir(osg::Vec3 val)
	Line 1574: void Vehicle::setSailTopPt(osg::Vec3f topPivotPt)
	Line 1580: void Vehicle::setSailBasePt(osg::Vec3f basePivotPt)
	Line 1586: void Vehicle::setBowWakePt(osg::Vec3f wakePivotPt)
	Line 1591: void Vehicle::setBowWakeRightPt(osg::Vec3f wakeRightPivotPt)
	Line 1596: void Vehicle::setBowWakeLeftPt(osg::Vec3f wakeLeftPivotPt)
	Line 1606: void Vehicle::setEyepoint(int scopeNum, osg::Vec3f point)
	Line 1611: void Vehicle::setEdgeBuoyTranslate(const osg::Vec3f& translate)
	Line 1621: void Vehicle::setRudderPosition(osg::Vec3f position)
	Line 1643: void Vehicle::setKnucklePos(osg::Vec3f knucklePos)
	Line 1650: void Vehicle::setWindscreenDrawBox(osg::Group * windscreenDrawBox)
	Line 1655: void Vehicle::setWindscreenDrawBoxBB(osg::BoundingBox windscreenDrawBoxBB)
	Line 1700: osg::Vec3 Vehicle::getMin()
	Line 1705: osg::Vec3 Vehicle::getMax()
	Line 1869: osg::Vec3f Vehicle::getModelOrigin()
	Line 1919: osg::Vec3d Vehicle::getContactLoc()
	Line 1924: osg::Vec3f Vehicle::getContactHPR()
	Line 1969: osg::Vec2d Vehicle::getMovementVector()
	Line 1984: osg::Vec3 Vehicle::getSternLightPos()
	Line 1989: osg::Vec3 Vehicle::getSternLightDir()
	Line 1994: osg::Vec3f Vehicle::getHorizontalLaunchPoint()
	Line 1999: osg::Vec3f Vehicle::getVerticalLaunchPoint()
	Line 2004: osg::Vec3f Vehicle::getBowWakePt()
	Line 2009: osg::Vec3f Vehicle::getBowWakeRightPt()
	Line 2014: osg::Vec3f Vehicle::getBowWakeLeftPt()
	Line 2019: osg::Vec3f Vehicle::getSailTopPt()
	Line 2024: osg::Vec3f Vehicle::getSailBasePt()
	Line 2049: osg::Vec3f Vehicle::getRudderPosition()
	Line 2071: osg::Vec3f Vehicle::getKnucklePos()
	Line 2078: osg::Group * Vehicle::getWindscreenDrawBox()
	Line 2083: osg::BoundingBox Vehicle::getWindscreenDrawBoxBB()
  D:\Development\psim\src\subview\Vehicle.h (99 hits)
	Line 62:     virtual void initHullNumber(osg::Group *hullGrp);
	Line 77:     void addVlsCellLaunchPt(std::string name, osg::Vec3 point);
	Line 78:     void addVlsVentLaunchPt(std::string name, osg::Vec3 point);
	Line 79:     //    void setGWSSmokePt(std::string whichGun, osg::Vec3 point);
	Line 83:     void setHorizontalLaunchPoint(osg::Vec3f launchH);
	Line 84:     void setVerticalLaunchPoint(osg::Vec3f launchV);
	Line 125:     void setLightStateSet(osg::StateSet* ss);
	Line 126:     void setLightGeometry(osg::Geometry* geo);
	Line 127:     void setLightPos_1(osg::Vec3 val);
	Line 128:     void setLightColor_1(osg::Vec3 val);
	Line 129:     void setLightPos_2(osg::Vec3 val);
	Line 130:     void setLightColor_2(osg::Vec3 val);
	Line 131:     void setSternLightPos(osg::Vec3 val);
	Line 132:     void setSternLightDir(osg::Vec3 val);
	Line 133:     void setSailTopPt(osg::Vec3f topPivotPt);
	Line 134:     void setSailBasePt(osg::Vec3f basePivotPt);
	Line 135:     void setBowWakePt(osg::Vec3f wakePivotPt);
	Line 136:     void setBowWakeRightPt(osg::Vec3f wakeRightPivotPt);
	Line 137:     void setBowWakeLeftPt(osg::Vec3f wakeLeftPivotPt);
	Line 139:     void setEyepoint(int scopeNum, osg::Vec3f point);
	Line 140:     void setEdgeBuoyTranslate(const osg::Vec3f& translate);
	Line 142:     void setRudderPosition(osg::Vec3f position);
	Line 148:     void setKnucklePos(osg::Vec3f knucklePos);
	Line 151:     void setWindscreenDrawBox(osg::Group * windscreenDrawBox);
	Line 152:     void setWindscreenDrawBoxBB(osg::BoundingBox windscreenDrawBoxBB);
	Line 163:     void explode(osg::Vec3f offset);
	Line 176:     osg::Vec3 getMin();
	Line 177:     osg::Vec3 getMax();
	Line 212:     osg::Vec3f getModelOrigin();
	Line 222:     osg::Vec3d getContactLoc();
	Line 223:     osg::Vec3f getContactHPR();
	Line 232:     osg::Vec2d getMovementVector();
	Line 235:     osg::Vec3 getSternLightPos();
	Line 236:     osg::Vec3 getSternLightDir();
	Line 237:     osg::Vec3f getHorizontalLaunchPoint();
	Line 238:     osg::Vec3f getVerticalLaunchPoint();
	Line 239:     osg::Vec3f getBowWakePt();
	Line 240:     osg::Vec3f getBowWakeRightPt();
	Line 241:     osg::Vec3f getBowWakeLeftPt();
	Line 242:     osg::Vec3f getSailTopPt();
	Line 243:     osg::Vec3f getSailBasePt();
	Line 248:     osg::Vec3f getRudderPosition();
	Line 254:     osg::Vec3f getKnucklePos();
	Line 257:     osg::Group * getWindscreenDrawBox();
	Line 258:     osg::BoundingBox getWindscreenDrawBoxBB();
	Line 269:     osg::Vec3f getActiveMastLoc();
	Line 273:     osg::Vec3 getVlsCellLaunchPt(int launcherSet, int moduleNumber, int cellNumber);
	Line 274:     osg::Vec3 getVlsVentLaunchPt(int launcherSet, int moduleNumber);
	Line 275:     osg::Vec3 getGWSSmokePt(std::string whichGun);
	Line 286:     osg::ref_ptr<osg::Group> xform;
	Line 286:     osg::ref_ptr<osg::Group> xform;
	Line 288:     osg::ref_ptr<osg::Group> xformBoundingBox;
	Line 288:     osg::ref_ptr<osg::Group> xformBoundingBox;
	Line 290:     osg::ref_ptr<osg::Node> nodeInstance;
	Line 290:     osg::ref_ptr<osg::Node> nodeInstance;
	Line 294:     osg::Vec3 mCameraWorldPos;
	Line 315:     osg::Matrixf* xformMat;
	Line 316:     osg::ref_ptr<osg::Group> mHullGrp;
	Line 316:     osg::ref_ptr<osg::Group> mHullGrp;
	Line 317:     std::vector< std::vector<osg::Vec2Array*> > origTexCoords;
	Line 336:     osg::Vec3 modelOrigin;
	Line 352:     osg::Vec3d contactLoc;
	Line 353:     osg::Vec3f contactHPR;
	Line 354:     osg::Vec3f mEdgeBuoyTranslate;
	Line 370:     osg::Vec2d moveVec;
	Line 371:     osg::Vec2d lastPosition;
	Line 376:     osg::ref_ptr<LightSystemUpdate> mLightSystemUpdate;
	Line 377:     osg::ref_ptr<LightSystemStateSetUpdate> mLightSystemStateSetUpdate;
	Line 378:     osg::ref_ptr<osg::StateSet> mLightStateSet;
	Line 378:     osg::ref_ptr<osg::StateSet> mLightStateSet;
	Line 379:     osg::ref_ptr<osg::Geometry> mLightGeometry;
	Line 379:     osg::ref_ptr<osg::Geometry> mLightGeometry;
	Line 380:     osg::ref_ptr<osg::Uniform> lightPos_1;
	Line 380:     osg::ref_ptr<osg::Uniform> lightPos_1;
	Line 381:     osg::ref_ptr<osg::Uniform> lightColor_1;
	Line 381:     osg::ref_ptr<osg::Uniform> lightColor_1;
	Line 382:     osg::ref_ptr<osg::Uniform> lightPos_2;
	Line 382:     osg::ref_ptr<osg::Uniform> lightPos_2;
	Line 383:     osg::ref_ptr<osg::Uniform> lightColor_2;
	Line 383:     osg::ref_ptr<osg::Uniform> lightColor_2;
	Line 384:     osg::Vec3 sternLightPos;
	Line 385:     osg::Vec3 sternLightDir;
	Line 388:     osg::Vec3 horizontalLaunchPt;
	Line 389:     osg::Vec3 verticalLaunchPt;
	Line 390:     std::map<std::string, osg::Vec3f> vlsCellLaunchPts;
	Line 391:     std::map<std::string, osg::Vec3f> vlsVentLaunchPts;
	Line 392:     osg::Vec3f gwsFrontSmokePt;
	Line 393:     osg::Vec3f gwsRearSmokePt;
	Line 396:     osg::Vec3 bowWakePt;
	Line 397:     osg::Vec3 bowWakeRightPt;
	Line 398:     osg::Vec3 bowWakeLeftPt;
	Line 399:     osg::Vec3 sailTopPt;
	Line 400:     osg::Vec3 sailBasePt;
	Line 401:     std::vector <osg::Vec3f> mScopeEyepoints;
	Line 402:     osg::Vec3f mRudderPosition;
	Line 405:     osg::Vec3f mKnucklePos;
	Line 408:     osg::ref_ptr<osg::Group> mWindscreenDrawBox; //draw box for wind screen values
	Line 408:     osg::ref_ptr<osg::Group> mWindscreenDrawBox; //draw box for wind screen values
	Line 409:     osg::BoundingBox mWindscreenDrawBoxBB;
  D:\Development\psim\src\subview\VehicleVisibilityUpdate.cpp (4 hits)
	Line 22: void VehicleVisibilityUpdate::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 22: void VehicleVisibilityUpdate::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 24:     osg::Switch * visibilitySwitch = dynamic_cast<osg::Switch *> (node);
	Line 24:     osg::Switch * visibilitySwitch = dynamic_cast<osg::Switch *> (node);
  D:\Development\psim\src\subview\VehicleVisibilityUpdate.h (3 hits)
	Line 19: class VehicleVisibilityUpdate : public osg::NodeCallback
	Line 27:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
	Line 27:     virtual void operator()(osg::Node * node, osg::NodeVisitor * nv);
  D:\Development\psim\src\subview\VesubHud.cpp (2 hits)
	Line 51: void VesubHud::drawImplementation(osg::RenderInfo& ri) const
	Line 57: void VesubHud::draw(osg::RenderInfo& ri)
  D:\Development\psim\src\subview\VesubHud.h (2 hits)
	Line 14:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 17:     void draw(osg::RenderInfo& ri);
  D:\Development\psim\src\subview\VesubPickOp.cpp (4 hits)
	Line 23: void VesubPickOp::operator()(osg::Object* obj)
	Line 30:         osg::Node *pNode = new osg::Node();
	Line 30:         osg::Node *pNode = new osg::Node();
	Line 32:         osg::ref_ptr<PickNodeCallback> pickNode = new PickNodeCallback(true);
  D:\Development\psim\src\subview\VesubPickOp.h (2 hits)
	Line 13: class VesubPickOp : public osg::Operation
	Line 19:     void operator()(osg::Object* obj);
  D:\Development\psim\src\subview\VideoShmWriter.cpp (10 hits)
	Line 27: VideoShmWriter::VideoShmWriter(std::string _shm_key, int _width, int _height, osg::Image* imageBuffer, osg::Texture* _fbo_tex) :
	Line 27: VideoShmWriter::VideoShmWriter(std::string _shm_key, int _width, int _height, osg::Image* imageBuffer, osg::Texture* _fbo_tex) :
	Line 492:             osg::ref_ptr<osg::Image> newImage = new osg::Image();
	Line 492:             osg::ref_ptr<osg::Image> newImage = new osg::Image();
	Line 492:             osg::ref_ptr<osg::Image> newImage = new osg::Image();
	Line 493:             newImage->setImage(1280, 1024, 1, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, data, osg::Image::NO_DELETE);
	Line 530:                 osg::ref_ptr<osg::Image> newImage = new osg::Image();
	Line 530:                 osg::ref_ptr<osg::Image> newImage = new osg::Image();
	Line 530:                 osg::ref_ptr<osg::Image> newImage = new osg::Image();
	Line 531:                 newImage->setImage(1280, 1024, 1, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, data, osg::Image::NO_DELETE);
  D:\Development\psim\src\subview\VideoShmWriter.h (5 hits)
	Line 25:     VideoShmWriter(std::string _shm_key, int _width, int _height, osg::Image* imageBuffer = NULL, osg::Texture* _fbo_tex = NULL);
	Line 25:     VideoShmWriter(std::string _shm_key, int _width, int _height, osg::Image* imageBuffer = NULL, osg::Texture* _fbo_tex = NULL);
	Line 103:     osg::Image* mImageBuffer;
	Line 104:     osg::ref_ptr<osg::Texture> fboTex;
	Line 104:     osg::ref_ptr<osg::Texture> fboTex;
  D:\Development\psim\src\subview\ViewSpec.cpp (40 hits)
	Line 234:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 234:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 234:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 234:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 235:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 235:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 235:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 235:     for (ii = 0; ii < 4; ++ii) mBase[ii] = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 238:         mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mBase[ii];
	Line 238:         mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mBase[ii];
	Line 238:         mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mBase[ii];
	Line 238:         mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mBase[ii];
	Line 256:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 256:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 256:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 256:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI / 180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 257:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 257:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 257:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 257:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, mRotXYZ[1] * M_PI / 180, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 259:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 259:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 259:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 259:     for (ii = 0; ii < 6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI / 180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 269:         for (ii=0; ii<4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 269:         for (ii=0; ii<4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 269:         for (ii=0; ii<4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 269:         for (ii=0; ii<4; ++ii) mBase[ii] = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mBase[ii];
	Line 272:             mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mBase[ii];
	Line 272:             mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mBase[ii];
	Line 272:             mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mBase[ii];
	Line 272:             mBase[ii] = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mBase[ii];
	Line 295:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 295:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 295:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 295:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(mRotXYZ[0] * M_PI/180, osg::X_AXIS, 0.0, osg::Y_AXIS, 0.0, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 297:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 297:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 297:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mPlanes[ii].ABC;
	Line 297:         for (ii=0; ii<6; ++ii) mPlanes[ii].ABC = osg::Quat(0.0, osg::X_AXIS, 0.0, osg::Y_AXIS, mRotXYZ[2] * M_PI/180, osg::Z_AXIS) * mPlanes[ii].ABC;
  D:\Development\psim\src\subview\ViewSpec.h (2 hits)
	Line 58:     osg::Vec3f mApex;
	Line 59:     osg::Vec3f mBase[4];
  D:\Development\psim\src\subview\ViewSpecPlane.h (1 hit)
	Line 14:     osg::Vec3f ABC;
  D:\Development\psim\src\subview\VlsAnimator.cpp (4 hits)
	Line 51:         osg::Vec3 position = vehicle->getVlsVentLaunchPt(cellSet, moduleNumber);
	Line 57:         params.setGeomDimensions(osg::Vec2(30, 30));
	Line 69:         params.setOrientation(osg::Vec3(0, 0, -90 * (M_PI / 180)));
	Line 73:         params.setOrientation(osg::Vec3(0, 0, 90 * (M_PI / 180)));
  D:\Development\psim\src\subview\VlsHatch.cpp (17 hits)
	Line 20: VlsHatch::VlsHatch(Vehicle* vehicle, osg::Geode* node) :
	Line 58:     osg::Vec3f position(node->computeBound().center());
	Line 59:     const osg::Vec3Array * normals = dynamic_cast<const osg::Vec3Array*> (dynamic_cast<osg::Geometry*> (node->getDrawable(0))->getNormalArray());
	Line 59:     const osg::Vec3Array * normals = dynamic_cast<const osg::Vec3Array*> (dynamic_cast<osg::Geometry*> (node->getDrawable(0))->getNormalArray());
	Line 59:     const osg::Vec3Array * normals = dynamic_cast<const osg::Vec3Array*> (dynamic_cast<osg::Geometry*> (node->getDrawable(0))->getNormalArray());
	Line 60:     osg::Vec3f orientation((*normals)[0].x(), (*normals)[0].y(), (*normals)[0].z());
	Line 63:     mPutMatrix = osg::Matrix::translate(-position) * osg::Matrix::rotate(orientation, osg::Vec3f(-1, 0, 0));
	Line 63:     mPutMatrix = osg::Matrix::translate(-position) * osg::Matrix::rotate(orientation, osg::Vec3f(-1, 0, 0));
	Line 63:     mPutMatrix = osg::Matrix::translate(-position) * osg::Matrix::rotate(orientation, osg::Vec3f(-1, 0, 0));
	Line 66:     mInvPutMatrix = osg::Matrix::rotate(osg::Vec3f(-1, 0, 0), orientation) * osg::Matrix::translate(position);
	Line 66:     mInvPutMatrix = osg::Matrix::rotate(osg::Vec3f(-1, 0, 0), orientation) * osg::Matrix::translate(position);
	Line 66:     mInvPutMatrix = osg::Matrix::rotate(osg::Vec3f(-1, 0, 0), orientation) * osg::Matrix::translate(position);
	Line 69: void VlsHatch::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 69: void VlsHatch::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 101:     osg::Matrix mTransform;
	Line 107:     mTransform.postMult(osg::Matrix::rotate(M_PI / 180.0 * (angle), 0.f, 1.f, 0.f));
	Line 112:     dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
  D:\Development\psim\src\subview\VlsHatch.h (6 hits)
	Line 16: class VlsHatch : public osg::NodeCallback
	Line 26:     VlsHatch(Vehicle* vehicle, osg::Geode* node);
	Line 32:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 32:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 40:     osg::Matrix mPutMatrix;
	Line 41:     osg::Matrix mInvPutMatrix;
  D:\Development\psim\src\subview\VlsVent.cpp (17 hits)
	Line 20: VlsVent::VlsVent(Vehicle* vehicle, osg::Geode* node) :
	Line 54:     osg::Vec3f position(node->computeBound().center());
	Line 55:     const osg::Vec3Array * normals = dynamic_cast<const osg::Vec3Array*> (dynamic_cast<osg::Geometry*> (node->getDrawable(0))->getNormalArray());
	Line 55:     const osg::Vec3Array * normals = dynamic_cast<const osg::Vec3Array*> (dynamic_cast<osg::Geometry*> (node->getDrawable(0))->getNormalArray());
	Line 55:     const osg::Vec3Array * normals = dynamic_cast<const osg::Vec3Array*> (dynamic_cast<osg::Geometry*> (node->getDrawable(0))->getNormalArray());
	Line 56:     osg::Vec3f orientation((*normals)[0].x(), (*normals)[0].y(), (*normals)[0].z());
	Line 59:     mPutMatrix = osg::Matrix::translate(-position) * osg::Matrix::rotate(orientation, osg::Vec3f(-1, 0, 0));
	Line 59:     mPutMatrix = osg::Matrix::translate(-position) * osg::Matrix::rotate(orientation, osg::Vec3f(-1, 0, 0));
	Line 59:     mPutMatrix = osg::Matrix::translate(-position) * osg::Matrix::rotate(orientation, osg::Vec3f(-1, 0, 0));
	Line 61:     mInvPutMatrix = osg::Matrix::rotate(osg::Vec3f(-1, 0, 0), orientation) * osg::Matrix::translate(position);
	Line 61:     mInvPutMatrix = osg::Matrix::rotate(osg::Vec3f(-1, 0, 0), orientation) * osg::Matrix::translate(position);
	Line 61:     mInvPutMatrix = osg::Matrix::rotate(osg::Vec3f(-1, 0, 0), orientation) * osg::Matrix::translate(position);
	Line 64: void VlsVent::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 64: void VlsVent::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 101:     osg::Matrix mTransform;
	Line 108:     mTransform.postMult(osg::Matrix::rotate(M_PI / 180.0 * (angle), 0.f, 1.f, 0.f));
	Line 113:     dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
  D:\Development\psim\src\subview\VlsVent.h (6 hits)
	Line 16: class VlsVent : public osg::NodeCallback
	Line 26:     VlsVent(Vehicle* vehicle, osg::Geode* node);
	Line 32:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 32:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 42:     osg::Matrix mPutMatrix;
	Line 43:     osg::Matrix mInvPutMatrix;
  D:\Development\psim\src\subview\Wake.cpp (65 hits)
	Line 56: Wake::Wake(Vehicle *assocVehicle, osg::Vec3 min, osg::Vec3 max, WakeType wakeType, bool wakeIsIR, bool wakeIsBacking) :
	Line 56: Wake::Wake(Vehicle *assocVehicle, osg::Vec3 min, osg::Vec3 max, WakeType wakeType, bool wakeIsIR, bool wakeIsBacking) :
	Line 59: normals(new osg::Vec3Array),
	Line 60: baseColors(new osg::Vec4Array),
	Line 61: baseCoords(new osg::Vec3Array),
	Line 62: baseCoordsCopy(new osg::Vec3Array),
	Line 63: baseTexCoords0(new osg::Vec2Array),
	Line 64: baseTexCoords1(new osg::Vec2Array),
	Line 65: tailColors(new osg::Vec4Array),
	Line 66: tailCoords(new osg::Vec3Array),
	Line 67: tailTexCoords(new osg::Vec2Array),
	Line 173:     curTailXYZ = osg::Vec3(xVal, yVal, zVal);
	Line 174:     storedTailXYZ = osg::Vec3(xVal, yVal, zVal);
	Line 206: void Wake::removeWake(osg::Group *root)
	Line 440:     curXYZ = osg::Vec3(subData->XYZ[0], subData->XYZ[1], subData->XYZ[2]);
	Line 441:     curTailXYZ = osg::Vec3(subData->XYZ[0] - X, subData->XYZ[1] + Y, subData->XYZ[2]);
	Line 542:     osg::Vec3 tmpVec3;
	Line 543:     osg::Matrixf multMat;
	Line 575:         osg::Vec3f coordsPosFront = (*baseCoordsCopy)[0];
	Line 576:         osg::Vec3f coordsPosBack = (*baseCoordsCopy)[1];
	Line 640:     osg::Matrixf wakePos;
	Line 642:     osg::Vec3 wakeTrans((float) curTailXYZ[0], (float) curTailXYZ[1], 0.f);
	Line 850: void Wake::manipMatrix(osg::Matrixf &res, float X, float Y, float H)
	Line 852:     osg::Matrixf rot = osg::Matrix::rotate(osg::inDegrees(H), 0.0f, 0.0f, 1.0f);
	Line 852:     osg::Matrixf rot = osg::Matrix::rotate(osg::inDegrees(H), 0.0f, 0.0f, 1.0f);
	Line 852:     osg::Matrixf rot = osg::Matrix::rotate(osg::inDegrees(H), 0.0f, 0.0f, 1.0f);
	Line 952:     osg::Matrixf wakePos;
	Line 954:     osg::Vec3 wakeTrans((float) curTailXYZ[0], (float) curTailXYZ[1], 0.f);
	Line 984:     (*normals)[0] = osg::Vec3(0.0f, 0.0f, 1.0f);
	Line 1007: void Wake::addWakeToOSG(osg::Group * root)
	Line 1009:     osg::ref_ptr<ProjWakeGeometry> projWakeGeom = getProjWakeGeom();
	Line 1010:     osg::ref_ptr<osg::Geode> projWakeGeode = getProjWakeGeode();
	Line 1010:     osg::ref_ptr<osg::Geode> projWakeGeode = getProjWakeGeode();
	Line 1016: void Wake::removeWakeFromOSG(osg::Group * root)
	Line 1023: osg::Texture* Wake::createProjTexture(int width, int height)
	Line 1025:     osg::Texture2D* texture = new osg::Texture2D();
	Line 1025:     osg::Texture2D* texture = new osg::Texture2D();
	Line 1029:     texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
	Line 1029:     texture->setFilter(osg::Texture::MIN_FILTER, osg::Texture::LINEAR);
	Line 1030:     texture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
	Line 1030:     texture->setFilter(osg::Texture::MAG_FILTER, osg::Texture::LINEAR);
	Line 1031:     texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_BORDER);
	Line 1031:     texture->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP_TO_BORDER);
	Line 1032:     texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER);
	Line 1032:     texture->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP_TO_BORDER);
	Line 1033:     texture->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_BORDER);
	Line 1033:     texture->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP_TO_BORDER);
	Line 1034:     texture->setBorderColor(osg::Vec4(0., 0., 0., 0.));
	Line 1054:     osg::Vec3f contactLoc = mVehicle->getContactLoc();
	Line 1072:     osg::Vec3f bowWakePt = mVehicle->getBowWakePt();
	Line 1081:         osg::Vec3f curActiveMastLoc = mVehicle->getActiveMastLoc();
	Line 1087:         osg::Vec3f sailWakePt = mVehicle->getSailTopPt();
	Line 1130:     osg::Vec3f backingWakePt;
	Line 1331:         geo->lees_nearWakePosUniform->setElement(index, osg::Vec4f(dynWake_origin[0], dynWake_origin[1], dynWake_origin[2], dynWake_origin[3]));
	Line 1332:         geo->lees_nearWakeDirSizeUniform->setElement(index, osg::Vec4f(dynWake_dirSize[0], dynWake_dirSize[1], dynWake_dirSize[2], dynWake_dirSize[3]));
	Line 1334:         geo->lees_nearWakeFalloffsAftUniform->set(osg::Vec4f(wakeFalloffsAft[0], wakeFalloffsAft[1], wakeFalloffsAft[2], wakeFalloffsAft[3]));
	Line 1345: osg::Vec2f Wake::getDynWakePos() const
	Line 1347:     return osg::Vec2f(dynWake_origin[0], dynWake_origin[1]);
	Line 1365: osg::ref_ptr<ProjWakeGeometry> Wake::getProjWakeGeom()
	Line 1367:     static osg::ref_ptr<ProjWakeGeometry> wakeGeom = new ProjWakeGeometry; // singleton
	Line 1371: osg::ref_ptr<osg::Geode> Wake::getProjWakeGeode()
	Line 1371: osg::ref_ptr<osg::Geode> Wake::getProjWakeGeode()
	Line 1373:     static osg::ref_ptr<osg::Geode> geode = new osg::Geode; // singleton
	Line 1373:     static osg::ref_ptr<osg::Geode> geode = new osg::Geode; // singleton
	Line 1373:     static osg::ref_ptr<osg::Geode> geode = new osg::Geode; // singleton
  D:\Development\psim\src\subview\Wake.h (45 hits)
	Line 37:     osg::ref_ptr<osg::Vec3Array> normals;
	Line 37:     osg::ref_ptr<osg::Vec3Array> normals;
	Line 41:     osg::ref_ptr<osg::Vec4Array> baseColors;
	Line 41:     osg::ref_ptr<osg::Vec4Array> baseColors;
	Line 42:     osg::ref_ptr<osg::Vec3Array> baseCoords;
	Line 42:     osg::ref_ptr<osg::Vec3Array> baseCoords;
	Line 43:     osg::ref_ptr<osg::Vec3Array> baseCoordsCopy;
	Line 43:     osg::ref_ptr<osg::Vec3Array> baseCoordsCopy;
	Line 44:     osg::ref_ptr<osg::Vec2Array> baseTexCoords0;
	Line 44:     osg::ref_ptr<osg::Vec2Array> baseTexCoords0;
	Line 45:     osg::ref_ptr<osg::Vec2Array> baseTexCoords1;
	Line 45:     osg::ref_ptr<osg::Vec2Array> baseTexCoords1;
	Line 49:     osg::ref_ptr<osg::Vec4Array> tailColors;
	Line 49:     osg::ref_ptr<osg::Vec4Array> tailColors;
	Line 50:     osg::ref_ptr<osg::Vec3Array> tailCoords;
	Line 50:     osg::ref_ptr<osg::Vec3Array> tailCoords;
	Line 51:     osg::ref_ptr<osg::Vec2Array> tailTexCoords;
	Line 51:     osg::ref_ptr<osg::Vec2Array> tailTexCoords;
	Line 53:     osg::Vec2d oldLatLon;
	Line 55:     osg::Vec3f dimensions;
	Line 56:     osg::Vec3f vehicleMin;
	Line 57:     osg::Vec3f vehicleMax;
	Line 58:     osg::Vec3f curXYZ;
	Line 59:     osg::Vec3f curTailXYZ;
	Line 60:     osg::Vec3f storedTailXYZ;
	Line 61:     osg::Vec3f oldXYZ;
	Line 62:     osg::Vec3f storedXYZ;
	Line 63:     osg::Vec3f pivotOffset;
	Line 64:     osg::Vec3f deltaWorldCenter;
	Line 65:     osg::BoundingBox bbox;
	Line 130:     void manipMatrix(osg::Matrixf &res, float X, float Y, float H);
	Line 135:     osg::Vec2f getDynWakePos() const;
	Line 174:     void removeWake(osg::Group *root);
	Line 176:     void reconstruct(ObjectData *subCurData, osg::Vec3f &min, osg::Vec3f &max, int id, int wakeType);
	Line 176:     void reconstruct(ObjectData *subCurData, osg::Vec3f &min, osg::Vec3f &max, int id, int wakeType);
	Line 187:     Wake(Vehicle *assocVehicle, osg::Vec3 min, osg::Vec3 max, WakeType wakeType, bool wakeIsIR, bool wakeIsBacking);
	Line 187:     Wake(Vehicle *assocVehicle, osg::Vec3 min, osg::Vec3 max, WakeType wakeType, bool wakeIsIR, bool wakeIsBacking);
	Line 191:     static void addWakeToOSG(osg::Group *root);
	Line 192:     void removeWakeFromOSG(osg::Group *root);
	Line 198:     static osg::ref_ptr<ProjWakeGeometry> getProjWakeGeom();
	Line 200:     static osg::ref_ptr<osg::Geode> getProjWakeGeode();
	Line 200:     static osg::ref_ptr<osg::Geode> getProjWakeGeode();
	Line 202:     osg::Texture* createProjTexture(int width, int height);
	Line 236:     osg::ref_ptr<osg::Uniform> mLightCoeffUniform;
	Line 236:     osg::ref_ptr<osg::Uniform> mLightCoeffUniform;
  D:\Development\psim\src\subview\WakeCallback.cpp (10 hits)
	Line 22: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 22: extern osg::ref_ptr<osg::Camera> mainCamera;
	Line 30: void WakeCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 30: void WakeCallback::operator()(osg::Node *node, osg::NodeVisitor *nv)
	Line 140:         osg::Vec2 dXY = contact->getMovementVector();
	Line 213:     osg::Vec3f cameraPos, lookAt, up, buoyXYZ;
	Line 217:     osg::Vec2f viewdir = osg::Vec2f(lookAt[0] - cameraPos[0], lookAt[1] - cameraPos[1]);
	Line 217:     osg::Vec2f viewdir = osg::Vec2f(lookAt[0] - cameraPos[0], lookAt[1] - cameraPos[1]);
	Line 218:     osg::Vec2f buoypos = osg::Vec2f(buoyXYZ[0], buoyXYZ[1]);
	Line 218:     osg::Vec2f buoypos = osg::Vec2f(buoyXYZ[0], buoyXYZ[1]);
  D:\Development\psim\src\subview\WakeCallback.h (3 hits)
	Line 13: class WakeCallback : public osg::NodeCallback
	Line 17:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
	Line 17:     virtual void operator()(osg::Node *node, osg::NodeVisitor *nv);
  D:\Development\psim\src\subview\WakeManager.cpp (7 hits)
	Line 121: void WakeManager::setWakeCallback(osg::ref_ptr<osg::Group> root)
	Line 121: void WakeManager::setWakeCallback(osg::ref_ptr<osg::Group> root)
	Line 186:         osg::Vec4 falloffs = osg::Vec4(
	Line 186:         osg::Vec4 falloffs = osg::Vec4(
	Line 279:         bowWakeScale = osg::clampBetween(bowWakeScale, 0.0, 1.0);
	Line 340:     maxBowHeight = osg::clampBelow(maxBowHeight, 125.0);
	Line 343:     speed = osg::clampBelow(static_cast<double> (speed), 20.0);
  D:\Development\psim\src\subview\WakeManager.h (5 hits)
	Line 44:     osg::ref_ptr<osg::Group> wakesGrp;
	Line 44:     osg::ref_ptr<osg::Group> wakesGrp;
	Line 53:     void setWakeCallback(osg::ref_ptr<osg::Group> root);
	Line 53:     void setWakeCallback(osg::ref_ptr<osg::Group> root);
	Line 56:     void addWakeToOSG(osg::Group * root);
  D:\Development\psim\src\subview\WashOver.cpp (26 hits)
	Line 26: WashOver::WashOver(osg::Group * root) :
	Line 37:     mTextureRect = new osg::TextureRectangle;
	Line 40:     mTextureRect->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 40:     mTextureRect->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR);
	Line 41:     mTextureRect->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 41:     mTextureRect->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 44:     osg::Geode* geode = new osg::Geode();
	Line 44:     osg::Geode* geode = new osg::Geode();
	Line 47:     mQuadSwitch = new osg::Switch;
	Line 72:         mWashMap[ii] = new osg::Texture2D;
	Line 75:         //mWashMap[ii]->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 75:         //mWashMap[ii]->setWrap(osg::Texture::WRAP_S, osg::Texture::CLAMP);
	Line 76:         //mWashMap[ii]->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 76:         //mWashMap[ii]->setWrap(osg::Texture::WRAP_T, osg::Texture::CLAMP);
	Line 77:         //mWashMap[ii]->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP);
	Line 77:         //mWashMap[ii]->setWrap(osg::Texture::WRAP_R, osg::Texture::CLAMP);
	Line 78:         mWashMap[ii]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 78:         mWashMap[ii]->setWrap(osg::Texture::WRAP_S, osg::Texture::REPEAT);
	Line 79:         mWashMap[ii]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 79:         mWashMap[ii]->setWrap(osg::Texture::WRAP_T, osg::Texture::REPEAT);
	Line 80:         mWashMap[ii]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 80:         mWashMap[ii]->setWrap(osg::Texture::WRAP_R, osg::Texture::REPEAT);
	Line 81:         mWashMap[ii]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 81:         mWashMap[ii]->setFilter(osg::Texture2D::MIN_FILTER, osg::Texture2D::LINEAR_MIPMAP_LINEAR);
	Line 82:         mWashMap[ii]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
	Line 82:         mWashMap[ii]->setFilter(osg::Texture2D::MAG_FILTER, osg::Texture2D::LINEAR);
  D:\Development\psim\src\subview\WashOver.h (10 hits)
	Line 16:     WashOver(osg::Group * root);
	Line 25:     osg::ref_ptr<osg::Image> mWashMapImage[180];
	Line 25:     osg::ref_ptr<osg::Image> mWashMapImage[180];
	Line 26:     osg::ref_ptr<osg::Texture2D>mWashMap[180];
	Line 26:     osg::ref_ptr<osg::Texture2D>mWashMap[180];
	Line 27:     osg::ref_ptr<WashOverQuad> mQuad;
	Line 28:     osg::ref_ptr<osg::Switch> mQuadSwitch;
	Line 28:     osg::ref_ptr<osg::Switch> mQuadSwitch;
	Line 30:     osg::ref_ptr<osg::TextureRectangle> mTextureRect;
	Line 30:     osg::ref_ptr<osg::TextureRectangle> mTextureRect;
  D:\Development\psim\src\subview\WashOverQuad.cpp (38 hits)
	Line 37: WashOverQuad::WashOverQuad(osg::Texture2D *_WasMap, osg::TextureRectangle *_textureRect)
	Line 37: WashOverQuad::WashOverQuad(osg::Texture2D *_WasMap, osg::TextureRectangle *_textureRect)
	Line 40:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-1.0, 1.0, -1.0, 1.0, -50.0, 50.0));
	Line 40:     sProjectionMatrix = new osg::RefMatrix(osg::Matrix::ortho(-1.0, 1.0, -1.0, 1.0, -50.0, 50.0));
	Line 41:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 41:     sModelviewMatrix = new osg::RefMatrix(osg::Matrixf::identity());
	Line 46:     stateSet = new osg::StateSet;
	Line 48:     stateSet->setTextureAttributeAndModes(0, WasMap, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 48:     stateSet->setTextureAttributeAndModes(0, WasMap, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 49:     stateSet->setTextureAttributeAndModes(1, textureRect, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 49:     stateSet->setTextureAttributeAndModes(1, textureRect, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 50:     stateSet->addUniform(new osg::Uniform("washMap", 0));
	Line 51:     stateSet->addUniform(new osg::Uniform("washScene", 1));
	Line 53:     invScreenWidthHeightUniform = new osg::Uniform("invScreenWidthHeight", osg::Vec2(1.f / SubviewConfig::winWidth, 1.f / SubviewConfig::winHeight));
	Line 53:     invScreenWidthHeightUniform = new osg::Uniform("invScreenWidthHeight", osg::Vec2(1.f / SubviewConfig::winWidth, 1.f / SubviewConfig::winHeight));
	Line 56:     fadeUniform = new osg::Uniform("fade", 1.f);
	Line 58:     randOffUniform = new osg::Uniform("randOff", 0.f);
	Line 61:     oceanColorOffsetUniform = new osg::Uniform("oceanColorOffset", osg::Vec3(1.0, 1.0, 1.0));
	Line 61:     oceanColorOffsetUniform = new osg::Uniform("oceanColorOffset", osg::Vec3(1.0, 1.0, 1.0));
	Line 62:     lightCoeffUniform = new osg::Uniform("lightCoeff", 0.0f);
	Line 70:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 70:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 70:     osg::ref_ptr<osg::Program> program = new osg::Program;
	Line 72:     program->addShader(ShaderMaster::getInstance().createShader(osg::Shader::FRAGMENT, "washoverFrag.glsl"));
	Line 73:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 73:     stateSet->setAttributeAndModes(program.get(), osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 74:     stateSet->setRenderingHint(osg::StateSet::TRANSPARENT_BIN);
	Line 78: void WashOverQuad::drawImplementation(osg::RenderInfo& ri) const
	Line 84:     osg::Texture::TextureObject* textureObject = textureRect->getTextureObject(0);
	Line 125: osg::BoundingBox WashOverQuad::computeBound() const
	Line 127:     osg::BoundingBox bbox;
	Line 128:     bbox.expandBy(osg::Vec3(-10000.f, -10000.f, -10000.f));
	Line 129:     bbox.expandBy(osg::Vec3(10000.f, 10000.f, 10000.f));
	Line 141: void WashOverQuad::setWashMap(osg::Texture2D *map, float fade)
	Line 143:     invScreenWidthHeightUniform->set(osg::Vec2(1.f / SubviewConfig::winWidth, 1.f / SubviewConfig::winHeight));
	Line 146:     oceanColorOffsetUniform->set(osg::Vec3((float) Shared->ocData.offsetcolor.Red / 255.0, (float) Shared->ocData.offsetcolor.Green / 255.0, (float) Shared->ocData.offsetcolor.Blue / 255.0));
	Line 149:     stateSet->setTextureAttributeAndModes(0, map, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
	Line 149:     stateSet->setTextureAttributeAndModes(0, map, osg::StateAttribute::ON | osg::StateAttribute::OVERRIDE);
  D:\Development\psim\src\subview\WashOverQuad.h (27 hits)
	Line 24: class WashOverQuad : public osg::Geometry
	Line 29:     WashOverQuad(const WashOverQuad& WashOverQuad, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 29:     WashOverQuad(const WashOverQuad& WashOverQuad, const osg::CopyOp& copyop = osg::CopyOp::SHALLOW_COPY) :
	Line 30:     osg::Geometry(WashOverQuad, copyop)
	Line 37:     WashOverQuad(osg::Texture2D *_WasMap, osg::TextureRectangle *_textureRect);
	Line 37:     WashOverQuad(osg::Texture2D *_WasMap, osg::TextureRectangle *_textureRect);
	Line 38:     virtual void drawImplementation(osg::RenderInfo& ri) const;
	Line 39:     virtual osg::BoundingBox computeBound() const;
	Line 41:     void setWashMap(osg::Texture2D *map, float fade);
	Line 49:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 49:     osg::ref_ptr<osg::RefMatrix> sProjectionMatrix;
	Line 50:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 50:     osg::ref_ptr<osg::RefMatrix> sModelviewMatrix;
	Line 51:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 51:     osg::ref_ptr<osg::StateSet> stateSet;
	Line 52:     osg::ref_ptr<osg::Uniform> invScreenWidthHeightUniform;
	Line 52:     osg::ref_ptr<osg::Uniform> invScreenWidthHeightUniform;
	Line 53:     osg::ref_ptr<osg::Uniform> fadeUniform;
	Line 53:     osg::ref_ptr<osg::Uniform> fadeUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> randOffUniform;
	Line 54:     osg::ref_ptr<osg::Uniform> randOffUniform;
	Line 55:     osg::ref_ptr<osg::Uniform> oceanColorOffsetUniform;
	Line 55:     osg::ref_ptr<osg::Uniform> oceanColorOffsetUniform;
	Line 56:     osg::ref_ptr<osg::Uniform> lightCoeffUniform;
	Line 56:     osg::ref_ptr<osg::Uniform> lightCoeffUniform;
	Line 58:     osg::Texture2D *WasMap;
	Line 59:     osg::TextureRectangle *textureRect;
  D:\Development\psim\src\subview\WaveHeightApp.cpp (1 hit)
	Line 29: osg::Image* WaveHeightApp::getHeightImage()
  D:\Development\psim\src\subview\WaveHeightApp.h (2 hits)
	Line 21:     osg::Image* getHeightImage();
	Line 28:     osg::Image* mpHeightImageApp;
  D:\Development\psim\src\subview\WaveHeightBase.cpp (6 hits)
	Line 39:             mHeightImages[ii][jj] = new osg::Image;
	Line 68: float WaveHeightBase::getHeight(float *xyz, osg::Image& heightImage) const
	Line 71:     osg::Vec2f viewOrigin(Shared->viewOrigin[0], Shared->viewOrigin[1]);
	Line 72:     osg::Vec2f glVertex(xyz[0], xyz[1]);
	Line 73:     osg::Vec2f coord = viewOrigin + glVertex;
	Line 75:     osg::Vec2f uv = coord * IFFT_SIZE_INV;
  D:\Development\psim\src\subview\WaveHeightBase.h (3 hits)
	Line 23:     float getHeight(float *xyz, osg::Image& heightImage) const;
	Line 34:     osg::ref_ptr<osg::Image> mHeightImages[3][NUM_READERS + 2];
	Line 34:     osg::ref_ptr<osg::Image> mHeightImages[3][NUM_READERS + 2];
  D:\Development\psim\src\subview\WaveHeightCreate.cpp (7 hits)
	Line 97: osg::Image* WaveHeightCreate::getHeightImage() const
	Line 216: float WaveHeightCreate::phillipsSpectrum(const osg::Vec2f& K)
	Line 223:     float KdotW = K * osg::Vec2f(1.f, 0.f); // K*mWindDir;
	Line 309:     osg::Vec2f K;
	Line 353:     osg::Vec2f K;
	Line 354:     osg::Vec2f Kh0(0, 0);
	Line 500:     osg::Image* height_image = getHeightImage();
  D:\Development\psim\src\subview\WaveHeightCreate.h (5 hits)
	Line 27:     osg::Image* getHeightImage() const;
	Line 34:     osg::Image* mpHeightImageCreate;
	Line 44:     float phillipsSpectrum(const osg::Vec2f& K);
	Line 75:     std::vector< osg::Vec2f > Kh;
	Line 101:     //	osg::Vec2f mWindDir;
  D:\Development\psim\src\subview\WaveHeightUpdate.cpp (1 hit)
	Line 31: osg::Image* WaveHeightUpdate::getHeightImage()
  D:\Development\psim\src\subview\WaveHeightUpdate.h (2 hits)
	Line 21:     osg::Image* getHeightImage();
	Line 31:     osg::Image* mpHeightImageUpdate;
  D:\Development\psim\src\subview\WindscreenDisplay.cpp (13 hits)
	Line 23: WindscreenDisplay::WindscreenDisplay(osg::BoundingBox boundingBox, osg::ref_ptr<osg::Group> drawBox) :
	Line 23: WindscreenDisplay::WindscreenDisplay(osg::BoundingBox boundingBox, osg::ref_ptr<osg::Group> drawBox) :
	Line 23: WindscreenDisplay::WindscreenDisplay(osg::BoundingBox boundingBox, osg::ref_ptr<osg::Group> drawBox) :
	Line 34:     osg::Vec3 upperLeftCorner = mBoundingBox.corner(6);
	Line 45:     osg::Vec3 windscreenColor;
	Line 49:         windscreenColor = osg::Vec3(atoi(getenv("WINDSCREEN_TEXT_RED")),
	Line 64:             mWindscreenGeode = new osg::Geode();
	Line 67:             mWindscreenGeode->getOrCreateStateSet()->setAttributeAndModes(new osg::Program(),
	Line 68:                     osg::StateAttribute::ON | osg::StateAttribute::PROTECTED);
	Line 68:                     osg::StateAttribute::ON | osg::StateAttribute::PROTECTED);
	Line 75:             mWindscreenText[row][column]->getOrCreateStateSet()->setDataVariance(osg::Object::DYNAMIC);
	Line 80:             mWindscreenText[row][column]->setColor(osg::Vec4(windscreenColor[0] / 255.f,
	Line 87:             osg::Vec3 position = upperLeftCorner;
  D:\Development\psim\src\subview\WindscreenDisplay.h (9 hits)
	Line 15:     WindscreenDisplay(osg::BoundingBox boundingBox, osg::ref_ptr<osg::Group> drawBox);
	Line 15:     WindscreenDisplay(osg::BoundingBox boundingBox, osg::ref_ptr<osg::Group> drawBox);
	Line 15:     WindscreenDisplay(osg::BoundingBox boundingBox, osg::ref_ptr<osg::Group> drawBox);
	Line 24:     osg::BoundingBox mBoundingBox;
	Line 25:     osg::ref_ptr<osg::Group> mDrawBox;
	Line 25:     osg::ref_ptr<osg::Group> mDrawBox;
	Line 26:     osg::ref_ptr<osgText::Text> mWindscreenText[ROW_COUNT][COLUMN_COUNT];
	Line 28:     osg::ref_ptr<osg::Geode> mWindscreenGeode;
	Line 28:     osg::ref_ptr<osg::Geode> mWindscreenGeode;
  D:\Development\psim\src\subview\WindscreenUpdateCallback.cpp (4 hits)
	Line 24: void WindscreenUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 24: void WindscreenUpdateCallback::operator()(osg::Node* node, osg::NodeVisitor* nv)
	Line 26:     osg::Geode* geode = dynamic_cast<osg::Geode*> (node);
	Line 26:     osg::Geode* geode = dynamic_cast<osg::Geode*> (node);
  D:\Development\psim\src\subview\WindscreenUpdateCallback.h (3 hits)
	Line 16: class WindscreenUpdateCallback : public osg::NodeCallback
	Line 23:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
	Line 23:     virtual void operator()(osg::Node* node, osg::NodeVisitor* nv);
  D:\Development\psim\src\subview\XFormNodeCallback.cpp (11 hits)
	Line 47: XFormNodeCallback::XFormNodeCallback(int contactId, QueryContacts::MastAttribs attribs, osg::Vec3f mastWakePos, osg::Geode * node, Vehicle *vehicle, bool isLightMast)
	Line 47: XFormNodeCallback::XFormNodeCallback(int contactId, QueryContacts::MastAttribs attribs, osg::Vec3f mastWakePos, osg::Geode * node, Vehicle *vehicle, bool isLightMast)
	Line 61:     osg::Vec3f position(node->computeBound().center());
	Line 62:     mPutMatrix = osg::Matrix::translate(-position);
	Line 63:     mInvPutMatrix = osg::Matrix::translate(position);
	Line 94: void XFormNodeCallback::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 94: void XFormNodeCallback::operator()(osg::Node * node, osg::NodeVisitor * nv)
	Line 126:         osg::Matrixf trans = osg::Matrixf::translate(0.f, 0.f, mHeight);
	Line 126:         osg::Matrixf trans = osg::Matrixf::translate(0.f, 0.f, mHeight);
	Line 129:         dynamic_cast<osg::MatrixTransform *> (node)->setMatrix(mTransform);
	Line 217: osg::Vec3f XFormNodeCallback::getActiveMastLoc()
  D:\Development\psim\src\subview\XFormNodeCallback.h (10 hits)
	Line 24: class XFormNodeCallback : public osg::NodeCallback
	Line 27:     XFormNodeCallback(int, QueryContacts::MastAttribs, osg::Vec3f, osg::Geode *, Vehicle *, bool isLightMast);
	Line 27:     XFormNodeCallback(int, QueryContacts::MastAttribs, osg::Vec3f, osg::Geode *, Vehicle *, bool isLightMast);
	Line 29:     virtual void operator()(osg::Node *, osg::NodeVisitor *);
	Line 29:     virtual void operator()(osg::Node *, osg::NodeVisitor *);
	Line 41:     osg::Vec3f getActiveMastLoc();
	Line 46:     osg::Matrix mPutMatrix; // puts back to world origin
	Line 47:     osg::Matrix mInvPutMatrix; // puts back to local origin
	Line 48:     osg::Matrix mTransform; // local transformation
	Line 58:     osg::Vec3f activeMastLoc;
Search "osg::" (0 hits in 0 files)
Search "OpenThreads::" (67 hits in 18 files)
  D:\Development\psim\src\subview\EffectsManager.h (1 hit)
	Line 134:     OpenThreads::Mutex rootUpdateMutex;
  D:\Development\psim\src\subview\GameBoard.cpp (16 hits)
	Line 65:     OpenThreads::ScopedLock<OpenThreads::Mutex> mlock(backgroundVehicleDeleteMutex);
	Line 65:     OpenThreads::ScopedLock<OpenThreads::Mutex> mlock(backgroundVehicleDeleteMutex);
	Line 106:             OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleLoadMutex);
	Line 106:             OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleLoadMutex);
	Line 124:             OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleLoadMutex);
	Line 124:             OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleLoadMutex);
	Line 138:                 OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleDeleteMutex);
	Line 138:                 OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleDeleteMutex);
	Line 516:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleLoadMutex);
	Line 516:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleLoadMutex);
	Line 570:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleDeleteMutex);
	Line 570:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleDeleteMutex);
	Line 658: OpenThreads::Mutex& GameBoard::getBackgroundVehicleLoadMutex()
	Line 663: OpenThreads::Mutex& GameBoard::getBackgroundVehicleDeleteMutex()
	Line 689:             OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleDeleteMutex);
	Line 689:             OpenThreads::ScopedLock<OpenThreads::Mutex> lock(backgroundVehicleDeleteMutex);
  D:\Development\psim\src\subview\GameBoard.h (4 hits)
	Line 41:     OpenThreads::Mutex backgroundVehicleDeleteMutex;
	Line 42:     OpenThreads::Mutex backgroundVehicleLoadMutex;
	Line 112:     OpenThreads::Mutex &getBackgroundVehicleLoadMutex();
	Line 114:     OpenThreads::Mutex &getBackgroundVehicleDeleteMutex();
  D:\Development\psim\src\subview\MiniBackgroundLoader.cpp (1 hit)
	Line 107:     OpenThreads::Mutex &backgroundVehicleLoadMutex = gameBoard->getBackgroundVehicleLoadMutex();
  D:\Development\psim\src\subview\MiniBackgroundLoader.h (1 hit)
	Line 23: class MiniBackgroundLoader : public OpenThreads::Thread
  D:\Development\psim\src\subview\OceanMesh.h (1 hit)
	Line 96:     OpenThreads::Mutex mDataMutex;
  D:\Development\psim\src\subview\OceanMeshGenerator.cpp (4 hits)
	Line 169:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSignalMutex);
	Line 169:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSignalMutex);
	Line 177:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSignalMutex);
	Line 177:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSignalMutex);
  D:\Development\psim\src\subview\OceanMeshGenerator.h (3 hits)
	Line 11: class OceanMeshGenerator : public OpenThreads::Thread
	Line 37:     OpenThreads::Mutex mSignalMutex;
	Line 38:     OpenThreads::Condition mSignalCond;
  D:\Development\psim\src\subview\ParticleGeom.h (1 hit)
	Line 33:     OpenThreads::Mutex deletionFinishRenderMutex;
  D:\Development\psim\src\subview\RootNodeCallback.cpp (1 hit)
	Line 867:     OpenThreads::Mutex &backgroundVehicleDeleteMutex = gameBoard->getBackgroundVehicleDeleteMutex();
  D:\Development\psim\src\subview\RootNodeCallback.h (1 hit)
	Line 72:     OpenThreads::Mutex vehicleAddListMutex;
  D:\Development\psim\src\subview\SubviewViewer.cpp (3 hits)
	Line 138:         //if (frameTime < minFrameTime) OpenThreads::Thread::microSleep(static_cast<unsigned int>(0.95*1000000.0*(minFrameTime-frameTime)));
	Line 139:         //if (frameTime < minFrameTime) OpenThreads::Thread::microSleep(static_cast<unsigned int>(1000000.0*(minFrameTime-frameTime)));
	Line 140:         if (elapsedTimeMicroSec < mMinFrameTimeMicroSec) OpenThreads::Thread::microSleep(mMinFrameTimeMicroSec - elapsedTimeMicroSec);
  D:\Development\psim\src\subview\ViewSpecShared.cpp (22 hits)
	Line 18:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 18:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 24:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 24:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 30:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 30:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 37:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 37:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 44:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 44:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 52:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 52:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 59:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 59:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 65:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 65:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 71:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 71:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 77:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 77:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 83:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
	Line 83:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mMutex);
  D:\Development\psim\src\subview\ViewSpecShared.h (1 hit)
	Line 28:     OpenThreads::Mutex mMutex;
  D:\Development\psim\src\subview\WaveHeightApp.cpp (2 hits)
	Line 36:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSpinMutex);
	Line 36:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSpinMutex);
  D:\Development\psim\src\subview\WaveHeightBase.h (1 hit)
	Line 36:     OpenThreads::Mutex mSpinMutex;
  D:\Development\psim\src\subview\WaveHeightCreate.cpp (2 hits)
	Line 106:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSpinMutex);
	Line 106:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSpinMutex);
  D:\Development\psim\src\subview\WaveHeightUpdate.cpp (2 hits)
	Line 56:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSpinMutex);
	Line 56:     OpenThreads::ScopedLock<OpenThreads::Mutex> lock(mSpinMutex);
Search "OpenThreads::" (0 hits in 0 files)
