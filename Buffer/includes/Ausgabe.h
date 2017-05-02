//
// Created by Yener Özsoy on 02.05.17.
//

#ifndef SCANNER_AUSGABE_H
#define SCANNER_AUSGABE_H

#include <fstream>

class Ausgabe {
public:
    Ausgabe(char* filepath) {
        stream.open(filepath, std::ios::out);
    };
    virtual ~Ausgabe() {
        stream.close();
    };
    void write(int type, int row, int column, char* key);
private:
    char* getType(int type);
    std::fstream stream;
};

#endif //SCANNER_AUSGABE_H

