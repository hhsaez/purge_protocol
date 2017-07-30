#ifndef PURGE_COMPONENTS_EXPENDABLE_GROUP_
#define PURGE_COMPONENTS_EXPENDABLE_GROUP_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class ExpendableGroup :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::ExpendableGroup )

	public:
		explicit ExpendableGroup( crimild::scripting::ScriptEvaluator &eval );
		virtual ~ExpendableGroup( void );

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;
	};

}

#endif

