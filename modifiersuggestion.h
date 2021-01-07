#ifndef MODIFIERSUGGESTION_H
#define MODIFIERSUGGESTION_H

#include <QWidget>

namespace Ui {
class modifiersuggestion;
}

class modifiersuggestion : public QWidget
{
    Q_OBJECT

public:
    explicit modifiersuggestion(QWidget *parent = 0);
    ~modifiersuggestion();

private slots:
    void on_pushButton_clicked();

    void on_retour_clicked();

private:
    Ui::modifiersuggestion *ui;
};

#endif // MODIFIERSUGGESTION_H
