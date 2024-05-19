#ifndef JSONPARSE_H
#define JSONPARSE_H

#include <QObject>
#include <QFile>

const QString CFGNAME = "dbcfg.json";

class JsonParse : public QObject
{
    Q_OBJECT
public:
    explicit JsonParse(QObject *parent = nullptr);
    ~JsonParse();

    // 打开文件
    QJsonDocument openJsonFile(QString fileName = CFGNAME);
    // 获得hostname
    QString getHostName();
    // 获得dbname
    QString getDBName();
    // 获得user
    QString getUserName();
    // 获得passwd
    QString getPassWd();
    // 获得port
    int getDBPort();

    // 写数据到json文件
    bool writeJson(QString hostname, QString dbname, QString port, QString user, QString pwd);

private:
    // 读json文件
    QString readJson(QString key, QString fileName = CFGNAME);

signals:

public slots:
private:
};


#endif // JSONPARSE_H
