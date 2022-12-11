# CMakeList.txt : CMake project for Rdec2d, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)


set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "cmake")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG bin.dbg)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE bin.rel)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELWITHDEBINFO bin.relwithdbg)


project ("Rdec2d")

# Add source to this project's executable.

add_subdirectory(r2d)

include_directories(.)

add_executable(cat_and_mouse main.cpp)

add_executable(r2d.doctest r2d_doctest.cpp)

target_link_libraries(cat_and_mouse Rdec2d)

target_link_libraries(r2d.doctest Rdec2d)

set_property(TARGET r2d.doctest PROPERTY CXX_STANDARD 20)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT r2d.doctest)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Rdec2d PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
