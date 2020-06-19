#ifndef LOADINGDATA_H
#define LOADINGDATA_H

#include <QDialog>

namespace Ui {
class Loadingdata;
}

class Loadingdata : public QDialog
{
    Q_OBJECT

public:
    explicit Loadingdata(QWidget *parent = nullptr);
    ~Loadingdata();

    void loadingdata(int process,QString data);
    void loadingdatabusy(QString data);
    void loadingdataback();


private:
    Ui::Loadingdata *ui;
};

#endif // LOADINGDATA_H
