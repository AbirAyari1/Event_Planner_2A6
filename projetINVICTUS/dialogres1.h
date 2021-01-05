#ifndef DIALOGRES1_H
#define DIALOGRES1_H

#include <QDialog>

namespace Ui {
class Dialogres1;
}

class Dialogres1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogres1(QWidget *parent = nullptr);
    ~Dialogres1();

private:
    Ui::Dialogres1 *ui;
};

#endif // DIALOGRES1_H
