#ifndef DOCTORINFO_H
#define DOCTORINFO_H

#include <QDialog>
#include "mainwindow.h"
#include "editprofile.h"

namespace Ui {
class DoctorInfo;
}

class DoctorInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DoctorInfo(QWidget *parent = nullptr);
    ~DoctorInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Edit_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_load_tbl_clicked();

    void on_listView_activated(const QModelIndex &index);

    void WelcomeTextDoctor();

    void DataBaseControlDoctor();

    void on_pushButton_2_closed_clicked();

    void on_pushButton_2_Edit_Proifle_Doctor_clicked();

private:
    Ui::DoctorInfo *ui;

    EditProfile *editProfile;
};

#endif // DOCTORINFO_H
