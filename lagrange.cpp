#include "lagrange.h"

Lagrange::Lagrange() {}

Lagrange::Lagrange(QList<std::pair<Complex, Complex> > points) : points(points), n(points.size())
{

}

Polynom Lagrange::P_i(int ind) {
    Polynom P = Polynom(QList({Monomial(0, Complex(Fraction(1, 1)))}));
    Complex x = Complex(Fraction(1, 1));
    for (int i = 0; i < n; i++) {
        if (i != ind) {
            P *= Polynom(QList({Monomial(1, Complex(Fraction(1, 1))), Monomial(0, -points[i].first)}));
            x *= points[ind].first - points[i].first;
        }
    }
    P /= x;
    return P;
}

Polynom Lagrange::calculate() {
    Polynom P;
    for (int i = 0; i < n; i++) {
        Polynom p = P_i(i);
        P += p * points[i].second;
        LString += "L_" + QString::number(i) + ": " + p.getText() + '\n';
    }
    if(pol != nullptr) delete pol;
    pol = new Polynom(P);
    return P;
}

QList<std::pair<Complex, Complex> > Lagrange::getPoints() const
{
    return points;
}

void Lagrange::setPoints(const QList<std::pair<Complex, Complex>> &newPoints)
{
    points = newPoints;
    n = points.size();
}

QString Lagrange::getLString()
{
    return LString;
}

Polynom *Lagrange::getPol() const
{
    return pol;
}

