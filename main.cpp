#include "widget.h"
#include "file_ini.h"
#include "settings.h"
#include <QApplication>
#include <syslog.h>
#include "sql_db.h"
#include "iostream"
#include <QtWidgets>

/**
 * \brief Функция входа в программу.
 * @param argc --- количество параметров командной строки;
 * @param argv --- параметры командной строки.
 */
int main(int argc, char *argv[])
{
    syslog(LOG_NOTICE,"Start gtkp_table");
    File_Ini file_ini(argc > 1 ? argv[1] : "params.ini");
    SQL_DB::setConfig(
                file_ini.GetVar("CONFIG_HOST","localhost"),
                file_ini.GetVar("CONFIG_DB","gtkp_table"),
                file_ini.GetVar("CONFIG_USER","user"),
                file_ini.GetVar("CONFIG_PASSWORD","password"));
    SQL_DB::setData(
                file_ini.GetVar("DATA_HOST","localhost"),
                file_ini.GetVar("DATA_DB","kgm"),
                file_ini.GetVar("DATA_USER","user"),
                file_ini.GetVar("DATA_PASSWORD","password"));
    int start_time = file_ini.GetVar("START_TIME","8").toInt();
    Settings::inst()->set("startTime",start_time);
    QString sp_param   =  file_ini.GetVar("SPREAD_PARAM","4803@gac");
    Settings::inst()->set("spreadParam",sp_param);
    if (!SQL_DB::connectConfig()) {
        return -1;
    }
    QApplication a(argc, argv);
    MainWidget* w = new MainWidget();
    w->show();

    return a.exec();
}
