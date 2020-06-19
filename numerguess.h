#ifndef NUMERGUESS_H
#define NUMERGUESS_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
namespace Ui {
class Numerguess;
}

class Numerguess : public QMainWindow
{
    Q_OBJECT

public:
    explicit Numerguess(QWidget *parent = nullptr);
    ~Numerguess();

    int correctnumber[4];
    int good;

    int usernumber[4];

    int Astate;
    int Bstate;


    int attempts;

    void numberset();



    QTimer* setu;

public slots:
    void reset();
    void reflash();
    void correctornot();


private:
    Ui::Numerguess *ui;
};

#endif // NUMERGUESS_H
