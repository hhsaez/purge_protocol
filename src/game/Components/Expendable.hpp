#ifndef PURGE_COMPONENTS_EXPENDABLE_
#define PURGE_COMPONENTS_EXPENDABLE_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class Expendable :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::Expendable )

	public:
		explicit Expendable( crimild::scripting::ScriptEvaluator &eval );
		virtual ~Expendable( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;
	};

}

#endif

