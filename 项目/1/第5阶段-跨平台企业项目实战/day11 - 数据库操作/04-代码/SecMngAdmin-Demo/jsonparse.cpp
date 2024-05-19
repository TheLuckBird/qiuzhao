#include "jsonparse.h"
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QFile>
#include <QDebug>
#include <QFileInfo>

JsonParse::JsonParse(QObject *parent) : QObject(parent)
{

}

JsonParse::~JsonParse()
{
}

QJsonDocument JsonParse::openJsonFile(QString fileName)
{
    QFileInfo info(fileName);
    if(!info.exists())
    {
        // 文件不存在
        return QJsonDocument();
    }
    // 打开文件
    QFile file(fileName);
    bool bl = file.open(QFile::ReadWrite);
    if(bl == false)
    {
        qDebug() << "文件打开失败...";
        return QJsonDocument();
    }

    // 读文件
    QByteArray all = file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(all);
    return doc;
}

QString JsonParse::readJson(QString key, QString fileName)
{
    QJsonDocument doc = openJsonFile(fileName);
    if(doc.isNull())
    {
        return QString();
    }

    // 解析json
    if(doc.isObject())
    {
        QJsonObject obj = doc.object();
        QString value = obj.value(key).toString();
        return value;
    }
    return QString();
}

QString JsonParse::getHostName()
{
    return readJson("hostname");
}

QString JsonParse::getDBName()
{
    return readJson("dbname");
}

QString JsonParse::getUserName()
{
    return readJson("dbuser");
}

QString JsonParse::getPassWd()
{
    return readJson("dbpasswd");
}

int JsonParse::getDBPort()
{
    return readJson("dbport").toInt();
}

bool JsonParse::writeJson(QString hostname, QString dbname, QString port, QString user, QString pwd)
{
    QJsonObject obj;
    obj.insert("hostname", hostname);
    obj.insert("dbname", dbname);
    obj.insert("dbport", port);
    obj.insert("dbpasswd", pwd);
    obj.insert("dbuser", user);

    QFile file(CFGNAME);
    file.open(QFile::WriteOnly);
    QJsonDocument doc(obj);
    QByteArray json = doc.toJson();
    file.write(json);
    file.close();

    return true;
}

