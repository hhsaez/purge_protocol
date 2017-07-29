/*
 * Copyright (c) 2017, Hernan Saez
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <Crimild.hpp>
#include <Crimild_GLFW.hpp>
#include <Crimild_Scripting.hpp>

#include "Components/FirstPersonCameraController.hpp"
#include "Components/ConsoleController.hpp"
#include "Components/ConsoleMessage.hpp"

using namespace crimild;
using namespace crimild::scripting;

int main( int argc, char **argv )
{
	CRIMILD_SCRIPTING_REGISTER_BUILDER( purge::FirstPersonCameraController );
	CRIMILD_SCRIPTING_REGISTER_BUILDER( purge::ConsoleController );
	CRIMILD_SCRIPTING_REGISTER_BUILDER( purge::ConsoleMessage );
	
    auto settings = crimild::alloc< LuaSettings >( argc, argv );
	settings->set( "video.width", 1024 );
    settings->set( "video.height", 768 );
	settings->set( "video.fullscreen", false );

	settings->load( "assets/scripts/config.lua" );

#ifdef CRIMILD_PLATFORM_WIN32
	settings->load( "assets/scripts/config.win.lua" );
#endif
    	
	settings->parseCommandLine( argc, argv );

	auto sim = crimild::alloc< GLSimulation >( "The P.U.R.G.E. Protocol", settings );
	sim->addSystem( crimild::alloc< UISystem >() );

	//AssetManager::getInstance()->loadFont( AssetManager::FONT_SYSTEM, "assets/fonts/Courier New.txt" );
	//Profiler::getInstance()->setOutputHandler( crimild::alloc< ProfilerScreenOutputHandler >() );

	sim->loadScene( "assets/scripts/scenes/room.lua", crimild::alloc< LuaSceneBuilder >() );

	Input::getInstance()->setMouseCursorMode( Input::MouseCursorMode::HIDDEN );

	sim->registerMessageHandler< crimild::messaging::KeyPressed >( [settings]( crimild::messaging::KeyPressed const &msg ) {
		float horiAxisCoeff = 1.0f;
		float cameraAxisCoeff = 5.0f;

		if ( Input::getInstance()->isKeyDown( CRIMILD_INPUT_KEY_LEFT_SHIFT ) || Input::getInstance()->isKeyDown( CRIMILD_INPUT_KEY_RIGHT_SHIFT ) ) {
			horiAxisCoeff = 0.5f;
			cameraAxisCoeff = 20.0f;
		}

		switch ( msg.key ) {
			case 'A':
			case CRIMILD_INPUT_KEY_LEFT:
				Input::getInstance()->setAxis( Input::AXIS_HORIZONTAL, -horiAxisCoeff );
				break;

		    case 'D':
			case CRIMILD_INPUT_KEY_RIGHT:
				Input::getInstance()->setAxis( Input::AXIS_HORIZONTAL, +horiAxisCoeff );
				break;

			case 'W':
			case CRIMILD_INPUT_KEY_UP:
				Input::getInstance()->setAxis( Input::AXIS_VERTICAL, +1.0f );
				break;

		    case 'S':
			case CRIMILD_INPUT_KEY_DOWN:
				Input::getInstance()->setAxis( Input::AXIS_VERTICAL, -1.0f );
				break;

		    case CRIMILD_INPUT_KEY_SPACE: 
		    case CRIMILD_INPUT_KEY_ENTER:
				Input::getInstance()->setAxis( "Action", 1 );
				break;

			default:
				break;
		}
	});

	sim->registerMessageHandler< crimild::messaging::KeyReleased >( [settings]( crimild::messaging::KeyReleased const &msg ) {
		switch ( msg.key ) {
			case 'R':
				Simulation::getInstance()->broadcastMessage( crimild::messaging::ReloadScene { } );
				break;

			case 'K':
				Simulation::getInstance()->broadcastMessage( crimild::messaging::ToggleDebugInfo { } );
				break;

			case 'L':
				Simulation::getInstance()->broadcastMessage( crimild::messaging::ToggleProfilerInfo { } );
				break;

			case 'A':
		    case 'D':
			case CRIMILD_INPUT_KEY_LEFT:
			case CRIMILD_INPUT_KEY_RIGHT:
				Input::getInstance()->setAxis( Input::AXIS_HORIZONTAL, 0.0f );
				break;

			case 'W':
		    case 'S':
			case CRIMILD_INPUT_KEY_UP:
			case CRIMILD_INPUT_KEY_DOWN:
				Input::getInstance()->setAxis( Input::AXIS_VERTICAL, 0.0f );
				break;

			case CRIMILD_INPUT_KEY_ESCAPE:
				Simulation::getInstance()->stop();
				break;

		    case CRIMILD_INPUT_KEY_ENTER:
			case CRIMILD_INPUT_KEY_SPACE:
				Input::getInstance()->setAxis( "Action", 0.0f );
				break;

			default:
				break;
		}
	});

	return sim->run();
}


