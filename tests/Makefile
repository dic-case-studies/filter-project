CXXFLAGS=-std=c++14 -Wall -g -I ../include -fsanitize=address
CXX=g++

all: directories ./test-build/test-run.o ./test-build/helpers.o ./test-build/filters.o ./test-build/filterTests.o
	$(CXX) $(CXXFLAGS) ./test-build/test-run.o ./test-build/helpers.o ./test-build/filters.o test-build/filterTests.o  -l gtest -o test-app 

./test-build/test-run.o: test-run.cpp ../include/helpers.hpp ../include/filters.hpp
	$(CXX) $(CXXFLAGS) -c test-run.cpp -o $@

./test-build/helpers.o: ../src/helpers.cpp 
	$(CXX) $(CXXFLAGS) -c ../src/helpers.cpp -o $@

./test-build/filters.o: ../src/filters.cpp ../include/helpers.hpp
	$(CXX) $(CXXFLAGS) -c ../src/filters.cpp -o $@

./test-build/filterTests.o: filterTests.cpp ../include/filters.hpp
	$(CXX) $(CXXFLAGS) -c filterTests.cpp -o $@

directories: 
	mkdir -p test-build

clean:
	rm -rf ./test-build/* test-app

.PHONY: clean directories all