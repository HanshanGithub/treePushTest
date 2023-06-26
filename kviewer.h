#ifndef KVIEWER_H
#define KVIEWER_H

#include <QDialog>

namespace Ui {
class Kviewer;
}

class Kviewer : public QDialog
{
    Q_OBJECT

public:
    explicit Kviewer(QWidget *parent = nullptr);
    ~Kviewer();

private:
    Ui::Kviewer *ui;
};

#endif // KVIEWER_H
