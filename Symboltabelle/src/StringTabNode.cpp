/*
 * StringTabNode.cpp
 *
 *  Created on: Apr 7, 2017
 *      Author: okan
 */

#include "../includes/StringTabNode.h"
#include <string.h>

StringTabNode::StringTabNode(char* vector, int size) {
	this->vector = new char[size +1];
	strcpy(this->vector, vector);
	this->vector[size] = '\0';
}

StringTabNode::~StringTabNode() {
	delete this->vector;
}


