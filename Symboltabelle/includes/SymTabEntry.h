/*
 * SymTabEntry.h
 *
 *  Created on: Apr 6, 2017
 *      Author: okan
 */

#ifndef SYMBOLTABELLE_INCLUDES_SYMTABENTRY_H_
#define SYMBOLTABELLE_INCLUDES_SYMTABENTRY_H_

#include "Information.h"

class SymTabEntry {
private:
	Information* info;

public:
	SymTabEntry();
	virtual ~SymTabEntry();

};

#endif /* SYMBOLTABELLE_INCLUDES_SYMTABENTRY_H_ */
