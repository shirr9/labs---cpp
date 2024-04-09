#include "functions.h"
#include <vector>
#include <functional>

Point::Point(int a, int b) {
    x = a;
    y = b;
}

bool Point::operator==(Point &other) const {
    return (x == other.x and y == other.y);
}

bool Point::operator>(Point &other) const {
    return (x > other.x and y > other.y);
}

bool Point::operator<(Point &other) const {
    return (x < other.x and y < other.y);
}


template<class InputIterator, class Predicate>
bool All_of(InputIterator start, InputIterator end, Predicate pred) {
    for (; start != end; start++) {
        if (!pred(*start)) {
            return false;
        }
    }
    return true;
}

template<class InputIterator, class Predicate>
bool my_is_sorted(InputIterator start, InputIterator end, Predicate pred) {
    if (start == end) return true;
    InputIterator next = start;
    next++;
    for (; next != end; start++) {
        if (!pred(*start, *next)) {
            return false;
        }
        next++;
    }
    return true;
}

template<class InputIterator, class Predicate>
bool my_is_palindrome(InputIterator start, InputIterator end, Predicate pred) {
    if (start == end) return true;
    end--;
    while (start < end) {
        while (start != end and !pred(*start)) start++;
        while (start != end and !pred(*end)) end--;
        if (*start != *end) return false;
        start++;
        end--;
    }
    return true;
}

template bool All_of<std::vector<int>::iterator, std::function<bool(int)>>(
std::vector<int>::iterator,
std::vector<int>::iterator,
std::function<bool(int)>
);

template bool my_is_sorted<std::vector<int>::iterator, std::function<bool(int, int)>>(
std::vector<int>::iterator,
std::vector<int>::iterator,
std::function<bool(int, int)> );

template bool my_is_sorted<std::vector<Point>::iterator, std::function<bool(Point, Point)>>(
std::vector<Point>::iterator,
std::vector<Point>::iterator,
std::function<bool(Point, Point)> );

template bool my_is_palindrome<std::vector<int>::iterator, std::function<bool(int)>> (
        std::vector<int>::iterator, std::vector<int>::iterator, std::function<bool(int)>);

//template class Point<int>;
//template class Point<double>;
//template class Point<float>;