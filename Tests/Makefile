all: datastructs_tests blackjack_tests

datastructs_tests: datastructs_tests.o
	g++ datastructs_tests.o -o bin/datastructs_tests -std=c++11
	
datastructs_tests.o: datastructs_tests.cpp ../datastructs.h
	g++ -c -g datastructs_tests.cpp -std=c++11

blackjack_tests: blackjack_tests.o
	g++ blackjack_tests.o -o bin/blackjack_tests -std=c++11

blackjack_tests.o: blackjack_tests.cpp ../blackjack.h
	g++ -c -g blackjack_tests.cpp -std=c++11

clean:
	rm -f *o bin/*
