#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <add_data_window.h>


int test()
{
    QCoreApplication *app = QCoreApplication::instance();
    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    engine.load(url);

    return QCoreApplication::exec();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    static gui::AddDataWindow inst;

    return app.exec();
}
