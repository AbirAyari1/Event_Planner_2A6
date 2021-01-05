#include "dialogahmed.h"
#include <QApplication>
#include <QMessageBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialogahmed w;
    w.show();
    return a.exec();
}
