#include "about.h"
#include "ui_about.h"

#include "version.h"

#include <QMessageBox>

#include <QDesktopServices>
#include <QUrl>
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);







}

About::~About()
{
    delete ui;
}
