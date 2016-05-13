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
	void play();
	void instructions() const;
	void showPayTable() const;
	PokerHand getRank() const;
private: 
	static const std::map<PokerHand, int> _payOutSheet;
	static const std::map<PokerHand, std::string> _handResult;
	std::vector<bool> _drawCard;
	Deck _deck; 
	Hand _hand;
};