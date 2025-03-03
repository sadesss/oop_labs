#ifndef WINDOWS_H
#define WINDOWS_H

#include "canvas.h"
#include <QWidget>
#include <QTextCodec>
#include <QPushButton> 

class Window : public QWidget
{
protected:
    Canvas * area;
    QPushButton * btn;
public:
    Window();
};
#endif
