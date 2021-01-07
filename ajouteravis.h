#ifndef AJOUTERAVIS_H
#define AJOUTERAVIS_H

#include <QWidget>

namespace Ui {
class ajouteravis;
}

class ajouteravis : public QWidget
{
    Q_OBJECT

public:
    explicit ajouteravis(QWidget *parent = 0);
    ~ajouteravis();

private slots:
    void on_pushButton_clicked();

    void on_retour_clicked();

private:
    Ui::ajouteravis *ui;
};

#endif // AJOUTERAVIS_H
