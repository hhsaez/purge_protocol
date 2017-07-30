#include "LevelLoader.hpp"

using namespace purge;

using namespace crimild;
using namespace crimild::scripting;

LevelLoader::LevelLoader( ScriptEvaluator &eval )
{
	eval.getPropValue( "nextScene", _nextScene );
	eval.getPropValue( "timeout", _timeout );
}

LevelLoader::~LevelLoader( void )
{

}

void LevelLoader::start( void )
{
	_timer.setTimeout( [this] {
		Simulation::getInstance()->loadScene( _nextScene, crimild::alloc< LuaSceneBuilder >() );
	}, _timeout );
}

void LevelLoader::update( const Clock &c )
{
	_timer += c;
}

