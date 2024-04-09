#include <iostream>
#include "func.h"

using namespace std;

int main() {
    //вариант 1: 3, 6



    triangle Tr1(0, 0, 3, 0, 0, 4);

    pair<int, int> pr(0,3);
    triangle Tr2(Tr1 + pr);
    Tr2.print();
    cout << (Tr1 == Tr2) << "\n";
    cout << (Tr1 != Tr2) << "\n";
    cout << (Tr1 > Tr2) << "\n";
    cout << (Tr1 < Tr2) << "\n";

    MyArray a1(4);
    a1.fill();
    MyArray a2(3);
    a2.fill();
    cout << (a1 == a2) << "\n";
    cout << (a1 != a2) << "\n";
    cout << (a1 > a2) << "\n";
    cout << (a1 < a2) << "\n";

    MyArray a3 = a1 + a2;
    a3.print();

}
