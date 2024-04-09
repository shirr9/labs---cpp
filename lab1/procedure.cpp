#include "procedure.h"
#include <cmath>

void Swap_l(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void Swap_ptr(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void to_int_l(double &a) {
    a = round(a);
}

void to_int_ptr(double *a) {
    *a = round(*a);
}

void Complex_l(std::complex<int> &z, int k) {
    z = z * k;
}

void Complex_ptr(std::complex<int> *z, int k) {
    *z = *z * k;
}

void move_circle_l(int &x0, int &y0, int x, int y) {
    x0 += x;
    y0 += y;
}

void move_circle_ptr(int *x0, int *y0, int x, int y) {
    *x0 += x;
    *y0 += y;
}