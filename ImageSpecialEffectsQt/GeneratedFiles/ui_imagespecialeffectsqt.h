/********************************************************************************
** Form generated from reading UI file 'imagespecialeffectsqt.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGESPECIALEFFECTSQT_H
#define UI_IMAGESPECIALEFFECTSQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageSpecialEffectsQtClass
{
public:
    QWidget *centralWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QPushButton *pushButton_4;
    QLabel *label;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QSpacerItem *verticalSpacer_3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ImageSpecialEffectsQtClass)
    {
        if (ImageSpecialEffectsQtClass->objectName().isEmpty())
            ImageSpecialEffectsQtClass->setObjectName(QStringLiteral("ImageSpecialEffectsQtClass"));
        ImageSpecialEffectsQtClass->resize(821, 578);
        centralWidget = new QWidget(ImageSpecialEffectsQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 817, 521));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSlider = new QSlider(horizontalLayoutWidget);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setEnabled(false);
        horizontalSlider->setMinimum(3);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setValue(10);
        horizontalSlider->setTracking(false);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(horizontalSlider);

        pushButton_4 = new QPushButton(horizontalLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setEnabled(false);

        horizontalLayout_2->addWidget(pushButton_4);


        verticalLayout->addLayout(horizontalLayout_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(640, 480));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        pushButton_3 = new QPushButton(horizontalLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_2);

        pushButton_5 = new QPushButton(horizontalLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setEnabled(false);

        verticalLayout_2->addWidget(pushButton_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_2);

        ImageSpecialEffectsQtClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(ImageSpecialEffectsQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 821, 21));
        ImageSpecialEffectsQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(ImageSpecialEffectsQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        ImageSpecialEffectsQtClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(ImageSpecialEffectsQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        ImageSpecialEffectsQtClass->setStatusBar(statusBar);

        retranslateUi(ImageSpecialEffectsQtClass);
        QObject::connect(pushButton, SIGNAL(clicked()), ImageSpecialEffectsQtClass, SLOT(openFile()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), ImageSpecialEffectsQtClass, SLOT(saveFile()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), ImageSpecialEffectsQtClass, SLOT(gray()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), ImageSpecialEffectsQtClass, SLOT(updateSize(int)));
        QObject::connect(pushButton_4, SIGNAL(clicked()), ImageSpecialEffectsQtClass, SLOT(undoZoom()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), ImageSpecialEffectsQtClass, SLOT(openBalanceDialog()));

        QMetaObject::connectSlotsByName(ImageSpecialEffectsQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *ImageSpecialEffectsQtClass)
    {
        ImageSpecialEffectsQtClass->setWindowTitle(QApplication::translate("ImageSpecialEffectsQtClass", "ImageSpecialEffectsQt", 0));
        label_2->setText(QApplication::translate("ImageSpecialEffectsQtClass", "\347\274\251\346\224\276", 0));
        pushButton_4->setText(QApplication::translate("ImageSpecialEffectsQtClass", "\346\201\242\345\244\215\345\216\237\345\233\276\345\244\247\345\260\217", 0));
        label->setText(QApplication::translate("ImageSpecialEffectsQtClass", "No Image", 0));
        pushButton->setText(QApplication::translate("ImageSpecialEffectsQtClass", "\346\211\223\345\274\200\345\233\276\345\203\217...", 0));
        pushButton_3->setText(QApplication::translate("ImageSpecialEffectsQtClass", "\345\217\246\345\255\230\344\270\272\345\233\276\345\203\217...", 0));
        pushButton_2->setText(QApplication::translate("ImageSpecialEffectsQtClass", "\351\273\221\347\231\275", 0));
        pushButton_5->setText(QApplication::translate("ImageSpecialEffectsQtClass", "\350\211\262\345\275\251\345\271\263\350\241\241...", 0));
    } // retranslateUi

};

namespace Ui {
    class ImageSpecialEffectsQtClass: public Ui_ImageSpecialEffectsQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGESPECIALEFFECTSQT_H
