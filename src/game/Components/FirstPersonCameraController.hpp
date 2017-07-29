#ifndef PURGE_COMPONENTS_FIRST_PERSON_CAMERA_CONTROLLER_
#define PURGE_COMPONENTS_FIRST_PERSON_CAMERA_CONTROLLER_

#include <Crimild.hpp>
#include <Crimild_Scripting.hpp>

namespace purge {

	class FirstPersonCameraController :
		public crimild::NodeComponent,
		public crimild::Messenger {
		CRIMILD_IMPLEMENT_RTTI( purge::FirstPersonCameraController )

	public:
		explicit FirstPersonCameraController( crimild::scripting::ScriptEvaluator &eval );
		virtual ~FirstPersonCameraController( void );

		virtual void onAttach( void ) override;
		virtual void onDetach( void ) override;

		virtual void start( void ) override;
		virtual void update( const crimild::Clock & ) override;

	private:
		crimild::Real32 _speed = 1.0f;
	};

}

#endif

