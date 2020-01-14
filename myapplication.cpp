#include "myapplication.h"
#include <QMouseEvent>
#include <QtDebug>

MyApplication::MyApplication(int &argc, char **argv) :
    QApplication(argc, argv)
{

}

bool MyApplication::notify(QObject *receive, QEvent *e)
{
//    if (e->type() == QEvent::MouseMove)
//    {
//        QMouseEvent *event = static_cast<QMouseEvent *>(e);
//        qDebug() << receive << event->globalPos();
//    }

    return QApplication::notify(receive, e);
}
