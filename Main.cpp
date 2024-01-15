
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

	Hand hand1, hand2, hand3;
	hand1.add_cards(one_card_hand);

	Deck deck1;
	std::vector<Hand> players = deck1.split_deck();
	hand2 = players[0];
	hand3 = players[1];

	//deck1.shuffle();

	std::cout << ace_of_spades.to_string() << "\n";
	std::cout << hand1.get_size() << "\n";
	std::cout << deck1.get_size() << "\n";
	//std::cout << deck1.cards_to_string() << "\n";
	std::cout << hand2.get_size() << "\n";
	std::cout << hand3.get_size() << "\n";
	std::cout << hand2.cards_to_string() << "\n";
	hand2.shuffle();
	std::cout << hand2.cards_to_string() << "\n";
	hand2.shuffle();
	std::cout << hand2.cards_to_string() << "\n";

	return 0;
}