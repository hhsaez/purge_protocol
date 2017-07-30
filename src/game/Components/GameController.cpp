#include "GameController.hpp"
#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

GameController::GameController( ScriptEvaluator &eval )
{

}

GameController::~GameController( void )
{

}

void GameController::start( void )
{
	registerMessageHandler< messaging::MessageEvent >( [ this ]( messaging::MessageEvent const &m ) {
		if ( m.eventName == "endGame" ) {
			_timer.reset();
			_timer.setTimeout( [this] {
				Simulation::getInstance()->loadScene( "assets/scripts/scenes/main.lua", crimild::alloc< LuaSceneBuilder >() );
			}, 5.0f );
		}
		else if ( m.eventName == "gameOver" ) {
			_timer.reset();
			_timer.setTimeout( [this] {
				Simulation::getInstance()->loadScene( "assets/scripts/scenes/game_over.lua", crimild::alloc< LuaSceneBuilder >() );
			}, 5.0f );
		}
	});
}

void GameController::update( const Clock &c )
{
	_timer += c;
}

