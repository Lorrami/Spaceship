set (CMAKE_CXX_STANDARD 11)

add_library (Components STATIC "sources/HealthComponent.cpp"
							   "sources/ScoreComponent.cpp")

target_include_directories (Components PUBLIC "./include")