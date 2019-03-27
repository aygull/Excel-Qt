/********************************************************************************
** Form generated from reading UI file 'helpwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWINDOW_H
#define UI_HELPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_helpwindow
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QDialog *helpwindow)
    {
        if (helpwindow->objectName().isEmpty())
            helpwindow->setObjectName(QStringLiteral("helpwindow"));
        helpwindow->resize(400, 300);
        textBrowser = new QTextBrowser(helpwindow);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 0, 401, 301));

        retranslateUi(helpwindow);

        QMetaObject::connectSlotsByName(helpwindow);
    } // setupUi

    void retranslateUi(QDialog *helpwindow)
    {
        helpwindow->setWindowTitle(QApplication::translate("helpwindow", "Dialog", 0));
        textBrowser->setHtml(QApplication::translate("helpwindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\224\320\260\320\275\320\275\320\260\321\217 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\277\321\200\320\265\320\264\320\275\320\260\320\267\320\275\320\260\321\207\320\265\320\275\320\260 \320\264\320\273\321\217 \321\200\320\260\320\261\320\276\321\202\321\213 \321\201 excel \321\204\320\260\320\271\320\273\320\260\320\274\320\270.  \320\230\320\274\320\265\321\216\321\202\321\201\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\320\270 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217"
                        " \321\210\321\200\320\270\321\204\321\202\320\260,  \321\206\320\262\320\265\321\202\320\260 \321\202\320\265\320\272\321\201\321\202\320\260, \321\206\320\262\320\265\321\202\320\260 \320\267\320\260\320\273\320\270\320\262\320\272\320\270, \320\277\321\200\320\265\320\276\320\261\321\200\320\260\320\267\320\276\320\262\320\260\320\275\320\270\321\217 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\321\217 \320\263\321\200\321\203\320\277\320\277 \320\262 \321\200\320\260\321\201\320\277\320\270\321\201\320\260\320\275\320\270\320\265 \320\277\321\200\320\265\320\277\320\276\320\264\320\260\320\262\320\260\321\202\320\265\320\273\320\265\320\271. </p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class helpwindow: public Ui_helpwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWINDOW_H
