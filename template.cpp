#include "template.h"
#include "ui_template.h"
#include <QPushButton>
Template::Template(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Template)
{
    ui->setupUi(this);

    setAttribute (Qt::WA_DeleteOnClose);
   connect(ui->type1,SIGNAL(clicked()),parent,SLOT(set_type1()));
   connect(ui->type2,SIGNAL(clicked()),parent,SLOT(set_type2()));
   connect(ui->type3,SIGNAL(clicked()),parent,SLOT(set_type3()));

}





Template::~Template()
{
    delete ui;
}
