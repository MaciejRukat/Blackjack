all: blackjack

blackjack: main.o card.o deck.o hand.o player.o dealer.o game.o
	g++ main.o card.o deck.o hand.o player.o dealer.o game.o -o blackjack

main.o: src/main.cpp include/card.h include/deck.h include/player.h include/dealer.h include/game.h
	g++ -Iinclude -Wall -Wextra -g -c src/main.cpp -o main.o

card.o: src/card.cpp include/card.h
	g++ -Iinclude -Wall -Wextra -g -c src/card.cpp -o card.o

deck.o: src/deck.cpp include/deck.h include/card.h
	g++ -Iinclude -Wall -Wextra -g -c src/deck.cpp -o deck.o

hand.o: src/hand.cpp include/hand.h include/card.h
	g++ -Iinclude -Wall -Wextra -g -c src/hand.cpp -o hand.o

player.o: src/player.cpp include/player.h include/hand.h
	g++ -Iinclude -Wall -Wextra -g -c src/player.cpp -o player.o

dealer.o: src/dealer.cpp include/dealer.h include/hand.h
	g++ -Iinclude -Wall -Wextra -g -c src/dealer.cpp -o dealer.o

game.o: src/game.cpp include/game.h include/player.h include/dealer.h include/deck.h
	g++ -Iinclude -Wall -Wextra -g -c src/game.cpp -o game.o