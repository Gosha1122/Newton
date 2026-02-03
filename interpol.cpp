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

QList<std::pair<Complex, Complex>> Interpol::getPoints() const
{
    return points;
}

void Interpol::setPoints(const QList<std::pair<Complex, Complex>> &newPoints)
{
    points = newPoints;
}

Polynom Interpol::calculate()
{
    return Polynom();
}

int Interpol::getN() const
{
    return n;
}

void Interpol::setN(int newN)
{
    n = newN;
}
