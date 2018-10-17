#include "CrcImgWdg.h"

#include <QPaintEvent>
#include <QPainter>

CrcImgWdg::CrcImgWdg(QWidget *parent)
    : QWidget(parent)
{

}

void CrcImgWdg::setPixmap(QString imgPath)
{
    Q_ASSERT(!imgPath.isEmpty());

    m_pixmap.load(imgPath);
}


void CrcImgWdg::paintEvent(QPaintEvent *event)
{
    Q_ASSERT(!m_pixmap.isNull());

    if (m_pixmap.isNull())
    {
        QWidget::paintEvent(event);
    }

    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing);

    QPainterPath path;

    QRect rcWdg = event->rect();

    path.addEllipse(rcWdg);

    painter.setClipPath(path);

    painter.drawPixmap(rcWdg, m_pixmap);
}
