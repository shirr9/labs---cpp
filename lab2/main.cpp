#include <iostream>
#include "file_reader.h"


int main() {
    const char *name;
    name = "test.txt";
    reader file(name);
    file.f_open(name);
    cout << "\n";
    cout << file.isOpen() << "\n";
    string word;
    string line;
    file.getNextWord(word);
    file.getNextLine(line);
    cout << "next word " << word << "\n";
    cout << "next line " << line <<"\n";
    file.getNextLine(line);
    cout << "next line " << line <<"\n";
    file.f_close();
    return 0;
}
