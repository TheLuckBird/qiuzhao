#ifndef DATABASEOP_H
#define DATABASEOP_H

#include <QObject>

class DatabaseOP : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseOP(QObject *parent = nullptr);

    // 打开数据库
    bool openDatabase(QString hostName, QString dbName, QString user, QString passwd, int port);
    // 关闭数据库
    void closeDatabase();
    // 数据库查询
    QVector<QVariantList> selectDatabase(QString table, QString filter = QString());
    // 添加数据
    bool insertDB(QString table, QStringList fields, QVariantList values);
    // 更新数据库
    bool updateDB(QString table, QStringList field, QVariantList value, QString filter);
    // 删除数据库
    bool deleteDB(QString table, QString filter);

signals:

public slots:
private:
    QString m_dbType;

};

#endif // DATABASEOP_H
