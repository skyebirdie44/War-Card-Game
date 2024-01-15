#ifndef WAR_H
#define WAR_H

#include <string>
#include <vector>

//#include "War.cpp"

//using std::vector;


class Card {
public:
	enum class suit_c : unsigned char {
		hearts,
		diamonds,
		clubs,
		spades
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
    	ace = 14
	};
	suit_c suit = suit_c::hearts;
	face_c face = face_c::two;

	std::string to_string();
};

class Hand {
private:
	std::vector<Card> card_stack;

public:
	void add_cards(std::vector<Card> cards);
	//void shuffle();
	//card draw();
	int get_size();
};

/*class Hand::Deck {
public:
	<Deck>();
};*/

#endif