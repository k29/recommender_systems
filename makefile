all: sushi.h sushi.cpp sushi.o testsushi.cpp
	g++ sushi.o testsushi.cpp sushi.cpp -o sushi

sushi.o: sushi.h sushi.cpp
	g++ -c sushi.cpp


