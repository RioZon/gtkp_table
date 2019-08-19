/**	\file file_ini.h
 *	\brief Содержит класс управления считыванием конфигурационных параметров.
*/

#ifndef FILE_INI_H
#define FILE_INI_H

#include <qfile.h>
#include <qregexp.h>
#include <qtextstream.h>

/**
 * @short Предоставляет компонент считывания из конфигурационного файла.
 **/
class File_Ini
{
public:
    /**
     * \brief Инициализация имени файла.
     * @param file_name --- имя конфигурационного файла.
     */
    File_Ini(const QString& file_name)
    {
        file = new QFile(file_name);
    }


    /**
     * \brief Получение значения параметра.
     * @param var --- имя параметра;
     * @param def --- значение по умолчанию.
     * \return Значение параметра.
     */
    QString GetVar(const QString& var,const QString& def)
    {
        if (file->open(QIODevice::ReadOnly))
            return def;
        QTextStream in(file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            line=line.replace(QRegExp(" "),"");
            line=line.replace(QRegExp("\t"),"");
            line=line.replace(QRegExp("\r"),"");
            line=line.replace(QRegExp("\n"),"");
            if(line.length()<3)
                continue;
            if(line.left(1)==QString("#"))
                continue;
            int eq_ind=line.indexOf("=");
            if (eq_ind <= 0)
                continue;
            QString name_var=line.left(eq_ind);
            QString val_var;
            if(name_var == var)
            {
                if(line.length() <= eq_ind+1)
                    val_var="";
                else
                    val_var=line.mid(eq_ind+1,300);
                file->close();
                return val_var;
            }
        }
        file->close();
        return def;
    }
private:
    QFile* file;
};

#endif
