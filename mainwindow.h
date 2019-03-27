#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtXlsx>
#include<QFileDialog>
#include<QString>
#include<QStandardItemModel>
#include<QDebug>
#include<QFontDialog>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_tableView_activated(const QModelIndex &index);
    void on_pushButton_2_clicked();
    void on_spinBox_valueChanged(int arg1);
    void on_spinBox_2_valueChanged(int arg1);
    void on_comboBox_activated(const QString &arg1);
    void on_comboBox_2_activated(const QString &arg1);\
    void on_comboBox_3_activated(const QString &arg1);
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_actionAbout_triggered();
    void on_actionHelp_triggered();
private:
    Ui::MainWindow *ui;
    QColor rainbow;
    QColor rainbow2;
    QFont font;
    QXlsx::Document  *xlsx;

};

#endif // MAINWINDOW_H
