#include "score.h"
#include "ui_score.h"
#include <QMessageBox>
Score::Score(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Score)
{
    ui->setupUi(this);
this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    setAttribute (Qt::WA_DeleteOnClose);

    QDir* dir=new QDir();

    QString path="C:/CalcTest Files";

    if(!dir->exists(path)){

        dir->mkpath(path);

    }



    QFile* fil=new QFile("C:/CalcTest Files/Scoredata.quesdat");

    fil->open(QIODevice::ReadWrite|QIODevice::Text);

    QByteArray t=fil->readAll();

    QString lastdata=QString(t);

    ui->textEdit->setText(lastdata);

    fil->close();

    connect(ui->pushButton_2,&QPushButton::clicked,this,[=](){

        QString datas=ui->textEdit->toPlainText();

        if(!fil->exists()){
            fil->open(QIODevice::ReadWrite|QIODevice::Text);

        }

        fil->open(QIODevice::WriteOnly|QIODevice::Text);

        fil->write(datas.toUtf8());

        fil->close();

        ui->label->setText("保存完成！");



    });

}

Score::~Score()
{
    delete ui;
}
