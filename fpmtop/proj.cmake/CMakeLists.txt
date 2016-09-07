cmake_minimum_required (VERSION 2.6)
project (fpmtop)

add_subdirectory(../../pugixml/ pugixml)
#add_definitions(${PUGIXML_DEFINITIONS})
include_directories(../../pugixml/src)
#link_directories(${PUGIXML_LIBRARY_DIRS})

#add_subdirectory(../../oxygine-sound/ oxygine-sound)
#include_directories(${OXYGINESOUND_INCLUDE_DIRS})

#add_subdirectory(../../box2d/ box2d)
#include_directories(../../box2d)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

file(GLOB all_SRC
    "../src/*.h"
    "../src/*.cpp"
)
add_executable(fpmtop ${all_SRC})

if (WIN32) #disable console mode for VC++
	set_target_properties(fpmtop PROPERTIES WIN32_EXECUTABLE TRUE)
endif(WIN32)

link_directories(/usr/lib/x86_64-linux-gnu)
target_link_libraries(fpmtop ncurses curl pugixml)
