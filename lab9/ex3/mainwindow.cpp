#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtCore/qmath.h>
double num_first=0;

void backspace(QString& text) {
    if (text.isEmpty()) {
        // Если строка пустая, ничего не делаем
        return;
    }

    // Проверяем, есть ли точка в числе
    bool has_decimal_point = text.contains('.');

    if (has_decimal_point) {
        // Если после точки только одна цифра, удаляем ее вместе с точкой
        int decimal_index = text.indexOf('.');
        int num_digits_after_decimal = text.length() - decimal_index - 1;
        if (num_digits_after_decimal == 1) {
            text.chop(2);
        } else {
            // Удаляем только последнюю цифру после точки
            text.chop(1);
        }
    } else {
        // Удаляем последнюю цифру
        text.chop(1);
    }

    // Если после удаления осталась только точка, удаляем ее
    if (text.endsWith('.')) {
        text.chop(1);
    }
}
double calculateLog(double a, double x) {
    return qLn(x) / qLn(a);
}
double calculatePower(double x, double a) {
    return qPow(x, a);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow){
    ui->setupUi(this);

    connect(ui->nule_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->one_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->two_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->three_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->four_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->five_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->six_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->seven_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->eight_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));
    connect(ui->nine_but, SIGNAL(clicked()),this,SLOT(digitsNumbers()));

    connect(ui->Inverse_but, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->bck_but, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->ClearEm_but, SIGNAL(clicked()),this,SLOT(operations()));

    connect(ui->Plus_but, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Minus_but, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Sin_but, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->Cos_but, SIGNAL(clicked()),this,SLOT(operations()));
    connect(ui->Log_but, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Pow_but, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Div_but, SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->Mult_but, SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->Plus_but->setCheckable(true);
    ui->Minus_but->setCheckable(true);
    ui->Log_but->setCheckable(true);
    ui->Pow_but->setCheckable(true);
    ui->Mult_but->setCheckable(true);
    ui->Div_but->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digitsNumbers(){
    QPushButton *button = (QPushButton*)sender();

    double allNums = 0;
    QString num_text;

    allNums = (ui->textEdit->toPlainText() + button->text()).toDouble();
    num_text = QString::number(allNums, 'g', 15);
    ui->textEdit->setText(num_text);
}

void MainWindow::on_dot_but_clicked(){
    if(!ui->textEdit->toPlainText().contains('.'))
        ui->textEdit->setText(ui->textEdit->toPlainText()+".");
}

void MainWindow::operations(){
    QPushButton *button = (QPushButton*)sender();

    double allNums = 0;
    QString num_str;

    if(button->text() == "-/+"){
        allNums = (ui->textEdit->toPlainText()).toDouble();
        allNums *= -1;
        num_str = QString::number(allNums, 'g', 15);
        ui->textEdit->setText(num_str);

    }else if (button->text() == "<-"){
        allNums = (ui->textEdit->toPlainText()).toDouble();
        num_str = QString::number(allNums, 'g', 15);
        backspace(num_str);

        ui->textEdit->setText(num_str);
    }else if (button->text() == "CE"){
        ui->textEdit->clear();
    }else if (button->text() == "sin(x)"){
        allNums = (ui->textEdit->toPlainText()).toDouble();
        allNums = qSin(allNums);
        num_str = QString::number(allNums, 'g', 15);
        ui->textEdit->setText(num_str);
    }else if (button->text() == "cos(x)"){
        allNums = (ui->textEdit->toPlainText()).toDouble();
        allNums = qCos(allNums);
        num_str = QString::number(allNums, 'g', 15);
        ui->textEdit->setText(num_str);
    }
}

void MainWindow::math_operations(){
    QPushButton *button = (QPushButton*)sender();

    num_first = ui->textEdit->toPlainText().toDouble();
    ui->textEdit->clear();
    button->setChecked(true);
}

void MainWindow::on_ClearAll_but_clicked(){
    num_first = 0;
    ui->textEdit->clear();
    ui->Plus_but->setChecked(false);
    ui->Minus_but->setChecked(false);
    ui->Log_but->setChecked(false);
    ui->Pow_but->setChecked(false);
    ui->Mult_but->setChecked(false);
    ui->Div_but->setChecked(false);

}

void MainWindow::on_Total_but_clicked(){
    double textNum, num_second = 0;
    QString new_Num;

    num_second = ui->textEdit->toPlainText().toDouble();

    if (ui->Plus_but->isChecked()){
        textNum = num_second + num_first;
        new_Num = QString::number(textNum, 'g', 15);
        ui->textEdit->setText(new_Num);
        ui->Plus_but->setChecked(false);

    }else if (ui->Minus_but->isChecked()){
        textNum = num_first - num_second;
        new_Num = QString::number(textNum, 'g', 15);
        ui->textEdit->setText(new_Num);
        ui->Minus_but->setChecked(false);

    }else if (ui->Log_but->isChecked()){

        if (num_second > 0 && num_second != 1){
            textNum =calculateLog(num_second, num_first);
            new_Num = QString::number(textNum, 'g', 15);
            ui->textEdit->setText(new_Num);
            ui->Log_but->setChecked(false);
        }else
            ui->textEdit->setText("ERROR");

    }else if (ui->Pow_but->isChecked()){
        textNum = calculatePower(num_second, num_first);
        new_Num = QString::number(textNum, 'g', 15);
        ui->textEdit->setText(new_Num);
        ui->Pow_but->setChecked(false);

    }else if (ui->Div_but->isChecked()){

        if (num_second != 0){
            textNum = num_first/num_second;
            new_Num = QString::number(textNum, 'g', 15);
            ui->textEdit->setText(new_Num);
            ui->Div_but->setChecked(false);
        }else
            ui->textEdit->setText("ERROR");
    }else if (ui->Mult_but->isChecked()){
        textNum = num_second * num_first;
        new_Num = QString::number(textNum, 'g', 15);
        ui->textEdit->setText(new_Num);
        ui->Mult_but->setChecked(false);
    }
}
