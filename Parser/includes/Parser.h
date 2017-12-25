/*
 * Parser.h
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */
#include "../../Scanner/includes/Scanner.h"
#include "../../Scanner/includes/Token.h"
#include "../../Symboltabelle/includes/Symboltabelle.h"
#include "../includes/ParseTree.h"

#ifndef PARSER_H_
#define PARSER_H_

class Parser {
private:
	Scanner* scanner;
	Token* lookahead;
	Symboltabelle* symtab;

	ParseTree* parseTree;
	ParseTreeNode* root;
	ParseTreeNode* ptr;

	ofstream output;

public:
    Parser(Symboltabelle* symtab, char* input, char* output);
    virtual ~Parser();

    void parse();
    void next();

    void parsePROG();
};

#endif /* PARSER_H_ */

