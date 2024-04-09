#include <iostream>
#include "procedure.h"

using namespace std;
//вариант 1: 1, 4, 9, 12

int main() {
    cout << "task 1" << "\n";
    int a = 11;
    int b = 2;
    cout << "a = " << a << " " << "b = " << b << "\n";
    Swap_l(a, b);
    cout << "a = " << a << " " << "b = " << b << "\n";
    a = 11;
    b = 2;
    Swap_ptr(&a, &b);
    cout << "a = " << a << " " << "b = " << b << "\n";

    cout << "task 4" << "\n";
    double c = 2.25;
    cout << c << "\n";
    to_int_l(c);
    cout << c << "\n";
    c = 2.25;
    to_int_ptr(&c);
    cout << c << "\n";

    cout << "task 9" << "\n";
    complex<int> z;
    z.real(5);
    z.imag(2);
    cout << z << "\n";
    int k = 10;
    Complex_l(z, k);
    cout << z << "\n";
    z.real(5);
    z.imag(2);
    Complex_ptr(&z, k);
    cout << z << "\n";

    cout << "task 12" << "\n";
    int x0 = 0;
    int y0 = 5;
    int x = 4;
    int y = -1;
    cout << "circle with center in " << '(' << x0 << ',' << y0 << ')' << '\n';
    move_circle_l(x0, y0, x, y);
    cout << "circle with center in " << '(' << x0 << ',' << y0 << ')' << '\n';
    x0 = 0;
    y0 = 5;
    move_circle_ptr(&x0, &y0, x, y);
    cout << "circle with center in " << '(' << x0 << ',' << y0 << ')' << '\n';
}