#ifndef PURGE_COMPONENTS_SMOKE_CONTROLLER_
#define PURGE_COMPONENTS_SMOKE_CONTROLLER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class SmokeController :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::SmokeController )

	public:
		explicit SmokeController( crimild::scripting::ScriptEvaluator &eval );
		virtual ~SmokeController( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;
	};

}

#endif

