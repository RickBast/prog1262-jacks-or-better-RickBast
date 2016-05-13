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