
#include "makewave.h"
#include "tunenote.h"
#include "ui_makewave.h"

#include <stdio.h>
#include <stdlib.h>

#include <QString>
#include <QFile>
#include <QIODevice>
#include <QDataStream>
#include <QDebug>

void write_headers(QFile& outfile, int dur, double srate) {

    const qint16      BitsPerSample   = 16;

    //RIFF header
    const QString     ChunkID         = "RIFF";
    const qint32      ChunkSize       = 36 + (srate/1000.0*dur*BitsPerSample/8);
    const QString     Format          = "WAVE";

    //fmt section
    const QString     Subchunk1ID     = "fmt ";
    const qint32      Subchunk1Size   = 16;
    const qint16      AudioFormat     = 1;
    const qint16      NumChannels     = 1;
    const qint32      SampleRate      = 44100;
    const qint32      ByteRate        = (SampleRate*NumChannels*BitsPerSample/8);
    const qint16      BlockAlign      = (NumChannels*BitsPerSample/8);

    //data
    const QString     Subchunk2ID     = "data";
    const qint32      Subchunk2Size   = (srate/1000.0*dur*BitsPerSample/8);

    QByteArray w;
    w.append(ChunkID.toLatin1());
    w.append((char*)&ChunkSize,     sizeof(ChunkSize));
    w.append(Format.toLatin1());

    w.append(Subchunk1ID.toLatin1());
    w.append((char*)&Subchunk1Size, sizeof(Subchunk1Size));
    w.append((char*)&AudioFormat,   sizeof(AudioFormat));
    w.append((char*)&NumChannels,   sizeof(NumChannels));
    w.append((char*)&SampleRate,    sizeof(SampleRate));
    w.append((char*)&ByteRate,      sizeof(ByteRate));
    w.append((char*)&BlockAlign,    sizeof(BlockAlign));
    w.append((char*)&BitsPerSample, sizeof(BitsPerSample));

    w.append(Subchunk2ID.toLatin1());
    w.append((char*)&Subchunk2Size, sizeof(Subchunk2Size));

    outfile.write(w);
}
