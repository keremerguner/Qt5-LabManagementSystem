#ifndef ASSISTANTINFO_H
#define ASSISTANTINFO_H

#include <QDialog>

namespace Ui {
class assistantinfo;
}

class assistantinfo : public QDialog
{
    Q_OBJECT

public:
    explicit assistantinfo(QWidget *parent = nullptr);
    ~assistantinfo();

private slots:
    void on_pushButton_assistant_load_tbl_clicked();

    void on_pushButton_assistan_blood_group_update_clicked();

    void on_tableView_assistant_activated(const QModelIndex &index);

    void WelcomeText();

    void DataBaseControlAssistant();

    void on_pushButton_closed_clicked();

private:
    Ui::assistantinfo *ui;
};

#endif // ASSISTANTINFO_H
