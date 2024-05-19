#ifndef DBINFOSET_H
#define DBINFOSET_H

#include <QDialog>

namespace Ui {
class DBInfoSet;
}

class DBInfoSet : public QDialog
{
    Q_OBJECT

public:
    explicit DBInfoSet(QWidget *parent = 0);
    ~DBInfoSet();

private slots:
    void on_dbTest_clicked();

    void on_dbConnect_clicked();

    void on_cancle_clicked();

private:
    Ui::DBInfoSet *ui;
};

#endif // DBINFOSET_H
