#include "addnetsite.h"
#include "ui_addnetsite.h"
#include <time.h>
#include <QDebug>

AddNetSite::AddNetSite(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNetSite)
{
    ui->setupUi(this);
}

AddNetSite::~AddNetSite()
{
    delete ui;
}

void AddNetSite::on_okBtn_clicked()
{
    // 发送信号
    emit createNet(ui->number->text().toInt(), ui->name->text(), ui->description->text(),
                   ui->authCode->text().toInt(), ui->status->text().toInt());
    close();
}

void AddNetSite::on_cancleBtn_clicked()
{
    close();
}

void AddNetSite::on_createAuthCode_clicked()
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
