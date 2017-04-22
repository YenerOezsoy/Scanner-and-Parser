/*
 * TestBuffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {

	cout << "Buffer" << endl;
//	Buffer*  buffer;
//
//	buffer = new Buffer();
//
//	buffer->read();

	Buffer buffer;
	int wantedSize = 400;
	try {
		for(int i = 0; i < wantedSize; i++){
			cout << buffer.getChar();
		}
	} catch(BufferOutOfBoundException& exception) { /* hier passiert nichts */ }

	buffer.ungetChar();
	buffer.ungetChar();
	buffer.ungetChar();
	buffer.ungetChar();
	cout << "\n";
	cout <<buffer.getChar();

}

