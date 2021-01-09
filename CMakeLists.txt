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
	IF(CMAKE_BUILD_TYPE STREQUAL "Debug")
		set (EXTRA_LIBS ${EXTRA_LIBS} "C:/bibliotheque/SFML-2.4.2/lib/sfml-system-d.lib")
		set (EXTRA_LIBS ${EXTRA_LIBS} "C:/bibliotheque/SFML-2.4.2/lib/sfml-window-d.lib")
		set (EXTRA_LIBS ${EXTRA_LIBS} "C:/bibliotheque/SFML-2.4.2/lib/sfml-graphics-d.lib")
	else()
		set (EXTRA_LIBS ${EXTRA_LIBS} "C:/bibliotheque/SFML-2.4.2/lib/sfml-system.lib")
		set (EXTRA_LIBS ${EXTRA_LIBS} "C:/bibliotheque/SFML-2.4.2/lib/sfml-window.lib")
		set (EXTRA_LIBS ${EXTRA_LIBS} "C:/bibliotheque/SFML-2.4.2/lib/sfml-graphics.lib")
	ENDIF()

	
	target_link_libraries (sfmlConsole  ${EXTRA_LIBS})
endif(WIN32)
	


