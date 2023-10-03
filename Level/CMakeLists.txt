set (CMAKE_CXX_STANDARD 11)

add_library (Level STATIC "./sources/Level.cpp")

target_include_directories (Level PUBLIC "./include")
target_link_libraries (Level GameProcess)