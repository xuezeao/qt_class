#ifndef ROTATEDPROXYMODEL_H
#define ROTATEDPROXYMODEL_H

#include <QAbstractProxyModel>

class RotatedProxyModel : public QAbstractProxyModel
{
public:
    RotatedProxyModel(QObject *p = 0);
    QModelIndex mapFromSource ( const QModelIndex & sourceIndex ) const
    {
        return index(sourceIndex.column(), sourceIndex.row());
    }
    QModelIndex mapToSource ( const QModelIndex & proxyIndex ) const
    {
        return sourceModel()->index(proxyIndex.column(), proxyIndex.row());
    }
    QModelIndex index(int r, int c, const QModelIndex &ind=QModelIndex()) const
    {
        ind;
        return createIndex(r,c);
    }
    QModelIndex parent(const QModelIndex&) const
    {
        return QModelIndex();
    }
    int rowCount(const QModelIndex &) const
    {
        return sourceModel()->columnCount();
    }
    int columnCount(const QModelIndex &) const
    {
        return sourceModel()->rowCount();
    }
    QVariant data(const QModelIndex &ind, int role) const
    {
        return sourceModel()->data(mapToSource(ind), role);
    }
    QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const
    {
        if( orientation == Qt::Horizontal )
            return sourceModel()->headerData( section, Qt::Vertical, role );
        else
            return sourceModel()->headerData( section, Qt::Horizontal, role );
    }

    bool setHeaderData( int section, Qt::Orientation orientation, const QVariant & value, int role = Qt::DisplayRole )
    {
        if( orientation == Qt::Horizontal )
            return sourceModel()->setHeaderData( section, Qt::Vertical, value, role );
        else
            return sourceModel()->setHeaderData( section, Qt::Horizontal, value, role );
    }
};

#endif // ROTATEDPROXYMODEL_H
