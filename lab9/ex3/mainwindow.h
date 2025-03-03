#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void digitsNumbers();
    void on_dot_but_clicked();
    void operations();
    void math_operations();

    void on_ClearAll_but_clicked();
    void on_Total_but_clicked();
};
#endif // MAINWINDOW_H
