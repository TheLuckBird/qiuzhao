#include "mainwindow.h"
#include <QApplication>
#include "jsonparse.h"
#include "databaseop.h"
#include "dbinfoset.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    JsonParse json;
    DatabaseOP db;
    bool bl = db.openDatabase(json.getHostName(), json.getDBName(),
                              json.getUserName(), json.getPassWd(), json.getDBPort());
    if(bl == false)
    {
        DBInfoSet infowg;
        int ret = infowg.exec();
        if(ret == QDialog::Rejected)
        {
            return 0;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
}
