cmake_minimum_required( VERSION 2.8 )

project( spacerocks )
set( CMAKE_CXX_FLAGS_DEBUG )
set( CMAKE_C_FLAGS_DEBUG )
set( CMAKE_BUILD_TYPE Debug )
add_executable( spacerocks main.cpp gameengine.cpp graphics.cpp
playstate.cpp background.cpp entity.cpp ship.cpp )
target_link_libraries( spacerocks -lSDL2 -lSDL2_image -lSDL2_ttf )
