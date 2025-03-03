#include "window.h"
#include <QVBoxLayout>

Window::Window()
{
    this->setWindowTitle("HW 3");
    area = new Canvas(this);
    btn = new QPushButton("Exit", this); 
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(area);
    layout->addWidget(btn);
    connect(btn, SIGNAL(clicked(bool)),this,SLOT(close()));
};

