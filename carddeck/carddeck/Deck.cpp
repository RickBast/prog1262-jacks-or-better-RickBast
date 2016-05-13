///////////////////////////////////////////////////////////////////////
// File:  Deck.cpp
//
// Author: Ricky Bastarache 
// This assignment represents my own work and is in accordance with the College Academic Policy
//
// Copyright (c) 2016 All Right Reserved by Dave Burchill
// Contributors: 
// Description:  
//
// Date: May 2016
//
// Revisions:
//
/////////////////////////////////////////////////////////////////////
#include "Deck.h"
#include <chrono>

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
	srand(static_cast<unsigned int>(time(0)));
	for (int i = 0; i < _deck.size(); ++i)
		std::swap(_deck[i], _deck[i + (rand() % (_deck.size() - i))]);
	_topOfDeck = _deck.size() - 1;
}

CardPtr Deck::draw()
{
	return _deck.at(_topOfDeck--);
}

bool Deck::isEmpty() const
{
	return (_topOfDeck < 0);
}