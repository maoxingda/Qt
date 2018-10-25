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
    ui->lineEditUrl->setText("http://127.0.0.1:18580/happyPk/match/anchorRank");
    showMaximized();
    connect(m_pNAMgr, SIGNAL(finished(QNetworkReply*)), SLOT(replyFinished(QNetworkReply*)));
    ui->comboBoxUrl->addItem("http://127.0.0.1:18580/happyPk/match/anchorRank?anchorId=367566&roomId=200066");
    ui->comboBoxUrl->addItem("http://127.0.0.1:18580/happyPk/match/anchorRank?anchorId=445216&roomId=223666");
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
//        ui->textBrowser->setText(QString::fromUtf8(bytes));
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
//    QUrlQuery query;
//    query.addQueryItem("anchorId", "367566");
//    query.addQueryItem("roomId", "225088");
    QUrl url(ui->lineEditUrl->text());
//    url.setQuery(query);
    m_pNAMgr->get(QNetworkRequest(url));
}

void MainWindow::on_pushButtonClr_clicked()
{
    ui->textBrowser->clear();
}

void MainWindow::on_pushButtonCls_clicked()
{
    close();
}

void MainWindow::on_comboBoxUrl_currentTextChanged(const QString &arg1)
{
    ui->lineEditUrl->setText(arg1);
}
