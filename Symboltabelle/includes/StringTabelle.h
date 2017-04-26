/*
 * StringTabelle.h
 *
 *  Created on: Apr 6, 2017
 *      Author: okan
 */

#ifndef SYMBOLTABELLE_INCLUDES_STRINGTABELLE_H_
#define SYMBOLTABELLE_INCLUDES_STRINGTABELLE_H_

#include "StringTabNode.h"

class StringTabelle {
private:
	char* freeP;
	int freeSpace;
	StringTabNode* first;

public:
	StringTabelle();
	virtual ~StringTabelle();

	char* insert(char* lexem, int size);
};


#endif /* SYMBOLTABELLE_INCLUDES_STRINGTABELLE_H_ */
