/********************************************************************************
** Form generated from reading UI file 'cdbdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CDBDIALOG_H
#define UI_CDBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_CDBDialog
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelWhite;
    QSpinBox *whiteVal;
    QHBoxLayout *horizontalLayout;
    QLabel *labelBlack;
    QSpinBox *blackVal;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSlider *treshold;
    QLCDNumber *lcdNumber;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *CDBDialog)
    {
        if (CDBDialog->objectName().isEmpty())
            CDBDialog->setObjectName(QString::fromUtf8("CDBDialog"));
        CDBDialog->resize(392, 120);
        gridLayout = new QGridLayout(CDBDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelWhite = new QLabel(CDBDialog);
        labelWhite->setObjectName(QString::fromUtf8("labelWhite"));

        horizontalLayout_2->addWidget(labelWhite);

        whiteVal = new QSpinBox(CDBDialog);
        whiteVal->setObjectName(QString::fromUtf8("whiteVal"));
        whiteVal->setMaximum(360);
        whiteVal->setValue(180);

        horizontalLayout_2->addWidget(whiteVal);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelBlack = new QLabel(CDBDialog);
        labelBlack->setObjectName(QString::fromUtf8("labelBlack"));

        horizontalLayout->addWidget(labelBlack);

        blackVal = new QSpinBox(CDBDialog);
        blackVal->setObjectName(QString::fromUtf8("blackVal"));
        blackVal->setValue(70);

        horizontalLayout->addWidget(blackVal);


        gridLayout->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(CDBDialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        treshold = new QSlider(CDBDialog);
        treshold->setObjectName(QString::fromUtf8("treshold"));
        treshold->setMaximum(100);
        treshold->setSliderPosition(50);
        treshold->setOrientation(Qt::Horizontal);
        treshold->setTickPosition(QSlider::TicksBelow);
        treshold->setTickInterval(5);

        horizontalLayout_3->addWidget(treshold);

        lcdNumber = new QLCDNumber(CDBDialog);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setProperty("value", QVariant(50.000000000000000));

        horizontalLayout_3->addWidget(lcdNumber);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(CDBDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(CDBDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), CDBDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), CDBDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(CDBDialog);
    } // setupUi

    void retranslateUi(QDialog *CDBDialog)
    {
        CDBDialog->setWindowTitle(QCoreApplication::translate("CDBDialog", "Clean Dark Background Settings", nullptr));
        labelWhite->setText(QCoreApplication::translate("CDBDialog", "White", nullptr));
        labelBlack->setText(QCoreApplication::translate("CDBDialog", "Black", nullptr));
        label->setText(QCoreApplication::translate("CDBDialog", "Treshhold", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CDBDialog: public Ui_CDBDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CDBDIALOG_H
