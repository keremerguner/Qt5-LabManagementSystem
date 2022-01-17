#include "assistantinfo.h"
#include "ui_assistantinfo.h"
#include "mainwindow.h"
#include <QMessageBox>

assistantinfo::assistantinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assistantinfo)
{
    ui->setupUi(this);
    WelcomeText();

//Database basariyla aciliyormu kontorlu yapildi
    MainWindow conn;
    if(!conn.connOpen()){

        ui->label_third_status->setText("DataBase Hatasi ");
    }
    else{
        ui->label_third_status->setText("Database Basariyla Baglandi");
    }
}

assistantinfo::~assistantinfo()
{
    delete ui;
}

void assistantinfo::DataBaseControlAssistant(){
//Database eger ki acilmazsa hata mesaji ( kontrol edildi )
    MainWindow conn;
    if(!conn.connOpen()){
        qDebug()<< "Failed to open the database";
        return;

    }

}
void assistantinfo::on_pushButton_assistant_load_tbl_clicked()
{
//Assistanin Hatanin kan grubunu duzenlemesi icin bilgiler tabela yazdirildigi kisim
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select name,surname,blood_group,tc from Users where roll_id=3");


    qry->exec();
    modal->setQuery(*qry);
    ui->tableView_assistant->setModel(modal);

}


void assistantinfo::on_pushButton_assistan_blood_group_update_clicked()
{
    MainWindow conn;
//Hasta kan grubunun guncellenmesi icin assistant pannel
    QString blood_group,tc;
    blood_group=ui->txt_assistant_blood_group->text();
    tc=ui->txt_assistant_tc->text();


//Database icine giris yapildi mi kontrolu saglandi
    DataBaseControlAssistant();

    conn.connOpen();
    QSqlQuery qry;
//En sonda where diye eklenen yer nereyi parametre alarak duzenleme yapacagini belirtir. Biz TC'ye göre update islemini gerceklestiriyoruz
    qry.prepare("update Users set blood_group='"+blood_group+"',tc='"+tc+"' where tc='"+tc+"'");

    if(qry.exec()){
        QMessageBox::critical(this,tr("Edit"),tr("Update"));
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void assistantinfo::on_tableView_assistant_activated(const QModelIndex &index)
{
//TableViewda Kan grubunun editlendigi yer
    QString val=ui->tableView_assistant->model()->data(index).toString();

    MainWindow conn;

    if(!conn.connOpen()){

        ui->label_third_status->setText("DataBase Hatasi ");
    }

    QSqlQuery qry;
    qry.prepare("select * from Users where blood_group='"+val+"'");

    if(qry.exec()){

        while(qry.next()){

            ui->txt_assistant_blood_group->setText(qry.value(6).toString());
            ui->txt_assistant_tc->setText(qry.value(7).toString());

        }
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}


void assistantinfo::WelcomeText(){
//Sol ust barda Assistant bilgisi
    MainWindow conn;

    QSqlQuery* qryAs = new QSqlQuery(conn.mydb);

    qryAs->prepare("select name from Users where roll_id=2");



    qryAs->exec();
    while(qryAs->next())
        {
            ui->label_3_login_assistan_info->setText("Welcome Asst. " + qryAs->value(0).toString() + "!");

        }

}

void assistantinfo::on_pushButton_closed_clicked()
{
//Bir Onceki Menuye Doner
    this->hide();
}

