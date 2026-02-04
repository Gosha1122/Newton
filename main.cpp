#include <iostream>
#include "lagrange.h"
#include "interpol.h"
using namespace std;

int main() {
    Lagrange to_do;
    QList<pair<Complex, Complex>> list = {std::make_pair(Complex(Fraction(1, 1)), Complex(Fraction(0, 1), Fraction(1, 1))),
                                          std::make_pair(Complex(Fraction(2, 1)), Complex(Fraction(1, 1))),
                                          std::make_pair(Complex(Fraction(3, 1)), Complex(Fraction(2, 1))),
                                          std::make_pair(Complex(Fraction(0, 1), Fraction(-1, 1)), Complex(Fraction(3, 1))),
                                          std::make_pair(Complex(Fraction(0, 1), Fraction(1, 1)), Complex(Fraction(0, 1), Fraction(-1, 1))),
                                          std::make_pair(Complex(Fraction(0, 1), Fraction(2, 1)), Complex(Fraction(0, 1)))};
    to_do.setPoints(list);
    cout << to_do.calculate() << endl;
    Interpol inter(QList({std::make_pair(Complex(Fraction(1, 1)), Complex(Fraction(0, 1), Fraction(1, 1))),
                          std::make_pair(Complex(Fraction(2, 1)), Complex(Fraction(1, 1))),
                          std::make_pair(Complex(Fraction(3, 1)), Complex(Fraction(2, 1))),
                          std::make_pair(Complex(Fraction(0, 1), Fraction(-1, 1)), Complex(Fraction(3, 1))),
                          std::make_pair(Complex(Fraction(0, 1), Fraction(1, 1)), Complex(Fraction(0, 1), Fraction(-1, 1))),
                          std::make_pair(Complex(Fraction(0, 1), Fraction(2, 1)), Complex(Fraction(0, 1)))}));
    Polynom P = inter.calculate();
    cout << P << endl;
    for (pair<Complex, Complex> &p : inter.getPoints()) {
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
