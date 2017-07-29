#ifndef PURGE_COMPONENTS_CONSOLE_CONTROLLER_
#define PURGE_COMPONENTS_CONSOLE_CONTROLLER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class ConsoleController :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::ConsoleController )

	public:
		explicit ConsoleController( crimild::scripting::ScriptEvaluator &eval );
		virtual ~ConsoleController( void );
	};

}

#endif

