/********************************************************************************
** Form generated from reading UI file 'kviewer.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KVIEWER_H
#define UI_KVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>

QT_BEGIN_NAMESPACE

class Ui_Kviewer
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Kviewer)
    {
        if (Kviewer->objectName().isEmpty())
            Kviewer->setObjectName(QString::fromUtf8("Kviewer"));
        Kviewer->resize(966, 331);
        buttonBox = new QDialogButtonBox(Kviewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(590, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(Kviewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), Kviewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Kviewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(Kviewer);
    } // setupUi

    void retranslateUi(QDialog *Kviewer)
    {
        Kviewer->setWindowTitle(QApplication::translate("Kviewer", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kviewer: public Ui_Kviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVIEWER_H
