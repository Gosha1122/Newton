#ifndef INTERPOL_H
#define INTERPOL_H

#include "polynom.h"

#include <QList>

struct Function{
    int start;
    int finish;
    Fraction value;
};

std::ostream& operator<<(std::ostream& out, const Function& f);

class Interpol
{
public:
    Interpol();
    Interpol(const QList<std::pair<Complex, Complex>>& points);
    Interpol(const Interpol& in);
    void operator=(const Interpol& in);


    QList<std::pair<Complex, Complex>> getPoints() const;
    void setPoints(const QList<std::pair<Complex, Complex>> &newPoints);
    Polynom calculate();

    int getN() const;
    void setN(int newN);

private:
    int n = 0;
    QList<std::pair<Complex, Complex>> points;
};

#endif // INTERPOL_H
