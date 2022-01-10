#include "assistantinfo.h"
#include "ui_assistantinfo.h"

assistantinfo::assistantinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::assistantinfo)
{
    ui->setupUi(this);
}

assistantinfo::~assistantinfo()
{
    delete ui;
}

void assistantinfo::on_pushButton_assistant_load_tbl_clicked()
{

}


void assistantinfo::on_pushButton_assistan_blood_group_update_clicked()
{

}

