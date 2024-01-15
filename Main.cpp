
#include "War.h"
#include <cmath>
#include <string>
#include <iostream>

int main(int argc, char const *argv[])
{
	Card ace_of_spades;
	ace_of_spades.suit = Card::suit_c::spades;
	ace_of_spades.face = Card::face_c::ace;

	//Hand hand1;

	std::cout << ace_of_spades.to_string();
	//std::cout << hand1.get_size();

	return 0;
}