/*
 * Scanner.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Scanner.h"
#include <iostream>

Scanner::Scanner(char* readFile, char* writeFile) {
    buffer = new Buffer(readFile);
    symboltabelle = new Symboltabelle(30);
    automat = new Automat();
    ausgabe = new Ausgabe(writeFile);
}

Token* Scanner::nextToken() {
    type = automat->reset();
    stop = false;
    char array[2048];
    i = 0;

    while (!stop) {

        initialize(array);

        //Ende des Files
        if (c == '\0' && i == 0) {
            stop = true;
            return nullptr;
        }

        checkRowEnd(c);

        checkType(c);

        i++;
    }

    array[i] = '\0';



    if (previousType != 8) symboltabelle->insert(array);

    token = new Token(previousType, row, column, array);
    ausgabe->write(previousType, row, column, array);

    column++;
    return token;
}

void Scanner::checkRowEnd(char c) {
    //Neue Zeile
    if (c == '\n' && i == 0) {
        row++;
        column = 1;
    }
}

void Scanner::checkType(char c) {
    //EndType Ende erreicht
    if (type == 5) {
        buffer->ungetChar();
        i--;
        stop = true;
    }

        //ErrorType Fehlerhaftes Zeichen
    else if (type == 8) {
        stop = true;
        previousType = type;
    }

        //StartType überspringen oder Kommentar übersrpingen
    else if (type == 7 || type == 6) {
        if (previousType == 0) {
            i--;
        }
        i--;
    }
}

void Scanner::initialize(char* array) {

    previousType = type;

    c = buffer->getChar();
    //std::cout << "eingelesen: " << c << std::endl;
    type = automat->handle(&c);
    array[i] = c;
}

