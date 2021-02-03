test_main: test_array.o test_main.o
	g++ -Wall -Wextra -pedantic -g -std=c++17 test_array.o test_main.o -o test_main

test_array.o: test_array.cpp
	g++ -c -Wall -Wextra -pedantic -g -std=c++17 test_array.cpp

test_main.o: test_main.cpp
	g++ -c -Wall -Wextra -pedantic -g -std=c++17 test_main.cpp

clean:
	rm -f *.o test_main
