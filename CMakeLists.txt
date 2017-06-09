cmake_minimum_required(VERSION 3.2)

# Project name
project(template-service)

# Project version
set(PROJECT_MAJOR_VERSION 0)
set(PROJECT_MINOR_VERSION 1)
set(PROJECT_PATCH_LEVEL 0)
set(PROJECT_VERSION ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_LEVEL})

# Use a pkg-config module for CMake
find_package(PkgConfig)

# Define GNU standard installation directories
include(GNUInstallDirs)

# C++ compiler flags
add_compile_options(-std=c++14)

# Project targets
set(TARGET ${PROJECT_NAME})

# Target source files
include_directories(src)
file(GLOB SOURCE_FILES "src/*.cpp" "src/*.h")

# Declare target executable
add_executable(${TARGET} ${SOURCE_FILES})

# Install directives
install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_BINDIR})
