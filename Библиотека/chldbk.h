#ifndef CHLDBK_H
#define CHLDBK_H
#include <stdlib.h>
#include <string>
#include <time.h>

class ChildrenBook
{
private:
    std::string author, name;
    int year, min_age;
    double price;
public:
    ChildrenBook()
    {
        this->author = "Not Defined";
        this->name = "Not Defined";
        this->price = 0.0;
        this->year = 0;
        this->min_age = 0;
    }

    ChildrenBook(std::string author, std::string name, int year, int min_age, double price)
    {
        this->author = author;
        this->name = name;
        this->price = price;
        this->year = year;
        this->min_age = min_age;
    }

    ChildrenBook(std::string name, int year)
    {
        ChildrenBook();
        this->name = name;
        this->year = year;
    }

    static ChildrenBook generateBook(int minAge)
    {
        ChildrenBook cB;
        cB.setAthr(generateRandString());
        cB.setName(generateRandString());
        cB.setPrice(rand() % 100 + (rand() % 100 * 1. / 100));
        cB.setYear(1900 + rand() % 121);
        cB.setMinAge(minAge);
        return cB;
    }


    void setAthr(std::string athr)
    {
        this->author = athr;
    }

    void setName(std::string nme)
    {
        this->name = nme;
    }

    void setPrice(double prc)
    {
        this->price = prc;
    }

    void setMinAge(int m_a)
    {
        this->min_age = m_a;
    }

    void setYear(int yr)
    {
        this->year = yr;
    }

    std::string getAthr()
    {
        return this->author;
    }

    std::string getName()
    {
        return this->name;
    }

    double getPrice()
    {
        return this->price;
    }

    int getMinAge()
    {
        return this->min_age;
    }

    int getYear()
    {
        return this->year;
    }


    static std::string generateRandString(int len = 0)
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

    ChildrenBook operator= (const ChildrenBook copy)
    {
        this->author = copy.author;
        this->name = copy.name;
        this->price = copy.price;
        this->year = copy.year;
        this->min_age = copy.min_age;

        return *this;
    }

    void printB()
    {
        std::cout << "Author: " << getAthr() << std::endl;
        std::cout << "Name: " << getName() << std::endl;
        std::cout << "Price: " << getPrice() << std::endl;
        std::cout << "Year of publish: " << getYear() << std::endl;
        std::cout << "Minimum age: " << getMinAge() << std::endl;
    }
};

#endif // CHLDBK_H
