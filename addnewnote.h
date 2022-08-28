#ifndef ADDNEWNOTE_H
#define ADDNEWNOTE_H

#include <QDialog>

namespace Ui {
class AddNewNote;
}

class AddNewNote : public QDialog
{
    Q_OBJECT

public:
    explicit AddNewNote(QWidget *parent = nullptr);
    ~AddNewNote();
    void SetStyle();

private:
    Ui::AddNewNote *ui;

signals:
    void sendData(QString App,QString Login, QString Password);

private slots:
    void on_pushButton_clicked();
};

#endif // ADDNEWNOTE_H
