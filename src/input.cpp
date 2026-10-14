#include <iostream>
#include <limits>
#include "input.h"

int ReadInt()
{
    int value = 0;
    while (!(std::cin >> value))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Podana wartość nie jest liczbą całkowitą, spróbuj jeszcze raz.\n";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return value;
}