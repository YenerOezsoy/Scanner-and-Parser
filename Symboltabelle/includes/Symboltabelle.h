/*
 * Symboltabelle.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef SYMBOLTABELLE_H_
#define SYMBOLTABELLE_H_

#include "SymTabEntry.h"
#include "StringTabelle.h"
#include "Information.h"

class Symboltabelle {
private:
	StringTabelle* strTab;
	SymTabEntry* entries;

	int size;
	int hash(char* str);

public:
	Symboltabelle(int size);
	virtual ~Symboltabelle();

	Key insert(char* lexem);
	Information* lookup(Key key);

	void initSymbols();
	void ausgabe();
};

#endif /* SYMBOLTABELLE_H_ */
