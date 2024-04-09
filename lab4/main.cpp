#include <iostream>
#include "interfaces.h"

using namespace std;
int main() {
//вариант 2: B(отрезок), D(прямоугольник)
    cout << "how many figures do you want to add?\n";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        add();
    }
    sort();
    cout << "the geometric figures have been sorted\n";
    Print();
    clearFigures();
}
