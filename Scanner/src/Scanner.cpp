/*
 * Scanner.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "Scanner.h"


Scanner::Scanner() {
    buffer = new Buffer();
    symboltabelle = new Symboltabelle();
}

Token* Scanner::nextToken() {
    automat = new Automat();
    stop = false;
    char array[2048];
    i = 0;

    while (!stop) {

        previousType = type;

        c = buffer->getChar();
        type = automat->handle(c);
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
            i--;
        }

        else {

            //EndType Ende erreicht
            if (type == 5) {
                buffer->ungetChar();
                //array[i] = '\0';
                i--;
                stop = true;
            }

            //ErrorType Fehlerhaftes Zeichen
            else if (type == 8) {
                stop = true;
            }

            //StartType überspringen oder Kommentar übersrpingen
            else if (type == 7 || type == 6) {
                i--;
            }
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
    //symboltabelle->insert(*array);

    token = new Token(previousType, row, column, array);
    return token;
    //TEST zum Anzeigen der Zeichen
    //buffer->test();
}
