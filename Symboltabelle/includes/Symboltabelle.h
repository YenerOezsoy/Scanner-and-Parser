/*
 * Symboltabelle.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef SYMBOLTABELLE_H_
#define SYMBOLTABELLE_H_

#include "StringTabelle.h"
#include "SymTabEntry.h"
#include "Information.h"

class Symboltabelle {
private:
	StringTabelle* strTab;
	SymTabEntry* entries[];

public:
	Symboltabelle();
	virtual ~Symboltabelle();

	Key insert(char* lexem);
	Information lookup(Key key);

};

#endif /* SYMBOLTABELLE_H_ */
