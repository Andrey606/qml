#include "add_data_window.h"

#include <QQmlApplicationEngine>
#include <QtQml>

namespace gui
{
    AddDataWindow::AddDataWindow(QObject *parent) : QObject(parent)
    {
        m_engine = new QQmlApplicationEngine();


        const QUrl url(QStringLiteral("qrc:/main.qml"));
        m_engine->load(url);
    }

    AddDataWindow::~AddDataWindow()
    {
        delete m_engine;
    }
}

