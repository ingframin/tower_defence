all: main.o vec2d.o
	
	mkdir ./build
	g++ ./objects/main.o ./objects/vec2d.o -o ./build/tdgame -std=c++17 -I./include -L./lib -lSDL2 -lSDL2_image -lSDL2_mixer

objects:
	mkdir ./objects
main.o: objects ./src/main.cpp
	
	g++ -c ./src/main.cpp -o ./objects/main.o -std=c++17 -I./include -L./lib -lSDL2 -lSDL2_image -lSDL2_mixer

vec2d.o: objects ./src/vec2d.cpp
	
	g++ -c ./src/vec2d.cpp -o ./objects/vec2d.o -std=c++17 


display.o: objects ./src/display.cpp
	g++ -c ./src/display.cpp -o ./objects/display.o -std=c++17 -I./include -L./lib -lSDL2 -lSDL2_image -lSDL2_mixer

clean:
	rm -rf ./build/tdgame
	rm -rf ./objects

