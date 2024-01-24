#ifndef WAR_H
#define WAR_H

#include <string>
#include <vector>

//#include "War.cpp"

//using std::vector;

/*** Class Card ***
	The Card class is comprised of the two attributes of a playing card: a suit and a face value.
	In the card game War, an ace is the highest rank. With this class, you are able to create a card
	as well as retrieve a numeric representation of the face value of the card. This class definition
	will also return the type of card in string value, i.e. if the card's suit is spades and the face
	value is ace, a user can retrieve the string "Ace of Spades"
*/
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
	int get_face();
	std::string to_string();
};

/*** Class Hand ***
 	This class is representative of a group of cards. The one attribute of the class is a vector of Card class
 	objects. This class allows a user to get the vector of Cards in the class, add a single Card or a vector
 	of Cards to the class, shuffle the attribute vector of Cards, get the size of the group of Cards, get a
 	string list of the cards in the vector attribute, or clear all the cards in the group of Cards.
*/
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
	void clear_cards();
};

/*** Class Deck ***
	The Deck class is a child class of the Hand parent class. The Deck class has all the same attributes and
	functions as the Hand class, except the constructor initializes a full 52 card deck as the Card vector
	attribute and has an additional function to split the deck into two even hands.
*/
class Deck: public Hand {
public:
	Deck();
	Hand split_deck();
};

/*** Function prompt ***
	The prompt function prints the game rules to the command line and asks the user if they would like to play.
*/
void prompt();

/*** Function war ***
	The war function is a recursive function that serves as the main part of the card game. This function takes
	in the computer and player decks and discard piles as inputs and returns an int value designating the winner
	of that round (0 for computer, 1 for player).
*/
int war(Hand &computer_deck, Hand &player_deck, Hand &comp_disc, Hand &player_disc);

/*** Function war_draw ***
	The war_draw function is used to draw the 3 "face down" cards during the war game when the player
	and computer draw the same card. This has logic for different card amount scenarios.
*/
int war_draw(Hand &tbl, Hand &plyr, Hand &plyr_d, std::string line, std::string no_cards);

#endif