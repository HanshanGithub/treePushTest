#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    itemNum = 0 ;
    initRootItem();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addWidgetItem_clicked()
{


    // 添加子项
    QTreeWidgetItem *item1 = new QTreeWidgetItem(rootItem);
    item1->setText(0, "Item "+QString::number(++itemNum));
    item1->setIcon(0, QIcon("E:/_Files/sec.png"));

    // 展开根节点
    ui->treeWidget->expandItem(rootItem);

    // 显示树形视图
    ui->treeWidget->show();
}

void MainWindow::initRootItem()
{
    // 隐藏根节点项前的图标（展开折叠图标）
    ui->treeWidget->setRootIsDecorated(false);
    // 设置树形视图的列数
    ui->treeWidget->setColumnCount(1);

    // 隐藏列号
    ui->treeWidget->header()->setVisible(false);

    rootItem = new QTreeWidgetItem(ui->treeWidget);
    rootItem->setText(0, "Root Item");
    rootItem->setIcon(0, QIcon("E:/_Files/fir.png"));
}
