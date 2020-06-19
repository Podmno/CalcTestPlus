#include "testprogram.h"
#include "ui_testprogram.h"
#include <QMessageBox>
#include "loadingdata.h"
TestProgram::TestProgram(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestProgram)
{
    ui->setupUi(this);
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    setAttribute (Qt::WA_DeleteOnClose);

    srand((int)time(NULL));

    ui->tui_end->hide();
    ui->tui_userinputsp->hide();


    timelimit=new QTimer(this);
    timecount=new QTimer(this);



    connect(ui->tui_handin,SIGNAL(clicked()),this,SLOT(t_userhandin()));
    connect(ui->tui_start,SIGNAL(clicked()),this,SLOT(t_setstart()));
    connect(timecount,SIGNAL(timeout()),this,SLOT(t_timeupdate()));
    connect(timelimit,SIGNAL(timeout()),this,SLOT(t_timeend()));
    connect(ui->tui_exit,SIGNAL(clicked()),parent,SLOT(exitmenu()));
    connect(ui->tui_restart,SIGNAL(clicked()),this,SLOT(t_restart()));
    connect(ui->tui_end,&QPushButton::clicked,this,[=](){

        fin=new Testfinish;

        fin->en_score=t_userscore;
        int usertimeuse;

        if(t_timesettings==false){
            usertimeuse=ui->tui_timeset->value();
        } else {
            usertimeuse=t_timeset/1000;
            usertimeuse=usertimeuse-ui->tui_timeset->value();

        }
        fin->en_time=usertimeuse;
        fin->en_target=t_targetset;

        fin->msg_accept();

        fin->show();

        this->hide();


    });

    t_userchance=3;
    t_userscore=0;
    t_current=0;
    t_trynumber=0;
    t_passed=false;

}

void TestProgram::t_setstart()
{

    if(t_timeset==0){
        t_timesettings=false;
        t_timecounton();
    } else {
        t_timesettings=true;
        t_timelimiton();
    }


    ui->tui_start->setEnabled(false);
    ui->tui_exit->setEnabled(false);
    ui->tui_end->setEnabled(false);

    ui->tui_userinput->setEnabled(true);
    ui->tui_userinputsp->setEnabled(true);
    ui->tui_handin->setEnabled(true);

    ui->tui_datadisplay->setText("🤔  现在开始测试。请在方框内填入你的答案，选择 提交 (Enter) 以提交答案。");

    ui->tui_handin->setShortcut(QKeySequence::InsertParagraphSeparator);
    ui->tui_handin->setShortcut(Qt::Key_Enter);
    ui->tui_handin->setShortcut(Qt::Key_Return);

    t_questionset();

}

void TestProgram::t_timecounton()
{



    t_currenttime=0;



    ui->tui_timeset->display(t_currenttime);



    timecount->start(1000);



}

void TestProgram::t_timelimiton()
{
    t_timecounter=t_timeset+1000;
    timelimit->start(t_timecounter);

    t_currenttime=t_timeset/1000;

    ui->tui_timeset->display(t_currenttime);


    timecount->start(1000);


}

void TestProgram::t_dataset()
{

    if(t_timeset==0){
        ui->text_3->setText("已用时间：");
    } else {
        ui->text_3->setText("剩余时间：");
    }

    ui->tui_timeset->display(t_timeset/1000);

    if(t_points==true){
           ui->tui_userinput->hide();
           ui->tui_userinputsp->show();
    }

    ui->tui_target->display(t_targetset);
    ui->tui_score->display(t_userscore);
    ui->tui_restart->setEnabled(false);

    ui->tui_userinput->setEnabled(false);
    ui->tui_userinputsp->setEnabled(false);
    ui->tui_handin->setEnabled(false);

    queindex=new Question(t_numbers,t_max,t_min,t_minus,t_points,t_type1,t_type2,t_type3,t_type4,t_targetset,t_timeset);

    t_1stscore=100/t_numbers;
    t_3rdscore=t_1stscore/2;
    t_2ndscore=t_3rdscore+(t_1stscore-t_3rdscore)/2;


}

void TestProgram::t_questionset()
{


    if(t_current==t_numbers){
        t_setend();
        return;
    }

    QString questionbar;
    QString questioncontent;

    if(t_points==false){

        ui->tui_userinput->setFocus();

        questionbar="第 "+QString::number(t_current+1)+" 题 / 共 "+QString::number(t_numbers)+" 题";
        questioncontent=QString::number(queindex->quelist[t_current].q_num1);
        if(queindex->quelist[t_current].q_type==0){
            questioncontent=questioncontent+" + ";
        }
        if(queindex->quelist[t_current].q_type==1){
            questioncontent=questioncontent+" - ";
        }
        if(queindex->quelist[t_current].q_type==2){
            questioncontent=questioncontent+" × ";
        }
        if(queindex->quelist[t_current].q_type==3){
            questioncontent=questioncontent+" ÷ ";
        }

        if(queindex->quelist[t_current].q_num2>0){

        questioncontent=questioncontent+QString::number(queindex->quelist[t_current].q_num2);
        } else {
        questioncontent=questioncontent+"("+QString::number(queindex->quelist[t_current].q_num2)+")";
        }
    }

    if(t_points==true){

        ui->tui_userinputsp->setFocus();

        questionbar="第 "+QString::number(t_current+1)+" 题 / 共 "+QString::number(t_numbers)+" 题";
        questioncontent=QString::number(queindex->quelistsp[t_current].q_num1);
        qDebug()<<queindex->quelistsp[t_current].q_num1;
        if(queindex->quelistsp[t_current].q_type==0){
            questioncontent=questioncontent+" + ";
            qDebug()<<"+";
        }
        if(queindex->quelistsp[t_current].q_type==1){
            questioncontent=questioncontent+" - ";
            qDebug()<<"-";
        }

        questioncontent=questioncontent+QString::number(queindex->quelistsp[t_current].q_num2);
        qDebug()<<queindex->quelistsp[t_current].q_num2;
        qDebug()<<queindex->quelistsp[t_current].q_answer;


    }

    questioncontent=questioncontent+" = ？";


    ui->tui_state->setText(questionbar);
    ui->tui_question->setText(questioncontent);


}

void TestProgram::t_userhandin()
{




if(t_points==false){

    int userresult=ui->tui_userinput->value();

    bool decide=(userresult==queindex->quelist[t_current].q_answer);

    if(t_userchance==3)
    {
        if(decide){
            t_userscore+=t_1stscore;
            t_userchance=3;
            ui->tui_datadisplay->setText("😁  回答正确！你获得 "+QString::number(t_1stscore)+" 分！");
            t_current++;
            t_questionset();
            t_scoreflash();
            ui->tui_userinput->setValue(0);
        } else {
            QApplication::beep();
            ui->tui_datadisplay->setText("<font color=red>😟  回答错误！你还有 2 次机会！</font>");
            t_userchance--;
            ui->tui_userinput->setValue(0);
            return;
        }

     }

     if(t_userchance==2){
         if(decide){
             t_userscore+=t_2ndscore;
             t_userchance=3;
             ui->tui_datadisplay->setText("😊  回答正确！你获得 "+QString::number(t_2ndscore)+" 分！");
             t_current++;
             t_questionset();
             t_scoreflash();
             ui->tui_userinput->setValue(0);
         } else {
             QApplication::beep();
             ui->tui_datadisplay->setText("<font color=red>😢  回答错误！你还有 1 次机会！</font>");
             t_userchance--;
             ui->tui_userinput->setValue(0);
             return;
         }

     }

     if(t_userchance==1){
         if(decide){
             t_userscore+=t_3rdscore;
             t_userchance=3;
             ui->tui_datadisplay->setText("🙂  回答正确！你获得 "+QString::number(t_3rdscore)+" 分！");
             t_current++;
             t_questionset();
             t_scoreflash();
             ui->tui_userinput->setValue(0);
         } else {
             QApplication::beep();
             ui->tui_datadisplay->setText("<font color=red>😈  遗憾！所有的机会用尽，请回答下一道题。</font>");
             t_current++;
             t_userchance=3;
             t_questionset();
             ui->tui_userinput->setValue(0);
         }

     }




}


if(t_points==true){





    float userin=ui->tui_userinputsp->value();

    bool decide=qFuzzyCompare(userin,queindex->quelistsp[t_current].q_answer);

    qDebug()<<"My Decision"<<decide;

    if(t_userchance==3)
    {

        if(decide){
            t_userscore+=t_1stscore;
            t_userchance=3;
            ui->tui_datadisplay->setText("😁  回答正确！你获得 "+QString::number(t_1stscore)+" 分！");
            t_current++;
            t_questionset();
            t_scoreflash();
            ui->tui_userinputsp->setValue(0.0);
        } else {
            QApplication::beep();
            ui->tui_datadisplay->setText("<font color=red>😟  回答错误！你还有 2 次机会！</font>");
            t_userchance--;
            ui->tui_userinputsp->setValue(0.0);
            return;
        }

     }

     if(t_userchance==2){
         if(decide){
             t_userscore+=t_2ndscore;
             t_userchance=3;
             ui->tui_datadisplay->setText("😊  回答正确！你获得 "+QString::number(t_2ndscore)+" 分！");
             t_current++;
             t_questionset();
             t_scoreflash();
             ui->tui_userinputsp->setValue(0.0);
         } else {
             QApplication::beep();
             ui->tui_datadisplay->setText("<font color=red>😢  回答错误！你还有 1 次机会！</font>");
             t_userchance--;
             ui->tui_userinputsp->setValue(0.0);
             return;
         }

     }

     if(t_userchance==1){
         if(decide){
             t_userscore+=t_3rdscore;
             t_userchance=3;
             ui->tui_datadisplay->setText("🙂  回答正确！你获得 "+QString::number(t_3rdscore)+" 分！");
             t_current++;
             t_questionset();
             t_scoreflash();
             ui->tui_userinputsp->setValue(0.0);
         } else {
             QApplication::beep();
             ui->tui_datadisplay->setText("<font color=red>😈  遗憾！所有的机会用尽，请回答下一道题。</font>");
             t_current++;
             t_userchance=3;
             t_questionset();
             ui->tui_userinputsp->setValue(0.0);
         }

     }





}

}

void TestProgram::t_restart()
{

    if(QMessageBox::Ok==QMessageBox::warning(this,"注意","确定要回复到做题前的状态吗？你所做的题目信息将不会被保存。",QMessageBox::Ok|QMessageBox::Cancel)){

        t_dataset();

        t_userscore=0;
        t_userchance=3;
        t_current=0;

        ui->tui_end->hide();
        ui->tui_start->show();
        ui->tui_start->setEnabled(true);

        ui->tui_state->setText("就绪");
        ui->tui_question->setText("点击 开始测试 (S) 以开始再一轮的测试。");
        ui->tui_datadisplay->setText("💪  再挑战一次！你一定可以通过测试！");

        if(t_passed==true){
            ui->tui_datadisplay->setText("💪  再挑战一次！取得更好的成绩！");
        }

        t_passed=false;


    }


}


void TestProgram::t_timeupdate()
{

    if(t_timesettings==false){
        t_currenttime++;
        ui->tui_timeset->display(t_currenttime);

    } else {

        t_currenttime--;
        ui->tui_timeset->display(t_currenttime);


    }


}

void TestProgram::t_timeend()
{

    timelimit->stop();
    timecount->stop();
    QMessageBox::critical(this,"时间到！","限定的时间已经结束，你将不能继续答题。");
    t_scoreflash();
    t_setend();
}

void TestProgram::t_setend()
{
    timelimit->stop();
    timecount->stop();

    ui->tui_state->setText("测试结束。");
    ui->tui_question->setText("已经没有题目可供回答了。");
    ui->tui_userinput->setEnabled(false);
    ui->tui_handin->setEnabled(false);
    ui->tui_userinputsp->setEnabled(false);

    t_scoreflash();

    ui->tui_start->hide();
    ui->tui_end->show();

    ui->tui_exit->setEnabled(true);
    ui->tui_restart->setEnabled(true);

    if(t_userscore>=t_targetset){
        ui->tui_end->setEnabled(true);
        ui->tui_datadisplay->setText("😄  恭喜你通过了测试！");
        t_passed=true;

    } else {
        ui->tui_datadisplay->setText("😭  很遗憾，你没有及格！请再试一次吧！");
        t_trynumber++;
    }

}


void TestProgram::closeEvent(QCloseEvent *event)
{
    QMessageBox::critical(this,"警告","测试页面不能被强行关闭！");

    event->ignore();

}

void TestProgram::t_scoreflash()
{
    ui->tui_score->display(t_userscore);
}

TestProgram::~TestProgram()
{
    delete ui;
}


