set (CMAKE_CXX_STANDARD 11)

add_library (UI STATIC "sources/MainMenuUI.cpp"
					   "sources/InGameUI.cpp"
					   "sources/GameEndedUI.cpp")

target_include_directories (UI PUBLIC "./include")
target_link_libraries (UI Application)