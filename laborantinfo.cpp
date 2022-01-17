#include "laborantinfo.h"
#include "ui_laborantinfo.h"
#include "mainwindow.h"

LaborantInfo::LaborantInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LaborantInfo)
{
    ui->setupUi(this);
}

LaborantInfo::~LaborantInfo()
{
    delete ui;
}

void LaborantInfo::on_pushButton_Load_To_Table_clicked()
{
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


void LaborantInfo::on_pushButton_close_clicked()
{
    this->hide();
}

