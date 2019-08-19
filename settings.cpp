#include "settings.h"
#include <iostream>

Settings* Settings::instance;



Settings *Settings::inst()
{
    if (!instance) {
        instance = new Settings();
    }
    return instance;
}

void Settings::set(const QString &name, const QVariant &value)
{
    conf[name] = value;
}

const QVariant &Settings::get(const QString &name) const
{
    auto it = conf.find(name);
    if(it == conf.end())
    {
        std::cerr << name.toStdString() << " not found" << std::endl;
        throw std::runtime_error("Parameter not found");
    }
    return it->second;
}

Settings::~Settings()
{
    delete instance;
}

