#ifndef ADDUSERS_H
#define ADDUSERS_H

#include <QDialog>

namespace Ui {
class AddUsers;
}

class AddUsers : public QDialog
{
    Q_OBJECT

public:
    explicit AddUsers(QWidget *parent = nullptr);
    ~AddUsers();

private slots:
    void on_pushButton_3_db_save_clicked();

    void DataBaseControlUsers();

    void DoctorAdd();

    void AssistantAdd();

    void LaborantAdd();

    void on_pushButton_closed_clicked();

private:
    Ui::AddUsers *ui;
};

#endif // ADDUSERS_H
