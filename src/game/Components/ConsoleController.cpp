#include "ConsoleController.hpp"
#include "ConsoleMessage.hpp"

#include <Crimild_Import.hpp>

using namespace purge;

using namespace crimild;
using namespace crimild::import;
using namespace crimild::scripting;

ConsoleController::ConsoleController( ScriptEvaluator &eval )
{

}

ConsoleController::~ConsoleController( void )
{

}

void ConsoleController::start( void )
{
	registerMessageHandler< messaging::ShowNextMessage >( [ this ]( messaging::ShowNextMessage const &msg ) {
		if ( msg.score > 0 ) {
			_successCount++;
		}
		else if ( msg.score < 0 ) {
			_failureCount++;
		}

		if ( msg.score == 0 || _failureCount < 2 ) {
			showMessage( msg.fileName );
		}
		else {
			showMessage( "assets/scripts/prefabs/console_game_over_000.lua" );
		}
	});

	showMessage( "assets/scripts/prefabs/console_welcome.lua" );
}

void ConsoleController::showMessage( std::string fileName )
{
	crimild::concurrency::async( [ this, fileName ] {
		auto builder = crimild::alloc< LuaSceneBuilder >( "message" );
		auto message = builder->fromFile( FileSystem::getInstance().pathForResource( fileName ) );
		if ( message != nullptr ) {
			crimild::concurrency::sync_frame( [ this, message ] {
				if ( _currentMessage != nullptr ) {
					_currentMessage->detachFromParent();
				}
				
				_currentMessage = message;
				
				if ( _currentMessage != nullptr ) {
					getNode< Group >()->attachNode( _currentMessage );
					_currentMessage->perform( UpdateWorldState() );
					_currentMessage->perform( UpdateRenderState() );
					_currentMessage->perform( StartComponents() );
				}
			});
		}
		else {
			Log::error( CRIMILD_CURRENT_CLASS_NAME, "Cannot find file ", fileName );
		}
	});
}

