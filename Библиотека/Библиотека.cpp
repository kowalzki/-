#include "chldlbrhl.h"
#include <iostream>
#include <time.h>

void remakeBk();

int main()
{
    srand(time(NULL));
    ChildrenLibraryHall hall("12+", 2);
    ChildrenBook cbk1 = ChildrenBook::generateBook(12), cbk2 = ChildrenBook::generateBook(12), cbk3 = ChildrenBook::generateBook(12);
    hall.add(cbk1, 0);
    hall.add(cbk2, 1);

    std::cout << "cbk1: " << cbk1.getPrice() << std::endl << "cbk2: " << cbk2.getPrice() << std::endl;

    hall.add(cbk3, 2);  
    std::cout << hall.getAmount() << std::endl << "U ra here2" << std::endl << "cbk3: " << cbk3.getPrice() << std::endl;
    std::cout << hall.getBestBook().getPrice() << ", " << hall.getBestBook().getAthr() << std::endl;

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
