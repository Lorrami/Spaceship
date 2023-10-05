set (CMAKE_CXX_STANDARD 11)

add_library (GameProcess STATIC "sources/Spaceship.cpp"
								"sources/Bullet.cpp"
								"sources/DangerZone.cpp"
								"sources/Asteroid.cpp"
								"sources/MovableObject.cpp"
)

target_include_directories (GameProcess PUBLIC "./include")
target_link_libraries (GameProcess Application UI Components sfml-graphics sfml-audio sfml-window)