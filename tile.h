#ifndef TILE_H
#define TILE_H

#include <QObject>

class tile : public QObject
{
    Q_OBJECT
public:
    explicit tile(QObject *parent = nullptr);



signals:

private:
    QString picture;
    QString icon;
    QString title;
    QString description;
};

#endif // TILE_H
