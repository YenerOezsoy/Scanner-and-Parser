/*
 *  TypeCheck.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: kaok1012
 */
#include "../includes/Parser.h"

void Parser::typeError(char* msg) {
	++typeErrorCount;
//	cout << msg << endl;
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
				typeError("identifier already defined");
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
			typeError("no identifier name");
		}
	}
	else if (node->getType() == ARRAY) {
		if (!node->isLeaf()) {
			if (node->getChild(1)->getToken()->getValue() > 0) {
				node->setCheckType(ARRAYTYPE);
			} else {
				typeError("no valid number");
				node->setCheckType(ERRORTYPE);
			}
		}
		else {
			node->setCheckType(NOTYPE);
		}
	}


}
