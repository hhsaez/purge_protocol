#include "LightController.hpp"
#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

LightController::LightController( ScriptEvaluator &eval )
{
	eval.getPropValue( "enableOnEvent", _enableOnEvent );
}

LightController::~LightController( void )
{

}

void LightController::start( void )
{
	registerMessageHandler< messaging::MessageEvent >( [ this ]( messaging::MessageEvent const &m ) {
		if ( m.eventName == "main_light_on" ) {
			getNode()->setEnabled( _enableOnEvent );
		}
	});

	getNode()->setEnabled( !_enableOnEvent );
}

void LightController::update( const Clock &c )
{

}

