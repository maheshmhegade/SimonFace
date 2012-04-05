#ifndef SIMONFACE_H
#define SIMONFACE_H

#include <QMainWindow>
#include </usr/include/opencv/cv.h>
#include </usr/include/opencv/highgui.h>

namespace Ui {
    class SimonFace;
}

class SimonFace : public QMainWindow
{
    Q_OBJECT

public:
    explicit SimonFace(QWidget *parent = 0);
    ~SimonFace();
public slots:
  void SimonFaceDetection();
private:
    Ui::SimonFace *ui;
};

#endif // SIMONFACE_H
