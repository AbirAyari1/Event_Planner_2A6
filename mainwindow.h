#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "invite.h"
#include "invitation.h"
#include "table.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_invitation_clicked();

    void on_pushButton_table_clicked();

    void moveHome();

private:
    Ui::MainWindow *ui;
    Invite inv;
    Invitation invitation;
    Table table;
};
#endif // MAINWINDOW_H
