#include "questionset.h"
#include "ui_questionset.h"

#include <QMessageBox>
#include <QFile>
Questionset::Questionset(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Questionset)
{
    ui->setupUi(this);

    setAttribute (Qt::WA_DeleteOnClose);


    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);



    ui->questionmax->setValue(50);
    ui->type1->setChecked(true);
    ui->type2->setChecked(true);


    connect(ui->points,&QCheckBox::stateChanged,this,[=](int state){
        if(state==0){

            ui->type3->setEnabled(true);
            ui->type4->setEnabled(true);
        }
        if(state==2){
            ui->type3->setChecked(false);
            ui->type4->setChecked(false);

            ui->type3->setEnabled(false);
            ui->type4->setEnabled(false);

        }


    });

    connect(ui->backmenu,SIGNAL(clicked()),parent,SLOT(backmenu()));

    connect(ui->minus,&QCheckBox::stateChanged,this,[=](int state){
        if(state==0){
            ui->questionmin->setValue(0);
            ui->questionmin->setEnabled(false);
        } else {
            ui->questionmin->setEnabled(true);
        }

    });


    connect(ui->startbuttom_2,&QPushButton::clicked,this,[=](){


        tem=new Template(this);
        tem->exec();

    });




    connect(ui->startbuttom,&QPushButton::clicked,this,[=](){

        int numbers = ui->questionnumbers->value();
        int target = ui->targetset->value();

        int depart=100%numbers;

        bool whether_go;

        int t_1stscore=100/numbers;

        int maxscore=t_1stscore*numbers;


        bool check=ui->type1->isChecked();
        qDebug()<<check;

        if(depart!=0){
            QApplication::beep();
            if(QMessageBox::Ok == QMessageBox::critical(this,"警告","你指定的题目个数将导致分数无法被平等分配到每一道题目。这样将会使题目的总分不为 100 分。请问你确定要这样操作吗？",QMessageBox::Ok|QMessageBox::Cancel)){
                whether_go=true;
            } else{
                whether_go=false;
            }

        } else{
            whether_go=true;
        }

        if(maxscore<target){
            QApplication::beep();
            QMessageBox::critical(this,"警告","不能设定比理论总分还要高的目标分数。请调整目标分数后再试。");
            whether_go=false;
        }






        int ques_numbers=ui->questionnumbers->value();
        int ques_max=ui->questionmax->value();
        int ques_min=ui->questionmin->value();
        bool ques_minus=ui->minus->isChecked();
        bool ques_points=ui->points->isChecked();
        bool ques_type1=ui->type1->isChecked();
        bool ques_type2=ui->type2->isChecked();
        bool ques_type3=ui->type3->isChecked();
        bool ques_type4=ui->type4->isChecked();
        int ques_targetset=ui->targetset->value();
        int ques_timeset=ui->timeset->value();

        if(ques_type1==false&&ques_type2==false&&ques_type3==false&&ques_type4==false){


            QApplication::beep();
            QMessageBox::critical(this,"警告","请至少选择一种算法。");
            whether_go=false;
        }

        if(ques_min>=ques_max){


            QApplication::beep();
            QMessageBox::critical(this,"警告","不能设定题目的最小值大于或等于最大值。");
            whether_go=false;
        }



        if(whether_go==true){



       QString datawrite;
       datawrite=QString::number(ques_numbers)+" "+QString::number(ques_max)+" "+QString::number(ques_min)+" "+boolhelper(ques_minus)+" "+boolhelper(ques_points)+" "+boolhelper(ques_type1)+" "+boolhelper(ques_type2)+" "+boolhelper(ques_type3)+" "+boolhelper(ques_type4)+" "+QString::number(ques_targetset)+" "+QString::number(ques_timeset);


       QFile* fil=new QFile("C:/CalcTest Files/Questiondata.quesdat");

       if(!fil->exists()){
           fil->open(QIODevice::ReadWrite|QIODevice::Text);

       }

       fil->open(QIODevice::WriteOnly|QIODevice::Text);

       fil->write(datawrite.toUtf8());

       fil->close();





        tes=new TestProgram(this);



      ques_timeset=ques_timeset*1000;
      tes->t_numbers=ques_numbers;
      tes->t_max=ques_max;
      tes->t_min=ques_min;
      tes->t_minus=ques_minus;
      tes->t_points=ques_points;
      tes->t_type1=ques_type1;
      tes->t_type2=ques_type2;
      tes->t_type3=ques_type3;
      tes->t_type4=ques_type4;
      tes->t_targetset=ques_targetset;
      tes->t_timeset=ques_timeset;













      tes->t_dataset();













        tes->show();



















        this->hide();

}


    });

}

void Questionset::exitmenu()
{
    tes->hide();
    this->show();
}

void Questionset::set_type1()
{

    type_helper(10,50,0,false,false,true,true,false,false,60,0);
    tem->close();

}

void Questionset::set_type2()
{
    type_helper(10,100,-100,true,true,true,true,false,false,60,0);
    tem->close();
}

void Questionset::set_type3()
{
    type_helper(50,100,-100,true,false,true,true,true,true,90,60);
    tem->close();
}

void Questionset::type_helper(int h_questionnumbers,int h_questionmax,int h_questionmin,bool h_minus,bool h_points,bool h_type1,bool h_type2,bool h_type3,bool h_type4,int h_targetset,int h_timeset)
{

    ui->questionnumbers->setValue(h_questionnumbers);
    ui->questionmax->setValue(h_questionmax);
    ui->questionmin->setValue(h_questionmin);
    ui->minus->setChecked(h_minus);
    ui->points->setChecked(h_points);
    ui->type1->setChecked(h_type1);
    ui->type2->setChecked(h_type2);
    ui->type3->setChecked(h_type3);
    ui->type4->setChecked(h_type4);
    ui->targetset->setValue(h_targetset);
    ui->timeset->setValue(h_timeset);


    int state1=ui->points->checkState();

    if(state1==0){

        ui->type3->setEnabled(true);
        ui->type4->setEnabled(true);
    } else{
        ui->type3->setChecked(false);
        ui->type4->setChecked(false);
        ui->type3->setEnabled(false);
        ui->type4->setEnabled(false);

    }

    int state2=ui->minus->checkState();

    if(state2==0){
        ui->questionmin->setValue(0);
        ui->questionmin->setEnabled(false);
    } else {
        ui->questionmin->setEnabled(true);
    }




}





QString Questionset::boolhelper(bool sth)
{
    QString data;
    if(sth==true){
        data="true";
    } else {
        data="false";
    }
    return data;
}

Questionset::~Questionset()
{
    delete ui;
}


