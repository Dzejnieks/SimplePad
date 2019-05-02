#ifndef SIMPLEPAD_H
#define SIMPLEPAD_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
namespace Ui {
class SimplePad;
}

class SimplePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimplePad(QWidget *parent = nullptr);
    ~SimplePad();

private slots:
    void on_New_triggered();

    void on_Open_triggered();

    void on_Save_As_triggered();

    void on_Exit_triggered();

    void on_Copy_triggered();

    void on_Paste_triggered();

    void on_Undo_triggered();

    void on_Redo_triggered();

private:
    Ui::SimplePad *ui;
    QString workingFile="";
};

#endif // SIMPLEPAD_H
