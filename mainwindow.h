#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onHwndChanged(HWND hwnd);

    void on_pushButton_setText_clicked();

private:
    Ui::MainWindow *ui;

    HWND m_hwnd = nullptr;
};
#endif // MAINWINDOW_H
