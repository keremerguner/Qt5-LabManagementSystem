#include "editprofile.h"
#include "ui_editprofile.h"
#include "mainwindow.h"
#include "qmessagebox.h"
#include "doctorinfo.h"

EditProfile::EditProfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditProfile)
{
    ui->setupUi(this);
}

EditProfile::~EditProfile()
{
    delete ui;
}


void EditProfile::on_pushButton_profileEdit_Update_clicked()
{
    MainWindow conn;
//Bulunan hastanin bilgilerinin guncellendigi yer
    QString name,surname;
    name=ui->lineEdit_Name_update->text();
    surname=ui->lineEdit_2_Surname_update->text();

    conn.connOpen();
    QSqlQuery qry;
//En sonda where diye eklenen yer nereyi parametre alarak duzenleme yapacagini belirtir. Biz TC'ye göre update islemini gerceklestiriyoruz
    qry.prepare("update Users set name='"+name+"',surname='"+surname+"' where surname='"+surname+"'");

    if(qry.exec()){
    QMessageBox::critical(this,tr("Edit"),tr("Update"));
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void EditProfile::on_pushButton_2_ProfileEdit_Load_To_List_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modalListView = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qryListView = new QSqlQuery(conn.mydb);

    qryListView->prepare("select name from Users where roll_id=1");

    qryListView->exec();
    modalListView->setQuery(*qryListView);
    ui->listView->setModel(modalListView);

    conn.connClose();
    //qDebug() << (modal->rowCount());
}


void EditProfile::on_listView_activated(const QModelIndex &index)
{
    QString val=ui->listView->model()->data(index).toString();
    MainWindow conn;

    conn.connOpen();
    QSqlQuery qryListView;
    qryListView.prepare("select * from Users where name='"+val+"'");

    if(qryListView.exec()){

        while(qryListView.next()){
            ui->lineEdit_Name_update->setText(qryListView.value(4).toString());
            ui->lineEdit_2_Surname_update->setText(qryListView.value(5).toString());

        }
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qryListView.lastError().text());
    }
}

