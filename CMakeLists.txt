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

# Check dependencies
pkg_check_modules(TEMPLATE-LIBRARY "template-library >= 0.1.0" REQUIRED)

# Project targets
set(TARGET ${PROJECT_NAME})

# Target source files
include_directories(src)
file(GLOB SOURCE_FILES "src/*.cpp" "src/*.h")

# Include dependency directories
include_directories(${TEMPLATE-LIBRARY_INCLUDE_DIRS})
link_directories(${TEMPLATE-LIBRARY_LIBRARY_DIRS})

# Declare target executable
add_executable(${TARGET} ${SOURCE_FILES})

# Link libraries
target_link_libraries(${TARGET} ${TEMPLATE-LIBRARY_LIBRARIES})

# Install directives
install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_BINDIR})
