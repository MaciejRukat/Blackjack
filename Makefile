all: blackjack

blackjack: main.o card.o deck.o hand.o player.o dealer.o game.o input.o
	g++ main.o card.o deck.o hand.o player.o dealer.o game.o input.o -o blackjack

main.o: src/main.cpp
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/main.cpp -o main.o

card.o: src/card.cpp include/card.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/card.cpp -o card.o

deck.o: src/deck.cpp include/deck.h include/card.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/deck.cpp -o deck.o

hand.o: src/hand.cpp include/hand.h include/card.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/hand.cpp -o hand.o

player.o: src/player.cpp include/player.h include/hand.h include/card.h include/input.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/player.cpp -o player.o

dealer.o: src/dealer.cpp include/dealer.h include/hand.h include/card.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/dealer.cpp -o dealer.o

game.o: src/game.cpp include/game.h include/player.h include/dealer.h include/deck.h include/hand.h include/card.h include/input.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/game.cpp -o game.o

input.o: src/input.cpp include/input.h
	g++ -std=c++17 -Iinclude -Wall -Wextra -g -c src/input.cpp -o input.o

run: blackjack
	./blackjack

clean:
	rm -f main.o card.o deck.o hand.o player.o dealer.o game.o input.o blackjack

.PHONY: all run clean