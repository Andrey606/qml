#ifndef TILELOADER_H
#define TILELOADER_H

#include <QObject>
#include <tile.h>

class tileLoader : public QObject
{
    Q_OBJECT
public:
    explicit tileLoader(QObject *parent = nullptr);

    void uploadTiles(int count);

signals:

private:
    QVector<tile> _tiles;

};

#endif // TILELOADER_H
