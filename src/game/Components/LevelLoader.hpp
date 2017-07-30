#ifndef PURGE_COMPONENTS_LEVEL_LOADER_
#define PURGE_COMPONENTS_LEVEL_LOADER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class LevelLoader :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::LevelLoader )

	public:
		explicit LevelLoader( crimild::scripting::ScriptEvaluator &eval );
		virtual ~LevelLoader( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;

	private:
		crimild::Clock _timer;
		crimild::Real32 _timeout;
		std::string _nextScene;
	};

}

#endif

