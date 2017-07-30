#ifndef PURGE_COMPONENTS_CONSOLE_MESSAGE_
#define PURGE_COMPONENTS_CONSOLE_MESSAGE_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	namespace messaging {

		struct ShowNextMessage {
			std::string fileName;
			int score;
		};

	}

	class ConsoleMessage :
		public crimild::NodeComponent,
		public crimild::Messenger {
	public:
		explicit ConsoleMessage( crimild::scripting::ScriptEvaluator &eval );
		virtual ~ConsoleMessage( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;

	private:
		crimild::Clock _timer;
		std::string _nextMessage;
		crimild::Bool _waitForInput = false;
	};

}

#endif


