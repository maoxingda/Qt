#ifndef MVP_H
#define MVP_H

#include <QtGui/QWidget>
#include "ui_mvp.h"

class mvp : public QWidget
{
	Q_OBJECT

public:
	mvp(QWidget *parent = 0, Qt::WFlags flags = 0);
	~mvp();

private slots:
    void on_add_clicked();
    void on_del_clicked();
    void on_delAll_clicked();
    void on_modify_clicked();

private:
	Ui::mvpClass ui;
};

#endif // MVP_H
