#include "dbinfoset.h"
#include "ui_dbinfoset.h"
#include <QMessageBox>
#include "databaseop.h"
#include "jsonparse.h"

DBInfoSet::DBInfoSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DBInfoSet)
{
    ui->setupUi(this);

    this->setWindowTitle("设置服务器信息");

    ui->dbHostName->setText("192.168.247.166");
    ui->dbName->setText("orcl");
    ui->dbUser->setText("SECMNG");
    ui->dbPasswd->setText("SECMNG");
    ui->dbPort->setText("1521");
}

DBInfoSet::~DBInfoSet()
{
    delete ui;
}

// 测试连接
void DBInfoSet::on_dbTest_clicked()
{
    DatabaseOP op;
    bool bl = op.openDatabase(ui->dbHostName->text(), ui->dbName->text(), ui->dbUser->text(),
                              ui->dbPasswd->text(), ui->dbPort->text().toInt());
    if(bl)
    {
        QMessageBox::information(this, "Connect", "数据连接成功");
    }
    else
    {
        QMessageBox::critical(this, "Connect", "数据连接失败");
    }
}

// 连接
void DBInfoSet::on_dbConnect_clicked()
{
    on_dbTest_clicked();
    JsonParse json;
    json.writeJson(ui->dbHostName->text(), ui->dbName->text(), ui->dbPort->text(),
                   ui->dbUser->text(), ui->dbPasswd->text());
    accept();
}

// 关闭
void DBInfoSet::on_cancle_clicked()
{
    reject();
}
