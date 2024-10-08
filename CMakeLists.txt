# 3.13 for target_link_directories.
cmake_minimum_required(VERSION 3.13)

# Define project.
project(
    USDPlugins
    VERSION 1.0.0
    DESCRIPTION "A collection of plugins for Pixar's USD (Universal Scene Description)."
    LANGUAGES CXX
)

# Discover cmake modules.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/packages
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Exposes build options (with default values) for this project.
include(Options)

# Set project defaults.
include(Defaults)

# Import the package dependencies (USD, TBB, ...).
include(Packages)

# Include USD plugin building CMake utilities.
include(USDPluginTools)

# Recurse into source tree.
add_subdirectory(pxr)

# Export targets and install package files.
# This must come after source tree recursion as exporting targets
# requires the targets to be defined in the first place!
include(Export)
