#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QSqlRecord>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setFixedSize(760,550);

    UnitsDbManager = std::make_unique<DatabaseManager>();


    TableUnits = new QSqlTableModel;
    TableUnits->setTable(QString("units"));
    TableUnits->select();



    ui->tableView->setModel(TableUnits);
    ui->tableView->setColumnHidden(0,true);
    ui->tableView->setColumnWidth(1,200);
    ui->tableView->setColumnWidth(2,200);
    ui->tableView->setColumnWidth(3,325);

    setWidgetStyle();

    NewNoteWidget = new AddNewNote;
    Wdgt = new Widget;

    connect(NewNoteWidget,&AddNewNote::sendData,this,&MainWindow::setData);

    this->setWindowTitle("Password Manager");
}

MainWindow::~MainWindow()
{
    delete TableUnits;
    delete ui;
}




void MainWindow::on_pushButton_3_clicked()
{
    Wdgt->show();
}


void MainWindow::on_pushButton_clicked()
{
    NewNoteWidget->show();
}


void MainWindow::on_pushButton_2_clicked()

{

    TableUnits->removeRow(indexRow);

    TableUnits->select();
    ui->tableView->repaint();


}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    indexRow = index.row();
}

void MainWindow::setData(QString App,QString Login, QString Password){

    QSqlRecord newRecord = TableUnits->record();

       newRecord.setValue(1, App);
       newRecord.setValue(2, Login);
       newRecord.setValue(3, Password);

     TableUnits->insertRecord(TableUnits->rowCount(), newRecord);

     TableUnits->select();
     ui->tableView->repaint();
}

void MainWindow::setWidgetStyle()
{
    this->setStyleSheet(
    "QWidget{"
        "background-color:#ddd;"
        "font: 900 9pt Segoe UI;"
    "}"


    "QPushButton{"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(232, 232, 232, 255));"
        "border-radius:5px;"
        "border:1px solid #aaa;"
        "color:#555;"
    "}"

    "QPushButton:hover{"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 stop:0 rgba(200, 200, 200, 200), stop:1 rgba(232, 232, 232, 255));"
        "border-radius:5px;"
        "border:1px solid #0078d7;"
        "color:#111;"
    "}"

                );
}
