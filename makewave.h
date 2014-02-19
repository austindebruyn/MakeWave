#ifndef MAKEWAVE_H
#define MAKEWAVE_H

#include <QMainWindow>
#include <iostream>

namespace Ui {
class MakeWave;
}

class MakeWave : public QMainWindow
{
    Q_OBJECT

public:
    explicit MakeWave(QWidget *parent = 0);
    ~MakeWave();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MakeWave *ui;
    QString getFname(QString defaultFname);
};

#endif // MAKEWAVE_H
