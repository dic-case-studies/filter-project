CXXFLAGS=-O3 -std=c++11 -Wall
CXX=g++

all: benchmark-app main-app

benchmark-app: directories build/benchmark.o build/helpers.o build/filters.o
	$(CXX) $(CXXFLAGS) ./build/benchmark.o ./build/helpers.o ./build/filters.o -o $@

build/benchmark.o: benchmark.cpp ./include/helpers.hpp ./include/filters.hpp
	$(CXX) $(CXXFLAGS) -c benchmark.cpp -o $@

main-app: directories build/main.o build/helpers.o build/filters.o
	$(CXX) $(CXXFLAGS) ./build/main.o ./build/helpers.o ./build/filters.o -o $@

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
