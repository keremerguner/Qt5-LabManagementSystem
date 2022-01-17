#ifndef LABORANTINFO_H
#define LABORANTINFO_H

#include <QDialog>

namespace Ui {
class LaborantInfo;
}

class LaborantInfo : public QDialog
{
    Q_OBJECT

public:
    explicit LaborantInfo(QWidget *parent = nullptr);
    ~LaborantInfo();

private slots:
    void on_pushButton_Load_To_Table_clicked();

    void on_pushButton_close_clicked();

private:
    Ui::LaborantInfo *ui;
};

#endif // LABORANTINFO_H
