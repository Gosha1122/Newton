#include "interpol.h"



std::ostream& operator<<(std::ostream& out, const Function& f){
    out << "f(";
    for(int i = f.start; i < f.finish + 1; i++){
        out << "x_" << i;
        if(i != f.finish) out << ", ";
    }
    out << ") = ";
    return out << f.value;
}

Interpol::Interpol() {

}

Interpol::Interpol(const QList<std::pair<Complex, Complex>>& points): points(points)
{
    n = points.count();
}

Interpol::Interpol(const Interpol &in)
{
    points = in.getPoints();
    n = in.getN();
}

void Interpol::operator=(const Interpol &in)
{
    points = in.getPoints();
    n = in.getN();
}

Polynom Interpol::calculate(const QList<std::pair<Complex, Complex> > &points)
{
    this->points = points;
    n = points.count();
    return calculate();
}

Polynom Interpol::calculate()
{
    Polynom otv = Polynom();
    for(int i = 0; i < n; i++){
        Function f = getFunction(0, i);
        Polynom p = Polynom(QList({Monomial(0, Complex(Fraction(1, 1)))}));
        for(int j = 0; j < i; j++){
            Polynom t(QList({Monomial(1, Complex(Fraction(1, 1))), Monomial(0, -points.at(j).first)}));
            p *= t;
        }
        otv += p * f.value;
    }
    return otv;
}

QList<std::pair<Complex, Complex>> Interpol::getPoints() const
{
    return points;
}

void Interpol::setPoints(const QList<std::pair<Complex, Complex>> &newPoints)
{
    points = newPoints;
}

int Interpol::getN() const
{
    return n;
}

void Interpol::setN(int newN)
{
    n = newN;
}

Function Interpol::getFunction(int first, int second)
{
    if(functions[std::make_pair(first, second)].start == 0 && functions[std::make_pair(first, second)].finish == 0 && functions[std::make_pair(first, second)].value == Complex()){
        if(first == second){
            functions[std::make_pair(first, second)] = {first, second, points.at(first).second};
            return {first, second, points.at(first).second};
        }
        functions[std::make_pair(first, second)] = {first, second, (getFunction(first + 1, second).value - getFunction(first, second - 1).value) / Fraction(second - first, 1)};
        return functions[std::make_pair(first, second)];
    }
    return functions[std::make_pair(first, second)];
}
