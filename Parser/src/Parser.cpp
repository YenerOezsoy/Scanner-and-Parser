/*
 *  Parser.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */

#include "../includes/Parser.h"


Parser::Parser(Symboltabelle* symtab, char* input, char* output) {
	this->output.open(output);
	scanner = new Scanner(input, symtab);
	lookahead = this->scanner->nextToken();
}

Parser::~Parser() {
	output.close();
}

void Parser::parse() {
	output << "Hello World!" << endl;
}
