all: directories main.o helpers.o filters.o
	g++ -std=c++11 -o app ./build/main.o ./build/helpers.o ./build/filters.o

main.o: directories main.cpp ./include/helpers.hpp ./include/filters.hpp
	g++ -std=c++11 -c main.cpp -o ./build/main.o

helpers.o: directories ./src/helpers.cpp 
	g++ -std=c++11 -c ./src/helpers.cpp -o ./build/helpers.o

filters.o: directories ./src/filters.cpp ./include/helpers.hpp
	g++ -std=c++11 -c ./src/filters.cpp -o ./build/filters.o

directories: 
	mkdir -p build

clean:
	rm -rf ./build/* app