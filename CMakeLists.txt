cmake_minimum_required(VERSION 3.1)
project(OrbitSimulator VERSION 1.0)

# configure options
option(SHOW_INSTALLATION "Shows installation of header files" OFF)
option(BUILD_EXAMPLES "Build the examples" OFF)

# Add include directory to include path
include_directories(include eigen)

# Add all source files
set(SOURCES
    src/constants.cpp
    src/controller.cpp
    src/observers.cpp
    src/forces.cpp
    src/object.cpp
    src/world.cpp
)

# Set CMake flags
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Ofast")

# Set Custom CMake flags
if(NOT SHOW_INSTALLATION)
    set(CMAKE_INSTALL_MESSAGE NEVER)
endif()

# Create library
add_library(OrbitSimulatorLib ${SOURCES})

# Set C++ standard
set_target_properties(OrbitSimulatorLib PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

# Install library
install(TARGETS OrbitSimulatorLib
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
)

# Install headers
install(DIRECTORY include/ DESTINATION include/OrbitSimulator)
install(DIRECTORY eigen/Eigen DESTINATION include)

# Examples
if(BUILD_EXAMPLES)
    
    add_executable(00-Newtons-First-Law examples/00-Newtons-First-Law.cpp)
    target_link_libraries(00-Newtons-First-Law OrbitSimulatorLib)

    add_executable(01-Simple-Orbit examples/01-Simple-Orbit.cpp)
    target_link_libraries(01-Simple-Orbit OrbitSimulatorLib) 

endif()