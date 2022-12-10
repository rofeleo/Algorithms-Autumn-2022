# CMakeList.txt : CMake project for Rdec2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("Rdec2d")

# Add source to this project's executable.
add_executable (Rdec2d "src/Rdec2d.cpp" "src/Rdec2d.hpp" "src/main.cpp")

include_directories(.)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Rdec2d PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
