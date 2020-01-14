#include "labelfind.h"
#include <QMouseEvent>
#include <QApplication>
#include <QtDebug>

LabelFind::LabelFind(QWidget *parent) :
    QLabel(parent)
{

}

void LabelFind::mousePressEvent(QMouseEvent *ev)
{
    static QPixmap labelPixmap("://images/window.png");
    static QPixmap cursorPixmap = QPixmap("://images/target.png").scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation);

    setPixmap(labelPixmap);
    qApp->setOverrideCursor(QCursor(cursorPixmap));

    QLabel::mousePressEvent(ev);
}

void LabelFind::mouseReleaseEvent(QMouseEvent *ev)
{
    static QPixmap labelPixmap("://images/window_normal.png");

    setPixmap(labelPixmap);
    qApp->restoreOverrideCursor();

    QLabel::mouseReleaseEvent(ev);
}

void LabelFind::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint p = ev->globalPos();

    POINT point;
    point.x = p.x();
    point.y = p.y();
    HWND hwnd = WindowFromPoint(point);
    emit hwndChanged(hwnd);

    QLabel::mouseMoveEvent(ev);
}
