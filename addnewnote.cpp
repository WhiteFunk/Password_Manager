#include "addnewnote.h"
#include "ui_addnewnote.h"

AddNewNote::AddNewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddNewNote)
{
    ui->setupUi(this);
    SetStyle();
//    Qt::WindowFlags flags;
//    flags = Qt::FramelessWindowHint;
//    QWidget::setWindowFlags (flags);

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
    "QSpinBox{"
        "border:1px solid #aaa;"
        "background:#fff;"
        "border-radius:3px;"
        "color:#333;"
    "}"
    "QSpinBox:hover{"
        "border:1px solid #0078d7;"
    "}"
    "QComboBox{"
        "border:1px solid #aaa;"
        "background-color: qlineargradient(spread:pad, x1:0.585, y1:1, x2:0.506, y2:0, "
                           "stop:0 rgba(180, 180, 180, 255), stop:1 rgba(232, 232, 232, 255));"
        "border-radius:3px;"
        "color:#333;"
    "}"
    "QComboBox::drop-down {"
        "subcontrol-origin: padding;"
        "subcontrol-position: top right;"
        "width: 15px;"
        "border-left-width: 1px;"
        "border-left-color: darkgray;"
        "border-left-style: solid;"
        "border-top-right-radius: 3px;"
        "border-bottom-right-radius: 3px;"
    "}"
    "QComboBox::down-arrow {"
        "image: url(:/images/arrow.png);"
    "}"
    "QComboBox QListView{"
        "background:#fff;"
    "}"
    "QComboBox:hover{"
        "border:1px solid #0078d7;"
    "}"
    "QSpinBox::up-button {"
        "subcontrol-origin: border;"
        "subcontrol-position: top right;"
        "background-color:#eee;"
        "width: 16px;"
        "border-width: 1px;"
        "height:10px;"
        "margin-top:1px;"
        "margin-right:1px;"
        "border-radius:4px;"
    "}"
    "QSpinBox::down-button {"
        "subcontrol-origin: border;"
        "subcontrol-position: bottom right;"
        "background-color:#eee;"
        "width: 16px;"
        "border-width: 1px;"
        "height:10px;"
        "margin-bottom:1px;"
        "margin-right:1px;"
        "border-radius:4px;"
    "}"
    "QSpinBox::down-arrow {"
        "image: url(:/images/down.png);"
        "width: 7px;"
        "height: 7px;"
    "}"
    "QSpinBox::up-arrow {"
        "image: url(:/images/up.png);"
        "width: 7px;"
        "height: 7px;"
    "}"
    "QPlainTextEdit{"
        "border:1px solid #ccc;"
        "background:#fff;"
    "}"
    "QPlainTextEdit:hover{"
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

