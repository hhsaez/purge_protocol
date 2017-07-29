#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

ConsoleMessage::ConsoleMessage( ScriptEvaluator &eval )
{
	eval.getPropValue( "nextMessage", _nextMessage );

	crimild::Real32 timeout;
	if ( eval.getPropValue( "timeout", timeout ) ) {
		if ( timeout > 0.0f ) {
			_timer.setTimeout( [this] {
				broadcastMessage( messaging::ShowNextMessage { _nextMessage } );
			}, timeout );
		}
	}

	eval.getPropValue( "waitForInput", _waitForInput );
}

ConsoleMessage::~ConsoleMessage( void )
{

}

void ConsoleMessage::start( void )
{
	if ( _waitForInput ) {
		getNode()->perform( Apply( [this]( Node *node ) {
			static const std::string SUCCESS = "Success";
			static const std::string FAILURE = "Failure";
			
			if ( node->getName().compare( 0, SUCCESS.length(), SUCCESS ) == 0 ) {
				node->attachComponent< UIResponder >( [this]( Node *n ) {
					broadcastMessage( messaging::ShowNextMessage { _nextMessage } );
					return true;
				});
			}
			else if ( node->getName().compare( 0, FAILURE.length(), FAILURE ) == 0 ) {
				node->attachComponent< UIResponder >( [this]( Node *n ) {
					broadcastMessage( messaging::ShowNextMessage { _nextMessage } );
					return true;
				});
			}
		}));
	}
}

void ConsoleMessage::update( const Clock &c )
{
	_timer += c;
}

