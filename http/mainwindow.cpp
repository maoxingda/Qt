#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QNetworkReply>
#include <QThread>
#include <json/reader.h>
#include <json/value.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser->setWordWrapMode(QTextOption::NoWrap);
    ui->lineEditUrl->setText("http://base.api.qxiu.com/cgi/attention/like?anchorId=%I64d&userId=%I64d&openid=%s&openkey=%s&uid=%I64d&mcheck=%s&accessToken=%s&roomId=%I64d");
    showMaximized();
    connect(&m_NAMgr, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *aReply)
{
    if (QNetworkReply::NoError == aReply->error())
    {
        QByteArray bytes = aReply->readAll();
        Json::Value root;
        Json::Reader reader;
        if (reader.parse(bytes.data(), root, false))
        {
            QString strUtf16 = QString::fromUtf8(root.toStyledString().c_str());
            ui->textBrowser->setText(strUtf16);
        }
    }

    aReply->deleteLater();
}

void MainWindow::on_pushButtonGet_clicked()
{
    m_NAMgr.get(QNetworkRequest(QUrl(ui->lineEditUrl->text())));
}

void MainWindow::on_pushButtonClr_clicked()
{
    ui->textBrowser->clear();
}
