#include "pointdialog.h"
#include "ui_pointdialog.h"

PointDialog::PointDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PointDialog)
{
    ui->setupUi(this);
    setWindowTitle("Set point");
}

PointDialog::~PointDialog()
{
    delete ui;
}



void PointDialog::on_OKButton_clicked()
{
    Complex first;
    QString firstStr = ui->lineEdit->text();

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
                if(firstStr.indexOf('.') == -1){
                    first = Complex(Fraction(firstStr.simplified().toLongLong(), 1));
                }else{
                    reList = firstStr.split('.');
                    first = Complex(Fraction((reList.at(0) + reList.at(1)).simplified().toLongLong(), pow(10, reList.at(1).size())));
                }
            }
        }
    }

    emit setPointSignal(first);
    accept();
}


void PointDialog::on_cancelButton_clicked()
{
    reject();
}

