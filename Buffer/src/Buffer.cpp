/*
 * Buffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"


Buffer::Buffer() {
	// TODO Auto-generated constructor stub

}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}

void Buffer::readFromFile() {
	char buffer1[SIZE], buffer2[SIZE];
	//char* next, current;

	inputFile.open(INPUT, ios::in);

	inputFile.read(buffer1, SIZE);
	inputFile.read(buffer2, SIZE);

	for (int i = 0; i < SIZE; ++i) {
		cout << i+1 << ": " << buffer1[i] << endl;
	}
	for (int i = 0; i < SIZE; ++i) {
			cout << i+1 << ": " << buffer2[i] << endl;
	}
//	cout << "Buffer1: " << buffer1 << endl;
//	cout << "Buffer2: " << buffer2 << endl;
	if (inputFile.eof() == 0) {
		inputFile.close();
	}
}

void Buffer::writeToFile(/* What to write */) {
	outputFile.open(OUTPUT, ios::out);

	outputFile << "Testing the output" << endl;

	outputFile.close();
}
