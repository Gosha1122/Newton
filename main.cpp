#include <iostream>
#include "interpol.h"
using namespace std;

int main()
{
    Interpol inter(QList({std::make_pair(Complex(Fraction(0, 1), Fraction(-1, 1)), Complex(Fraction(0, 1))),
                          std::make_pair(Complex(Fraction(0, 1)), Complex(Fraction(2, 1))),
                          std::make_pair(Complex(Fraction(1, 1)), Complex(Fraction(3, 1))),
                          std::make_pair(Complex(Fraction(2, 1)), Complex(Fraction(5, 1)))}));
    std::cout << inter.calculate() <<std::endl;
    std::cout << inter.getFunction(0, 2).value << " | " << inter.getFunction(1, 3).value << " | ";
    std::cout << inter.getFunction(1, 3).value - inter.getFunction(0, 2).value; //<< " | " << inter.getFunction(0, 3);
    return 0;
}
