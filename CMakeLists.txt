cmake_minimum_required( VERSION 2.8 )

project( spacerocks )
set( CMAKE_CXX_FLAGS_DEBUG )
set( CMAKE_C_FLAGS_DEBUG )
add_executable( spacerocks main.cpp gameengine.cpp graphics.cpp playstate.cpp background.cpp )
target_link_libraries( spacerocks -lSDL2 -lSDL2_image -lSDL2_ttf )