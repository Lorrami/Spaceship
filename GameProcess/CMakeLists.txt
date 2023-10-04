set (CMAKE_CXX_STANDARD 11)

add_library (GameProcess STATIC "sources/Spaceship.cpp"
								"sources/Bullet.cpp"
								"sources/DangerZone.cpp"
								"sources/HealthComponent.cpp")

target_include_directories (GameProcess PUBLIC "./include")
target_link_libraries (GameProcess Application sfml-graphics sfml-audio sfml-window)