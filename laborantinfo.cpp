#include "laborantinfo.h"
#include "ui_laborantinfo.h"
#include "mainwindow.h"

LaborantInfo::LaborantInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaborantInfo)
{
    ui->setupUi(this);
    WelcomeTextLaborant();
}

LaborantInfo::~LaborantInfo()
{
    delete ui;
}

void LaborantInfo::on_pushButton_Load_To_Table_clicked()
{
//Sorgu islemleriyle birlikte Hastanin bilgilerini gösterir
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);

    qry->prepare("select name,surname,blood_group from Users where roll_id=3");

    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);


    conn.connClose();
}

void LaborantInfo::WelcomeTextLaborant(){
//Sol ust barda Laborant bilgisi
    MainWindow conn;

    QSqlQuery* qryAsDoc = new QSqlQuery(conn.mydb);

    qryAsDoc->prepare("select name from Users where roll_id=4");



    qryAsDoc->exec();
    while(qryAsDoc->next())
        {
            ui->label->setText("Welcome Lab. " + qryAsDoc->value(0).toString() + "!");

        }
}

void LaborantInfo::on_pushButton_close_clicked()
{
//Bir önceki ekrana atar
    this->hide();
}

