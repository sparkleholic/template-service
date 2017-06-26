cmake_minimum_required(VERSION 3.2)

# Project name and version
project(template-service VERSION 0.1.0)

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
