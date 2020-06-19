#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "about.h"

#include "question.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    filereadmode=true;
    fileread();


    connect(ui->commandLinkButton_3,&QPushButton::clicked,this,[=](){
        src=new Score;

        src->exec();



    });


    connect(ui->commandLinkButton_4,&QPushButton::clicked,this,[=](){

        About *dlg = new About;
        dlg->exec();

    });

    connect(ui->commandLinkButton,&QPushButton::clicked,this,[=](){



        QString datawrite;
        datawrite="10 50 0 false false true true false false 60 0";


        QFile* fil=new QFile("C:/CalcTest Files/Questiondata.quesdat");

        if(!fil->exists()){
            fil->open(QIODevice::ReadWrite|QIODevice::Text);

        }

        fil->open(QIODevice::WriteOnly|QIODevice::Text);

        fil->write(datawrite.toUtf8());

        fil->close();



        tes=new TestProgram(this);

        tes->t_timeset=0;
        tes->t_numbers=10;
        tes->t_max=50;
        tes->t_min=0;
        tes->t_minus=false;
        tes->t_points=false;
        tes->t_type1=true;
        tes->t_type2=true;
        tes->t_type3=false;
        tes->t_type4=false;
        tes->t_targetset=60;




        tes->t_dataset();
        tes->show();



        this->hide();


    });

    connect(ui->commandLinkButton_2,&QPushButton::clicked,this,[=](){

        queset = new Questionset(this);

        queset->show();

        this->hide();




    });


    connect(ui->littlegame,&QPushButton::clicked,this,[=](){


        numg=new Numerguess(this);


        numg->show();

        this->hide();



    });


    connect(ui->lasttest,&QPushButton::clicked,this,[=](){

        tes=new TestProgram(this);

        que_timeset=que_timeset*1000;

        tes->t_numbers=que_numbers;
        tes->t_max=que_max;
        tes->t_min=que_min;
        tes->t_minus=que_minus;
        tes->t_points=que_points;
        tes->t_type1=que_type1;
        tes->t_type2=que_type2;
        tes->t_type3=que_type3;
        tes->t_type4=que_type4;
        tes->t_targetset=que_targetset;
        tes->t_timeset=que_timeset;

        tes->t_dataset();

        tes->show();

        this->hide();



    });



}

void MainWindow::trannormal()
{

}

void MainWindow::fileread()
{
    QDir* dir=new QDir();

    QString path="C:/CalcTest Files";

    if(!dir->exists(path)){

        bool res = dir->mkpath(path);
        if(res==false){
            QMessageBox::critical(this,"错误代码：E01","应用程序无法创建题目归档文件，所有的与题目保存有关的功能将可能无法正常运行，请检查磁盘卷标及磁盘是否允许程序读取。",QMessageBox::Ok);
            filereadmode=false;
        }

    }

    if(filereadmode==true){

    QFile* fil=new QFile("C:/CalcTest Files/Questiondata.quesdat");


    if(!fil->exists()){
        fil->open(QIODevice::ReadWrite|QIODevice::Text);
        fil->close();

    } else{

            ui->lasttest->setEnabled(true);



           fil->open(QIODevice::ReadWrite|QIODevice::Text);

           QByteArray t=fil->readAll();

           QString lastdata=QString(t);

           QStringList strlist=lastdata.split(" ");

           que_numbers=strlist[0].toInt();

           que_max=strlist[1].toInt();

           que_min=strlist[2].toInt();

           que_minus=typehelper(strlist[3]);

           que_points=typehelper(strlist[4]);

           que_type1=typehelper(strlist[5]);

           que_type2=typehelper(strlist[6]);

           que_type3=typehelper(strlist[7]);

           que_type4=typehelper(strlist[8]);

           que_targetset=strlist[9].toInt();

           que_timeset=strlist[10].toInt();









    }


}

}

bool MainWindow::typehelper(QString ls)
{
    if(ls=="true"){
        return true;
    } else {
        return false;
    }



}

void MainWindow::exitmenu()
{

    tes->hide();
    this->show();

}

void MainWindow::goodnight()
{

    numg->hide();

    this->show();


}

void MainWindow::backmenu()
{

    queset->hide();

    this->show();

}


MainWindow::~MainWindow()
{
    delete ui;
}


