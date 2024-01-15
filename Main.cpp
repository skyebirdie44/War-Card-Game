
#include "War.h"
#include <cmath>
#include <string>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
	Card ace_of_spades;
	ace_of_spades.suit = Card::suit_c::spades;
	ace_of_spades.face = Card::face_c::ace;

	std::vector<Card> one_card_hand;
	one_card_hand.push_back(ace_of_spades);

	Hand hand1;
	hand1.add_cards(one_card_hand);

	Deck deck1;

	std::cout << ace_of_spades.to_string() << "\n";
	std::cout << hand1.get_size() << "\n";
	std::cout << deck1.get_size() << "\n";
	std::cout << deck1.cards_to_string() << "\n";

	return 0;
}