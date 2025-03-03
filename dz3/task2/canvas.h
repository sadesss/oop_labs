#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>

#include <figure.h>
#include <line.h>
#include <ticker.h>

class Canvas : public QWidget {
private:
    int timerId;
    int time;
    Line * line;
    Ticker * ticker;
    Ticker * double_ticker;
protected:
    void paintEvent(QPaintEvent * event);
    void timerEvent(QTimerEvent * event);
    void showEvent(QShowEvent * event);
    void hideEvent(QHideEvent * event);
public:
    Canvas(QWidget * parent = nullptr);
    ~Canvas() {
        delete line; 
        delete ticker;
        delete[] double_ticker;
    };
};

#endif // CANVAS_H
