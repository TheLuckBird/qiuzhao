#include "modifynetsite.h"
#include "ui_modifynetsite.h"
#include <time.h>
#include <QDebug>
#include "databaseop.h"
#include <QMessageBox>

ModifyNetSite::ModifyNetSite(QString id, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ModifyNetSite)
{
    ui->setupUi(this);

    m_id = id;
    // 查数据库, 根据id
    DatabaseOP db;
    QVector<QVariantList> list = db.selectDatabase("secnode", "id=" + id);
    QVariantList sub = list.at(0);
    ui->number->setText(sub.at(0).toString());
    ui->name->setText(sub.at(1).toString());
    ui->description->setText(sub.at(2).toString());
    ui->authCode->setText(QString::number(sub.at(4).toInt()));
    ui->status->setText(QString::number(sub.at(5).toInt()));
}

ModifyNetSite::~ModifyNetSite()
{
    delete ui;
}

void ModifyNetSite::on_createAuthCode_clicked()
{
    // 生成六位随机数
    qsrand(time(NULL));
    QString str;
    for(int i=0; i<8; ++i)
    {
        str += QString::number(qrand() % 10);
    }
    qDebug() << "autoCode : " << str;
    ui->authCode->setText(str);
}

void ModifyNetSite::on_okBtn_clicked()
{
    QString id = ui->number->text();
    QString name = ui->name->text();
    QString description = ui->description->text();
    QString authCode = ui->authCode->text();
    QString status = ui->status->text();

    // 更新数据库
    DatabaseOP db;
    QStringList fields;
    QVariantList values;
    fields << "id" << "name" << "nodedesc" << "authcode" << "state";
    values << id << name << description << authCode.toInt() << status.toInt();
    bool bl = db.updateDB("secnode", fields, values, "id='" + m_id + "'");
    if(bl)
    {
        QMessageBox::information(this, "Update", "恭喜, 数据库更新成功!");
        close();
    }
    else
    {
        QMessageBox::critical(this, "Error", "遗憾, 数据库更新失败!");
    }
}

void ModifyNetSite::on_cancleBtn_clicked()
{
    close();
}
