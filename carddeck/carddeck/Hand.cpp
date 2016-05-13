///////////////////////////////////////////////////////////////////////
// File:  Hand.cpp
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
#include "Hand.h"
#include <sstream>
#include <utility>

Hand::Hand()
{
}

int Hand::size()
{
	return _hand.size();
}

void Hand::clearHand()
{
	_hand.clear();
	_faceset.clear();
}

void Hand::addCard(CardPtr crd)
{
	_hand.push_back(std::pair<CardPtr, bool>(crd, true));
	_faceset.insert(crd->face);
}

bool Hand::isPair() const
{
	std::map<Face, int> faces;
	for (auto e : _hand)
		faces[e.first->face]++;
	auto itr = std::find_if(faces.begin(), faces.end(), [](std::pair<Face, int> e) {return 	e.second == 2;});
	if (itr != faces.end())
		return true;
	return false;
}

bool Hand::isThreeOfAKind() const
{
	std::map<Face, int> faces;
	for (auto e : _hand)
		faces[e.first->face]++;
	auto itr = std::find_if(faces.begin(), faces.end(), [](std::pair<Face, int> e) {
		return 	e.second == 3;
	});
	if (itr != faces.end())
		return true;
	return false;
}

bool Hand::isFourOfAKind() const
{
	std::map<Face, int> faces;
	for (auto e : _hand)
		faces[e.first->face]++;
	auto itr = std::find_if(faces.begin(), faces.end(), [](std::pair<Face, int> e) {
		return 	e.second == 4;
	});
	if (itr != faces.end())
		return true;
	return false;
}

bool Hand::isFlush() const
{
	std::map<Suit, int> suits;
	for (auto e : _hand)
		suits[e.first->suit]++;
	auto itr = std::find_if(suits.begin(), suits.end(), [](std::pair<Suit, int> e) {
		return 	e.second == 5;
	});
	if (itr != suits.end())
		return true;
	return false;
}

bool Hand::isStraight() const
{
	if (_faceset.size() == _hand.size())
	{
		auto itr = _faceset.begin();
		int min = static_cast<int>(*itr);
		auto itr2 = std::max_element(_faceset.begin(), _faceset.end());
		int max = static_cast<int>(*itr2);

		if (max - min == (_hand.size() - 1))
			return true;
		for (auto f : _faceset)
		{
			if (0 == static_cast<int>(f))
			{
				int ace = 13;
				auto itr4 = ++_faceset.begin();
				min = static_cast<int>(*itr4);
				if (ace - min == 4)
					return true;
			}
		}
	}
	return false;
}

bool Hand::isFullHouse() const
{
	if (isThreeOfAKind() && isPair())
		return true;
	return false;
}

bool Hand::isTwoPair() const
{
	std::map<Face, int> faces;
	for (auto e : _hand)
		faces[e.first->face]++;
	auto itr = std::count_if(faces.begin(), faces.end(), [](std::pair<Face, int> e)
	{
		return 	e.second == 2;
	});
	if (itr == 2)
		return true;
	return false;
}

std::string Hand::toString()
{
	std::stringstream ss;
	std::string hand = "";
	int i = 0;
	for (auto e : _hand)
	{
		++i;
		ss << i << ": " << *(e.first);
		if (e.second)
			ss << "  (draw)\n";
		else
			ss << "  (hold)\n";
	}
	return ss.str();
}

std::string Hand::toStringNoHold()
{
	std::stringstream ss;
	std::string hand;
	int i = 0;
	for (auto e : _hand)
		ss << ++i << ": " << *(e.first) << std::endl;
	return ss.str();
}


bool Hand::isStraightFlush() const
{
	if (isStraight() && isFlush())
		return true;
	return false;
}

bool Hand::isRoyalFlush() const
{
	auto itr = _faceset.begin();
	auto itr2 = --_faceset.end();
	if (isStraightFlush())
		if (0 == static_cast<int>(*itr))
			if (12 == static_cast<int>(*itr2))
				return true;
	return false;
}

bool Hand::isJacksOrBetter() const
{
	std::map<Face, int> faces;
	for (auto e : _hand)
		faces[e.first->face]++;
	if (isPair() == true)
	{
		auto itr = std::find_if(faces.begin(), faces.end(), [](std::pair<Face, int> e) {return 	e.second == 2;});
		if (itr != faces.end())
			if (itr->first >= Face::JACK || itr->first == Face::ACE)
				return true;
	}
	return false;
}

void Hand::drawOrHold()
{
	std::string str;
	while (str != "p")
	{
		int i = 6;
		std::cin >> str;
		std::istringstream(str) >> i;
		if (i > 0 && i < 6)
		{
			i = i - 1;
		_hand[i].second = !_hand[i].second;
	}
		system("cls");
		std::cout << toString() << std::endl;
		std::cout << "choose cards you want to draw or hold (1-5) and press (p) when you are ready to continue.";
	}
		_hand.erase(remove_if(_hand.begin(), _hand.end(), [](std::pair<CardPtr, bool>e) {return e.second;}), _hand.end());
}