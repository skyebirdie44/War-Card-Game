#include "War.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	char user = 'y';

	Deck h1;
	h1.shuffle();
	Hand h2, h1d, h2d;
	for (int i = 0; i < 5; i++) {
		h2.add_a_card(h1.draw_card());
	}

	Hand &h1r = h1;
	Hand &h2r = h2;
	Hand &h1dr = h1d;
	Hand &h2dr = h2d;
	while(user != 'q' && h2.get_size() + h2d.get_size() != 0) {
	war(h1r, h2r, h1dr, h2dr);
	if (h2.get_size() == 0) {
		if (h2d.get_size() == 0) {
			std::cout << "Congratulations, you lost the card game of War!\n";
			std::cout << "Would you like to play again? Y/N\n";

		} else {
			h2d.shuffle();
			h2.add_cards(h2d.get_cards());
			h2d.clear_cards();
		}
	}
	if (h1.get_size() == 0) {
		if (h1d.get_size() == 0) {
			std::cout << "Congratulations, you won the card game of War!\n";
			std::cout << "Would you like to play again? Y/N\n";

		} else {
			h1d.shuffle();
			h1.add_cards(h1d.get_cards());
			h1d.clear_cards();
		}
	}

	std::cout << h1.cards_to_string() << "\n...\n";
	std::cout << h1d.cards_to_string() << "\n...\n";
	std::cout << h2.cards_to_string() << "\n...\n";
	std::cout << h2d.cards_to_string() << "\n...\n";

	std::cin >> user;
}

	return 0;
}