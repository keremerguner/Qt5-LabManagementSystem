#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    qry.prepare("select * from Users where username='"+username +"'and password='"+password +"' ");

    if(qry.exec()){

        int count=0;
        while(qry.next()){

            count++;
        }
        if(count==1){
            ui->label->setText("Username and password is TRUE ");
            //Eger basarili giris yapilirsa login ekrannii silip ikinci ekrani gösterir
            connClose();
            this->hide();
            EmployeeInfo employeeinfo;
            employeeinfo.setModal(true);
            employeeinfo.exec();
//
        }
        if(count<1){
            ui->label->setText("Username and password (is not) TRUE ");
        }

    }
//
}

