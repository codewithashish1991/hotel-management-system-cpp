#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QObject>
#include <QMainWindow>
#include <QWidget>
#include <QSqlTableModel>
#include <QSqlQuery>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_rb6_clicked();

    void on_rb1_clicked();

    void on_rb2_clicked();

    void on_rb5_clicked();

    void on_rb3_clicked();

    void on_rb4_clicked();

    //void on_pushButton_clicked();

    void on_pbSubmit_clicked();

    void on_pbCancel_clicked();

    void on_pbOut_Search_clicked();

    void on_pbCheckout_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_resetRecords_clicked();

private:
    Ui::MainWindow *ui;
    QSqlTableModel *roominfo_model;
    QSqlTableModel *priceinfo_model;
    QSqlTableModel *checkout_model;
    QSqlTableModel *model_checkout;
    QSqlTableModel *model_checkin;
};

#endif // MAINWINDOW_H
