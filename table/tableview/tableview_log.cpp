#include "tableview_log.h"
#include <QSqlTableModel>
#include <QHeaderView>

TableView_Log::TableView_Log()
{
    goal_SQL = new QSqlTableModel;
}

void TableView_Log::ShowGoalInfo(QString tableName)
{
    goal_SQL->setTable(QString("%1").arg(tableName));
    goal_SQL->select();

    goal_SQL->setHeaderData(0, Qt::Horizontal, QObject::tr("编号"));
    goal_SQL->setHeaderData(3, Qt::Horizontal, QObject::tr("日期"));
    goal_SQL->setHeaderData(4, Qt::Horizontal, QObject::tr("记录"));
}

void TableView_Log::TableConfig(QTableView *goal_table,\
                                QString tableName)
{
    ShowGoalInfo(tableName);

    goal_table->setModel(goal_SQL);
    goal_table->setColumnHidden(1, true);
    goal_table->setColumnHidden(2, true);

    goal_table->setSelectionMode(QAbstractItemView::NoSelection);
    goal_table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    goal_table->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    //隐藏格子线
    goal_table->setShowGrid(false);
    //隐藏行头
    goal_table->verticalHeader()->setHidden(true);
    //无边框
    goal_table->setFrameShape(QFrame::NoFrame);
    //最后一行延伸
    goal_table->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);

}

void TableView_Log::ShowAppointLogInfo(int id)
{
    //筛选信息
    goal_SQL->setFilter(QString("id_agentia like %1").arg(id));//筛选结果
}
