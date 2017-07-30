#include "GameOverController.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

GameOverController::GameOverController( ScriptEvaluator &eval )
{

}

GameOverController::~GameOverController( void )
{

}

void GameOverController::start( void )
{
	_timer.setTimeout( [this] {
		Simulation::getInstance()->loadScene( "assets/scripts/scenes/main.lua", crimild::alloc< LuaSceneBuilder >() );
	}, 5.0f );
}

void GameOverController::update( const Clock &c )
{
	_timer += c;
}

