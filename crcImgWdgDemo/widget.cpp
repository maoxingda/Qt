#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->widgetCrcImg->setPixmap(":/anchor1.jpg", ":/anchor2.jpg");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButtonDec_clicked()
{
    QRect rcWdg = ui->widgetCrcImg->rect();

    ui->widgetCrcImg->setFixedSize(rcWdg.width() - 5, rcWdg.height() - 5);
}

void Widget::on_pushButtonAdd_clicked()
{
    QRect rcWdg = ui->widgetCrcImg->rect();

    ui->widgetCrcImg->setFixedSize(rcWdg.width() + 5, rcWdg.height() + 5);
}
