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

char* Parser::typeToString(int type) {
	switch (type) {
	case 5:
		return "SignPlus";
	case 6:
		return "SignMinus";
	case 7:
		return "SignDoppelPunkt";
	case 8:
		return "SignStern";
	case 9:
		return "SignKleiner";
	case 10:
		return "SignGroesser";
	case 11:
		return "SignGleich";
	case 12:
		return "SignDoppelpunktGleich";
	case 13:
		return "SignGleichDoppelpunktGleich";
	case 14:
		return "SignAusrufezeichen";
	case 15:
		return "SignUndUnd";
	case 16:
		return "SignSemikolon";
	case 17:
		return "SignRundeKlammerAuf";
	case 18:
		return "SignRundeKlammerZu";
	case 19:
		return "SignGeschweifteKlammerAuf";
	case 20:
		return "SignGeschweifteKlammerZu";
	case 21:
		return "SignEckigeKlammerAuf";
	case 22:
		return "SignEckigeKlammerZu";
	default:
		return "Others";
	}
}

void Parser::error() {
	parseErrorCount++;
	cerr << "error  ";

	if (lookahead->getRow() == 0 && lookahead->getColumn() == 0) {
		cerr << "end" << endl;
	}
	else {
		cerr << "Line: " << lookahead->getRow();
		cerr << "Column: " << lookahead->getColumn();
		cerr << '  ' << typeToString(lookahead->getType()) << endl;
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

// TypeCheck
void Parser::typeError(char* msg) {
	++typeErrorCount;
	cerr << msg << endl;
}

void Parser::typeError(char* msg, Token* token) {
	++typeErrorCount;

	cerr << "Line:   " << token->getRow();
	cerr << "\tColumn: " << token->getColumn();
	cerr << '\t' << msg << endl;
}

void Parser::store(Key key, CheckType type){
	symtab->lookup(key)->setCheckType(type);
}

CheckType Parser::getType(Key key) {
	return symtab->lookup(key)->getCheckType();
}

void Parser::typeCheck(ParseTreeNode* node) {
	if (node->getType() == PROG) {
		typeCheck(node->getChild(0));
		typeCheck(node->getChild(1));
		node->setCheckType(NOTYPE);
	}
	else if (node->getType() == DECLS || node->getType() == STATEMENTS) {
		if (node->isLeaf()) {
			node->setCheckType(NOTYPE);
		}
		else {
			ParseTreeNode* child = node->getChild();

			while (child != nullptr) {
				typeCheck(child);
				child = child->getNext();
			}
			node->setCheckType(NOTYPE);
		}
	}
	else if (node->getType() == DECL) {
		typeCheck(node->getChild(1));

		if (node->getChild(2) != nullptr) {
			if (getType(node->getChild(2)->getToken()->getRealKey()) != NOTYPE) {
				typeError("identifier already defined", node->getChild(2)->getToken());
				node->setCheckType(ERRORTYPE);
			}
			else if (node->getChild(1)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(NOTYPE);

				if (node->getChild(1)->getCheckType() == ARRAYTYPE) {
					store(node->getChild(2)->getToken()->getRealKey(), INTARRAYTYPE);
				} else {
					store(node->getChild(2)->getToken()->getRealKey(), INTTYPE);
				}
			}
		}
		else {
			typeError("no identifier name", node->getNext()->getToken());
		}
	}
	else if (node->getType() == ARRAY) {
		if (!node->isLeaf()) {
			if (node->getChild(1)->getToken()->getValue() > 0) {
				node->setCheckType(ARRAYTYPE);
			} else {
				typeError("no valid number", node->getChild(1)->getToken());
				node->setCheckType(ERRORTYPE);
			}
		}
		else {
			node->setCheckType(NOTYPE);
		}
	}
	else if (node->getType() == STATEMENT) {
		Type stmtType = (Type) node->getChild()->getToken()->getType();

		// ASSIGN
		if (stmtType == Letter) {
			typeCheck(node->getChild(3));
			typeCheck(node->getChild(1));

			if (getType(node->getChild(0)->getToken()->getRealKey()) == NOTYPE) {
				typeError("identifier not defined", node->getChild(0)->getToken());
				node->setCheckType(ERRORTYPE);
			}
			else if (node->getChild(3)->getCheckType() == INTTYPE
								&& ((getType(node->getChild(0)->getToken()->getRealKey()) == INTTYPE
										&& node->getChild(1)->getCheckType() == NOTYPE)
										|| (getType(node->getChild(0)->getToken()->getRealKey()) == INTARRAYTYPE
												&& node->getChild(1)->getCheckType() == ARRAYTYPE))
					) {
				node->setCheckType(NOTYPE);
			}
			else {
				typeError("incompatible types", node->getChild(0)->getToken());
			}
		}

		// WRITE
		else if (stmtType == writeType) {
			typeCheck(node->getChild(2));
			node->setCheckType(NOTYPE);
		}

		//READ
		else if (stmtType == readType) {
			typeCheck(node->getChild(3));

			if (getType(node->getChild(2)->getToken()->getRealKey()) == NOTYPE) {
				typeError("identifier not defined", node->getChild(2)->getToken());
				node->setCheckType(ERRORTYPE);
			}
			else if ( ((getType(node->getChild(2)->getToken()->getRealKey()) == INTTYPE)
					&& node->getChild(3)->getCheckType() == NOTYPE)
					||((getType(node->getChild(2)->getToken()->getRealKey()) == INTARRAYTYPE)
							&& node->getChild(3)->getCheckType() == ARRAYTYPE)
					) {
				node->setCheckType(NOTYPE);
			}
			else {
				typeError("incompatible types", node->getChild(2)->getToken());
			}
		}

		//{STATEMENTS}
		else if (stmtType == SignGeschweifteKlammerAuf) {
			typeCheck(node->getChild(1));
			node->setCheckType(NOTYPE);
		}

		//IF
		else if (stmtType == If) {
			typeCheck(node->getChild(2));
			typeCheck(node->getChild(4));
			typeCheck(node->getChild(6));
			if (node->getChild(2)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(NOTYPE);
			}
		}
		else if (stmtType == While) {
			typeCheck(node->getChild(2));
			typeCheck(node->getChild(4));

			if(node->getChild(2)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(NOTYPE);
			}
		}
	}
	else if (node->getType() == INDEX) {
		if (!node->isLeaf()) {
			typeCheck(node->getChild(1));
			if (node->getChild(1)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			} else {
				node->setCheckType(ARRAYTYPE);
			}
		}
		else {
			node->setCheckType(NOTYPE);
		}
	}
	else if(node->getType() == EXP) {
		typeCheck(node->getChild(0));
		typeCheck(node->getChild(1));

		if (node->getChild(1)->getCheckType() == NOTYPE) {
			node->setCheckType(node->getChild(0)->getCheckType());
		}
		else if (node->getChild(0)->getCheckType() != node->getChild(1)->getCheckType()) {
			node->setCheckType(ERRORTYPE);
		}
		else {
			node->setCheckType(node->getChild(0)->getCheckType());
		}
	}
	else if (node->getType() == EXP2) {
		Type exp2Type = (Type) node->getChild()->getToken()->getType();

		if (exp2Type == SignRundeKlammerAuf) {
			typeCheck(node->getChild(1));
			node->setCheckType(node->getChild(1)->getCheckType());
		}
		else if (exp2Type == Letter) {
			typeCheck(node->getChild(1));

			CheckType identifierType = getType(node->getChild(0)->getToken()->getRealKey());

			if (identifierType == NOTYPE) {
				typeError("identifier not defined", node->getChild(0)->getToken());
				node->setCheckType(ERRORTYPE);
			}
			else if (identifierType == INTTYPE && node->getChild(1)->getCheckType() == NOTYPE) {
				node->setCheckType(identifierType);
			}
			else if (identifierType == INTARRAYTYPE && node->getChild(1)->getCheckType() == ARRAYTYPE) {
				node->setCheckType(INTTYPE);
			}
			else {
				typeError("no primitive type", node->getChild(0)->getToken());
				node->setCheckType(ERRORTYPE);
			}
		}
		else if (exp2Type == Digit) {
			node->setCheckType(INTTYPE);
		}
		else if (exp2Type == SignMinus) {
			typeCheck(node->getChild(1));
			node->setCheckType(node->getChild(1)->getCheckType());
		}
		else if (exp2Type == SignAusrufezeichen) {
			typeCheck(node->getChild(1));

			if (node->getChild(1)->getCheckType() != INTTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(INTTYPE);
			}
		}
	}
	else if (node->getType() == OP_EXP) {
		if (!node->isLeaf()) {
			typeCheck(node->getChild(0));
			typeCheck(node->getChild(1));
			node->setCheckType(node->getChild(1)->getCheckType());

		}
		else {
			node->setCheckType(NOTYPE);
		}
	}
	else if (node->getType() == OP) {
		Type opType = (Type) node->getChild()->getToken()->getType();

		switch(opType) {
		case SignPlus:
			node->setCheckType(OPPLUS);
			break;
		case SignMinus:
			node->setCheckType(OPMINUS);
			break;
		case SignStern:
			node->setCheckType(OPMULT);
			break;
		case SignDoppelpunkt:
			node->setCheckType(OPDIV);
			break;
		case SignKleiner:
			node->setCheckType(OPLESS);
			break;
		case SignGroesser:
			node->setCheckType(OPGREATER);
			break;
		case SignGleich:
			node->setCheckType(OPEQUAL);
			break;
		case SignGleichDoppelpunktGleich:
			node->setCheckType(OPUNEQUAL);
			break;
		case SignUndUnd:
			node->setCheckType(OPAND);
			break;
		default:
			break;
		}
	}
}

// MakeCode
int Parser::getLabelCounter() {
	return ++labelCounter;
}

void Parser::makeCode(ParseTreeNode* node) {
	if(node->getType() == PROG){
		makeCode(node->getChild(0));
		makeCode(node->getChild(1));
		code << "STP" <<endl;
	}
	else if (node->getType() == DECLS) {
		if (!node->isLeaf()) {
			ParseTreeNode* child = node->getChild();
			while(child != nullptr){
				makeCode(child);
				child = child->getNext();
			}
		}
	}
	else if (node->getType() == DECL) {
		code << "DS " << "$" << this->symtab->lookup(node->getChild(2)->getToken()->getRealKey())->getName() << " ";
		makeCode(node->getChild(1));
	}
	else if (node->getType() == ARRAY) {
		if (!node->isLeaf()) {
			code << node->getChild(1)->getToken()->getValue() <<endl;
		}
		else{
			code << 1 << endl;
		}
	}
	else if (node->getType() == STATEMENTS) {
		if (!node->isLeaf()) {
			ParseTreeNode* child = node->getChild();
			while (child != nullptr) {
				makeCode(child);
				child = child->getNext();
			}
		} else {
			code << "NOP " << endl;
		}
	}
	else if (node->getType() == STATEMENT) {
		Type stmtType = (Type) node->getChild()->getToken()->getType();

		//ASSIGN
		if (stmtType == Letter) {
			makeCode(node->getChild(3));
			code << "LA " << "$" << this->symtab->lookup(node->getChild(0)->getToken()->getRealKey())->getName() <<endl;
			makeCode(node->getChild(1));
			code << "STR " <<endl;
		}

		//WRITE
		else if (stmtType == writeType) {
			makeCode(node->getChild(2));
			code << "PRI "<<endl;
		}
		//READ
		else if (stmtType == readType) {
			code << "REA "<<endl;
			code << "LA " << "$" << this->symtab->lookup(node->getChild(2)->getToken()->getRealKey())->getName() <<endl;
			makeCode(node->getChild(3));
			code << "STR "<<endl;
		}

		//{STATEMENTS}
		else if (stmtType == SignGeschweifteKlammerAuf) {
			makeCode(node->getChild(1));
		}

		//IF
		else if (stmtType == If) {
			int label1 = this->getLabelCounter();
			int label2 = this->getLabelCounter();

			makeCode(node->getChild(2));
			code << "JIN " << "#" << "label"<< label1 << endl;

			makeCode(node->getChild(4));
			code << "JMP " << "#" << "label"<< label2 << endl;

			code << "#" << "label" << label1 << " NOP " << endl;

			makeCode(node->getChild(6));
			code << "#" << "label" << label2 << " NOP " << endl;
		}

		else if (stmtType == While) {
			int label1 = this->getLabelCounter();
			int label2 = this->getLabelCounter();

			code << "#" << "label" << label1 << " NOP "<< endl;

			makeCode(node->getChild(2));
			code << "JIN " << "#" << "label" << label2 << endl;

			makeCode(node->getChild(4));
			code << "JMP " << "#" << "label" << label1 << endl;

			code << "#" << "label" << label2 << " NOP " << endl;
		}
	}
	else if (node->getType() == EXP) {
		if (node->getChild(1)->getCheckType() == NOTYPE) {
			makeCode(node->getChild(0));
		}
		else if (node->getChild(1)->getChild()->getCheckType() == OPGREATER) {
			makeCode(node->getChild(1));
			makeCode(node->getChild(0));
			code << "LES " << endl;
		}
		else if (node->getChild(1)->getChild()->getCheckType() == OPUNEQUAL) {
			makeCode(node->getChild(0));
			makeCode(node->getChild(1));
			code << "NOT " << endl;
		}
		else {
			makeCode(node->getChild(0));
			makeCode(node->getChild(1));
		}
	}
	else if (node->getType() == INDEX) {
		if (!node->isLeaf()) {
			makeCode(node->getChild(1));
			code << "ADD " << endl;
		}
	}
	else if (node->getType() == EXP2) {
		Type exp2Type = (Type) node->getChild()->getToken()->getType();

		if (exp2Type == SignRundeKlammerAuf) {
			makeCode(node->getChild(1));
		}
		else if (exp2Type == Letter) {
			code << "LA " << "$" << this->symtab->lookup(node->getChild(0)->getToken()->getRealKey())->getName() << endl;
			makeCode(node->getChild(1));
			code << "LV "<<endl;
		}
		else if (exp2Type == Digit) {
			if (node->getChild()->getToken()->isThisANumber()) {
				code << "LC " << node->getChild()->getToken()->getValue() <<endl;
			} else {
				typeError("not a number", node->getChild()->getToken());
			}
		}
		else if (exp2Type == SignMinus) {
			code << "LC " << 0 <<endl;
			makeCode(node->getChild(1));
			code << "SUB " << endl;
		}
		else if (exp2Type == SignAusrufezeichen) {
			makeCode(node->getChild(1));
			code << "NOT " << endl;
		}
	}
	else if (node->getType() == OP_EXP) {
		if (!node->isLeaf()) {
			makeCode(node->getChild(1));
			makeCode(node->getChild(0));
		}
	}
	else if (node->getType() == OP) {
		CheckType opType = node->getCheckType();

		switch (opType) {
		case OPPLUS:
			code << "ADD" << endl;
			break;
		case OPMINUS:
			code << "SUB" << endl;
			break;
		case OPMULT:
			code << "MUL" << endl;
			break;
		case OPDIV:
			code << "DIV" << endl;
			break;
		case OPLESS:
			code << "LES" << endl;
			break;
		case OPGREATER:
			break;
		case OPEQUAL:
			code << "EQU" << endl;
			break;
		case OPUNEQUAL:
			code << "EQU" << endl;
			break;
		case OPAND:
			code << "AND" << endl;
			break;
		default:
			break;
		}
	}
}
