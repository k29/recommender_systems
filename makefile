all: sushi.h sushi.cpp sushi.o
	g++ sushi.o sushi.cpp -o sushi
	
sushi.o: sushi.h sushi.cpp
	g++ -c sushi.cpp


