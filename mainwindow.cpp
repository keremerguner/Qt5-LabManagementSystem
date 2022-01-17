#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "assistantinfo.h"
#include "addusers.h"
#include "laborantinfo.h"
#include <qmessagebox.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Database basariyla aciliyormu kontorlu yapildi
    if(!connOpen()){
        ui->label->setText("DataBase Hatasi ");
    }
    else{
        ui->label->setText("Database Basariyla Baglandi");
    }

//
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //Login Panelinde kullanıcı adi ve sifre line olusturuldu
    QString username,password;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_2_Password->text();
//
    //Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
    if(!connOpen()){
        qDebug()<< "Failed to open the database";
        return;

    }
//
    connOpen();
    QSqlQuery qry;
    qry.prepare("select * from Users where username='"+username +"'and password='"+password +"' and roll_id=1");

    if(qry.exec()){

        int count=0;
        while(qry.next()){

            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is TRUE ");
            //Eger basarili giris yapilirsa login ekrannii silip ikinci ekrani gösterir
            connClose();
            DoctorInfo doctorinfo;
            doctorinfo.setModal(true);
            doctorinfo.exec();
//
        }
        if(count<1){
            ui->label->setText("Username and password (is not) TRUE ");
        }

    }

    //ASSISTANT LOGIN
    qry.prepare("select * from Users where username='"+username +"'and password='"+password +"' and roll_id=2");

    if(qry.exec()){

        int count=0;
        while(qry.next()){

            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is TRUE ");
            //Eger basarili giris yapilirsa login ekrannii silip assitant ekrani gösterir
            connClose();
            assistantinfo assistantinfo;
            assistantinfo.setModal(true);
            assistantinfo.exec();

//
        }
        if(count<1){
            ui->label->setText("Username and password (is not) TRUE ");
        }

    }


    qry.prepare("select * from Users where username='"+username +"'and password='"+password +"' and roll_id=4");

    if(qry.exec()){

        int count=0;
        while(qry.next()){

            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is TRUE ");
            //Eger basarili giris yapilirsa login ekrannii silip assitant ekrani gösterir
            connClose();
            LaborantInfo laborantinfo;
            laborantinfo.setModal(true);
            laborantinfo.exec();

//
        }
        if(count<1){
            ui->label->setText("Username and password (is not) TRUE ");
        }

    }


//
}


void MainWindow::on_pushButton_2_Signin_clicked()
{
    //Login Panelinde kullanıcı adi ve sifre line olusturuldu
    QString username,password;
    username=ui->lineEdit_Username->text();
    password=ui->lineEdit_2_Password->text();

    connOpen();
    QSqlQuery qry;

    connClose();
    AddUsers addusers;
    addusers.setModal(true);
    addusers.exec();
}

