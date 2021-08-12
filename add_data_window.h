#pragma once

#include <QObject>
#include <QVector>


class QQmlApplicationEngine;


namespace gui
{
class AddDataWindow : public QObject
{
    Q_OBJECT
public:
    explicit AddDataWindow(QObject *parent = nullptr);
    ~AddDataWindow();


private:
    QQmlApplicationEngine* m_engine;

signals:

};
}
