#include "login.h"
#include "ui_login.h"
#include<QString>
#include<QMessageBox>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QtGui>
#include"mainwindow.h"
#include"databaseconnection.h"
#include"chgpwd.h"
login::login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pblogin_clicked()
{
    if(ui->leUid->text().isEmpty()||ui->lePwd->text().isEmpty())
    {
        QMessageBox::information(this,tr("Notice"),tr("कृपया पूरी जानकारी दर्ज करें！"),QMessageBox::Ok);
        return;
    }
    QString uid=ui->leUid->text();
    QString pwd=ui->lePwd->text();

    if(connectiondatabase()){
        QSqlQuery query;
        query.prepare("select *from staff where sid=:sid and pwd=:pwd");
        query.bindValue(":sid",uid);
        query.bindValue(":pwd",pwd);
        query.exec();
        if(query.next())
        {
            MainWindow *w=new MainWindow();
            w->show();
            this->hide();
        }
        else
        {
            QMessageBox::information(this,tr("Warning"),tr("कृपया अपना खाता पासवर्ड जांचें！"),QMessageBox::Ok);
            ui->leUid->clear();
            ui->lePwd->clear();
            ui->leUid->setFocus();
        }
    }
}

void login::on_pbChgpwd_clicked()
{
        Chgpwd *c=new Chgpwd();
        c->show();
        this->hide();
}

void login::on_pbQuit_clicked()
{
    this->close();
}
