#include "question.h"

Question::Question()
{





    /*
    qDebug()<<"There must be a number input.";
    */




   quelist=new Questionlist;
   qm_points=true;

}




Question::Question(int numbers,
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
            )
{

    //生成题目主体结构
    qm_numbers=numbers;
    qm_max=max;
    qm_min=min;
    qm_minus=minus;
    qm_points=points;
    qm_type1=type1;
    qm_type2=type2;
    qm_type3=type3;
    qm_type4=type4;
    qm_targetset=targetset;
    qm_timeset=timeset;

    qm_current=0;


    if(qm_points==false){
        quelist=new Questionlist[qm_numbers];
        qm_questioncreator();
    } else {
        quelistsp=new Questionlistsp[qm_numbers];
        qm_questioncreatorsp();
    }




}

void Question::qm_questioncreator()
{

    for(int k=0;k<qm_numbers;k++){

        int decide=qm_typecreator(qm_type1,qm_type2,qm_type3,qm_type4);

        if(decide==0){
            qm_calccreator1();
        }
        if(decide==1){
            qm_calccreator2();
        }
        if(decide==2){
            qm_calccreator3();
        }
        if(decide==3){
            qm_calccreator4();
        }

        qm_current++;

    }

}

void Question::qm_questioncreatorsp()
{

    for(int k=0;k<qm_numbers;k++){

        int decide=qm_typecreator(qm_type1,qm_type2,false,false);
        if(decide==0){
            qm_calccreatorsp1();
        }
        if(decide==1){
            qm_calccreatorsp2();
        }

        qm_current++;


    }




}

void Question::qm_calccreator1()
{
    quelist[qm_current].q_type=0;
    startpointcc1:
    int temp_num1;
    int temp_num2;
    int temp_answer;
    temp_num1=qm_numbercreator(qm_min,qm_max);
    temp_num2=qm_numbercreator(qm_min,qm_max);
    temp_answer=temp_num1+temp_num2;
    int decide=temp_num1+temp_num2;
    if(decide<qm_min||decide>qm_max){
        goto startpointcc1;
    }
    if(temp_num1==0||temp_num2==0){
        goto startpointcc1;
    }

    quelist[qm_current].q_num1=temp_num1;
    quelist[qm_current].q_num2=temp_num2;
    quelist[qm_current].q_answer=temp_answer;



}

void Question::qm_calccreator2()
{
    quelist[qm_current].q_type=1;
    startpointcc2:
    int temp_num1;
    int temp_num2;
    int temp_answer;
    temp_num1=qm_numbercreator(qm_min,qm_max);
    temp_num2=qm_numbercreator(qm_min,qm_max);
    temp_answer=temp_num1-temp_num2;
    int decide=temp_num1-temp_num2;
    if(decide<qm_min||decide>qm_max){
        goto startpointcc2;
    }
    if(temp_num1==0||temp_num2==0){
        goto startpointcc2;
    }

    quelist[qm_current].q_num1=temp_num1;
    quelist[qm_current].q_num2=temp_num2;
    quelist[qm_current].q_answer=temp_answer;




}

void Question::qm_calccreator3()
{
    quelist[qm_current].q_type=2;
    startpointcc3:
    int temp_num1;
    int temp_num2;
    int temp_answer;
    temp_num1=qm_numbercreator(qm_min,qm_max);
    temp_num2=qm_numbercreator(qm_min,qm_max);
    int decide=temp_num1*temp_num2;
    if(decide<qm_min||decide>qm_max){
        goto startpointcc3;
    }
    if(temp_num1==0||temp_num2==0||temp_num1==1||temp_num2==1){
        goto startpointcc3;
    }
    temp_answer=decide;

    quelist[qm_current].q_num1=temp_num1;
    quelist[qm_current].q_num2=temp_num2;
    quelist[qm_current].q_answer=temp_answer;




}

void Question::qm_calccreator4()
{

    quelist[qm_current].q_type=3;

    startpointcc4:
    int temp_num1;
    int temp_num2;
    int temp_answer;
    temp_num1=qm_numbercreator(qm_min,qm_max);
    temp_num2=qm_numbercreator(qm_min,qm_max);
    int decide=temp_num1*temp_num2;
    temp_answer=decide;
    if(decide<qm_min||decide>qm_max){
        goto startpointcc4;
    }
    if(temp_num2==0){
        goto startpointcc4;
    }
    if(temp_num1==0||temp_num2==0||temp_num1==1||temp_num2==1){
        goto startpointcc4;
    }

    quelist[qm_current].q_num1=temp_answer;
    quelist[qm_current].q_num2=temp_num2;
    quelist[qm_current].q_answer=temp_num1;



}

void Question::qm_calccreatorsp1()
{

    quelistsp[qm_current].q_type=0;

    float temp_num1;
    float temp_num2;
    float temp_answer;

    startpoint:
    temp_num1=qm_numbercreatorsp(qm_min,qm_max);
    temp_num2=qm_numbercreatorsp(qm_min,qm_max);
    temp_answer=temp_num1+temp_num2;
    if(temp_answer>qm_max||temp_answer<qm_min){
        goto startpoint;
    }

    quelistsp[qm_current].q_num1=temp_num1;
    quelistsp[qm_current].q_num2=temp_num2;
    quelistsp[qm_current].q_answer=temp_answer;


}

void Question::qm_calccreatorsp2()
{

    quelistsp[qm_current].q_type=1;

    float temp_num1;
    float temp_num2;
    float temp_answer;

    startpoint:
    temp_num1=qm_numbercreatorsp(qm_min,qm_max);
    temp_num2=qm_numbercreatorsp(qm_min,qm_max);
    temp_answer=temp_num1-temp_num2;
    if(temp_answer>qm_max||temp_answer<qm_min){
        goto startpoint;
    }

    quelistsp[qm_current].q_num1=temp_num1;
    quelistsp[qm_current].q_num2=temp_num2;
    quelistsp[qm_current].q_answer=temp_answer;


}

//传入最大数值，将会生成 min ~ max 的数字
int Question::qm_numbercreator(int min,int max)
{

    int result;

    ncstart:

    int t_max=max;
    int t_min=-min;
    int t_temp;
    if(t_max>t_min){
        t_temp=t_max;
    } else {
        t_temp=t_min;
    }

    t_temp++;

    result=rand()%t_temp;
    if(qm_minus==true){
        result=qm_minuscreator(result);
    }

    int t_result=-result;
    t_result=-t_result;

    bool decide=t_result<min||result>max;

    if(decide==true){
        goto ncstart;
    }

    return result;


}

//传入允许的类型，将会返回对应类型：0,1,2,3 对应加减乘除
int Question::qm_typecreator(bool type1,bool type2,bool type3,bool type4)
{

type_startpoint:
    int randtype=rand()%4;
    if(type1==false&&randtype==0){
        goto type_startpoint;
    }
    if(type2==false&&randtype==1){
        goto type_startpoint;
    }
    if(type3==false&&randtype==2){
        goto type_startpoint;
    }
    if(type4==false&&randtype==3){
        goto type_startpoint;
    }
    return randtype;

}

float Question::qm_numbercreatorsp(int min,int max)
{

    float result_1;
    float result_2;
    float finalresult;

    startpoint:

    result_1=qm_numbercreator(min,max);

    result_2=rand()%11;

    finalresult=result_1+(result_2/10);

    if(finalresult<qm_min||finalresult>qm_max){
        goto startpoint;
    }

    return finalresult;

}

//将传入的数字随机变成负数
int Question::qm_minuscreator(int number)
{
    int decide=rand()%2;
    if(decide==0){

    } else {
        number=-number;
    }
    return number;
}


Question::~Question()
{
    if(qm_points==false){
        delete[] quelist;
    }
    if(qm_points==true){
        delete[] quelistsp;
    }
}
