#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    stopwatch = new Stopwatch(this);

    ui->puB_StartStop->setText("Старт");
    ui->puB_Circle->setText("Круг");
    ui->puB_Clear->setText("Очистить");

    ui->puB_StartStop->setCheckable(true);
    ui->puB_Circle->setEnabled(false);

    QObject::connect(stopwatch, &Stopwatch::sig_PrintStopwatch, this, &MainWindow::printLaBTime);
    QObject::connect(stopwatch, &Stopwatch::sig_Circle, this, &MainWindow::printTeBCircle);
    QObject::connect(this, &MainWindow::sig_startStopwatch, stopwatch, &Stopwatch::startCircle);
    QObject::connect(this, &MainWindow::sig_stopStopwatch, stopwatch, &Stopwatch::stopCircle);
    QObject::connect(this, &MainWindow::sig_circleStopwatch, stopwatch, &Stopwatch::circle);
    QObject::connect(this, &MainWindow::sig_crearStopwatch, stopwatch, &Stopwatch::crearStopwatch);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::printLaBTime(QString rcv) {

    ui->lab_Time->setText(rcv);
}

void MainWindow::printTeBCircle(QString rcv) {

    QString text = "Круг: " + QString::number(number) + ", время: " + rcv;
    number++;

    ui->teB_Circle->append(text);
}

void MainWindow::on_puB_StartStop_clicked() {

    if(ui->puB_StartStop->isChecked()) {

        emit sig_startStopwatch();

        ui->puB_StartStop->setText("Стоп");

        ui->puB_Circle->setEnabled(true);
        ui->puB_Clear->setEnabled(false);
    }
    else {

        emit sig_stopStopwatch();

        ui->puB_StartStop->setText("Старт");

        ui->puB_Circle->setEnabled(false);
        ui->puB_Clear->setEnabled(true);
    }
}

void MainWindow::on_puB_Circle_clicked() {

    emit sig_circleStopwatch();
}

void MainWindow::on_puB_Clear_clicked() {

    emit sig_crearStopwatch();

    ui->teB_Circle->clear();
    ui->lab_Time->setText("00:00:00.000");

    number = 1;
}
