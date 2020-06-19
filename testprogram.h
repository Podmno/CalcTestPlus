#ifndef TESTPROGRAM_H
#define TESTPROGRAM_H
#include "question.h"
#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include "testfinish.h"
#include <QCloseEvent>
namespace Ui {
class TestProgram;
}

class TestProgram : public QMainWindow
{
    Q_OBJECT

public:
    explicit TestProgram(QWidget *parent = nullptr);
    ~TestProgram();


    Question* queindex;
    Testfinish* fin;




    int t_numbers;
    int t_max;
    int t_min;
    bool t_minus;
    bool t_points;
    bool t_type1;
    bool t_type2;
    bool t_type3;
    bool t_type4;
    int t_targetset;
    int t_timeset;

    bool t_timesettings;

    int t_currenttime;
    int t_timecounter;


    int t_current;
    int t_userscore;
    int t_userchance;

    int t_1stscore;
    int t_2ndscore;
    int t_3rdscore;

    int t_trynumber;


public slots:
    void t_setstart();
    void t_timeend();
    void t_timeupdate();
    void t_setend();
    void t_userhandin();
    void t_restart();

public:

    QTimer *timelimit;
    QTimer *timecount;



    void t_questionset();
    void t_dataset();
    void t_scoreflash();
    void t_timecounton();
    void t_timelimiton();

    bool t_passed;

private:
    Ui::TestProgram *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // TESTPROGRAM_H
