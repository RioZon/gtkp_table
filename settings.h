#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <qstring.h>
#include <qvariant.h>

class Settings
{
public:
    static Settings* inst();
    void set(const QString& name, const QVariant& value);
    const QVariant& get(const QString& name) const;
    ~Settings();

private:
    Settings() {}
    static Settings* instance;
    std::map<QString,QVariant> conf;
};

#endif // SETTINGS_H
