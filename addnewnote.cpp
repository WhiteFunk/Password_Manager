#include "addnewnote.h"
#include "ui_addnewnote.h"

AddNewNote::AddNewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewNote)
{
    ui->setupUi(this);
    SetStyle();

     setFixedSize(400,137);


    Qt::WindowFlags flags;
    flags = Qt::Tool;
    QWidget::setWindowFlags (flags);

}

AddNewNote::~AddNewNote()
{
    delete ui;
}



void AddNewNote::SetStyle()
{
    this->setStyleSheet(
    "QWidget{"
        "background-color:#ddd;"
    "}"
    "QLineEdit{"
        "border:1px solid #aaa;"
        "background:#fff;"
        "border-radius:3px;"
        "color:#333;"
    "}"
    "QLineEdit:hover{"
        "border:1px solid #0078d7;"
    "}"
    "QPushButton{"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(180, 180, 180, 255), stop:1 rgba(232, 232, 232, 255));"
        "border-radius:5px;"
        "border:1px solid #aaa;"
        "color:#555;"
    "}"
    "QPushButton:hover{"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, stop:0 rgba(200, 200, 200, 200), stop:1 rgba(232, 232, 232, 255));"
        "border-radius:5px;"
        "border:1px solid #0078d7;"
        "color:#111;"
    "}");
}

void AddNewNote::on_pushButton_clicked()
{
    emit sendData(ui->lineEdit->text(),ui->lineEdit_2->text(),ui->lineEdit_3->text());
    QWidget::close();
}

