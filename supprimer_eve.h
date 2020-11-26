#ifndef SUPPRIMER_EVE_H
#define SUPPRIMER_EVE_H

#include <QDialog>

namespace Ui {
class Supprimer_eve;
}

class Supprimer_eve : public QDialog
{
    Q_OBJECT

public:
    explicit Supprimer_eve(QWidget *parent = nullptr);
    ~Supprimer_eve();

private:
    Ui::Supprimer_eve *ui;
};

#endif // SUPPRIMER_EVE_H
