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
	char vector[];
	StringTabNode* next;

public:
	StringTabNode();
	virtual ~StringTabNode();

};

#endif /* SYMBOLTABELLE_INCLUDES_STRINGTABNODE_H_ */
