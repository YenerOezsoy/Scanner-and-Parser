/*
 * Scanner.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Scanner.h"
#include <iostream>

Scanner::Scanner() {
    buffer = new Buffer();
    automat = new Automat();
    symboltabelle = new Symboltabelle(100);
}

Token* Scanner::nextToken() {
    automat->reset();
    stop = false;
    char array[2048];
    i = 0;

    while (!stop) {

        previousType = type;

        c = buffer->getChar();
        //std::cout << "eingelesen: " << c << std::endl;
        type = automat->handle(&c);
        array[i] = c;

        //Ende des Files
        if (c == '\0' && i == 0) {
            stop = true;
            return nullptr;
        }

            //Neue Zeile
        else if (c == '\n') {
            row++;
            column = 1;
        }

        //EndType Ende erreicht
        if (type == 5) {
                buffer->ungetChar();
                i--;
                stop = true;
        }

        //ErrorType Fehlerhaftes Zeichen
        else if (type == 8) {
            stop = true;
        }

        //StartType überspringen oder Kommentar übersrpingen
        else if (type == 7 || type == 6) {
            if (previousType == 0) {
                i--;
            }
            i--;
        }

    i++;
    }

    array[i] = '\0';

    //Ausgabe TEST
    /*
    int j = 0;
    while (array[j] != '\0') {
        std::cout << "Buchstabe: "<< array[j] << std::endl;
        j++;

    }


    std::cout << "Row: " << row << " Column: " << column << std::endl;
    */

    column++;

    //AKTIVIEREN!!
    symboltabelle->insert(array);

    token = new Token(previousType, row, column, array);
    return token;

    //TEST zum Anzeigen der Zeichen
    //buffer->test();
}
