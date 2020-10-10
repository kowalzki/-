#ifndef CHLDLBRHL_H
#define CHLDLBRHL_H
#include <string>
#include <iostream>
#include "chldbk.h"

class ChildrenLibraryHall
{
private:
    std::string z_name;
    ChildrenBook *pCB;
    int amount;
    int fill;

public:
    ChildrenLibraryHall()
    {
        std::string z_name = "Not Defined";
        ChildrenBook* pCB = nullptr;
        amount = 0;
        fill = 0;
    }
    ChildrenLibraryHall(std::string z_name, int amount)
    {
        this->z_name = z_name;
        this->amount = amount;
        this->pCB = new ChildrenBook[amount];
        fill = 0;
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
        fill = amount;
    }

    ChildrenLibraryHall(ChildrenLibraryHall& clh)
    {
        this->z_name = clh.getZName();
        this->amount = clh.getAmount();
        this->fill = clh.fill;
        this->pCB = new ChildrenBook[this->amount];

        for (int i=0; i<this->amount; i++)
        {
            this->pCB[i] = clh.pCB[i];
        }
    }

    ChildrenLibraryHall generateHall(int minAge, int count = -1)
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

    void addN(ChildrenBook book, int num)
    {
        ChildrenBook* arr = new ChildrenBook[getAmount()];
        for (int i = 0; i < getAmount(); i++)
        {
            arr[i] = pCB[i];
        }
        delete[] pCB;
        if (fill == amount) { amount++; }

        pCB = new ChildrenBook[amount];

        if (num <= getAmount()+1 && num >=0)
        {
            for (int i = 0, j=0; i < num; i++, j++)
            {
                if (i == num)
                {
                    pCB[i] = book;
                    ++i;
                }
                pCB[i] = arr[j];
            }
            /*arr[num] = pCB[num];
            for (i = i + 1; i < amount + 1; i++)
            {
                arr[i] = pCB[i];
            }
            arr[this->amount] = book;
            delete[] pCB;
            pCB = arr;
            this->amount++;*/
            fill++;
            delete[] arr;
        }
        else { std::cout << "Array is too small" << std::endl;}
    }

    ChildrenBook getBook(int n)
    {
        return pCB[n];
    }
    
    void remakeBook(int n, std::string athr, std::string name, int year, int price, int minAge)
    {
        pCB[n].setAthr(athr);
        pCB[n].setName(name);
        pCB[n].setYear(year);
        pCB[n].setPrice(price);
        pCB[n].setMinAge(minAge);
    }

    int getAmount()
    {
        return this->amount;
    }

    std::string getZName()
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
        this->pCB = copy.pCB;
        this->amount = copy.amount;
        this->fill = copy.fill;

        return *this;
    }

    void deleteBook(int num)
    {
        ChildrenBook* arr = new ChildrenBook[getAmount()-1];
        int i;
        if (num <= getAmount() && num >= 0)
        {
            for (i = 0; i <= num - 1; i++)
            {
                arr[i] = pCB[i];
            }
            i++;
            for (i = i + 1; i < amount -1; i++)
            {
                arr[i-1] = pCB[i-1];
            }
            delete[] pCB;
            pCB = arr;
        }
        else { std::cout << "Array is too small" << std::endl; }
    }


};

#endif // CHLDLBRHL_H