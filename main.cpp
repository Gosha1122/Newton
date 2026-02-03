#include <iostream>
#include "lagrange.h"

using namespace std;

int main()
{
    Lagrange to_do;
    QList<pair<Complex, Complex>> list = {{Complex(Fraction(0, 1), Fraction(-1, 1)), Complex(Fraction(0, 1))},
                                          {Complex(Fraction(0, 1)), Complex(Fraction(2, 1))},
                                          {Complex(Fraction(1, 1)), Complex(Fraction(3, 1))},
                                          {Complex(Fraction(2, 1)), Complex(Fraction(5, 1))}
                                          };
    to_do.setPoints(list);
    cout << to_do.calculate() << endl;
    return 0;
}
