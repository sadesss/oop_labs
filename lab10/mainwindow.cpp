#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Читает введённое значение из QLineEdit, определяет его тип и добавляет в стек.
void MainWindow::on_pushButtonPush_clicked()
{
    QString input = ui->lineEditInput->text();
    if (input.isEmpty()) {
        QMessageBox::warning(this, "Ошибка ввода", "Введите число или слово.");
        return;
    }
    // Определяем, является ли введённое значение числом
    bool flag;
    int intValue = input.toInt(&flag);
    if (flag) {
        StackElement elem(intValue);
        stack.push(elem);
    } else {
        StackElement elem(input);
        stack.push(elem);
    }
    ui->lineEditInput->clear();
}

// Слот обработки нажатия кнопки "Pop"
// Удаляет элемент с вершины стека и выводит его значение.
void MainWindow::on_pushButtonPop_clicked()
{
    StackElement elem(0);
    if (stack.pop(elem)) {
        QMessageBox::information(this, "Pop", "Удален элемент: " + elem.toString());
    } else {
        QMessageBox::warning(this, "Pop", "Стек пуст!");
    }
}

// Слот обработки нажатия кнопки "Print"
// Выводит содержимое стека в текстовое поле.
void MainWindow::on_pushButtonPrint_clicked()
{
    QString stackContents = stack.printStack();
    ui->textEditOutput->setPlainText(stackContents);
}

// Слот обработки нажатия кнопки "Find Max"
// Определяет и выводит элемент стека с максимальной длиной строкового представления.
void MainWindow::on_pushButtonFindMax_clicked()
{
    if (stack.isEmpty()) {
        QMessageBox::warning(this, "Find Max", "Стек пуст!");
        return;
    }
    StackElement maxElem = stack.findMaxLengthElement();
    QMessageBox::information(this, "Max Element", "Элемент с максимальной длиной: " + maxElem.toString());
}
