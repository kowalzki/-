#ifndef CHLDLBRHL_H
#define CHLDLBRHL_H
#include <string>
#include <iostream>
#include "chldbk.h"
#include <time.h>
#include <iomanip>

class ChildrenLibraryHall
{
private:
    std::string z_name;
    ChildrenBook *pCB;
    int amount;

public:
    ChildrenLibraryHall()
    {
        std::string z_name = "Not Defined";
        ChildrenBook* pCB = nullptr;
        amount = 0;
    }
    ChildrenLibraryHall(std::string z_name, int amount)
    {
        this->z_name = z_name;
        this->amount = amount;
        this->pCB = new ChildrenBook[amount];
    }

    ChildrenLibraryHall(std::string z_name, int amount, ChildrenBook *pbooks)
    {
        this->z_name = z_name;
        this->amount = amount;
        this->pCB = new ChildrenBook[amount];
        for (int i=0; i<amount; i++)
        {
            this->pCB[i] = pbooks[i];
        }
    }

    ChildrenLibraryHall(const ChildrenLibraryHall&  copy)
    {
        this->z_name = copy.getZName();
        this->amount = copy.getAmount();
        this->pCB = new ChildrenBook[this->amount];

        for (int i=0; i<this->amount; i++)
        {
            this->pCB[i] = copy.pCB[i];
        }
    }
    
    ~ChildrenLibraryHall()
    {
        delete[] pCB;
        pCB = nullptr;
    }

    /*ChildrenLibraryHall generateHall(int minAge, int count = -1)
    {
        if (count == -1)
        {
            count = rand() % 20;
        }
        ChildrenLibraryHall t;
        pCB->setMinAge(minAge);
        std::string name = "";
        if (minAge < 100)
        {
            if (minAge < 10)
            {
                name += char(minAge + 48);
            }
            else
            {
                name += char(minAge / 10 + 48);
                name += char(minAge % 10 + 48);
            }
            name += '+';
        }
        pCB->setName(name);
        for (int i = 0; i < count; i++)
        {
            t.add(pCB->generateBook(minAge));
        }
        return t;
    }*/

    void setPointer(ChildrenBook* p)
    {
        this->pCB = p;
    }

    void add(ChildrenBook book)
    {
        ChildrenBook* arr = new ChildrenBook[getAmount()+1];
        for (int i = 0; i <= this->amount - 1; i++)
        {
            arr[i] = pCB[i];
        }
        arr[this->amount] = book;
        delete[] pCB;
        pCB = arr;
        this->amount++;
    }

    /*void addN(ChildrenBook book, int num)
    {
        ChildrenBook* arr = new ChildrenBook[getAmount()];
        for (int i = 0; i < getAmount(); i++)
        {
            arr[i] = pCB[i];
        }
        delete[] pCB;
        if (fill == amount) { amount++; }

        pCB = new ChildrenBook[amount];

        if (num <= this->getAmount()+1 && num >=0)
        {
            for (int i = 0, j=0; i < this->getAmount(); i++, j++)
            {
                if (i == num)
                {
                    pCB[i] = book;
                    ++i;
                }
                pCB[i] = arr[j];
            }
            
            fill++;
            delete[] arr;
        }
        else { std::cout << "Array is too small" << std::endl;}
    }*/
    //add 
    /*void add(ChildrenBook book, int ind)
    {
        if (ind > this->amount; i++)
        {
            ChildrenBook* copy = new ChildrenBook[amount + 1];

            for (int iWr = 0, iRd = 0; iWr < amount; iWr++, iRd++)
            {
                if (iWr == ind)
                {
                    copy[iWr] = book;
                    iWr++;  //возможно, iRd--
                    amount++;
                }
                else
                    copy[iWr] = pCB[iRd];
            }
            delete[] pCB;

            pCB = copy;
        }
    }*/  // addm

    void deleteBook(int ind)
    {/*
        ChildrenBook* arr = new ChildrenBook[amount-1];
        int i;
        if (num < amount && num >= 0)
        {
            for (i = 0; i <= num - 1; i++)
            {
                arr[i] = pCB[i];
            }
            i++;
            for (i; i < amount -1; i++)
            {
                arr[i-1] = pCB[i];
            }
            delete[] pCB;
            pCB = arr;
            amount--;
        }
        else { std::cout << "Array is too small" << std::endl; }
        */
        if (ind < 0 || ind >= amount) {
            return;
        }
        ChildrenBook* copy = new ChildrenBook[amount - 1];
        for (int iWr = 0, iRd = 0; iRd < this->amount; iWr++, iRd++) {
            if (iRd != ind) {
                copy[iWr] = this->pCB[iRd];
            }
            else {
                iWr--;
            }
        }

        this->amount--;
        delete[] this->pCB;
        this->pCB = copy;
    }

    void add(ChildrenBook book, int ind)
    {
        if (ind < 0 || ind > amount)
        {
            return;
        }
        this->amount++;
        ChildrenBook* copy = new ChildrenBook[amount];
        for (int i = 0, k = 0; k < this->amount; i++, k++)
        {
            if (k != ind)
            {
                copy[k] = this->pCB[i];
            }
            else
            {
                copy[k] = book;
                i--;
            }
        }
        delete[] this->pCB;
        this->pCB = copy;
    }


    /*ChildrenBook getBook(int n) const
    {
        return pCB[n];
    }*/

    ChildrenBook getBook(int ind) const
    {
        if (ind >= this->amount)
        {
            ChildrenBook t;
            return t;
        }
        return this->pCB[ind];
    }

    
    void remakeBook(int n, std::string athr, std::string name, int year, int price, int minAge)
    {
        pCB[n].setAthr(athr);
        pCB[n].setName(name);
        pCB[n].setYear(year);
        pCB[n].setPrice(price);
        pCB[n].setMinAge(minAge);
    }

    int getAmount() const
    {
        return this->amount;
    }

    std::string getZName() const
    {
        return this->z_name;
    }

    void setAmount(int amount)
    {
        this->amount = amount;
    }

    void setZName(std::string z_name)
    {
        this->z_name = z_name;
    }

    void showAllNames()
    {
        for (int i = 0; i < this->amount; i++)
        {
            std::cout << pCB[i].getName() << ', ';
        }
    }

    double getFullPrice()
    {
        double full;
        for (int i = 0; i < this->amount; i++)
        {
            full += pCB->getPrice();
        }
        return full;
    }

    std::string generateRandString(int len = 0)
    {
        std::string str = "";
        if (!len)
        {
            len = rand() % 5 + 3;
        }
        for (int i = 0; i < len; i++)
        {
            str += char(rand() % 26 + 97);
        }
        return str;
    }

    ChildrenLibraryHall operator= (const ChildrenLibraryHall copy)
    {
        this->z_name = copy.z_name;
        this->amount = copy.amount;
        pCB = new ChildrenBook[amount];
        

        for (int i = 0; i < amount; i++)
        {
            this->pCB[i] = copy.getBook(i);
        }
        return *this;
    }

    ChildrenBook getBestBook()
    {
        ChildrenBook bb;
        for (int i = 0; i < amount-1; i++)
        {
            if (bb.getPrice() < pCB[i].getPrice())
            {
                bb = pCB[i];
            }
        }
        return bb;
    }

    ChildrenBook& operator[](const int index)
    {
        return this->pCB[index];
    }

    void printHl()
    {        
        std::cout << "Hall: " << z_name << "\n Amount of books: " << this->amount << std::endl;
        for (int i = 0; i < this->amount; i++)
        {
            std::cout << " Book #" << i << " author: " << std::setw(7) << this->pCB[i].getAthr() 
                << " name: " << std::setw(7) << this -> pCB[i].getName() 
                << " price: " << std::setw(7) << pCB[i].getPrice() << std::endl;
        }
        std::cout << std::endl;
    }
};

#endif // CHLDLBRHL_H