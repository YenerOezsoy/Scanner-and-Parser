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


    //Automat *automat;
    Buffer *buffer;
    Symboltabelle *symboltabelle;
    Token *token;
    Ausgabe *ausgabe;

    Start* start;
    State* currentState;

    int i = 0;
    int begin = 1;
    bool setBegin;
    int row = 1;
    int arrayCounter;
    char c;

public: Token* nextToken();
    Scanner();
    Scanner(char* readFile, char* writeFile);
private:
    void undo(char* array);
	void addToArray(char* array);
	void createToken(char* array);
	void checkRowEnd();
	void checkComment();
};

#endif /* SCANNER_H_ */

