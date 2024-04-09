#include <iostream>
#include "tempates.h"

using namespace std;

int main() {
    try {
        Stack<int> myStack(3);
        myStack.push(1);
        myStack.push(2);
        myStack.push(3);
        myStack.push(4);
    }
    catch (MyException &exc) {
        cout << "exception: " << exc.what() << "\n";
    }

    int arr[4]{1, 2, 3, 4};
    cout << Max<int>(arr, 4);
    return 0;

}
