#ifndef MODIFYNETSITE_H
#define MODIFYNETSITE_H

#include <QDialog>

namespace Ui {
class ModifyNetSite;
}

class ModifyNetSite : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyNetSite(QString id, QWidget *parent = 0);
    ~ModifyNetSite();

private slots:
    void on_createAuthCode_clicked();

    void on_okBtn_clicked();

    void on_cancleBtn_clicked();

private:
    Ui::ModifyNetSite *ui;
    QString m_id;
};

#endif // MODIFYNETSITE_H
