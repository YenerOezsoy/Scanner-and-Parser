/*
 * Scanner.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef SCANNER_H_
#define SCANNER_H_


#include "../../Buffer/includes/Buffer.h"
#include "../../Automat/includes/Automat.h"
#include "../../Symboltabelle/includes/Symboltabelle.h"
#include "Token.h"
#include "../../Buffer/includes/Ausgabe.h"

class Scanner {
private:
    int i = 0;
    int row = 1;
    int column = 1;
    bool stop = false;

    Automat *automat;
    Buffer *buffer;
    Symboltabelle *symboltabelle;
    Token *token;
    Ausgabe *ausgabe;

    int type = 7;
    int previousType;

    char c;

public: Token* nextToken();
    Scanner();
    void checkRowEnd(char c);
    void checkType(char c);
    void initialize(char* array);
    Scanner(char* readFile, char* writeFile);
};

#endif /* SCANNER_H_ */
