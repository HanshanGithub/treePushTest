#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QIcon>
#include <QtWidgets/QWidget>
#include <QFile>
#include <QTextBrowser>
#include <QDebug>
#include <QTextStream>
#include <QFileDialog>
#include <QStandardItemModel>
#include <QTableView>
#include <QHeaderView>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_treeWidget_itemSelectionChanged();
    void on_actionOpen_triggered();
    void OnlineTreeViewDoubleClick(QTreeWidgetItem*, int);

private:
    Ui::MainWindow *ui;
    // 添加根节点
    QTreeWidgetItem *rootItem;
    // 子节点编号
    int itemNum;
    // 2级结点的键值
    QMap<QString, QMap<QString, QString>*> *rootMap;


public:
    void initRootItem();
	void addKitem(QTreeWidgetItem* root,QString item);
    void removeItem(QTreeWidgetItem* item);
    void removeAll_treeWidgetItemv();
};

#endif // MAINWINDOW_H
