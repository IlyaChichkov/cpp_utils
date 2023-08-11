all: build run 

build:
	g++ main.cpp redmath.cpp -o ./debug/main 

run:
	./debug/main

test:
	g++ test.cpp redmath.cpp ./catch2/catch_amalgamated.cpp -o ./debug/main 
	./debug/main