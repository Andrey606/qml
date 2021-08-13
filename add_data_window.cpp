#include "add_data_window.h"

#include <QQmlApplicationEngine>
#include <QtQml>
#include "tileloader.h"

namespace gui
{
    AddDataWindow::AddDataWindow(QObject *parent) : QObject(parent)
    {
        m_engine = new QQmlApplicationEngine();
        const QUrl url(QStringLiteral("qrc:/main.qml"));

        tileLoader _tileLoader;
        m_engine->rootContext()->setContextObject(&_tileLoader);

        m_engine->load(url);
    }

    AddDataWindow::~AddDataWindow()
    {
        delete m_engine;
    }
}

