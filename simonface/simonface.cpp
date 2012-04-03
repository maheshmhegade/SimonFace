#include "simonface.h"
#include "ui_simonface.h"

SimonFace::SimonFace(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SimonFace)
{
    ui->setupUi(this);
}

SimonFace::~SimonFace()
{
    delete ui;
}
