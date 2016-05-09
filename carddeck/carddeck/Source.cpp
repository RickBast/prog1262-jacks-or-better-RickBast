#include <iostream>
#include "Card.h"
#include "Deck.h"
#include "Hand.h"
#include <chrono>

using std::cout;
using std::endl;

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	Deck deck;
	Hand hand;
	deck.sort();
	deck.shuffle();


	while (hand.size() < 5)
		hand.addCard(deck.draw());
	cout << hand.toString() << endl;
		

	//while (hand.isTwoPair() == false)
	//{
	//	hand.clearHand();
	//	deck.shuffle();
	//	while (hand.size() < 5)
	//		hand.addCard(deck.draw());
	//	cout << hand.toString() << endl;


	system("pause");

}

