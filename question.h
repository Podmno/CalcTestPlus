#ifndef QUESTION_H
#define QUESTION_H

#include <QDebug>
#include <ctime>
#include <stdlib.h>

struct Questionlist
{
    int q_num1;
    int q_type;
    int q_num2;
    int q_answer;
};

struct Questionlistsp
{
    float q_num1;
    int q_type;
    float q_num2;
    float q_answer;
};


class Question{
    public:

    Questionlist* quelist;
    Questionlistsp* quelistsp;

    int qm_numbers;
    int qm_max;
    int qm_min;
    bool qm_minus;
    bool qm_points;
    bool qm_type1;
    bool qm_type2;
    bool qm_type3;
    bool qm_type4;
    int qm_targetset;
    int qm_timeset;

    int qm_current;

    void qm_questioncreator();
    void qm_questioncreatorsp();

    int qm_numbercreator(int min,int max);
    int qm_typecreator(bool type1,bool type2,bool type3,bool type4);
    int qm_minuscreator(int number);

    float qm_numbercreatorsp(int min,int max);

    void qm_calccreator1();
    void qm_calccreator2();
    void qm_calccreator3();
    void qm_calccreator4();

    void qm_calccreatorsp1();
    void qm_calccreatorsp2();

    Question();
    Question(int numbers,
             int max,
             int min,
             bool minus,
             bool points,
             bool type1,
             bool type2,
             bool type3,
             bool type4,
             int targetset,
             int timeset
            );
    ~Question();
};
#endif // QUESTION_H
