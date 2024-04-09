#include "func.h"
#include <cmath>
#include <iostream>

template<class T>
triangle<T>::triangle(T Ax, T Ay, T Bx, T By, T Cx, T Cy) {
    this->Ax = Ax;
    this->Ay = Ay;
    this->Bx = Bx;
    this->By = By;
    this->Cx = Cx;
    this->Cy = Cy;
    calc_area();
}

template<class T>
triangle<T>::triangle(const triangle &other) {
    this->Ax = other.Ax;
    this->Ay = other.Ay;
    this->Bx = other.Bx;
    this->By = other.By;
    this->Cx = other.Cx;
    this->Cy = other.Cy;
    this->area = other.area;
}

template<class T>
void triangle<T>::calc_area() {
    T a = sqrt((Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By));
    T b = sqrt((Cx - Bx) * (Cx - Bx) + (Cy - By) * (Cy - By));
    T c = sqrt((Ax - Cx) * (Ax - Cx) + (Ay - Cy) * (Ay - Cy));
    T p = (a + b + c) / 2;
    area = sqrt(p * (p - a) * (p - b) * (p - c));
}

template<class T>
bool triangle<T>::operator==(const triangle<T> &other) {
    return area == other.area;
}

template<class T>
bool triangle<T>::operator!=(const triangle<T> &other) {
    return area != other.area;
}

template<class T>
bool triangle<T>::operator>(const triangle<T> &other) {
    return area > other.area;
}

template<class T>
bool triangle<T>::operator<(const triangle<T> &other) {
    return area < other.area;
}

template<class T>
triangle<T> triangle<T>::operator+(std::pair<T, T> pair) {

    triangle<T> tr(this->Ax + pair.first, this->Ay + pair.second,
                   this->Bx + pair.first, this->By + pair.second,
                   this->Cx + pair.first, this->Cy + pair.second);
    return tr;
}

template<class T>
void triangle<T>::print() {
    std::cout << "A: (" << Ax << ", " << Ay << ")\n";
    std::cout << "B: (" << Bx << ", " << By << ")\n";
    std::cout << "C: (" << Cx << ", " << Cy << ")\n";
}

template class triangle<int>;

template class triangle<float>;

template class triangle<double>;

MyArray::MyArray(int n) {
    size = n;
    arr = new int[n];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

MyArray::~MyArray() {
    delete[]arr;
}

MyArray::MyArray(const MyArray &other) {
    this->size = other.size;
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

void MyArray::print() {
    std::cout << "arr: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }

}

void MyArray::fill() {
    std::cout << "enter " << size << " numbers";
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

}

bool MyArray::operator==(MyArray &other) const {
    return size == other.size;
}

bool MyArray::operator!=(MyArray &other) const {
    return size != other.size;
}

bool MyArray::operator>(MyArray &other) const {
    return size > other.size;
}

bool MyArray::operator<(MyArray &other) const {
    return size < other.size;
}

MyArray MyArray::operator+(const MyArray &other) const {
    MyArray tmp(size + other.size);
    for (int i = 0; i < size; i++) {
        tmp.arr[i] = arr[i];
    }
    for (int i = 0; i < other.size; i++) {
        tmp.arr[size + i] = other.arr[i];
    }
    return tmp;
}
