#ifndef LAB3_FUNC_H
#define LAB3_FUNC_H

#include <utility>

template<class T>
class triangle {
public:
    T Ax;
    T Ay;
    T Bx;
    T By;
    T Cx;
    T Cy;
    T area;

    triangle(T Ax, T Ay, T Bx, T By, T Cx, T Cy);

    triangle(const triangle &other);

    void calc_area();

    bool operator==(const triangle<T> &other);

    bool operator!=(const triangle<T> &other);

    bool operator>(const triangle<T> &other);

    bool operator<(const triangle<T> &other);

    triangle<T> operator+(std::pair<T, T>);

    void print();
};


class MyArray {
private:
    int size;
public:
    int *arr;

    MyArray(int n);

    MyArray(const MyArray &other);

    ~MyArray();

    void fill();

    void print();

    bool operator==(MyArray &other) const;

    bool operator!=(MyArray &other) const;

    bool operator>(MyArray &other) const;

    bool operator<(MyArray &other) const;

    MyArray operator+(const MyArray &other) const;
};

#endif
