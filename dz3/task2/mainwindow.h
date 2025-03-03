#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

#include <canvas.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    Canvas * canvas;
    QPushButton * exit_button;
public:
    MainWindow(QWidget *parent = nullptr); 
    ~MainWindow();
};
#endif // MAINWINDOW_H
