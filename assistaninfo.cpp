include "assistaninfo.h"

assistaninfo::assistaninfo(QObject *parent)
    : QAbstractItemModel(parent)
{
}

QVariant assistaninfo::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

QModelIndex assistaninfo::index(int row, int column, const QModelIndex &parent) const
{
    // FIXME: Implement me!
}

QModelIndex assistaninfo::parent(const QModelIndex &index) const
{
    // FIXME: Implement me!
}

int assistaninfo::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

int assistaninfo::columnCount(const QModelIndex &parent) const
{
    if (!parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant assistaninfo::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
