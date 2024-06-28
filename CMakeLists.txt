cmake_minimum_required(VERSION 3.10)
project(SimSuite_C C)

set(CMAKE_C_STANDARD 99)

# Include directory for header files
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add integrators and systems libraries
add_library(integrators src/integrators.c)
add_library(systems src/systems.c)

# Add executable
add_executable(sim src/main.c)

# Link libraries and math library
target_link_libraries(sim integrators systems m)
