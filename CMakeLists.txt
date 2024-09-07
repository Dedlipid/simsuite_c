cmake_minimum_required(VERSION 3.10)
project(SimSuite C)

# Specify C++ standard if using C++ code
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add subdirectories for different components
add_subdirectory(src/integrators)
add_subdirectory(src/systems)
add_subdirectory(src/tools)
add_subdirectory(src/simulate)

# Create a library for the init component
add_library(init src/init.c)

# Link libraries
add_executable(sim src/main.c)
target_link_libraries(sim 
    init 
    integrators 
    systems 
    tools 
    simulate
    m
)
