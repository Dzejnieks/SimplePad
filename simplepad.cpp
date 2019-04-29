#include "simplepad.h"
#include "ui_simplepad.h"

SimplePad::SimplePad(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimplePad)
{
    ui->setupUi(this);
}

SimplePad::~SimplePad()
{
    delete ui;
}
