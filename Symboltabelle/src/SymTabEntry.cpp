/*
 * SymTabEntry.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: okan
 */

#include "../includes/SymTabEntry.h"
#include <iostream>
#include <string.h>

SymTabEntry::SymTabEntry() {
	first = nullptr;
	size = 0;
}

SymTabEntry::~SymTabEntry() {
	Information* current = first;
	for (int i = 0; i < size; ++i) {
		Information* tmp = current;
		current = current->getNext();
		delete tmp;
	}
}

Key SymTabEntry::insert(int hash, char* lexem, StringTabelle* strTab) {
	int index = exists(lexem);

	if (index == -1) {
		Information* info = new Information(strTab->insert(lexem, strlen(lexem)));

		if (first == nullptr) {
			first = info;
			size++;
		} else {
			Information* current = first;
			while (current->getNext() != nullptr) {
				current = current->getNext();
			}
			current->setNext(info);
			size++;
		}
		index = size;
	}

	return Key(hash, index);
}

int SymTabEntry::exists(char* lexem) {
	Information* current = first;
	for (int i = 0; i < size; ++i) {
		if (current->compareLex(lexem) == 0) {
			std::cout << "EXISTS " << lexem  << " = " << current->getName() << " ," << std::endl;
			return i;
		}
		current = current->getNext();
	}
	return -1;
}

Information* SymTabEntry::lookup(Key key) {
	Information* current = first;
	for (int i = 0; i < key.index; ++i) {
		current = current->getNext();
	}
	return current;
}

void SymTabEntry::ausgeben() {
	Information* current = first;
	while (current != nullptr) {
		std::cout << current->getName() << " ";
		current = current->getNext();
	}
}
