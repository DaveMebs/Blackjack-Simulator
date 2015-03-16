simulator: simulator.o
	g++ simulator.o -o simulator -std=c++11

simulator.o: simulator.cpp blackjack.h datastructs.h
	g++ -c -g simulator.cpp -std=c++11

clean:
	rm -f *o simulator
