#include <iostream>
#include <cmath>
#include <cstdlib>
#ifndef PRFRACTION_HPP
#define PRFRACTION_HPP

class PrFraction {
private:
	int numer;
	int denom;
public:
	PrFraction() = delete;

	PrFraction(int up, int down);

	PrFraction(const PrFraction& Pr1);

	int NOD() const;

	void Sokr();

	int getNum() const;

	int getDenom() const;

	void Display() const;

	PrFraction OpPLUS(PrFraction Pr1, PrFraction Pr2);

	PrFraction OpMULT(PrFraction Pr1, PrFraction Pr2);

	PrFraction OpFRACT(PrFraction Pr1, PrFraction Pr2);
};

	PrFraction FrCin();

	#endif