#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "jsonparse.h"
#include "databaseop.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    // 初始化服务器配置信息
    void initServerCfgInfo();
    // 初始化网点信息
    void initNetInfo();
    // 刷新列表
    void refreshList(QString tableName, QString filter=QString());
    // 添加网点
    void addNetSite(int id, QString name, QString desp, int authCode, int status);

private slots:
    void on_dbArgSave_clicked();

    void on_createNet_clicked();

    void on_modifyNet_clicked();

    void on_deleteNet_clicked();

    void on_vagueSearch_clicked();

    void on_exactSearch_clicked();

private:
    Ui::MainWindow *ui;

    JsonParse m_json;
    DatabaseOP m_dbop;
};

#endif // MAINWINDOW_H
