#pragma once
#include "Card.h"
#include <memory>
#include <algorithm>

struct Card;
using CardPtr = std::shared_ptr<Card>;
class Deck
{
public:
	Deck();

	void shuffle();
	void sort();
	CardPtr draw();
	CardPtr cut();
	bool isEmpty() const;
private:
	std::vector<CardPtr> _deck;
	int _topOfDeck;
};

