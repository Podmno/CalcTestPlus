#ifndef UPDATE_H
#define UPDATE_H

#include <QWidget>
#include <QTimer>
namespace Ui {
class Update;
}

class Update : public QWidget
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();
    QTimer* timer;

public slots:
    void setwaiting();

private:
    Ui::Update *ui;
};

#endif // UPDATE_H
