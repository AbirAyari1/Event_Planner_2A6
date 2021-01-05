#include "rh.h"
#include "ui_rh.h"
#include <QMessageBox>
#include <QMediaPlayer>
#include <QtWidgets>


rh::rh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::rh)
{
    ui->setupUi(this);
    //Connection C;
    //C.createConnection();
    show_tables(); //allows you to show if a table is a base table or a view
    update_emp_list();

    //concerns the emailing tab
    // signature signal et slot ( connecter un signal à un slot )
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
    connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

    //souuuuund
    QMediaPlayer *music = new QMediaPlayer() ;
    music->setMedia(QUrl("C:/Users/Laptop/documents/Project/AbirAyari/Event_Planner_2A6/musicBG.mp3")) ;
    music->play() ;


    //chat
   ui->lineEdit_31->setFocusPolicy(Qt::StrongFocus);
    ui->textEdit->setFocusPolicy(Qt::NoFocus);
   ui-> textEdit->setReadOnly(true);
   ui-> listWidget->setFocusPolicy(Qt::NoFocus);

    connect(ui->lineEdit_31, SIGNAL(returnPressed()), this, SLOT(returnPressed()));
    connect(&client, SIGNAL(newMessage(QString,QString)),this, SLOT(appendMessage(QString,QString)));
    connect(&client, SIGNAL(newParticipant(QString)),this, SLOT(newParticipant(QString)));
    connect(&client, SIGNAL(participantLeft(QString)),this, SLOT(participantLeft(QString)));

    myNickName = client.nickName();
    newParticipant(myNickName);
    tableFormat.setBorder(0);

    m_speech = new QTextToSpeech(this);
QString name="Bienvenue dans le module de gestion des employés et de congés";
  m_speech->say(name+" patron.");
}

rh::~rh()
{
    delete ui;
}

//ajouter employé
void rh::on_Ajouter_Employe_clicked()
{

     int id =ui->lineEdit_7->text().toInt();
     QString nom=ui->lineEdit_8->text();
     QString prenom=ui->lineEdit_9->text();
     QString email=ui->lineEdit_10->text();
     QString fonction=ui->comboBox->currentText();
     int score=ui->lineEdit_11->text().toInt();
      QString mdp=ui->lineEdit_28->text();

    if ((nom.contains(QRegExp("[^a-zA-Z ]")))||(prenom.contains(QRegExp("[^a-zA-Z ]"))))
    {
        ui->label->setText("Verifier vos informations !");
    } else
    {
        Employe e(id,nom,prenom,email,fonction,score,mdp);
        bool test=e.ajouter();
        if (test)
        {
            show_tables();
        QMessageBox::information(nullptr,QObject::tr("Ajouer Employé"),
                                 QObject::tr(" Employé ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }

        update_emp_list();
        ui->label->setText("Employé ajouté !");

    }


}

//supprimer employé
void rh::on_supprimer_employe_clicked()
{
      bool test=tmpemploye.supprimer(id_emp);
     if (test)
     {
         show_tables();
      QMessageBox::information(nullptr,QObject::tr("Supprimer employé"),
                               QObject::tr("Employé supprimé.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
     }

     update_emp_list();

}


//fill form modifier employé
void rh::on_tableView_activated(const QModelIndex &index)
{ QString val=ui->tableView->model()->data(index).toString();
  QSqlQuery qry;
  qry.prepare("select * from Employe where ""ID='"+val+"'");

  if(qry.exec())
    {while (qry.next())
   { ui->lineEdit_19->setText(qry.value(0).toString());
     ui->lineEdit_20->setText(qry.value(1).toString());
     ui->lineEdit_21->setText(qry.value(2).toString());
     ui->lineEdit_22->setText(qry.value(3).toString());
     ui->lineEdit_24->setText(qry.value(4).toString());
     ui->lineEdit_25->setText(qry.value(5).toString());
     ui->lineEdit_30->setText(qry.value(6).toString());
      }
}
}

//modifier un employé
void rh::on_modifier_employe_clicked()
{ int id =ui->lineEdit_19->text().toInt();
    QString nom=ui->lineEdit_20->text();
    QString prenom=ui->lineEdit_21->text();
    QString email=ui->lineEdit_22->text();
    QString fonction=ui->lineEdit_24->text();
    int score=ui->lineEdit_25->text().toInt();
    QString mdp=ui->lineEdit_30->text();
    Employe e(id,nom,prenom,email,fonction,score,mdp);
    bool test=e.modifier();
    if (test)
    {
        show_tables();
    QMessageBox::information(nullptr,QObject::tr("Modification Employé"),
                             QObject::tr("Employé modifié.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
    }


}

//methode mailing
void  rh::browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   rh::sendMail()
{
    Smtp* smtp = new Smtp("abir.ayari@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("abir.ayari@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("abir.ayari@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   rh::mailSent(QString status)
{

    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

//affichage + metier tri
void rh::show_tables(){
    //employe
//creation model (masque du tableau) : permet recherche et tri
    proxy_emp = new QSortFilterProxyModel();

 //definir la source (tableau original)
    proxy_emp->setSourceModel(tmpemploye.afficher());

 //pour la recherche
    proxy_emp->setFilterCaseSensitivity(Qt::CaseInsensitive); //no diff btwn MAJ/MIN
    proxy_emp->setFilterKeyColumn(selcomemp); // Look in all table
   //remplissage tableau avec le masque
    ui->tableView->setModel(proxy_emp);

    //conge

    //creation model (masque du tableau) : permet recherche et tri
        proxy_co = new QSortFilterProxyModel();

     //definir la source (tableau original)
        proxy_co->setSourceModel(tmpco.afficher());

     //pour la recherche
        proxy_co->setFilterCaseSensitivity(Qt::CaseInsensitive); // S=s (pas de difference entre majiscule et miniscule)
        proxy_co->setFilterKeyColumn(selcomco); // chercher dans tout le tableau (-1) ou donner le numero de la colone
       //remplissage tableau avec le masque
        ui->tableView_3->setModel(proxy_co);

}

// index when clicking on tableview (employe)
void rh::on_tableView_clicked(const QModelIndex &index)
{
    id_emp=ui->tableView->model()->data(index).toInt();

}

// combobox index changed
void rh::on_comboBox_2_currentIndexChanged(int index)
{
    selcomemp=ui->comboBox_2->currentIndex();
    show_tables();
}


//recherche dynamique for both tables
void rh::on_lineEdit_23_textChanged(const QString &arg1)
{
    proxy_emp->setFilterFixedString(arg1);
}
void rh::on_lineEdit_26_textChanged(const QString &arg1)
{
    proxy_co->setFilterFixedString(arg1);

}

// refresh emlpoye
void rh::update_emp_list(){
    QSqlQueryModel *m=new QSqlQueryModel();
    QSqlQuery *querry=new QSqlQuery();
    querry->prepare("SELECT id FROM EMPLOYE");
    querry->exec();
    m->setQuery(*querry);

    ui->comboBox_3->setModel(m);
    ui->comboBox_4->setModel(m);



}

//combobox index
void rh::on_comboBox_5_currentIndexChanged(int index)
{
    selcomco=ui->comboBox_5->currentIndex();
    show_tables();
}

//click on table view
void rh::on_tableView_3_clicked(const QModelIndex &index)
{
    id_co=ui->tableView_3->model()->data(index).toInt();

}

//bouton supprimer
void rh::on_pushButton_27_clicked()
{
    bool test=tmpco.supprimer(id_co);
   if (test)
   {
       show_tables();
    QMessageBox::information(nullptr,QObject::tr("Supprimer employé"),
                             QObject::tr("Employé supprimé.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);
   }

}

//export excel
void rh::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "id", "char(20)");
    obj.addField(1, "nom", "char(20)");
    obj.addField(2, "prenom", "char(20)");
    obj.addField(3, "mail", "char(20)");
    obj.addField(4, "fonction", "char(20)");
    obj.addField(5, "score", "char(20)");


    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        QMessageBox::information(this, tr("Done"),
                                 QString(tr("%1 records exported!")).arg(retVal)
                                 );
    }
}



//ajouter co

void rh::on_pushButton_12_clicked()
{


    QString id =ui->lineEdit_54->text();
    QString type=ui->comboBox_7->currentText();
    QString debut=ui->dateEdit->date().toString("dd.MM.yyyy");
    QString fin=ui->dateEdit_2->date().toString("dd.MM.yyyy");
    int idemp=ui->comboBox_3->currentText().toInt();
    if (id.contains(QRegExp("[^0-9]")))
    {
     ui->label_2->setText("id doit contenir des chiffres seulement ! ") ;
    } else
    {
        Conge c(id.toInt(),type,debut,fin,idemp);
        bool test=c.ajouter();
        if (test)
        {
            show_tables();

            ui->lineEdit_54->clear();
            ui->comboBox_7->setCurrentIndex(0);
            ui->comboBox_3->setCurrentIndex(0);

        QMessageBox::information(nullptr,QObject::tr("Ajouer Congé"),
                                 QObject::tr("Congé ajouté.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }  ui->label_2->setText(" Congé affecté! ") ;
    }


}

//fill form tab conge
void rh::on_tableView_3_activated(const QModelIndex &index)
{
    QString val=ui->tableView_3->model()->data(index).toString();
     QSqlQuery qry;
     qry.prepare("select * from CONGE where ID=:id");
     qry.bindValue(":id",val);


     if(qry.exec())
       {while (qry.next())
      { ui->lineEdit_67->setText(qry.value(0).toString());
        ui->comboBox_8->setCurrentText(qry.value(1).toString());
        ui->comboBox_4->setCurrentText(qry.value(4).toString());
       ui->dateEdit_5->setDate(QDate::fromString(qry.value(2).toString(),"dd.MM.yyyy"));
       ui->dateEdit_6->setDate(QDate::fromString(qry.value(3).toString(),"dd.MM.yyyy"));

         }
   }
}
//modifier un conge
void rh::on_pushButton_33_clicked()
{

    int id =ui->lineEdit_67->text().toInt();
    QString type=ui->comboBox_8->currentText();
    QString debut=ui->dateEdit_5->date().toString("dd.MM.yyyy");
    QString fin=ui->dateEdit_6->date().toString("dd.MM.yyyy");
    int idemp=ui->comboBox_4->currentText().toInt();
        Conge c(id,type,debut,fin,idemp);
        bool test=c.modifier();
        if (test)
        {
            show_tables();

            ui->lineEdit_67->clear();
            ui->comboBox_8->setCurrentIndex(0);
            ui->comboBox_4->setCurrentIndex(0);

        QMessageBox::information(nullptr,QObject::tr("Modification congé"),
                                 QObject::tr("congé modifié.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        }

}


//chat


void rh::appendMessage(const QString &from, const QString &message)
{
    if (from.isEmpty() || message.isEmpty())
        return;

    QTextCursor cursor(ui->textEdit->textCursor());
    cursor.movePosition(QTextCursor::End);
    QTextTable *table = cursor.insertTable(1, 2, tableFormat);
    table->cellAt(0, 0).firstCursorPosition().insertText('<' + from + "> ");
    table->cellAt(0, 1).firstCursorPosition().insertText(message);
    QScrollBar *bar = ui->textEdit->verticalScrollBar();
    bar->setValue(bar->maximum());
}

void rh::returnPressed()
{
    QString text = ui->lineEdit_31->text();
    if (text.isEmpty())
        return;

    if (text.startsWith(QChar('/'))) {
        QColor color = ui->textEdit->textColor();
        ui->textEdit->setTextColor(Qt::red);
        ui->textEdit->append(tr("! Unknown command: %1")
                         .arg(text.left(text.indexOf(' '))));
        ui->textEdit->setTextColor(color);
    } else {
        client.sendMessage(text);
        appendMessage(myNickName, text);
    }

    ui->lineEdit_31->clear();
}

void rh::newParticipant(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QColor color = ui->textEdit->textColor();
    ui->textEdit->setTextColor(Qt::gray);
    ui->textEdit->append(tr("* %1 has joined").arg(nick));
    ui->textEdit->setTextColor(color);
    ui->listWidget->addItem(nick);
}

void rh::participantLeft(const QString &nick)
{
    if (nick.isEmpty())
        return;

    QList<QListWidgetItem *> items = ui->listWidget->findItems(nick,
                                                           Qt::MatchExactly);
    if (items.isEmpty())
        return;

    delete items.at(0);
    QColor color = ui->textEdit->textColor();
    ui->textEdit->setTextColor(Qt::gray);
   ui-> textEdit->append(tr("* %1 has left").arg(nick));
    ui->textEdit->setTextColor(color);
}

