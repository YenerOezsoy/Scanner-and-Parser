/*
 * Buffer.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef BUFFER_H_
#define BUFFER_H_

#include <fstream>
#include <iostream>

using namespace std;

class Buffer {
public:
	const char* INPUT = "Buffer//input";
	const char* OUTPUT = "Buffer//output";
	const int SIZE = 20;

	Buffer();
	virtual ~Buffer();

	fstream inputFile, outputFile;

	void readFromFile();
	void writeToFile();
};

#endif /* BUFFER_H_ */
