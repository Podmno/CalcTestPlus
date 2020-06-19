#include "loadingdata.h"
#include "ui_loadingdata.h"

Loadingdata::Loadingdata(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Loadingdata)
{
    ui->setupUi(this);





}

void Loadingdata::loadingdata(int process,QString data)
{

    ui->loadingbar->setValue(process);
    ui->statereport->setText(data);

}

void Loadingdata::loadingdatabusy(QString data)
{
    ui->loadingbar->setMaximum(0);
    ui->loadingbar->setMinimum(0);
    ui->statereport->setText(data);
}

void Loadingdata::loadingdataback()
{
    ui->loadingbar->setMaximum(100);
    ui->loadingbar->setMinimum(0);
}

Loadingdata::~Loadingdata()
{
    delete ui;
}
