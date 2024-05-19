#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QTableWidgetItem>
#include "addnetsite.h"
#include <QDateTime>
#include "modifynetsite.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->setCurrentWidget(ui->welcome);
    connect(ui->serverSet, &QToolButton::clicked, [=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->serverArgSet);
    });
    connect(ui->netMng, &QToolButton::clicked, [=]()
    {
        ui->stackedWidget->setCurrentWidget(ui->netMng_page);
    });

    initServerCfgInfo();
    initNetInfo();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initServerCfgInfo()
{
    // 初始数据库连接信息
    ui->dbHostName->setText(m_json.getHostName());
    ui->dbName->setText(m_json.getDBName());
    ui->dbPort->setText(QString::number(m_json.getDBPort()));
    ui->dbUser->setText(m_json.getUserName());
    ui->dbPasswd->setText(m_json.getPassWd());

    qDebug() << m_json.getHostName()
             << m_json.getDBName()
             << m_json.getDBPort()
             << m_json.getUserName()
             << m_json.getPassWd();

    // 初始化
    QVector<QVariantList> list = m_dbop.selectDatabase("srvcfg");
    if(list.empty())
    {
        return;
    }
    ui->serverIP->setText(list.at(0).at(0).toString());
    ui->serverPort->setText(list.at(0).at(1).toString());
}

// 初始化网点信息
void MainWindow::initNetInfo()
{
    // 列表初始化
    QStringList labels;
    labels << "网点编号" << "网点名称" << "网点创建时间" << "网点授权码" << "网点状态" ;
    // 先设置列数
    ui->tableWidget->setColumnCount(labels.size());
    ui->tableWidget->setHorizontalHeaderLabels(labels);

    // 设置列表属性
    // 选择行为, 单击选一行
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 只能选一行
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // 不允许编辑
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 隔行变颜色
    ui->tableWidget->setAlternatingRowColors(true);
    // 单元格填满整个窗口
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 读数据 - secnode
    refreshList("secnode");

    ui->dateEnd->setDateTime(QDateTime::currentDateTime());
}

void MainWindow::refreshList(QString tableName, QString filter)
{
    QVector<QVariantList> list = m_dbop.selectDatabase(tableName, filter);
    // 清空列表
    ui->tableWidget->clearContents();
    ui->tableWidget->setRowCount(list.size());
    for(int i=0; i<list.size(); ++i)
    {
        QVariantList sub = list.at(i);
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(sub.at(0).toString()));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(sub.at(1).toString()));
        QString time = sub.at(3).toDateTime().toString("yyyy-MM-dd hh:mm:ss");
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(time));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number(sub.at(4).toInt())));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(sub.at(5).toInt())));
    }
}

void MainWindow::addNetSite(int id, QString name, QString desp, int authCode, int status)
{
    QString curTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
    // 数据更新到数据库
    QStringList fields;
    QVariantList values;
    fields << "id" << "name" << "nodedesc" << "createtime" << "authcode" << "state";
    values << id << name << desp << QDateTime::currentDateTime() << authCode << status;
    bool bl = m_dbop.insertDB("secnode", fields, values);
    if(bl == false)
    {
        return;
    }
    // 获取当前的列表行数
    int rows = ui->tableWidget->rowCount();
    // 在末尾添加一行
    ui->tableWidget->insertRow(rows);
    // 初始化内容
    ui->tableWidget->setItem(rows, 0, new QTableWidgetItem(QString::number(id)));
    ui->tableWidget->setItem(rows, 1, new QTableWidgetItem(name));
    ui->tableWidget->setItem(rows, 2, new QTableWidgetItem(curTime));
    ui->tableWidget->setItem(rows, 3, new QTableWidgetItem(QString::number(authCode)));
    ui->tableWidget->setItem(rows, 4, new QTableWidgetItem(QString::number(status)));
}

void MainWindow::on_dbArgSave_clicked()
{
    QString dbHostName = ui->dbHostName->text();
    QString dbName = ui->dbName->text();
    QString dbPort = ui->dbPort->text();
    QString dbUser = ui->dbUser->text();
    QString dbPasswd = ui->dbPasswd->text();

    bool bl = m_json.writeJson(dbHostName, dbName, dbPort, dbUser, dbPasswd);
    if(bl)
    {
        QMessageBox::information(this, "OK", "数据保存成功!!!");
    }
    else
    {
        QMessageBox::critical(this, "Error", "数据保存失败!!!");
    }
}

// 创建网点
void MainWindow::on_createNet_clicked()
{
    AddNetSite netSite;
    // 信号槽连接
    connect(&netSite, &AddNetSite::createNet, this, &MainWindow::addNetSite);
    // 模态显示
    netSite.exec();
}

// 修改网点
void MainWindow::on_modifyNet_clicked()
{
    // 获取选择的当前行信息
    int curRow = ui->tableWidget->currentRow();
    if(curRow < 0)
    {
        QMessageBox::warning(this, "Waring", "您没有选中任何行, 请选择!");
        return;
    }
    QString number = ui->tableWidget->item(curRow, 0)->text();
    ModifyNetSite netsite(number);
    netsite.exec();
    refreshList("secnode");
}

// 删除网点
void MainWindow::on_deleteNet_clicked()
{
    // 获取选择的当前行信息
    int curRow = ui->tableWidget->currentRow();
    if(curRow < 0)
    {
        QMessageBox::warning(this, "Waring", "您没有选中任何行, 请选择!");
        return;
    }
    QString number = ui->tableWidget->item(curRow, 0)->text();
    QString name = ui->tableWidget->item(curRow, 1)->text();
    QString info = QString("您确定要删除该网点吗? \n\t编号: %1\n\t 网点名称: %2\n")
            .arg(number).arg(name);
    int ret = QMessageBox::question(this, "Question", info);
    if(ret == QMessageBox::Yes)
    {
        // 删除
        bool bl = m_dbop.deleteDB("secnode", "id='" + number + "'");
        if(bl)
        {
            QMessageBox::information(this, "Sucess", "删除成功");
            // 删除当前行
            ui->tableWidget->removeRow(curRow);
        }
        else
        {
            QMessageBox::information(this, "Fail", "删除失败");
        }
    }
}

// 模糊查询
void MainWindow::on_vagueSearch_clicked()
{
    QString format = "yyyy-mm-dd hh24:mi:ss";
    QString start = ui->dateStart->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString end = ui->dateEnd->dateTime().toString("yyyy-MM-dd hh:mm:ss");
    QString sql = QString("createtime between to_date('%1', '%3') and to_date('%2', '%3')")
            .arg(start).arg(end).arg(format);
    refreshList("secnode", sql);
}

// 精确查询
void MainWindow::on_exactSearch_clicked()
{
    QString sql;
    QString name = ui->netInfo->text();
    QString number = ui->netID->text();

    if(!name.isEmpty() && !number.isEmpty())
    {
        sql += QString("name = '%1' and id = %2").arg(name).arg(number);
        qDebug() << "+++++++++" << sql;
    }
    else
    {
        QString title = name.isEmpty() ? "id" : "name";
        QString str = name.isEmpty() ? number : name;
        sql += QString("%1 = '%2'").arg(title).arg(str);
    }
    refreshList("secnode", sql);
}
