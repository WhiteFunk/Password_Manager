#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databasemanager.h"

#include <widget.h>
#include <addnewnote.h>


#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_clicked(const QModelIndex &index);

public slots:
    void setData (QString App,QString Login, QString Password);

private:
    void setWidgetStyle();

    QSqlTableModel *TableUnits;

    std::unique_ptr<DatabaseManager> UnitsDbManager;
    Ui::MainWindow *ui;

    AddNewNote *NewNoteWidget;
    Widget *Wdgt;

    int indexRow;



};
#endif // MAINWINDOW_H
