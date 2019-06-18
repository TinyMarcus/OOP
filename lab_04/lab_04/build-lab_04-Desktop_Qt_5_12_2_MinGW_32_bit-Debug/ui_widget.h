/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGraphicsView *Canvas;
    QPushButton *AddButton;
    QPushButton *DeleteButton;
    QPushButton *LoadButton;
    QComboBox *CameraBox;
    QComboBox *ModelBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1063, 873);
        Widget->setStyleSheet(QString::fromUtf8(""));
        Canvas = new QGraphicsView(Widget);
        Canvas->setObjectName(QString::fromUtf8("Canvas"));
        Canvas->setGeometry(QRect(10, 10, 811, 851));
        Canvas->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        Canvas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        AddButton = new QPushButton(Widget);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        AddButton->setGeometry(QRect(830, 200, 221, 27));
        DeleteButton = new QPushButton(Widget);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));
        DeleteButton->setGeometry(QRect(830, 240, 221, 27));
        LoadButton = new QPushButton(Widget);
        LoadButton->setObjectName(QString::fromUtf8("LoadButton"));
        LoadButton->setGeometry(QRect(830, 60, 221, 27));
        CameraBox = new QComboBox(Widget);
        CameraBox->setObjectName(QString::fromUtf8("CameraBox"));
        CameraBox->setGeometry(QRect(830, 280, 221, 27));
        ModelBox = new QComboBox(Widget);
        ModelBox->setObjectName(QString::fromUtf8("ModelBox"));
        ModelBox->setGeometry(QRect(830, 100, 221, 27));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(830, 20, 221, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(830, 160, 221, 31));
        label_2->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
#ifndef QT_NO_TOOLTIP
        Canvas->setToolTip(QString());
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        Canvas->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        AddButton->setText(QApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        DeleteButton->setText(QApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", nullptr));
        LoadButton->setText(QApplication::translate("Widget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        label->setText(QApplication::translate("Widget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\260 \320\274\320\276\320\264\320\265\320\273\320\270 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", nullptr));
        label_2->setText(QApplication::translate("Widget", "\320\240\320\260\320\261\320\276\321\202\320\260 \321\201 \320\272\320\260\320\274\320\265\321\200\320\276\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
