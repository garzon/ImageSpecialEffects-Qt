/********************************************************************************
** Form generated from reading UI file 'textImageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEXTIMAGEDIALOG_H
#define UI_TEXTIMAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_textImageDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *outputChar;
    QTextEdit *textImage;
    QPushButton *pushButton;

    void setupUi(QWidget *textImageDialog)
    {
        if (textImageDialog->objectName().isEmpty())
            textImageDialog->setObjectName(QStringLiteral("textImageDialog"));
        textImageDialog->resize(560, 534);
        verticalLayoutWidget = new QWidget(textImageDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 541, 481));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, -1);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        outputChar = new QLineEdit(verticalLayoutWidget);
        outputChar->setObjectName(QStringLiteral("outputChar"));

        horizontalLayout->addWidget(outputChar);


        verticalLayout->addLayout(horizontalLayout);

        textImage = new QTextEdit(verticalLayoutWidget);
        textImage->setObjectName(QStringLiteral("textImage"));
        textImage->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textImage->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        textImage->setReadOnly(true);

        verticalLayout->addWidget(textImage);

        pushButton = new QPushButton(textImageDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(240, 500, 75, 23));

        retranslateUi(textImageDialog);
        QObject::connect(pushButton, SIGNAL(clicked()), textImageDialog, SLOT(accepted()));

        QMetaObject::connectSlotsByName(textImageDialog);
    } // setupUi

    void retranslateUi(QWidget *textImageDialog)
    {
        textImageDialog->setWindowTitle(QApplication::translate("textImageDialog", "textImageDialog", 0));
        label->setText(QApplication::translate("textImageDialog", "\350\246\201\350\276\223\345\207\272\347\232\204\345\255\227\347\254\246\347\247\215\347\261\273:", 0));
        outputChar->setText(QApplication::translate("textImageDialog", " .-+&#=|x0o@", 0));
        pushButton->setText(QApplication::translate("textImageDialog", "\347\224\237\346\210\220\345\255\227\347\254\246\347\224\273", 0));
    } // retranslateUi

};

namespace Ui {
    class textImageDialog: public Ui_textImageDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEXTIMAGEDIALOG_H
