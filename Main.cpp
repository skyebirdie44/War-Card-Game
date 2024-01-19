
#include "War.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

//This function simulates the card game War. refer to the README.txt file for how to play the game.
int main(int argc, char const *argv[])
{
	//initializing the game
	Deck playing_cards;
	std::vector<Hand> players;
	players = playing_cards.split_deck();
	Hand computer_deck = players[0];
	Hand player_deck = players[1];
	Card computer_card, player_card;
	Hand computer_discard, player_discard;

	//prompt the user to play the game
	prompt();
	char user;
	std::cin >> user;

	if (user != 'n' || user != 'N' || user != 'q' || user != 'Q') { //if user wants to play
		std::cout << "Type D to draw a card.\n";
		std::cin >> user;
	}

	//references need to be used to change the actual decks in the war function
	Hand &cdeck_r = computer_deck;
	Hand &pdeck_r = player_deck;
	Hand &cdisc_r = computer_discard;
	Hand &pdisc_r = player_discard;

	while(user == 'd' || user == 'D') { //while user wants to play
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
		std::cout << "\nThe computer has " << computer_deck.get_size() + computer_discard.get_size() << " cards\n";
		std::cout << "You have " << player_deck.get_size() + player_discard.get_size() << " cards\n";
		std::cout << "\nType D to draw a card.\n";
		std::cin >> user;
	}


	return 0;
}