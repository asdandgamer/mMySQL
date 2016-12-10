#ifndef GLOBALS
#define GLOBALS

#include <QString>
#include <QSettings>

extern QSettings *qsLang;
extern QSettings *qsSettings;
extern QString curLang;

inline QString getIniValueInLatin1(QSettings *iniFile, QString key, QString defaultValue)
{
    return iniFile->value(key, defaultValue).toString().toLatin1();
}

#endif // GLOBALS

