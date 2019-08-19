#include "sql_db.h"
#include <iostream>

struct SQLParams
{
    QString host;
    QString database;
    QString user;
    QString password;
};

SQLParams SQL_DB::config;
SQLParams SQL_DB::data;
QSqlDatabase SQL_DB::db;

void SQL_DB::setConfig(const QString &host, const QString &db, const QString &user, const QString &password)
{
    config.host = host;
    config.database = db;
    config.user = user;
    config.password = password;
}

void SQL_DB::setData(const QString &host, const QString &db, const QString &user, const QString &password)
{
    data.host = host;
    data.database = db;
    data.user = user;
    data.password = password;
}

bool SQL_DB::connectConfig()
{
    if (db.isOpen()) {
        db.close();
    }
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(config.database);
    db.setHostName(config.host);
    db.setUserName(config.user);
    db.setPassword(config.password);
    if (!db.open()) {
        std::cerr << "Cannot open config database "<< std::endl;
        return false;
    }
    return true;
}

bool SQL_DB::connectData()
{
    if (db.isOpen()) {
        db.close();
    }
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setDatabaseName(data.database);
    db.setHostName(data.host);
    db.setUserName(data.user);
    db.setPassword(data.password);
    if (!db.open()) {
        std::cerr << "Cannot open data database " << std::endl;
        return false;
    }
    return true;
}

void SQL_DB::disconnect()
{
    db.close();
}
