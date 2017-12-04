/*
 * Scanner.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Scanner.h"
#include <iostream>
#include <stdlib.h>
#include <errno.h>

ScannerNew::ScannerNew(char* readFile, char* writeFile) {
    buffer = new Buffer(readFile);
    symboltabelle = new Symboltabelle(30);
    //automat = new Automat();
    start = new Start();
    currentState = start;
    ausgabe = new Ausgabe(writeFile);
}

Token* ScannerNew::nextToken() {
    char array[2048];
    arrayCounter = 0;
    setBegin = false;

    c = buffer->getChar();
    currentState = start->read(&c);

    i++;

    while (currentState->type != 25 && currentState->type != 26 && c != '\0') {
        std::cout << currentState->type << std::endl;
        if (currentState->type < 23) {
            if (!setBegin) {
                begin = i;
                setBegin = true;
            }
            array[arrayCounter] = c;
            arrayCounter++;
        }

        if (c == '\n') {
            row++;
            i = 0;
        }

        c = buffer->getChar();
        currentState = currentState->read(&c);
        i++;
    }

    if (c == '\0') return nullptr;

    undo(array);
    array[arrayCounter] = '\0';
    token = new Token(currentState->type, row, begin, array);
    ausgabe->write(currentState->type, row, begin, array);

    return token;
}

void ScannerNew::undo(char* array) {
    //Nur ein Zeichen gelesen -> kein undo!
    if (currentState->type == 26) {
        array[arrayCounter] = c;
        arrayCounter++;
    }
    else {
        //Ein gültiges Zeichen
        if (arrayCounter==1 && currentState->previousState->accepted){
            buffer->ungetChar();
            currentState = currentState->previousState;
            i--;
        }
        //Mehrere Zeichen
        while (!currentState->accepted && arrayCounter > 1) {
            if (currentState->type != 25) arrayCounter--; i--;
            buffer->ungetChar();
            currentState = currentState->previousState;
        }
    }
}‚
