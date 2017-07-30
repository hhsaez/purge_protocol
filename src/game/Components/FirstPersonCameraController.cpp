#include "FirstPersonCameraController.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::navigation;
using namespace crimild::scripting;

FirstPersonCameraController::FirstPersonCameraController( ScriptEvaluator &eval )
{
	eval.getPropValue( "speed", _speed );
}

FirstPersonCameraController::~FirstPersonCameraController( void )
{

}

void FirstPersonCameraController::onAttach( void )
{
	NodeComponent::onAttach();

	auto camera = getNode< Camera >();

	auto geo = crimild::alloc< Geometry >();
	geo->attachPrimitive( crimild::alloc< QuadPrimitive >( 0.005f, 0.005f, VertexFormat::VF_P3_UV2 ) );
	geo->local().setTranslate( 0.0f, 0.0f, -0.25f );
	auto m = crimild::alloc< Material >();
	m->setColorMap( AssetManager::getInstance()->get< Texture >( "assets/textures/cursor.tga" ) );
	m->setAlphaState( crimild::alloc< AlphaState >( true ) );
	m->setDepthState( crimild::alloc< DepthState >( false ) );
	m->setProgram( Renderer::getInstance()->getShaderProgram( Renderer::SHADER_PROGRAM_UNLIT_TEXTURE ) );
	geo->getComponent< MaterialComponent >()->attachMaterial( m );
	
	camera->attachNode( geo );

    auto renderPass = crimild::alloc< CompositeRenderPass >();
    renderPass->attachRenderPass( crimild::alloc< ShadowRenderPass >() );
    renderPass->attachRenderPass( crimild::alloc< StandardRenderPass >() );
    camera->setRenderPass( renderPass );	
}

void FirstPersonCameraController::onDetach( void )
{
	NodeComponent::onDetach();

	Input::getInstance()->setMouseCursorMode( Input::MouseCursorMode::NORMAL );
}

void FirstPersonCameraController::start( void )
{
	NodeComponent::start();
}

void FirstPersonCameraController::update( const Clock &c )
{
	NodeComponent::update( c );

	Input::getInstance()->setMouseCursorMode( Input::MouseCursorMode::GRAB );

	float dSpeed = Input::getInstance()->getAxis( Input::AXIS_VERTICAL );
	float rSpeed = Input::getInstance()->getAxis( Input::AXIS_HORIZONTAL );
	float roll = 0.0f;//Input::getInstance()->getAxis( "CameraAxisRoll" );
	
	auto mouseDelta = Input::getInstance()->getNormalizedMouseDelta();

	auto root = getNode();

	// apply roll first
	root->local().rotate() *= Quaternion4f::createFromAxisAngle( Vector3f::UNIT_Z, c.getDeltaTime() * roll );

	// apply pitch
	auto right = root->getLocal().computeRight();
	right[ 1 ] = 0.0f;
	right.normalize();
	root->local().rotate() *= Quaternion4f::createFromAxisAngle( Vector3f::UNIT_X, -mouseDelta[ 1 ] );

	// apply yaw
	auto up = root->getLocal().computeWorldUp();
	root->local().rotate() *= Quaternion4f::createFromAxisAngle( up.getNormalized(), -mouseDelta[ 0 ] );
	
	auto direction = root->getLocal().computeDirection();
	direction[ 1 ] = 0.0f;
	direction.normalize();

	auto currentPos = root->getLocal().getTranslate();
	auto newPos = currentPos + c.getDeltaTime() * _speed * ( dSpeed * direction + rSpeed * right );

	auto nav = getComponent< NavigationController >();
	if ( nav != nullptr ) {
		newPos = nav->move( currentPos, newPos );
	}

	root->local().setTranslate( newPos );
}

