///////////////////////////////////////////////////////////////////////
// File:  Util.h
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
#include "Game.h"
class Util
{
public:
	Util();
	~Util();
	void menu();//diplays a menu where you can choose to play, view instructions or view pay table
private:
	Game _game;
};