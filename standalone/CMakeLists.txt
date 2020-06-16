cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(StrixStandalone
  LANGUAGES CXX
)

# ---- import tools ----

include(../cmake/tools.cmake)

# ---- Dependencies ----

include(../cmake/CPM.cmake)

CPMAddPackage(
  NAME cxxopts
  GITHUB_REPOSITORY jarro2783/cxxopts
  VERSION 2.2.0
  OPTIONS
    "CXXOPTS_BUILD_EXAMPLES Off"
    "CXXOPTS_BUILD_TESTS Off"
)

CPMAddPackage(
  NAME Strix
  SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/..
)

# ---- Create standalone executable ----

file(GLOB src CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(StrixStandalone ${src})

set_target_properties(StrixStandalone PROPERTIES
  CXX_STANDARD 17
  OUTPUT_NAME "Strix"
)

target_link_libraries(StrixStandalone Strix cxxopts)