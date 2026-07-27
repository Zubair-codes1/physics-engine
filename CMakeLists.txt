cmake_minimum_required(VERSION 3.20)
project(physics_engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source files
set(SOURCES
    src/main.cpp
    src/Vector2.cpp
    src/RigidBody.cpp
    src/World.cpp
)

add_executable(physics_engine ${SOURCES})

# Include headers directory
target_include_directories(physics_engine PRIVATE include)