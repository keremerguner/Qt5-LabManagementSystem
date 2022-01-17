#include "doctorinfo.h"
#include "ui_doctorinfo.h"
#include <QMessageBox>
#include "editprofile.h"

DoctorInfo::DoctorInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DoctorInfo)
{
    ui->setupUi(this);
    WelcomeTextDoctor();

    editProfile = new EditProfile();

//Database basariyla aciliyormu kontorlu yapildi
    MainWindow conn;
    if(!conn.connOpen()){

        ui->label_sec_status->setText("DataBase Hatasi ");
    }
    else{
        ui->label_sec_status->setText("Database Basariyla Baglandi");
    }
}

DoctorInfo::~DoctorInfo()
{
    delete ui;
}

void DoctorInfo::DataBaseControlDoctor(){
    MainWindow conn;
    if(!conn.connOpen()){
        qDebug()<< "Failed to open the database";
        return;
    }
}

void DoctorInfo::on_pushButton_clicked()
{
    DataBaseControlDoctor();
    MainWindow conn;
//Yeni hasta kayit ederken SAVE isleminin dondugu yer
    QString name,surname,blood_group,tc,gender,age;
    name=ui->txt_name->text();
    surname=ui->txt_surname->text();
    blood_group=ui->txt_blood_group->text();
    tc=ui->txt_tc->text();
    gender=ui->txt_gender->text();
    age=ui->txt_age->text();


//Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
    DataBaseControlDoctor();
    conn.connOpen();
    QSqlQuery qry;
//Save isleminin sorgusunun dondugu yer
    qry.prepare("INSERT INTO Users(name,surname,blood_group,tc,gender,age,roll_id) VALUES('"+name+"', '"+surname+"','"+blood_group+"','"+tc+"','"+gender+"','"+age+"',3)");

    if(qry.exec()){
    QMessageBox::critical(this,tr("Save"),tr("Saved"));
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }

}


void DoctorInfo::on_pushButton_Edit_clicked()
{

        MainWindow conn;
//Bulunan hastanin bilgilerinin guncellendigi yer
        QString name,surname,blood_group,tc,gender,age;
        name=ui->txt_name->text();
        surname=ui->txt_surname->text();
        blood_group=ui->txt_blood_group->text();
        tc=ui->txt_tc->text();
        gender=ui->txt_gender->text();
        age=ui->txt_age->text();


//Database icine giris yapildi mi kontrolu saglandi
        DataBaseControlDoctor();

        conn.connOpen();
        QSqlQuery qry;
//En sonda where diye eklenen yer nereyi parametre alarak duzenleme yapacagini belirtir. Biz TC'ye göre update islemini gerceklestiriyoruz
        qry.prepare("update Users set name='"+name+"',surname='"+surname+"',blood_group='"+blood_group+"',tc='"+tc+"',gender='"+gender+"',age='"+age+"' where tc='"+tc+"'");

        if(qry.exec()){
        QMessageBox::critical(this,tr("Edit"),tr("Update"));
        conn.connClose();
        }
        else{
            QMessageBox::critical(this,tr("error::"),qry.lastError().text());
        }


}


void DoctorInfo::on_pushButton_Delete_clicked()
{
//Delete isleminde sadece Tc'ye gore yapiyoruz
    MainWindow conn;
    QString tc;
    tc=ui->txt_tc->text();


//Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
    DataBaseControlDoctor();

    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from Users where tc='"+tc+"'");
//Delete islemi icin sorgumuzu yaptıgımız yer
    if(qry.exec()){
    QMessageBox::critical(this,tr("Delete"),tr("Deleted"));
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());
    }
}


void DoctorInfo::on_pushButton_load_tbl_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal = new QSqlQueryModel();
    QSqlQueryModel * modalListView = new QSqlQueryModel();

    conn.connOpen();
    QSqlQuery* qry = new QSqlQuery(conn.mydb);
    QSqlQuery* qryListView = new QSqlQuery(conn.mydb);

    qry->prepare("select name,surname,blood_group,tc from Users where roll_id=3");
    qryListView->prepare("select name from Users where roll_id=3");

    qry->exec();
    qryListView->exec();
    modal->setQuery(*qry);
    modalListView->setQuery(*qryListView);
    ui->tableView->setModel(modal);
    ui->listView->setModel(modalListView);


    conn.connClose();
    //qDebug() << (modal->rowCount());
}


void DoctorInfo::on_listView_activated(const QModelIndex &index)
{
    QString val=ui->listView->model()->data(index).toString();
    MainWindow conn;

//Database icine giris yapildi mi kontrolu saglandi (sorgulari yapildi)
    DataBaseControlDoctor();
//
    conn.connOpen();
    QSqlQuery qryListView;
    qryListView.prepare("select * from Users where name='"+val+"'");

    if(qryListView.exec()){

        while(qryListView.next()){
            ui->txt_tc->setText(qryListView.value(7).toString());
            ui->txt_name->setText(qryListView.value(4).toString());
            ui->txt_surname->setText(qryListView.value(5).toString());
            ui->txt_blood_group->setText(qryListView.value(6).toString());
            ui->txt_gender->setText(qryListView.value(8).toString());
            ui->txt_age->setText(qryListView.value(9).toString());


        }
    conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qryListView.lastError().text());
    }
}

void DoctorInfo::WelcomeTextDoctor(){

    MainWindow conn;

    QSqlQuery* qryAsDoc = new QSqlQuery(conn.mydb);

    qryAsDoc->prepare("select name from Users where roll_id=1");



    qryAsDoc->exec();
    while(qryAsDoc->next())
        {
            ui->label_7_login_doctor_info->setText("Welcome Dr. " + qryAsDoc->value(0).toString() + "!");

        }

}


void DoctorInfo::on_pushButton_2_closed_clicked()
{
    this->hide();
}


void DoctorInfo::on_pushButton_2_Edit_Proifle_Doctor_clicked()
{
    EditProfile editprofile;
    editprofile.setModal(true);
    editprofile.exec();
}

