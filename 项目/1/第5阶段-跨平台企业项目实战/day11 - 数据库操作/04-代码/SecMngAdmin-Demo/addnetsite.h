#ifndef ADDNETSITE_H
#define ADDNETSITE_H

#include <QDialog>

namespace Ui {
class AddNetSite;
}

class AddNetSite : public QDialog
{
    Q_OBJECT

public:
    explicit AddNetSite(QWidget *parent = 0);
    ~AddNetSite();

signals:
 void createNet(int id, QString name, QString desp, int authCode, int status);

private slots:
    void on_okBtn_clicked();

    void on_cancleBtn_clicked();

    void on_createAuthCode_clicked();

private:
    Ui::AddNetSite *ui;
};

#endif // ADDNETSITE_H
