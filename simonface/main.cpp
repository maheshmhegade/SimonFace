#include <QtGui/QApplication>
#include "simonface.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SimonFace w;
    w.show();

    return a.exec();
}
