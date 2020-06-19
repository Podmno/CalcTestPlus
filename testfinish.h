#ifndef TESTFINISH_H
#define TESTFINISH_H

#include <QDialog>
#include "score.h"

namespace Ui {
class Testfinish;
}

class Testfinish : public QDialog
{
    Q_OBJECT

public:
    explicit Testfinish(QWidget *parent = nullptr);

    ~Testfinish();

    int en_score;
    int en_target;
    int en_time;

    void msg_accept();

    Score* src;


private:
    Ui::Testfinish *ui;
};

#endif // TESTFINISH_H
