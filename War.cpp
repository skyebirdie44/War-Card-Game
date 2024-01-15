#include <cmath>
#include <string>
#include <iostream>

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
	 	case Card::suit_c::hearts:
	 		s = "Hearts";
	 		break;
	 	case Card::suit_c::diamonds:
	 		s = "Diamonds";
	 		break;
	 	case Card::suit_c::clubs:
	 		s = "Clubs";
	 		break;
	 	case Card::suit_c::spades:
	 		s = "Spades";
	 		break;
	 	default:
	 		s = "NaN";
	}

	return f + " of " + s;
}

/*int Hand::get_size() {
	return size(cards);
}*/