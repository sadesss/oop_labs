#ifndef STACK_H
#define STACK_H

#include <QString>

// Перечисление для определения типа элемента стека
enum ElementType { Int, Word };

// Класс, представляющий элемент стека (целое число или слово)
class StackElement {
private:
    ElementType type;
    int intValue;
    QString strValue;
public:
    // Конструктор для целого числа
    StackElement(int value);
    // Конструктор для слова (строки)
    StackElement(const QString& value);
    // Метод возвращает строковое представление элемента
    QString toString() const;
    // Метод возвращает длину строкового представления
    int length() const;
};

// Структура узла стека (односвязный список)
struct Node {
    StackElement data;
    Node* next;
    Node(const StackElement& d, Node* n = nullptr) : data(d), next(n) {}
};

// Базовый класс стека с операциями push/pop/print
class Stack {
protected:
    Node* top;
public:
    Stack();
    virtual ~Stack();
    // Добавление элемента в стек
    void push(const StackElement& elem);
    // Удаление элемента с вершины стека (возвращает true при успешном удалении)
    bool pop(StackElement& elem);
    // Формирование строки с содержимым стека
    QString printStack() const;
    // Проверка, пуст ли стек
    bool isEmpty() const;
};

// Класс-наследник, расширяющий функционал стека методом поиска элемента с максимальной длиной строки
class ExtendedStack : public Stack {
public:
    ExtendedStack();
    ~ExtendedStack();
    // Метод для определения элемента с максимальной длиной при печати.
    // Если стек пуст, возвращается элемент с пустой строкой.
    StackElement findMaxLengthElement() const;
};

#endif // STACK_H
