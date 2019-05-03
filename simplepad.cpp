#include "simplepad.h"
#include "ui_simplepad.h"

SimplePad::SimplePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimplePad)
{
    ui->setupUi(this);
    //Teksta laukums tiek izvietots pa visu ekranu
    this->setCentralWidget(ui->textArea);

}
//destruktors
SimplePad::~SimplePad()
{
    delete ui;
}

void SimplePad::on_New_triggered()
{
    //Notira tekstu un sagatavo jaunai ievadei
    workingFile.clear();
    ui->textArea->setText(QString());


}
//Atvert failu
void SimplePad::on_Open_triggered()
{
    //atver logu un prasa izveleties failu
       QString fileName = QFileDialog::getOpenFileName(this, "Open file");
       // izveido input/output objektu failam
       QFile file(fileName);
       //atvertais fails klust par pasreiz atverto failu
       workingFile = fileName;

       //ja kluda tad atgriez pazinojumu
       if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
           //atgriez kludas pazinojumu
           QMessageBox::warning(this, "ERROR!!!", "Could not open file: " + file.errorString());
           //beidz metodi
           return;
       }
       //uzstada faila nosaukumu par loga nosaukumu
       setWindowTitle(fileName);

       //Nolasa tekstu no faila, un ievada to teksta laukuma
       QTextStream in(&file);
       QString text = in.readAll();
       ui->textArea->setText(text);

       //aizver failu
       file.close();
}

//saglaba failu
void SimplePad::on_Save_As_triggered()
{
        // atver faila saglabasanas dialogu. Nosaukuma
        QString fileName = QFileDialog::getSaveFileName(this, "Save as");
        // izveido input/output objektu failam
        QFile file(fileName);

        //ja kluda, tad atgriez pazinojumu
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "ERROR!!!", "Could not save file: " + file.errorString());
            //beidz metodi
            return;
        }
        //izveido output uz failu
        QTextStream out(&file);
        //parvers teksta laukuma ievadito tekstu par parastu tekstu
        QString text = ui->textArea->toPlainText();
        //izvada tekstu jauna faila
        out << text;
        //nomaina loga nosaukumu uz jauno
        setWindowTitle(fileName);
        //aizver failu
        file.close();
}
//Aizvert failu
void SimplePad::on_Exit_triggered()
{
     QApplication::quit();
}
//kopet tekstu
void SimplePad::on_Copy_triggered()
{
    ui->textArea->copy();
}
//ielimet tekstu
void SimplePad::on_Paste_triggered()
{
    ui->textArea->paste();
}
//atgriezties vienu darbibu atpakal
void SimplePad::on_Undo_triggered()
{
    ui->textArea->undo();
}
//atgriezties vienu darbibu uz prieksu
void SimplePad::on_Redo_triggered()
{
    ui->textArea->redo();
}

void SimplePad::on_Print_triggered()
{
        //izveido objektu printera apstradei
        QPrinter printer;
        //atvert printera izvelnes logu
        QPrintDialog printDialog(&printer, this);
        //ja neizdodas printeri izveleties, tad izvada erroru
        if(printDialog.exec() != QDialog::Accepted){
            QMessageBox::warning(this,"ERROR!!!", "Could not find printer");
            //partrauc metodi
            return;
        }
        //nosuta tekstu uz printeri
        ui->textArea->print(&printer);
}
