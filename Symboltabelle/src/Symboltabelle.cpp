/*
 * Symboltabelle.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Symboltabelle.h"
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
	//entries[index].insert(lexem);
}

Information Symboltabelle::lookup(Key key) {

}

int Symboltabelle::hash(char* str) {
    int hash = 0;

    for (unsigned int i = 0; i < strlen(str); i++) {
    	hash += str[i];
    }
    hash %= this->size;

	return hash;
}
