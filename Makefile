all: growable_example example test_main

growable_example: growable_example.o int_array.o
	g++ -Wall -Wextra -pedantic -g -std=c++17 growable_example.o int_array.o -o growable_example

example: example.o int_array.o
	g++ -Wall -Wextra -pedantic -g -std=c++17 example.o int_array.o -o example

test_main: test_main.o test_array.o int_array.o
	g++ -Wall -Wextra -pedantic -g -std=c++17 test_main.o test_array.o int_array.o -o test_main

int_array.o: int_array.cpp
	g++ -Wall -Wextra -pedantic -g -std=c++17 int_array.cpp -c -o int_array.o

growable_example.o: growable_example.cpp
	g++ -Wall -Wextra -pedantic -g -std=c++17 growable_example.cpp -c

example.o: example.cpp
	g++ -Wall -Wextra -pedantic -g -std=c++17 example.cpp -c

test_main.o: test_main.cpp
	g++ -Wall -Wextra -pedantic -g -std=c++17 test_main.cpp -c

test_array.o: test_array.cpp
	g++ -Wall -Wextra -pedantic -g -std=c++17 test_array.cpp -c

clean:
	rm -f *.o growable_example example test_main