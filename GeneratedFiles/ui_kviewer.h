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
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Kviewer
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *textEdit;

    void setupUi(QDialog *Kviewer)
    {
        if (Kviewer->objectName().isEmpty())
            Kviewer->setObjectName(QString::fromUtf8("Kviewer"));
        Kviewer->resize(966, 331);
        buttonBox = new QDialogButtonBox(Kviewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(600, 290, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Kviewer);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 54, 12));
        textEdit = new QTextEdit(Kviewer);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 60, 101, 31));

        retranslateUi(Kviewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), Kviewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Kviewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(Kviewer);
    } // setupUi

    void retranslateUi(QDialog *Kviewer)
    {
        Kviewer->setWindowTitle(QApplication::translate("Kviewer", "Dialog", nullptr));
        label->setText(QApplication::translate("Kviewer", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Kviewer: public Ui_Kviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KVIEWER_H
