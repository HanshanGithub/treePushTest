#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addWidgetItem_clicked()
{
    // 设置树形视图的列数
    ui->treeWidget->setColumnCount(1);

    // 隐藏列号
    ui->treeWidget->header()->setVisible(false);

    // 添加根节点
    QTreeWidgetItem *rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, "Root Item");
    rootItem->setIcon(0, QIcon("E:/_Files/fir.png"));

    // 添加子项
    QTreeWidgetItem *item1 = new QTreeWidgetItem(rootItem);
    item1->setText(0, "Item 1");
    item1->setIcon(0, QIcon("E:/_Files/sec.png"));

    QTreeWidgetItem *item2 = new QTreeWidgetItem(rootItem);
    item2->setText(0, "Item 2");
    item2->setIcon(0, QIcon("E:/_Files/sec.png"));

    // 展开根节点
    ui->treeWidget->expandItem(rootItem);

    // 显示树形视图
    ui->treeWidget->show();
}
