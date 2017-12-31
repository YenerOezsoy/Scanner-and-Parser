/*
 * MakeCode.cpp
 *
 *  Created on: Dec 31, 2017
 *      Author: kaok1012
 */
#include "../includes/Parser.h"

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
		Type stmtType = node->getChild()->getToken()->getType();

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
		Type exp2Type = node->getChild()->getToken()->getType();

		if (exp2Type == SignRundeKlammerAuf) {
			makeCode(node->getChild(1));
		}
		else if (exp2Type == Letter) {
			code << "LA " << "$" << this->symtab->lookup(node->getChild(2)->getToken()->getRealKey())->getName() << endl;
			makeCode(node->getChild(1));
			code << "LV "<<endl;
		}
		else if (exp2Type == intType) {
			code << "LC " << node->getChild()->getToken()->getValue() <<endl;
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
