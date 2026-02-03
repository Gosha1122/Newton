#include <iostream>
#include "Polynom.h"
using namespace std;

int main()
{
    Polynom P(QList{Monomial(2, Complex(Fraction(1, 1))),
                    Monomial(1, Complex(Fraction(1, 1))),
                    Monomial(0, Complex(Fraction(1, 1)))});
    Polynom Q(QList{Monomial(2, Complex(Fraction(1, 1))),
                    Monomial(1, Complex(Fraction(1, 1))),
                    Monomial(0, Complex(Fraction(1, 1)))});
    cout << P << " " << Q << endl;
    cout << P * Q << endl;
    cout << P - Q << endl;
    cout << P + Q << endl;
    return 0;
}
