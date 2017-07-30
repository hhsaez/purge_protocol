#ifndef PURGE_COMPONENTS_GAME_OVER_CONTROLLER_
#define PURGE_COMPONENTS_GAME_OVER_CONTROLLER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class GameOverController :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::GameOverController )

	public:
		explicit GameOverController( crimild::scripting::ScriptEvaluator &eval );
		virtual ~GameOverController( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;

	private:
		crimild::Clock _timer;
	};

}

#endif

