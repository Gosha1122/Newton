#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "interpol.h"
#include "lagrange.h"

class Complex;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void addPointButtonSlot();
    void deletePointButtonSlot();
    void clearPointButtonSlot();
    void calculateButtonSlot();
    void getPointValueButtonSlot();
    void setPointValueSlot(const Complex& p);

private:
    Ui::Widget *ui;

    QList<std::pair<Complex, Complex>> points;

    std::pair<Complex, Complex> getPoint(int indexPoint);

    Interpol* inter = nullptr;
    Lagrange* lagr  = nullptr;

    Complex p;
};

#endif // WIDGET_H
