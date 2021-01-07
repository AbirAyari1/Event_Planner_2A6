#ifndef MODIFIERRECLAMATION_H
#define MODIFIERRECLAMATION_H

#include <QWidget>

namespace Ui {
class modifierreclamation;
}

class modifierreclamation : public QWidget
{
    Q_OBJECT

public:
    explicit modifierreclamation(QWidget *parent = 0);
    ~modifierreclamation();

private slots:
    void on_pushButton_clicked();

    void on_retour_clicked();

private:
    Ui::modifierreclamation *ui;
};

#endif // MODIFIERRECLAMATION_H
