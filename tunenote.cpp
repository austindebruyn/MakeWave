#include "makewave.h"
#include "tunenote.h"
#include "ui_makewave.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QDebug>

#ifndef M_PI
#define M_PI (3.141592654)
#endif

int tune_note(QFile& outfile, int dur, double freq, double srate, double amp) {

    qint32 i, nsamps;
    double samp;
    double start, end, fac, angleincr;
    double twopi = 2.0*M_PI;
    qint16 toPCM;


    //TODO: test above

    nsamps = (int)(dur/1000.0*srate);
    angleincr = twopi*freq/ srate;
    float fsamp;

    qDebug() << "Number of samples: " << nsamps << endl;

    start = 1.0;
    end = 1.0e-4; //-80dB
    fac = pow(end/start,1.0/nsamps);

    for (i=0; i<nsamps; i++) {
        samp = amp* sin(angleincr*i);
        samp *= start;
        start *= fac;
        fsamp = (float)samp*32768;

        toPCM = fsamp;

        QByteArray w;
        w.append( (char*)&toPCM, sizeof(toPCM));
        outfile.write(w);
    }

    outfile.close();
    return 0;
}
