/*
 *  ParseTreeNode.h
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */
#include "../../Scanner/includes/Token.h"

#ifndef PARSETREENODE_H_
#define PARSER_INCLUDES_PARSETREENODE_H_

enum NodeType {
	PROG,
	DECLS,
	DECL,
	ARRAY,
	STATEMENTS,
	STATEMENT,
	EXP,
	EXP2,
	INDEX,
	OP_EXP,
	OP,
	EPSILON,
	INT,
	IDENTIFIER,
	INTEGER,
	ASSIGN,
	WRITE,
	READ,
	IF,
	ELSE,
	WHILE,
	LEAF
};

class ParseTreeNode {
private:
	NodeType type;
	Token* token;

	ParseTreeNode* next;
	ParseTreeNode* parent;
	ParseTreeNode* child;

public:
	ParseTreeNode(NodeType type, ParseTreeNode* parent);
	ParseTreeNode(NodeType type, ParseTreeNode* parent, Token* token);
	virtual ~ParseTreeNode();

	void addChild(ParseTreeNode* child);
	bool isLeaf();

	// Getter
	NodeType getType();
	Token* getToken();
	ParseTreeNode* getNext();
	ParseTreeNode* getParent();
	ParseTreeNode* getChild();
	ParseTreeNode* getChild(int index);

	// Setter
	void setChild(ParseTreeNode* child);
	void setNext(ParseTreeNode* next);
	void setType(ParseTreeNode* type);
};



#endif /* PARSETREENODE_H_ */
