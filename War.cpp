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

Card::Card() {
	face = two;
	suit = hearts;
}

Card::Card(face_c face_in, suit_c suit_in) {
	face = face_in;
	suit = suit_in;
}

int Card::get_face() {
	return static_cast<Card::face_c>(face);
}

std::vector<Card> Hand::get_cards() {
	return card_stack;
}

int Hand::get_size() {
	return card_stack.size();
}

void Hand::add_a_card(Card a_card) {
	card_stack.push_back(a_card);
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
	srand(time(0));
	std::random_shuffle(std::begin(card_stack), std::end(card_stack));
}

Card Hand::draw_card() {
	Card last = card_stack.back();
	card_stack.pop_back();
	return last;
}

void Hand::clear_cards() {
	card_stack.clear();
}

Deck::Deck() {
	//the card class enum values are used like integers to index and initialize a full deck
	for(int temp_face = Card::face_c::two; temp_face != Card::face_c::Placehold_f; temp_face++) {
		for (int temp_suit = Card::suit_c::hearts; temp_suit != Card::suit_c::Placehold_s; temp_suit++) {
			Card temp_c(static_cast<Card::face_c>(temp_face), static_cast<Card::suit_c>(temp_suit));
			add_a_card(temp_c);
		}
	}
}

Hand Deck::split_deck() {
	shuffle();
	Hand hand2;
	for (int i = 0; i < 26; i++){
		hand2.add_a_card(draw_card());
	}
	return hand2;
}

void prompt() {
	std::cout << "Hello and welcome to the executable version of the card game War."
	"This game uses a standard 52 card deck with no jokers.\n"
	"\nHOW TO PLAY:\n"
	"The 52 card deck is shuffled and split evenly into 2 hands, one hand for each player.\n"
	"For each round, each player draws the top card from their hand and lays the card face up.\n" 
	"Whichever card ranks highest (2 is lowest, ace is highest) wins that round.\n"
	"If both cards are the same, 3 more cards are drawn face down and the fourth card is drawn face up to again compare rank.\n"
	"\nThis continues until there is a winner. The winner takes all the cards used in that round into their discard pile.\n"
	"Rounds continue until either player runs out of cards in their hand.\n"
	"Then that user shuffles their discard pile and uses that as their new hand to continue playing.\n"
	"\nThe player left with all the cards in the original deck wins the game.\n";

	std::cout << "\nWould you like to play? Type Y for yes, N for no, Q for quit.\n";
}

int war(Hand &computer_deck, Hand &player_deck, Hand &comp_disc, Hand &player_disc) {
	Hand table;
	//first we draw a card from each deck
	int w;
	Card computer_card = computer_deck.draw_card();
	if (computer_card.to_string() == "NaN of NaN") {
		std::cout << computer_deck.cards_to_string();
	}
	std::cout << "\nThe computer drew a " << computer_card.to_string() << "\n";
	
	Card player_card = player_deck.draw_card();
	if (player_card.to_string() == "NaN of NaN") {
			std::cout << player_deck.cards_to_string();
	}
	std::cout << "You drew a " << player_card.to_string() << "\n";


	if (computer_card.get_face() > player_card.get_face()) { //computer won
		std::cout << "The computer's " << computer_card.to_string() << " beats your " << player_card.to_string() << "\n";
		w = 0;
	} else if (computer_card.get_face() < player_card.get_face()) { //player won
		std::cout << "Your " << player_card.to_string() << " beats the computer's " << computer_card.to_string() << "\n";
		w = 1;
	} else { //player card == computer card
		std::cout << "Your " << player_card.to_string() << " matches the computer's " << computer_card.to_string() << "\n";
		std::cout << "\nPrepare for War!\n";

		std::string s = "The computer draws a card\n";
		std::string i = "The computer has no more cards to play!\n";
		int c = war_draw(table, computer_deck, comp_disc, s, i);

		s = "You draw a card\n";
		i = "You have no more cards to play!\n";
		int p = war_draw(table, player_deck, player_disc, s, i);

		if (c == 0) {
			std::cout << "noccards\n";
			computer_deck.add_a_card(computer_card);
		}

		if (p == 0) {
			std::cout << "nopcards\n";
			player_deck.add_a_card(player_card);
		}

		w = war(computer_deck, player_deck, comp_disc, player_disc);
	}

	table.add_a_card(computer_card);
	table.add_a_card(player_card);

	if (w == 0) {//computer wins & takes all the cards played
		comp_disc.add_cards(table.get_cards());
	} else { //w == 1 so player wins & takes all the cards played
		player_disc.add_cards(table.get_cards());
	}

	return w;

}

int war_draw(Hand &tbl, Hand &plyr, Hand &plyr_d, std::string card_draw, std::string no_cards) {
	int n = 0;
	for(int i = 0; (i < 3) && ((plyr.get_size() + plyr_d.get_size()) > 1); i++) {
		if (plyr.get_size() == 0) {
			plyr.add_cards(plyr_d.get_cards());
			plyr_d.clear_cards();
		}
		Card c = plyr.draw_card();
		if (c.to_string() == "NaN of NaN") {
			std::cout << plyr.cards_to_string();
		}
		std::cout << card_draw;
		tbl.add_a_card(c);
		n = i + 1;
	}
	if (n < 3) {
		std::cout << no_cards;
	}
	return n;
}