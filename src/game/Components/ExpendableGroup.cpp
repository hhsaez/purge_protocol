#include "ExpendableGroup.hpp"
#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

ExpendableGroup::ExpendableGroup( ScriptEvaluator &eval )
{

}

ExpendableGroup::~ExpendableGroup( void )
{

}

void ExpendableGroup::start( void )
{
	registerMessageHandler< messaging::MessageEvent >( [ this ]( messaging::MessageEvent const &m ) {
		if ( m.eventName == "expendableGroup" ) {
			getNode()->setEnabled( true );
		}
	});

	getNode()->setEnabled( false );
}

void ExpendableGroup::update( const Clock &c )
{
	getNode()->local().rotate() *= Quaternion4f::createFromAxisAngle( Vector3f::UNIT_X, 0.1f * c.getDeltaTime() );

	Interpolation::linear( getNode()->getLocal().getTranslate(), Vector3f( -15.0f, 1.0f, 3.0f ), 0.1f * c.getDeltaTime(), getNode()->local().translate() );
}

