#-------------------------------------------------
#
# Project created by QtCreator 2019-08-07T10:47:06
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = gtkp_table
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        objects.cpp \
        observer.cpp \
        observer_factory.cpp \
        settings.cpp \
        sp_connect.cpp \
        sql_db.cpp \
        subject.cpp \
        table_line.cpp \
        table_object.cpp \
        table_text.cpp \
        text_cycle.cpp \
        text_interval.cpp \
        text_num_rosp.cpp \
        text_num_train.cpp \
        text_processed_cars.cpp \
        text_processed_otc.cpp \
        text_processed_trains.cpp \
        text_rasform_cars.cpp \
        text_rasform_trains.cpp \
        text_repeats_cars.cpp \
        text_repeats_otc.cpp \
        text_repeats_train.cpp \
        text_speed_thrust_average.cpp \
        text_speed_thrust_current.cpp \
        text_time.cpp \
        text_time_start_rosp.cpp \
        widget.cpp

HEADERS += \
        events.h \
        file_ini.h \
        objects.h \
        observer.h \
        observer_factory.h \
        settings.h \
        sp_connect.h \
        sql_db.h \
        subject.h \
        table_line.h \
        table_object.h \
        table_text.h \
        text_cycle.h \
        text_interval.h \
        text_num_rosp.h \
        text_num_train.h \
        text_processed_cars.h \
        text_processed_otc.h \
        text_processed_trains.h \
        text_rasform_cars.h \
        text_rasform_trains.h \
        text_repeats_cars.h \
        text_repeats_otc.h \
        text_repeats_train.h \
        text_speed_thrust_average.h \
        text_speed_thrust_current.h \
        text_time.h \
        text_time_start_rosp.h \
        widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS +=
