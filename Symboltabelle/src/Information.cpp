/*
 * Information.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: okan
 */

#include "../includes/Information.h"
#include <string.h>

bool Information::compareLex(char* lexem) {
	return strcmp(this->name, lexem);
}
