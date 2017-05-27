#include "chconfig.h"

ChConfig::ChConfig()
{

}

void ChConfig::WriteConfigFile_Ini()
{
    //QSettings构造函数的第一个参数是ini文件的路径,第二个参数表示针对ini文件,第三个参数可以缺省
    QSettings *configIniWrite = new QSettings("./workspace/qt/Qttest/config.ini", QSettings::IniFormat);
    //向ini文件中写入内容,setValue函数的两个参数是键值对
    //向ini文件的第一个节写入内容,ip节下的第一个参数
    configIniWrite->setValue("/ip/first", "192.168.0.1");
    //向ini文件的第一个节写入内容,ip节下的第二个参数
    configIniWrite->setValue("ip/second", "127.0.0.1");
    //向ini文件的第二个节写入内容,port节下的第一个参数
    configIniWrite->setValue("port/open", "2222");
    //写入完成后删除指针
    delete configIniWrite;
}

void ChConfig::ReadConfigFile_Ini()
{
    QSettings *configIniRead = new QSettings("./workspace/qt/Qttest/config.ini", QSettings::IniFormat);
    //将读取到的ini文件保存在QString中，先取值，然后通过toString()函数转换成QString类型
    QString ipResult = configIniRead->value("/ip/second").toString();
    QString portResult = configIniRead->value("/port/open").toString();
    //读入入完成后删除指针
    delete configIniRead;
}
