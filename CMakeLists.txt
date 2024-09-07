cmake_minimum_required(VERSION 3.10)
project(SimSuite_C C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)

# Include directory for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add integrators and systems libraries
add_library(integrators src/integrators.c)
add_library(systems src/systems.c)
add_library(init src/init.c)
add_library(simulate src/simulate.c)

# Add executable
add_executable(sim src/main.c)

# Link libraries and math library
target_link_libraries(sim integrators systems init simulate m)

# Set up different build types
set(CMAKE_BUILD_TYPE Debug) # Default build type (can be changed or overridden in command line)

# Specify compile options for Debug mode
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0") # Debug symbols, no optimization

# Specify compile options for Release mode
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O3") # Optimization

# Optionally, you can define additional flags or settings for each configuration
