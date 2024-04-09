#ifndef LABARATORY2_FILE_READER_H
#define LABARATORY2_FILE_READER_H
#include <fstream>
#include <string>

using namespace std;

class reader {
private:
    string filename;
    fstream file;
public:
    reader();

    reader(const string &file_name);

    void f_open(const string &file_name);

    void f_close();

    string getFilename() const;

    bool isOpen() const;

    bool isEndOfFile() const;

    bool getNextLine(string &line);

    bool getNextWord(string &word);
};
#endif //LABARATORY2_FILE_READER_H
