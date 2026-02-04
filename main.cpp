#include <iostream>
#include "lagrange.h"

using namespace std;

int main()
{
    Lagrange to_do;
    QList<pair<Complex, Complex>> list = {{Complex(Fraction(0, 1)), Complex(Fraction(1, 1))},
                                          {Complex(Fraction(1, 1)), Complex(Fraction(1, 1))},
                                          {Complex(Fraction(-1, 1)), Complex(Fraction(-1, 1))},
                                          {Complex(Fraction(2, 1)), Complex(Fraction(5, 1))},
                                          };
    to_do.setPoints(list);
    Polynom P = to_do.calculate();
    cout << P << endl;
    for (pair<Complex, Complex> &p : list) {
        Complex x;
        for (Monomial &m : P.getMonomials()) {
            Complex one = Complex(Fraction(1, 1));
            for (int i = 0; i < m.getPower(); i++) {
                one *= p.first;
            }
            x += one * m.getK();
        }
        cout << x << " ? " << p.second << endl;
    }
    return 0;
}
