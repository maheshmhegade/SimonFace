#ifndef SIMONFACE_H
#define SIMONFACE_H

#include <QMainWindow>

namespace Ui {
    class SimonFace;
}

class SimonFace : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimonFace(QWidget *parent = 0);
    ~SimonFace();

private:
    Ui::SimonFace *ui;
};

#endif // SIMONFACE_H
