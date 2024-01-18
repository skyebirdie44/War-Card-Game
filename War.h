#ifndef WAR_H
#define WAR_H

#include <string>
#include <vector>

//#include "War.cpp"

//using std::vector;


class Card {
public:
	enum suit_c {
		hearts,
		diamonds,
		clubs,
		spades,
		Placehold_s
	};

	enum face_c {
    	two   = 2,
    	three = 3,
    	four  = 4,
    	five  = 5,
    	six   = 6,
    	seven = 7,
    	eight = 8,
    	nine  = 9,
    	ten   = 10,
    	jack  = 11,
    	queen = 12,
    	king  = 13,
    	ace = 14,
    	Placehold_f
	};
	suit_c suit = suit_c::hearts;
	face_c face = face_c::two;

	Card();
	Card(face_c face_in, suit_c suit_in);
	std::string to_string();
};

class Hand {
private:
	std::vector<Card> card_stack;
public:
	std::vector<Card> get_cards();
	void add_a_card(Card a_card);
	void add_cards(std::vector<Card> cards);
	void shuffle();
	Card draw_card();
	int get_size();
	std::string cards_to_string();
};

class Deck: public Hand {
public:
	Deck();
	std::vector<Hand> split_deck();
};

/*void prompt();

int war(Card comp_card, Card play_card, Hand &computer_deck, Hand &player_deck);*/

#endif