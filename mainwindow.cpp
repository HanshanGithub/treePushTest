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
    item1->setIcon(0, QIcon("E:/_Files/kFiles/sec.png"));

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
    rootItem->setText(0, "Excitation numerical analysis");//中文乱码，目前是编码问题
    rootItem->setIcon(0, QIcon("E:/_Files/kFiles/fir.png"));
}

void MainWindow::on_treeWidget_itemSelectionChanged()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    ui->textBrowser->append(item->text(0)+" click once");
}



void MainWindow::on_showKfileBtn_clicked() // showKfileBtn控件名字
{
    QString fileName = QFileDialog::getOpenFileName(// 正常加载
                    this, "open k file",
                    ".",
                    "k files (*.k);;All files (*.*)");
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QTextStream in(&file);
	while (!in.atEnd()) {
		QByteArray line = file.readLine();
		QString str(line);
		str.remove("\n");
		if (str.at(0) == '*')
			addKitem(str.mid(1));
		ui->textBrowser->append(str);
	}
	file.close();
}

void MainWindow::addKitem(QString item)
{
	// 添加子项
	QTreeWidgetItem *item1 = new QTreeWidgetItem(rootItem);
	item1->setText(0, item);
	item1->setIcon(0, QIcon("E:/_Files/kFiles/sec.png"));

	// 展开根节点
	ui->treeWidget->expandItem(rootItem);

	// 显示树形视图
	ui->treeWidget->show();
}
