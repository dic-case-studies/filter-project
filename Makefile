CXXFLAGS=-O3 -std=c++11
CXX=g++

all: directories build/main.o build/helpers.o build/filters.o
	$(CXX) $(CXXFLAGS) -o app ./build/main.o ./build/helpers.o ./build/filters.o

build/main.o: main.cpp ./include/helpers.hpp ./include/filters.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o $@

build/helpers.o: ./src/helpers.cpp 
	$(CXX) $(CXXFLAGS) -c ./src/helpers.cpp -o $@

build/filters.o: ./src/filters.cpp ./include/helpers.hpp
	$(CXX) $(CXXFLAGS) -c ./src/filters.cpp -o $@

# build/%.o: ./src/%.cpp
# 	$(CXX) $(CXXFLAGS) -c 

directories: 
	mkdir -p build

clean:
	rm -rf ./build/* app

.PHONY: clean directories all
