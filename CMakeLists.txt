cmake_minimum_required (VERSION 3.8)
set (CMAKE_CXX_STANDARD 11)

project (Spaceship)

add_subdirectory (SFML)
add_subdirectory (Components)
add_subdirectory (GameProcess)
add_subdirectory (Level)
add_subdirectory (Application)

add_executable (${PROJECT_NAME} main.cpp)
target_link_libraries (${PROJECT_NAME} Application)