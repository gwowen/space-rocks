cmake_minimum_required( VERSION 2.8 )

project( spacerocks )
file( GLOB SOURCE_FILES src/*.cpp)
set( CMAKE_CXX_FLAGS_DEBUG )
set( CMAKE_C_FLAGS_DEBUG )
set( CMAKE_BUILD_TYPE Debug )
add_executable( spacerocks ${SOURCE_FILES})
target_link_libraries( spacerocks -lSDL2 -lSDL2_image -lSDL2_ttf )
