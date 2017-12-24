/*
 * Parser.h
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */

#ifndef PARSER_H_
#define PARSER_H_

#include "../../Scanner/includes/Scanner.h";
#include "../../Scanner/includes/Token.h";
#include "../../Symboltabelle/includes/Symboltabelle.h"


class Parser {
private:
	Scanner* scanner;
	Token* lookahead;

	ofstream output;

public:
    Parser(Symboltabelle* symtab, char* input, char* output);
    virtual ~Parser();

    void parse();
};

#endif /* PARSER_H_ */

