#include <iostream>
#include <cmath>
#include <cstdlib>
#include "PrFraction.hpp"

int main()
{
    char ans1;
    std::cout << "Would you like to enter the fraction yourself/default? (y/d)";
    std::cin >> ans1;
    PrFraction Pr1(1,2);
    switch (ans1)
    {
        case 'y':
        Pr1 = FrCin();
        break;
        case 'd':
        break;
        default:
        return 0;
	}
    char ans2;
    std::cout << "Would you like to enter the fraction yourself/default? (y/d)";
    std::cin >> ans2;
    PrFraction Pr2(1,2);
    switch (ans2)
    {
        case 'y':
        Pr2 = FrCin();
        break;
        case 'd':
        break;
        default:
        return 0;
	}

std::cout << "\nFraction 1: ";
Pr1.Display();

std::cout << "\nFraction 2: ";
Pr2.Display();
std::cout << '\n\n';
    Pr1.Display();
    std::cout << " + ";
    Pr2.Display();
    std::cout << " = ";
    PrFraction result1 = Pr1.OpPLUS(Pr1, Pr2);
    result1.Display();
    std::cout << std::endl; 

std::cout << '\n';
    Pr1.Display();
    std::cout << " * ";
    Pr2.Display();
    std::cout << " = ";
    PrFraction result2 = Pr1.OpMULT(Pr1, Pr2);
    result2.Display();
    std::cout << std::endl; 

std::cout << '\n';
    Pr1.Display();
    std::cout << " / ";
    Pr2.Display();
    std::cout << " = ";
    PrFraction result3 = Pr1.OpFRACT(Pr1, Pr2);
    result3.Display();
    std::cout << std::endl; 
}