#ifndef LAGRANGE_H
#define LAGRANGE_H
#include "polynom.h"

class Lagrange
{
public:
    Lagrange();
    Lagrange(QList<std::pair<Complex, Complex>> points);

    Polynom P_i(int ind);
    Polynom calculate();

    QList<std::pair<Complex, Complex> > getPoints() const;
    void setPoints(const QList<std::pair<Complex, Complex>> &newPoints);


private:
    QList<std::pair<Complex, Complex>> points;
    int n;
};

#endif // LAGRANGE_H
