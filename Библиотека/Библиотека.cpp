#include "chldlbrhl.h"
#include <iostream>

void remakeBk();

int main()
{
    ChildrenLibraryHall hall("12+", 2);
    /*hall.add();
    hall.add();
    hall.add();*/

    std::cout << hall.getAmount();

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
}
