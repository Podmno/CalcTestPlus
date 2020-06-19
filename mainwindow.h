#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include "testprogram.h"
#include "questionset.h"
#include "score.h"
#include "numerguess.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void connectdata(int,int,int);
    void trannormal();

    bool filereadmode;

    TestProgram *tes;
    Questionset *queset;
    Score *src;

    bool typehelper(QString);

    int que_numbers;
    int que_max;
    int que_min;
    bool que_minus;
    bool que_points;
    bool que_type1;
    bool que_type2;
    bool que_type3;
    bool que_type4;
    int que_targetset;
    int que_timeset;

    Numerguess* numg;

private:
    Ui::MainWindow *ui;


    void fileread();




public slots:
    void exitmenu();
    void backmenu();
    void goodnight();
};
#endif // MAINWINDOW_H
