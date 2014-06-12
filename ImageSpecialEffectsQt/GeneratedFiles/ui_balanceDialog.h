/********************************************************************************
** Form generated from reading UI file 'balanceDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALANCEDIALOG_H
#define UI_BALANCEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_balanceDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSlider *rSlider;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QSlider *gSlider;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QSlider *bSlider;
    QLabel *label_4;

    void setupUi(QWidget *balanceDialog)
    {
        if (balanceDialog->objectName().isEmpty())
            balanceDialog->setObjectName(QStringLiteral("balanceDialog"));
        balanceDialog->resize(493, 227);
        buttonBox = new QDialogButtonBox(balanceDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(300, 190, 161, 23));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(balanceDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 471, 161));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(label);

        rSlider = new QSlider(verticalLayoutWidget);
        rSlider->setObjectName(QStringLiteral("rSlider"));
        rSlider->setMinimum(-255);
        rSlider->setMaximum(255);
        rSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(rSlider);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_3->addWidget(label_6);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        gSlider = new QSlider(verticalLayoutWidget);
        gSlider->setObjectName(QStringLiteral("gSlider"));
        gSlider->setMinimum(-255);
        gSlider->setMaximum(255);
        gSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(gSlider);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_5->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        bSlider = new QSlider(verticalLayoutWidget);
        bSlider->setObjectName(QStringLiteral("bSlider"));
        bSlider->setMinimum(-255);
        bSlider->setMaximum(255);
        bSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(bSlider);

        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_4->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(balanceDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), balanceDialog, SLOT(accepted()));
        QObject::connect(buttonBox, SIGNAL(rejected()), balanceDialog, SLOT(rejected()));

        QMetaObject::connectSlotsByName(balanceDialog);
    } // setupUi

    void retranslateUi(QWidget *balanceDialog)
    {
        balanceDialog->setWindowTitle(QApplication::translate("balanceDialog", "balanceDialog", 0));
        label->setText(QApplication::translate("balanceDialog", "\351\235\222\350\211\262", 0));
        label_6->setText(QApplication::translate("balanceDialog", "\347\272\242\350\211\262", 0));
        label_2->setText(QApplication::translate("balanceDialog", "\347\264\253\350\211\262", 0));
        label_5->setText(QApplication::translate("balanceDialog", "\347\273\277\350\211\262", 0));
        label_3->setText(QApplication::translate("balanceDialog", "\351\273\204\350\211\262", 0));
        label_4->setText(QApplication::translate("balanceDialog", "\350\223\235\350\211\262", 0));
    } // retranslateUi

};

namespace Ui {
    class balanceDialog: public Ui_balanceDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALANCEDIALOG_H
