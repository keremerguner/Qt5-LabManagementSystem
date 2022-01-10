#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class EmployeeInfo;
}

class EmployeeInfo : public QDialog
{
    Q_OBJECT

public:
    explicit EmployeeInfo(QWidget *parent = nullptr);
    ~EmployeeInfo();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_Edit_clicked();

    void on_pushButton_Delete_clicked();

    void on_pushButton_load_tbl_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_load_list_name_clicked();

    void on_listView_indexesMoved(const QModelIndexList &indexes);

    void on_listView_windowIconTextChanged(const QString &iconText);

    void on_listView_activated(const QModelIndex &index);

    void on_comboBox_currentIndexChanged(const QString &arg1);

private:
    Ui::EmployeeInfo *ui;
};

#endif // EMPLOYEEINFO_H
