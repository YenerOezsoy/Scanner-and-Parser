/*
 * Buffer.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef BUFFER_H_
#define BUFFER_H_
#include <fstream>

using namespace std;
class BufferOutOfBoundException {};
class NotAbleToOpenFileException{};

class Buffer {

private:
	const char* INPUT = "Buffer//debug//input";

	//new
	const static int BUFFER_SIZE = 10;
	char buffer1 [BUFFER_SIZE];
	char buffer2 [BUFFER_SIZE];
	int location1, location2;
	int currentBuffer, wantedSize, inputSize1, inputSize2;


	fstream file;

public:
	Buffer();
	virtual ~Buffer();
	void read();

	//new
	char getChar();
	void ungetChar();

};

#endif /* BUFFER_H_ */
