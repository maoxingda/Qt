#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QFile>
#include <QNetworkReply>
#include <QThread>
//#include <QUrlQuery>
#include <json/reader.h>
#include <json/value.h>
#include <QDebug>

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
    ui->comboBoxUrl->addItem("http://127.0.0.1:18580/branch_combine_portable_internerKT_remoteTrial_ASR.zip");
    ui->comboBoxUrl->addItem("http://127.0.0.1:18580/hero/rank/hero");
    ui->comboBoxUrl->addItem("http://hot.active.qxiu.com/happyPk/match/anchorRank?anchorId=448159&roomId=226033");
    ui->labelUrl->hide();
    ui->lineEditUrl->hide();
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
        ui->textBrowser->setText(QString::fromUtf8(bytes));
//        Json::Value root;
//        Json::Reader reader;
//        if (reader.parse(bytes.data(), root, false))
//        {
//            QString strUtf16 = QString::fromUtf8(root.toStyledString().c_str());
//            ui->textBrowser->setText(strUtf16);
//        }
    }

    aReply->deleteLater();
}

void MainWindow::on_pushButtonGet_clicked()
{
//    QUrlQuery query;
//    query.addQueryItem("anchorId", "367566");
//    query.addQueryItem("roomId", "225088");
    QUrl url("http://download.qxiu.com/app100717093/autoupdate/0/1.22.86/autoupdate/config/commendline.dat");
//    url.setQuery(query);
    QNetworkReply* reply = m_pNAMgr->get(QNetworkRequest(url));
    connect(reply, &QNetworkReply::downloadProgress, this, &MainWindow::downloadProgress);
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

void MainWindow::downloadProgress(qint64 bytesReceived, qint64 bytesTotal)
{
    qDebug() << Q_FUNC_INFO << bytesReceived << "/" << bytesTotal;
}
