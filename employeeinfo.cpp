#include "employeeinfo.h"
#include "ui_employeeinfo.h"
#include <QMessageBox>

EmployeeInfo::EmployeeInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmployeeInfo)
{
    ui->setupUi(this);

    //Database basariyla aciliyormu kontorlu yapildi
    MainWindow conn;
    if(!conn.connOpen()){

        ui->label_sec_status->setText("DataBase Hatasi ");
    }
    else{
        ui->label_sec_status->setText("Database Basariyla Baglandi");
    }
}

EmployeeInfo::~EmployeeInfo()
{
    delete ui;
}

void EmployeeInfo::on_pushButton_clicked()
{
    MainWindow conn;
    //Login Panelinde kullanıcı adi ve sifre line olusturuldu
    QString roll_id,name,surname,blood_group,tc,gender,age;
    roll_id=ui->txt_roll_id->text();
    name=ui->txt_name->text();
    surname=ui->txt_surname->text();
    blood_group=ui->txt_blood_group->text();
    tc=ui->txt_tc->text();
    gender=ui->txt_gender->text();
    age=ui->txt_age->text();

//
    //Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
    if(!conn.connOpen()){
        qDebug()<< "Failed to open the database";
        return;

    }
//
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("INSERT INTO Users(roll_id,name,surname,blood_group,tc,gender,age) VALUES('"+roll_id+"', '"+name+"', '"+surname+"','"+blood_group+"','"+tc+"','"+gender+"','"+age+"')");

    if(qry.exec()){
    QMessageBox::critical(this,tr("Save"),tr("Saved"));
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
//
}


void EmployeeInfo::on_pushButton_Edit_clicked()
{

        MainWindow conn;
        //Login Panelinde kullanıcı adi ve sifre line olusturuldu
        QString roll_id,name,surname,blood_group,tc,gender,age;
        roll_id=ui->txt_roll_id->text();
        name=ui->txt_name->text();
        surname=ui->txt_surname->text();
        blood_group=ui->txt_blood_group->text();
        tc=ui->txt_tc->text();
        gender=ui->txt_gender->text();
        age=ui->txt_age->text();

    //
        //Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
        if(!conn.connOpen()){
            qDebug()<< "Failed to open the database";
            return;

        }
    //
        conn.connOpen();
        QSqlQuery qry;
        //En sonda where diye eklenen yer nereyi parametre alarak duzenleme yapacagini belirtir. Biz roll_id'ye göre update islemini gerceklestiriyoruz
        qry.prepare("update Users set roll_id='"+roll_id+"',name='"+name+"',surname='"+surname+"',blood_group='"+blood_group+"',tc='"+tc+"',gender='"+gender+"',age='"+age+"' where roll_id='"+roll_id+"'");

        if(qry.exec()){
        QMessageBox::critical(this,tr("Edit"),tr("Update"));
        conn.connClose();
        }
        else{
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    //

}


void EmployeeInfo::on_pushButton_Delete_clicked()
{
    //Delete isleminde sadece roll idye gore yapacagimiz icin onun disindakiler yorumda
    MainWindow conn;
    //Login Panelinde kullanıcı adi ve sifre line olusturuldu
    QString roll_id;
    //QString name,surname,blood_group,tc,gender,age
    roll_id=ui->txt_roll_id->text();
    //name=ui->txt_name->text();
    //surname=ui->txt_surname->text();
    //blood_group=ui->txt_blood_group->text();
    //tc=ui->txt_tc->text();
    //gender=ui->txt_gender->text();
    //age=ui->txt_age->text();

//
    //Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
    if(!conn.connOpen()){
        qDebug()<< "Failed to open the database";
        return;

    }
//
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from Users where roll_id='"+roll_id+"'");

    if(qry.exec()){
    QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void EmployeeInfo::on_pushButton_load_tbl_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select name,surname,blood_group from Users");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);

    conn.connClose();
    qDebug() << (modal->rowCount());
}

