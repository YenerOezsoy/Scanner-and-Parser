/*
 * StringTabEntry.h
 *
 *  Created on: Apr 6, 2017
 *      Author: okan
 */

#ifndef SYMBOLTABELLE_INCLUDES_STRINGTABNODE_H_
#define SYMBOLTABELLE_INCLUDES_STRINGTABNODE_H_

class StringTabNode {
private:
	char* vector;
	int size;
	StringTabNode* next;

public:
	StringTabNode(char* vector, int size);
	virtual ~StringTabNode();

	char* getVector() {
		return vector;
	}

	StringTabNode* getNext() {
		return next;
	}

	void setNext(StringTabNode* node) {
		next = node;
	}
};

#endif /* SYMBOLTABELLE_INCLUDES_STRINGTABNODE_H_ */
