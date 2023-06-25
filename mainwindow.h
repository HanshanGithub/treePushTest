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
    void on_addWidgetItem_clicked();
    void on_treeWidget_itemSelectionChanged();

    void on_showKfileBtn_clicked();

private:
    Ui::MainWindow *ui;
    // 添加根节点
    QTreeWidgetItem *rootItem;
    // 子节点编号
    int itemNum;

public:
    void initRootItem();
	void addKitem(QTreeWidgetItem* root,QString item);
};

#endif // MAINWINDOW_H
