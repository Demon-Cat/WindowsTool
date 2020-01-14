#ifndef LABELFIND_H
#define LABELFIND_H

#include <QLabel>
#include <windows.h>

class LabelFind : public QLabel
{
    Q_OBJECT
public:
    explicit LabelFind(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseReleaseEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;

signals:
    void hwndChanged(HWND hwnd);

public slots:
};

#endif // LABELFIND_H
