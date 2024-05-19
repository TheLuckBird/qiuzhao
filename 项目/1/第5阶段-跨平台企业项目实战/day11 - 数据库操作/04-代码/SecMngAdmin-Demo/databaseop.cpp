#include "databaseop.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>
#include <QDateTime>

DatabaseOP::DatabaseOP(QObject *parent) : QObject(parent)
{
}

bool DatabaseOP::openDatabase(QString hostName, QString dbName, QString user, QString passwd, int port)
{
    if(hostName.isNull() || dbName.isNull() || user.isNull() || passwd.isNull() || port <= 0)
    {
        return false;
    }

    QSqlDatabase db = QSqlDatabase::database();
    if(db.isOpen())
    {
        return true;
    }
    db = QSqlDatabase::addDatabase("QOCI");
    db.setHostName(hostName);
    db.setDatabaseName(dbName);
    db.setUserName(user);
    db.setPassword(passwd);
    db.setPort(port);

    // open db
    bool bl = db.open();
    if(bl == false)
    {
        QMessageBox::critical(NULL, "ERROR", db.lastError().text());
        return false;
    }
    return true;
}

void DatabaseOP::closeDatabase()
{
    // 得到实例
    QSqlDatabase base = QSqlDatabase::database();
    // 关闭数据库
    base.close();
}

// 查询数据
QVector<QVariantList> DatabaseOP::selectDatabase(QString table, QString filter)
{
    QString sql;
    QSqlQuery query;
    QVector<QVariantList> list;
    list.clear();
    if(filter.isEmpty())
    {
        sql = QString("select * from %1").arg(table);
    }
    else
    {
        sql = QString("select * from %1 where %2").arg(table).arg(filter);
    }
    qDebug() << "sql = " << sql;
    bool bl = query.exec(sql);
    if(bl == false)
    {
        qDebug() << "-------------------- select error ------------------------";
    }
    while(query.next())
    {
        QVariantList sublist;
        QSqlRecord record = query.record();
        for(int i=0; i<record.count(); ++i)
        {
            sublist.append(record.value(i));
        }
        list.append(sublist);
    }
    return list;
}

// 插入数据
bool DatabaseOP::insertDB(QString table, QStringList fields, QVariantList values)
{
    QStringList valList;
    QString myFields = fields.join(",");
    for(int i=0; i<values.size(); ++i)
    {
        if(values.at(i).type() == QVariant::String)
        {
            valList += ("'" + values.at(i).toString() + "'");
        }
        else if(values.at(i).type() == QVariant::DateTime)
        {
            QString str = QString("to_date('%1', 'yyyy-mm-dd hh24:mi:ss')")
                    .arg(values.at(i).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
            valList += str;
        }
        else
        {
            valList += values.at(i).toString();
        }
    }
    QString myValues = valList.join(",");

    QString sql = QString("insert into %1(%2) values(%3)").arg(table).arg(myFields).arg(myValues);
    qDebug() << "sql = " << sql;
    // 执行sql
    QSqlQuery query;
    QSqlDatabase db = QSqlDatabase::database();
    // 开启事务
    db.transaction();
    bool bl = query.exec(sql);
    if(bl)
    {
        // 提交
        db.commit();
        qDebug() << "=============== insert success ==============";
        return true;
    }
    else
    {
        // 回滚
        db.rollback();
        qDebug() << "=============== insert fail ==============";
        return false;
    }
}

// 更新数据
bool DatabaseOP::updateDB(QString table, QStringList fields, QVariantList values, QString filter)
{
    QString sql;
    QStringList list;
    QSqlQuery query;
    for(int i=0; i<fields.size(); ++i)
    {
        QString str;
        if(values.at(i).type() == QVariant::Int)
        {
            str = QString("%1=%2").arg(fields.at(i)).arg(values.at(i).toInt());
        }
        else if(values.at(i).type() == QVariant::DateTime)
        {
            str = QString("%1=to_date('%2', 'yyyy-mm-dd hh24:mi:ss')").arg(fields.at(i))
                    .arg(values.at(i).toDateTime().toString("yyyy-MM-dd hh:mm:ss"));
        }
        else
        {
            str = QString("%1='%2'").arg(fields.at(i)).arg(values.at(i).toString());
        }
        list.append(str);
    }
    sql = list.join(",");
    sql = QString("update %1 set %2 where %3")
            .arg(table).arg(sql).arg(filter);
    qDebug() << "sql = " << sql;
    QSqlDatabase db = QSqlDatabase::database();
    db.transaction();
    bool bl = query.exec(sql);
    if(bl)
    {
        // 成功
        db.commit();
        qDebug() << "=============== update sucess ==============";
        return true;
    }
    else
    {
        db.rollback();
        qDebug() << "=============== update fail ==============";
        return false;
    }

}

// 删除
bool DatabaseOP::deleteDB(QString table, QString filter)
{
    QSqlQuery query;
    QSqlDatabase db = QSqlDatabase::database();
    QString sql = QString("delete from %1 where %2").arg(table).arg(filter);
    qDebug() << "sql = " << sql;
    db.transaction();
    bool bl = query.exec(sql);
    if(bl)
    {
        db.commit();
        return true;
    }
    else
    {
        db.rollback();
        return false;
    }
}
