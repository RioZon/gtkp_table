/**	\file sp_connect.cpp
*	\brief Содержит класс, предоставляющий интерфейс работы с демоном spread.
*/

#include "sp_connect.h"

mailbox Sp_Connect::id=0;
char Sp_Connect::priv_gr[MAX_GROUP_NAME];


/**
* \brief Соединение со спридом.
* @param param_con --- строка соединения в формате порт@хост;
* @param private_name --- имя приватной группы.
* \return Результат соединения со спридом (содержит ошибку в случае неудачного соединения).
*/
int Sp_Connect::Connect(const char *param_con,const char *private_name)
{
    Disconnect();
    return SP_connect(param_con,private_name,0,0,&id,priv_gr);
}

/**
* \brief Подключение к группе демона сприд.
* @param group --- группа демона сприд.
* \return Результат подключения к группе демона сприд (содержит ошибку в случае неудачного подключения).
*/
int Sp_Connect::Join(const QString& group)
{
    if(!id) return -1;
    return SP_join(id,group.toStdString().c_str());
}

/**
* \brief Отсоединие от группы сприд.
* @param group --- группа сприд.
* \return Результат отсоединения от группы сприд.
*/
int Sp_Connect::Leave(const QString& group)
{
    if(!id) return -1;
    return SP_leave(id,group.toStdString().c_str());
}

/**
* \brief Отсоединение от демона сприд.
* \return 0.
*/
int Sp_Connect::Disconnect()
{
    if(id)
    {
        SP_disconnect(id);
        id=0;
    }
    return 0;
}
