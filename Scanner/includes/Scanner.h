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
    int column = 0;
    int startColumn;
    bool newWord;
    bool stop = false;
    const int error = 8;


    Automat *automat;
    Buffer *buffer;
    Symboltabelle *symboltabelle;
    Token *token;
    Ausgabe *ausgabe;

    int type = 7;
    int previousType;
    int previousAcceptence;

    char c;

public: Token* nextToken();
    Scanner();
    Scanner(char* readFile, char* writeFile);
private:   void checkRowEnd(char c);
    void checkType(char c);
    void initialize(char* array);
    void checkNewWord();
};

#endif /* SCANNER_H_ */
