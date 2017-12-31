/*
 *  Parser.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */
#include <iostream>
#include "../includes/Parser.h"

Parser::Parser(Symboltabelle* symtab, char* input, char* output) {
	this->code.open(output);
	this->scanner = new Scanner(input, symtab);
	this->lookahead = nullptr;
	this->symtab = symtab;

	this->parseTree = new ParseTree();
	this->root = new ParseTreeNode(PROG, nullptr);
	this->ptr = root;
	parseTree->setRoot(root);

	this->parseErrorCount = 0;
	this->typeErrorCount = 0;
	this->labelCounter = 0;
}

Parser::~Parser() {
	code.close();
}

void Parser::parse() {
	cout << "parsing ..." << endl;
	parsePROG();

	if (parseErrorCount == 0) {
		cout << "type checking ..." << endl;
		typeCheck(root);

		if (typeErrorCount == 0) {
			cout << "generate code ..." << endl;
			makeCode(root);
		}
		else {
			cout << "type checking failed" << endl;
		}

	}
	else {
		cout << "parsing failed" << endl;
	}
}

void Parser::next() {
	lookahead = scanner->nextToken();

	if (lookahead == nullptr) {
		Key key = symtab->insert("END_OF_FILE");
		lookahead = new Token(FinalType, 0, 0, "END_OF_FILE", key);
	}
}

void Parser::error() {
	parseErrorCount++;
	cout << "Error at: ";

	if (lookahead->getColumn() == 0 && lookahead->getRow() == 0) {
		cout << "end" << endl;
	}
	else {
		cout << lookahead->getColumn() << "|" << lookahead->getRow() << endl;
	}
}

bool Parser::match(Type type, ParseTreeNode* node) {
	if (lookahead->getType() == type) {
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

	ParseTreeNode* statementsNode = new ParseTreeNode(STATEMENTS, root);
	root->addChild(statementsNode);
	parseSTATEMENTS(statementsNode);


}

void Parser::parseDECLS(ParseTreeNode* parent) {
	if (lookahead->getType() == intType) {
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
	if (match(intType, declNode)) {
		parseARRAY(declNode);
		match(Letter, declNode); // LETTER == IDENTIFIER
	}
}

void Parser::parseARRAY(ParseTreeNode* parent) {
	ParseTreeNode* arrayNode = new ParseTreeNode(ARRAY, ptr);
	parent->addChild(arrayNode);
	if (match(SignEckigeKlammerAuf, arrayNode)) {
		match(Digit, arrayNode);
		match(SignEckigeKlammerZu, arrayNode);
	}
}

void Parser::parseSTATEMENTS(ParseTreeNode* parent) {
	if (lookahead->getType() == Letter
		|| lookahead->getType() == writeType
		|| lookahead->getType() == readType
		|| lookahead->getType() == SignGeschweifteKlammerAuf
		|| lookahead->getType() == If
		|| lookahead->getType() == While
	) {
		parseSTATEMENT(parent);

		if (match(SignSemikolon, parent)) {
			parseSTATEMENTS(parent);
		}
		else if (lookahead->getColumn() == 0) {

		}
		else {
			error();
		}
	}
}

void Parser::parseSTATEMENT(ParseTreeNode* parent) {
	ParseTreeNode* statementNode = new ParseTreeNode(STATEMENT, ptr);
	parent->addChild(statementNode);

	//identifier INDEX:=EXP
	if(match(Letter, statementNode)){
		parseINDEX(statementNode);
		if (match(SignDoppelpunktGleich, statementNode)) {
			parseEXP(statementNode);
		}
	}

	//write(EXP)
	else if (match(writeType, statementNode)) {
		if (match(SignRundeKlammerAuf, statementNode)) {
			parseEXP(statementNode);
			if (match(SignRundeKlammerZu, statementNode)) {
				//cout << "WRITE"<< endl;
			} else {
				error();
			}
		} else {
			error();
		}
	}

	//read(EXP)
	else if (match(readType, statementNode)) {
		if (match(SignRundeKlammerAuf, statementNode)) {
			if (match(Letter, statementNode)) {
				parseINDEX(statementNode);
				if(match(SignRundeKlammerZu, statementNode)){
					//cout << "READ" << endl;
				}
				else {
					error();
				}
			}
			else {
				error();
			}
		}
		else{
			error();
		}
	}

	//if
	else if (match(If, statementNode)) {
		if (match(SignRundeKlammerAuf, statementNode)) {
			parseEXP(statementNode);
			if (match(SignRundeKlammerZu, statementNode)) {
				parseSTATEMENT(statementNode);
				if (match(elseType, statementNode)){
					parseSTATEMENT(statementNode);
					this->ptr = statementNode;
				}
				else{
					error();
				}
			} else {
				error();
			}
		} else {
			error();
		}
	}


	//WHILE
	else if (match(While, statementNode)) {
		if (match(SignRundeKlammerAuf, statementNode)) {
			parseEXP(statementNode);
			if (match(SignRundeKlammerZu, statementNode)) {
				parseSTATEMENT(statementNode);
				//cout << "WHILE" << endl;
			}
			else{
				error();
			}
		}
		else{
			error();
		}
	}

	//{statements}
	else if (match(SignGeschweifteKlammerAuf, statementNode)){
		ParseTreeNode* statementsNode = new ParseTreeNode(STATEMENTS, statementNode);
		statementNode->addChild(statementsNode);

		parseSTATEMENTS(statementsNode);
		if(match(SignGeschweifteKlammerZu, statementNode)){
			//cout << "{statements}" << endl;
		}
		else{
			error();
		}
	}
}

void Parser::parseINDEX(ParseTreeNode* parent){
	ParseTreeNode* indexNode = new ParseTreeNode(INDEX, parent);
	parent->addChild(indexNode);

	if(match(SignEckigeKlammerAuf, indexNode)){
		parseEXP(indexNode);
		if(match(SignEckigeKlammerZu, indexNode)){
		}
		else{
			error();
		}
	}
}

void Parser::parseEXP(ParseTreeNode* parent){
	ParseTreeNode* expNode = new ParseTreeNode(EXP, parent);
	parent->addChild(expNode);

	parseEXP2(expNode);
	parseOP_EXP(expNode);

}

void Parser::parseEXP2(ParseTreeNode* parent){
	ParseTreeNode* exp2Node = new ParseTreeNode(EXP2, ptr, lookahead);
	parent->addChild(exp2Node);

	if (match(Digit, exp2Node)){
	}
	else if (match(SignRundeKlammerAuf, exp2Node)){
		parseEXP(exp2Node);
		if (match(SignRundeKlammerZu, exp2Node)){
		}
		else{
			error();
		}
	}
	else if (match(Letter, exp2Node)){
		parseINDEX(exp2Node);
	}
	else if (match(SignMinus, exp2Node)){
		parseEXP2(exp2Node);
	}
	else if (match(SignAusrufezeichen, exp2Node)){
		parseEXP2(exp2Node);
	}

}

void Parser::parseOP_EXP(ParseTreeNode* parent){
	ParseTreeNode* op_expNode = new ParseTreeNode(OP_EXP,this->ptr);
	parent->addChild(op_expNode);
	if (lookahead->getType() == SignPlus ||
		lookahead->getType() == SignMinus ||
		lookahead->getType() == SignStern ||
		lookahead->getType() == SignDoppelpunkt ||
		lookahead->getType() == SignKleiner ||
		lookahead->getType() == SignGroesser ||
		lookahead->getType() == SignGleich ||
		lookahead->getType() == SignGleichDoppelpunktGleich ||
		lookahead->getType() == SignUndUnd
		) {

		parseOP(op_expNode);
		parseEXP(op_expNode);
	}
}


void Parser::parseOP(ParseTreeNode* parent){
	ParseTreeNode* opNode = new ParseTreeNode(OP, parent);
	parent->addChild(opNode);

	switch(lookahead->getType()) {
		case SignPlus:
			match(SignPlus, opNode);
			break;
		case SignMinus:
			match(SignMinus, opNode);
			break;
		case SignStern:
			match(SignStern, opNode);
			break;
		case SignDoppelpunkt:
			match(SignDoppelpunkt, opNode);
			break;
		case SignKleiner:
			match(SignKleiner, opNode);
			break;
		case SignGroesser:
			match(SignGroesser, opNode);
			break;
		case SignGleich:
			match(SignGleich, opNode);
			break;
		case SignGleichDoppelpunktGleich:
			match(SignGleichDoppelpunktGleich, opNode);
			break;
		case SignUndUnd:
			match(SignUndUnd, opNode);
			break;
		default:
			break;
		}


}
