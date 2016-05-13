///////////////////////////////////////////////////////////////////////
// File:  Card.cpp
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
#include "Card.h"

std::string Card::toString() const
{
	return  Card::faceNames.at(face) + " of " + Card::suitNames.at(suit);
}

std::ostream& operator<<(std::ostream& os, Card& c)
{
	os << c.toString();
	return os;
}

const std::set<Suit>Card::suits{ Suit::CLUB, Suit::DIAMOND, Suit::HEART, Suit::SPADE };
const std::set<Face>Card::faces
{
	Face::ACE,
	Face::TWO,
	Face::THREE,
	Face::FOUR,
	Face::FIVE,
	Face::SIX,
	Face::SEVEN,
	Face::EIGHT,
	Face::NINE,
	Face::TEN,
	Face::JACK,
	Face::QUEEN,
	Face::KING
};

const std::map<Face, std::string> Card::faceNames
{
	{Face::ACE, "Ace"},
	{Face::TWO, "2"},
	{Face::THREE, "3"},
	{Face::FOUR, "4"},
	{Face::FIVE, "5"},
	{Face::SIX, "6"},
	{Face::SEVEN, "7"},
	{Face::EIGHT, "8"},
	{Face::NINE, "9"},
	{Face::TEN, "10"},
	{Face::JACK, "Jack"},
	{Face::QUEEN, "Queen"},
	{Face::KING, "King"}
};

const std::map<Suit, std::string> Card::suitNames
{
	{ Suit::CLUB, "club" },
	{ Suit::DIAMOND, "diamond" },
	{ Suit::HEART, "heart" },
	{ Suit::SPADE, "spade" }
};