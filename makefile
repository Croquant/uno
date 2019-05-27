uno: main.o Hand.o Deck.o Card.o
	g++ main.o Hand.o Deck.o Card.o -o uno

main.o: main.cpp
	g++ -c main.cpp

Hand.o: Hand.cpp Hand.h
	g++ -c Hand.cpp Hand.h

Card.o: Card.cpp Card.h
	g++ -c Card.cpp Card.h

Deck.o: Deck.cpp Deck.h
	g++ -c Deck.cpp Deck.h

clean:
	rm *.o *.gch uno
