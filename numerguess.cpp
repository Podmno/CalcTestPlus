#include "numerguess.h"
#include "ui_numerguess.h"
#include <ctime>
#include <stdlib.h>

Numerguess::Numerguess(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Numerguess)
{
    ui->setupUi(this);

    setu=new QTimer;

    attempts=0;

    srand((int)time(NULL));

   QString state1="？ ？ ？ ？";
   QString state2="🤔  0 Attempts, 0 A 0 B";

    ui->state->setText(state2);
    ui->number->setText(state1);


    connect(ui->close,SIGNAL(clicked()),parent,SLOT(goodnight()));
    connect(setu,SIGNAL(timeout()),this,SLOT(reflash()));
    connect(ui->restart,SIGNAL(clicked()),this,SLOT(reset()));
    connect(ui->ok,&QPushButton::clicked,this,[=](){


        attempts++;

        unsigned int guess=ui->datainput->value();
        usernumber[0]=guess/1000;
        guess=guess-1000*usernumber[0];
        usernumber[1]=guess/100;
        guess=guess-100*usernumber[1];
        usernumber[2]=guess/10;
        guess=guess-10*usernumber[2];
        usernumber[3]=guess;


        Astate=0;
        Bstate=0;

        for(int k=0;k<4;k++){
            if(usernumber[k]==correctnumber[k]){
                Astate++;
            } else {
                for(int h=0;h<4;h++){
                    if(usernumber[k]==correctnumber[h]){
                        Bstate++;
                    }
                }

            }

        }

        if(Astate==4){
            QString num="🎉 Answer: "+QString::number(good);
            QString state="😊  "+QString::number(attempts)+" Attempts, 4 A 0 B";

            ui->number->setText(num);
            ui->state->setText(state);
            ui->ok->setEnabled(false);
        } else {
            QString state2="🤔  "+QString::number(attempts)+" Attempts, "+QString::number(Astate)+" A "+QString::number(Bstate)+" B";
            ui->state->setText(state2);

        }




    });













    numberset();






}

void Numerguess::numberset()
{

    correctnumber[0]=rand()%10;
    correctnumber[1]=rand()%10;
    correctnumber[2]=rand()%10;
    correctnumber[3]=rand()%10;

    good=correctnumber[0]*1000+correctnumber[1]*100+correctnumber[2]*10+correctnumber[3];
/*

    good=7859;
    correctnumber[0]=7;
    correctnumber[1]=8;
    correctnumber[2]=5;
    correctnumber[3]=9;
*/

    qDebug()<<good;


}

void Numerguess::correctornot()
{



}
void Numerguess::reset()
{

    setu->start(1000);

    ui->number->hide();
    ui->state->hide();
    ui->ok->setEnabled(true);

    numberset();

    QString state1="？ ？ ？ ？";
    QString state2="🤔  0 Attempts, 0 A 0 B";

    ui->state->setText(state2);
    ui->number->setText(state1);
}
void Numerguess::reflash()
{

    ui->number->show();
    ui->state->show();

    setu->stop();

    attempts=0;


}


Numerguess::~Numerguess()
{
    delete ui;
}
