#ifndef INTERPOL_H
#define INTERPOL_H

#include "fraction.h"
#include "complex.h"

#include <QMap>

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
    Interpol(const QMap<Complex, Complex>& points);
    Interpol(const Interpol& in);
    void operator=(const Interpol& in);


    QMap<Complex, Complex> getPoints() const;
    void setPoints(const QMap<Complex, Complex> &newPoints);

    int getN() const;
    void setN(int newN);

private:
    int n = 0;
    QMap<Complex, Complex> points;
};

#endif // INTERPOL_H
