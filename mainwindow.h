#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include "doctorinfo.h"
#include "assistantinfo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    void connClose(){

        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen(){

//DataBase baglantilari olusturuldu
        mydb = QSqlDatabase::addDatabase("QSQLITE");
        mydb.setDatabaseName("C:/Users/ergun/Desktop/dbBaglantiQtProje/qtDenemeDb2/qtDataBase/dataBase.sqlite.db");

//Database basariyla aciliyormu kontorlu yapildi
        if(!mydb.open()){
            qDebug()<<("DataBase Hatasi ");
            return false;
        }
        else{
            qDebug()<<("Database Basariyla Baglandi");
            return true;
        }
    }


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    assistantinfo *assistantinfoWelcomeText;


};
#endif // MAINWINDOW_H
