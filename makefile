SFML_PATH = /home/ubuntu/Documents/bibliotheque
CFLAG =  -Wall -Wfatal-errors -I$(SFML_PATH)
LDFLAG = -lsfml-graphics -lsfml-window -lsfml-system

all: main console utils
	g++ -o exec console.o main.o $(LDFLAG)

main: main.cpp
	g++ -c main.cpp $(CFLAG)

console: console.cpp
	g++ -c console.cpp $(CFLAG)

utils: utils.cpp 
	g++ -c utils.cpp $(CFLAG)