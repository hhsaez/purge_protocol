#include "Expendable.hpp"
#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

Expendable::Expendable( ScriptEvaluator &eval )
{

}

Expendable::~Expendable( void )
{

}

void Expendable::start( void )
{
	registerMessageHandler< messaging::MessageEvent >( [ this ]( messaging::MessageEvent const &m ) {
		if ( m.eventName == "expendable" ) {
			getNode()->setEnabled( true );
		}
	});

	getNode()->setEnabled( false );
}

void Expendable::update( const Clock &c )
{
	getNode()->local().rotate() *= Quaternion4f::createFromAxisAngle( Vector3f::UNIT_Z, c.getDeltaTime() );

	Interpolation::linear( getNode()->getLocal().getTranslate(), Vector3f( -12.0f, 2.0f, 2.5f ), 0.1f * c.getDeltaTime(), getNode()->local().translate() );
}

