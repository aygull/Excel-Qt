#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpwindow.h"
#include "aboutwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   ui->setupUi(this);
   QStandardItemModel* model = new QStandardItemModel();
   ui->tableView->setModel(model);


}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
   QString filename=QFileDialog::getOpenFileName(this,
   tr("Open File"),"C://lab02Excel//" , "Excel Files(*.xlsx);;");
    if (filename=="")
            return;
   xlsx = new QXlsx::Document(filename);
   ui->pushButton_5->setEnabled(true);
   ui->pushButton_2->setEnabled(true);
   ui->comboBox_3->clear();
   ui->comboBox_3->addItems(xlsx->sheetNames());
   int x, y;
   x=xlsx->dimension().columnCount();
   y=xlsx->dimension().rowCount();
   QStandardItemModel *model=new QStandardItemModel(y-1, x);
   QString string_1;
   ui->tableView->setModel(model);
   ui->label_5->setText(xlsx->read(1,1).toString());

    for(int i=1; i<=x; i++){
        for (int j=2; j<=y;j++){
         QXlsx::Format format1 = xlsx->cellAt(j, i)->format();
          model->setData(model->index(j-2, i-1), format1.font(), Qt::FontRole);
          model->setData(model->index(j-2, i-1), format1.fontColor(), Qt::ForegroundRole);
          model->setData(model->index(j-2, i-1), format1.patternBackgroundColor(), Qt::BackgroundRole);
          model->setData(model->index(j-2, i-1), xlsx->read(j, i));
           }
}
  ui->spinBox->setValue(y-1);
  ui->spinBox_2->setValue(x);
    for (int i=0;i<model->rowCount();i++) {
     Qt::ItemFlags currentFlagss = model->item(i,0)->flags();
     model->item(i,0)->setFlags(currentFlagss & (~Qt::ItemIsEditable));
     model->item(i,1)->setFlags(currentFlagss & (~Qt::ItemIsEditable));
  }
}

void MainWindow::on_tableView_activated(const QModelIndex &index)
{

}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename=QFileDialog::getSaveFileName(this,
    tr("Save File"),"C://" , "Excel Files(*.xlsx);;");
    if (filename=="")
            return;
    QXlsx::Document xlsx_1;
    QAbstractItemModel *model=ui->tableView->model();
    QXlsx::Format format1;
    format1.setFontColor(rainbow2);
    format1.setPatternBackgroundColor(rainbow);
    format1.setFont(font);
    xlsx->deleteSheet(ui->comboBox_3->currentText());
    QXlsx::AbstractSheet *sheet = xlsx_1.currentSheet();
    xlsx->insertSheet(ui->comboBox_3->currentIndex(),ui->comboBox_3->currentText(), sheet->sheetType());
    xlsx->selectSheet(ui->comboBox_3->currentText());
    xlsx->write(1, 1, ui->label_5->text());
     for(int i=1; i<=model->rowCount(); i++){
         for (int j=1; j<=model->columnCount();j++){
            xlsx->write(i+1, j, model->itemData(model->index(i-1,j-1)).value(0).toString(), format1);
         }
     }
   xlsx->saveAs(filename);

}

void MainWindow::on_spinBox_valueChanged(int arg1)//строки
{
    QAbstractItemModel *model = ui->tableView->model();
    while(model->rowCount() != arg1){
    if (arg1 < model->rowCount()){
    model->removeRow(model->rowCount()-1);
    }else{
    model->insertRow(model->rowCount()); } }
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)//столбцы
{
   QAbstractItemModel *model = ui->tableView->model();
    while(model->columnCount() != arg1){
    if (arg1 < model->columnCount()){
    model->removeColumn(model->columnCount()-1);
    }else{
    model->insertColumn(model->columnCount());
    }
    }
}



void MainWindow::on_comboBox_activated(const QString &arg1)
{
    rainbow2.setNamedColor(arg1);
    QAbstractItemModel* tableModel=ui->tableView->model();
    int iRows = tableModel->rowCount();
    int iCols = tableModel->columnCount();
    for(int i=0; i<iRows; i++){
        for (int j=0; j<iCols;j++){
             tableModel->setData((tableModel->index(i,j, QModelIndex())), QVariant(QColor(rainbow2)), Qt::ForegroundRole);
        }
    }
    ui->tableView->setModel(tableModel);

}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
    rainbow.setNamedColor(arg1);
    QAbstractItemModel* tableModel=ui->tableView->model();
    int iRows = tableModel->rowCount();
    int iCols = tableModel->columnCount();
    for(int i=0; i<iRows; i++){
        for (int j=0; j<iCols;j++){
             tableModel->setData((tableModel->index(i,j, QModelIndex())), QVariant(QColor(rainbow)), Qt::BackgroundColorRole);
        }
    }
    ui->tableView->setModel(tableModel);

}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
   xlsx->selectSheet(arg1);
   int x, y;
   x=xlsx->dimension().columnCount();
   y=xlsx->dimension().rowCount();

   ui->label_5->setText(ui->comboBox_3->currentText());

   QStandardItemModel *model=new QStandardItemModel(y-1, x);
   QString string_1;
   ui->tableView->setModel(model);

    for(int i=1; i<=x; i++){
        for (int j=2; j<=y;j++){
          //QXlsx::Format format1 = xlsx->cellAt(j, i)->format();
          //model->setData(model->index(j-2, i-1), format1.font(), Qt::FontRole);
          //model->setData(model->index(j-2, i-1), format1.fontColor(), Qt::ForegroundRole);
          //model->setData(model->index(j-2, i-1), format1.patternBackgroundColor(), Qt::BackgroundRole);
          model->setData(model->index(j-2, i-1), xlsx->read(j, i));
           }
}
  ui->spinBox->setValue(y-1);
  ui->spinBox_2->setValue(x);
    for (int i=0;i<model->rowCount();i++) {
     Qt::ItemFlags currentFlagss = model->item(i,0)->flags();
     model->item(i,0)->setFlags(currentFlagss & (~Qt::ItemIsEditable));
     model->item(i,1)->setFlags(currentFlagss & (~Qt::ItemIsEditable));
  }
}

void MainWindow::on_pushButton_4_clicked()
{
    bool ok;
    font = QFontDialog::getFont(
                    &ok, QFont("Helvetica [Cronyx]", 10), this);
    if(!ok)return;
    QAbstractItemModel* tableModel=ui->tableView->model();
    int iRows = tableModel->rowCount();
    int iCols = tableModel->columnCount();
    for(int i=0; i<iRows; i++){
        for (int j=0; j<iCols;j++){
   tableModel->setData((tableModel->index(i,j, QModelIndex())), QVariant(QFont(font)), Qt::FontRole);
    }
    }
    //if(font.)
      ui->tableView->setModel(tableModel);
}

void MainWindow::on_pushButton_5_clicked()
{
    QXlsx::Document xl_file_for_pr("C:\\lab02Excel\\расписание преподавателей2.xlsx");
    xlsx = new QXlsx::Document;
    QAbstractItemModel *model_for_pr = ui->tableView->model();
    xl_file_for_pr.selectSheet(ui->label_5->text());
    QString str;
    for (int i = 1; i<=xl_file_for_pr.dimension().rowCount(); i++){
     if(xlsx->sheetNames() != xl_file_for_pr.read(i,1))
     xlsx->addSheet(xl_file_for_pr.read(i,1).toString());
     else
     xlsx->selectSheet(xl_file_for_pr.read(i,1).toString());
        xlsx->write(1, 1, xl_file_for_pr.read(i,1).toString());
        for (int j = 0; j < model_for_pr->rowCount(); j++){
            for(int k = 0 ; k < model_for_pr->columnCount()-2; k++){
             if(xlsx->read(j+2, k+1).toString() == "")
             xlsx->write(j+2, k+1, model_for_pr->itemData(model_for_pr->index(j, k)).value(0).toString());
        }
        for(int k = 2 ; k < model_for_pr->columnCount(); k++){
            if(xlsx->read(j+2, k+1).toString() == "" && xl_file_for_pr.read(i, 2) == model_for_pr->itemData(model_for_pr->index(j, 3)).value(0).toString() && xl_file_for_pr.read(i, 3) == ui->label_5->text())
            xlsx->write(j+2, k+1, model_for_pr->itemData(model_for_pr->index(j, k)).value(0).toString());
            }
         }
    }
    ui->comboBox_3->clear();
    ui->comboBox_3->addItems(xlsx->sheetNames());
    xlsx->selectSheet(ui->comboBox_3->currentText());
    ui->label_5->setText(xlsx->read(1,1).toString());
    QStandardItemModel *model = new QStandardItemModel(xlsx->dimension().rowCount()-1, xlsx->dimension().columnCount());
    for(int i = 1; i <= xlsx->dimension().columnCount();i++){
        for(int j = 2; j <= xlsx->dimension().rowCount(); j++){
         str = xlsx->read(j,i).toString();
         QStandardItem *item = new QStandardItem(str);
         model->setItem(j-2, i-1, item);
        }
    }
    ui->tableView->setModel(model);
    ui->spinBox->setValue(xlsx->dimension().rowCount()-1);
    ui->spinBox_2->setValue(xlsx->dimension().columnCount());
    ui->comboBox->setCurrentIndex(0);
    ui->comboBox_2->setCurrentIndex(0);
}

void MainWindow::on_actionAbout_triggered()
{
    aboutwindow about;
    about.setModal(true);
    about.exec();
}

void MainWindow::on_actionHelp_triggered()
{
    helpwindow help;
    help.setModal(true);
    help.exec();
}
