cmake_minimum_required(VERSION 3.10)

project(
	Snake-AI-SFML
	VERSION 1.0.0
	LANGUAGES CXX
)

# set(SFML_DIR )
find_package(SFML 2 REQUIRED COMPONENTS graphics system window)
message(STATUS "Found SMFL in ${SFML_DIR}")

set(SFML_LIBS sfml-graphics sfml-system sfml-window)

add_executable(
	snake-ai-sfml
	snake-ai-sfml/src/Food.cpp
	snake-ai-sfml/src/Game.cpp
	snake-ai-sfml/src/Map.cpp
	snake-ai-sfml/src/Point.cpp
	snake-ai-sfml/src/RamdomPoint.cpp
	snake-ai-sfml/src/Snake.cpp
	snake-ai-sfml/src/Utilities.cpp
	snake-ai-sfml/src/main.cpp
)
target_include_directories( snake-ai-sfml PUBLIC snake-ai-sfml/include )
target_link_libraries( snake-ai-sfml SFML_LIBS )

if(MSVC)
   foreach(lib ${SFML_LIBS})
      get_target_property(lib_path ${lib} LOCATION)
      file(COPY ${lib_path} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
   endforeach()
endif()
