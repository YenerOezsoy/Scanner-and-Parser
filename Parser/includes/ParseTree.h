/*
 *  ParseTree.h
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */
#include "ParseTreeNode.h"

#ifndef PARSETREE_H_
#define PARSETREE_H_


class ParseTree {
private:
	ParseTreeNode* root;

public:
	ParseTree();
	virtual ~ParseTree();

	ParseTreeNode* getRoot();
	void setRoot(ParseTreeNode* root);
};




#endif /* PARSETREE_H_ */
