#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
   Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

    void sig_startStopwatch(void);
    void sig_stopStopwatch(void);
    void sig_circleStopwatch(void);
    void sig_crearStopwatch(void);

private slots:

    void printLaBTime(QString rcv);
    void printTeBCircle(QString rcv);
    void on_puB_StartStop_clicked();
    void on_puB_Circle_clicked();
    void on_puB_Clear_clicked();

private:

    Ui::MainWindow *ui;
    Stopwatch *stopwatch;

    int number = 1;
};

#endif // MAINWINDOW_H
