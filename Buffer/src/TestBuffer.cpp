/*
 * TestBuffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"


int main(int argc, char **argv) {
	cout << "Buffer" << endl;

	Buffer*  buffer = new Buffer();

	buffer->readFromFile();
	//buffer->readFromFile();
}
