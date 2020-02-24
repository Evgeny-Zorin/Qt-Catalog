#include "firmlistmodel.h"



FirmListModel::FirmListModel(QObject *parent):QAbstractListModel(parent)
{
    //QObject *parent = 0;
}

int FirmListModel::rowCount(const QModelIndex &parent) const
{
    //return model_firm->count();
    return 0;
}

QVariant FirmListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        //return QVariant();
    if(role==Qt::DisplayRole){
        //return ;
    }
        //else return QVariant();
    return QVariant();

}

void FirmListModel::sort(int column, Qt::SortOrder order)
{
}
