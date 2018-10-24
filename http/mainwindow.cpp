#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QNetworkReply>
#include <QThread>
#include <QUrlQuery>
#include <json/reader.h>
#include <json/value.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pNAMgr = new QNetworkAccessManager(this);
    ui->textBrowser->setWordWrapMode(QTextOption::NoWrap);
    ui->lineEditUrl->setText("http://hot.active.qxiu.com/happyPk/match/anchorRank");
    showMaximized();
    connect(m_pNAMgr, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
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
    QUrlQuery query;
    query.addQueryItem("anchorId", "439851");
    query.addQueryItem("roomId", "225088");
    m_pNAMgr->get(QNetworkRequest(QUrl(ui->lineEditUrl->text() + "?" + query.toString())));
}

void MainWindow::on_pushButtonClr_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::on_pushButtonCls_clicked()
{
    close();
}
