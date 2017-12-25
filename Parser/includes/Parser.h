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
#include "../../Automat/includes/State.h"

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

	int errorCount;

public:
    Parser(Symboltabelle* symtab, char* input, char* output);
    virtual ~Parser();

    void parse();
    void next();
    void error();
    bool match(Type type, ParseTreeNode* node);


    void parsePROG();
    void parseDECLS(ParseTreeNode* parent);
    void parseDECL(ParseTreeNode* parent);
};

#endif /* PARSER_H_ */

