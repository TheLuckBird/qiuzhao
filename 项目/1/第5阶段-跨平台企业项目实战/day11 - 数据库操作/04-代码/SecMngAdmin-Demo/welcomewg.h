#ifndef WELCOMEWG_H
#define WELCOMEWG_H

#include <QWidget>

class WelcomeWg : public QWidget
{
    Q_OBJECT
public:
    explicit WelcomeWg(QWidget *parent = nullptr);

protected:
    // 绘图
    void paintEvent(QPaintEvent *event);

signals:

public slots:
};

#endif // WELCOMEWG_H
