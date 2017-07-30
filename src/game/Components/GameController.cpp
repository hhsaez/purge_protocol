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
				broadcastMessage( crimild::messaging::ReloadScene { } );
			}, 5.0f );
		}
	});
}

void GameController::update( const Clock &c )
{
	_timer += c;
}

