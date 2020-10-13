#pragma once
#include <string>
#include <iostream>
#include "chldlbrhl.h"

class ChildrenLibrary
{
	ChildrenLibraryHall* pCH;
	int amountOfBooks, amountOfHalls, filled;


	ChildrenLibrary(int amountOH, int amountOB)
	{

	}

	ChildrenLibrary(ChildrenLibraryHall* phalls, int amount)
	{
		this->amountOfHalls = amount;
		for (int i = 0; i < amount; i++)
		{
			this->pCH[i] = phalls[i];
		}
		this->filled = amount;
	}

	ChildrenLibrary(ChildrenLibrary& copy)
	{
		this->amountOfBooks = copy.getAOB();
		this->amountOfHalls = copy.getAOH();
		this->filled = copy.getAOFilled();

		this->pCH = new ChildrenLibraryHall[this->amountOfHalls];
		for (int i = 0; i < this->amountOfHalls; i++)
		{
			this->pCH[i] = copy.pCH[i];
		}
	}

	~ChildrenLibrary()
	{
		delete[] pCH;
		pCH = 0;
	}

	int getAOB()
	{
		return this->amountOfBooks;
	}

	int getAOH()
	{
		return this->amountOfHalls;
	}

	int getAOFilled()
	{
		return this->filled;
	}



};