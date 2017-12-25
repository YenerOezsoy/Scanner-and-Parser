/*
 *  Parser.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */

#include "../includes/Parser.h"


Parser::Parser(Symboltabelle* symtab, char* input, char* output) {
	this->output.open(output);
	this->scanner = new Scanner(input, symtab);
	this->lookahead = nullptr;
	this->symtab = symtab;

	this->parseTree = new ParseTree();
	this->root = new ParseTreeNode(PROG, nullptr);
	this->ptr = root;
	parseTree->setRoot(root);
}

Parser::~Parser() {
	output.close();
}

void Parser::parse() {
	output << "Hello World!" << endl;
}

void Parser::next() {
	lookahead = scanner->nextToken()
}

void Parser::parsePROG() {
	next();
}
