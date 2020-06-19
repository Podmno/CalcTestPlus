#ifndef QUESTIONSET_H
#define QUESTIONSET_H
#include "template.h"
#include <QMainWindow>
#include "testprogram.h"
namespace Ui {
class Questionset;
}

class Questionset : public QMainWindow
{
    Q_OBJECT

public:
    explicit Questionset(QWidget *parent = nullptr);
    ~Questionset();

    TestProgram *tes;

    Template *tem;

    void type_helper(int h_questionnumbers,int h_questionmax,int h_questionmin,bool h_minus,bool h_points,bool h_type1,bool h_type2,bool h_type3,bool h_type4,int h_targetset,int h_timeset);

    QString boolhelper(bool);



public slots:
    void set_type1();
    void set_type2();
    void set_type3();
    void exitmenu();

private:
    Ui::Questionset *ui;

};

#endif // QUESTIONSET_H
