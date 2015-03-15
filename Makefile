blackjack: blackjack.o
	g++ blackjack.o -o blackjack -std=c++11
	
blackjack.o: blackjack.cpp HelperLib/datastructs.h
	g++ -c -g blackjack.cpp -std=c++11

clean:
	rm -f *o blackjack
