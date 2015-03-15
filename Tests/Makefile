all: linkedlist_tests stack_tests shoe_tests

linkedlist_tests: linkedlist_tests.o
	g++ linkedlist_tests.o -o bin/linkedlist_tests -std=c++11
	
linkedlist_tests.o: linkedlist_tests.cpp ../datastructs.h
	g++ -c -g linkedlist_tests.cpp -std=c++11

stack_tests: stack_tests.o
	g++ stack_tests.o -o bin/stack_tests -std=c++11

stack_tests.o: stack_tests.cpp ../datastructs.h
	g++ -c -g stack_tests.cpp -std=c++11

shoe_tests: shoe_tests.o
	g++ shoe_tests.o -o bin/shoe_tests -std=c++11

shoe_tests.o: shoe_tests.cpp ../blackjack.cpp
	g++ -c -g shoe_tests.cpp -std=c++11

clean:
	rm -f *o bin/*
