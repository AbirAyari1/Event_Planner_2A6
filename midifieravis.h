#ifndef MIDIFIERAVIS_H
#define MIDIFIERAVIS_H

#include <QWidget>

namespace Ui {
class midifieravis;
}

class midifieravis : public QWidget
{
    Q_OBJECT

public:
    explicit midifieravis(QWidget *parent = 0);
    ~midifieravis();

private slots:
    void on_pushButton_clicked();

    void on_retour_clicked();

private:
    Ui::midifieravis *ui;
};

#endif // MIDIFIERAVIS_H
