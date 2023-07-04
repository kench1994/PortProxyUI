#ifndef MODEL_H
#define MODEL_H

#include <QAbstractListModel>

class Model : public QAbstractListModel
{
    Q_OBJECT

public:
    enum {
        inPortRole = Qt::UserRole + 1,
        inIPvNRole,
        outAddressRole,
        outIPvNRole,
        ROLE_END
    };

    explicit Model(QObject *parent = nullptr);

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Add data:
    bool insertRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    // Remove data:
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

    QHash<int,QByteArray> roleNames() const override;

private:
    QList<QVariantList> vlist;

    const QList<QByteArray> columns{"inPort", "inIPvN", "outAddress", "outIPvN"};


};

#endif // MODEL_H
