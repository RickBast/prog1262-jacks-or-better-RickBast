#pragma once
#include "Deck.h"
#include <iostream>

struct Card;
class Deck;
using CardPtr = std::shared_ptr<Card>;
class Hand
{
public:
	Hand();
	int size();
	void clearHand();
	void addCard(CardPtr);
	bool isPair() const;
	bool isThreeOfAKind() const;
	bool isFourOfAKind() const;
	bool isFullHouse() const;
	bool isTwoPair() const;
	bool isFlush() const;
	bool isStraight() const;
	bool isStraightFlush() const;
	bool isRoyalFlush() const;
	bool isJacksOrBetter() const;
	std::string toString();
	void sort();
	std::string handResult();

private:
	std::vector<CardPtr> _hand;
	std::set<Face> _faceset;
	std::map<Face, int> _face;
	std::map<Suit, int> _suit;
};



