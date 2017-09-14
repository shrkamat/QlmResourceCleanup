#include <QGuiApplication>
#include <QQuickView>
#include <QObject>
#include <QDebug>

class VDestroyer : public QObject
{
    Q_OBJECT
public:
    explicit VDestroyer(QQuickView *view, QObject *parent = 0) :
        QObject(parent), m_view(view)
    {
        // destroy m_view in 3 secs
        timerId = startTimer(5 * 1000);
    }

protected:
    void timerEvent(QTimerEvent * event)
    {
        if (event->timerId() == timerId) {
            m_view->deleteLater();
        }
    }

private :
    QQuickView *m_view;
    int timerId;
};

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    app.setQuitOnLastWindowClosed(false);

    QQuickView *view = new QQuickView;
    view->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
    view->show();

    VDestroyer *vDestroyer = new VDestroyer(view);

    int rc = app.exec();

    qDebug() << "exiting from application!!";

    delete vDestroyer;
    return rc;
}

#include "main.moc"
