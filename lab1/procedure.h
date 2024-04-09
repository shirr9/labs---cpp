#ifndef LAB1_PROCEDURE_H
#define LAB1_PROCEDURE_H

#include <complex>

void Swap_l(int &a, int &b);

void Swap_ptr(int *a, int *b);

void to_int_l(double &a);

void to_int_ptr(double *a);

void Complex_l(std::complex<int> &z, int k);

void Complex_ptr(std::complex<int> *z, int k);

void move_circle_l(int &x0, int &y0, int x, int y);

void move_circle_ptr(int *x0, int *y0, int x, int y);

#endif //LAB1_PROCEDURE_H
