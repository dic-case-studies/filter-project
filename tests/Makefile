all: test.o helpers.o filters.o filterTests.o
	g++ -std=c++11 -o test-app ./test-build/test.o ./test-build/helpers.o ./test-build/filters.o test-build/filterTests.o

test.o: test.cpp ../include/helpers.hpp ../include/filters.hpp filterTests.hpp
	g++ -std=c++11 -c test.cpp -o ./test-build/test.o

helpers.o: ../src/helpers.cpp 
	g++ -std=c++11 -c ../src/helpers.cpp -o ./test-build/helpers.o

filters.o: ../src/filters.cpp ../include/helpers.hpp
	g++ -std=c++11 -c ../src/filters.cpp -o ./test-build/filters.o

filterTests.o: filterTests.cpp ../include/filters.hpp
	g++ -std=c++11 -c filterTests.cpp -o ./test-build/filterTests.o

clean:
	rm -rf ./test-build/* test-app