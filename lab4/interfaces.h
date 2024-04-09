#ifndef LAB4_INTERFACES_H
#define LAB4_INTERFACES_H

#include <vector>

void add();
void clearFigures();
void Print();
void sort();

class vector2D {
public:
    double x, y;
    vector2D operator+ (const vector2D &other) const;
    vector2D operator- (const vector2D &other) const;
    vector2D operator/ (int num) const;
    vector2D operator* (int num) const;

};

class ALL {
public:
    int mass = 1;
    virtual const std::string classname() = 0;
    virtual unsigned int size() = 0;
    virtual void initFromDialog() = 0;
    virtual void print() = 0;
    virtual int Area()  = 0;
    virtual int Perimeter()  = 0;
    virtual int sumAllArea()  = 0;
    virtual int sumALlPerimeters()  = 0;
    virtual vector2D position() = 0;
    virtual vector2D resPos() = 0;
    virtual unsigned int memory() = 0;
};

class rectangle
        :public ALL {
private:
    int height = 0;
    int width = 0;
    vector2D center = {0.0, 0.0};
public:

    bool operator==(const rectangle& other);

    bool operator>(const rectangle& other);

    bool operator<(const rectangle& other);

    const std::string classname() override;

    unsigned int size() override;

    void initFromDialog() override;

    void print() override;

    int Area() override;

    int Perimeter() override;

    int sumAllArea() override;

    int sumALlPerimeters() override;

    vector2D position() override;

    vector2D resPos() override;

    unsigned int memory() override;


};

class segment
        :public ALL {
private:
    int len;
    vector2D start;
    vector2D end;
public:
    bool operator==(const segment& other) const;

    bool operator>(const segment& other) const;

    bool operator<(const segment& other) const;

    const std::string classname() override;

    unsigned int size() override;

    void initFromDialog() override;

    void print() override;

    int Area() override;

    int Perimeter() override;

    int sumAllArea() override;

    int sumALlPerimeters() override;

    vector2D position() override;

    vector2D resPos() override;

    unsigned int memory() override;


};
#endif





//class Object {
//public:
//    virtual const char *classname() = 0;
//
//    virtual unsigned int size() = 0;
//};
//
//class DialogeInitiable {
//public:
//    virtual void initFromDialog() = 0;
//};
//
//class draw {
//public:
//    virtual void print() = 0;
//};
//
//class allFigure {
//public:
////    virtual void addFigure() = 0;
//
////    virtual void sortFigures() = 0;
//
////    virtual void printAll() = 0;
//
//    virtual void memory() = 0;
//};

//class GeoFigure {
//public:
//    int mass = 1;
//    virtual int sumAllArea() = 0;
//
//    virtual int sumALlPerimeters() = 0;
//
//    virtual vector2D position() = 0;
//
//};

