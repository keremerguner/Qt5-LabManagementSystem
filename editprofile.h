#ifndef EDITPROFILE_H
#define EDITPROFILE_H

#include <QDialog>

namespace Ui {
class EditProfile;
}

class EditProfile : public QDialog
{
    Q_OBJECT

public:
    explicit EditProfile(QWidget *parent = nullptr);
    ~EditProfile();

private slots:

    void on_pushButton_profileEdit_Update_clicked();

    void on_pushButton_2_ProfileEdit_Load_To_List_clicked();

    void on_listView_activated(const QModelIndex &index);

private:
    Ui::EditProfile *ui;
};

#endif // EDITPROFILE_H
