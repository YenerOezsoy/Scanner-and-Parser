/*
 *  TypeCheck.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: kaok1012
 */
#include "../includes/Parser.h"

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
	else if () {

	}


}
