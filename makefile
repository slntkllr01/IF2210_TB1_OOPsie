SRCS := $(wildcard *.cpp) $(wildcard src/command/*.cpp) $(wildcard src/cpp/*.cpp) $(wildcard src/cpp/*/*.cpp)

EXECUTABLE_FILENAME = main

all: compile run

compile:
	g++ -o $(EXECUTABLE_FILENAME) $(SRCS) 

run:
	./$(EXECUTABLE_FILENAME)

