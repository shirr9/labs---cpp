#include "tempates.h"
#include <cstring>


template<class T>
T Max(T *arr, int n) {
    T max = arr[0];
    for (int i = 1; i < n; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }
    return max;
}

template<class T>
Node<T>::Node(T val) {
    value = val;
}

template<class T>
Stack<T>::Stack(int N) {
    size = 0;
    max_size = N;
    top = nullptr;
}

template<class T>
T Stack<T>::getTop() {
    if (size == 0) {
        throw MyException("stack is empty");
    }
    return top->value;
}

template<class T>
void Stack<T>::pop() {
    if (size == 0) {
        throw MyException("stack is empty");
    }
    Node<T> *tmp = top;
    top = top->next;
    delete (tmp);
    size--;
}

template<class T>
void Stack<T>::push(T val) {
    if (size == max_size) {
        throw MyException("stack is overloaded");
    }
    Node<T> *new1 = new Node(val);
    new1->next = top;
    top = new1;
    size++;
}

template<class T>
Stack<T>::~Stack() {
    while (size > 0) {
        pop();
    }
}

MyException::MyException(char *msg) {
    char *mess = new char[strlen(msg) + 1];
    strcpy(mess, msg);
    message = mess;
}

const char *MyException::what() const noexcept {
    return message;
}

MyException::~MyException() {
    delete[] message;
}

template
class Stack<int>;

template
class Stack<string>;

template
class Stack<double>;

template
class Stack<char>;

template
class Stack<float>;

template
class Stack<long long>;

template int Max(int *arr, int n);
template double Max(double *arr, int n);
template float Max(float *arr, int n);
template char Max(char *arr, int n);
