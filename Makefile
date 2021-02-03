test_main: test_array.o test_main.o int_array.o
	g++ -Wall -Wextra -pedantic -g -std=c++17 test_array.o test_main.o int_array.o -o test_main

test_array.o: test_array.cpp
	g++ -c -Wall -Wextra -pedantic -g -std=c++17 test_array.cpp

test_main.o: test_main.cpp
	g++ -c -Wall -Wextra -pedantic -g -std=c++17 test_main.cpp

int_array.o: int_array.cpp
	g++ -c -Wall -Wextra -pedantic -g -std=c++17 int_array.cpp

clean:
	rm -f *.o test_main
