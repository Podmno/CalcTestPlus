#include "update.h"
#include "ui_update.h"
#include <QMessageBox>
Update::Update(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Update)
{
    ui->setupUi(this);

    setAttribute (Qt::WA_DeleteOnClose);

    ui->axWidget->dynamicCall("Navigate(const QString&)","https://tristudio.github.io/post/calctest-extraedition/");

    ui->btn->setVisible(false);

    timer=new QTimer;

    connect(timer,SIGNAL(timeout()),this,SLOT(setwaiting()));

    connect(ui->btn,&QPushButton::clicked,this,[=](){

        QMessageBox::information(this,"等待时间过长？","由于我们的服务器构架在 Github Pages 上，所以对于国内的访问有一定阻力。请麻烦您耐心等候。");


    });

    timer->start(15000);



}

void Update::setwaiting()
{

    timer->stop();

    ui->btn->setVisible(true);


}

Update::~Update()
{
    delete ui;
}
