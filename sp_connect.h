/**	\file sp_connect.h
*	\brief Содержит класс, предоставляющий интерфейс работы с демоном spread.
*/


#ifndef SP_CONNECT_H
#define SP_CONNECT_H

#include <sp.h>
#include <qstring.h>

/**
* \brief Предоставляет интерфейс работы с соединением spread.
**/
class Sp_Connect
{
public:
    static int Connect(const char *param_con="4803",const char *private_name="spread_u");
    static int Disconnect();
    static int Join(const QString& group);
    static int Leave(const QString& group);
    static mailbox id;  ///< Идентификатор соединения со сприд.
    static char priv_gr[MAX_GROUP_NAME];  ///< Имя приватной группы.
};

#endif
