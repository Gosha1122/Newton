#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "interpol.h"
#include "lagrange.h"

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

private:
    Ui::Widget *ui;

    QList<std::pair<Complex, Complex>> points;

    std::pair<Complex, Complex> getPoint(int indexPoint);
};

#endif // WIDGET_H
