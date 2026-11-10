#include <iostream>
#include <cmath>
#include <cstdlib>
#include "PrFraction.hpp"

	//конструктор для получения значения дроби
	PrFraction::PrFraction(int up, int down):
		numer(up), denom(down)
	{
		if (down == 0)
		{
			std::cout << "Denominator is 0. Fraction doesn't exist";
			exit(1);
		}
		Sokr();
	}

	//конструктор копирования
	PrFraction::PrFraction(const PrFraction& Pr1)
	{
		numer = Pr1.numer;
		denom = Pr1.denom;
		Sokr();
	}


	//методы


	//поиск нода
	int PrFraction::NOD() const

	{
        int a = abs(numer);
        int b = abs(denom);
			while (b != 0) 
			{
				int temp = b;
                b = a % b;
                a = temp;
			}
			return abs(a);
	}

	//сокращение неправильных дробей
	void PrFraction::Sokr()
	{
        int div = NOD();
		numer = numer / div;
		denom = denom / div;
        if (denom <0)
        {
            denom = - denom;
            numer = -numer;
        }
	}

	int PrFraction::getNum() const    //для константных методов const пишется после объявления метода
	{
		return numer;
	}

	int PrFraction::getDenom() const	
	{
		return denom;
	}


	//вывод дроби 
	void PrFraction::Display() const
	{
		std::cout << numer << '/' << denom;
	}


	//метод сложения 2х дробей
	PrFraction PrFraction::OpPLUS(PrFraction Pr1, PrFraction Pr2)
	{
		int resUp, resDown;
		resUp = Pr1.numer * Pr2.denom + Pr2.numer * Pr1.denom;
		resDown = Pr1.denom * Pr2.denom;
		PrFraction res{ resUp,resDown };
		res.Sokr();
		return res;
	}
	//метод умножения 2х дробей
	PrFraction PrFraction::OpMULT(PrFraction Pr1, PrFraction Pr2)
	{
		int resUp, resDown;
		resUp = Pr1.numer * Pr2.numer;
		resDown = Pr1.denom * Pr2.denom;
		PrFraction res{ resUp,resDown };
		res.Sokr();
		return res;
	}
	//метод деления 2х дробей
	PrFraction PrFraction::OpFRACT(PrFraction Pr1, PrFraction Pr2)
	{
		int resUp, resDown;
		resUp = Pr1.numer * Pr2.denom;
		resDown = Pr1.denom * Pr2.numer;
		PrFraction res{ resUp,resDown };
		res.Sokr();		
		return res;
		}


PrFraction FrCin()
	{
		int a;
		int b;
		char c;
		std::cout << "Enter the numerator and denominator (num/den): ";
		std::cin >> a >> c >> b;
		PrFraction Pr1(a, b);
		return Pr1;
	}