///////////////////////////////////////////////////////////////////////
// File:  Game.cpp
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
#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

const std::map<PokerHand, int> Game::_payOutSheet
{
	{ PokerHand::NADA, 0 },
	{ PokerHand::JACKS_OR_BETTER, 1 },
	{ PokerHand::TWO_PAIRS, 2 },
	{ PokerHand::THREE_OF_A_KIND, 3 },
	{ PokerHand::STRAIGHT, 4 },
	{ PokerHand::FLUSH, 6 },
	{ PokerHand::FULL_HOUSE, 9 },
	{ PokerHand::FOUR_OF_A_KIND, 25 },
	{ PokerHand::STRAIGHT_FLUSH, 50 },
	{ PokerHand::ROYAL_FLUSH, 250 }
};

const std::map<PokerHand, std::string>  Game::_handResult
{
	{ PokerHand::NADA, "Nada" },
	{ PokerHand::JACKS_OR_BETTER, "Jacks or Better" },
	{ PokerHand::TWO_PAIRS, "Two Pairs" },
	{ PokerHand::THREE_OF_A_KIND, "Three of a kind" },
	{ PokerHand::STRAIGHT, "Straight" },
	{ PokerHand::FLUSH, "Flush" },
	{ PokerHand::FULL_HOUSE, "Full House" },
	{ PokerHand::FOUR_OF_A_KIND, "Four of a Kind" },
	{ PokerHand::STRAIGHT_FLUSH, "Straight Flush" },
	{ PokerHand::ROYAL_FLUSH, "Royal Flush" }
};

PokerHand Game::getRank() const
{
	if (_hand.isRoyalFlush())
		return PokerHand::ROYAL_FLUSH;
	if (_hand.isStraightFlush())
		return PokerHand::STRAIGHT_FLUSH;
	else if (_hand.isFourOfAKind())
		return PokerHand::FOUR_OF_A_KIND;
	else if (_hand.isFullHouse())
		return PokerHand::FULL_HOUSE;
	else if (_hand.isFlush())
		return PokerHand::FLUSH;
	else if (_hand.isStraight())
		return PokerHand::STRAIGHT;
	else if (_hand.isThreeOfAKind())
		return PokerHand::THREE_OF_A_KIND;
	else if (_hand.isTwoPair())
		return PokerHand::TWO_PAIRS;
	else if (_hand.isJacksOrBetter())
		return PokerHand::JACKS_OR_BETTER;
	else
		return PokerHand::NADA;
}

void Game::play()
{
	system("cls");
	_hand.clearHand();
	_deck.shuffle();
	while (_hand.size() < 5)
		_hand.addCard(_deck.draw());
	std::cout << _hand.toString() << std::endl;
	int i = 0;
	std::cout << "choose cards you want to draw or hold (1-5) and press (p) when you are ready to continue.";
	_hand.drawOrHold();
	while (_hand.size() < 5)
		_hand.addCard(_deck.draw());
	system("cls");
	std::cout << _hand.toStringNoHold() << std::endl;
	PokerHand rank = getRank();
	std::cout << "you got a " << _handResult.at(rank) << std::endl;// displays poker hand name
	std::cout << "this hand pays out " << _payOutSheet.at(rank) << " times your bet." << std::endl;// displays value of pay out
	system("pause");
}

void Game::instructions() const
{
	std::cout
		<< "Welcome to Jacks or Better Video Poker\n\n"
		<< "Instructions:\n"
		<< "Once you started a game by pressing (p) at the start menu, the screen will show your hand.\n"
		<< "You can toggle which cards you want to redraw or hold by typing a number between 1 and 5.\n"
		<< "You can redraw multiple cards, but can only do it once.\n"
		<< "After you selected the cards you want to keep, press (p) to redraw cards.";

	system("pause");
}

void Game::showPayTable() const
{
	std::cout
		<< "Pay Table:\n"
		<< "______________________________\n"
		<< "|       hand        |1 credit|\n"
		<< "|Royal Flush        |250     |\n"
		<< "|Straight Flush     |50      |\n"
		<< "|Four of a Kind     |25      |\n"
		<< "|Full House         |9       |\n"
		<< "|Flush              |6       |\n"
		<< "|Straight           |4       |\n"
		<< "|Three of a Kind    |3       |\n"
		<< "|Two Pairs          |2       |\n"
		<< "|Jacks or Better    |1       |\n"
		<< "|Theoretical return |98.4%   |\n"
		<< "|___________________|________|\n";
	system("pause");
}