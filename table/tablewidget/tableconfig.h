#ifndef TABLECONFIG_H
#define TABLECONFIG_H

#include <QTableWidget>
#include <QTableWidgetItem>
#define TEST

class TableConfig
{
public:
    explicit TableConfig();
    ~TableConfig();

    void SetTableRowAndColumn(QTableWidget *goal, int row, int column);
    void ShowData2Table(QTableWidget *goal, QString tableName, int drawerNo, int setPointSize);


signals:

public slots:

private:
    enum{useful, useless};

    QTableWidgetItem* SetCellStyle(QString color, QString text, int setPointSize);
    void SetTableConfig(QTableWidget *goal);

};

#endif // TABLECONFIG_H
