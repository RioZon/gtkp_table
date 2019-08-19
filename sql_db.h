#ifndef SQL_DB_H
#define SQL_DB_H

#include <QString>
#include <QtSql>
struct SQLParams;

class SQL_DB
{
public:
    SQL_DB();
    static void setConfig(const QString& host,
                   const QString& db,
                   const QString& user,
                   const QString& password);
    static void setData(const QString& host,
                 const QString& db,
                 const QString& user,
                 const QString& password);
    static bool connectConfig();
    static bool connectData();
    static void disconnect();
private:
    static SQLParams config;
    static SQLParams data;
    static QSqlDatabase db;
};

#endif // SQL_DB_H
