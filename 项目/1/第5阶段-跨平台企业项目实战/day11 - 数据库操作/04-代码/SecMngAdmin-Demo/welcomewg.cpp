#include "welcomewg.h"
#include <QPainter>

WelcomeWg::WelcomeWg(QWidget *parent) : QWidget(parent)
{

}

void WelcomeWg::paintEvent(QPaintEvent *event)
{
    QPainter p(this);
    // 背景图
    p.drawPixmap(0, 0, width(), height(), QPixmap(":/images/background.bmp"));
    QString text = "欢迎使用SecMngServer管理终端";
    QFont font("华文行楷", 32, QFont::Bold, false);
    p.setFont(font);
    p.save();
    QPen pen(QColor(137, 137, 137));
    p.setPen(pen);
    p.drawText(10, (height()-100)/2, width(), 100, Qt::AlignCenter, text);
    p.restore();
    p.drawText(0, (height()-100)/2-10, width(), 100, Qt::AlignCenter, text);
}
