#include "CrcImgWdg.h"

#include <QPaintEvent>
#include <QPainter>

CrcImgWdg::CrcImgWdg(QWidget *parent)
    : QWidget(parent)
    , m_nRadius(3)
{

}

void CrcImgWdg::setPixmap(QString imgPathOuter, QString imgPathInner, int radius/* = 3*/)
{
    Q_ASSERT(!imgPathOuter.isEmpty() && !imgPathInner.isEmpty() && 0 < radius);

    m_pixmapOuter.load(imgPathOuter);
    m_pixmapInner.load(imgPathInner);
}


void CrcImgWdg::paintEvent(QPaintEvent *event)
{
    Q_ASSERT(!m_pixmapOuter.isNull() || !m_pixmapInner.isNull());

    if (m_pixmapOuter.isNull() || m_pixmapInner.isNull())
    {
        QWidget::paintEvent(event);

        return;
    }

    QRect rcWdgOuter = event->rect();
    QRect rcWdgInner(rcWdgOuter.left() + m_nRadius, rcWdgOuter.top() + m_nRadius, rcWdgOuter.width() - 2 * m_nRadius, rcWdgOuter.height() - 2 * m_nRadius);

    {
        // Draw outer circle
        QPainter painter(this);

        painter.setRenderHints(QPainter::Antialiasing);

        QPainterPath path;

        path.addEllipse(rcWdgOuter);

        painter.setClipPath(path);

        painter.drawPixmap(rcWdgOuter, m_pixmapOuter);
    }

    {
        // Draw inner circle
        QPainter painter(this);

        painter.setRenderHints(QPainter::Antialiasing);

        QPainterPath path;

        path.addEllipse(rcWdgInner);

        painter.setClipPath(path);

        painter.drawPixmap(rcWdgInner, m_pixmapInner);
    }
}
