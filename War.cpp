#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <algorithm>
#include <random>

#include "War.h"


std::string Card::to_string() {
	std::string f;
	std::string s;
	switch (face)
	{
		case 2:
			f = "Two";
			break;
		case 3:
			f = "Three";
			break;
		case 4:
			f = "Four";
			break;
		case 5:
			f = "Five";
			break;
		case 6:
			f = "Six";
			break;
		case 7:
			f = "Seven";
			break;
		case 8:
			f = "Eight";
			break;
		case 9:
			f = "Nine";
			break;
		case 10:
			f = "Ten";
			break;
		case 11:
			f = "Jack";
			break;
		case 12:
			f = "Queen";
			break;
		case 13:
			f = "King";
			break;
		case 14:
			f = "Ace";
			break;
		default:
			f = "NaN";
	}

	switch (suit)
	{
	 	case hearts:
	 		s = "Hearts";
	 		break;
	 	case diamonds:
	 		s = "Diamonds";
	 		break;
	 	case clubs:
	 		s = "Clubs";
	 		break;
	 	case spades:
	 		s = "Spades";
	 		break;
	 	default:
	 		s = "NaN";
	}

	return f + " of " + s;
}

int Hand::get_size() {
	return card_stack.size();
}

void Hand::add_cards(std::vector<Card> cards) {
	card_stack.insert(card_stack.end(), cards.begin(), cards.end());
}

std::string Hand::cards_to_string() {
	std::string cards_string;
	for (int i=0; i < card_stack.size(); i++) {
		cards_string = cards_string + card_stack[i].to_string() + "\n";
	}
	return cards_string;
}

void Hand::shuffle() {
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(card_stack), std::end(card_stack), rng);
}

Deck::Deck() {
	Card temp_c;
	for(int temp_face = Card::face_c::two; temp_face != Card::face_c::Placehold_f; temp_face++) {
		for (int temp_suit = Card::suit_c::hearts; temp_suit != Card::suit_c::Placehold_s; temp_suit++) {
			temp_c.face = static_cast<Card::face_c>(temp_face);
			temp_c.suit = static_cast<Card::suit_c>(temp_suit);
			card_stack.push_back(temp_c);
		}
	}
}

std::vector<Hand> Deck::split_deck() {
	/*int index;
	srand(time(0));
	for(int i = 0; i < div; i++) {
		index = rand() % card_stack.size();
		hand1.card_stack.push_back(card_stack[index]);
		card_stack.erase(card_stack.begin() + index);
		index = rand() % card_stack.size();
		hand2.card_stack.push_back(card_stack[index]);
		card_stack.erase(card_stack.begin() + index);
	}*/

	shuffle();
	Hand hand1, hand2;
	int half = card_stack.size() / 2;
	std::vector<Card> cards1(card_stack.begin(), card_stack.end() - half);
	std::vector<Card> cards2(card_stack.begin() + half, card_stack.end());
	hand1.card_stack = cards1;
	hand2.card_stack = cards2;
	std::vector<Hand> hands = {hand1, hand2};
	return hands;
}