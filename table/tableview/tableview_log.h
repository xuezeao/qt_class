#ifndef TABLEVIEW_LOG_H
#define TABLEVIEW_LOG_H

#include <QSqlTableModel>
#include <QTableView>

class TableView_Log
{
public:
    TableView_Log();
    void TableConfig(QTableView *goal_table, QString tableName);
    void ShowAppointLogInfo(int id);
private:
    QSqlTableModel *goal_SQL;

    void ShowGoalInfo(QString tableName);

};

#endif // TABLEVIEW_LOG_H
