#include "kviewer.h"
#include "ui_kviewer.h"

Kviewer::Kviewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Kviewer)
{
    ui->setupUi(this);
}

Kviewer::~Kviewer()
{
    delete ui;
}

