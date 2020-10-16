#include "chldlbr.h"
#include <iostream>
#include <time.h>

void remakeBk();
std::string generateRandString(int len = 0);
ChildrenBook generateBook(int minAge);
ChildrenLibraryHall generateHall(int minAge, int count = -1);
ChildrenLibrary generateLibrary(int hallsNum = -1, int maxMinAge = 21);


int main()
{
    srand(time(NULL));
    /*ChildrenLibraryHall hall("12+", 2);
    ChildrenBook cbk1 = ChildrenBook::generateBook(12), cbk2 = ChildrenBook::generateBook(12), cbk3 = ChildrenBook::generateBook(12);
    //ChildrenLibrary(hall);

    hall.add(cbk1, 0);
    hall.add(cbk2, 1);

    std::cout << "cbk1: " << cbk1.getPrice() << std::endl << "cbk2: " << cbk2.getPrice() << std::endl;

    hall.add(cbk3, 2);  
    std::cout << hall.getAmount() << std::endl << "U ra here2" << std::endl << "cbk3: " << cbk3.getPrice() << std::endl;
    std::cout << hall.getBestBook().getPrice() << ", " << hall.getBestBook().getAthr() << std::endl;*/
    ChildrenLibrary libka;
    libka = generateLibrary();
    
    std::cout << libka.getBestBook().getAthr();

    system("pause");
    return 0;
}

void remakeBk(int n)
{
    ChildrenLibraryHall clh;
    std::string athr, name;
    int year, price, minAge;

    std::cout << "\nSet new author: "; std::cin >> athr; std::cin.ignore(); std::cin.clear();
    std::cout << "Set new name: "; std::cin >> name; std::cin.ignore(); std::cin.clear(); 
    std::cout << "Set new year of publish: "; std::cin >> year; std::cin.ignore(); std::cin.clear();
    std::cout << "Set new price: "; std::cin >> price; std::cin.ignore(); std::cin.clear(); 
    std::cout << "Set new min age: "; std::cin >> minAge; std::cin.ignore(); std::cin.clear();
    std::cout << "\nNew version:" << std::endl;

    clh.remakeBook(n, athr, name, year, price, minAge);
    std::cout << "\nNew author: ";
    std::cout << "New name: ";
    std::cout << "New year of publish: ";
    std::cout << "New price: ";
    std::cout << "New min age: ";
}

std::string generateRandString(int len)
{
    std::string t = "";
    if (!len) {
        len = rand() % 5 + 3;
    }
    for (int i = 0; i < len; i++) {
        t += char(rand() % 26 + 97);
    }
    return t;
}

ChildrenBook generateBook(int minAge)
{
    ChildrenBook cb;
    cb.setAthr(generateRandString());
    cb.setName(generateRandString());
    cb.setPrice(rand() % 100 + (rand() % 100 * 1. / 100));
    cb.setYear(1900 + rand() % 121);
    cb.setMinAge(minAge);
    return cb;
}

ChildrenLibraryHall generateHall(int minAge, int count)
{
    if (count == -1)
    {
        count = rand() % 20;
    }
    ChildrenLibraryHall clh;
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
    clh.setZName(name);
    for (int i = 0; i < count; i++)
    {
        clh.add(generateBook(minAge));
    }
    return clh;
}

ChildrenLibrary generateLibrary(int hallsNum, int maxMinAge)
{
    if (hallsNum == -1)
    {
        hallsNum = rand() % 5 + 5;
    }
    ChildrenLibrary cl;
    ChildrenLibraryHall hall;
    for (int i = 1, j = 0; j <= maxMinAge; i++, j = int((maxMinAge * 1.0 / hallsNum) * i))
    {
        hall = generateHall(j);
        cl.add(hall);
    }
    return cl;
}
