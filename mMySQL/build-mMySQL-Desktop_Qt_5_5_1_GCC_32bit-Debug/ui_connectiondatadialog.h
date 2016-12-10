/********************************************************************************
** Form generated from reading UI file 'connectiondatadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTIONDATADIALOG_H
#define UI_CONNECTIONDATADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ConnectionDataDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_1;
    QLineEdit *lineEdit_1;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *ConnectionDataDialog)
    {
        if (ConnectionDataDialog->objectName().isEmpty())
            ConnectionDataDialog->setObjectName(QStringLiteral("ConnectionDataDialog"));
        ConnectionDataDialog->resize(400, 258);
        buttonBox = new QDialogButtonBox(ConnectionDataDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 170, 81, 61));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label_1 = new QLabel(ConnectionDataDialog);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(10, 10, 260, 20));
        lineEdit_1 = new QLineEdit(ConnectionDataDialog);
        lineEdit_1->setObjectName(QStringLiteral("lineEdit_1"));
        lineEdit_1->setGeometry(QRect(20, 30, 360, 27));
        label_2 = new QLabel(ConnectionDataDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 260, 17));
        lineEdit_2 = new QLineEdit(ConnectionDataDialog);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 90, 250, 27));
        label_3 = new QLabel(ConnectionDataDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 260, 17));
        lineEdit_3 = new QLineEdit(ConnectionDataDialog);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(20, 150, 250, 27));
        label_4 = new QLabel(ConnectionDataDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 190, 250, 17));
        lineEdit_4 = new QLineEdit(ConnectionDataDialog);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(20, 210, 250, 27));
        label_5 = new QLabel(ConnectionDataDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 70, 80, 17));
        lineEdit_5 = new QLineEdit(ConnectionDataDialog);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(290, 90, 90, 27));

        retranslateUi(ConnectionDataDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConnectionDataDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConnectionDataDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ConnectionDataDialog);
    } // setupUi

    void retranslateUi(QDialog *ConnectionDataDialog)
    {
        ConnectionDataDialog->setWindowTitle(QApplication::translate("ConnectionDataDialog", "Dialog", 0));
        label_1->setText(QApplication::translate("ConnectionDataDialog", "TextLabel", 0));
        label_2->setText(QApplication::translate("ConnectionDataDialog", "TextLabel", 0));
        label_3->setText(QApplication::translate("ConnectionDataDialog", "TextLabel", 0));
        label_4->setText(QApplication::translate("ConnectionDataDialog", "TextLabel", 0));
        label_5->setText(QApplication::translate("ConnectionDataDialog", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class ConnectionDataDialog: public Ui_ConnectionDataDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTIONDATADIALOG_H
