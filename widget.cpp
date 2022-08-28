#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>
#include <QClipboard>
#include <QMimeData>


bool didgitIsValid(const QString &didgits);


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(504,410);
    this->setWidgetStyle();
//    Qt::WindowFlags flags;
//    flags = Qt::FramelessWindowHint;
//    QWidget::setWindowFlags (flags);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    ui->plainTextEdit->clear();
    QString result = "";

 addLatin(result);
 addCiryllic(result);
 addSymbols(result);
 addDidgits(result);

int lettersCount = ui->lettersSpin->value();
int passCount = ui->passCountSpin->value();
srand(time(0));

for(int i =0;i<passCount;i++)
{
    QString pass = "";
    int index;
    for(int j=0;j<lettersCount;j++){
        index = rand() % result.length();
        pass += result[index];
    }
    ui->plainTextEdit->appendPlainText(pass);
}




}

void Widget::addSymbols(QString &res)
{
    if(ui->symbolCheck->isChecked())
    {
        QString symbols = ui->symbolEdit->text();
        symbols.replace(" ","");
        res += symbols;

    }
}

void Widget::addLatin(QString &res)
{
    QString latinLower = "abcdefghijklmnopqrstuvwxyz";
    QString latinUpper  =latinLower.toUpper() ;
    if(this->ui->latinCheck->isChecked()){
        if(ui->latinCombo->currentIndex()==1)
        {
            res += latinUpper;
        }
        else if(ui->latinCombo->currentIndex()==2)
        {
            res += latinLower;
        }
        else
        {
            res += latinUpper + latinLower;

        }
    }

}

void Widget::addCiryllic(QString &res)
{
    QString ciryllicLower ="абвгдеёжзиклмнопрстуфхцчшщъьыэюя";
    QString ciryllicUpper =ciryllicLower.toUpper();
    if(ui->ciryllicCheck->isChecked())
    {
        if(ui->ciryllicCombo->currentIndex()==1)
        {
            res += ciryllicUpper;
        }
        else if(ui->ciryllicCombo->currentIndex()==2)
        {
            res += ciryllicLower;
        }
        else
        {
            res +=ciryllicUpper + ciryllicLower;

        }
    }
}

void Widget::addDidgits(QString &res)
{
    if(ui->didgitCheck->isChecked())
    {
        QString didgits = ui->didgitEdit->text();
        didgits.replace(" ","");

        if(didgitIsValid(didgits)){
            int start =QString(didgits.at(0)).toInt();
            int end =  QString(didgits.at(2)).toInt();
            for (int i = start; i<=end;i++)
            {
                res+=QString::number(i);
            }

        }

    }

}

bool didgitIsValid(const QString &didgits){
    if(didgits.length()!=3){
        return false;
    }
    else if (didgits.at(1)!= '-')
    {
        return false;
    }
    else if ((didgits.at(0).isDigit() == false) || (didgits.at(0).isDigit() == false) )
    {
        return false;
    }
    else
    {
        return true;
    }

}

void Widget::on_pushButton_2_clicked()
{
    ui->plainTextEdit->clear();
}


/*******************************************
 * Функция устанавливает QSS для виджетов.
 *******************************************/
void Widget::setWidgetStyle()
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





void Widget::on_pushButton_3_clicked()
{
     QClipboard* c = QApplication::clipboard();
       c->setText( ui->plainTextEdit->toPlainText() );
}




