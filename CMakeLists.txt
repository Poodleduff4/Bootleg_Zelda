cmake_minimum_required(VERSION 3.0.0)
project(Platformer VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Platformer main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

message("system: ${CMAKE_SYSTEM_PREFIX_PATH}")
find_library(SFML_LIBRARY SFML)
message("sfml: ${SFML_LIBRARY}")
