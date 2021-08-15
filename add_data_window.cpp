#include "add_data_window.h"
#include <QQmlApplicationEngine>
#include <QtQml>
#include "tilemodel.h"
#include "tileList.h"

namespace gui
{
    AddDataWindow::AddDataWindow(QObject *parent) : QObject(parent)
    {
        qmlRegisterType<TileModel>("Tile", 1, 0, "TileModel");
        qmlRegisterUncreatableType<TileList>("Tile", 1, 0, "TileList",
            QStringLiteral("TileList should not be created in QML"));

        tileList = new TileList();

        m_engine = new QQmlApplicationEngine();
        m_engine->rootContext()->setContextProperty(QStringLiteral("tileList"), tileList);

        const QUrl url(QStringLiteral("qrc:/main.qml"));
        m_engine->load(url);
    }

    AddDataWindow::~AddDataWindow()
    {
        delete tileList;
        delete m_engine;
    }
}

