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
	//Card temp_c;
	for(int temp_face = Card::face_c::two; temp_face != Card::face_c::Placehold_f; temp_face++) {
		for (int temp_suit = Card::suit_c::hearts; temp_suit != Card::suit_c::Placehold_s; temp_suit++) {
			Card temp_c(static_cast<Card::face_c>(temp_face), static_cast<Card::suit_c>(temp_suit));
			add_a_card(temp_c);
		}
	}
}

std::vector<Hand> Deck::split_deck() {
	shuffle();
	Hand hand1, hand2;
	std::vector<Card> temp_c = get_cards();
	int half = get_size() / 2;
	std::vector<Card> cards1(temp_c.begin(), temp_c.end() - half);
	std::vector<Card> cards2(temp_c.begin() + half, temp_c.end());
	hand1.add_cards(cards1);
	hand2.add_cards(cards2);
	std::vector<Hand> hands = {hand1, hand2};
	return hands;
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
	"/nThe player left with all the cards in the original deck wins the game.\n";

	std::cout << "Would you like to play? Type Y for yes, N for no, Q for quit.\n";
}

int war(Hand &computer_deck, Hand &player_deck, Hand &comp_disc, Hand &player_disc) {
	int w;
	Card computer_card = computer_deck.draw_card();
	std::cout << "The computer drew a " << computer_card.to_string() << "\n";
	Card player_card = player_deck.draw_card();
	std::cout << "The computer drew a " << computer_card.to_string() << "\n";
	std::vector<Card> temp_comp, temp_play;

	if (computer_card.get_face() > player_card.get_face()) {
		std::cout << "The computer's " << computer_card.to_string() << " beats your " << player_card.to_string() << "\n";
		comp_disc.add_a_card(computer_card);
		comp_disc.add_a_card(player_card);
		w = 0;
	} else if (computer_card.get_face() < player_card.get_face()) {
		std::cout << "Your  " << computer_card.to_string() << " beats the computer's " << player_card.to_string() << "\n";
		player_disc.add_a_card(computer_card);
		player_disc.add_a_card(player_card);
		w = 1;
	} else { //player cars == computer card
		std::cout << "Your " << player_card.to_string() << " matches the computer's " << computer_card.to_string() << "\n";
		std::cout << "Prepare for War!\n";
		for (int i = 0; i < 3 && i < computer_deck.get_size(); i++) {
			if (i < 3 && computer_deck.get_size() - i == 1) {
				if (comp_disc.get_size() > 0) {
					computer_deck.add_cards(comp_disc.get_cards());
					computer_deck.shuffle();
					comp_disc.clear_cards();
					temp_comp.push_back(computer_deck.draw_card());
					std::cout << "The computer draws a card\n";
				} else { //computer has no more cards to play
					i = 3; //exit loop
					std::cout << "The computer has ran out of cards!\n";
				}
			} else {
				temp_comp.push_back(computer_deck.draw_card());
			}
		}
		for (int i = 0; i < 3 && i < player_deck.get_size(); i++) {
			if (i < 3 && player_deck.get_size() - i == 1) {
				if (player_disc.get_size() > 0) {
					player_deck.add_cards(player_disc.get_cards());
					player_deck.shuffle();
					player_disc.clear_cards();
					temp_play.push_back(player_deck.draw_card());
					std::cout << "You draw a card\n";
				} else { //player has no more cards to play
					i = 3; //exit loop
					std::cout << "You have run out of cards!\n";
				}
			} else {
				temp_play.push_back(player_deck.draw_card());
			}
		}
		//need to figure out recursive calls with refs
		w = war(&computer_deck, &player_deck, &comp_disc, &player_disc)
	}
	if (w == 0) {//computer wins
		computer_deck.add_cards(temp_comp);
		computer_deck.add_cards(temp_play);
	} else { //w == 1 so player wins
		player_deck.add_cards(temp_comp);
		player_deck.add_cards(temp_play);
	}
	return w;
}