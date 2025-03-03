#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Класс MainWindow обеспечивает пользовательский интерфейс для работы со стеком
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Слоты для обработки нажатий кнопок
    void on_pushButtonPush_clicked();
    void on_pushButtonPop_clicked();
    void on_pushButtonPrint_clicked();
    void on_pushButtonFindMax_clicked();

private:
    Ui::MainWindow *ui;
    ExtendedStack stack; // Экземпляр расширенного стека
};

#endif // MAINWINDOW_H
