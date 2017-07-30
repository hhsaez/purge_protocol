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

		virtual void start( void ) override;

	private:
		void showMessage( std::string message );

	private:
		crimild::SharedPointer< crimild::Node > _currentMessage;
		int _successCount = 0;
		int _failureCount = 0;
	};

}

#endif

