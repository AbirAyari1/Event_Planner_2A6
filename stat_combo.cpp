//#include "stat_combo.h"
//#include "ui_stat_combo.h"

//stat_combo::stat_combo(QWidget *parent) :
//    QDialog(parent),
//    ui(new Ui::stat_combo)
//{
//    ui->setupUi(this);
//}

//stat_combo::~stat_combo()
//{
//    delete ui;
//}

//void stat_combo::choix_pie()
//{
//QSqlQuery q1,q2,q3,q4;
//qreal tot=0,c1=0,c2=0;

//q1.prepare("SELECT * FROM EVENEMENT");
//q1.exec();

//q2.prepare("SELECT * FROM EVENEMENT WHERE TYPEEVENEMENT = 'mariage'");
//q2.exec();

//q3.prepare("SELECT * FROM EVENEMENT WHERE TYPEEVENEMENT='soiree'");
//q3.exec();



//while (q1.next()){tot++;}
//while (q2.next()){c1++;}
//while (q3.next()){c2++;}


//c1=c1/tot;
//c2=c2/tot;


//// Define slices and percentage of whole they take up
//QPieSeries *series = new QPieSeries();
//series->append("mariage",c1);
//series->append("soiree",c2);

//}
