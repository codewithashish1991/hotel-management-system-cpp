#ifndef CHGPWD_H
#define CHGPWD_H

#include"login.h"
#include<QString>
#include<QMessageBox>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDriver>
#include<QtSql/QSql>
#include<QtGui>
namespace Ui {
class Chgpwd;
}

class Chgpwd : public QMainWindow
{
    Q_OBJECT

public:
    explicit Chgpwd(QWidget *parent = 0);
    ~Chgpwd();

private slots:
    void on_pbSubmit_clicked();

    void on_pbQuit_clicked();

private:
    Ui::Chgpwd *ui;
};

#endif // CHGPWD_H
