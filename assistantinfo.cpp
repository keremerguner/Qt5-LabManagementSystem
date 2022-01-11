#include "assistantinfo.h"
#include "ui_assistantinfo.h"
#include "mainwindow.h"
#include <QMessageBox>

assistantinfo::assistantinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assistantinfo)
{
    ui->setupUi(this);

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

void assistantinfo::on_pushButton_assistant_load_tbl_clicked()
{
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

}


void assistantinfo::on_tableView_assistant_activated(const QModelIndex &index)
{
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

        }
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}

