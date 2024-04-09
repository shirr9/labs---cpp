#include "file_reader.h"
#include <iostream>

reader::reader() = default;

reader::reader(const string &file_name) {
    filename = file_name;
    file.open(filename);
}

void reader::f_open(const string &file_name) {
    if (file.is_open()) {
        file.close();
    }
    file.open(filename);
    if (file.is_open()) {
        filename = file_name;
        cout << "file was opened";
    }
    else {
        cout << "file opening error";
    }
}

void reader::f_close() {
    if (file.is_open()) {
        file.close();
        cout << "file closed";
    }
    else {
        cout << "file is already closed";
    }
}

bool reader::isOpen() const {
    return file.is_open();
}

string reader::getFilename() const {
    return filename;
}

bool reader::isEndOfFile() const {
    return file.eof();
}

bool reader::getNextLine(string &line) {
    if (getline(file,line)) {return true;}
    return false;
}

bool reader::getNextWord(string &word) {
    if (file >> word) {return true;}
    return false;
}
