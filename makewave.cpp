#include "makewave.h"
#include "ui_makewave.h"
#include "tunenote.h"
#include "write_headers.h"

#include <sstream>

#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>

MakeWave::MakeWave(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MakeWave)
{
    ui->setupUi(this);

    ui->hzBox->setMinimum(20);
    ui->hzBox->setMaximum(20000);

    ui->msecBox->setMinimum(10);
    ui->msecBox->setMaximum(10000);
}

MakeWave::~MakeWave()
{
    delete ui;
}

void MakeWave::on_pushButton_clicked()
{
    int msec = ui->msecBox->value();
    double hz = ui->hzBox->value();

    std::ostringstream oss;
    oss << "wav-" << hz << "hz" << ".wav";
    QString defaultFname(oss.str().c_str());
    QString fileName = getFname(defaultFname);

    if (fileName.length() < 1)
        return;

    QFile file(fileName);
    file.open(QIODevice::ReadWrite);
    write_headers(file, msec, 44100);
    tune_note(file, msec, hz, 44100, 1.0);

    file.close();

    close();
}

QString MakeWave::getFname(QString defaultFname) {
    return QFileDialog::getSaveFileName(this, "Where to save?", defaultFname, "Wave File (*.wav)");
}
