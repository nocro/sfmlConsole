cmake_minimum_required(VERSION 3.10)

#set binary path
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../bin)

#set the project name
project(sfmlConsole VERSION 1.0)

#specify the c++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add the executable
add_executable(sfmlConsole main.cpp console.cpp utils.cpp)
set(CMAKE_CXX_FLAGS "-Wall -Wfatal-errors")

# add SFML 
include_directories("/home/ubuntu/Documents/bibliotheque")
target_link_libraries(sfmlConsole "-lsfml-graphics -lsfml-window -lsfml-system")
