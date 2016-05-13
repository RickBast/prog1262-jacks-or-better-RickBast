///////////////////////////////////////////////////////////////////////
// File:  Game.h
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
#include "Hand.h"

class Game
{
public:
	Game();
	~Game();
	void play(); // starts a game of jacks or better video poker
	void instructions() const; // show instructions to user
	void showPayTable() const;// shows the pay table to the user
	PokerHand getRank() const;//returns a enum ofPokerHand that corresponds with bools of poker hands.
private:
	static const std::map<PokerHand, int> _payOutSheet;// maps out the pay amount for each poker hand
	static const std::map<PokerHand, std::string> _handResult;//  gives the poker hand with a string
	Deck _deck;
	Hand _hand;
};