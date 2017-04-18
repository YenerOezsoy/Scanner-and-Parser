/*
 * StringTabelle.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: okan
 */

#include "../includes/StringTabelle.h"

StringTabelle::StringTabelle() {

}

StringTabelle::~StringTabelle() {
	StringTabNode* current = first;
	while (current->getNext() != nullptr) {
		StringTabNode* tmp = current;
		current = current->getNext();
		delete tmp;
	}
}

char* StringTabelle::insert(char* lexem, int size) {
	StringTabNode* node = new StringTabNode(lexem, size);
	if (first == nullptr) {
		first = node;
	} else {
		StringTabNode* current = first;
		while (current->getNext() != nullptr) {
			current = current->getNext();
		}
		current->setNext(node);
	}

	return node->getVector();
}


