#include "CrcImgWdg.h"

#include <QPaintEvent>
#include <QPainter>

CrcImgWdg::CrcImgWdg(QWidget *parent) : QWidget(parent)
{

}


void CrcImgWdg::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing);

    QPixmap pixmap(":/anchor2.jpg");

    QPainterPath path;

    QRect rcLabel = event->rect();

    path.addEllipse(rcLabel);

    painter.setClipPath(path);

    painter.drawPixmap(rcLabel, pixmap);
}
