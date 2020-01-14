#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->label_find, &LabelFind::hwndChanged, this, &MainWindow::onHwndChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onHwndChanged(HWND hwnd)
{
    m_hwnd = hwnd;

    TCHAR windowText[128];
    GetWindowText(hwnd, windowText, sizeof(windowText));

    QString strHwnd = QString("0x%1").arg((qint64)hwnd, 0, 16);
    QString strText = QString::fromWCharArray(windowText);
    ui->lineEdit_hwnd->setText(strHwnd);
    ui->lineEdit_text->setText(strText);
}


void MainWindow::on_pushButton_setText_clicked()
{
    if (!m_hwnd)
    {
        QMessageBox::information(this, "提示", "无效句柄");
        return;
    }

    QString strText = ui->lineEdit_setText->text();
    if (strText.size() > 128)
    {
        QMessageBox::information(this, "提示", "长度不能超过128");
        return;
    }

    TCHAR windowText[128];
    wcscpy_s(reinterpret_cast<wchar_t*>(windowText), sizeof(windowText) / sizeof(wchar_t), reinterpret_cast<const wchar_t*>(strText.utf16()));
    SetWindowText(m_hwnd, windowText);
}
