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
enum class PokerHand { NADA, JACKS_OR_BETTER, TWO_PAIRS, THREE_OF_A_KIND, FOUR_OF_A_KIND, FULL_HOUSE, FLUSH, STRAIGHT, STRAIGHT_FLUSH, ROYAL_FLUSH };// enum of every poker hand
class Hand
{
public:
	Hand();
	int size();// gets number of cards in players hand
	void clearHand();// clears the player's hand
	void addCard(CardPtr);//adds a card to the player's hand
	void drawOrHold();// lets user decide which cards he wants to hold or draw
	bool isPair() const;          //////////////////////////
	bool isThreeOfAKind() const;  //
	bool isFourOfAKind() const;	  //
	bool isFullHouse() const;	  //
	bool isTwoPair() const;		  // bools for each
	bool isFlush() const;		  // different poker hand
	bool isStraight() const;	  //
	bool isStraightFlush() const; //
	bool isRoyalFlush() const;	  //
	bool isJacksOrBetter() const; //////////////////////////
	std::string toString();// prints out: # card (draw/hold)
	std::string toStringNoHold();// prints out: # card 
private:
	std::vector<std::pair<CardPtr, bool> > _hand;//holds a cardPtr and a bool in a vector. the bool is used to see if the user whats to draw the card or hold it
	std::set<Face> _faceset;// a set that contains every face value a card can have
};