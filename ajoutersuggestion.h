#ifndef AJOUTERSUGGESTION_H
#define AJOUTERSUGGESTION_H

#include <QWidget>

namespace Ui {
class ajoutersuggestion;
}

class ajoutersuggestion : public QWidget
{
    Q_OBJECT

public:
    explicit ajoutersuggestion(QWidget *parent = 0);
    ~ajoutersuggestion();

private slots:
    void on_retour_clicked();

    void on_pushButton_clicked();




private:
    Ui::ajoutersuggestion *ui;
};

#endif // AJOUTERSUGGESTION_H
