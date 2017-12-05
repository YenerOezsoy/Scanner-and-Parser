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

Scanner::Scanner(char* readFile, char* writeFile) {
    buffer = new Buffer(readFile);
    symboltabelle = new Symboltabelle(30);
    //automat = new Automat();
    start = new Start();
    currentState = start;
    ausgabe = new Ausgabe(writeFile);
}

Token* Scanner::nextToken() {
    char array[2048];
    arrayCounter = 0;
    setBegin = false;

    c = buffer->getChar();
    currentState = start->read(&c);

    i++;
    rowCount = false;

    while (currentState->type != 25 && currentState->type != 26 && c != '\0') {
        if (currentState->type < 23) {
            addToArray(array);
        }

        checkComment();
        checkRowEnd();

        c = buffer->getChar();
        currentState = currentState->read(&c);
        i++;
    }

    if (c == '\0') return nullptr;

    createToken(array);

    return token;
}

void Scanner::undo(char* array) {
    //Nur ein Zeichen gelesen -> kein undo!
    if (currentState->type == 26) {
        array[arrayCounter] = c;
        arrayCounter++;
    }
    else {
        //Ein gültiges Zeichen
        if (arrayCounter==1){
            buffer->ungetChar();
            currentState = currentState->previousState;
            i--;
        }
        //Mehrere Zeichen
        while (!currentState->accepted && arrayCounter > 1) {
            if (currentState->type != 25){
                arrayCounter--;
                i--;
            }
            if (rowCount && currentState->type == 26) {
                !rowCount;
                row--;
            }
            buffer->ungetChar();
            currentState = currentState->previousState;
        }
    }
}

void Scanner::addToArray(char* array) {
    if (!setBegin) {
        begin = i;
        setBegin = true;
    }
    array[arrayCounter] = c;
    arrayCounter++;
}

void Scanner::createToken(char* array) {
    undo(array);
    array[arrayCounter] = '\0';
    token = new Token(currentState->type, row, begin, array);
    ausgabe->write(currentState->type, row, begin, array);
}

void Scanner::checkRowEnd()  {
    if (c == '\n') {
        row++;
        i = 0;
        rowCount = true;
    }
}

void Scanner::checkComment() {
    if (setBegin && currentState->type == 23) {
        arrayCounter--;
        setBegin = false;
    }
}
