#include "tableconfig.h"
#include <QHeaderView>
#include <QSqlQuery>
#include <QDebug>
#include <QFont>


TableConfig::TableConfig()
{
}

TableConfig::~TableConfig()
{

}

void TableConfig::SetTableConfig(QTableWidget *goal)
{
    //选中单元格
    goal->setSelectionBehavior(QAbstractItemView::SelectItems);
    //禁止编辑
    goal->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //单选
    goal->setSelectionMode(QAbstractItemView::SingleSelection);

    //关闭拖动条
    goal->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    goal->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //表格自适应窗口
    goal->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    goal->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //无边框
    goal->setFrameShape(QFrame::NoFrame);

}

void TableConfig::SetTableRowAndColumn(QTableWidget *goal, int row, int column)
{
    SetTableConfig(goal);
    goal->setColumnCount(column);
    goal->setRowCount(row);
}

void TableConfig::ShowData2Table(QTableWidget *goal, QString tableName, int drawerNo, int setPointSize)
{
    QSqlQuery query;
    int recordCount = 0;
    int rowNo = 0;
    int columnNo = 0;
    int storageStatus = 0;
    QString storageName = "";
    QTableWidgetItem *setCellItem = new QTableWidgetItem;

    query.exec(QString("SELECT * FROM %1 WHERE drawerNo=%2").arg(tableName).arg(drawerNo));
    query.last();
    recordCount = query.at() + 1;

    for (int i = 0; i < recordCount; i++)
    {
       query.seek(i);

       rowNo = query.value("rowNo").toInt();
       columnNo = query.value("columnNo").toInt();
       storageName = query.value("storageName").toString();
       storageStatus = query.value("status").toInt();

       if (useful == storageStatus)
       {
            storageName += "  在位";
            setCellItem = SetCellStyle("green", storageName, setPointSize);
       }
       else if (useless == storageStatus)
       {
            storageName += "  借出";
            setCellItem = SetCellStyle("yellow", storageName, setPointSize);
       }

       goal->setItem(rowNo-1, columnNo-1, setCellItem);


#ifdef TEST
        qDebug()<< query.value(0).toInt()<<" "<<query.value("rowNo").toInt()<<" "<<\
                   query.value("columnNo").toInt()<<" "<<query.value("storageName").toString()<<" "<<\
                   query.value(4).toInt();

#endif
    }

}

QTableWidgetItem* TableConfig::SetCellStyle(QString color, QString text, int setPointSize)
{
    QTableWidgetItem* cellItem = new QTableWidgetItem;
    QFont pointSize;

    pointSize.setPointSize(setPointSize);
    cellItem->setFont(pointSize);
    cellItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    if ("green" == color)
        cellItem->setBackgroundColor(Qt::green);
    else if ("yellow" == color)
        cellItem->setBackgroundColor(Qt::yellow);
    cellItem->setText(QString("%1").arg(text));

    return cellItem;
}

