#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void replyFinished(QNetworkReply* aReply);

    void on_pushButtonGet_clicked();

    void on_pushButtonClr_clicked();

    void on_pushButtonCls_clicked();

    void on_comboBoxUrl_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager* m_pNAMgr;
};

#endif // MAINWINDOW_H
