
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
	//std::cout << playing_cards.get_size() << "\n";
	std::vector<Hand> players;
	players = playing_cards.split_deck();
	Hand computer_deck = players[0];
	Hand player_deck = players[1];
	//std::cout << computer_deck.get_size() << "\n";
	//std::cout << player_deck.get_size() << "\n";

	Card computer_card, player_card;
	Hand computer_discard, player_discard;

	char user;

	std::cin >> user;

	if (user != 'n' || user != 'N' || user != 'q' || user != 'Q') {
		std::cout << "Type D to draw a card.\n";
		std::cin >> user;
	}
	Hand &cdeck_r = computer_deck;
	Hand &pdeck_r = player_deck;
	Hand &cdisc_r = computer_discard;
	Hand &pdisc_r = player_discard;

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
			war(cdeck_r, pdeck_r, cdisc_r, pdisc_r);
		}
		std::cout << "The computer has " << computer_deck.get_size() + computer_discard.get_size() << " cards\n";
		std::cout << "You have " << player_deck.get_size() + player_discard.get_size() << " cards\n";
		std::cout << "\nType D to draw a card.\n";
		std::cin >> user;
	}


	return 0;
}