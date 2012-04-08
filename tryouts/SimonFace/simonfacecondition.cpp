#include "simonfacecondition.h"
#include "ui_createsimonfaceconditionwidget.h"
#include <QtGui>

SimonFace::SimonFace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonFace)
{
    ui->setupUi(this);
    
    connect(ui->pbCameraCalibration, SIGNAL(clicked()), this, SLOT(SimonFaceDetection()));
    
    connect(ui->BrightnessAdjust, SIGNAL(valueChanged(int)),this, SLOT(updateBrightness()));

    connect(ui->pbCancelButton, SIGNAL(clicked()), this, SLOT(StopExecution()));
}

SimonFace::~SimonFace()
{
  delete ui;
}
void SimonFace::SimonFaceDetection(){
    filename= "/usr/share/kde4/apps/libkface/haarcascades/haarcascade_frontalface_alt.xml";
    
    cascade = ( CvHaarClassifierCascade* )cvLoad( filename, 0, 0, 0 );
    
    storage = cvCreateMemStorage( 0 );
    
    cameracapture = cvCaptureFromCAM(0);
    
    assert( cascade && storage && cameracapture );
    
    key = true;  
    
    while( key == true ) {
       
      IplImage* frame = cvQueryFrame(cameracapture);
      
      if( !frame ) break;
      
      cvCvtColor(frame,frame,CV_BGR2RGB);
      
      QImage image = QImage((uchar *)frame->imageData, frame->width, frame->height, QImage::Format_RGB888);
      
      QGraphicsScene* scene = new QGraphicsScene(this);
      
      QPixmap tempimage=QPixmap::fromImage(image);
      
      QPixmap *backgroundPixmap = &tempimage;
      
      QPixmap sized = backgroundPixmap->scaled(QSize(ui->graphicsView_2->width(),ui->graphicsView_2->height()),Qt::KeepAspectRatioByExpanding);
      
      QImage sizedImage = QImage(sized.toImage());
      
      ui->graphicsView_2->setScene(scene);
      
      cvWaitKey(1);
    }
        
    cvReleaseCapture( &cameracapture );
    
    cvReleaseHaarClassifierCascade( &cascade );
    
    cvReleaseMemStorage( &storage );  
    
 return;
}
void SimonFace::updateBrightness()
{
    brightnessvalue = (ui->BrightnessAdjust->value())/100.00;
    
    cvSetCaptureProperty(cameracapture, CV_CAP_PROP_BRIGHTNESS,brightnessvalue);
}
void SimonFace::StopExecution(){
  key = false; 
}