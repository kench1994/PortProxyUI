#include "model.h"

Model::Model(QObject *parent)
    : QAbstractListModel(parent)
{
    for(auto i = 0; i < 4;i++)
    {
        QVariantList temp;
        temp.append("1");
        temp.append("2");
        temp.append("3");
        temp.append("4");
        vlist.push_back(temp);
    }
}

int Model::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    return vlist.size();
}

QHash<int,QByteArray> Model::roleNames() const
{
    QHash<int, QByteArray> roles;
    int column_number{0};
    for (int i{inPortRole}; i != ROLE_END; ++i, ++column_number) {
        roles.insert(i, this->columns[column_number]);
    }
    return roles;
}


QVariant Model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QVariantList temp = vlist.at(index.row());
    switch (role) {
        case inPortRole:
            return temp[0];
        case inIPvNRole:
            return temp[1];
        case outAddressRole:
            return temp[2];
        case outIPvNRole:
            return temp[3];
    }
    return QVariant();
}

bool Model::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return true;
}

bool Model::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return true;
}
