#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
#include <QTime>

class Stopwatch : public QObject {

    Q_OBJECT

public:

    explicit Stopwatch(QObject *parent = nullptr);

signals:

    void sig_PrintStopwatch(QString rbv);
    void sig_Circle(QString rbv);

protected:

public slots:

    void startCircle();
    void stopCircle();
    void circle();
    void timerStopwatch();
    void crearStopwatch();

private:

    const int stopwatch_timer = 100;
    QTime circle_time = QTime(0, 0);
    QTime timeNull = QTime(0, 0);
    QTime timeNullMinus = QTime(0, 0);
    QTime time_out = QTime(0, 0);
    QString time_return;

    QTimer *timer;

    QString timeStopwatch(QTime& time_stopwatch, QTime stopwatch_time);
};

#endif // STOPWATCH_H
