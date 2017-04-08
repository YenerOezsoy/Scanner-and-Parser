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

	Key () {
		this->hash = 0;
		this->index = -1;
	}
};

class Information{
private:
	char* name;

public:
	bool compareLex (char* lexem);
	char* getName () {
		return name;
	}
};

#endif /* SYMBOLTABELLE_INCLUDES_INFORMATION_H_ */
