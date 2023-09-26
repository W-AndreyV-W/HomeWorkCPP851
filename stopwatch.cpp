#include "stopwatch.h"

Stopwatch::Stopwatch(QObject *parent) : QObject{parent} {

    timer = new QTimer(this);

    QObject::connect(timer, &QTimer::timeout, this, &Stopwatch::timerStopwatch, Qt::DirectConnection);
}



void Stopwatch::stopCircle() {

    timeNullMinus = QTime::fromMSecsSinceStartOfDay(timeNull.msecsTo(QTime::currentTime()));

    timer->stop();
}

void Stopwatch::circle() {

    emit sig_Circle(timeStopwatch(circle_time, QTime::currentTime()));
}

void Stopwatch::timerStopwatch() {

    QTime nullTime = timeNull;

    emit sig_PrintStopwatch(timeStopwatch(nullTime, QTime::currentTime()));
}

void Stopwatch::crearStopwatch() {

    if(timer->isActive()) {

        circle_time = QTime::currentTime();
        timeNull = circle_time;
    }
    else {

        timeNull = QTime(0, 0);
    }
}

void Stopwatch::startCircle() {

    circle_time = QTime::currentTime();

    if(timeNull == QTime(0, 0)) {

        timeNull = circle_time;
    }
    else {

        timeNull = QTime::fromMSecsSinceStartOfDay(timeNullMinus.msecsTo(circle_time));
    }

    timer->start(stopwatch_timer);
}

QString Stopwatch::timeStopwatch(QTime& time_stopwatch, QTime stopwatch_time) {

    time_out = QTime::fromMSecsSinceStartOfDay(time_stopwatch.msecsTo(stopwatch_time));
    time_return = time_out.toString("hh:mm:ss.zzz");
    time_stopwatch = stopwatch_time;

    return time_return;
}
