cmake_minimum_required(VERSION 3.10)

#set binary path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#set the project name
project(sfmlConsole VERSION 1.0)


#add the executable
add_executable(sfmlConsole main.cpp console.cpp utils.cpp)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -Wfatal-errors")
	# add SFML 
	include_directories("/home/ubuntu/Documents/bibliotheque")
	target_link_libraries(sfmlConsole "-lsfml-graphics -lsfml-window -lsfml-system")
endif(UNIX)
if(WIN32)
	include_directories("C:/bibliotheque/SFML-2.4.2/include")
	target_link_libraries(sfmlConsole C:/bibliotheque/SFML-2.4.2/include/lib/lsfml-graphics.lib C:/bibliotheque/SFML-2.4.2/include/lib/lsfml-window.lib C:/bibliotheque/SFML-2.4.2/include/lib/lsfml-system.lib)

endif(WIN32)
	


