#include "tileList.h"
#include <QDebug>

TileList::TileList(QObject *parent) : QObject(parent)
{
    mItems.append({ "file:///home/andrew/Documents/qml/Imagery.png",
                  "file:///home/andrew/Documents/qml/gear-50.png",
                  "Bundesländergrenzen 2018",
                  "Owner: \nItem Type: \nCreated: \nModified: \nViews: \nTags: \nCredits: ",
                  "http://www.arcgis.com/home/item.html?id=d3a78deedc0749eeb3ed9069773d5551/"});

    mItems.append({ "",
                  "",
                  "123",
                  "",
                  ""});

    mItems.append({ "",
                  "",
                  "245",
                  "",
                  ""});

    mItems.append({ "",
                  "",
                  "",
                  "",
                  ""});

    mItems.append({ "",
                  "",
                  "",
                  "",
                  ""});

    mItems.append({ "",
                  "",
                  "",
                  "",
                  ""});
}

QVector<TileItem> TileList::items() const
{
    qDebug() << "items";
    return mItems;
}

bool TileList::setItemAt(int index, const TileItem &item)
{
    qDebug() << "setItemAt";
    if (index < 0 || index >= mItems.size())
        return false;

    mItems[index] = item;
    return true;
}

/*
void TileList::appendItem()
{
    qDebug() << "appendItem";
    emit preItemAppended();
    TileItem item;
    mItems.append(item);
    emit postItemAppended();
}

void TileList::removeCompletedItems()
{
    qDebug() << "removeCompletedItems";
    for (int i = 0; i < mItems.size(); ) {
        emit preItemRemoved(i);

        mItems.removeAt(i);

        emit postItemRemoved();
    }
}
*/
