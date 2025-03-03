#include <QTimerEvent>

#include "canvas.h"

Canvas::Canvas(QWidget * parent)
    : QWidget(parent), timerId(0), time(0) {
    setFixedSize(QSize(400, 400));

    line = new Line({70, 100}, 50, 2000);
    ticker = new Ticker({200, 100}, 15, 1000);
    double_ticker = new Ticker[2] {
            Ticker({320, 100}, 30, 1500),
            Ticker({320, 100}, -30, 1500)
    };
}

void Canvas::showEvent(QShowEvent *) {
    timerId = startTimer(50);
}

void Canvas::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::red);
    line->draw(painter, time);
    ticker->draw(painter, time);
    double_ticker[0].draw(painter, time);
    double_ticker[1].draw(painter, time);
}

void Canvas::timerEvent(QTimerEvent * event) {
    if (event->timerId() == timerId) {
        time += 50; 
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

void Canvas::hideEvent(QHideEvent *) {
    killTimer(timerId);
}
