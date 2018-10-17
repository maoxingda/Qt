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
    void setPixmap(QString imgPath);

private:
    QPixmap m_pixmap;

    // QWidget interface
protected:
    virtual void paintEvent(QPaintEvent *event) override;
};

#endif // CRCIMGWDG_H
