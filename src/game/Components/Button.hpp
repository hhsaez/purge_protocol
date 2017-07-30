#ifndef PURGE_COMPONENTS_BUTTON_
#define PURGE_COMPONENTS_BUTTON_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class Button :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::Button )

	public:
		explicit Button( crimild::scripting::ScriptEvaluator &eval );
		virtual ~Button( void );

		virtual void start( void ) override;

	private:
		std::string _action;
		std::string _data;
	};

}

#endif

