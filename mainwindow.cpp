#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "databaseconnection.h"
#include <sstream>
#include<QDate>
#include<QAbstractItemView>
#include<QDateTime>
#include<QMessageBox>
#include<QSqlRecord>
#include<QString>
#include<QSqlTableModel>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tabWidget->setCurrentIndex(0);
    if(connectiondatabase()){

        priceinfo_model=new QSqlTableModel(this);
        priceinfo_model->setTable("roomtype");
        priceinfo_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        priceinfo_model->select();
        priceinfo_model->removeColumn(priceinfo_model->fieldIndex("tid"));
        priceinfo_model->removeColumn(priceinfo_model->fieldIndex("amount"));
        priceinfo_model->setHeaderData(0,Qt::Horizontal,tr("Room type"));
        priceinfo_model->setHeaderData(1,Qt::Horizontal,tr("Price"));
        priceinfo_model->setHeaderData(2,Qt::Horizontal,tr("Deposit"));
        priceinfo_model->setHeaderData(3,Qt::Horizontal,tr("Describe"));
        ui->tvPriceInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tvPriceInfo->setModel(this->priceinfo_model);

        this->roominfo_model=new QSqlTableModel(this);
        this->roominfo_model->setTable("room");
        this->roominfo_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        this->roominfo_model->select();
        this->roominfo_model->setHeaderData(0,Qt::Horizontal,tr("Room number"));
        this->roominfo_model->setHeaderData(2,Qt::Horizontal,tr("State"));
        ui->tvRoomInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tvRoomInfo->setModel(this->roominfo_model);
        ui->tvRoomInfo->hideColumn(1);
        ui->rb1->setChecked(true);
        this->roominfo_model->setFilter("tid=1");
        this->roominfo_model->select();
        ui->leID->setText("");
        ui->leUserName->setText("");
        ui->leRoomID->setText("");
        ui->leNumOfNig->setText("");

        checkout_model=new QSqlTableModel(this);
        checkout_model->setTable("checkin");
        checkout_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
        checkout_model->setHeaderData(1,Qt::Horizontal,tr("Room number"));
        checkout_model->setHeaderData(2,Qt::Horizontal,tr("check in time"));
        checkout_model->setHeaderData(3,Qt::Horizontal,tr("Check-in days"));
        checkout_model->setHeaderData(4,Qt::Horizontal,tr("Deposit"));
        checkout_model->select();
        //checkout_model->removeColumn(this->checkout_model->fieldIndex("engagedate"));
        checkout_model->removeColumn(this->checkout_model->fieldIndex("engagecaash"));
        checkout_model->removeColumn(this->checkout_model->fieldIndex("sid"));
        ui->tvQuery->setModel(checkout_model);
        ui->tvQuery->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model_checkin=new QSqlTableModel(this);
        model_checkin->setTable("checkin");
        model_checkin->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model_checkin->select();
       model_checkin->setHeaderData(0,Qt::Horizontal,tr("cnumber"));
        model_checkin->setHeaderData(1,Qt::Horizontal,tr("Room number"));
        model_checkin->setHeaderData(2,Qt::Horizontal,tr("Check-in date"));
        model_checkin->setHeaderData(4,Qt::Horizontal,tr("Stay days"));
        ui->tvCheckin->setModel(this->model_checkin);
        ui->tvCheckin->hideColumn(3);
        ui->tvCheckin->hideColumn(5);
        ui->tvCheckin->hideColumn(6);
        ui->tvCheckin->setEditTriggers(QAbstractItemView::NoEditTriggers);
        model_checkout= new  QSqlTableModel(this);
        // model_checkout->setTable("this");
        model_checkout->setTable("checkout");
        model_checkout->setEditStrategy(QSqlTableModel::OnManualSubmit);
        model_checkout->select();
        model_checkout->setHeaderData(0,Qt::Horizontal,tr("client number"));
        model_checkout->setHeaderData(1,Qt::Horizontal,tr("Room number"));
        model_checkout->setHeaderData(2,Qt::Horizontal,tr("Check-in days"));
        model_checkout->setHeaderData(3,Qt::Horizontal,tr("Refund date"));
        model_checkout->setHeaderData(4,Qt::Horizontal,tr("Payment amount"));
        ui->tvCheckout->setModel(this->model_checkout);
        ui->tvCheckout->setEditTriggers(QAbstractItemView::NoEditTriggers);
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rb6_clicked()
{
    this->roominfo_model->setFilter("tid=6");
    this->roominfo_model->select();
}

void MainWindow::on_rb1_clicked()
{
    this->roominfo_model->setFilter("tid=1");
    this->roominfo_model->select();


}

void MainWindow::on_rb2_clicked()
{
    this->roominfo_model->setFilter("tid=2");
    this->roominfo_model->select();
}

void MainWindow::on_rb5_clicked()
{
    this->roominfo_model->setFilter("tid=5");
    this->roominfo_model->select();
}

void MainWindow::on_rb3_clicked()
{
    this->roominfo_model->setFilter("tid=3");
    this->roominfo_model->select();
}

void MainWindow::on_rb4_clicked()
{
    this->roominfo_model->setFilter("tid=4");
    this->roominfo_model->select();
}

void MainWindow::on_pbSubmit_clicked()
{

    QString cnum =ui->leID->text();
    QString cname =ui->leUserName->text();
    QString rid =ui->leRoomID->text();
    QString day =ui->leNumOfNig->text();
    QString state ;
    QDateTime time;
    if(connectiondatabase()){
        QSqlQuery query;
        query.prepare("select state from room where rid =?");
        query.bindValue(0,rid);
        query.exec();
        if(query.next())
        {
            state =query.value(0).toString();
            if(state==tr("Occupy"))
            {
                QMessageBox::warning(this,tr("info"),tr("Room occupied!"));
                return ;
            }
        }

        query.prepare("select * from client where cnumber = ?");
        query.bindValue(0, cnum);
        query.exec();

        if(!query.next())
        {
            query.prepare("insert into client (cnumber, name) values (:id,:name)");
            query.bindValue(":id",cnum);
            query.bindValue(":name",cname);
            if(query.exec()){
                //qDebug() << getLastExecutedQuery(query);
                QMessageBox::information(this,tr("info"),tr("New client added"));
            }else{
                QMessageBox::information(this,tr("info"),tr("something went wrong!"));
            }
        }
        query.prepare("select foregift from room,roomtype where room.tid and room.rid=?");
        query.bindValue(0, rid);
        query.exec();
        QString cash = QString('0');
        if(query.next())
        {
            cash = query.value(0).toString();
            //QMessageBox::information(this,tr("info"), cash);

        }
        QString stime =time.currentDateTime().toString();
        query.prepare("INSERT INTO checkin (cnumber, rid, engagedate, engagecash) VALUES"
                      "(:cnum, :rid, :engagedate, :engagecash)");
        query.bindValue(":cnum", cnum);
        query.bindValue(":rid", rid);
        query.bindValue(":engagedate", day);
        query.bindValue(":engagecash", cash);

        if (query.exec())
        {
            query.prepare("update room set state ='Occupy' where id =?");
            query.bindValue(0,rid);
            query.exec();
            QMessageBox::information(this,tr("info"),tr("Check in successfully"));

         }
        else{
            qDebug() << getLastExecutedQuery(query);
            QMessageBox::information(this,tr("info"),tr("Check-in failed"));
        }
    }else{
        QMessageBox::information(this,tr("info"),tr("Database connection lost."));
    }


}




void MainWindow::on_pbCancel_clicked()
{
    ui->leID->setText("");
    ui->leUserName->setText("");
    ui->leRoomID->setText("");
    ui->leNumOfNig->setText("");
}

void MainWindow::on_pbOut_Search_clicked()
{

    if(ui->leOut_ID->text().isEmpty())
    {

        QMessageBox::information(this,tr("hint"),tr("Please enter identification information"), QMessageBox::Ok);
        return ;

    }
    QString cnumber=ui->leOut_ID->text().trimmed();

    this->checkout_model->setFilter(QObject::tr("cnumber=%1").arg(cnumber));
    this->checkout_model->select();
    ui->tvQuery->setModel(checkout_model);

}

void MainWindow::on_pbCheckout_clicked()
{


    if(this->checkout_model->record(0).isEmpty())
    {

        QMessageBox::information(this,tr("hint"),tr(" Please check the information"), QMessageBox::Ok);
        return ;

    }
  QDateTime closedatetime=QDateTime::currentDateTime();
  QDateTime opendatetime;
  QDate closedate=closedatetime.date();
  QDate opendate;
  int realdate=1;
  opendatetime=this->checkout_model->record(0).value("opendate").toDateTime();

  opendate=opendatetime.date();
  if(closedate.year()==opendate.year())
  {
      realdate +=closedate.dayOfYear()-opendate.dayOfYear();

  }
  else
  {
      int tempyear=opendate.year();
      while(tempyear !=closedate.year())
      {
          if( QDate::isLeapYear(opendate.year()))
          {
              realdate+=366;
          }
          else
          {
              realdate+=365;
          }
          tempyear ++;
      }
      realdate+=closedate.dayOfYear()-opendate.dayOfYear();
      }
  ui->leRealdate->setText(QString::number(realdate));
  int price=0;
  QString rid;
  rid=this->checkout_model->record(0).value("rid").toString();
  QSqlQuery query;
  query.prepare("select roomtype.price from roomtype where roomtype.tid=(select room.tid from room where room.rid=:rid)");
  query.bindValue(":rid",rid);
  query.exec();
  if(query.first())
  {
      price=query.value(0).toInt();
      price*=realdate;
  }
  ui->lePay->setText(QString::number(price));
  QString ID=this->checkout_model->record(0).value("cnumber").toString();
  query.prepare("delete from checkin where cnumber=:cnumber and opendate=:opendate");
  query.bindValue(":cnumber",ID);
  query.bindValue(":opendate",opendatetime);
  query.exec();
  query.prepare("insert into checkout (cnumber,rid,opendate,closedate,cash)values(:cnumber,:rid,:opendate,:closedate,:cash)");
  query.bindValue(":cnumber",ID);
  query.bindValue(":rid",rid);
  query.bindValue(":opendate",opendatetime);
  query.bindValue(":closedate",closedatetime);
  query.bindValue(":cash",price);
  query.exec();
  query.prepare("update room set room.state = 'idle' where rid=:rid");
  query.bindValue(":rid",rid);
  if(query.exec()){
    QMessageBox::information(this,tr("hint"),tr("Checkout marked successfully"), QMessageBox::Ok);
  }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index==3)
    {
        model_checkin->select();
        ui->tvCheckin->setModel(this->model_checkin);
        model_checkout->select();
        ui->tvCheckout->setModel(this->model_checkout);

    }
    else if(index==2)
    {
        this->model_checkout->select();
        ui->tvQuery->setModel(this->checkout_model);

    }
}

void MainWindow::on_resetRecords_clicked()
{
    this->checkout_model->setFilter(QObject::tr("cnumber!=%1").arg('0'));
    this->model_checkout->select();
    ui->tvQuery->setModel(this->checkout_model);
    ui->leOut_ID->setText("");
}
