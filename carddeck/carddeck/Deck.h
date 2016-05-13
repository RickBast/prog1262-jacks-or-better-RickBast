///////////////////////////////////////////////////////////////////////
// File:  Deck.h
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
#pragma once
#include "Card.h"
#include <memory>
#include <algorithm>

struct Card;
using CardPtr = std::shared_ptr<Card>;
class Deck
{
public:
	Deck();// creates every card and puts them in a vector
	void shuffle();// shuffles every card in _deck
	CardPtr draw();// draws card from top of deck
	bool isEmpty() const; // checks to see if the deck is out of cards
private:
	std::vector<CardPtr> _deck;//holds the deck
	int _topOfDeck;
};