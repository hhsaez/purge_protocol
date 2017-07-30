#ifndef PURGE_COMPONENTS_LIGHT_CONTROLLER_
#define PURGE_COMPONENTS_LIGHT_CONTROLLER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class LightController :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::LightController )

	public:
		explicit LightController( crimild::scripting::ScriptEvaluator &eval );
		virtual ~LightController( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;

	private:
		crimild::Bool _enableOnEvent = true;
	};

}

#endif

