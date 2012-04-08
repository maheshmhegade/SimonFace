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
    
    CvHaarClassifierCascade *cascade;
    
    CvMemStorage            *storage;
    
    CvCapture               *cameracapture; 
    
    char                    key;
    
    char                    *filename; 
    
    double                  brightnessvalue;
     
    explicit                SimonFace(QWidget *parent = 0);
    
    ~SimonFace();

public slots:

  void updateBrightness();
  
  void SimonFaceDetection();
  
  void StopExecution();
private:

  Ui::SimonFace *ui;
};

#endif // SIMONFACE_H
