///////////////////////////////////////////////////////////////////////
// File:  Hand.h
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
#include "Deck.h"
#include <iostream>

struct Card;


using CardPtr = std::shared_ptr<Card>;
enum class PokerHand { NADA, JACKS_OR_BETTER, TWO_PAIRS, THREE_OF_A_KIND, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, STRAIGHT_FLUSH, ROYAL_FLUSH };
class Hand
{
public:
	Hand();
	int size();
	void clearHand();
	void addCard(CardPtr);
	void drawOrHold();
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
	std::string toStringNoHold();
private:
	std::vector<std::pair<CardPtr, bool> > _hand;
	std::set<Face> _faceset;
};