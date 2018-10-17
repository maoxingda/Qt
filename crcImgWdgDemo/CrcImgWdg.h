#ifndef CRCIMGWDG_H
#define CRCIMGWDG_H

#include <QWidget>

class CrcImgWdg : public QWidget
{
    Q_OBJECT
public:
    explicit CrcImgWdg(QWidget *parent = nullptr);

signals:

public slots:

public:
    void setPixmap(QString imgPathOuter, QString imgPathInner, int radius = 3);

private:
    int m_nRadius;
    QPixmap m_pixmapOuter;
    QPixmap m_pixmapInner;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // CRCIMGWDG_H
