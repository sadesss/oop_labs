#include <QVBoxLayout>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("HW 3");
    canvas = new Canvas(this);
    exit_button = new QPushButton("exit", this);

    QVBoxLayout * layout = new QVBoxLayout(this);

    layout->addWidget(canvas);
    layout->addWidget(exit_button);

    connect(exit_button, SIGNAL(clicked(bool)), this, SLOT(close())); 
}

MainWindow::~MainWindow()
{
}

