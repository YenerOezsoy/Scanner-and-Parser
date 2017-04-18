/*
 * Information.h
 *
 *  Created on: Apr 6, 2017
 *      Author: okan
 */

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
	char* name;
	Information* next;

public:
	bool compareLex (char* lexem);

	char* getName () {
		return name;
	}

	Information* getNext() {
		return next;
	}
};

#endif /* SYMBOLTABELLE_INCLUDES_INFORMATION_H_ */
