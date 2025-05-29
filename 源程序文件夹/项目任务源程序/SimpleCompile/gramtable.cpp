
#include "gramtable.h"

GramTable::GramTable(const QString &title, QWidget *parent)
    : QDialog(parent)
{
    this->setWindowTitle(title);
    this->resize(800, 600);

    tableWidget = new QTableWidget(this);
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableWidget->verticalHeader()->setVisible(false);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(tableWidget);
    this->setLayout(layout);
}

void GramTable::setTable(int rowCount, int columnCount, const QStringList &headers)
{
    tableWidget->setRowCount(rowCount);
    tableWidget->setColumnCount(columnCount);
    tableWidget->setHorizontalHeaderLabels(headers);

    tableWidget->setWordWrap(false);                              // 禁止自动换行，避免被省略
    tableWidget->horizontalHeader()->setStretchLastSection(false); // 不自动拉伸最后一列
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents); // 自动适应内容宽度
    tableWidget->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents); // 表格自适应调整
    tableWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel); // 平滑横向滚动
    tableWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);   // 平滑纵向滚动
    tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded); // 横向滚动条按需出现
    tableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);   // 纵向滚动条按需出现

}

QTableWidget *GramTable::getTableWidget()
{
    return tableWidget;
}
