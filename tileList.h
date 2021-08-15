#pragma once

#include <QObject>
#include <QVector>

#include <QDebug>

class TileItem
{
public:

    QString picture;
    QString icon;
    QString title;
    QString description;
    QString link;

    void onClick()
    {
        qDebug() << title;
    }

};

class TileList : public QObject
{
    Q_OBJECT
public:
    explicit TileList(QObject *parent = nullptr);

    QVector<TileItem> items() const;

    bool setItemAt(int index, const TileItem &item);

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    //void appendItem();
    //void removeCompletedItems();

private:
    QVector<TileItem> mItems;
};
