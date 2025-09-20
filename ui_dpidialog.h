/********************************************************************************
** Form generated from reading UI file 'dpidialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DPIDIALOG_H
#define UI_DPIDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DPIDialog
{
public:
    QGridLayout *gridLayout;
    QLabel *labelResolution;
    QDialogButtonBox *buttonBox;
    QSpinBox *xDPI;
    QLabel *labelX;
    QSpinBox *yDPI;

    void setupUi(QDialog *DPIDialog)
    {
        if (DPIDialog->objectName().isEmpty())
            DPIDialog->setObjectName(QString::fromUtf8("DPIDialog"));
        DPIDialog->resize(275, 72);
        gridLayout = new QGridLayout(DPIDialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        labelResolution = new QLabel(DPIDialog);
        labelResolution->setObjectName(QString::fromUtf8("labelResolution"));
        labelResolution->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelResolution, 0, 0, 1, 3);

        buttonBox = new QDialogButtonBox(DPIDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 0, 3, 2, 1);

        xDPI = new QSpinBox(DPIDialog);
        xDPI->setObjectName(QString::fromUtf8("xDPI"));
        xDPI->setMaximum(999999999);
        xDPI->setValue(300);

        gridLayout->addWidget(xDPI, 1, 0, 1, 1);

        labelX = new QLabel(DPIDialog);
        labelX->setObjectName(QString::fromUtf8("labelX"));
        labelX->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelX, 1, 1, 1, 1);

        yDPI = new QSpinBox(DPIDialog);
        yDPI->setObjectName(QString::fromUtf8("yDPI"));
        yDPI->setMaximum(999999999);
        yDPI->setValue(300);

        gridLayout->addWidget(yDPI, 1, 2, 1, 1);


        retranslateUi(DPIDialog);
        QObject::connect(buttonBox, SIGNAL(rejected()), DPIDialog, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), DPIDialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(DPIDialog);
    } // setupUi

    void retranslateUi(QDialog *DPIDialog)
    {
        DPIDialog->setWindowTitle(QCoreApplication::translate("DPIDialog", "Change DPI...", nullptr));
        labelResolution->setText(QCoreApplication::translate("DPIDialog", "Resolution", nullptr));
#if QT_CONFIG(tooltip)
        xDPI->setToolTip(QCoreApplication::translate("DPIDialog", "<html><head/><body><p>Y-DPI</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        labelX->setText(QCoreApplication::translate("DPIDialog", "x", nullptr));
#if QT_CONFIG(tooltip)
        yDPI->setToolTip(QCoreApplication::translate("DPIDialog", "<html><head/><body><p>X-DPI</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class DPIDialog: public Ui_DPIDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DPIDIALOG_H
