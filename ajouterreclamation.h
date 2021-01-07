#ifndef AJOUTERRECLAMATION_H
#define AJOUTERRECLAMATION_H

#include <QWidget>

namespace Ui {
class ajouterreclamation;
}

class ajouterreclamation : public QWidget
{
    Q_OBJECT

public:
    explicit ajouterreclamation(QWidget *parent = 0);
    ~ajouterreclamation();

private slots:
    void on_retour_clicked();

    void on_pushButton_clicked();

private:
    Ui::ajouterreclamation *ui;
};

#endif // AJOUTERRECLAMATION_H
