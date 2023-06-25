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
	// 一级结点
	//隐藏根节点项前的图标（展开折叠图标）
	ui->treeWidget->setRootIsDecorated(false);
	//如果只是隐藏根点的展开折叠图标而子节点保留，则只需要上面语句
	ui->treeWidget->setStyleSheet("QTreeView::branch:has-children:!has-siblings:closed,\
	QTreeView::branch:closed:has-children:has-siblings{border-image: none; image: none;}\
	QTreeView::branch:open:has-children:!has-siblings,\
	QTreeView::branch:open:has - children : has - siblings{ border - image: none; image: none; }");
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

	// 添加文件的2级结点
	QTreeWidgetItem *kfileitem = new QTreeWidgetItem(rootItem);
	kfileitem->setText(0, fileName.mid(fileName.lastIndexOf('/')+1));
	kfileitem->setIcon(0, QIcon("E:/_Files/kFiles/fir.png"));	

	QTextStream in(&file);
	while (!in.atEnd()) {
		QByteArray line = file.readLine();
		QString str(line);
		str.remove("\n");
		if (str.at(0) == '*')
			addKitem(kfileitem,str.mid(1));
		ui->textBrowser->append(str);
	}
	ui->treeWidget->expandAll();
	file.close();
}

void MainWindow::addKitem(QTreeWidgetItem* root, QString item)
{
	// 此处应为3级结点
	// 添加子项
	QTreeWidgetItem *item1 = new QTreeWidgetItem(root);
	item1->setText(0, item);
	item1->setIcon(0, QIcon("E:/_Files/kFiles/sec.png"));

	// 展开根节点
	ui->treeWidget->expandItem(rootItem);

	// 显示树形视图
	ui->treeWidget->show();
}
