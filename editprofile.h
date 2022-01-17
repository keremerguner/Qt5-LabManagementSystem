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
    void on_pushButton_clicked();

private:
    Ui::EditProfile *ui;
};

#endif // EDITPROFILE_H
