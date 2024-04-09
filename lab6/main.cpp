#include <iostream>
#include <vector>
#include <functional>
#include "functions.h"

using namespace std;

int main() {
    // 1 (all_of), 5 (is_sorted), 9 (is_palindrome)
    vector<int> vec1{1, 2, 3, 4, 5};
    function<bool(int)> pr1 = [](int x) { return x > 0; };
    bool ans1 = All_of(vec1.begin(), vec1.end(), pr1);
    cout << ans1 << "\n";

    function<bool(int, int)> pr2 = [](int a, int b) -> bool { return a < b; };
    bool ans2 = my_is_sorted(vec1.begin(), vec1.end(), pr2);
    cout << ans2 << "\n";

    vector<int> vec3{1, 2, 4, 3, 8, 1};
    function<bool(int)> pr3{[](int x) { return x % 2 != 0; }};
    bool ans3 = my_is_palindrome(vec3.begin(), vec3.end(), pr3);
    cout << ans3 << "\n";

    vector<Point> p;
    for (int i = 0; i < 4; i++) {
        Point tmp_p(i, i);
        p.push_back(tmp_p);
    }
    function<bool(Point, Point)> pr4 = [](Point a, Point b) -> bool { return a < b; };
    bool ans4 = my_is_sorted(p.begin(), p.end(), pr4);
    cout << ans4 << "\n";
    return 0;
}


//    auto pr3 = [](int x){return x % 2 != 0;};