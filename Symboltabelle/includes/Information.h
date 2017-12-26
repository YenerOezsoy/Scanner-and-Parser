/*
 * Information.h
 *
 *  Created on: Apr 6, 2017
 *      Author: okan
 */

#include "../../Parser/includes/CheckType.h"

#ifndef SYMBOLTABELLE_INCLUDES_INFORMATION_H_
#define SYMBOLTABELLE_INCLUDES_INFORMATION_H_

struct Key {
	int hash;
	int index;

	Key (int hash, int index) {
		this->hash = hash;
		this->index = index;
	}
};

class Information{
private:
	Information* next;
	char* lexem;
	CheckType type;

public:
	Information(char* lexem);

	bool compareLex (char* lexem);

	char* getName () {
		return lexem;
	}

	Information* getNext() {
		return next;
	}

	void setNext(Information* info) {
		next = info;
	}

	void setCheckType(CheckType type) {
		this->type = type;
	}

	CheckType getCheckType() {
		return this->type;
	}
};


#endif /* SYMBOLTABELLE_INCLUDES_INFORMATION_H_ */
