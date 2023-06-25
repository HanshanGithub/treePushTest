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
    // 删除QTreeWidget中所有节点

}

// 已弃用
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

    rootMap = new QMap<QString, QMap<QString, QString>>();
}

void MainWindow::on_treeWidget_itemSelectionChanged()
{
    QTreeWidgetItem *item = ui->treeWidget->currentItem();
    // item文本:item->text(0）
    // item的属性值:用Json保存？
    ui->textBrowser->append(item->text(0)+" click once");
}


// 已弃用
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

// 添加子项
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

void MainWindow::on_actionOpen_triggered()
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
    QString kItem; // 上一个选项卡名字
    while (!in.atEnd()) {
        QByteArray line = file.readLine();
        QString str(line);
        str.remove("\n");
        ui->textBrowser->append(str);
        // 判断选项卡
        if (str.at(0) == '*') {
            // 如果是则跳过
            if (str == "*NODE" || str == "*ELEMENT_SOLID" || str == "*KEYWORD" || str == "*PARAMETER_DUPLICATION")
                continue;
            addKitem(kfileitem, str.mid(1));
            kItem = str;
        }
        // 添加选项卡属性值
        else if (str.at(0) == '$') {
            
            QStringList key = str.split(" "); // 下标1开始，最后一个为unused要丢弃
            int len = key.length();
            ui->textBrowser->append("str.split lenth is " + QString::number(len));

            //line = file.readLine(); // 属性的值 下标0开始
            
        }
    }

    ui->treeWidget->expandAll();
    file.close();
}



// 递归删除节点
void MainWindow::removeItem(QTreeWidgetItem* item)
{
    int count = item->childCount();
    if (count == 0)//没有子节点，直接删除
    {
        delete item;
        return;
    }

    for (int i = 0; i < count; i++)
    {
        QTreeWidgetItem* childItem = item->child(0);//删除子节点
        removeItem(childItem);
    }
    delete item;//最后将自己删除

}

void MainWindow::removeAll_treeWidgetItemv(void)
{
    //通过删除根节点及其子节点来达到删除整个TreeWidget的目的
    QTreeWidgetItem* item;
    item = ui->treeWidget->topLevelItem(0);
    while (item)
    {
        removeItem(item);
        item = ui->treeWidget->topLevelItem(0);
    }
}
