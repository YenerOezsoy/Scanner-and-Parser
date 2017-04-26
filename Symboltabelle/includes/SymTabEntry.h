/*
 * SymTabEntry.h
 *
 *  Created on: Apr 6, 2017
 *      Author: okan
 */

#ifndef SYMBOLTABELLE_INCLUDES_SYMTABENTRY_H_
#define SYMBOLTABELLE_INCLUDES_SYMTABENTRY_H_

#include "Information.h"
#include "StringTabelle.h"

class SymTabEntry {
private:
	Information* first;
	int size;

	int exists(char* lexem);
public:
	SymTabEntry();
	virtual ~SymTabEntry();

	Key insert(int hash, char* lexem, StringTabelle* strTab);
	Information* lookup(Key key);

	void ausgeben();
};


#endif /* SYMBOLTABELLE_INCLUDES_SYMTABENTRY_H_ */
