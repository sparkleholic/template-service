cmake_minimum_required(VERSION 3.4)

# Project name and version
project(template-service VERSION 0.1.0 LANGUAGES CXX)

# Use a pkg-config module for CMake
find_package(PkgConfig)

# Define GNU standard installation directories
include(GNUInstallDirs)

# Add feature summary
include(FeatureSummary)

# C++ compiler flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_EXTENSIONS OFF)

# C++ compiler flags for arm FPU
if (NOT ARCH OR ARCH STREQUAL "" OR ARCH STREQUAL "native" OR ARCH STREQUAL "default")
  set(ARCH_ID "${CMAKE_SYSTEM_PROCESSOR}")
else()
  set(ARCH_ID "${ARCH}")
endif()
string(TOLOWER "${ARCH_ID}" ARM_ID)
string(SUBSTRING "${ARM_ID}" 0 3 ARM_TEST)
if (ARM_TEST STREQUAL "arm")
    CHECK_CXX_ACCEPTS_FLAG(-mfloat-abi=hard CXX_ACCEPTS_MFLOAT_HARD)
    if(CXX_ACCEPTS_MFLOAT_HARD)
        message(STATUS "Setting FPU Flags for ARM Processors")
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mfloat-abi=hard")
    endif()
endif()

# Options on enabling / disabling template-library at compile-time
option(ENABLE_TEMPLATE_LIBRARY "Enables the template library features" OFF)
add_feature_info("Enable Template Library" ENABLE_TEMPLATE_LIBRARY "Provides access to Template Library classes and methods")


# Check dependencies
if(ENABLE_TEMPLATE_LIBRARY)
    pkg_check_modules(TEMPLATE-LIBRARY "template-library >= 0.1.0" REQUIRED)
endif()

# Project targets
set(TARGET ${PROJECT_NAME})

# Target source files
include_directories(src)
file(GLOB SOURCE_FILES "src/*.cpp" "src/*.h")

# Include dependency directories
if(ENABLE_TEMPLATE_LIBRARY)
    include_directories(${TEMPLATE-LIBRARY_INCLUDE_DIRS})
    link_directories(${TEMPLATE-LIBRARY_LIBRARY_DIRS})
endif()

# Declare target executable
add_executable(${TARGET} ${SOURCE_FILES})

# Link libraries
if(ENABLE_TEMPLATE_LIBRARY)
    add_definitions(-DTEMPLATE_LIBRARY)
    target_link_libraries(${TARGET} ${TEMPLATE-LIBRARY_LIBRARIES})
endif()

# Install directives
install(TARGETS ${TARGET} DESTINATION ${CMAKE_INSTALL_BINDIR})
