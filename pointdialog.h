#ifndef POINTDIALOG_H
#define POINTDIALOG_H

#include <QDialog>
#include "Complex.h"

namespace Ui {
class PointDialog;
}

class PointDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PointDialog(QWidget *parent = nullptr);
    ~PointDialog();

private slots:


    void on_OKButton_clicked();

    void on_cancelButton_clicked();

signals:
    void setPointSignal(const Complex& p);

private:
    Ui::PointDialog *ui;
};

#endif // POINTDIALOG_H
