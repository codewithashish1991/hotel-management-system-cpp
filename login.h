#ifndef LOGIN_H
#define LOGIN_H
#include<QString>
#include<QMessageBox>
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlDatabase>
#include<QtGui>
#include <QMainWindow>

namespace Ui {
class login;
}

class login : public QMainWindow
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pblogin_clicked();

    void on_pbChgpwd_clicked();

    void on_pbQuit_clicked();

private:
    Ui::login *ui;

};

#endif // LOGIN_H
