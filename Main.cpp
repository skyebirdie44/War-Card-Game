
#include "War.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{

	prompt();

	Deck playing_cards;
	std::vector<Hand> players;
	players = playing_cards.split_deck();
	Hand computer_deck = players[0];
	Hand player_deck = players[1];

	Card computer_card, player_card;
	std::vector<Card> computer_hand, player_hand, computer_discard, player_discard;

	char user;

	std::cin >> user;

	if (user != 'n' || user != 'N' || user != 'q' || user != 'Q') {
		std::cout << "Type D to draw a card.\n";
		std::cin >> user;
	}

	while(user != 'n' || user != 'N' || user != 'q' || user != 'Q') {
		if (computer_deck.get_size() == 0) {
			std::cout << "Congratulations, you won the card game of War!\n";
		} else if (player_deck.get_size() == 0) {
			std::cout << "Oh no, you lost the card game of War!\n";
		} else {
			computer_card = computer_deck.draw_card();
			std::cout << "The computer drew a " << computer_card.to_string() << "\n";
			player_card = player_deck.draw_card();
			std::cout << "The computer drew a " << computer_card.to_string() << "\n";
		}
	}


	return 0;
}