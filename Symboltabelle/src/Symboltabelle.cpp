/*
 * Symboltabelle.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Symboltabelle.h"
#include <iostream>
#include <string.h>

Symboltabelle::Symboltabelle(int size) {
	this->size = size;
	this->strTab = new StringTabelle;
	this->entries = new SymTabEntry[size];
}

Symboltabelle::~Symboltabelle() {
	delete strTab;
	delete[] entries;
}

Key Symboltabelle::insert(char* lexem) {
	int index = hash(lexem);
	entries[index].insert(index, lexem, strTab);
}

Information* Symboltabelle::lookup(Key key) {
	return entries[key.hash].lookup(key);
}

int Symboltabelle::hash(char* str) {
    int hash = 0;

    for (unsigned int i = 0; i < strlen(str); i++) {
    	hash += str[i];
    }
    hash %= this->size;

	return hash;
}

void Symboltabelle::initSymbols() {
	insert("while");
	insert("WHILE");
	insert("if");
	insert("IF");
	insert("test");
	insert("i");
	insert("come");
	insert("lel");
	insert("lel");
}

void Symboltabelle::ausgabe() {
	for (int i = 0; i < this->size; i++) {
		std::cout << i << ": ";
		entries[i].ausgeben();
		std::cout << std::endl;
	}
}
