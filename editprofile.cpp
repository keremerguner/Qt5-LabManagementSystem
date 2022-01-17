#include "editprofile.h"
#include "ui_editprofile.h"
#include "mainwindow.h"
#include "qmessagebox.h"

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

void EditProfile::on_pushButton_clicked()
{

}

