#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QIcon>

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

private:
    Ui::MainWindow *ui;
    // 添加根节点
    QTreeWidgetItem *rootItem;
    // 子节点编号
    int itemNum;

public:
    void initRootItem();
};

#endif // MAINWINDOW_H
