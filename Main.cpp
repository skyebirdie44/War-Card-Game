
#include "War.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

//This function simulates the card game War. refer to the README.txt file for how to play the game.
int main(int argc, char const *argv[])
{
	//initializing the game
	Deck computer_deck;
	Hand player_deck = computer_deck.split_deck();
	Card computer_card, player_card;
	Hand computer_discard, player_discard;
	bool won = false;

	//prompt the user to play the game
	prompt();
	char user;
	std::cin >> user;

	if (user != 'n' || user != 'N' || user != 'q' || user != 'Q') { //if user wants to play
		std::cout << "Type D to draw a card.\n";
		std::cin >> user;
	}

	while((user == 'd' || user == 'D') && won == false) { //while user wants to play
		war(computer_deck, player_deck, computer_discard, player_discard);
		if (computer_deck.get_size() == 0) {
			if (computer_discard.get_size() == 0) {
				std::cout << "\nCongratulations, you won the card game of War!\n";
				std::cout << "Would you like to play again? Y/N\n";
				std::cin >> user;
				won = true;
			} else {
				computer_discard.shuffle();
				computer_deck.add_cards(computer_discard.get_cards());
				computer_discard.clear_cards();
			}
		}
		if (player_deck.get_size() == 0) {
			if (player_discard.get_size() == 0) {
				std::cout << "\nOh no, you lost the card game of War!\n";
				std::cout << "Would you like to play again? Y/N\n";
				std::cin >> user;
				won = true;
			} else {
				player_discard.shuffle();
				player_deck.add_cards(player_discard.get_cards());
				player_discard.clear_cards();
			}
		}
		if (computer_deck.get_size() != 0 && player_deck.get_size() != 0) {
			std::cout << "\nThe computer has " << computer_deck.get_size() + computer_discard.get_size() << " cards\n";
			std::cout << "You have " << player_deck.get_size() + player_discard.get_size() << " cards\n";
			int comp = computer_deck.get_size() + computer_discard.get_size();
			int play = player_discard.get_size() + player_deck.get_size();
		}

		if (won == false) {
			std::cout << "\nType D to draw a card.\n";
			std::cin >> user;
		} else {
			if (user == 'y' || user != 'Y') {
				won = false;
				computer_deck.add_cards(player_deck.get_cards());
				computer_deck.add_cards(player_discard.get_cards());
				computer_deck.add_cards(computer_discard.get_cards());
				player_deck.clear_cards();
				computer_discard.clear_cards();
				player_discard.clear_cards();
				computer_deck.shuffle();
				player_deck = computer_deck.split_deck();
				std::cout << "\nNew Game!\n\nType D to draw a card\n";
				std::cin >> user;
			} else {
				std::cout << "Goodbye\n";
			}
		} 
		if (user == 'p') {
			std::cout << computer_deck.cards_to_string() << "\n...\n";
			std::cout << computer_discard.cards_to_string() << "\n...\n";
			std::cout << player_deck.cards_to_string() << "\n...\n";
			std::cout << player_discard.cards_to_string() << "\n...\n";

			std::cin >> user;
		}
	}


	return 0;
}