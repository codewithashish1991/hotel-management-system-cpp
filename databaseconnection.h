#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include<QtSql/qsqlquery.h>
#include<QtSql/QSqlDriver>
#include<QString>
#include<QtSql/QSqlDatabase>
#include<QObject>
static bool connectiondatabase()
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("hotel");
    db.setUserName("root");
    db.setPassword("your-password");
    if(!db.open())
    {
        return false;
    }
    return true;
}

static QString getLastExecutedQuery(const QSqlQuery& query)
{
    QString str = query.lastQuery();
    QMapIterator<QString, QVariant> it(query.boundValues());

    it.toBack();

    while (it.hasPrevious())
    {
        it.previous();
        str.replace(it.key(),it.value().toString());
    }
    return str;
}

#endif // DATABASECONNECTION_H
