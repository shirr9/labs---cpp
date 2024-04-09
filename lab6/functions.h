#ifndef LAB6_FUNCTIONS_H
#define LAB6_FUNCTIONS_H


class Point{
public:
    int x;
    int y;
    Point(int a, int b);
    bool operator==(Point &other) const;
    bool operator>(Point &other) const;
    bool operator<(Point &other) const;

};

template <class InputIterator, class Predicate>
bool All_of(InputIterator start, InputIterator end, Predicate pred);

template <class InputIterator, class Predicate>
bool my_is_sorted(InputIterator start, InputIterator end, Predicate pred);

template <class InputIterator, class Predicate>
bool my_is_palindrome(InputIterator start, InputIterator end, Predicate pred);

#endif
