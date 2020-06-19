#include "testfinish.h"
#include "ui_testfinish.h"

Testfinish::Testfinish(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Testfinish)
{
    ui->setupUi(this);

    setAttribute (Qt::WA_DeleteOnClose);

    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);


    connect(ui->commandLinkButton,&QPushButton::clicked,this,[=](){

        src=new Score;

        src->exec();



    });


}

void Testfinish::msg_accept()
{

    ui->score->setText(QString::number(en_score));

    int temprank=100-en_target;

    int rank_3rd=en_target+temprank/4;
    int rank_2nd=en_target+temprank/3;
    int rank_1st=en_target+temprank/2;

    if(en_target==en_score){
        ui->rank->setText("😂  勉勉强强通过测试！");
    }
    if(en_score>rank_3rd){
        ui->rank->setText("😊  不错不错！继续努力！");
    }
    if(en_score>rank_2nd){
        ui->rank->setText("😀  再努力一点点就完美了！");
    }
    if(en_score>rank_1st){
        ui->rank->setText("😁  很棒的成绩！");
    }
    if(en_score==100){
        ui->rank->setText("👏  恭喜满分！！！");
    }
    if(en_score<en_target){
        ui->rank->setText("😱  欸欸欸欸欸欸额欸欸欸欸？？？");
    }


    ui->timeuse->setText("使用时间："+QString::number(en_time)+" 秒");




}

Testfinish::~Testfinish()
{
    delete ui;
}
