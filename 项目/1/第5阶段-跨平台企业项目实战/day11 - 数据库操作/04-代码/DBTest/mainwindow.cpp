#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << QSqlDatabase::drivers();
    // 添加数据库实例
    QSqlDatabase db = QSqlDatabase::addDatabase("QOCI");
    // 设置连接信息
    db.setHostName("192.168.237.166");  // 主机地址
    db.setPort(1521);   // 如果是默认端口, 可以不设置
    db.setDatabaseName("orcl"); // 数据库名
    db.setUserName("scott");
    db.setPassword("tiger");

    // 连接数据库
    if(db.open())
    {
        qDebug() << "数据库连接成功";
        // 数据库查询
        QSqlQuery q;
        QString sql = "select * from dept";
        bool bl = q.exec(sql);
        if(!bl)
        {
            qDebug() << "查询失败";
        }
        else
        {
            // 遍历结果
            while(q.next())
            {
                // 取出当前记录中的字段
                qDebug() << "no:" << q.value("deptno").toInt()
                         <<"name: " << q.value("dname").toString()
                         <<"location: " << q.value("loc").toString();
            }
        }
        // 插入数据
        sql = "insert into dept values(55, '艾斯', '东京')";

        QSqlDatabase db1 = QSqlDatabase::database();
        db1.transaction();
        bl = q.exec(sql);
        if(bl==false)
        {
            qDebug() << "插入失败";
            db1.rollback();
        }
        else
        {
            qDebug() << "插入数据成功";
            db1.commit();
        }

    }
    else
    {
        qDebug() << "数据库连接失败";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}
