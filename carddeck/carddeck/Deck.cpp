#include "Deck.h"


Deck::Deck()
{

	if (_deck.size() != 0)
		_deck.clear();

	std::set<Card> cards;
	for (auto s : Card::suits)
		for (auto f : Card::faces)
			_deck.push_back(std::make_shared<Card>(Card(f, s)));

	_topOfDeck = _deck.size() - 1;
}


void Deck::shuffle()
{
	for (int i = 0; i < _deck.size(); ++i)
	{
		std::swap(_deck[i], _deck [i + (rand() % (_deck.size()-i))]);
	}
	_topOfDeck = _deck.size()-1;
}

void Deck::sort()
{
	std::sort(_deck.begin(), _deck.end(), [](CardPtr lhs, CardPtr rhs) { return (*lhs < *rhs);});
}

CardPtr Deck::draw()
{
	return _deck.at(_topOfDeck--);
}

CardPtr Deck::cut()
{
	return _deck[rand() % _deck.size()];
}

bool Deck::isEmpty() const
{
	return (_topOfDeck < 0);
}

