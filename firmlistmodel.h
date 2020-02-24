#ifndef FIRMLISTMODEL_H
#define FIRMLISTMODEL_H
#include <QAbstractListModel>
#include "firmclass.h"


class FirmListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FirmListModel(QObject *parent = 0);

public:
     QVector<Firm>* model_firm;

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void sort(int column, Qt::SortOrder order);
};

#endif // FIRMLISTMODEL_H
