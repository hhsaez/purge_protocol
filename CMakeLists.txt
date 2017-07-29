CMAKE_MINIMUM_REQUIRED( VERSION 3.1.0 FATAL_ERROR )

PROJECT( PurgeProtocol )

SET( CRIMILD_ENABLE_SCRIPTING ON CACHE BOOL "Enable scripting module for Crimild" )
SET( CRIMILD_ENABLE_IMPORT ON CACHE BOOL "Enable import module for Crimild" )
SET( CRIMILD_ENABLE_GLFW ON CACHE BOOL "Enable glfw module for Crimild" )
SET( CRIMILD_SCRIPTING_LOG_VERBOSE ON CACHE BOOL "Enable verbose logging for Crimild" )

IF ( APPLE ) 
	SET( CRIMILD_ENABLE_AL ON CACHE BOOL "Enable al module for Crimild" )
	SET( CRIMILD_BUILD_TOOLS ON CACHE BOOL "Enable tools for Crimild" )
	SET( CRIMILD_ENABLE_TESTS ON CACHE BOOL "Enable testing module for Crimild" )
ENDIF ()

ADD_SUBDIRECTORY( crimild )

SET ( CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CRIMILD_SOURCE_DIR}/CMakeTools" )

SET( CRIMILD_APP_NAME PurgeProtocol )

SET( CRIMILD_APP_SOURCE_DIRECTORIES 
	src/game
	src/pc
)

SET( CRIMILD_APP_INCLUDE_DIRECTORIES 
	src/game
	src/pc
)

INCLUDE( ModuleBuildApp )

