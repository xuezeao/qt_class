#include <QHeaderView>

#include "tableview_storageinfo.h"
#include "rotatedproxymodel.h"


TableView_StorageInfo::TableView_StorageInfo()
{
    goal_SQL = new QSqlRelationalTableModel(this);
}

void TableView_StorageInfo::ShowGoalInfo(QTableView *goal_table, \
                                         QString tableName, \
                                         int needIndexColunm, \
                                         QString indexTableName, \
                                         QString indexColumnName, \
                                         QString indexShowInfoColumnName)
{
    goal_SQL->setTable(QString("%1").arg(tableName));
    goal_SQL->setRelation(needIndexColunm, QSqlRelation(QString("%1").arg(indexTableName),\
                                                        QString("%1").arg(indexColumnName),\
                                                        QString("%1").arg(indexShowInfoColumnName)));
    goal_SQL->select();

    SetShowHorizonalName();

    RotatedProxyModel *standardModel = new RotatedProxyModel(this);
    standardModel->setSourceModel(goal_SQL);
    goal_table->setModel(standardModel);
    SetTableViewConfig(goal_table);
}

void TableView_StorageInfo::SetTableViewConfig(QTableView *goal_table)
{
//    隐藏格子线
    goal_table->setShowGrid(false);

    //隐藏横向拖动条
    goal_table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //隐藏行头
    goal_table->horizontalHeader()->setHidden(true);
//    无边框
//    goal_table->setFrameShape(QFrame::NoFrame);
    goal_table->setRowHidden(0, true);//i_No
    goal_table->setRowHidden(3, true);//positionId

}

void TableView_StorageInfo::ShowAppointLogInfo(int id)
{
    goal_SQL->setFilter(QString("storageId like %1").arg(id));
}

void TableView_StorageInfo::SetShowHorizonalName()
{
    goal_SQL->setHeaderData(0, Qt::Horizontal, QObject::tr("序号"));
    goal_SQL->setHeaderData(1, Qt::Horizontal, QObject::tr("试剂名"));
    goal_SQL->setHeaderData(2, Qt::Horizontal, QObject::tr("试剂ID"));
    goal_SQL->setHeaderData(3, Qt::Horizontal, QObject::tr("位置ID"));
    goal_SQL->setHeaderData(4, Qt::Horizontal, QObject::tr("位置"));
    goal_SQL->setHeaderData(5, Qt::Horizontal, QObject::tr("剩余容积"));
    goal_SQL->setHeaderData(6, Qt::Horizontal, QObject::tr("入柜日期"));
    goal_SQL->setHeaderData(7, Qt::Horizontal, QObject::tr("失效日期"));
    goal_SQL->setHeaderData(8, Qt::Horizontal, QObject::tr("状态"));
}
