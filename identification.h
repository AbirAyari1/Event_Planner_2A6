#ifndef IDENTIFICATION_H
#define IDENTIFICATION_H

#include <QDialog>

namespace Ui {
class Identification;
}

class Identification : public QDialog
{
    Q_OBJECT

public:
    explicit Identification(QWidget *parent = nullptr);
    ~Identification();

private:
    Ui::Identification *ui;
};

#endif // IDENTIFICATION_H
