#pragma once

#include <QAbstractListModel>

class TileList;

class TileModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(TileList *list READ list WRITE setList)

public:
    explicit TileModel(QObject *parent = nullptr);

    enum {
        PictureRole = Qt::UserRole,
        IconRole,
        TitleRole,
        DescriptionRole,
        LinkRole
    };

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    TileList *list() const;
    void setList(TileList *list);

private:
    TileList *mList;
};
