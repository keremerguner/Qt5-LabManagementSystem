#include "addusers.h"
#include "ui_addusers.h"
#include "mainwindow.h"
#include "qmessagebox.h"

AddUsers::AddUsers(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddUsers)
{
    ui->setupUi(this);
}

AddUsers::~AddUsers()
{
    delete ui;
}


void AddUsers::DataBaseControlUsers(){
//Database eger ki acilmazsa hata mesaji ( kontrol edildi )
    MainWindow conn;
    if(!conn.connOpen()){
        qDebug()<< "Failed to open the database";
        return;

    }

}

void AddUsers::DoctorAdd(){
//RadioButton Doktor ekleme islevi
    if(ui->radioButton_doctor_add->isChecked()){

        MainWindow conn;
//Yeni Doktor kayit ederken SAVE isleminin dondugu yer
        QString username,password,name,surname;
        username=ui->lineEdit_2_db_username->text();
        password=ui->lineEdit_3_db_password->text();
        name=ui->lineEdit_4_db_employee_name->text();
        surname=ui->lineEdit_5_db_employee_surname->text();


//Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
        conn.connOpen();
        QSqlQuery qry;
//Save isleminin sorgusunun dondugu yer
        qry.prepare("INSERT INTO Users(username,password,name,surname,roll_id) VALUES('"+username+"', '"+password+"','"+name+"','"+surname+"',1)");

        if(qry.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        conn.connClose();
        }
        else{
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    }


}

void AddUsers::AssistantAdd(){
//RadioButton Assistant ekleme islevi

    if(ui->radioButton_2_assistant_add->isChecked()){

        MainWindow conn;
//Yeni Asistant kayit ederken SAVE isleminin dondugu yer
        QString username,password,name,surname;
        username=ui->lineEdit_2_db_username->text();
        password=ui->lineEdit_3_db_password->text();
        name=ui->lineEdit_4_db_employee_name->text();
        surname=ui->lineEdit_5_db_employee_surname->text();


//Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
        conn.connOpen();
        QSqlQuery qry;
//Save isleminin sorgusunun dondugu yer
        qry.prepare("INSERT INTO Users(username,password,name,surname,roll_id) VALUES('"+username+"', '"+password+"','"+name+"','"+surname+"',2)");

        if(qry.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        conn.connClose();
        }
        else{
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    }

}

void AddUsers::LaborantAdd(){
//RadioButton Laborant ekleme islevi

    if(ui->radioButton_laborant_add->isChecked()){

        MainWindow conn;
//Yeni laborant kayit ederken SAVE isleminin dondugu yer
        QString username,password,name,surname;
        username=ui->lineEdit_2_db_username->text();
        password=ui->lineEdit_3_db_password->text();
        name=ui->lineEdit_4_db_employee_name->text();
        surname=ui->lineEdit_5_db_employee_surname->text();


//Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
        conn.connOpen();
        QSqlQuery qry;
//Save isleminin sorgusunun dondugu yer
        qry.prepare("INSERT INTO Users(username,password,name,surname,roll_id) VALUES('"+username+"', '"+password+"','"+name+"','"+surname+"',4)");

        if(qry.exec()){
        QMessageBox::critical(this,tr("Save"),tr("Saved"));
        conn.connClose();
        }
        else{
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }
    }

}


void AddUsers::on_pushButton_3_db_save_clicked()
{
//Hangi Users eklendiyse onun fonksiyonun dondugu kisim
    DataBaseControlUsers();
    DoctorAdd();
    AssistantAdd();
    LaborantAdd();

}

void AddUsers::on_pushButton_closed_clicked()
{
//Bir onceki menuye doner
    this->hide();
}

