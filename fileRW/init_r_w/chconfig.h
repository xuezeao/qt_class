#ifndef CHCONFIG_H
#define CHCONFIG_H

#include <QSettings>

class ChConfig
{
public:
    ChConfig();
    void WriteConfigFile_Ini();
    void ReadConfigFile_Ini();
};

#endif // CHCONFIG_H
