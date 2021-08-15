#include "tilemodel.h"

#include "tileList.h"
#include <QDebug>

TileModel::TileModel(QObject *parent)
    : QAbstractListModel(parent)
    , mList(nullptr)
{
}

int TileModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;

    qDebug() << "size: " << mList->items().size();

    return mList->items().size();
}

QVariant TileModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const TileItem item = mList->items().at(index.row());
    switch (role) {
    case PictureRole:
        return QVariant(item.picture);
    case IconRole:
        return QVariant(item.icon);
    case TitleRole:
        return QVariant(item.title);
    case DescriptionRole:
        return QVariant(item.description);
    case LinkRole:
        return QVariant(item.link);
    }

    return QVariant();
}

bool TileModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList)
        return false;

    TileItem item = mList->items().at(index.row());
    switch (role) {
    case PictureRole:
        item.picture = value.toString();
        break;
    case IconRole:
        item.icon = value.toString();
        break;
    case TitleRole:
        item.title = value.toString();
        break;
    case DescriptionRole:
        item.description = value.toString();
        break;
    case LinkRole:
        item.link = value.toString();
        break;
    }

    if (mList->setItemAt(index.row(), item)) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags TileModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> TileModel::roleNames() const
{
    QHash<int, QByteArray> names;
    names[PictureRole] = "picture";
    names[IconRole] = "icon";
    names[TitleRole] = "title";
    names[DescriptionRole] = "description";
    names[LinkRole] = "link";
    return names;
}

TileList *TileModel::list() const
{
    return mList;
}

void TileModel::setList(TileList *list)
{
    qDebug() << "setList: " ;
    beginResetModel();

    if (mList)
        mList->disconnect(this);

    mList = list;

    if (mList) {
        connect(mList, &TileList::preItemAppended, this, [=]() {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(), index, index);
        });
        connect(mList, &TileList::postItemAppended, this, [=]() {
            endInsertRows();
        });

        connect(mList, &TileList::preItemRemoved, this, [=](int index) {
            beginRemoveRows(QModelIndex(), index, index);
        });
        connect(mList, &TileList::postItemRemoved, this, [=]() {
            endRemoveRows();
        });
    }

    endResetModel();
}
