#ifndef LAB5_TEMPATES_H
#define LAB5_TEMPATES_H

#include <iostream>
#include <exception>
#include <string>

using namespace std;

template<class T>
T Max(T *arr, int n);

template<class T>
class Node {
public:
    T value;
    Node *next;

    Node(T val);
};

class MyException : public exception {
private:
    char *message;
public:
    MyException(char *msg);

    const char *what() const noexcept override;

    ~MyException();
};

template<class T>
class Stack {
private:
    Node<T> *top;
    int size;
    int max_size;
public:
    Stack(int N);

    T getTop();

    void pop();

    void push(T val);

    ~Stack();
};

#endif
