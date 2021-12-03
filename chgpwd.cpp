#include "chgpwd.h"
#include "ui_chgpwd.h"
#include"login.h"
#include "databaseconnection.h"
#include<QString>
#include<qmessagebox.h>
#include<QtSql/QSqlDatabase>
#include<QtGui>

Chgpwd::Chgpwd(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Chgpwd)
{
    ui->setupUi(this);
}

Chgpwd::~Chgpwd()
{
    delete ui;
}

void Chgpwd::on_pbSubmit_clicked()
{
      QString uid=ui->leUid->text().trimmed();
      QString pwd=ui->lePwd->text().trimmed();
      QString newpwd=ui->leNewPwd->text().trimmed();
      QString newpwdcopy=ui->leNewPwdCopy->text().trimmed();
      if(uid.isEmpty()||pwd.isEmpty()||newpwd.isEmpty()||newpwdcopy.isEmpty())
      {
          QMessageBox::information(this,tr("Notice"),tr("कृपया पूरी जानकारी दर्ज करें ！"),QMessageBox::Ok);
          return;
      }
      if(newpwd!=newpwdcopy)
      {
          QMessageBox::information(this,tr("Notice"),tr("कृपया पासवर्ड जांचें！"),QMessageBox::Ok);
          return;
      }

      if(connectiondatabase()){
          QSqlQuery query;
          query.prepare("select * from staff where sid=:sid and pwd=:pwd");
          query.bindValue(":sid",uid);
          query.bindValue(":pwd",pwd);
          query.exec();
          if(query.next())
          {
               query.clear();
               query.prepare("update  staff set pwd=:pwd where sid=:sid");
               query.bindValue(":sid",uid);
               query.bindValue(":pwd",newpwd);
               if(query.exec())
               {
                   if(query.isActive())
                   {
                       QMessageBox::information(this,tr("Notice"),tr("आपका पासवर्ड सफलतापूर्वक बदल गया!"),QMessageBox::Ok);
                       return;
                   }
               }
               else
               {
                     QMessageBox::information(this,tr("Warning"),tr("आपका पासवर्ड बदला नहीं जा सकता!!!"),QMessageBox::Ok);
                     return;
               }
          }
          else
          {
              QMessageBox::information(this,tr("Warning"),tr("यूजर आईडी या पासवर्ड गलत है !"),QMessageBox::Ok);
              ui->leUid->clear();
              ui->lePwd->clear();
              ui->leNewPwd->clear();
              ui->leNewPwdCopy->clear();
              ui->leUid->setFocus();
          }
      }

}

void Chgpwd::on_pbQuit_clicked()
{
        login *log=new login();
        log->show();
        this->hide();
}
