/*
 *  ParseTree.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */
#include "../includes/ParseTree.h"

ParseTree::ParseTree() {
	this->root = nullptr;
}

ParseTree::~ParseTree() {

}

void ParseTree::setRoot(ParseTreeNode* root) {
	this->root = root;
}

ParseTreeNode* ParseTree::getRoot() {
	return this->root;
}
