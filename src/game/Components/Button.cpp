#include "Button.hpp"
#include "ConsoleMessage.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

Button::Button( ScriptEvaluator &eval )
{
	eval.getPropValue( "action", _action );
	eval.getPropValue( "data", _data );
}

Button::~Button( void )
{

}

void Button::start( void )
{
	auto node = getNode();
	
	node->attachComponent< UIResponder >( [this]( Node *n ) {
		if ( _action == "load_scene" ) {
			Simulation::getInstance()->loadScene( _data, crimild::alloc< LuaSceneBuilder >() );
		}
		else if ( _action == "quit" ) {
			crimild::concurrency::sync_frame( [] {
				Simulation::getInstance()->stop();
			});
		}
		
		return true;
	});
}

