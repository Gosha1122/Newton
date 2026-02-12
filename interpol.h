#ifndef INTERPOL_H
#define INTERPOL_H

#include "fraction.h"
#include "complex.h"
#include "polynom.h"

#include <QList>

struct Function{
    int start      = 0;
    int finish     = 0;
    Complex value = Complex();
    QString getText();
};

std::ostream& operator<<(std::ostream& out, const Function& f);

class Interpol
{
public:
    Interpol();
    Interpol(const QList<std::pair<Complex, Complex>>& points);
    Interpol(const Interpol& in);
    void operator=(const Interpol& in);

    Polynom calculate(const QList<std::pair<Complex, Complex>>& points);
    Polynom calculate();

    QList<std::pair<Complex, Complex>> getPoints() const;
    void setPoints(const QList<std::pair<Complex, Complex>> &newPoints);


    int getN() const;
    void setN(int newN);

    Function getFunction(int first, int second);
    Polynom *getPol() const;
    QString getFunctionStr();

private:
    int n = 0;
    QList<std::pair<Complex, Complex>> points;
    QMap<std::pair<int, int>, Function> functions;
    Polynom* pol = nullptr;
};

#endif // INTERPOL_H
