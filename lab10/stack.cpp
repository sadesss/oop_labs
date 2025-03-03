#include "stack.h"
#include <QString>

// Реализация конструктора для целого числа
StackElement::StackElement(int value) : type(Int), intValue(value) {}

// Реализация конструктора для слова
StackElement::StackElement(const QString& value) : type(Word), strValue(value) {}

// Возвращает строковое представление элемента
QString StackElement::toString() const {
    if (type == Int)
        return QString::number(intValue);
    else
        return strValue;
}

// Возвращает длину строкового представления
int StackElement::length() const {
    return toString().length();
}

// Конструктор стека
Stack::Stack() : top(nullptr) {}

// Деструктор стека – освобождает память узлов
Stack::~Stack() {
    while (top) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

// Добавление элемента в стек
void Stack::push(const StackElement& elem) {
    Node* newNode = new Node(elem, top);
    top = newNode;
}

// Удаление элемента с вершины стека
bool Stack::pop(StackElement& elem) {
    if (!top)
        return false;
    elem = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return true;
}

// Формирование строки с содержимым стека (элементы разделены символом новой строки)
QString Stack::printStack() const {
    QString result;
    Node* current = top;
    while (current) {
        result += current->data.toString() + "\n";
        current = current->next;
    }
    return result;
}

// Проверка, пуст ли стек
bool Stack::isEmpty() const {
    return top == nullptr;
}

// Конструктор класса ExtendedStack (наследует функционал базового стека)
ExtendedStack::ExtendedStack() : Stack() {}

// Деструктор ExtendedStack
ExtendedStack::~ExtendedStack() {}

// Метод поиска элемента с максимальной длиной при печати
StackElement ExtendedStack::findMaxLengthElement() const {
    if (!top) {
        // Если стек пуст, возвращаем элемент с пустой строкой
        return StackElement(QString(""));
    }
    Node* current = top;
    StackElement maxElem = current->data;
    current = current->next;
    while (current) {
        if (current->data.length() > maxElem.length())
            maxElem = current->data;
        current = current->next;
    }
    return maxElem;
}
