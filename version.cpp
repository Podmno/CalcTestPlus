#include "version.h"
#include "ui_version.h"

Version::Version(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Version)
{
    ui->setupUi(this);

    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
}

Version::~Version()
{
    delete ui;
}
