
#include "War.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
/*
	Card ace_spades(Card::face_c::ace, Card::suit_c::spades);
	std::cout << ace_spades.to_string();

	Hand h1, h2;
	//std::vector<Card> card_v = {ace_spades};
	//h1.add_a_card(ace_spades);
	//std::cout << h1.cards_to_string();

	Deck d1;
	std::vector<Hand> deck_split = d1.split_deck();
	h1 = deck_split[0];
	std::cout << h1.cards_to_string();*/


	prompt();

	Deck playing_cards;
	std::vector<Hand> players;
	players = playing_cards.split_deck();
	Hand computer_deck = players[0];
	Hand player_deck = players[1];

	Card computer_card, player_card;
	Hand computer_hand, player_hand, computer_discard, player_discard;

	char user;

	std::cin >> user;

	if (user != 'n' || user != 'N' || user != 'q' || user != 'Q') {
		std::cout << "Type D to draw a card.\n";
		std::cin >> user;
	}

	while(user != 'n' || user != 'N' || user != 'q' || user != 'Q') {
		if (computer_deck.get_size() == 0) {
			if (computer_discard.get_size() == 0) {
				std::cout << "Congratulations, you won the card game of War!\n";
			} else {
				computer_discard.shuffle();
				computer_deck.add_cards(computer_discard.get_cards());
				computer_discard.clear_cards();
			}
		} else if (player_deck.get_size() == 0) {
			if (player_discard.get_size() == 0) {
				std::cout << "Oh no, you lost the card game of War!\n";
			} else {
				player_discard.shuffle();
				player_deck.add_cards(player_discard.get_cards());
				player_discard.clear_cards();
			}
		} else {
			//war
		}
	}


	return 0;
}