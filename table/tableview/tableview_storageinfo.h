#ifndef TABLEVIEW_STORAGEINFO_H
#define TABLEVIEW_STORAGEINFO_H

#include <QSqlRelationalTableModel>
#include <QTableView>
class TableView_StorageInfo : public QSqlRelationalTableModel
{
public:
    TableView_StorageInfo();
    //显示制定目标的试剂信息
    void ShowGoalInfo(QTableView *goal_table, \
                      QString tableName, \
                      int needIndexColunm, \
                      QString indexTableName, \
                      QString indexColumnName, \
                      QString indexShowInfoColumnName);

    //筛选数据
    void ShowAppointLogInfo(int id);

private:
    QSqlRelationalTableModel *goal_SQL;

    //配置表格设置
    void SetTableViewConfig(QTableView *goal_table);
    void SetShowHorizonalName();

};

#endif // TABLEVIEW_STORAGEINFO_H
