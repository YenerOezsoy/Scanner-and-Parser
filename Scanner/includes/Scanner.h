/*
 * Scanner.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef SCANNER_H_
#define SCANNER_H_


#include "Buffer.h"
#include "Automat.h"
#include "Symboltabelle.h"
#include "Token.h"

class Scanner {
        int i = 0;
        int row = 1;
        int column = 1;
        bool stop = false;

        Automat *automat;
        Buffer *buffer;
        Symboltabelle *symboltabelle;
        Token *token;

        int type = 7;
        int previousType;

        char c;

public: Token* nextToken();
        Scanner();
};

#endif /* SCANNER_H_ */
