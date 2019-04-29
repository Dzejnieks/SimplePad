#ifndef SIMPLEPAD_H
#define SIMPLEPAD_H

#include <QMainWindow>

namespace Ui {
class SimplePad;
}

class SimplePad : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimplePad(QWidget *parent = nullptr);
    ~SimplePad();

private:
    Ui::SimplePad *ui;
};

#endif // SIMPLEPAD_H
