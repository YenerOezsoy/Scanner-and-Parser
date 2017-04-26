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
	char* lexem;
	Information* next;

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
};


#endif /* SYMBOLTABELLE_INCLUDES_INFORMATION_H_ */
