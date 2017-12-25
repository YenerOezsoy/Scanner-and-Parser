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

	this->errorCount = 0;
}

Parser::~Parser() {
	output.close();
}

void Parser::parse() {
	output << "Hello World!" << endl;
}

void Parser::next() {
	lookahead = scanner->nextToken();
}

void Parser::error() {
	errorCount++;
}

bool Parser::match(Type type, ParseTreeNode* node) {
	if (node->getType() == type) {
		ParseTreeNode* matchNode = new ParseTreeNode(LEAF, node, lookahead);
		node->addChild(matchNode);
		next();
		return true;
	}
	return false;
}

void Parser::parsePROG() {
	next();

	ParseTreeNode* declsNode = new ParseTreeNode(DECLS, root);
	root->addChild(declsNode);

	parseDECLS(declsNode);

}

void Parser::parseDECLS(ParseTreeNode* parent) {
	if (lookahead->getType() == T_INT) {
		parseDECL(parent);
		if (match(SignSemikolon, parent)) {
			parseDECLS(parent);
		}
		else {
			error();
		}
	}
}

void Parser::parseDECL(ParseTreeNode* parent) {
	ParseTreeNode* declNode = new ParseTreeNode(DECL, ptr);
	parent->addChild(declNode);
	if (match(T_INT, declNode)) {
		parseARRAY(declNode);
		match(IDENTIFIER, declNode);
	}
}
















