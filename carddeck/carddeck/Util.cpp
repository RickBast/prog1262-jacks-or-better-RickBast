///////////////////////////////////////////////////////////////////////
// File:  Util.cpp
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
#include "Util.h"

Util::Util()
{
}

Util::~Util()
{
}

void Util::menu()
{
	bool quit = false;
	char choice;
	do {
		system("cls");
		std::cout
			<< "****************************************\n"
			<< "*      Jacks or Better Video Poker     *\n"
			<< "*                                      *\n"
			<< "* choose an Option:                    *\n"
			<< "*                                      *\n"
			<< "* Play (p)                             *\n"
			<< "* Show Pay Table (t)                   *\n"
			<< "* Instructions (i)                     *\n"
			<< "*                                      *\n"
			<< "* Quit (q)                             *\n"
			<< "****************************************\n\n";
		std::cout << "enter you choice:\n";
		std::cin >> choice;
		switch (tolower(choice))
		{
		case 'p':
			_game.play();
			break;
		case 't':
			_game.showPayTable();
			break;
		case 'i':
			_game.instructions();
			break;
		case 'q':
			quit = true;
			break;
		default:
			std::cout << "invalid choice\n";
			break;
		}
	} while (!quit);
}