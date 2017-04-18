/*
 * Information.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: okan
 */

#include "../includes/Information.h"
#include <string.h>

Information::Information(char* lexem) {
	this->lexem = lexem;
}

bool Information::compareLex(char* lexem) {
	return strcmp(this->lexem, lexem);
}
