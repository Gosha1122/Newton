#include "widget.h"
#include "ui_widget.h"

#include "lagrange.h"
#include "interpol.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->addPointButton   , &QPushButton::clicked, this, &Widget::addPointButtonSlot);
    connect(ui->clearButton      , &QPushButton::clicked, this, &Widget::clearPointButtonSlot);
    connect(ui->deletePointButton, &QPushButton::clicked, this, &Widget::deletePointButtonSlot);
    connect(ui->calculateButton  , &QPushButton::clicked, this, &Widget::calculateButtonSlot);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::addPointButtonSlot()
{
    QTableWidgetItem* item = new QTableWidgetItem();
    item->setText("p_" + QString::number(ui->tablePoints->rowCount() + 1));

    ui->tablePoints->insertRow(ui->tablePoints->rowCount());

    qDebug() << ui->tablePoints->rowCount();
    ui->tablePoints->setVerticalHeaderItem(ui->tablePoints->rowCount() - 1, item);
}

void Widget::deletePointButtonSlot()
{
    QModelIndexList selectedRows = ui->tablePoints->selectionModel()->selectedRows();
    while (!selectedRows.empty()) {
        ui->tablePoints->removeRow(selectedRows[0].row());
        selectedRows = ui->tablePoints->selectionModel()->selectedRows();
    }
    for(int i = 0; i < ui->tablePoints->rowCount(); ++i){
        QTableWidgetItem* item = new QTableWidgetItem("p_" + QString::number(i + 1));
        ui->tablePoints->setVerticalHeaderItem(i, item);
    }
}

void Widget::clearPointButtonSlot()
{
    for(int i = ui->tablePoints->rowCount() - 1; i >= 0; --i){
        ui->tablePoints->removeRow(i);
    }
}

void Widget::calculateButtonSlot()
{
    int count = ui->tablePoints->rowCount();
    for(int i = 0; i < count; i++){
        points.append(getPoint(i));
    }
    Interpol inter(points);
    ui->resultEdit->setPlainText(inter.calculate().getText());
}

std::pair<Complex, Complex> Widget::getPoint(int indexPoint)
{
    Complex first, second;
    QString firstStr = ui->tablePoints->item(indexPoint, 0)->text();

    firstStr = firstStr.simplified();
    QString imStr, reStr;
    QStringList list, imList, reList;
    if(firstStr.indexOf('+') != -1){
        list = firstStr.split('+');
        if(list.at(0).indexOf('i') != -1){
            imStr = list.at(0);
            reStr = list.at(1);
        }else{
            imStr = list.at(1);
            reStr = list.at(0);
        }

        imStr.removeAt(imStr.indexOf('i'));
        imStr.removeAt(imStr.indexOf('*'));
        Fraction re, im;
        if(imStr.indexOf('/') != -1){
            imList = imStr.split('/');
            im = Fraction(imList.at(0).simplified().toLongLong(), imList.at(1).simplified().toLongLong());
        }else{
            im = Fraction(imStr.simplified().toLongLong(), 1);
        }
        if(reStr.indexOf('/') != -1){
            reList = reStr.split('/');
            re = Fraction(reList.at(0).simplified().toLongLong(), reList.at(1).simplified().toLongLong());
        }else{
            re = Fraction(reStr.simplified().toLongLong(), 1);
        }

        first = Complex(re, im);
    }else{
        if(firstStr.indexOf('i') != -1){
            firstStr.remove('i');
            firstStr.remove('*');
            if(firstStr.indexOf('/') != -1){
                imList = firstStr.split('/');
                first = Complex(Fraction(0, 1), Fraction(imList.at(0).simplified().toLongLong(), imList.at(1).simplified().toLongLong()));
            }else{
                first = Complex(Fraction(0, 1), Fraction(firstStr.simplified().toLongLong(), 1));
            }
        }else{
            if(firstStr.indexOf('/') != -1){
                imList = firstStr.split('/');
                first = Complex(Fraction(imList.at(0).simplified().toLongLong(), imList.at(1).simplified().toLongLong()));
            }else{
                first = Complex(Fraction(firstStr.simplified().toLongLong(), 1));
            }
        }
    }
    QString secondStr = ui->tablePoints->item(indexPoint, 1)->text();

    if(secondStr.indexOf('+') != -1){
        list = secondStr.simplified().split('+');
        if(list.at(0).indexOf('i') != -1){
            imStr = list.at(0);
            reStr = list.at(1);
        }else{
            imStr = list.at(1);
            reStr = list.at(0);
        }

        imStr.removeAt(imStr.indexOf('i'));
        imStr.removeAt(imStr.indexOf('*'));
        Fraction re, im;
        if(imStr.indexOf('/') != -1){
            imList = imStr.split('/');
            im = Fraction(imList.at(0).simplified().toLongLong(), imList.at(1).simplified().toLongLong());
        }else{
            im = Fraction(imStr.simplified().toLongLong(), 1);
        }
        if(reStr.indexOf('/') != -1){
            reList = reStr.split('/');
            re = Fraction(reList.at(0).simplified().toLongLong(), reList.at(1).simplified().toLongLong());
        }else{
            re = Fraction(reStr.simplified().toLongLong(), 1);
        }

        second = Complex(re, im);
    }else{
        if(secondStr.indexOf('i') != -1){
            secondStr.remove('i');
            secondStr.remove('*');
            if(secondStr.indexOf('/') != -1){
                imList = secondStr.split('/');
                second = Complex(Fraction(0, 1), Fraction(imList.at(0).simplified().toLongLong(), imList.at(1).simplified().toLongLong()));
            }else{
                second = Complex(Fraction(0, 1), Fraction(secondStr.simplified().toLongLong(), 1));
            }
        }else{
            if(secondStr.indexOf('/') != -1){
                imList = secondStr.split('/');
                second = Complex(Fraction(imList.at(0).simplified().toLongLong(), imList.at(1).simplified().toLongLong()));
            }else{
                second = Complex(Fraction(secondStr.simplified().toLongLong(), 1));
            }
        }
    }

    return std::make_pair(first, second);
}
