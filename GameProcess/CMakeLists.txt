set (CMAKE_CXX_STANDARD 11)

add_library (GameProcess STATIC "./sources/Turret.cpp" "./sources/Bullet.cpp")

target_include_directories (GameProcess PUBLIC "./include")
target_link_libraries (GameProcess sfml-graphics sfml-audio sfml-window)