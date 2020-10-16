#pragma once
#include <string>
#include <iostream>
#include "chldlbrhl.h"

class ChildrenLibrary
{
private:
	ChildrenLibraryHall* pCH;
	int amountOfBooks, amountOfHalls;
	
public:
	ChildrenLibrary()
	{
		pCH = nullptr;
		amountOfBooks = 0;
		amountOfHalls = 0;
	}

	ChildrenLibrary(int amountOH, int* pAmountOB)
	{
		this->amountOfHalls = amountOH;
		pCH = new ChildrenLibraryHall[amountOfHalls];
		
		for (int i = 0; i < amountOH; i++)
		{
			ChildrenBook* ptm = new ChildrenBook[pAmountOB[i]];
			pCH[i].setPointer(ptm);
			pCH[i].setAmount(pAmountOB[i]);
		}

	}

	ChildrenLibrary(ChildrenLibraryHall* phalls, int amount)
	{
		this->amountOfHalls = amount;
		for (int i = 0; i < amount; i++)
		{
			this->pCH[i] = phalls[i];
		}
	}

	ChildrenLibrary(const ChildrenLibrary& copy)
	{
		this->amountOfBooks = copy.getAOB();
		this->amountOfHalls = copy.getAOH();
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

	void add(ChildrenLibraryHall added)
	{	
		if (!pCH)
		{
			pCH = new ChildrenLibraryHall[amountOfHalls];
		}

        ChildrenLibraryHall* copy = new ChildrenLibraryHall[++amountOfHalls];

		for (int i = 0; i < amountOfHalls-1; i++) {
			copy[i] = pCH[i];
		}
		copy[amountOfHalls-1] = added;
        pCH = copy;
	}

	int getAOB() const
	{
		return this->amountOfBooks;
	}

	int getAOH() const
	{
		return this->amountOfHalls;
	}


	int getFAOB() // Сумма всех книг в либке
	{
		int FAOB = 0;
		for (int i = 0; i < amountOfHalls; i++)
		{
			FAOB += pCH[i].getAmount();
		}
		return FAOB;
	}

	ChildrenLibraryHall getHalls()
	{
		return *pCH;
	}

	ChildrenLibraryHall getHallInd(int index)
	{
		return pCH[index];
	}

	ChildrenBook getBookInd(int index)
	{
		for (int i = 0; i < amountOfHalls; i++)
		{
			int lgh = pCH[i].getAmount();
			if (index >= lgh) {
				index -= lgh;
			}
			else {
				return pCH[i].getBook(index);
			}
		}
	}

	void printHallNames()
	{
		for (int i = 0; i <= amountOfHalls; i++)
		{
			std::cout << std::endl << "Зал №1: " << pCH[i].getZName() 
				<< ". Количество книг в зале: " << pCH[i].getAmount() << std::endl;
		}
	}

	void replaceHAll(int index, ChildrenLibraryHall* copy)
	{
		pCH[index] = *copy;
	}

	void replaceBook(int ind, ChildrenBook* copy)
	{
		getBookInd(ind) = *copy;
	}

	void addBookInd(int ind, ChildrenBook* added)
	{
		for (int i = 0; i < amountOfHalls; i++)
		{
			int lgh = pCH[i].getAmount();
			if (ind >= lgh) {
				ind -= lgh;
			}
			else {
				pCH[i].add(*added, ind);
			}
		}
	}

	void addBookInd(int ind)
	{
		for (int i = 0; i < amountOfHalls; i++)
		{
			int lgh = pCH[i].getAmount();
			if (ind >= lgh) {
				ind -= lgh;
			}
			else {
				pCH[i].deleteBook(ind);
			}
		}
	}

	ChildrenBook getBestBook()
	{
		ChildrenBook bb;
		for (int i = 0; i < amountOfHalls; i++)
		{
			if (bb.getPrice() < pCH[i].getBestBook().getPrice())
			{
				bb = pCH[i].getBestBook();
			}
		}
		return bb;
	}

	ChildrenLibrary operator= (const ChildrenLibrary copy)
	{
		this->amountOfBooks = copy.amountOfBooks;
		this->amountOfHalls = copy.amountOfHalls;

		return *this;
	}
};