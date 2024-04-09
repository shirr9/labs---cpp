#include <iostream>
#include <cmath>
#include "interfaces.h"
std::vector<ALL *> all_figure;

void sort() {
    for (int j = 1; j < all_figure.size(); j++) {
        ALL *key = all_figure[j];
        int i = j - 1;
        while (i >= 0 and key->mass < all_figure[i]->mass) {
            all_figure[i + 1] = all_figure[i];
            i--;
        }
        all_figure[i + 1] = key;
    }
}


void Print() {
    bool rect = false;
    bool segm = false;
    if (!all_figure.empty()) {
        for (ALL *figure: all_figure) {
            if (figure->classname() == "rectangle") {
                if (!rect) {
                    std::cout <<"position of all rectangles: "<< figure->resPos().x << ", " << figure->resPos().y << "\n";
                    std::cout <<"summary area of all rectangles: "<< figure->sumAllArea() << "\n";
                    std::cout <<"summary perimeters of all rectangles: "<< figure->sumALlPerimeters() << "\n";
                    std::cout <<"summary memory of all rectangles: "<< figure->memory() << "\n";
                    rect = true;
                }
            }
            if (figure->classname() == "segment") {
                if (!segm) {
                    std::cout <<"position of all segments: "<< figure->resPos().x << ", " << figure->resPos().y << "\n";
                    std::cout <<"summary area of all segments: "<< figure->sumAllArea() << "\n";
                    std::cout <<"summary perimeters of all segments: "<< figure->sumALlPerimeters() << "\n";
                    std::cout <<"summary memory of all segments: "<< figure->memory() << "\n";
                    segm = true;
                }
            }
            figure->print();
        }
    }
    else {std::cout << "empty";}
}

void clearFigures() {
    for (ALL *figure: all_figure) {
        delete figure;
    }
    all_figure.clear();
}

void add() {
    std::cout << "choose a figure to add:\n";
    std::cout << "1. rectangle\n";
    std::cout << "2. segment\n";
    std::cout << "0. exit\n";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            rectangle* new_rec = new rectangle();
            new_rec->initFromDialog();
            all_figure.push_back(new_rec);
            break;
        }
        case 2: {
            segment* new_seg = new segment();
            new_seg->initFromDialog();
            all_figure.push_back(new_seg);
            break;
        }
        case 0:
            return;
        default:
            std::cout << "invalid choice." << std::endl;
            return;
    }
}

const std::string rectangle::classname() {
    return "rectangle";
}

unsigned int rectangle::size() {
    return sizeof(*this);
}

void rectangle::initFromDialog() {
    std::cout << "text the height in int" << "\n";
    std::cin >> height;
    std::cout << "text the width in int" << "\n";
    std::cin >> width;
    std::cout << "text the center in double (x, y)" << "\n";
    std::cin >> center.x >> center.y;
    std::cout << "text the mass in int" << "\n";
    std::cin >> mass;
}

void rectangle::print() {
    std::cout << "rectangle:\n" << "height: " << height << "\n" << "width: " << width << "\n" << "center: " << center.x
              << ", " << center.y << "\n" << "mass: " <<  mass << "\n\n";
}

int rectangle::Perimeter() {
    return 2*(height + width);
}

int rectangle::Area() {
    return (height * width);
}

int rectangle::sumAllArea() {
    int all_sum = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "rectangle") {
            all_sum += figure->Area();
        }
    }
    return all_sum;
}

int rectangle::sumALlPerimeters() {
    int all_sum = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "rectangle") {
            all_sum += figure->Perimeter();
        }
    }
    return all_sum;
}

vector2D vector2D::operator+(const vector2D &other) const {
    vector2D tmp{};
    tmp.x = this->x + other.x;
    tmp.y = this->y + other.y;
    return tmp;
}

vector2D vector2D::operator-(const vector2D &other) const {
    vector2D tmp{};
    tmp.x = this->x - other.x;
    tmp.y = this->y - other.y;
    return tmp;
}

vector2D vector2D::operator/(int num) const {
    vector2D tmp{};
    tmp.x = this->x / num;
    tmp.y = this->y / num;
    return tmp;
}

vector2D vector2D::operator*(int num) const {
    vector2D tmp{};
    tmp.x = this->x * num;
    tmp.y = this->y * num;
    return tmp;
}

vector2D rectangle::position() {
    return center;
}

vector2D rectangle::resPos() {
    vector2D res = {0.0, 0.0};
    int m = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "rectangle") {
            res = res + figure->position() * figure->mass;
            m += figure->mass;
        }
    }
    res = res / m;
    return res;
}

unsigned int rectangle::memory() {
    unsigned int all_memory = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "rectangle") {
            all_memory += figure->size();
        }
    }
    return all_memory;
}

bool rectangle::operator==(const rectangle &other) {
    return this->mass == other.mass;
}

bool rectangle::operator>(const rectangle &other) {
    return this->mass > other.mass;
}

bool rectangle::operator<(const rectangle &other) {
    return this->mass < other.mass;
}




const std::string segment::classname() {
    return "segment";
}

unsigned int segment::size() {
    return sizeof(*this);
}

void segment::initFromDialog() {
    std::cout << "text the start point in double (x, y)" << "\n";
    std::cin >> start.x >> start.y;
    std::cout << "text the end point in double (x, y)" << "\n";
    std::cin >> end.x >> end.y;
    std::cout << "text the mass in int" << "\n";
    std::cin >> mass;
    len = pow((pow((start.x - end.x), 2.0) + pow((start.y - end.y), 2.0)), 0.5);
}

void segment::print() {
    std::cout << "segment:\n"
    << "start: " <<start.x << ", " << start.y << "\n"
    << "end: " << end.x << ", " << end.y << "\n"
    << "length: " << len << "\n"
    <<  "mass: " <<  mass << "\n\n";
}

int segment::Area() {
    return 0;
}

int segment::Perimeter() {
    return len;
}

int segment::sumAllArea() {
    return 0;
}

int segment::sumALlPerimeters() {
    int res = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "segment") {
            res += figure->Perimeter();
        }
    }
    return res;
}

vector2D segment::position() {
    return (end - start);
}

vector2D segment::resPos() {
    vector2D res = {0.0, 0.0};
    int m = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "segment") {
            res = res + figure->position() * figure->mass;
            m += figure->mass;
        }
    }
    res = res / m;
    return res;
}

unsigned int segment::memory() {
    unsigned int all_memory = 0;
    for (ALL *figure: all_figure) {
        if (figure->classname() == "segment") {
            all_memory += figure->size();
        }
    }
    return all_memory;
}

bool segment::operator==(const segment &other) const {
    return this->mass == other.mass;
}

bool segment::operator>(const segment &other) const {
    return this->mass > other.mass;
}

bool segment::operator<(const segment &other) const {
    return this->mass < other.mass;
}