#include "makewave.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MakeWave w;
    w.show();

    return a.exec();
}
