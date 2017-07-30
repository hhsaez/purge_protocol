#ifndef PURGE_COMPONENTS_GAME_CONTROLLER_
#define PURGE_COMPONENTS_GAME_CONTROLLER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class GameController :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::GameController )

	public:
		explicit GameController( crimild::scripting::ScriptEvaluator &eval );
		virtual ~GameController( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;

	private:
		crimild::Clock _timer;
	};

}

#endif

