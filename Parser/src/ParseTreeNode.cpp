/*
 *  ParseTreeNode.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */
#include "../includes/ParseTreeNode.h"

ParseTreeNode::ParseTreeNode(NodeType type, ParseTreeNode* parent) {
	this->type = type;
	this->token = nullptr;

	this->next = nullptr;
	this->parent = parent;
	this->child = nullptr;
}

ParseTreeNode::~ParseTreeNode() {

}

void ParseTreeNode::addChild(ParseTreeNode* child) {
	if (getChild() == nullptr) {
		setChild(child);
	}
	else {
		ParseTreeNode* ptr = this->child;

		while (ptr->getNext() != nullptr) {
			ptr = ptr->getNext();
		}

		ptr->setNext(child);
	}
}

bool ParseTreeNode::isLeaf() {
	return child == nullptr;
}

//
// Getter
//
NodeType ParseTreeNode::getType() {
	return type;
}

Token*ParseTreeNode::getToken() {
	return token;
}

ParseTreeNode* ParseTreeNode::getNext() {
	return next;
}

ParseTreeNode* ParseTreeNode::getParent() {
	return parent;
}

ParseTreeNode* ParseTreeNode::getChild() {
	return child;
}

ParseTreeNode* ParseTreeNode::getChild(int index) {
	ParseTreeNode* ptr = child;
	for(int i = 0; i < index; i++){
		ptr = ptr->getNext();
	}
	return ptr;
}

//
// Setter
//
void ParseTreeNode::setChild(ParseTreeNode* child) {
	this->child = child;
}

void ParseTreeNode::setNext(ParseTreeNode* next) {
	this->next = next;
}

void ParseTreeNode::setType(ParseTreeNode* type) {
	this->type = type;
}
