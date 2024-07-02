cmake_minimum_required(VERSION 3.26)
project(GravityPlanet)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/sfml.git GIT_TAG 2.6.1)
FETCHCONTENT_MAKEAVAILABLE(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(GravityPlanet src/main.cpp
        src/physic/particule/Planet.cpp
        src/physic/particule/Planet.h
        src/physic/particule/Point.cpp
        src/physic/particule/Point.h
        src/physic/particule/Point.h
)

target_link_libraries(GravityPlanet sfml-system sfml-window sfml-graphics sfml-audio)