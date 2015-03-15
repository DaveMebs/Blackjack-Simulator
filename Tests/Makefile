shoe_tests: shoe_tests.o
	g++ shoe_tests.o -o shoe_tests -std=c++11
	
shoe_tests.o: shoe_tests.cpp ../blackjack.cpp
	g++ -c -g shoe_tests.cpp -std=c++11

clean:
	rm -f *o shoe_tests
