#include "SmokeController.hpp"
#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

SmokeController::SmokeController( ScriptEvaluator &eval )
{

}

SmokeController::~SmokeController( void )
{

}

void SmokeController::start( void )
{
	registerMessageHandler< messaging::MessageEvent >( [ this ]( messaging::MessageEvent const &m ) {
		if ( m.eventName == "smoke_on" ) {
			getNode()->setEnabled( true );
		}
	});

	crimild::concurrency::sync_frame( [this] {
		getNode()->setEnabled( false );
	});
}

void SmokeController::update( const Clock &c )
{

}

